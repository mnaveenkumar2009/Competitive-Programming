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
    	int t;
    	cin>>t;
    	while(t--)
    	{
    		int n;
    		sd(n);
    		vector <string> a(n);
    		int i;
    		f(i,n)
    		cin>>a[i];
    		sort(a.begin(),a.end());
    		bool we=1;
    		if(!binary_search(a.begin(), a.end(), "cakewalk"))we=0;
    		if(!binary_search(a.begin(), a.end(), "simple"))we=0;
    		if(!binary_search(a.begin(), a.end(), "easy"))we=0;
    		if(!binary_search(a.begin(), a.end(), "medium")&&!binary_search(a.begin(), a.end(), "easy-medium"))we=0;
    		if(!binary_search(a.begin(), a.end(), "hard")&&!binary_search(a.begin(), a.end(), "medium-hard"))we=0;	
    		if(we)
    		{
    			cout<<"Yes\n";
    		}
    		else
    		{
    			cout<<"No\n";
    		}
    	}
    } 