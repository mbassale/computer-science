; Exercise 1.11

(define (f n) 
  (cond ((< n 3) n)
        ((>= n 3) (+ 
          (f (- n 1))
          (* 2 (f (- n 2)))
          (* 3 (f (- n 3)))))))

(f 0)
(f 1)
(f 2)
(f 3)
(f 4)
(f 5)
(f 6)
(f 7)
(f 8)

; TODO: Understand this...
(define (f_i n)
  ;iterative
  ;initial values of accumulators are f(2) = 2, f(1) = 1 and f(0) = 0; loop variable is n.
  (f_i-prime 2 1 0 n))

(define (f_i-prime f-x+2 f-x+1 f-x n-x)
  (cond ((= n-x 0) f-x)   ; if n-x = 0, then n = x, so return f(x) = f(n).
        ((f_i-prime (+ f-x+2 (* 2 f-x+1) (* 3 f-x))   ; iterative step -- compute next value of f(x + 2);
                    f-x+2                             ; ... rotate all other accumulators;
                    f-x+1
                    (- n-x 1)))))                     ; ... and decrement loop variable.

(f_i 8)