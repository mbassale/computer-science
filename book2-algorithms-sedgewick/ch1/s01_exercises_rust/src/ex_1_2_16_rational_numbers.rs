#[allow(dead_code)]
use std::ops::{Add, Div, Mul, Sub};

#[derive(Debug, Clone, PartialEq)]
pub struct DivisionByZeroError;

#[derive(Debug)]
pub struct Rational {
    pub r: i32,
    pub q: i32,
}

impl Rational {
    pub fn new(r: i32, q: i32) -> Result<Rational, DivisionByZeroError> {
        if q == 0 {
            return Err(DivisionByZeroError {});
        }
        let gcd = euclids(r, q);
        let r = r / gcd;
        let q = q / gcd;
        Ok(Rational { r, q })
    }
}

impl PartialEq for Rational {
    fn eq(&self, other: &Self) -> bool {
        self.r == other.r && self.q == other.q
    }
}

impl Add for Rational {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        let r = self.r * rhs.q + rhs.r * self.q;
        let q = self.q * rhs.q;
        let gcd = euclids(r, q);
        Rational {
            r: r / gcd,
            q: q / gcd,
        }
    }
}

impl Sub for Rational {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        let r = self.r * rhs.q - rhs.r * self.q;
        let q = self.q * rhs.q;
        let gcd = euclids(r, q);
        Rational {
            r: r / gcd,
            q: q / gcd,
        }
    }
}

impl Mul for Rational {
    type Output = Self;

    fn mul(self, rhs: Self) -> Self::Output {
        let r = self.r * rhs.r;
        let q = self.q * rhs.q;
        let gcd = euclids(r, q);
        Rational {
            r: r / gcd,
            q: q / gcd,
        }
    }
}

impl Div for Rational {
    type Output = Self;

    fn div(self, rhs: Self) -> Self::Output {
        let r = self.r * rhs.q;
        let q = self.q * rhs.r;
        let gcd = euclids(r, q);
        Rational {
            r: r / gcd,
            q: q / gcd,
        }
    }
}

fn euclids(mut r: i32, mut q: i32) -> i32 {
    while q > 0 {
        let m = r % q;
        if m == 0 {
            return q;
        }
        r = q;
        q = m;
    }
    return q;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_new() {
        let test_cases: [(i32, i32, Result<Rational, DivisionByZeroError>); 4] = [
            (0, 0, Err(DivisionByZeroError)),
            (1, 1, Ok(Rational { r: 1, q: 1 })),
            (2, 4, Ok(Rational { r: 1, q: 2 })),
            (27, 81, Ok(Rational { r: 1, q: 3 })),
        ];
        for (r, q, expected) in test_cases {
            assert_eq!(Rational::new(r, q), expected);
        }
    }

    #[test]
    fn test_ops() {
        let test_cases = [
            ((1, 1), (1, 1), "+", (2, 1)),
            ((1, 4), (2, 4), "+", (3, 4)),
            ((5, 7), (4, 9), "+", (73, 63)),
            ((2, 4), (2, 4), "+", (1, 1)),
            ((1, 1), (1, 1), "-", (0, 1)),
            ((1, 4), (2, 4), "-", (-1, 4)),
            ((2, 4), (2, 4), "*", (1, 4)),
            ((0, 1), (2, 4), "*", (0, 1)),
            ((3, 9), (3, 9), "/", (1, 1)),
        ];
        for (r1, r2, op, expected) in test_cases {
            let lhs = Rational::new(r1.0, r1.1).unwrap();
            let rhs = Rational::new(r2.0, r2.1).unwrap();
            let result = match op {
                "+" => lhs + rhs,
                "-" => lhs - rhs,
                "*" => lhs * rhs,
                "/" => lhs / rhs,
                _ => panic!("Unsupported operator"),
            };
            let expected_rational = Rational::new(expected.0, expected.1).unwrap();
            assert_eq!(
                result, expected_rational,
                "TestCase: {:?} {op} {:?} = {:?}",
                r1, r2, expected
            );
        }
    }
}
