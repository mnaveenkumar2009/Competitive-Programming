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
    		int n,k;
    		cin>>n>>k;
    		int i;
    		vector <int> a(n);
    		f(i,n)sd(a[i]);
    		sort(a.begin(),a.end());
    		cout<<a[(n+k)/2]<<endl;
    	}
    	return 0;
    } 