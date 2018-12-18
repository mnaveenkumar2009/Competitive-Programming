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
int main()
{
    // ll t=sc;
    ll t=1;
    while(t--){
        ll n=sc,c=sc;
        ll i,j,k;
        f(i,100){
            cout<<1<<' '<<min(i*1500+1,n)<<endl;
            if(sc){
                cout<<2<<endl;
                break;
            }
        }
        if(!i){
            cout<<3<<' '<<1<<endl;
            continue;
        }
        // breaks at max i*1500+1,n
        ll low=(i-1)*1500+1;
        ll high=min(i*1500+1,n);
        f(i,10){
            cout<<1<<' '<<min(low+i*100,high)<<endl;
            if(sc){
                cout<<2<<endl;
                break;
            }
        }

        low=low+(i-1)*100;
        high=min(low+i*100,high);
        while(low!=high){
            cout<<1<<' '<<low<<endl;
            if(sc){
                cout<<2<<endl;
                break;
            }
            low++;
        }
        cout<<3<<' '<<low<<endl;
    }
	return 0;
}