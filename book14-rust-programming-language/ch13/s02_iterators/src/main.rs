use function_name::named;

fn trace(name: &str) {
    println!("===== Called {name} =====");
}

#[named]
fn test1_iterators() {
    trace(function_name!());
    let v1 = vec![1, 2, 3];
    let v1_iter = v1.iter();
    for val in v1_iter {
        println!("Got: {}", val);
    }

    let v1 = vec![1, 2, 3];
    let mut v1_iter = v1.iter();
    assert_eq!(v1_iter.next(), Some(&1));
    assert_eq!(v1_iter.next(), Some(&2));
    assert_eq!(v1_iter.next(), Some(&3));
    assert_eq!(v1_iter.next(), None);
}

#[named]
fn test2_iterator_sum() {
    trace(function_name!());
    let v1 = vec![1, 2, 3];
    let v1_iter = v1.iter();
    let total: i32 = v1_iter.sum();
    assert_eq!(total, 6);
    println!("Total: {total}");
}

#[named]
fn test3_iterator_production() {
    trace(function_name!());
    let v1 = vec![1, 2, 3];
    let v1_plus_one: Vec<_> = v1.iter().map(|x| x + 1).collect();
    assert_eq!(v1_plus_one, vec![2, 3, 4]);
    dbg!(v1_plus_one);
}

#[derive(PartialEq, Debug)]
struct Shoe {
    size: u32,
    style: String,
}

fn shoes_in_size(shoes: Vec<Shoe>, shoe_size: u32) -> Vec<Shoe> {
    shoes.into_iter().filter(|s| s.size == shoe_size).collect()
}

#[named]
fn test4_closure_capture() {
    trace(function_name!());
    let shoes = vec![
        Shoe {
            size: 10,
            style: String::from("sneaker"),
        },
        Shoe {
            size: 13,
            style: String::from("sandal"),
        },
        Shoe {
            size: 10,
            style: String::from("boot"),
        },
    ];
    let in_my_size = shoes_in_size(shoes, 10);
    assert_eq!(
        in_my_size,
        vec![
            Shoe {
                size: 10,
                style: String::from("sneaker")
            },
            Shoe {
                size: 10,
                style: String::from("boot")
            }
        ]
    );
    dbg!(in_my_size);
}

fn main() {
    test1_iterators();
    test2_iterator_sum();
    test3_iterator_production();
    test4_closure_capture();
}
