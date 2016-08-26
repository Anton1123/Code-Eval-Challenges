{-
Having a string representation of a set of numbers you need to print these numbers.
All numbers are separated by semicolon. There are up to 20 numbers in one line. The numbers are "zero" to "nine"
Your program should accept as its first argument a path to a filename. Each line in this file is one test case. 

https://www.codeeval.com/open_challenges/104/
-}

import System.Environment (getArgs)

main = do
	[inpFile] <- getArgs
	input <- readFile inpFile
	mapM_ putStrLn $ map (foldl1 (++)) $ (map . map) wordToDigit $ map (wordsWhen (==';')) $ lines input


wordToDigit      :: String -> String
wordToDigit word | word == "zero"   = "0"
                 | word == "one"    = "1"
                 | word == "two"    = "2"
                 | word == "three"  = "3"
                 | word == "four"   = "4"
                 | word == "five"   = "5"
                 | word == "six"    = "6"
                 | word == "seven"  = "7"
                 | word == "eight"  = "8"
                 | word == "nine"   = "9"
                 | otherwise        = "-"

wordsWhen     :: (Char -> Bool) -> String -> [String]
wordsWhen p s =  case dropWhile p s of
                      "" -> []
                      s' -> w : wordsWhen p s''
                            where (w, s'') = break p s'
