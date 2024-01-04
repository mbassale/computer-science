/*
* [Sedgewick][Ch2][Rust] Exercise 2.2.19 Inversions using merge sort.
*/

#![allow(dead_code)]

fn number_inversions(arr: &Vec<i32>) -> usize {
    if arr.len() < 2 {
        return 0;
    }

    fn merge(arr: &mut Vec<i32>, aux: &mut Vec<i32>, lo: usize, mid: usize, hi: usize) -> usize {
        let mut i = lo;
        let mut j = mid + 1;
        let mut inv_count: usize = 0;
        let mut k = 0;
        while i <= mid && j <= hi {
            if arr[i] <= arr[j] {
                aux[k] = arr[i];
                i += 1;
            } else {
                aux[k] = arr[j];
                j += 1;
                inv_count += (mid + 1) - i;
            }
            k += 1;
        }

        while i <= mid {
            aux[k] = arr[i];
            i += 1;
            k += 1;
        }

        while j <= hi {
            aux[k] = arr[j];
            j += 1;
            k += 1;
        }

        for k in lo..=hi {
            arr[k] = aux[k];
        }

        inv_count
    }

    fn number_inversions_impl(
        arr: &mut Vec<i32>,
        aux: &mut Vec<i32>,
        lo: usize,
        hi: usize,
    ) -> usize {
        if lo >= hi {
            return 0;
        }
        let mid = lo + (hi - lo) / 2;
        number_inversions_impl(arr, aux, lo, mid)
            + number_inversions_impl(arr, aux, mid + 1, hi)
            + merge(arr, aux, lo, mid, hi)
    }

    let sz = arr.len();
    let mut arr = arr.clone();
    let mut aux = arr.clone();
    number_inversions_impl(&mut arr, &mut aux, 0, sz - 1)
}

#[cfg(test)]
mod tests {
    use super::number_inversions;

    #[test]
    fn test_number_inversions() {
        vec![
            (vec![], 0),
            (vec![1], 0),
            (vec![1, 2], 0),
            (vec![1, 2, 3], 0),
            (vec![3, 2, 1], 3),
            (vec![2, 4, 1, 3, 5], 3),
        ]
        .into_iter()
        .for_each(|(arr, expected)| {
            let actual = number_inversions(&arr);
            assert_eq!(actual, expected);
        });
    }
}
