fn is_palindrome(s: &str) -> bool {
    let chars: Vec<char> = s.chars().collect();
    let n = chars.len();
    for i in 0..(n / 2) {
        if chars[i] != chars[n - i - 1] {
            return false;
        }
    }
    true
}

fn main() {
    let test_cases = vec![
        ("", true),
        ("a", true),
        ("aaa", true),
        ("aaaa", true),
        ("aaabaaa", true),
        ("aaabbaaa", true),
        ("aaabbbaa", false),
        ("radar", true),
        ("level", true),
        ("racecar", true),
        ("deeds", false),
        ("reviled", false),
    ];
    for (s, expected) in test_cases {
        println!(
            "is_palindrome({s}): {:?} Expect: {expected}",
            is_palindrome(s)
        );
    }
}
