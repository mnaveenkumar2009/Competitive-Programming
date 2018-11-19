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

int main()
{
    ll tt=sc,kkk;

    f(kkk,tt){
        string s;
        cin>>s;
        ll d=0,c=0,i;
        vector <ll > a(s.length());
        f(i,s.length()){
            if(s[i]!='R'){
                if(i&1){
                    a[i]=1;
                }
                else{
                    a[i]=0;
                }
            }
            else{
                if(i&1){
                    a[i]=0;
                }
                else{
                    a[i]=1;
                }
            }
        }
        // prin(a);
        ll coun=0;
        f(i,s.length()){
            if(!i)continue;
            if(a[i]!=a[i-1])coun++;
        }
        if(coun<=2){
            bool we=1;
            ll n=s.length();
            if(a[0]==0)
            f(i,n){
                a[i]=1-a[i];
            }
            //  1111100001111
            coun=0;
            f(i,n)
            {
                if(a[i]==0)coun++;
            }
            if(coun%2==0&&n%2==0)
            cout<<"yes\n";
            else
            cout<<"no\n";
        }
        else{
            cout<<"no\n";
        }
    }

    return 0;
}