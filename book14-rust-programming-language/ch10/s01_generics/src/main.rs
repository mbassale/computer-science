use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====");
}

#[named]
fn largest_no_generics(list: &[i32]) -> &i32 {
    trace(function_name!());
    let mut largest = &list[0];
    for item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}

#[named]
fn test1_no_generics() {
    trace(function_name!());
    let test_cases = vec![vec![1, 2, 3, 4, 5], vec![0, 0, 0, 0, 0], vec![0]];
    for test_case in test_cases {
        println!(
            "list: {:?} largest: {}",
            test_case,
            largest_no_generics(&test_case)
        );
    }
}

#[named]
fn largest<T: std::cmp::PartialOrd>(list: &[T]) -> &T {
    trace(function_name!());
    let mut largest = &list[0];
    for item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}

#[named]
fn test2_generics() {
    trace(function_name!());
    let number_list = vec![34, 50, 25, 100, 65];
    let result = largest(&number_list);
    println!("list: {:?} largest: {}", number_list, result);

    let char_list = vec!['y', 'm', 'a', 'q'];
    let result = largest(&char_list);
    println!("list: {:?} largest: {}", char_list, result);
}

#[derive(Debug)]
struct Point<T, U> {
    x: T,
    y: U,
}

impl<T, U> Point<T, U> {
    fn x(&self) -> &T {
        &self.x
    }
}

impl Point<f32, f32> {
    fn distance_from_origin(&self) -> f32 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

#[named]
fn test3_generic_structs() {
    trace(function_name!());
    let integer = Point { x: 5, y: 10 };
    dbg!(integer);
    let float: Point<f32, f32> = Point { x: 1.0, y: 4.0 };
    let float = dbg!(float);
    let mixed = Point { x: 5, y: 4.0 };
    let mixed = dbg!(mixed);
    println!("mixed.y: {}", &mixed.y);
    println!(
        "float: {:?} distance_from_origin: {}",
        float,
        float.distance_from_origin()
    );
}

fn main() {
    test1_no_generics();
    test2_generics();
    test3_generic_structs();
}
