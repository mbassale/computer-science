from typing import List


def maxProfit(prices: List[int]) -> int:
    buyIdx = None
    profit = 0
    for i in range(0, len(prices) - 1):
        if buyIdx is None and prices[i] < prices[i + 1]:
            buyIdx = i
        if buyIdx is not None and prices[i] > prices[i + 1]:
            profit += prices[i] - prices[buyIdx]
            buyIdx = None
    if buyIdx is not None:
        profit += prices[-1] - prices[buyIdx]
    return profit


def runTestCase(prices: List[int], expected: int) -> None:
    pricesStr = ",".join([str(p) for p in prices])
    profit = maxProfit(prices)
    print(f"{pricesStr} => Expected: {expected} Actual: {profit}")


if __name__ == "__main__":
    runTestCase([7, 1, 5, 3, 6, 4], 7)
    runTestCase([1, 2, 3, 4, 5], 4)
    runTestCase([7, 6, 4, 3, 1], 0)
