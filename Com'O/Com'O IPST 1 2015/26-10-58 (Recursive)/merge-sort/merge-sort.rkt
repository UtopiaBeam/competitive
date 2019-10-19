#lang racket
(define (mypushback lst x)
  (if (null? lst)
      (list x)
      (cons (first lst) (mypushback (rest lst) x))))

(define (merge-list1 l1 l2 l3)
  (if (null? l1)
      (if (null? l2)
          l3
          (merge-list1 l1 (rest l2) (mypushback l3 (first l2))))
      (if (null? l2)
          (merge-list1 (rest l1) l2 (mypushback l3 (first l1)))
          (let ((x (first l1)) (y (first l2)))
            (if (< x y)
                (merge-list1 (rest l1) l2 (mypushback l3 (first l1)))
                (merge-list1 l1 (rest l2) (mypushback l3 (first l2))))))))

(define (merge-list l1 l2) (merge-list1 l1 l2 '()))

(define (split-list1 lst l1 l2)
  (if (null? lst)
      (list l1 l2)
      (if (null? (rest lst))
          (split-list1 (rest lst) (mypushback l1 (first lst)) l2)
          (split-list1 (rest (rest lst)) (mypushback l1 (first lst)) (mypushback l2 (second lst))))))

(define (split-list lst) (split-list1 lst '() '()))

(define (merge-sort lst)
  (if(null? lst) '()
   (let ((l (split-list lst)))
    ((merge-sort (first l)) (merge-sort (second l))))))
  