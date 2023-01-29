; Exercise 1.12: Pascal Triangle

(define (pascal x y) 
  (cond ((or (<= x 0) (<= y 0) (< x y)) 0)
        ((or (= y 1) (= x y)) 1)
        (else (+ (pascal (- x 1) y) (pascal (- x 1) (- y 1))))))


(pascal 0 0)
(pascal 0 1)
(pascal 1 1)
(pascal 6 4)
(pascal 10 10)