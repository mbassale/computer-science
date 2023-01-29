; Exercise 1.8 Cube Root using Newton's approximation method.

(define (cube x) (* x x x))

(define (cube-approx x y)
  (/ (+ (/ x (* y y)) (* 2 y)) 3))

(define (improve guess x)
  (begin (display guess) 
        (display " ") 
        (display x) 
        (newline) 
        (cube-approx x guess)))

(define (good-enough? guess x)
  (< (abs (- (cube guess) x)) 0.0001))

(define (cube-iter guess x)
  (if (good-enough? guess x)
      guess
      (cube-iter (improve guess x) x)))

(define (cube-newton x)
  (cube-iter 1.0 x))

(cube-newton 1000)