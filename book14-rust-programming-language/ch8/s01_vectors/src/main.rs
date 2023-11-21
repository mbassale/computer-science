use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====");
}

#[named]
fn test1_vector() {
    trace(function_name!());
    let v: Vec<i32> = Vec::new();
    dbg!(v);
    let v = vec![1, 2, 3];
    dbg!(v);
}

#[named]
fn test2_vector_update() {
    trace(function_name!());
    let mut v: Vec<i32> = Vec::new();
    for i in 0..5 {
        v.push(i);
    }
    dbg!(v);
}

#[named]
fn test3_vector_reading() {
    trace(function_name!());
    let mut v = vec![1, 2, 3, 4, 5];
    let third: &i32 = &v[2];
    dbg!(third);

    let third: Option<&i32> = v.get(2);
    match third {
        Some(third) => println!("third: {third}"),
        None => println!("No third element"),
    }

    dbg!(v.len());
    v.push(6);
    let first = &v[0];
    println!("first: {first}");
    dbg!(v.len());
}

#[named]
fn test4_vector_iteration() {
    trace(function_name!());
    let mut v = vec![1, 2, 3, 4, 5];
    for i in &v {
        println!("{i}");
    }

    for i in &mut v {
        *i += 10;
    }
    dbg!(v);
}

#[derive(Debug)]
enum SpreadsheetCell {
    Int(i32),
    Float(f64),
    Text(String),
}

#[named]
fn test5_vector_enum() {
    trace(function_name!());
    let row = vec![
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Text(String::from("red")),
        SpreadsheetCell::Float(10.23),
    ];
    dbg!(row);
}

fn main() {
    test1_vector();
    test2_vector_update();
    test3_vector_reading();
    test4_vector_iteration();
    test5_vector_enum();
}
