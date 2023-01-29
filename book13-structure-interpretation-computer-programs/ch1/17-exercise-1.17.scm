; Exercise 1.17

; Time: O(n) Space: O(n)
(define (mul a b)
  (if (= b 0)
    0
    (+ a (mul a (- b 1)))))

(mul 10 0)
(mul 10 1)
(mul 10 2)
(mul 10 3)
(mul 10 4)
(mul 10 5)

; Logarithmic Approach
; Time: O(log(n)) Space: O(log(n))

(define (even? n)
  (= (remainder n 2) 0))
(define (double a) (+ a a))
(define (halve a) (/ a 2))

; 4 * 5 = 20 => 4 + (4 * 4) => 4 + 2 * (4 + 4) => 4 + 2 * 8 = 4 + 16 = 20
; 4 * 4 = 16 => 2 * (4 * 2) => 2 * 8 => 16
(define (mul-iter a b)
  (cond ((= b 0) 0)
        ((even? b) (double (mul-iter a (halve b))))
        (else (+ a (mul-iter a (- b 1))))))

(mul-iter 10 4)