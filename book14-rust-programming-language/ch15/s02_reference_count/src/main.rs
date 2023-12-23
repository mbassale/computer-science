#![allow(dead_code)]

use std::rc::Rc;

enum List {
    Cons(i32, Rc<List>),
    Nil,
}

impl List {
    fn new(val: i32, next: Rc<List>) -> Rc<List> {
        Rc::new(List::Cons(val, next))
    }

    fn size(&self) -> usize {
        match self {
            List::Nil => 0,
            List::Cons(_, next) => 1 + next.size(),
        }
    }
}

#[cfg(test)]
mod tests {

    use super::*;
    use crate::List::{Cons, Nil};

    #[test]
    fn test_cons() {
        let a = List::new(5, Rc::new(Cons(10, Rc::new(Nil))));
        assert_eq!(a.size(), 2);
        assert_eq!(Rc::strong_count(&a), 1);
        let b = Cons(3, Rc::clone(&a));
        assert_eq!(b.size(), 3);
        assert_eq!(Rc::strong_count(&a), 2);
        {
            let c = Cons(4, Rc::clone(&a));
            assert_eq!(c.size(), 3);
            assert_eq!(Rc::strong_count(&a), 3);
        }
        assert_eq!(Rc::strong_count(&a), 2);
    }
}

fn main() {}
