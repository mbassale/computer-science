/*
[Sedgewick][Ch1][Rust] Exercise 1.3.10 Infix to Postfix conversion

Example Trace:
INPUT: ((A+B)*C)+(A+B)            EXPECTED: AB+C*AB++
IN              STACK             POSTFIX_EXPR
(               (
(               (,(
A                                 A
+               (,(,+
B                                 A,B
)               (,                A,B,+
*               (,*
C                                 A,B,+,C
)                                 A,B,+,C,*
+               +
(               +,(
A                                 A,B,+,C,*,A
+               +,(,+
B                                 A,B,+,C,*,A,B
)                                 A,B,+,C,*,A,B,+,+
*/

#[allow(dead_code)]
use std::collections::HashMap;

fn is_operator(ch: char) -> bool {
    ch == '+' || ch == '-' || ch == '*' || ch == '/'
}

fn infix_to_postfix(infix_expr: &str) -> String {
    let mut postfix_expr: Vec<char> = Vec::new();
    let mut stack: Vec<char> = Vec::new();

    let mut precedences = HashMap::new();
    precedences.insert('+', 1);
    precedences.insert('-', 1);
    precedences.insert('*', 2);
    precedences.insert('/', 2);

    for ch in infix_expr.chars() {
        if ch.is_whitespace() {
            continue;
        }
        if ch.is_alphanumeric() {
            postfix_expr.push(ch);
        } else if ch == '(' {
            stack.push(ch)
        } else if ch == ')' {
            while stack.len() > 0 && stack.last() != Some(&'(') {
                postfix_expr.push(stack.pop().unwrap());
            }
            stack.pop();
        } else if is_operator(ch) {
            while stack.len() > 0
                && stack.last() != Some(&'(')
                && precedences[stack.last().unwrap()] >= precedences[&ch]
            {
                postfix_expr.push(stack.pop().unwrap());
            }
            stack.push(ch);
        }
    }

    while stack.len() > 0 {
        postfix_expr.push(stack.pop().unwrap());
    }

    String::from_iter(postfix_expr.iter())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_infix_to_postfix() {
        let test_cases = [
            ("((A+B)*C)", "AB+C*"),
            ("((A+B)*C)+(A+B)", "AB+C*AB++"),
            ("(A+(B*C))", "ABC*+"),
            ("A+B*C", "ABC*+"),
            ("A*B+C", "AB*C+"),
        ];
        for (infix_expr, expected) in test_cases {
            let actual = infix_to_postfix(infix_expr);
            assert_eq!(actual, expected);
        }
    }
}
