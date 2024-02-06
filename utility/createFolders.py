import os, sys

if len(sys.argv) > 1:
    last = int(sys.argv[1])
else:
    last = 30


for i in range(1, last+1):
        path = f'..\\day{i}'
        if not os.path.exists(path):
            os.mkdir(path)
        with open(f'{path}/main.cpp', 'w', encoding = 'utf-8') as f:
            f.write("// failed compiles: \n")
            f.write("// failed runs: \n")	
            f.write("// time taken: \n")
