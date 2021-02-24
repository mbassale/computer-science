#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <filesystem>
#include <iomanip>

using namespace std;

filesystem::path this_source_file{R"(/Users/mbassale/devel/computer-science/cpp/18-filesystems.cpp)" };

TEST_CASE("std::filesystem::path supports == and .empty()") {
    filesystem::path empty_path;
    filesystem::path shadow_path{ "/etc/shadow" };
    REQUIRE(empty_path.empty());
    REQUIRE(shadow_path == std::string{ "/etc/shadow"} );
}

TEST_CASE("get path components") {
    REQUIRE(this_source_file.root_name() == "");
    REQUIRE(this_source_file.root_directory() == "/");
    REQUIRE(this_source_file.root_path() == "/");
    REQUIRE(this_source_file.relative_path() == "Users/mbassale/devel/computer-science/cpp/18-filesystems.cpp");
    REQUIRE(this_source_file.parent_path() == "/Users/mbassale/devel/computer-science/cpp");
    REQUIRE(this_source_file.filename() == "18-filesystems.cpp");
    REQUIRE(this_source_file.stem() == "18-filesystems");
    REQUIRE(this_source_file.extension() == ".cpp");
}

TEST_CASE("modifying paths") {
    REQUIRE(this_source_file.make_preferred() == "/Users/mbassale/devel/computer-science/cpp/18-filesystems.cpp");
    REQUIRE(this_source_file.replace_filename("test.cpp") == "/Users/mbassale/devel/computer-science/cpp/test.cpp");
    REQUIRE(this_source_file.remove_filename() == "/Users/mbassale/devel/computer-science/cpp/");
    this_source_file.clear();
    REQUIRE(this_source_file.empty());
}

TEST_CASE("path-composing") {
    const auto relative = filesystem::relative(this_source_file);
    REQUIRE(relative.is_relative());
    REQUIRE_FALSE(relative.is_absolute());
}

TEST_CASE("inspecting file types") {
    REQUIRE_FALSE(filesystem::is_empty(this_source_file));
    REQUIRE_FALSE(filesystem::is_directory(this_source_file));
    REQUIRE_FALSE(filesystem::is_symlink(this_source_file));
    REQUIRE(filesystem::exists(this_source_file));
    REQUIRE(filesystem::file_size(this_source_file) > 0);
}

TEST_CASE("directory iterators") {
    const auto path = filesystem::current_path();
    for (const auto& entry : filesystem::directory_iterator{ path }) {
        REQUIRE(entry.exists());
        REQUIRE(entry.path().wstring().length() > 0);
    }
}
