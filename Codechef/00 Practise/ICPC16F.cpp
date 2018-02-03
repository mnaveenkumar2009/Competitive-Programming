    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
     
    int main()
    {
    	int t=1;
    	cin>>t;
    	while(t--){
    	int n,m,d,D;
    	cin>>n>>m>>d>>D;
    	bool we=1;
    	vector < vector <int> > a(n, vector <int> (0,0)),b(n, vector <int>(0,0));
    	
    	int count=0;
    	int i,j;
    	int max=m/n;
    	int mo=m%n;
    	f(i,n){
    	    f(j,max){
    	        a[i].pb(count);
    	        count++;
    	        count%=n;
    	    }
    	    if(mo>0){
    	        a[i].pb(count);
    	        count++;
    	        mo--;
    	        count%=n;
    	    }
    	}
    	f(i,n){
    	    f(j,a[i].size()){
    	        b[a[i][j]].pb(i);
    	    }
    	}
    	f(i,n){
    	    if(b[i].size()<d||b[i].size()>D){
    	        we=0;
    	        //cout<<b[i].size()<<endl;
    	    }
    	}
    	if(we)
    	{
    	    f(i,n){
    	        f(j,a[i].size()){
    	            printf("%d %d\n",i+1,a[i][j]+1);
    	        }
    	    }
    	}   
    	else
    	cout<<"-1\n";
    	}
    	return 0;
    } 