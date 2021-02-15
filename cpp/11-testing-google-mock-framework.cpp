#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <functional>

using ::testing::_;
using ::testing::A;
using ::testing::Field;
using ::testing::DoubleEq;
using ::testing::NiceMock;
using ::testing::StrictMock;
using ::testing::Invoke;

struct SpeedUpdate {
    double velocity_mps;
};

struct CarDetected {
    double distance_m;
    double velocity_mps;
};

struct BrakeCommand {
    double time_to_collision_s;
};

using SpeedUpdateCallback = std::function<void(const SpeedUpdate&)>;
using CarDetectedCallback = std::function<void(const CarDetected&)>;

struct IServiceBus {
    virtual ~IServiceBus() = default;
    virtual void publish(const BrakeCommand&) = 0;
    virtual void subscribe(SpeedUpdateCallback) = 0;
    virtual void subscribe(CarDetectedCallback) = 0;
};

struct MockServiceBus : IServiceBus {
    MOCK_METHOD1(publish, void(const BrakeCommand& cmd));
    MOCK_METHOD1(subscribe, void(SpeedUpdateCallback callback));
    MOCK_METHOD1(subscribe, void(CarDetectedCallback callback));
};

struct AutoBrake {
    AutoBrake(IServiceBus& bus) : collision_threshold_s{ 5 }, speed_mps{} {
        bus.subscribe([this](const SpeedUpdate& update) {
            speed_mps = update.velocity_mps;
        });
        bus.subscribe([this, &bus](const CarDetected &cd) {
            const auto relative_velocity_mps = speed_mps - cd.velocity_mps;
            const auto time_to_collision_s = cd.distance_m / relative_velocity_mps;
            if (time_to_collision_s > 0 && time_to_collision_s < collision_threshold_s) {
                bus.publish(BrakeCommand{ time_to_collision_s });
            }
        });
    }
    void set_collision_threshold_s(double x) {
        if (x < 1) throw std::invalid_argument("Collision less than 1.");
        collision_threshold_s = x;
    }
    double get_collision_threshold_s() const {
        return collision_threshold_s;
    }
    double get_speed_mps() const {
        return speed_mps;
    }
private:
    double collision_threshold_s;
    double speed_mps;
};

struct NiceAutoBrakeTest : ::testing::Test {
    NiceMock<MockServiceBus> bus;
    AutoBrake auto_brake { bus };
};

struct StrictAutoBrakeTest : ::testing::Test {
    StrictAutoBrakeTest() {
        EXPECT_CALL(bus, subscribe(A<CarDetectedCallback>())).Times(1)
                .WillOnce(Invoke([this](const auto& x) {
                    car_detected_callback = x;
                }));
        EXPECT_CALL(bus, subscribe(A<SpeedUpdateCallback>())).Times(1)
                .WillOnce(Invoke([this](const auto& x) {
                    speed_update_callback = x;
                }));;
    }
    CarDetectedCallback car_detected_callback;
    SpeedUpdateCallback speed_update_callback;
    StrictMock<MockServiceBus> bus;
};

TEST_F(NiceAutoBrakeTest, InitialCarSpeedIsZero) {
    ASSERT_DOUBLE_EQ(0, auto_brake.get_speed_mps());
}

TEST_F(NiceAutoBrakeTest, InitialSensitivityIsFive) {
    ASSERT_ANY_THROW(auto_brake.set_collision_threshold_s(0.5L));
}

int main(int argc, char** argv) {
    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ::testing::InitGoogleMock(&argc, argv);
}