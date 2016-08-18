{-
An Armstrong number is an n-digit number that is equal to the sum of the n'th powers of its digits. Determine if the input numbers are Armstrong numbers.
Your program should accept as its first argument a path to a filename. Each line in this file has a positive integer.
Print out True/False if the number is an Armstrong number or not. 
https://www.codeeval.com/open_challenges/82/
-}
import System.Environment (getArgs)

main = do
    [inpFile] <- getArgs
    input <- readFile inpFile
    mapM_ putStrLn $ map checkifArmstrongNumber $ lines input

checkifArmstrongNumber :: String -> String
checkifArmstrongNumber num | (read num :: Int) == foldl1 (+) [(read [y] :: Int) ^ (length num) | y <- num] = "True"
                           | otherwise = "False"
