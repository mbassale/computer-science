; Exercise 1.15: Sin Approximation

(define (cube x) (* x x x))

(define (p x) (- (* 3 x) (* 4 (cube x))))

(define (sine angle)
  (if (not (> (abs angle) 0.1))
      angle
      (p (sine (/ angle 3.0)))))

(sine 12.15)

; How many times is the procedure p applied when (sine 12.15) is evaluated?
; 12.15 / 3 ^ n = 0.1, solve for n
; n = 3*log(5)/log(3) ~ 4.39
; The procedure will be called 4 times.

; What is the order of growth in space and number of steps depending on n?
; is O(log(n))