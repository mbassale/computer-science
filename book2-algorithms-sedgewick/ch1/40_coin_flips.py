import random
import inspect

NUM_TRIALS = 10000000


class Counter:
    def __init__(self, id: str, initial_value: int = 0):
        self.id = id
        self.value = initial_value

    def increment(self) -> None:
        self.value += 1

    def tally(self) -> int:
        return self.value

    def __str__(self) -> str:
        return f"{self.value} {self.id}"

    @classmethod
    def max(cls, counter1: "Counter", counter2: "Counter") -> "Counter":
        return cls("max", max(counter1.value, counter2.value))


def test0_counter() -> None:
    print(f"===== Calling: {inspect.currentframe().f_code.co_name} =====")
    heads = Counter("heads")
    tails = Counter("tails")
    for i in range(NUM_TRIALS):
        if random.random() < 0.5:
            heads.increment()
        else:
            tails.increment()
    print(heads)
    print(tails)
    delta = abs(heads.tally() - tails.tally())
    print(f"delta: {delta}")
    print(Counter.max(heads, tails))


def test1_rolling_dice_simulation() -> None:
    print(f"===== Calling: {inspect.currentframe().f_code.co_name} =====")
    SIDES = 6
    rolls = [Counter(f"{i}") for i in range(0, SIDES + 1)]
    for _ in range(NUM_TRIALS):
        result = random.randint(1, SIDES)
        rolls[result].increment()
    for counter in [c for c in rolls if c.tally() > 0]:
        print(counter)


if __name__ == "__main__":
    test0_counter()
    test1_rolling_dice_simulation()
