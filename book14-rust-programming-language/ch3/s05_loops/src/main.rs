/*
$ cargo run
   Compiling s05_loops v0.1.0 (/Users/mbassale/devel/computer-science/book14-rust-programming-language/ch3/s05_loops)
    Finished dev [unoptimized + debuginfo] target(s) in 0.09s
     Running `target/debug/s05_loops`
===== Call test0 =====
i: 0
i: 1
i: 2
i: 3
i: 4
i: 5
===== Call test1 =====
The result is: 20
===== Call test2 =====
counter: 3
counter: 2
counter: 1
Done.
===== Call test3 =====
the value is: 10
the value is: 20
the value is: 30
the value is: 40
the value is: 50
===== Call test4 =====
the value is: 10
the value is: 20
the value is: 30
the value is: 40
the value is: 50
===== Call test5 =====
value: 3
value: 2
value: 1
Done.
*/

use ::function_name::named;

fn trace(name: &str) {
    println!("===== Call {} =====", name);
}

#[named]
fn test0() {
    trace(function_name!());
    let mut i = 0;
    let limit = 5;
    loop {
        println!("i: {i}");
        if i == limit {
            break;
        }
        i += 1;
    }
}

#[named]
fn test1() {
    trace(function_name!());
    let mut counter = 0;

    let result = loop {
        counter += 1;
        if counter == 10 {
            break counter * 2;
        }
    };
    println!("The result is: {result}");
}

#[named]
fn test2() {
    trace(function_name!());
    let mut counter = 3;
    while counter > 0 {
        println!("counter: {counter}");
        counter -= 1;
    }
    println!("Done.")
}

#[named]
fn test3() {
    trace(function_name!());
    let a = [10, 20, 30, 40, 50];
    let mut index = 0;
    while index < 5 {
        println!("the value is: {}", a[index]);
        index += 1;
    }
}

#[named]
fn test4() {
    trace(function_name!());
    let a = [10, 20, 30, 40, 50];
    for element in a {
        println!("the value is: {element}");
    }
}

#[named]
fn test5() {
    trace(function_name!());
    for number in (1..4).rev() {
        println!("value: {number}");
    }
    println!("Done.");
}

fn main() {
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
}
