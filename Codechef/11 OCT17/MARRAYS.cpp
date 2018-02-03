#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define slld(n) scanf("%lld",&n)
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
void prin(vector < vector <int> > a,int n){
    int i;
    int j;
    f(i,n){
        f(j,a[i].size())cout<<a[i][j]<<" ";cout<<endl;
    }
}
 
int main()
{
	int t=1;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector < vector <ll> > dp(n,vector <ll>(4,0));
	    vector < vector <ll> > a(n, vector <ll>(0));
	    int i,j,m;
	    f(i,n){
	        sd(m);
	        f(j,m){
	            ll h;
	            slld(h);a[i].pb(h);
	        }
	        a[i].pb(a[i][0]);
	    }
	    
	    vector<vector <pair <ll,ll> > > b(4,vector <pair <ll,ll> >(n));
	    f(i,n){
	    	b[0][i].first=a[i][0];
	    	b[0][i].second=a[i][1];
	        b[1][i].first=a[i][0];
	    	b[1][i].second=a[i][1];
	    	b[2][i].first=a[i][0];
	    	b[2][i].second=a[i][1];
	    	b[3][i].first=a[i][0];
	    	b[3][i].second=a[i][1];
			
			int sizz=a[i].size()-1;
	        f(j,sizz){
	            if((b[0][i].first*(i+1)+b[0][i].second*(i))<(a[i][j]*(i+1)+a[i][j+1]*i)){
	                b[0][i].first=a[i][j];
	                b[0][i].second=a[i][j+1];
	            }
	            if(-(b[1][i].first*(i+1)-b[1][i].second*(i))<-(a[i][j]*(i+1)-a[i][j+1]*i)){
	                b[1][i].first=a[i][j];
	                b[1][i].second=a[i][j+1];
	            }
	            if(((b[2][i].first)*(i+1)-b[2][i].second*(i))<(a[i][j]*(i+1)-a[i][j+1]*i)){
	                b[2][i].first=a[i][j];
	                b[2][i].second=a[i][j+1];
	            }
	            if(((-b[3][i].first)*(i+1)-b[3][i].second*(i))<-(a[i][j]*(i+1)+a[i][j+1]*i)){
	                b[3][i].first=a[i][j];
	                b[3][i].second=a[i][j+1];
	            }
	        }
	    }
	    //prin(a,n);
	    f(i,n){
	        f(j,4)
	        swap(b[j][i].ff,b[j][i].ss);
	    }
	    /*
		f(i,n){
		    
	            cout<<b[0][i].first<<" "<<b[1][i].first<<" "<<b[2][i].first<<" "<<b[3][i].first<<endl;;
	    }
	    cout<<endl;
	    f(i,n){
	            cout<<b[0][i].second<<" "<<b[1][i].second<<" "<<b[2][i].second<<" "<<b[3][i].second<<endl;;
	    }*/
	    dp[0][0]=0;
	    dp[0][2]=0;
		dp[0][1]=0;
		dp[0][3]=0;
		long long mini=INT_MAX,maxi=0;
		f(i,a[n-1].size()){
		    if(mini>a[n-1][i])mini=a[n-1][i];
		    if(maxi<a[n-1][i])maxi=a[n-1][i];
		}
		//int cur[4];
		//0 ++ 1+- 2-+ 3--
		b[2][n-1].ff=mini;
		b[3][n-1].ff=mini;
		b[1][n-1].ff=maxi;
		b[0][n-1].ff=maxi;
	    f(i,n-1){
	        
	        if(dp[i][0]+abs(b[0][i].ss-b[2][i+1].ff)*(i+1)>dp[i][2]+abs(b[2][i].ss-b[2][i+1].ff)*(i+1)){
	            dp[i+1][2]=dp[i][0]+abs(b[0][i].ss-b[2][i+1].ff)*(i+1);
	            //cout<<1<<i<<endl;
	        }
	        else{
	            dp[i+1][2]=dp[i][2]+abs(b[2][i].ss-b[2][i+1].ff)*(i+1);
	            //cout<<2<<i<<endl;
	        }
	        if(dp[i][0]+abs(b[0][i].ss-b[3][i+1].ff)*(i+1)>dp[i][2]+abs(b[2][i].ss-b[3][i+1].ff)*(i+1)){
	            dp[i+1][3]=dp[i][0]+abs(b[0][i].ss-b[3][i+1].ff)*(i+1);
	            //cout<<3<<i<<endl;
	        }
	        else{
	            dp[i+1][3]=dp[i][2]+abs(b[2][i].ss-b[3][i+1].ff)*(i+1);
	            //cout<<4<<i<<endl;
	        }
	        if(dp[i][1]+abs(b[1][i].ss-b[0][i+1].ff)*(i+1)>dp[i][3]+abs(b[3][i].ss-b[0][i+1].ff)*(i+1)){
	            dp[i+1][0]=dp[i][1]+abs(b[1][i].ss-b[0][i+1].ff)*(i+1);
	            //cout<<5<<i<<endl;
	        }
	        else{
	            dp[i+1][0]=dp[i][3]+abs(b[3][i].ss-b[0][i+1].ff)*(i+1);
	            //cout<<6<<i<<endl;
	        }
	        if(dp[i][1]+abs(b[1][i].ss-b[1][i+1].ff)*(i+1)>dp[i][3]+abs(b[3][i].ss-b[1][i+1].ff)*(i+1)){
	            dp[i+1][1]=dp[i][1]+abs(b[1][i].ss-b[1][i+1].ff)*(i+1);
	            //cout<<7<<i<<endl;
	            
	        }
	        else{
	            dp[i+1][1]=dp[i][3]+abs(b[3][i].ss-b[1][i+1].ff)*(i+1);
	            //cout<<8<<i<<endl;
	        }
		}
	//	f(i,n)cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<"\n";
	    cout<<max(max(dp[n-1][2],dp[n-1][3]),max(dp[n-1][0],dp[n-1][1]))<<endl;
	    //cout<<(3+5*7)<<endl;
	}
	return 0;
} 