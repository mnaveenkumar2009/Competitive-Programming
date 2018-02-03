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
    		getchar();
    		string s;
    		cin>>s;
    		//cout<<s;
    		int n=s.length();
    		s.pb('X');
    		vector <int> a(1,0);
    		int i;
    		f(i,n-1){
    			if(s[i+1]!=s[i])a.pb(i+1);
    		}
    		a.pb(n);
    		int nn=a.size();
    		long long count=0;
    		f(i,nn-1){
    			if(i)
    			if(s[a[i]-1]==s[a[i+1]])count+=1;
    		}
    		f(i,nn-1){
    			long long h=a[i+1]-a[i];
    			if(h>1)
    			count+=(h*(h-1))/2;
    		}
    		cout<<count<<endl;
    	}
    	return 0;
    }  