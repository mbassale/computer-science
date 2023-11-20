use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====");
}

#[derive(Debug)]
enum IpAddr {
    V4(u8, u8, u8, u8),
    V6(String),
}

#[named]
fn test1_enums() {
    trace(function_name!());
    let home = IpAddr::V4(127, 0, 0, 1);
    dbg!(home);
    let loopback = IpAddr::V6(String::from("::1"));
    dbg!(loopback);
}

#[derive(Debug)]
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

impl Message {
    #[named]
    fn call(&self) {
        trace(function_name!());
        match self {
            Message::Write(text) => println!("message: {text}"),
            _ => (),
        }
    }
}

#[named]
fn test2_enum_structs() {
    trace(function_name!());
    let m = Message::Write(String::from("hello"));
    m.call();
}

#[named]
fn test3_option() {
    trace(function_name!());
    let some_number = Some(5);
    let some_char = Some('e');
    let absent_number: Option<i32> = None;
    dbg!(some_number);
    dbg!(some_char);
    dbg!(absent_number);
}

fn main() {
    test1_enums();
    test2_enum_structs();
    test3_option();
}
