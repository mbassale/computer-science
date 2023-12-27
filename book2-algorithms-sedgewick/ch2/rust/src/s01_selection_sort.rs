#![allow(dead_code)]

fn selection_sort(arr: &mut Vec<i32>) -> &Vec<i32> {
    for i in 0..arr.len() {
        let mut min_index = i;
        for j in (i + 1)..arr.len() {
            if arr[j] < arr[min_index] {
                min_index = j;
            }
        }
        arr.swap(i, min_index);
    }
    arr
}

#[cfg(test)]
mod tests {
    use super::selection_sort;

    #[test]
    fn test_selection_sort() {
        let test_cases = vec![
            vec![],
            vec![1],
            vec![1, 1],
            vec![2, 1],
            vec![10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0],
        ];
        for test_case in test_cases {
            let mut actual = test_case.clone();
            let actual = selection_sort(&mut actual);
            let mut expected = test_case.clone();
            expected.sort();
            assert_eq!(actual, &expected);
        }
    }
}
