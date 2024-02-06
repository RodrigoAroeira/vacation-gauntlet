import os, sys

if len(sys.argv) > 1:
    last = sys.argv[1]
else:
    last = 30


for i in range(1, last+1):
        os.mkdir(f'day{i}')
        with open(f'day{i}/main.cpp', 'w', encoding = 'utf-8'):
            pass
