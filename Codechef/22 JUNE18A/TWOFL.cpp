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
inline ll uscan()
{
    ll n=0,c=gc();
    bool check=0;
    if(c=='-')check=1;
    while(c<'0'||c>'9')
    {
        c=gc();
        if(c=='-')check=1;
    }
    while(c<='9'&&c>='0'){
        n=n*10+c-'0';
        c=gc();
    }
    return n+(-2*check*n);
}
unordered_map < ll ,ll> ans[4000003],O[4000003],orgy[4000003];
unordered_map < ll ,ll> :: iterator it;
vector <ll> freq(4000003,0);
ll n,m,i,j,a[2005][2005],b[2005][2005];
bool f3(ll x,ll y){
    return (a[i+1][j+1]==a[i+x][j+y]);
}
bool f4(ll x,ll y){
    return (b[x][y]==-1);
}
void f5(){
    if(f3(1,0)){
        b[i+1][j+1]=min(b[i+1][j+1],b[i+1][j]);
    }
    if(f3(1,2)){
        b[i+1][j+1]=min(b[i+1][j+1],b[i+1][j+2]);
    }
    if(f3(0,1)){
        b[i+1][j+1]=min(b[i+1][j+1],b[i][j+1]);
    }
    if(f3(2,1)){
        b[i+1][j+1]=min(b[i+1][j+1],b[i+2][j+1]);
    }
}
void f2(ll x, ll y){
    if(!f3(x,y)&&!f4(i+x,j+y)){
        ll xxx= a[i+1][j+1]+a[i+x][j+y];
        xxx=(xxx*(xxx+1))>>1;
        xxx+=min(a[i+1][j+1],a[i+x][j+y]);

        ll val=min(b[i+1][j+1],b[i+x][j+y]);
        ll val2=O[b[i+x][j+y]][xxx];
        ll val3=O[b[i+1][j+1]][xxx];
        if(!val2)val2=INT_MAX;
        if(!val3)val3=INT_MAX;
        val=min(val,min(val2,val3));
        if(val2!=val)
        O[b[i+x][j+y]][xxx]=val;
        if(val3!=val)
        O[b[i+1][j+1]][xxx]=val;
    }
}
void f6(ll x, ll y){
    if(!f3(x,y)&&!f4(i+x,j+y)){
        ll xxx= a[i+1][j+1]+a[i+x][j+y];
        xxx=(xxx*(xxx+1))>>1;
        xxx+=min(a[i+1][j+1],a[i+x][j+y]);
        ll val2=O[b[i+x][j+y]][xxx];
        ll val3=O[b[i+1][j+1]][xxx];
        if(val2<val3)
            orgy[val3][xxx]=val2;
        else
            if(val2!=val3)
            orgy[val2][xxx]=val3;
    }
}
int main()
{
    n=uscan();
    m=uscan();
    f(j,m+2){
        f(i,n+2){
            a[i][j]=1234567889;
            b[i][j]=-1;
        }
    }
    f(i,n){
        f(j,m){
            a[i+1][j+1]=uscan();
        }
    }
    ll bind=2;
    f(i,n){
        f(j,m){
            b[i+1][j+1]=bind++;
            if(f3(1,2)&&b[i+1][j+2]!=-1){
                b[i+1][j+1]=min(b[i+1][j+1],b[i+1][j+2]);
            }
            if(f3(1,0)&&b[i+1][j]!=-1){
                b[i+1][j+1]=min(b[i+1][j+1],b[i+1][j]);
            }
            if(f3(2,1)&&b[i+2][j+1]!=-1){
                b[i+1][j+1]=min(b[i+1][j+1],b[i+2][j+1]);
            }
            if(f3(0,1)&&b[i][j+1]!=-1){
                b[i+1][j+1]=min(b[i+1][j+1],b[i][j+1]);
            }
            if(b[i+1][j+1]+1!=bind){
                bind--;
            }
        }
    }
    f(i,n){
        f(j,m){
            f5();
        }
        for(j=m-1;j>=0;j--){
            f5();
        }
    }
    for(i=n-1;i>=0;i--){
        for(j=m-1;j>=0;j--){
            f5();
        }
    }
//  f(i,n){
//         f(j,m){
//             cout<<b[i+1][j+1];
//         }cout<<'\n';
//     }
    f(i,n){
        f(j,m){
            freq[b[i+1][j+1]]++;
        }
    }
    f(i,n){
        f(j,m){       
            //f2(1,0);
            f2(1,2);
            //f2(0,1);
            f2(2,1);
        }
        for(j=m-1;j>=0;j--){
            f2(1,0);
            //f2(1,2);
            //f2(0,1);
            f2(2,1);
        } 
    }
    for(i=n-1;i>=0;i--){
        f(j,m){       
            //f2(1,0);
            f6(1,2);
            f6(0,1);
            //f6(2,1);
        }
    }
    ll prin=1;
    f(i,4000003)prin=max(prin,freq[i]);
    f(i,4000003){
        for(it=O[i].begin();it!=O[i].end();++it){
            //cout<<'d';
            // cout<<i<<' '<<it->second<<' '<<it->ff<<'\n';
            ans[it->second][it->first]+=freq[i];
        }
    }
    for(i=4000002;i>=0;i--){
        for(it=orgy[i].begin();it!=orgy[i].end();++it){
            ans[it->second][it->first]+=ans[i][it->first];
            // cout<<i<<' '<<ans[it->second][it->first]<<' '<<ans[i][it->first]<<"fds"<<it->first<<' '<<it->second<<'\n';
        }
    }   
    f(i,4000003){
        for(it=ans[i].begin();it!=ans[i].end();++it){
            prin=max(prin,it->second);
        }
    }
    cout<<prin<<'\n';
    return 0;
}   