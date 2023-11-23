# Algorithms: Sedgewick, Ch1 Ex 1.2.6 Circular Shift


def is_circular_rotation(s1: str, s2: str) -> bool:
    """
    Returns true if s2 is a circular rotation of s1.
    """
    return s2 in s1 + s1


def run():
    test_cases = [
        ("", "", True),
        ("A", "A", True),
        ("AA", "AA", True),
        ("ABC", "CAB", True),
        ("ABA", "BAA", True),
        ("ABA", "AAC", False),
        ("ACTGACG", "TGACGAC", True),
        ("CTGACG", "TGACGAC", False),
    ]
    for test_case in test_cases:
        print(
            f"is_circular_rotation({test_case[0]}, {test_case[1]}): ",
            is_circular_rotation(test_case[0], test_case[1]),
            f"Expected: {test_case[2]}",
        )


if __name__ == "__main__":
    run()
