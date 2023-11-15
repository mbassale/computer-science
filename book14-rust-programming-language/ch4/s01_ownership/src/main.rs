use ::function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====")
}

#[named]
fn test0() {
    trace(function_name!());
    let s = "hello, world!";
    println!("s: {s}");
    let mut s = String::from("hello");
    s.push_str(", world!");
    println!("s: {s}")
}

#[named]
fn test1() {
    trace(function_name!());
    let x = 5;
    let y = x;
    println!("x: {x}, y: {y}");

    {
        let s1 = String::from("hello");
        let s2 = s1;
        println!("s2: {s2}");
    }

    {
        let s1 = String::from("hello");
        let s2 = s1.clone();
        println!("s1: {s1}, s2: {s2}");
    }
}

#[named]
fn takes_ownership(some_string: String) {
    trace(function_name!());
    println!("some_string: {some_string}");
}

#[named]
fn makes_copy(some_integer: i32) {
    trace(function_name!());
    println!("some_integer: {some_integer}");
}

#[named]
fn test2() {
    trace(function_name!());
    let s = String::from("hello");
    takes_ownership(s);

    let x = 5;
    makes_copy(x);
}

#[named]
fn gives_ownership() -> String {
    trace(function_name!());
    String::from("yours")
}

#[named]
fn takes_ownership_and_gives_back(str: String) -> String {
    trace(function_name!());
    str
}

#[named]
fn test3() {
    trace(function_name!());
    let s1 = gives_ownership();
    println!("s1: {s1}");
    let s1 = takes_ownership_and_gives_back(s1);
    println!("s1: {s1}");
}

#[named]
fn calculate_length(s: String) -> (String, usize) {
    trace(function_name!());
    let length = s.len();
    (s, length)
}

#[named]
fn test4() {
    trace(function_name!());
    let s1 = String::from("hello");
    let (s1, len) = calculate_length(s1);
    println!("s1: {s1} s1.len(): {len}");
}

fn main() {
    test0();
    test1();
    test2();
    test3();
    test4();
}
