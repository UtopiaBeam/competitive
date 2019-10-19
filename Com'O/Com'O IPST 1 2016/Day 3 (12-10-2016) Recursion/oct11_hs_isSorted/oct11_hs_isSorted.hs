main :: IO ()
main = do
 x1 <- readLn -- this is a
 putStrLn (show (isSorted x1))
isSorted :: [Int] -> Bool

isSorted [] = True
isSorted [x] = True
isSorted (x:y:ys) =
 if x > y then False
 else isSorted (y:ys)
