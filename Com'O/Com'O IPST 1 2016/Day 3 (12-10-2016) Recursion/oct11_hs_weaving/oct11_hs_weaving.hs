main :: IO ()
main = do
 x1 <- readLn
 x2 <- readLn
 putStrLn (show (weaving x1 x2))
weaving :: [Int] -> [Int] -> [Int]

weaving xs [] = xs
weaving [] ys = ys
weaving (x:xs) (y:ys) = x:y:weaving xs ys
