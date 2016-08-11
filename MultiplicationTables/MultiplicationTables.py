"""
Print out the grade school multiplication table upto 12*12.
Print out the table in a matrix like fashion, each number formatted to a width of 4 (The numbers are right-aligned and strip out leading/trailing spaces on each line). The first 3 line will look like:
https://www.codeeval.com/open_challenges/23/
"""
import sys

for i in range(1,13):
    for j in range(1,13):
        num = i * j
        if j == 1:
            if i < 10:
                sys.stdout.write("   " + str(num))
            else:
                sys.stdout.write("  " + str(num))
        elif num / 10 == 0:
            sys.stdout.write("   " + str(num))
        elif num / 100 == 0:
            sys.stdout.write("  " + str(num))
        else:
            sys.stdout.write(" " + str(num))
    print


