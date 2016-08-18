{-
You will be given a hexadecimal (base 16) number. Convert it into decimal (base 10).
Your program should accept as its first argument a path to a filename. Each line in this file contains a hex number. You may assume that the hex number does not have the leading 'Ox'. Also all alpha characters (a through f) in the input will be in lowercase.
Print out the equivalent decimal number.
https://www.codeeval.com/open_challenges/67/
-}

import System.Environment (getArgs)

main = do
    [inpFile] <- getArgs
    input <- readFile inpFile
    mapM_ print $ map hex2dec $ lines input

hexChar :: Char -> Integer
hexChar c
	  | c == '0' = 0
	  | c == '1' = 1
	  | c == '2' = 2
	  | c == '3' = 3
	  | c == '4' = 4
	  | c == '5' = 5
	  | c == '6' = 6
	  | c == '7' = 7
	  | c == '8' = 8
	  | c == '9' = 9
	  | c == 'a' = 10
	  | c == 'b' = 11
	  | c == 'c' = 12
	  | c == 'd' = 13
	  | c == 'e' = 14
	  | c == 'f' = 15
	  | otherwise     = 0

hex2dec :: String -> Integer
hex2dec str = go (reverse str)
	  where go []     = 0
	        go (x:xs) = hexChar x + 16 * go xs
