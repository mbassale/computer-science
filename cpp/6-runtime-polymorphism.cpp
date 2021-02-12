#include <cstdio>
#include <stdexcept>

#define ACCOUNT_DATABASE_INITIAL_SIZE 200

struct Account {
    long id{ 0 };
    long credit{ 0 };
    long debit{ 0 };
    long balance{ 0 };
};

struct AccountDatabase {
    virtual Account get_account(long id) = 0;

    static const Account None;
};

struct InMemoryAccountDatabase : AccountDatabase {

    InMemoryAccountDatabase(size_t initial_size = ACCOUNT_DATABASE_INITIAL_SIZE) {
        accounts = new Account[initial_size];
        accounts_size = initial_size;
        accounts_num = 0;
    }

    ~InMemoryAccountDatabase() {
        delete[] accounts;
    }

    Account get_account(long id) override {
        for (size_t i = 0; i < accounts_num; i++) {
            if (accounts[i].id == id) return accounts[id];
        }
        return None;
    }
private:
    Account* accounts;
    size_t accounts_size = 0;
    size_t accounts_num = 0;
};

struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
    ConsoleLogger() : name{} {}
    ConsoleLogger(const char* name) : name{name} {}
    void log_transfer(long from, long to, double amount) override {
        printf("[cons] %s: %ld -> %ld: %f\n", name, from, to, amount);
    }
private:
    const char* name;
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld, %ld, %f\n", from, to, amount);
    }
};

struct Bank {
    Bank(Logger* logger) : logger{ logger } {}
    void make_transfer(long from, long to, double amount) {
        logger->log_transfer(from, to, amount);
    }
    void set_logger(Logger* new_logger) {
        if (!new_logger) throw std::invalid_argument("new_logger");
        logger = new_logger;
    }
private:
    Logger* logger;
};

int main() {
    ConsoleLogger console_logger{ "Default" };
    FileLogger file_logger;
    Bank bank{&console_logger};
    bank.make_transfer(1000, 2000, 49.95);
    bank.set_logger(&file_logger);
    bank.make_transfer(2000, 4000, 20.00);
    return 0;
}