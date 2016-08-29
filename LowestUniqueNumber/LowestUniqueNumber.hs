{-
There is a game where each player picks a number from 1 to 9, writes it on a paper and gives to a guide. A player wins if his number is the lowest unique. We may have 10-20 players in our game.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename.

You're a guide and you're given a set of numbers from players for the round of game. E.g. 2 rounds of the game look this way:

3 3 9 1 6 5 8 1 5 3
9 2 9 9 1 8 8 8 2 1 1
OUTPUT SAMPLE:

Print a winner's position or 0 in case there is no winner. In the first line of input sample the lowest unique number is 6. So player 5 wins.

5
0
https://www.codeeval.com/open_challenges/103/
-}

import System.Environment (getArgs)
import Data.Maybe (fromJust)
import Data.List (elemIndex)

main = do
  [inpFile] <- getArgs
  input <- readFile inpFile
  let lines_ = map (map (read :: String -> Integer) . words) (lines input)
  mapM_ (print . fromJust_) $ zipWith elemIndex (map (mymin . uniqify) lines_) lines_

uniqify :: [Integer] -> [Integer]
uniqify [] = []
uniqify (x:xs) | x `elem` xs = uniqify $ filter (/=x) xs
               | otherwise = x : uniqify xs

mymin :: [Integer] -> Integer
mymin [] = 0
mymin xs = minimum xs

fromJust_ :: Num a => Maybe a -> a
fromJust_ Nothing = 0
fromJust_ (Just x) = x + 1 -- convert to "1-index"

-- lpaste with suggestions saved for later (http://lpaste.net/181404)
