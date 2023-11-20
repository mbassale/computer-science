use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====");
}

#[derive(Debug)]
enum UsState {
    California,
    Other,
}

#[derive(Debug)]
enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => {
            println!("Lucky penny!");
            1
        }
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(state) => {
            println!("State quarter from: {:?}", state);
            25
        }
    }
}

#[named]
fn test1_match() {
    trace(function_name!());
    let value1 = value_in_cents(Coin::Penny);
    dbg!(value1);
    let value2 = value_in_cents(Coin::Quarter(UsState::California));
    dbg!(value2);
}

fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}

#[named]
fn test2_option() {
    trace(function_name!());
    let six = plus_one(Some(5));
    dbg!(six);
    let none = plus_one(None);
    dbg!(none);
}

#[named]
fn test3_catch_all() {
    trace(function_name!());
    let dice_roll = 9;
    match dice_roll {
        3 => println!("s3"),
        7 => println!("s7"),
        _ => println!("other"),
    }
}

fn main() {
    test1_match();
    test2_option();
    test3_catch_all();
}
