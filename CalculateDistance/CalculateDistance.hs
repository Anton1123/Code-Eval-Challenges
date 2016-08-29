{-
You have coordinates of 2 points and need to find the distance between them.

INPUT SAMPLE:

Your program should accept as its first argument a path to a filename. Input example is the following

(25, 4) (1, -6)
(47, 43) (-25, -11)
All numbers in input are integers between -100 and 100.

OUTPUT SAMPLE:

Print results in the following way.

26
90

You don't need to round the results you receive. They must be integer numbers.\
https://www.codeeval.com/open_challenges/99/
-}

import System.Environment (getArgs)

main = do
  [inpFile] <- getArgs
  input <- readFile inpFile
  mapM_ print $ map (getDistance . convert_ . words) $ lines input

-- Converts the input into lists of integers
convert_ :: [String] -> [Integer]
convert_ currlist = map (read :: String -> Integer) $ (tail $ init $ head currlist) : ((init $ currlist!!1) : ((tail $ init $ currlist!!2):[init $ currlist!!3]))

getDistance :: [Integer] -> Integer
getDistance coords = isqrt((coords!!0 - coords!!2)^2 + (coords!!1 - coords!!3)^2)

isqrt :: Integer -> Integer
isqrt = floor . sqrt . fromIntegral
