n,q,k=raw_input().split(" ")
n=int(n)
q=int(q)
k=int(k)
a= list(raw_input().split(" "))
for i in range(n):
    a[i]=int(a[i])
s=raw_input()
# print(s)
xxx=[]
i=0
ans=[0]*n
freq=[0]*1000090
while(i<n):
	if(a[i]==0):
		xxx.append(0)
		i=i+1
	else:
		count=0
		while(i<n and a[i]==1):
			count=count+1
			i=i+1
		xxx.append(count)
for i in range (len(xxx)):
	if(xxx[i]!=0):
		freq[xxx[i]]+=1

ans[0]=max(xxx)
maxi=ans[0]
nn=len(xxx)
# print(xxx)
for i in range (1,n):
	# print (xxx)
	if(xxx[nn-1]==0):
		xxx.pop(nn-1)
		xxx.insert(0,0)
		ans[i]=maxi
	else:
		if(xxx[nn-1]>1):
			if(xxx[0]==0):
				x=xxx[nn-1]
				freq[x]-=1
				freq[x-1]+=1
				freq[1]+=1
				xxx[nn-1]-=1
				nn+=1
				xxx.insert(0,1)
			elif(xxx[0]>0):
				x1=xxx[nn-1]
				x2=xxx[0]
				freq[x1-1]+=1
				freq[x2]-=1
				freq[x1]-=1
				freq[x2+1]+=1
				xxx[nn-1]-=1
				xxx[0]+=1
		elif(xxx[nn-1]==1):
			if(xxx[0]==0):
				xxx.pop()
				xxx.insert(0,1)
			elif(xxx[0]>0):
				freq[xxx[0]+1]+=1
				freq[xxx[0]]-=1
				freq[1]-=1
				xxx.pop()
				xxx[0]+=1
				nn-=1
		if(freq[maxi+1]>0):
			maxi=maxi+1
		if(freq[maxi]==0):
		    if(freq[maxi-1]>0):
			    maxi=maxi-1
	
		ans[i]=maxi

count=0
if(xxx[0]>k):
    xxx[0]=k
    
for i in range(len(ans)):
    ans[i]=min(ans[i],k)
# print(ans)
if(len(xxx)==1):
	for i in range (q):
		if(s[i]=='?'):
			print(xxx[0])
else:
	for i in range (q):
		if(s[i]=='!'):
			count+=1
			if count==n:
			    count=0
		else:
			print(ans[count])
