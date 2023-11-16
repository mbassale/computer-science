use function_name::named;

fn trace(name: &str) {
    println!("===== Calling {name} =====")
}

#[named]
fn first_word(s: &String) -> usize {
    trace(function_name!());
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }

    s.len()
}

#[named]
fn test1_without_slices() {
    trace(function_name!());
    let mut s = String::from("hello world");
    let word_idx = first_word(&s);
    s.clear();
    println!("str: {s}, word_idx: {word_idx}");
}

#[named]
fn test2_slices() {
    trace(function_name!());
    let s = String::from("hello world");
    let hello = &s[0..5];
    let world = &s[6..11];
    println!("s: {s}, hello: {hello}, world: {world}");

    let s = String::from("hello");
    println!("s: {s}");
    let slice = &s[0..2];
    println!("s[0..2]: {slice}");
    let slice = &s[..2];
    println!("s[..2]: {slice}");

    let slice = &s[3..s.len()];
    println!("s[3..len]: {slice}");
    let slice = &s[3..];
    println!("s[3..]: {slice}");
}

#[named]
fn first_word_slices(s: &str) -> &str {
    trace(function_name!());
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[..i];
        }
    }

    &s[..]
}

#[named]
fn test3_first_word_slices() {
    trace(function_name!());
    let mut s = String::from("hello world");
    let word = first_word_slices(&s);
    // cannot call clear on mutable ref because we have an inmutable reference.
    // s.clear();
    println!("word: {word}");
}

#[named]
fn test4_array_slices() {
    trace(function_name!());
    let a = [1, 2, 3, 4, 5];
    let slice = &a[1..3];
    assert_eq!(slice, &[2, 3]);
}

fn main() {
    test1_without_slices();
    test2_slices();
    test3_first_word_slices();
    test4_array_slices();
}
