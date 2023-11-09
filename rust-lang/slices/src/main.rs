
fn main() {
    let s = String::from("Hello, world!");
    let first_word_index = first_word(&s);
    let s2 = &s[0..first_word_index];
    println!("First Word: {}", s2);

    let s3 = first_word2(&s);
    println!("First Word: {}", s3);
}

fn first_word(s: &String) -> usize {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }
    s.len()
}

fn first_word2(s: &String) -> &str {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    &s[..]
}