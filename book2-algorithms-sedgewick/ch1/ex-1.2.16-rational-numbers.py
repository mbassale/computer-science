class Rational:
    def __init__(self, r: int, q: int):
        """
        Creates a new rational number, r is the numerator, q is the denominator.
        Uses Euclid's algorithm to find the greatest common divisor (GCD),
        after it finds the GCD, reduces the fractions to its minimal form.
        """
        if q == 0:
            raise ArithmeticError("Division by zero")
        gcd = self.euclids(r, q)
        self.r = r // gcd
        self.q = q // gcd

    def __add__(self, other: "Rational") -> "Rational":
        if isinstance(other, Rational):
            new_r = self.r * other.q + other.r * self.q
            new_q = self.q * other.q
            return Rational(new_r, new_q)
        else:
            raise TypeError(
                "Unsupported operand type for +: 'Rational' and '{}'".format(
                    type(other)
                )
            )

    def __sub__(self, other: "Rational") -> "Rational":
        if isinstance(other, Rational):
            new_r = self.r * other.q - other.r * self.q
            new_q = self.q * other.q
            return Rational(new_r, new_q)
        else:
            raise TypeError(
                "Unsupported operand type for -: 'Rational' and '{}'".format(
                    type(other)
                )
            )

    def __mul__(self, other: "Rational") -> "Rational":
        if isinstance(other, Rational):
            new_r = self.r * other.r
            new_q = self.q * other.q
            return Rational(new_r, new_q)
        else:
            raise TypeError(
                "Unsupported operand type for *: 'Rational' and '{}'".format(
                    type(other)
                )
            )

    def __truediv__(self, other: "Rational") -> "Rational":
        if isinstance(other, Rational):
            new_r = self.r * other.q
            new_q = self.q * other.r
            return Rational(new_r, new_q)
        else:
            raise TypeError(
                "Unsupported operand type for /: 'Rational' and '{}'".format(
                    type(other)
                )
            )

    def __str__(self) -> str:
        return f"{self.r}/{self.q}"

    def euclids(self, a: int, b: int) -> int:
        while b != 0:
            a, b = b, a % b
        return a


def run():
    test_cases = [
        ((1, 1), (1, 1), "+", (2, 1)),
        ((1, 4), (2, 4), "+", (3, 4)),
        ((5, 7), (4, 9), "+", (73, 63)),
        ((2, 4), (2, 4), "+", (1, 1)),
        ((1, 1), (1, 1), "-", (0, 1)),
        ((1, 4), (2, 4), "-", (-1, 4)),
        ((2, 4), (2, 4), "*", (1, 4)),
        ((0, 1), (2, 4), "*", (0, 1)),
        ((3, 9), (3, 9), "/", (1, 1)),
    ]
    for test_case in test_cases:
        op = test_case[2]
        result = None
        rational1 = Rational(test_case[0][0], test_case[0][1])
        rational2 = Rational(test_case[1][0], test_case[1][1])
        expected = Rational(test_case[3][0], test_case[3][1])
        if op == "+":
            result = rational1 + rational2
        elif op == "-":
            result = rational1 - rational2
        elif op == "*":
            result = rational1 * rational2
        elif op == "/":
            result = rational1 / rational1
        print(f"{rational1} {op} {rational2} = {result} Expected: {expected}")


if __name__ == "__main__":
    run()
