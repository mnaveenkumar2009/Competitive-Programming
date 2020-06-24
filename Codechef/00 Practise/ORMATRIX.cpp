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
void prin(vector < pair<ll,ll> > a){
    ll i,j;
    f(i,a.size()){
        cout<<a[i].ff<<' '<<a[i].ss<<'\n';
    }
    pc('\n');
}

int main()
{
    int t=uscan();
    while(t--){
        ll n=sc;
        ll m=sc;
        ll i,j,k;
        ll a[n][m],ans[n][m];
        ll sumh[n][m],sumv[n][m];
        f(i,n){
            string s;
            cin>>s;
            f(j,m){
                a[i][j]=s[j]-'0';
                sumh[i][j]=a[i][j];
                sumv[i][j]=a[i][j];
                // cout<<a[i][j]<<' ';
            }//pc('\n');
        }
        f(i,n){
            f(j,m){
                if(j){
                    sumh[i][j]+=sumh[i][j-1];
                }
                if(i){
                    sumv[i][j]+=sumv[i-1][j];
                }
            }
        }
        f(i,n){
            f(j,m){
                ans[i][j]=2;
                if(sumh[i][m-1]||sumv[n-1][j]){
                    ans[i][j]=1;
                }
                if(a[i][j]){
                    ans[i][j]=0;
                }
            }
        }
        bool we=1;
        f(i,n){
            f(j,m){
                if(a[i][j])we=0;
            }
        }
        if(we){
            f(i,n){
                f(j,m){
                    ans[i][j]=-1;
                }
            }
        }
        f(i,n){
            f(j,m){
                cout<<ans[i][j]<<' ';
            }pc('\n');
        }
    }
	return 0;
} 