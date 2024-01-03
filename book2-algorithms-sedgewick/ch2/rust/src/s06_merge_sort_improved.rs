#![allow(dead_code)]

fn merge_sort_improved(arr: &mut Vec<i32>) -> &Vec<i32> {
    let mut aux = arr.clone();

    const CUT_OFF_INSERTION_SORT: usize = 20;

    fn insertion_sort(arr: &mut Vec<i32>, lo: usize, hi: usize) {
        for i in lo..=hi {
            let mut j = i;
            while j > lo && arr[j] < arr[j - 1] {
                arr.swap(j, j - 1);
                j -= 1;
            }
        }
    }

    fn merge(arr: &mut Vec<i32>, aux: &mut Vec<i32>, lo: usize, mid: usize, hi: usize) {
        // copy arr[lo..=hi] into aux
        for k in lo..=hi {
            aux[k] = arr[k];
        }

        let mut i = lo;
        let mut j = mid + 1;
        for k in lo..=hi {
            if i > mid {
                arr[k] = aux[j];
                j += 1;
            } else if j > hi {
                arr[k] = aux[i];
                i += 1;
            } else if aux[i] <= aux[j] {
                arr[k] = aux[i];
                i += 1;
            } else if aux[j] < aux[i] {
                arr[k] = aux[j];
                j += 1;
            }
        }
    }

    fn is_sorted(arr: &Vec<i32>, lo: usize, hi: usize) -> bool {
        let mut k = lo;
        while k < hi {
            if arr[k] > arr[k + 1] {
                return false;
            }
            k += 1;
        }
        true
    }

    fn merge_sort_impl(arr: &mut Vec<i32>, aux: &mut Vec<i32>, lo: usize, hi: usize) {
        if lo >= hi {
            return;
        }
        // bail out if subarray is sorted
        if is_sorted(arr, lo, hi) {
            return;
        }
        if (hi - lo) <= CUT_OFF_INSERTION_SORT {
            insertion_sort(arr, lo, hi);
            return;
        }

        let mid = lo + (hi - lo) / 2;
        merge_sort_impl(arr, aux, lo, mid);
        merge_sort_impl(arr, aux, mid + 1, hi);
        if arr[mid] > arr[mid + 1] {
            merge(arr, aux, lo, mid, hi);
        }
    }

    if arr.len() > 0 {
        merge_sort_impl(arr, &mut aux, 0, arr.len() - 1);
    }
    arr
}

#[cfg(test)]
mod tests {

    use super::merge_sort_improved;
    use crate::s04_merge_sort::merge_sort;
    use rand::distributions::{Distribution, Uniform};
    use rand::thread_rng;
    use std::time::Instant;

    #[test]
    fn test_merge_improved() {
        vec![
            vec![],
            vec![1],
            vec![1, 1],
            vec![2, 1],
            vec![10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0],
        ]
        .into_iter()
        .for_each(|test_case| {
            let mut actual = test_case.clone();
            let actual = merge_sort_improved(&mut actual);
            let mut expected = test_case.clone();
            expected.sort();
            assert_eq!(actual, &expected);
        });
    }

    #[test]
    fn test_merge_sort_and_improved() {
        // Create a random number generator
        let mut rng = thread_rng();

        // Define the range as 1 to 100,000 inclusive
        let die = Uniform::from(1..=100000);

        // Generate and collect the numbers
        let random_numbers: Vec<i32> = (0..1000000).map(|_| die.sample(&mut rng)).collect();

        let mut test_case1 = random_numbers.clone();
        let start = Instant::now();
        merge_sort(&mut test_case1);
        let duration = start.elapsed();
        println!(
            "merge_sort(Vec<i32>(10000 nums)): {}ms",
            duration.as_millis()
        );

        let mut test_case2 = random_numbers.clone();
        let start = Instant::now();
        merge_sort_improved(&mut test_case2);
        let duration = start.elapsed();
        println!(
            "merge_sort_improved(Vec<i32>(10000 nums)): {}ms",
            duration.as_millis()
        );
    }
}
