"""
Given a string write a program to convert it into lowercase.
The first argument will be a path to a filename containing sentences, one per line. You can assume all characters are from the english language.
Print to stdout, the lowercase version of the sentence, each on a new line.
https://www.codeeval.com/open_challenges/20/
"""
import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    print test.lower()

test_cases.close()
