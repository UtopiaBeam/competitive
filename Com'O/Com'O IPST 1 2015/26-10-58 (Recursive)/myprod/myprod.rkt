#lang racket
(define (myprod lst)
  (if (null? lst)
      1
      (let ((x (first lst)) (y (rest lst)))
        (* x (myprod y)))))