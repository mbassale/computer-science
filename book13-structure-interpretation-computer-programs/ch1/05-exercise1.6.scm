; Exercise 1.6
(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
        (else else-clause)))

(new-if (= 2 3) 0 5)
(new-if (= 1 1) 0 5)

(define (square x) (* x x))

(define (average x y)
  (/ (+ x y) 2))

(define (improve guess x)
  (average guess (/ x guess)))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.0001))

(define (sqrt-iter guess x)
  (new-if (good-enough? guess x)
      guess
      (sqrt-iter (improve guess x) x)))

(sqrt-iter 1.0 2.0)

; If we run this, we will get the error "Maximum recursion depth exceeded" 
; this is because (new-if) function is not a special form and it doesn't
; short-circuit or evaluates from left to right. So when we call (new-if)
; the interpreter will try to evaluate both arguments, creating an 
; infinite call stack recursion for the second argument:
; ..
;    (sqrt-iter (improve guess x) x)
; ..
; This second arg, will be re-evaluated multiple times until the callstack
; overflows.