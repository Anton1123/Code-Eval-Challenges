{-
Write a program which sorts numbers.
Your program should accept as its first argument a path to a filename.
Print sorted numbers in the following way. Please note, that you need to print the numbers till the 3rd digit after the dot including trailing zeros.
https://www.codeeval.com/open_challenges/91/
-}

import System.Environment (getArgs)
import Numeric (showFFloat)

main = do
    [inpFile] <- getArgs
    input <- readFile inpFile
    -- print your output to stdout
    mapM_ putStrLn $ map unwords $ (map . map) (\x ->  showFFloat (Just 3) x "") $ map quicksort $ (map . map) (\x -> read x :: Double) $ map words $ lines input

quicksort :: Ord a => [a] -> [a]
quicksort []     = []
quicksort (p:xs) = (quicksort lesser) ++ [p] ++ (quicksort greater)
    where
        lesser  = filter (< p) xs
        greater = filter (>= p) xs
