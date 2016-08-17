{-
Given two integers N and M, calculate N Mod M (without using any inbuilt modulus operator).
Your program should accept as its first argument a path to a filename. Each line in this file contains two comma separated positive integers. 
You may assume M will never be zero.
Print out the value of N Mod M
https://www.codeeval.com/open_challenges/62/
-}
import System.Environment (getArgs)

main = do
    [inpFile] <- getArgs
    input <- readFile inpFile
    -- print your output to stdout
    mapM_ putStrLn (map mymod (map (wordsWhen (==',')) (lines input)))

wordsWhen     :: (Char -> Bool) -> String -> [String]
wordsWhen p s =  case dropWhile p s of
                      "" -> []
                      s' -> w : wordsWhen p s''
                            where (w, s'') = break p s'

mymod :: [String] -> String
mymod a | (read (head a) :: Int) < (read (last a) :: Int) = (head a)
        | otherwise = mymod ((show ((read (head a) :: Int) - (read (last a) :: Int))) : (tail a))
