main :: IO ()
main = do
 x1 <- readLn -- this is a
 x2 <- readLn -- this is b
 putStrLn (show (find x1 x2))
find :: String -> String -> Int

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
