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
#define sort1(a) sort(a.begin(),a.end())
#define sort2(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
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
#define sc uscan()
void prin(vector <ll> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(vector <vector <ll> > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j]<<' ';
        pc('\n');
    }
    pc('\n');
}
void prin(vector <vector <pair <ll,ll> > > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j].ss<<' ';
        pc('\n');
    }
    pc('\n');
}
string has(ll a,ll b,ll c){
    ll d=0;
    string ans;
    while(a!=0){
        ans.pb(a%255);
        a/=255;
    }
    ans.pb(255);
    while(b!=0){
        ans.pb(b%255);
        b/=255;
    }
    ans.pb(255);
    while(c!=0){
        ans.pb(c%255);
        c/=255;
    }
    ans.pb(255);
    while(d!=0){
        ans.pb(d%255);
        d/=255;
    }
    ans.pb(255);

    return ans;
}
int main()
{
    ll n=sc,m=sc;
    vvl a(n,vl (m));
    
    vector <vector <vector <bool > > > xxx(n,vector <vector <bool > >(n,vector <bool > (m,0)));
    ll i,j,k;
    ll ans=0;
    f(i,n){
        f(j,m){
            a[i][j]=sc;
        }
    }
    f(i,n){
        f(j,n){
            if(j>=i)
                ans+=((j-i+1)*m*(m+1))/2;
        }
    }
    // cout<<ans<<'\n';
    f(i,n){
        f(j,n){
            if(j>i){
                // row i,j
                ll temp=0;
                ll cn=0;
                f(k,m){
                    if(a[i][k]==a[j][k]){
                        cn++;
                        xxx[i][j][k]=1;
                    }
                    else{
                        cn=0;
                    }
                }
                if(cn){
                    cn=0;
                }
            }
        }
    }
    f(i,n){
        f(j,n){
            if(j>i){
                // row i,j
                ll temp=0;
                ll cn=0;
                ll lass=i-1;
                f(k,m){
                    if(a[i][k]==a[j][k]){
                        cn++;
                        ll pos1,pos2=n;
                        for (pos1=lass;pos1>=0;pos1--){
                            if(xxx[pos1][i][k]){
                                break;
                            }
                        }
                        lass=pos1;
                        // for (pos2=j+1;pos2<n;pos2++){
                        //     if(xxx[i][pos2][k]){
                        //         break;
                        //     }
                        // }
                        ll xyz=1;
                        temp+=(cn)*(i-pos1)*(pos2-j);
                        // cout<<temp<<' '<<pos1<<' '<<pos2<<'s'<<'\n';
                    }
                    else{
                        cn=0;
                        lass=i-1;
                    }
                }
                                
                // temp*=(i-pos1)*(pos2-j);
                // cout<<i<<' '<<j<<' '<<temp<<'\n';
                ans-=temp;
            }
        }
    }

    cout<<ans;
    return 0;
}

/*
3 3
1 2 3
1 2 3
1 2 3
*/