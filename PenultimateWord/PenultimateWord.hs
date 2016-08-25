{-
Write a program which finds the next-to-last word in a string.
Your program should accept as its first argument a path to a filename.
Print the next-to-last word.
https://www.codeeval.com/open_challenges/92/
-}

import System.Environment (getArgs)

main = do
  [inpFile] <- getArgs
  input <- readFile inpFile
  mapM_ putStrLn $ map last $ map init $ map words $ lines input
