use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====")
}

fn area_no_structs(width: u32, height: u32) -> u32 {
    width * height
}

#[named]
fn test1_rectangle_area_no_structs() {
    trace(function_name!());
    let width = 30;
    let height = 50;
    println!(
        "The area of the rectangle is {} square pixels.",
        area_no_structs(width, height)
    );
}

fn area_tuple(dimensions: (u32, u32)) -> u32 {
    dimensions.0 * dimensions.1
}

#[named]
fn test2_rectangle_area_tuple() {
    trace(function_name!());
    let rect1 = (30, 50);
    println!(
        "The area of the rectangle is {} square pixels.",
        area_tuple(rect1)
    );
}

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn area_struct(rectangle: &Rectangle) -> u32 {
    rectangle.width * rectangle.height
}

#[named]
fn test3_rectangle_area_struct() {
    trace(function_name!());
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };
    println!(
        "The area of the rectangle is {} square pixels.",
        area_struct(&rect1)
    );
    dbg!(rect1);
}

fn main() {
    test1_rectangle_area_no_structs();
    test2_rectangle_area_tuple();
    test3_rectangle_area_struct();
}
