t=int(input())
# print (t)
# # ans=input()
# # ans=1<<ans
for i in range(t):
    ans=0
    n=int(input())
    ans+=1<<n
    n2=int(input())
    for j in range(n2):
        ans-=1<<(n-int(input()))
    
    print("Case #"+str(i+1)+": "+str(ans))
    # print(ans)

# print ans