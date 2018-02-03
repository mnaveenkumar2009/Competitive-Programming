    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
    const int N = 1000070;
    vector<vector<int>> divisors(N+1);
    vector <bool> b(1000009,0);
     
    vector <long long> dp(1000009,-1);
     
    long long f2(int n){
        
        //cout<<n<<" "<<"gd ";
        if(n<0)return 0;
        if(dp[n]!=-1){
          //  cout<<endl;
        return dp[n];}
        //cout<<b[n]<<" ";
        
        if(b[n]){
            
            dp[n]= 1;
            //cout<<dp[n]<<" ";
            int j;
            f(j,divisors[n].size()){
                if(divisors[n][j]!=n)
                dp[n]=(dp[n]+f2(divisors[n][j]))%mod;
               // cout<<j<<" "<<dp[n]<<" ";
            }
            //cout<<endl;
            return dp[n]%mod;
        }
        else{
            //cout<<endl;
        return 0;
        }
    }
    int main()
    {
        for (int i = 2; i <= N; i++) {
            divisors[i].pb(1);
        for (int j = i; j <= N; j += i) {
        divisors[j].push_back(i);
        }
        }
        divisors[1].pb(1);
    	int t=1;
    	cin>>t;
    	while(t--){
    	    int n;
    	    cin>>n;
    	    vector <int> a(n);
    	    int i;
    	    f(i,1000009)b[i]=0,dp[i]=-1;
    	    dp[0]=0;
    	    
    	    f(i,n){
    	        sd(a[i]);
    	        b[a[i]]=1;
    	    }
    	    long long ans=0;
    	    f(i,1000000){
    	        ans=(ans+f2(i))%mod;
    	       // if(i<20)cout<<ans<<endl;
    	    }
    	    
    	    cout<<ans<<endl;
    	}
    	int i;
    	//f(i,500)if(b[i])cout<<dp[i]<<endl;
    	return 0;
    } 