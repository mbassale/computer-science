use std::{thread, time::Duration};

use function_name::named;

fn trace(name: &str) {
    println!("===== Called {name} =====");
}

#[derive(Debug, PartialEq, Copy, Clone)]
enum ShirtColor {
    Red,
    Blue,
}

struct Inventory {
    shirts: Vec<ShirtColor>,
}

impl Inventory {
    fn giveaway(&self, user_preference: Option<ShirtColor>) -> ShirtColor {
        user_preference.unwrap_or_else(|| self.most_stocked())
    }

    fn most_stocked(&self) -> ShirtColor {
        let mut num_red = 0;
        let mut num_blue = 0;

        for color in &self.shirts {
            match color {
                ShirtColor::Red => num_red += 1,
                ShirtColor::Blue => num_blue += 1,
            }
        }

        if num_red > num_blue {
            ShirtColor::Red
        } else {
            ShirtColor::Blue
        }
    }
}

#[named]
fn test1_inventory() {
    trace(function_name!());
    let store = Inventory {
        shirts: vec![ShirtColor::Blue, ShirtColor::Red, ShirtColor::Blue],
    };

    let user_pref1 = Some(ShirtColor::Red);
    let giveaway1 = store.giveaway(user_pref1);
    println!(
        "The user with preference: {:?} gets {:?}",
        user_pref1, giveaway1
    );

    let user_pref2 = None;
    let giveaway2 = store.giveaway(user_pref2);
    println!(
        "The user with preference: {:?} gets {:?}",
        user_pref2, giveaway2
    );
}

#[named]
fn test2_closures() {
    trace(function_name!());
    let expensive_closure = |num: u32| -> u32 {
        println!("calculating slowly...");
        thread::sleep(Duration::from_secs(1));
        num
    };
    println!("Expensive closure: {}", expensive_closure(10));

    let add_one = |x| x + 1;
    println!("add_one(1): {}", add_one(1));
}

#[named]
fn test3_capturing() {
    trace(function_name!());
    let list = vec![1, 2, 3];
    println!("Before defining closure: {:?}", list);

    let only_borrows = || println!("From closure: {:?}", list);
    only_borrows();
    println!("After calling closure: {:?}", list);

    let mut list = vec![1, 2, 3];
    println!("Before calling closure: {:?}", list);
    let mut borrows_mutably = || list.push(7);
    borrows_mutably();
    println!("After calling closure: {:?}", list);
}

#[named]
fn test4_thread_move() {
    trace(function_name!());
    let list = vec![1, 2, 3];
    println!("Before defining closure: {:?}", list);
    thread::spawn(move || println!("From thread: {:?}", list))
        .join()
        .unwrap();
}

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

#[named]
fn test5_sort_by_key() {
    trace(function_name!());
    let mut list = [
        Rectangle {
            width: 10,
            height: 1,
        },
        Rectangle {
            width: 3,
            height: 5,
        },
        Rectangle {
            width: 7,
            height: 12,
        },
    ];
    let mut sort_operations = 0;
    list.sort_by_key(|r| {
        sort_operations += 1;
        r.width
    });
    println!("{:#?}, sorted in {sort_operations} operations", list);
}

fn main() {
    test1_inventory();
    test2_closures();
    test3_capturing();
    test4_thread_move();
    test5_sort_by_key();
}
