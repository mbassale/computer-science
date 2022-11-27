; Procedure Equivalence by Return Values, Black Box Procedure Model

(define (square1 x) (* x x))

(define (double x) (+ x x))
(define (square2 x) (exp (double (log x))))

(square1 9)
(square2 9)

(abs (- (square1 9) (square2 9)))

; Lexical Scoping in Procedure Definitions

(define (sqrt-newton x)
  (define (square x) (* x x))

  (define (average x y) (/ (+ x y) 2))

  (define (good-enough? guess)
    (< (abs (- (square guess) x)) 0.0001))
  
  (define (improve guess)
    (average guess (/ x guess)))

  (define (sqrt-iter guess)
    (if (good-enough? guess)
        guess
        (sqrt-iter (improve guess))))

  (sqrt-iter 1.0))

(sqrt-newton 81)