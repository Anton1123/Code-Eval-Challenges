-- Print 0 if numbers is odd, 1 if even
-- https://www.codeeval.com/open_challenges/100/submit/

import System.Environment (getArgs)

main = do
	[inpFile] <- getArgs
	input <- readFile inpFile
	mapM_ putStrLn $ [if (mod x 2 == 0) then "1" else "0"| x <- map (read :: String -> Integer) $ lines input]
