#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll int
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

#define vl vector <ll> 
#define vvl vector <vector <ll> >
const int N = 10000000;
int lp[N+1];
vector<int> pr;

int main(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    ll n=sc;
    multiset <pair <ll,ll> > a;

    ll i,j;
    // f(i,20)cout<<lp[i]<<'\n';

    f(i,n){
        a.insert(mp(sc,i));
    }
    vector <pair <ll,ll> > ans;
    ll sum=0;
    f(i,n){
        pair <ll,ll> num=*a.begin();
        for(auto it:a){
            if((lp[it.ff+sum]==it.ff+sum)){
                num=it;
                break;
            }
        }
        ans.pb(num);
        sum+=num.ff;
        a.erase(a.find(num));
    }

    f(i,n-1){
        cout<<ans[i].ss+1<<' '<<ans[i+1].ss+1<<'\n';
    }
}