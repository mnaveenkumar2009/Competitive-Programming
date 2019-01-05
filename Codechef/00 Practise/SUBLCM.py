MAX=1000006

divisors=[[]] * MAX
for i in range (MAX):
    divisors[i]=[]
    
for i in range(2,MAX):
    if len(divisors[i])==0:
        divisors[i].append(i)
        j=2
        while (j*i)<MAX:
            divisors[j*i].append(i)
            j+=1
t=int(raw_input())
while t>0:
    n=int(raw_input())
    dp = [0]*n
    p = [-1]*1000005
    a= list(raw_input().split(" "))
    for i in range(n):
        a[i]=int(a[i])
    dp[0]=1
    for i in range(n):
        pos=-1
        for pf in divisors[a[i]]:
            pos=max(p[pf],pos)
            p[pf]=i
        if i!=0:
            dp[i]=min(dp[i-1]+1,i-pos)
    ans=max(dp)
    if ans<=1:
        ans=-1
    print(ans)
    t-=1