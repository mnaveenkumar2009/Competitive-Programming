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
void prin(ll a[],ll n){
    ll i;
    f(i,n){
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
#define vl vector <ll> 
#define vvl vector <vector <ll> >
#define vpl vector <pair <ll,ll> >

char a[1005][1005];
ll n,m;
bool pos(ll i,ll j){
    if(i<0)return 0;
    if(j<0)return 0;
    if(i+1>=n)return 0;
    if(j+1>=m)return 0;

    return ((a[i][j]=='.')&&(a[i+1][j]=='.')&&(a[i][j+1]=='.')&&(a[i+1][j+1]=='.'));
}
int main()
{
    ll tt=sc,kkk;

    f(kkk,tt){
        n=sc,m=sc;
        ll i,j;
        f(i,n){
            string s;
            cin>>s;
            f(j,m){
                a[i][j]=s[j];
            }
        }
        bool ans=1;
        f(i,n){
            f(j,m)
            {
                if(a[i][j]=='.'){
                    bool we=0;
                    ll l=i-1,r=j-1;
                    ll ii,jj;
                    f(ii,2){
                        f(jj,2){
                            if(pos(l+ii,r+jj)){
                                we=1;
                                break;
                            }
                        }
                    }
                    if(!we){
                        ans=0;
                        break;
                    }
                }
            }
        }
        if(ans){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}