#include <bits/stdc++.h>
#define ll int
#define pb push_back
#define f first
#define s second
#define ip(x) cin>>x
#define debug(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<" "<<y<<endl
#define debug3(x,y,z) cout<<x<<" "<<y<<z<<endl
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false)
using namespace std;
bool vis[2003][2003];
bool ispali[2003][2003];
ll dp[2003][2003];
ll dp1[2003][2003];
ll t,n,l,r,x,y,m,ans,q;
long long fina;
string s;
bool f(int i,int j)
{
    if(i == j)
        return true;
    if(i + 1 == j)
        return (s[i] == s[j]);
    
    if(vis[i][j])
        return ispali[i][j];
    
    vis[i][j] = 1;

    ispali[i][j] = ((s[i] == s[j] ) && f(i+1,j-1));

    return ispali[i][j];
}
int main()
{
    FIO;
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>s;
        cin>>q;
        n=s.size();
        memset(vis,false,sizeof vis);
        memset(dp,0,sizeof dp);
        memset(dp1,0,sizeof dp1);
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(f(i,j))
                {
                    dp[i][j-i+1]++;
                    dp1[j][j-i+1]++;
                }
            }
        }
        // for(int i=0;i<=s.size();i++)
        // {
        //     for(int j=0;j<=s.size();j++)
        //     {
        //         cout<<dp1[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int j=0;j<=s.size();j++)
        {
            for(int i=1;i<=s.size();i++)
            {
                dp[i][j]+=dp[i-1][j];
                dp1[i][j]+=dp1[i-1][j];
            }
        }
        // for(int i=0;i<=s.size();i++)
        // {
        //     for(int j=0;j<=s.size();j++)
        //     {
        //         cout<<dp1[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<=s.size();i++)
        {
            for(int j=1;j<=s.size();j++)
            {
                dp[i][j]+=dp[i][j-1];
                dp1[i][j]+=dp1[i][j-1];
            }
        }
        // for(int i=0;i<=s.size();i++)
        // {
        //     for(int j=0;j<=s.size();j++)
        //     {
        //         cout<<dp1[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cin>>l>>r>>x>>y>>m;
        fina=0;
        ans=0;
        while(q--)
        {
            l = 1+(l+ans)%n;
            r = 1+(r+ans)%n;
            if(l>r)
            swap(l,r);
            x=1+(x+ans)%m;
            y=1+(y+ans)%n;
            if(x>y)
            swap(x,y);
            // debug2(l,r);
            // debug2(x,y);
            ll gy = min(y,r-l+1);
            if(x>gy)
            {
                ans=0;
            // cout<<ans<<'\n';
                continue;
            }
            if(l!=1)
                ans=dp1[r-1][gy]-dp1[r-1][x-1]-(dp[l-2][gy]-dp[l-2][x-1]);
            else
            {
                ans=dp1[r-1][gy]-dp1[r-1][x-1];
            }
            fina+=ans;
            // cout<<ans<<'\n';
        }
        cout<<fina<<endl;
    }
    return 0;
}