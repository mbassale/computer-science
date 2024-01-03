#![allow(dead_code)]

use std::cmp::min;

fn bottom_up_merge_sort(arr: &mut Vec<i32>) -> &Vec<i32> {
    let mut aux: Vec<i32> = Vec::with_capacity(arr.len());
    aux.resize(arr.len(), 0);

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

    let n = arr.len();
    if n > 0 {
        let mut sz = 1;
        while sz < n {
            let mut lo = 0;
            while lo < n - sz {
                merge(arr, &mut aux, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
                lo += sz + sz;
            }

            sz = sz + sz;
        }
    }
    arr
}

#[cfg(test)]
mod tests {

    use super::bottom_up_merge_sort;

    #[test]
    fn test_bottom_up_merge_sort() {
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
            let actual = bottom_up_merge_sort(&mut actual);
            let mut expected = test_case.clone();
            expected.sort();
            assert_eq!(actual, &expected);
        });
    }
}
