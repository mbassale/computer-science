; Exercise 1.1

10

(+ 5 3 4)

(- 9 1)

(/ 6 2)

(+ (* 2 4) (- 4 6))

(define a 3)

(define b (+ a 1))

(+ a b (* a b))

(= a b)

(if (and (> b a) (< b (* a b))) b a)

(+ 2 (if (> b a) b a))

(* (cond  ((> a b) a)
          ((< a b) b)
          (else -1))
    (+ a 1))

; Exercise 1.3

(define (exercise1 x y z) 
        (- (+ (* x x) (* y y) (* z z)) (* (min x y z) (min x y z))))
(exercise1 1 2 3)

; Exercise 1.4
(define (a-plus-abs-b a b)
        ((if (> b 0) + -) a b))
(a-plus-abs-b 2 (- 2))

; Exercise 1.5
(define (p) (p))

(define (test x y)
  (if (= x 0) 0 y))

(test 0 (p))