#![allow(dead_code)]

fn shell_sort(arr: &mut Vec<i32>) -> &Vec<i32> {
    let mut h: usize = 1;
    while h < arr.len() / 3 {
        h = 3 * h + 1;
    }
    while h >= 1 {
        for i in h..arr.len() {
            let mut j = i;
            while j >= h && arr[j] < arr[j - h] {
                arr.swap(j, j - h);
                j -= h;
            }
        }
        h /= 3;
    }
    arr
}

#[cfg(test)]
mod tests {
    use super::shell_sort;

    #[test]
    fn test_shell_sort() {
        let test_cases = vec![
            vec![],
            vec![1],
            vec![1, 1],
            vec![2, 1],
            vec![10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0],
        ];
        for test_case in test_cases {
            let mut actual = test_case.clone();
            let actual = shell_sort(&mut actual);
            let mut expected = test_case.clone();
            expected.sort();
            assert_eq!(actual, &expected);
        }
    }
}
