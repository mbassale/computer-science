#![allow(dead_code)]
use std::boxed::Box;
use std::ops::Deref;

#[derive(Debug, PartialEq)]
enum List {
    Cons(i32, Box<List>),
    Nil,
}

impl List {
    fn size(&self) -> usize {
        let &(mut cur) = &self;
        let mut sz: usize = 0;
        loop {
            match cur {
                List::Nil => {
                    return sz;
                }
                List::Cons(_, next) => {
                    sz += 1;
                    cur = next;
                }
            }
        }
    }
}

#[derive(Debug, PartialEq)]
struct MyBox<T>(T);

impl<T> MyBox<T> {
    fn new(x: T) -> MyBox<T> {
        MyBox(x)
    }
}

impl<T> Deref for MyBox<T> {
    type Target = T;

    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

#[derive(Debug)]
struct CustomSmartPointer {
    data: String,
}

impl Drop for CustomSmartPointer {
    fn drop(&mut self) {
        println!("Dropping CustomSmartPointer with data: `{}`", self.data);
    }
}

#[cfg(test)]
mod tests {
    use crate::{
        CustomSmartPointer,
        List::{Cons, Nil},
        MyBox,
    };

    #[test]
    fn test_box() {
        let b = Box::new(5);
        assert_eq!(*b, 5)
    }

    #[test]
    fn test_cons_list() {
        let list = Cons(1, Box::new(Cons(2, Box::new(Cons(3, Box::new(Nil))))));
        assert_eq!(list.size(), 3);
    }

    #[test]
    fn test_references() {
        let x = 5;
        let y = &x;
        assert_eq!(x, 5);
        assert_eq!(*y, 5);

        let y = Box::new(5);
        assert_eq!(*y, 5);

        let y = MyBox::new(x);
        assert_eq!(x, 5);
        assert_eq!(*y, 5);

        // deref coersion
        let message = MyBox::new(String::from("rust"));
        assert_eq!(*message, "rust");
    }

    #[test]
    fn test_drop() {
        let c = CustomSmartPointer {
            data: String::from("test1"),
        };
        let d = CustomSmartPointer {
            data: String::from("test2"),
        };
        println!("c: {:?} d: {:?}", c, d);
        drop(c);
    }
}

fn main() {}
