/*
$ ./01-absolute-value
|-10| 10
|10| 10
|-3.14| 3.14
|3.14| 3.14
*/
use std::cmp::PartialOrd;
use std::ops::Neg;

/*
 * Generic abs() function.
 * The type must support:
 * - Partial ordering for comparison: PartialOrd
 * - Be default-constructible: Default
 * - Be capable of negation: Neg
 */
fn abs<T: PartialOrd + Neg<Output = T> + Default>(x: T) -> T {
    if x < T::default() {
        return -x;
    } else {
        return x;
    }
}

fn main() {
    println!("|-10| {}", abs(-10));
    println!("|10| {}", abs(10));
    println!("|-3.14| {}", abs(-3.14));
    println!("|3.14| {}", abs(3.14));
}
