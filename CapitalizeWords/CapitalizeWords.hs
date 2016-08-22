{-
Write a program which capitalizes the first letter of each word in a sentence.
Your program should accept as its first argument a path to a filename. 
Print capitalized words.
https://www.codeeval.com/open_challenges/93/
-}

import System.Environment (getArgs)
import Data.Char (toUpper)

main = do
  [inpFile] <- getArgs
  input <- readFile inpFile
  mapM_ putStrLn $ map unwords $ (map . map) capitalize $ map words $ lines input

capitalize :: String -> String
capitalize (x:xs) = toUpper x : xs
