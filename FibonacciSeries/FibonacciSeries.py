"""
The Fibonacci series is defined as: F(0) = 0; F(1) = 1; F(n) = F(n–1) + F(n–2) when n>1. Given an integer n≥0, print out the F(n).
The first argument will be a path to a filename containing integer numbers, one per line.
Print to stdout, the fibonacci number, F(n).
https://www.codeeval.com/open_challenges/22/
"""

import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    a = 0
    b = 1
    total = 1
    n = int(test)
    while n > 0:
        a = b
        b = total
        total = a + b
        n -= 1
    print a

test_cases.close()

