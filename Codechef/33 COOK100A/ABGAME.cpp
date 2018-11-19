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
        char sss[2];
        sss[0]='A';
        sss[1]='B';
        string s;
        cin>>s;
        ll n=s.length(),i,j;
        vector <pair <ll,ll > > players;
        f(i,n){
            if(s[i]!='.'){
                players.pb(mp(s[i]=='A',i));
            }
        }

        ll extra=0;
        bool we;
        vector <ll> nim;
        ll playsiz=players.size();
        // prin(players);
        if(playsiz&1){
            // 1 is 'A'
            if(players[playsiz-1].ff)
                extra+=n-1-players[playsiz-1].ss;
            else{
                extra-=n-1-players[playsiz-1].ss;
            }
            players.pop_back();
        }
        f(i,playsiz/2){
            if(players[2*i].ff==players[2*i+1].ff){
                if(players[2*i].ff)
                    extra+=players[2*i+1].ss-players[2*i].ss-1;
                else{
                    extra-=players[2*i+1].ss-players[2*i].ss-1;
                }
            }
            else{
                nim.pb(players[2*i+1].ss-players[2*i].ss-1);
            }
        }
        // cout<<extra<<'\n';
        // prin(nim);
        ll xxxx=0;
        f(i,nim.size()){
            xxxx^=nim[i];
        }
        we=xxxx!=0;
        if(extra){
            if(extra>0){
                we=1;
            }
            else{
                we=0;
            }
        }
        if(we){
            cout<<"A\n";
        }
        else{
            cout<<"B\n";
        }
    }

    return 0;
}