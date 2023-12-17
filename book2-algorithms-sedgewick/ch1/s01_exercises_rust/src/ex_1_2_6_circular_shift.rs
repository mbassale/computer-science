fn is_circular_rotation(s1: &str, s2: &str) -> bool {
    let s3 = String::from(s1) + s1;
    s3.find(s2).is_some()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_is_circular_rotation() {
        let test_cases: [(&str, &str, bool); 8] = [
            ("", "", true),
            ("A", "A", true),
            ("AA", "AA", true),
            ("ABC", "CAB", true),
            ("ABA", "BAA", true),
            ("ABA", "AAC", false),
            ("ACTGACG", "TGACGAC", true),
            ("CTGACG", "TGACGAC", false),
        ];
        for (s1, s2, expected) in test_cases {
            assert_eq!(is_circular_rotation(s1, s2), expected);
        }
    }
}
