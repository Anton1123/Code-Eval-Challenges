import System.Environment (getArgs)
import System.Posix (getFileStatus, fileSize)

main = do
	[inpFile] <- getArgs
	input <- getFileStatus inpFile
	putStrLn $ show $ fileSize input
