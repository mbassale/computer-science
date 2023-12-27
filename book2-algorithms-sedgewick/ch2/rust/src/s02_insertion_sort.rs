#![allow(dead_code)]

fn insertion_sort(arr: &mut Vec<i32>) -> &Vec<i32> {
    for i in 1..arr.len() {
        let mut j = i;
        while j > 0 && arr[j] < arr[j - 1] {
            arr.swap(j, j - 1);
            j -= 1;
        }
    }
    arr
}

#[cfg(test)]
mod tests {
    use super::insertion_sort;

    #[test]
    fn test_insertion_sort() {
        let test_cases = vec![
            vec![],
            vec![1],
            vec![1, 1],
            vec![2, 1],
            vec![10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0],
        ];
        for test_case in test_cases {
            let mut actual = test_case.clone();
            let actual = insertion_sort(&mut actual);
            let mut expected = test_case.clone();
            expected.sort();
            assert_eq!(actual, &expected);
        }
    }
}
