#include <cstdio>

namespace BroopKidron13::Shaltanac {
    enum class Color {
        Mauve,
        Pink,
        Russet
    };

    struct JoopleberryShrub {
        const char* name;
        Color shade;
    };

    bool is_more_mauvey(const JoopleberryShrub& shrub) {
        return shrub.shade == Color::Mauve;
    }
}

using namespace BroopKidron13::Shaltanac;
using ShaltanacColor = BroopKidron13::Shaltanac::Color;

int main() {
    const JoopleberryShrub yours {
        "The other Shaltanac",
        ShaltanacColor::Mauve
    };
    if (is_more_mauvey(yours)) {
        printf("The other Shaltanac's joopleberry shrub is always "
            "a more mauvey shade of pinky russet.\n");
    }
    return 0;
}