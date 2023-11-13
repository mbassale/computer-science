use std::io;

fn test0_float() {
    let x = 1.0 / 3.0; // f64
    println!("x: {x}");
    let y: f32 = 1.0 / 3.0;
    println!("y: {y}");
}

fn test1_boolean() {
    let t = true;
    println!("true: {t}");
    let f: bool = false;
    println!("false: {f}");
}

fn test2_char() {
    let c = 'z';
    println!("c: {c}");
    let z: char = 'ℤ';
    println!("Z: {z}");
    let heart_eyed_cat = '😻';
    println!("Emoji: {heart_eyed_cat}");
}

fn test3_tuple() {
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    println!("tup: {:?}", tup);
    let (x, y, z) = tup;
    println!("x: {x}, y: {y}, z: {z}");
    let x = tup.0;
    println!("x: {x}");
    let y = tup.1;
    println!("y: {y}");
    let z = tup.2;
    println!("z: {z}");
}

fn test4_array() {
    let a = [1, 2, 3, 4, 5];
    println!("a: {:?}", a);

    let a: [i32; 5] = [1, 2, 3, 4, 5];
    println!("a: {:?}", a);

    let a = [0; 5];
    println!("a: {:?}", a);

    let a = [1, 2, 3, 4, 5];
    let mut index = String::new();
    io::stdin()
        .read_line(&mut index)
        .expect("Failed to read line");
    let index: usize = index
        .trim()
        .parse()
        .expect("Index entered was not a number");
    let element = a[index];
    println!("The value of the element at index {index} is: {element}");
}

fn main() {
    test0_float();
    test1_boolean();
    test2_char();
    test3_tuple();
    test4_array();
}
