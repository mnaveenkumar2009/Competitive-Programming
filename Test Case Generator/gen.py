import os,time

if(os.path.isfile('test.zip')):
    os.system("rm test.zip")

os.system("g++ test_case.cpp")

number_of_cases=2
x=0
for i in range(number_of_cases):
    if i+x<10:
        os.system("./a.out > input/input0"+str(i+x)+".txt")
    else:
        os.system("./a.out > input/input"+str(i+x)+".txt")
    time.sleep(1)

os.system("g++ answer.cpp")

for i in range(number_of_cases):
    if i+x<10:
        os.system("./a.out < input/input0"+str(i+x)+".txt > output/output0"+str(i+x)+".txt")
    else:
        os.system("./a.out < input/input"+str(i+x)+".txt > output/output"+str(i+x)+".txt")

s="zip -r test input output"
os.system(s)