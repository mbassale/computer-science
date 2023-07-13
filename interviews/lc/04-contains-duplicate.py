from typing import List


def containsDuplicate(nums: List[int]) -> bool:
    seen = {}
    for i in nums:
        if i in seen:
            return True
        seen[i] = True
    return False


def runTestCase(nums: List[int], expected: bool) -> None:
    numsStr = ",".join([str(n) for n in nums])
    actual = containsDuplicate(nums)
    print(f"{numsStr} => Expected: {expected} Actual: {actual}")


if __name__ == "__main__":
    runTestCase([1, 2, 3, 1], True)
    runTestCase([1, 2, 3, 4], False)
    runTestCase([1, 1, 1, 3, 3, 4, 3, 2, 4, 2], True)
