use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====")
}

#[derive(Debug)]
struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

#[named]
fn test1_defining_structs() {
    trace(function_name!());

    let mut user1 = User {
        active: true,
        username: String::from("testymctest"),
        email: String::from("testymctest@example.com"),
        sign_in_count: 1,
    };
    println!("user1: {:?}", user1);

    user1.username = String::from("testy.mctest");
    user1.email = String::from("testy.mctest@example.com");
    println!("user1: {:?}", user1);
}

#[named]
fn build_user(email: String, username: String) -> User {
    trace(function_name!());
    User {
        active: true,
        username,
        email,
        sign_in_count: 1,
    }
}

#[named]
fn test2_shorthand_syntax() {
    trace(function_name!());
    let user = build_user(
        String::from("mbassaletti@example.com"),
        String::from("mbassaletti"),
    );
    println!("user: {:?}", user);
}

#[named]
fn test3_struct_update_syntax() {
    trace(function_name!());
    let user = build_user(
        String::from("mbassaletti@example.com"),
        String::from("mbassaletti"),
    );
    println!("user: {:?}", user);
    let user2 = User {
        email: String::from("marco.bassaletti@example.com"),
        ..user
    };
    println!("user2: {:?}", user2);
}

#[derive(Debug)]
struct Color(i32, i32, i32);

#[derive(Debug)]
struct Point(i32, i32, i32);

#[named]
fn test4_tuple_structs() {
    trace(function_name!());
    let black = Color(0, 0, 0);
    println!("color: {:?}", black);
    let origin = Point(0, 0, 0);
    println!("point: {:?}", origin);
}

fn main() {
    test1_defining_structs();
    test2_shorthand_syntax();
    test3_struct_update_syntax();
    test4_tuple_structs();
}
