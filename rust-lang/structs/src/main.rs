struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

fn main() {
    let mut user1 = User {
        email: String::from("bassaletti@gmail.com"),
        username: String::from("mbassale"),
        active: true,
        sign_in_count: 1,
    };
    user1.username = String::from("mbassaletti");

    let user2 = User {
        email: String::from("bassaletti@outlook.com"),
        ..user1
    };

    let user3 = build_user(String::from("nkft@msn.com"), String::from("nkft"));

    let black = Color(0, 0, 0);
    let origin = Point(0, 0, 0);
}

fn build_user(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        sign_in_count: 1,
    }
}
