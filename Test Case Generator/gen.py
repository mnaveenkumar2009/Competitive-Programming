import os,time
os.system("g++ test_case.cpp")
number_of_cases=15
for i in range(number_of_cases):
    if i+0<10:
        os.system("./a.out <temp> input/input0"+str(i+0)+".txt")
    else:
        os.system("./a.out <temp> input/input"+str(i+0)+".txt")
    time.sleep(1)

os.system("g++ answer.cpp")

for i in range(number_of_cases):
    if i+0<10:
        os.system("./a.out <input/input0"+str(i+0)+".txt> output/output0"+str(i+0)+".txt")
    else:
        os.system("./a.out <input/input"+str(i+0)+".txt> output/output"+str(i+0)+".txt")

s="zip -r test input output"
os.system(s)