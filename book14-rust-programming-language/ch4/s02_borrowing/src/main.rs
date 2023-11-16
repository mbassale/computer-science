use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====")
}

fn calculate_length(s: &String) -> usize {
    s.len()
}

#[named]
fn test0() {
    trace(function_name!());
    let s1 = String::from("hello");
    let len = calculate_length(&s1);
    println!("s1: {s1}, s1.len(): {len}");
}

#[named]
fn change(s: &mut String) {
    trace(function_name!());
    s.push_str(", world");
}

#[named]
fn test1_mutable_reference() {
    trace(function_name!());
    let mut s = String::from("hello");
    change(&mut s);
    println!("s: {s}");
}

#[named]
fn test2_multiple_mutable_reference() {
    trace(function_name!());

    let mut s = String::from("hello");
    println!("str: {s}");
    {
        let r1 = &mut s;
        r1.push_str(", world!");
    }
    println!("str: {s}");

    let r2 = &mut s;
    r2.push_str(" - eom");

    println!("str: {s}");
}

fn main() {
    test0();
    test1_mutable_reference();
    test2_multiple_mutable_reference();
}
