#![allow(dead_code)]

pub fn merge_sort(arr: &mut Vec<i32>) -> &Vec<i32> {
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

    fn merge_sort_impl(arr: &mut Vec<i32>, aux: &mut Vec<i32>, lo: usize, hi: usize) {
        if lo >= hi {
            return;
        }

        let mid = lo + (hi - lo) / 2;
        merge_sort_impl(arr, aux, lo, mid);
        merge_sort_impl(arr, aux, mid + 1, hi);
        merge(arr, aux, lo, mid, hi);
    }

    if arr.len() > 0 {
        merge_sort_impl(arr, &mut aux, 0, arr.len() - 1);
    }
    arr
}

#[cfg(test)]
mod tests {

    use super::merge_sort;

    #[test]
    fn test_merge_sort() {
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
            let actual = merge_sort(&mut actual);
            let mut expected = test_case.clone();
            expected.sort();
            assert_eq!(actual, &expected);
        });
    }
}
