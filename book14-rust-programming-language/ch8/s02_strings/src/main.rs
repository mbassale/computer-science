use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====");
}

#[named]
fn test1_string() {
    trace(function_name!());
    let s1 = "initial contents";
    dbg!(s1);
    let s2 = s1.to_string();
    dbg!(s2);
    let s3 = String::from(s1);
    dbg!(s3);
    let s4 = "initial contents".to_string();
    dbg!(s4);
}

#[named]
fn test2_update() {
    trace(function_name!());
    let mut s = String::from("foo");
    s.push_str("bar");
    let s2 = "bar";
    s.push_str(s2);
    dbg!(s);

    let s1 = String::from("Hello, ");
    let s2 = String::from("world!");
    let s3 = s1 + &s2;
    dbg!(s3);

    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");
    let s = s1 + "-" + &s2 + "-" + &s3;
    dbg!(s);

    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");
    let s = format!("{s1}-{s2}-{s3}");
    dbg!(s);
}

#[named]
fn test3_iteration() {
    trace(function_name!());
    let s = "Здравствуйте";
    for c in s.chars() {
        println!("c: {c}");
    }
}

fn main() {
    test1_string();
    test2_update();
    test3_iteration();
}
