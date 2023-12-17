//

fn binary_search_impl(a: &Vec<i32>, key: i32, left: usize, right: usize) -> Option<usize> {
    if left > right {
        return None;
    }
    let mid = left + (right - left) / 2;
    if a[mid] == key {
        return Some(mid);
    }
    
    if mid > 0 && a[mid] < key {
        return binary_search_impl(a, key, left, mid - 1);
    } else if mid + 1 < a.len() && a[mid] > key {
        return binary_search_impl(a, key, mid + 1, right);
    }
    return None
}

pub fn binary_search(a: Vec<i32>, key: i32) -> Option<usize> {
    if a.len() == 0 {
        return None
    }
    binary_search_impl(&a, key, 0, a.len() - 1)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_binary_search() {
        let test_cases: [(Vec<i32>, i32, Option<usize>); 4] = [
            (Vec::from([]), 10, None),
            (Vec::from([1]), 1, Some(0)),
            (Vec::from([1]), 2, None),
            (Vec::from([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), 5, Some(4)),
        ];
        for (a, key, expected) in test_cases {
            let result = binary_search(a, key);
            assert_eq!(result, expected);
        }
    }
}
