t = int(raw_input())
for iii in range(t):
    a,b=raw_input().split(" ")
    a=int(a)
    b=int(b)
    # b=int(raw_input())
    if(a%b==0):
        print(a)
        continue
    z=a
    i=1
    while(z%b!=0):
        z%=b
        if z==0:
            z=b
        # print(z)
        z=a+b-z
        # print(z)
        xx=int(z/i)
        yy=int(a/i)
        if xx==yy:
            break
        a*=10
        i*=10
        z=a
    if z<=1000000000000000000:
        print(z)
    else:
        print(-1)
