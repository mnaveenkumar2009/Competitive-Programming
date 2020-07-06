import os,time

if(os.path.isfile('test.zip')):
    os.system("rm test.zip")

os.system("g++ test_case.cpp")

number_of_cases=1
x=1
for i in range(number_of_cases):
    if i+x<10:
        os.system("./a.out > TC/in0"+str(i+x)+".txt")
    else:
        os.system("./a.out > TC/in"+str(i+x)+".txt")
    time.sleep(1)

os.system("g++ answer.cpp")

for i in range(number_of_cases):
    if i+x<10:
        os.system("./a.out < TC/in0"+str(i+x)+".txt > TC/out0"+str(i+x)+".txt")
    else:
        os.system("./a.out < TC/in"+str(i+x)+".txt > TC/out"+str(i+x)+".txt")

s="zip -r test TC/*"
os.system(s)