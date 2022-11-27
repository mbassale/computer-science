; 1.2.1 Linear Recursion and Iteration

(define (factorial n)
  (if (= n 1)
      1
      (* n (factorial (- n 1)))))

(factorial 1)
(factorial 10)
(factorial 100)

(define (factorial-iter n)
  (define (iter product counter)
    (if (> counter n)
        product
        (iter (* counter product)
              (+ counter 1))))
    (iter 1 1))

(factorial-iter 1)
(factorial-iter 10)
(factorial-iter 100)