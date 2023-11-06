def calc():
    f = 0
    g = 1
    for i in range(0, 16):
        print(f)
        f = f + g
        g = f - g


if __name__ == "__main__":
    calc()
