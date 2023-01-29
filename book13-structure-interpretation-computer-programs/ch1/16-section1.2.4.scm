; 1.2.4 Exponentiation

; Recursive Algorithm for Exponentiation
; Time O(n) Space O(n)

(define (expt b n)
  (if (= n 0)
    1
    (* b (expt b (- n 1)))))

(expt 10 0)
(expt 10 1)
(expt 10 2)
(expt 10 3)
(expt 10 4)
(expt 10 5)
(expt 10 6)

; Exponentiation, iterative solution
; Time O(n) Space O(1)

(define (expt-iter b counter product)
  (if (= counter 0)
    product
    (expt-iter b (- counter 1) (* b product))))

(define (expt b n)
  (expt-iter b n 1))

(expt 10 0)
(expt 10 1)
(expt 10 2)
(expt 10 3)
(expt 10 4)
(expt 10 5)
(expt 10 6)

; Exponentiation, successive squaring method
; Time O(log(n)) Space O(log(n))

(define (even? n)
  (= (remainder n 2) 0))

(define (fast-expt b n)
  (cond ((= n 0) 1)
        ((even? n) (square (fast-expt b (/ n 2))))
        (else (* b (fast-expt b (- n 1))))))

(fast-expt 10 0)
(fast-expt 10 1)
(fast-expt 10 2)
(fast-expt 10 3)
(fast-expt 10 4)
(fast-expt 10 5)
(fast-expt 10 6)