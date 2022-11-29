; 1.2.2 Tree Recursion

(define (fib n)
  (cond ((= n 0) 0)
        ((= n 1) 1)
        (else (+ (fib (- n 1))
                 (fib (- n 2))))))

(fib 0)
(fib 1)
(fib 2)
(fib 4)
(fib 5)
(fib 6)
(fib 7)
(fib 8)
(fib 9)
(fib 10)

(define (fib-iter a b count)
  (if (= count 0)
      b
      (fib-iter (+ a b) a (- count 1))))
(define (fib2 n) (fib-iter 1 0 n))

(fib2 0)
(fib2 1)
(fib2 2)
(fib2 4)
(fib2 5)
(fib2 6)
(fib2 7)
(fib2 8)
(fib2 9)
(fib2 10)

