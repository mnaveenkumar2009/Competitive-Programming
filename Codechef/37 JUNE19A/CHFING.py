t=int(raw_input())
for i in range(t):
    x,l=(raw_input().split())
    x=int(x)-1
    l=int(l)
    ans=0
    mod=10**9 + 7
    ans=(l-1)%mod
    n=(l-1)/x
    # print(n)
    ans+=n*(l-1) - ((n*(n+1))/2)*x
    ans%=mod
    print(ans)