main :: IO ()
main = (readLn >>= (\n -> putStrLn (show (fibo n))))
fibo :: Integer -> Integer
fibo 0 = 0
fibo 1 = 1
fibo 2 = 1
fibo n = 2*fibo (n-2) + fibo (n-3)
