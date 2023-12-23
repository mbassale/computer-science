#![allow(dead_code)]

use std::cell::RefCell;
use std::rc::{Rc, Weak};

#[derive(Debug, PartialEq)]
enum List {
    Cons(i32, RefCell<Rc<List>>),
    Nil,
}

impl List {
    fn size(&self) -> usize {
        match self {
            List::Cons(_, next) => 1 + next.borrow().size(),
            List::Nil => 0,
        }
    }

    fn tail(&self) -> Option<&RefCell<Rc<List>>> {
        match self {
            List::Cons(_, item) => Some(item),
            List::Nil => None,
        }
    }
}

#[derive(Debug)]
struct Node {
    value: i32,
    parent: RefCell<Weak<Node>>,
    children: RefCell<Vec<Rc<Node>>>,
}

#[cfg(test)]
mod tests {

    use std::cell::RefCell;
    use std::rc::Rc;

    use super::*;
    use crate::List::{Cons, Nil};

    #[test]
    fn leak_memory() {
        let a = Rc::new(Cons(5, RefCell::new(Rc::new(Nil))));
        assert_eq!(Rc::strong_count(&a), 1);
        assert!(a.tail().is_some());

        let b = Rc::new(Cons(10, RefCell::new(Rc::clone(&a))));
        assert_eq!(Rc::strong_count(&a), 2);
        assert_eq!(Rc::strong_count(&b), 1);

        // make a reference cycle
        if let Some(link) = a.tail() {
            *link.borrow_mut() = Rc::clone(&b);
        }

        assert_eq!(Rc::strong_count(&a), 2);
        assert_eq!(Rc::strong_count(&b), 2);
    }

    #[test]
    fn tree_struct() {
        let leaf = Rc::new(Node {
            value: 3,
            parent: RefCell::new(Weak::new()),
            children: RefCell::new(vec![]),
        });
        {
            let branch = Rc::new(Node {
                value: 5,
                parent: RefCell::new(Weak::new()),
                children: RefCell::new(vec![Rc::clone(&leaf)]),
            });
            assert!(leaf.parent.borrow().upgrade().is_none());
            assert_eq!(leaf.parent.borrow().strong_count(), 0);
            assert_eq!(leaf.parent.borrow().weak_count(), 0);

            *leaf.parent.borrow_mut() = Rc::downgrade(&branch);
            assert_eq!(Rc::strong_count(&branch), 1);
            assert_eq!(Rc::weak_count(&branch), 1);
            assert!(leaf.parent.borrow().upgrade().is_some());
            let leaf_parent = leaf.parent.borrow().upgrade().unwrap();
            assert_eq!(leaf_parent.value, 5);
        }

        assert!(leaf.parent.borrow().upgrade().is_none());
    }
}

fn main() {}
