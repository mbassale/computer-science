/*
* [Sedgewick][Ch2] Quick Sort
*
* Comparison between merge_sort, merge_sort_improved and quick_sort for 10,000 random i32s.
* $ cargo test
* [snip]
* test s04_merge_sort::tests::test_merge_sort ... ok
* test s06_merge_sort_improved::tests::test_merge_improved ... ok
* test s07_quick_sort::tests::test_quick_sort ... ok
* merge_sort(Vec<i32>(10000 nums)): 825ms
* merge_sort_improved(Vec<i32>(10000 nums)): 697ms
* quick_sort(Vec<i32>(10000 nums)): 193ms
* test s06_merge_sort_improved::tests::test_merge_sort_and_improved ... ok

* test result: ok. 10 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 1.98s
*/
#![allow(dead_code)]

pub fn quick_sort(arr: &mut Vec<i32>) {
    if arr.len() < 2 {
        return;
    }

    fn partition(arr: &mut Vec<i32>, lo: usize, hi: usize) -> usize {
        let mut i = lo;
        let mut j = hi + 1;
        // select pivot
        let pivot = arr[lo];

        loop {
            // move from left to right while values are less than the pivot
            i += 1;
            while i < hi && arr[i] < pivot {
                if i == hi {
                    break;
                }
                i += 1;
            }

            // move from right to left while values are greater than the pivot
            j -= 1;
            while j > lo && arr[j] > pivot {
                if j == lo {
                    break;
                }
                j -= 1;
            }

            // if the values cross, bail out
            if i >= j {
                break;
            }

            // exchange left and right pointers
            arr.swap(i, j);
        }

        // exchange the pivot with the left most position from the right
        arr.swap(lo, j);
        // now the pivot its in the final position
        j
    }

    // divide-and-conquer template
    fn quick_sort_impl(arr: &mut Vec<i32>, lo: usize, hi: usize) {
        if lo >= hi {
            return;
        }
        let j = partition(arr, lo, hi);
        if j > 0 {
            quick_sort_impl(arr, lo, j - 1);
        }
        if j < arr.len() {
            quick_sort_impl(arr, j + 1, hi);
        }
    }

    quick_sort_impl(arr, 0, arr.len() - 1);
}

#[cfg(test)]
mod tests {
    use super::quick_sort;
    use rand::{distributions::Distribution, distributions::Uniform, thread_rng};

    #[test]
    fn test_quick_sort() {
        // Create a random number generator
        let mut rng = thread_rng();

        // Define the range as 1 to 100,000 inclusive
        let die = Uniform::from(1..=100000);

        // Generate and collect the numbers
        let random_numbers: Vec<i32> = (0..1000000).map(|_| die.sample(&mut rng)).collect();

        vec![
            vec![],
            vec![1],
            vec![2, 1],
            vec![3, 2, 1],
            vec![10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
            random_numbers,
        ]
        .into_iter()
        .for_each(|arr| {
            let mut expected = arr.clone();
            expected.sort();
            let mut actual = arr.clone();
            quick_sort(&mut actual);
            assert_eq!(actual, expected);
        });
    }
}
