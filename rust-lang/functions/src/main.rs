fn main() {
    println!("Hello, world!");
    another_function(10);
    print_labelel_measurements(5, 'h');

    let y = {
        let x = 3;
        x + 1
    };
    println!("The value of y is: {}", y);

    let ret1 = five();
    println!("The value of ret1 is: {}", ret1);

    let x = plus_one(5);
    println!("The value of x is: {}", x);
}

fn another_function(x: i32) {
    println!("The value of x is: {}", x);
}

fn print_labelel_measurements(value: i32, unit_label: char) {
    println!("The measurement is: {}{}", value, unit_label);
}

fn five() -> i32 {
    5
}

fn plus_one(x: i32) -> i32 {
    x + 1
}