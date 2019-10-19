main :: IO ()
main = do
 x1 <- readLn -- this is the list
 x2 <- readLn -- this is the value
 putStrLn (show (myinsert x1 x2))
myinsert :: [Int] -> Int -> [Int]

myinsert [] y = [y]
myinsert (x:xs) y = if x >= y
 then y:(x:xs)
 else x:myinsert xs y
