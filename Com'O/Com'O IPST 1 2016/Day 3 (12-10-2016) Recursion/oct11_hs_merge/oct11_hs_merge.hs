main :: IO ()
main = do
 x1 <- readLn
 x2 <- readLn
 putStrLn (show (merge x1 x2))
merge :: [Int] -> [Int] -> [Int]

merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) =
 if(x <= y) then x:merge xs (y:ys)
 else y:merge (x:xs) ys
