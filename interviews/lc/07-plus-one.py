from typing import List


def plusOne(digits: List[int]) -> List[int]:
    rdigits = list(reversed(digits))
    carry = 1
    for i in range(0, len(rdigits)):
        res = rdigits[i] + carry
        if res == 10:
            res = 0
            carry = 1
        else:
            carry = 0
        rdigits[i] = res
    if carry > 0:
        rdigits.append(carry)
    return list(reversed(rdigits))


def runTestCase(digits: List[int]) -> None:
    digitsStr = ",".join([str(n) for n in digits])
    result = plusOne(digits)
    resultStr = ",".join([str(n) for n in result])
    print(f"{digitsStr} + 1 => {resultStr}")


if __name__ == "__main__":
    runTestCase([1, 2, 3])
    runTestCase([4, 3, 2, 1])
    runTestCase([9, 9, 9, 9])
