{-
Write a program which swaps letters' case in a sentence. All non-letter characters should remain the same.
Your program should accept as its first argument a path to a filename. 
https://www.codeeval.com/open_challenges/96/
-}

import System.Environment (getArgs)
import Data.Char (isUpper, isLower, toUpper, toLower)

main = do
  [inpFile] <- getArgs
  input <- readFile inpFile
  mapM_ putStrLn $ map unwords $ (map . map . map) swapCase $ map words $ lines input

swapCase :: Char -> Char
swapCase x | isUpper x = toLower x
           | isLower x = toUpper x
           | otherwise = x
