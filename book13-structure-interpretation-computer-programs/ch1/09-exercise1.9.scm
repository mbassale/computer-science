; Exercise 1.0 Recursion or iteration?

(define (inc x) (+ x 1))
(define (dec x) (- x 1))

; Recursive implementation
(define (addition1 a b)
  (if (= a 0)
      b
      (inc (addition1 (dec a) b))))
(addition1 1 1)

; Tail recursive implementation
(define (addition2 a b)
  (if (= a 0)
      b
      (addition2 (dec a) (inc b))))
(addition2 1 1)