gen 0 = []
gen n = n:gen(n-1)

myappend x [] = [x]
myappend x (y:ys) = y:myappend x ys


myrev xs = rev0 xs []
 where
  rev0 [] ys = ys
  rev0 (x:xs) ys = rev0 xs (x:ys)


myconcat [] y = y
myconcat (x:xs) y = x:myconcat xs y

myinsert [] y = [y]
myinsert (x:xs) y = if x >= y
 then y:(x:xs)
 else x:myinsert xs y

isort [] = []
isort (x:xs) = myinsert (isort xs) x

merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) =
 if(x <= y) then x:merge xs (y:ys)
 else y:merge (x:xs) ys

lsplit xs = (split xs,split (tail xs))
 where split [] = []
       split (x:xs) =
        if xs==[] then [x]
        else x:split (tail xs)

msort [] = []
msort [x] = [x]
msort xs = merge (msort a) (msort b)
 where (a,b) = lsplit xs

cmp xs [] = True
cmp [] ys = False
cmp (x:xs) (y:ys) =
 if (x==y) then cmp xs ys
 else False

fstr [] ys z = -1
fstr xs ys z =
 if (cmp xs ys) then z
 else fstr (tail xs) ys (z+1)

find xs ys = fstr xs ys 0
