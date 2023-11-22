class Date1:
    def __init__(self, m: int, d: int, y: int):
        self._month = m
        self._day = d
        self._year = y

    def month(self) -> int:
        return self._month

    def day(self) -> int:
        return self._day

    def year(self) -> int:
        return self._year

    def __str__(self) -> str:
        return f"{self.month()}/{self.day()}/{self.year()}"


class Date2:
    def __init__(self, m: int, d: int, y: int):
        self.value = y * 512 + m * 32 + d

    def month(self) -> int:
        return int(self.value / 32) % 16

    def day(self) -> int:
        return self.value % 32

    def year(self) -> int:
        return int(self.value / 512)

    def __str__(self) -> str:
        return f"{self.month()}/{self.day()}/{self.year()}"


if __name__ == "__main__":
    testCases = [(11, 22, 2023), (8, 15, 1984), (12, 10, 2001)]
    for testCase in testCases:
        (m, d, y) = testCase
        date1 = Date1(m, d, y)
        print("Date1:", date1)
        date2 = Date2(m, d, y)
        print("Date2:", date2)
