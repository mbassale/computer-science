use function_name::named;
use rand::{thread_rng, Rng};
use std::collections::HashMap;

fn trace(name: &str) {
    println!("===== Calling {name} =====");
}

fn make_random_array() -> Vec<i32> {
    let mut lst = Vec::new();
    let mut rng = thread_rng();
    for i in 1..=100 {
        let num = rng.gen_range(1..=100);
        lst.push(num);
    }
    lst.sort();
    return lst;
}

#[named]
fn calculate_median(lst: &Vec<i32>) -> f32 {
    trace(function_name!());
    return if lst.len() % 2 == 0 {
        let mid = lst.len() / 2;
        (lst[mid - 1] + lst[mid]) as f32 / 2.0
    } else {
        lst[lst.len() / 2] as f32
    };
}

#[named]
fn calculate_mode_hash(lst: &Vec<i32>) -> i32 {
    trace(function_name!());
    let mut frequencies: HashMap<i32, usize> = HashMap::new();
    for num in lst {
        let entry = frequencies.entry(*num).or_insert(0);
        *entry += 1;
    }
    let mut max_freq = std::usize::MIN;
    let mut max_num: i32 = 0;
    for (num, count) in frequencies {
        if count > max_freq {
            max_freq = count;
            max_num = num;
        }
    }
    return max_num;
}

#[named]
fn calculate_mode_sorted_array(lst: &Vec<i32>) -> i32 {
    trace(function_name!());
    let mut max_freq: usize = 0;
    let mut max_num = 0;
    let mut freq: usize = 1;
    for i in 1..lst.len() {
        freq += 1;
        if lst[i - 1] != lst[i] {
            if freq > max_freq {
                max_freq = freq;
                max_num = lst[i - 1];
            }
            freq = 1;
        }
    }
    if freq > max_freq {
        max_num = lst[lst.len() - 1];
    }
    return max_num;
}

#[named]
fn main() {
    trace(function_name!());

    // generate random number list
    let numbers = make_random_array();
    println!("numbers: {:?}", numbers);

    // get the median
    let median = calculate_median(&numbers);
    println!("Median: {median}");

    // get the mode
    let mode = calculate_mode_hash(&numbers);
    println!("Mode HashMap: {mode}");

    let mode = calculate_mode_sorted_array(&numbers);
    println!("Mode Sorted Array: {mode}");
}
