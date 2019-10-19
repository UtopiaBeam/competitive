#lang racket
(define (myappend l1 l2)
  (if (null? l1)
      l2
      (cons (first l1) (myappend (rest l1) l2))))
(define (mypushback lst x)
  (if (null? lst)
      (list x)
      (cons (first lst) (mypushback (rest lst) x))))
(define (myflat2 l1 l2)
  (if (null? l1) l2
      (if (list? (first l1))
          (myflat2 (rest l1) (myappend l2 (myflat2 (first l1) '())))
          (myflat2 (rest l1) (mypushback l2 (first l1))))))
(define (myflat lst) (myflat2 lst '()))