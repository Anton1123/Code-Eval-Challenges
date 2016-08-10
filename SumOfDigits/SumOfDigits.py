import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    number = int(test)
    total = 0
    while number > 0:
        total += number % 10
        number /= 10

    print total
test_cases.close()
