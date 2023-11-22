def isPalindrome(s: str) -> bool:
    n = len(s)
    for i in range(0, int(n / 2)):
        if s[i] != s[n - i - 1]:
            return False
    return True


if __name__ == "__main__":
    testCases = [
        ("", True),
        ("a", True),
        ("aaa", True),
        ("aaaa", True),
        ("aaabaaa", True),
        ("aaabbaaa", True),
        ("aaabbbaa", False),
        ("radar", True),
        ("level", True),
        ("racecar", True),
        ("deeds", True),
        ("reviled", True),
    ]
    for testCase in testCases:
        print(
            f"isPalindrome({testCase[0]}):",
            isPalindrome(testCase[0]),
            "Expect:",
            testCase[1],
        )
