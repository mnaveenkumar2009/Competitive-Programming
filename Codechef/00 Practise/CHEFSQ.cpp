    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    int main()
    {
        
    	int t;
    	cin>>t;
    	while(t--){
    	    int n,m,i,k;
    	    vector <int> num(1000000,0);
    	    cin>>n;
    	    f(i,n){cin>>k;num[k]++;}
    	    cin>>m;
    	    f(i,m){cin>>k;num[k]--;}
    	    bool we=1;
    	    f(i,1000000)if(num[i]<0)we=0;
    	    if(we)
    	    printf("Yes\n");
    	    else
    	    printf("No\n");
    	    
    	}
    	
    	return 0;
    } 