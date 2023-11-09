const THREE_HOURS_IN_SECONDS: u16 = 60 * 60 * 3;

fn tuple_test() {
    let tup = (1, 2, 3);
    let (_x, y, _z) = tup;
    println!("The value of y is: {}", y);
    let z2 = tup.2;
    println!("The value of z is: {}", z2);
}

fn array_test() {
    let a = [1, 2, 3, 4, 5];
    println!("The value of a is: {:?}", a);
    let nil_array = [0; 20];
    println!("The long array: {:?}", nil_array);
}

fn main() {
    println!("Three hours in seconds: {}", THREE_HOURS_IN_SECONDS);
    let mut x = 5;
    println!("The value of x is: {}", x);
    x = 6;
    println!("The value of x if: {}", x);
    tuple_test();
    array_test();
}
