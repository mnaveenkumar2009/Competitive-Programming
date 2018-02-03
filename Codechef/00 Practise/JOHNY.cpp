    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    using namespace std;
    int main()
    {
    	int t;
    	
    	scanf("%d",&t);
    	while(t--)
    	{long long q;
    		int n,i,k;
    		scanf("%d",&n);
    		vector <long long> a(n);
    		f(i,n)
    		{
    			scanf("%d",&a[i]);
    		}
    		scanf("%d",&k);
    		q=a[k-1];
    		sort(a.begin(),a.end());
    			f(i,n)
    			{
    				if(a[i]==q)
    				cout<<i+1<<endl;
    			}
    			
    		
    	}
    	return 0;
    } 