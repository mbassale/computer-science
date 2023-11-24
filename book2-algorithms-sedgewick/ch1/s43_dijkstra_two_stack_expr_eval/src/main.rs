/*
 [Sedgewick][Ch1][Rust] 1.3 Dijkstra Two-Stack Algorithm for Expression Evaluation

$ cargo run "((1+2)*(5+3))"
    Finished dev [unoptimized + debuginfo] target(s) in 0.00s
     Running `target/debug/s43_dijkstra_two_stack_expr_eval '((1+2)*(5+3))'`
Evaluating: 2 + 1 = 3
Evaluating: 3 + 5 = 8
Evaluating: 8 * 3 = 24
Result: 24
*/

fn is_operator(ch: char) -> bool {
    match ch {
        '+' => true,
        '-' => true,
        '*' => true,
        '/' => true,
        _ => false,
    }
}

fn eval_binary(op: &str, lhs_val: f32, rhs_val: f32) -> f32 {
    match op {
        "+" => lhs_val + rhs_val,
        "-" => lhs_val - rhs_val,
        "*" => lhs_val * rhs_val,
        "/" => {
            if rhs_val != 0.0 {
                lhs_val / rhs_val
            } else {
                panic!("Division by zero")
            }
        }
        _ => panic!("Unknown operator: {op}"),
    }
}

fn main() {
    let mut ops: Vec<String> = Vec::new();
    let mut vals: Vec<f32> = Vec::new();

    let args: Vec<String> = std::env::args().collect();
    if args.len() < 2 {
        println!("Missing argument.");
        return;
    }

    let mut is_parsing_float = false;
    let mut float_str = String::new();
    for ch in args[1].chars() {
        if is_parsing_float {
            if ch.is_digit(10) {
                float_str.push(ch);
                continue;
            } else if float_str.len() > 0 {
                let val: f32 = float_str.parse().expect("Invalid float");
                vals.push(val);
                float_str.clear();
            }
            is_parsing_float = false;
        }

        if ch.is_whitespace() || ch == '(' {
            continue;
        } else if is_operator(ch) {
            ops.push(ch.to_string());
        } else if ch == ')' {
            let op = ops.pop().expect("Missing operator");
            let lhs_val = vals.pop().expect("Missing left hand side value");
            let rhs_val = vals.pop().expect("Missing right hand side value");
            let res_val = eval_binary(&op, lhs_val, rhs_val);
            println!("Evaluating: {lhs_val} {op} {rhs_val} = {res_val}");
            vals.push(res_val);
        } else if ch.is_digit(10) {
            is_parsing_float = true;
            float_str.push(ch);
            continue;
        }
    }
    println!("Result: {}", vals.pop().expect("Invalid expression"));
}
