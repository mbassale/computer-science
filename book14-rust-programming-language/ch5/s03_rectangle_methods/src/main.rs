use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====")
}

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn square(size: u32) -> Self {
        Self {
            width: size,
            height: size,
        }
    }

    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

#[named]
fn test1_rectangle_area() {
    trace(function_name!());
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };
    println!(
        "The area of the rectangle is {} square pixels.",
        rect1.area()
    );
}

#[named]
fn test2_rectangle_can_hold() {
    trace(function_name!());
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };
    let rect2 = Rectangle {
        width: 10,
        height: 40,
    };
    let rect3 = Rectangle {
        width: 60,
        height: 45,
    };
    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
    println!("Can rect1 hold rect3? {}", rect1.can_hold(&rect3));
}

#[named]
fn test3_associated_function() {
    trace(function_name!());
    let sq1 = Rectangle::square(10);
    println!("Square: {:?}", sq1);
}

fn main() {
    test1_rectangle_area();
    test2_rectangle_can_hold();
    test3_associated_function();
}
