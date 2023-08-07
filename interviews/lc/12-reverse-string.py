
def reverseStr(s: str) -> str:
    return "".join([c for c in reversed(s)])


def reverseList(s: str) -> str:
    lst = [ord(i) for i in s]
    left = 0
    right = len(lst) - 1
    while left < right:
        lst[left], lst[right] = lst[right], lst[left]
        left += 1
        right -= 1
    return "".join([chr(i) for i in lst])


def runTestCase(s: str) -> None:
    s1 = reverseStr(s)
    s2 = reverseList(s)
    print(f"Original: {s} Reversed BuildIn: {s1} Reversed List: {s2}")


if __name__ == "__main__":
    runTestCase('Hello, World!')
    runTestCase('Lorem Ipsum Dolor Senet')

