def task0():
    t = 9.0
    while abs(t - 9.0 / t) > 0.001:
        t = (9.0 / t + t) / 2.0
    print(f"task0: {t:.5f}")


def task1():
    sum = 0
    for i in range(1, 1000):
        for j in range(0, i):
            sum += 1
    print(f"task1: {sum}")


def task2():
    sum = 0
    i = 1
    while i < 1000:
        for j in range(0, 1000):
            sum += 1
        i *= 2
    print(f"task2: {sum}")


if __name__ == "__main__":
    task0()
    task1()
    task2()
