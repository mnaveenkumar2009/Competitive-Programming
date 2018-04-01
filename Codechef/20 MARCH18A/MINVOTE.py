j=input
t=int(j())
while(t>0):
    n=int(j())
    a=list(map(int,input().split()))
    v=[0]*n
    for i in range (n):
        s1=0
        s2=0
        if(i+1<n):
            v[i+1]+=1
        if(i-1>=0):
            v[i-1]+=1
            
        for j in range (i+1,n):
            s1=s1+a[j]
            if(s1<=a[i]) and (j+1<n):
                v[j+1]+=1
            else:
                break
        for j in range (i-1,-1,-1):
            s2=s2+a[j]
            if (s2<=a[i]) and (j-1>=0):
                v[j-1]+=1
            else:
                break
         
    for i in range (n):
        print(v[i],end=" ")         
    print()
    t=t-1