#lang racket
(define (mylen lst)
  (if (null? lst)
      0
      (+ 1 (mylen (rest lst)))))

(define (unitlist lst)
   (if (= (mylen lst) 1) #t #f))