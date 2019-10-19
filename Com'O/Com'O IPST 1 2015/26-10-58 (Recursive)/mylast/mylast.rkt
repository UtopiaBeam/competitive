#lang racket
(define (mylast lst)
  (if (null? (rest lst))
      (first lst)
      (mylast (rest lst))))
        