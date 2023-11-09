use crate::List::{Cons, Nil};

enum List {
    Cons(i32, List),
    Nil,
}

fn main() {
    let b = Box::new(5);
    println!("b = {}", b);
}
