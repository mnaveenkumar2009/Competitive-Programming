#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define sort(a) sort(a.begin(),a.end())
#define sortn(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
inline ll uscan(){
    ll n=0,c=gc();bool check=0;
    while(c<'0'||c>'9'){if(c=='-')check=1;c=gc();}
    while(c<='9'&&c>='0'){n=n*10+c-'0';c=gc();}
    return check?-n:n;
}
#define sc uscan()
void prin(vector <ll> a){
    for(auto it:a)cout<<it<<' ';pc('\n');
}
void prin(vector <vector <ll> > a){
    for(auto vec:a){for(auto it:vec)cout<<it<<' ';pc('\n');}pc('\n');
}
void prin(vector <pair <ll,ll> > a){
    for(auto it:a)cout<<it.ff<<' '<<it.ss<<'\n';pc('\n');
}

int main(){
    int t=sc,kkk=1;
    while(t--){
        ll n=sc,m=sc;
        vector <ll> a(n);
        int i,j,k;
        vector <ll> pos[n];
        f(i,n){
            a[i]=i;
            pos[i].pb(i);
        }
        f(i,m){
            ll x=sc-1,y=sc-1;
            while(x<y){
                if(a[x]!=a[y]){
                    ll ff=min(a[x],a[y]),gg=max(a[x],a[y]);
                    for(auto it:pos[gg]){
                        a[it]=ff;
                        pos[ff].pb(it);
                    }
                    pos[gg].clear();
                }
                x++;y--;
            }
        }
        // prin(a);
        unordered_map <ll,ll> xxx;
        ll cur_num=1;
        vector <ll> b(n,-1);
        vector <ll> arr(n,0),ans(n,1);
        f(i,n){
            if(!xxx[a[i]]){
                xxx[a[i]]=cur_num++;
                b[cur_num-2]=a[i];
            }
        }
        f(i,n){
            arr[xxx[a[i]]-1]++;
        }
        vector <vector <bool > > dp(cur_num,vector <bool >(n+1,0));
        f(i,cur_num){
            f(j,n+1)
                dp[i][j]=0;
        }

        for ( i = 0; i < cur_num; i++)
            dp[i][0] = true;
        for ( i = 1; i < n+1; i++) 
            dp[0][i] = false;
        for ( i=1; i<cur_num; i++) 
        { 
            for ( j=1; j<n+1; j++) 
            {
                dp[i][j] = dp[i-1][j];
                if (arr[i-1] <= j) 
                    if(!dp[i][j])
                    dp[i][j] = dp[i-1][j-arr[i-1]]; 
            }
        }
        for ( j=(n)/2; j>=0; j--) {
            if (dp[cur_num-1][j] == true)
                break;
        } 
        // cout<<j<<' '<<n - 2*j<<'\n';
        for(i=cur_num-1;i>=1;i--){
            if(!dp[i][j]){
                ans[i]=0;
                j-=arr[i];
            }
        }
        // cout<<j<<' '<<n - 2*j<<'\n';
        if(j){
            ans[0]=0;
        }
        string ban;
        f(i,n)ban.pb('1');
        f(i,n){
            ban[i]=ans[xxx[a[i]]-1]+'0';
        }
        cout<<"Case #"<<kkk++<<": ";
        cout<<ban<<'\n';
    }

}