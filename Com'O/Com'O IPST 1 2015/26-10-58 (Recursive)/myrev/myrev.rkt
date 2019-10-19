#lang racket
(define (mypushback lst x)
  (if (null? lst)
      (list x)
      (cons (first lst) (mypushback (rest lst) x))))

(define (myrev lst)
  (if (null? lst)
      '()
      (mypushback (myrev (rest lst)) (first lst))))