use function_name::named;
use std::collections::HashMap;

fn trace(name: &str) {
    println!("===== Calling {name} =====");
}

#[named]
fn test1_hashmaps() {
    trace(function_name!());

    let mut scores = HashMap::new();
    scores.insert(String::from("blue"), 10);
    scores.insert(String::from("yellow"), 50);
    let scores = dbg!(scores);

    let team_name = String::from("blue");
    let score = scores.get(&team_name).copied().unwrap_or(0);
    println!("Blue team score: {score}");
}

#[named]
fn test2_iterator() {
    trace(function_name!());

    let mut scores = HashMap::new();
    scores.insert(String::from("blue"), 10);
    scores.insert(String::from("yellow"), 50);

    for (key, value) in &scores {
        println!("{key}: {value}");
    }
}

#[named]
fn test3_update() {
    trace(function_name!());

    let mut scores = HashMap::new();
    scores.insert(String::from("blue"), 10);
    scores.insert(String::from("blue"), 25);
    println!("{:?}", scores);

    let mut scores = HashMap::new();
    scores.insert(String::from("blue"), 10);

    scores.entry(String::from("Yellow")).or_insert(50);
    scores.entry(String::from("blue")).or_insert(50);

    println!("{:?}", scores);
}

#[named]
fn test4_update_old_values() {
    trace(function_name!());
    let text = "hello world hola world";
    let mut word_frequencies = HashMap::new();

    for word in text.split_whitespace() {
        let count = word_frequencies.entry(word).or_insert(0);
        *count += 1
    }

    println!("{:?}", word_frequencies);
}

fn main() {
    test1_hashmaps();
    test2_iterator();
    test3_update();
    test4_update_old_values();
}
