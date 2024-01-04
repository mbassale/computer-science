/*
* [Sedgewick][Ch2] Exercise 2.2.18 Shuffle using Merge Sort. Shuffle for an array.
*/

#![allow(dead_code)]

use rand::random;

fn shuffle_array(arr: &mut Vec<i32>) {
    if arr.len() < 2 {
        return;
    }

    fn merge(arr: &mut Vec<i32>, aux: &mut Vec<i32>, lo: usize, mid: usize, hi: usize) {
        // shuffle aux between left and right subarrays
        let mut i = lo;
        let mut j = mid + 1;
        let mut k = lo;
        while i <= mid && j <= hi {
            if random::<bool>() {
                aux[k] = arr[i];
                i += 1;
            } else {
                aux[k] = arr[j];
                j += 1;
            }
            k += 1;
        }

        // consume remainder of left subarray
        while i <= mid {
            aux[k] = arr[i];
            i += 1;
            k += 1;
        }

        // consume remainder of right subarray
        while j <= hi {
            aux[k] = arr[j];
            j += 1;
            k += 1;
        }

        // copy aux to arr
        for k in lo..=hi {
            arr[k] = aux[k];
        }
    }

    fn shuffle_impl(arr: &mut Vec<i32>, aux: &mut Vec<i32>, lo: usize, hi: usize) {
        if lo >= hi {
            return;
        }

        let mid = lo + (hi - lo) / 2;
        shuffle_impl(arr, aux, lo, mid);
        shuffle_impl(arr, aux, mid + 1, hi);
        merge(arr, aux, lo, mid, hi);
    }

    let mut aux = arr.clone();
    shuffle_impl(arr, &mut aux, 0, arr.len() - 1);
}

#[cfg(test)]
mod tests {

    use super::shuffle_array;

    #[test]
    fn test_shuffle_array() {
        vec![
            vec![],
            vec![1],
            vec![1, 2],
            vec![1, 2, 3],
            vec![1, 2, 3, 4],
            vec![1, 2, 3, 4, 5],
            vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
        ]
        .into_iter()
        .for_each(|arr| {
            let mut actual = arr.clone();
            shuffle_array(&mut actual);
            dbg!(&actual);
            actual.sort();
            assert_eq!(arr, actual);
        });
    }
}
