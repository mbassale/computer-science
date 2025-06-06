
#[derive(Debug)]
enum UsState {
    Alabama,
    Alaska,
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(state) => {
            println!("State quarter from {:?}!", state);
            25
        }
    }
}

fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1)
    }
}

fn main() {
    println!("A dime in cents: {}", value_in_cents(Coin::Dime));
    println!("A quarter in cents(AL): {}", value_in_cents(Coin::Quarter(UsState::Alabama)));
    let five = Some(5);
    let six = plus_one(five);
    let none = plus_one(None);
    match six {
        None => (),
        Some(s) => println!("Six is: {}", s)
    };
    println!("Six is some: {}", six.is_some());
    println!("None is none: {}", none.is_none());
}
