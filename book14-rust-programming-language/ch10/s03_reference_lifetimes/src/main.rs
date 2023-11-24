use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====");
}

#[named]
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    trace(function_name!());
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

#[named]
fn test1_generic_lifetimes() {
    trace(function_name!());
    let string1 = String::from("abcd");
    {
        let string2 = "xyz";
        let result = longest(&string1.as_str(), string2);
        println!("The longest string is: {}", result);
    }
}

#[derive(Debug)]
struct ImportantExcerpt<'a> {
    part: &'a str,
}

impl<'a> ImportantExcerpt<'a> {
    fn level(&self) -> i32 {
        3
    }

    fn announce_and_return_part(&self, announcement: &str) -> &str {
        println!("Attention please: {}", announcement);
        self.part
    }
}

#[named]
fn test2_struct_definitions() {
    trace(function_name!());
    let novel = String::from("lorem ipsum dolor senet. Ut enim ad minim veniam.");
    let first_sentence = novel.split('.').next().expect("Could not find a '.'");
    let excerpt = ImportantExcerpt {
        part: first_sentence,
    };
    let excerpt = dbg!(excerpt);

    println!("level: {}", excerpt.level());
    println!(
        "announce: {}",
        excerpt.announce_and_return_part("Hello, world!")
    );
}

fn get_static_lifetime_var() -> &'static str {
    let s: &'static str = "singleton variable";
    s
}

#[named]
fn test3_static_lifetime() {
    trace(function_name!());
    let s;
    {
        s = get_static_lifetime_var();
    }
    println!("static: {s}");
}

fn main() {
    test1_generic_lifetimes();
    test2_struct_definitions();
    test3_static_lifetime();
}
