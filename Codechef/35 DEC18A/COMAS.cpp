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
ll has(ll a,ll b){
    ll sum=a+b;
    sum*=sum+1;
    sum/=2;
    return sum+a;
}

int main()
{
    ll t=sc;
    while(t--){
        ll n=sc,i,j;
        set <ll> ans;
        while(n--)
            ans.insert(n+1);
        while(ans.size()>=7){
            int c=0;
            cout<<"? ";
            for(auto it:ans){
                cout<<it<<' ';
                c++;
                if(c==5)break;
            }
            cout<<endl;
            ans.erase(sc);
            if(ans.size()>6)
                ans.erase(sc);
            else
                sc;
        }
        vector <ll> a;
        for(auto it:ans){
            a.pb(it);
        }
        unordered_map <ll,vector <ll> > xxx;
        unordered_map <ll,ll> xxx2;
        f(i,6){
            cout<<"? ";
            f(j,6){
                if(i!=j){
                    cout<<a[j]<<' ';
                }
            }
            cout<<endl;
            ll x=sc,y=sc;
            xxx2[has(x,y)]++;
            f(j,6){
                if(i!=j&&a[j]!=x&&a[j]!=y){
                    xxx[has(x,y)].pb(a[j]);
                }
            }
        }
        ll ansss;
        for(auto it:xxx2){
            if(it.ss==3){
                unordered_map <ll,ll> xxxx;
                for(auto it2:xxx[it.ff]){
                    xxxx[it2]++;
                    if(xxxx[it2]==3)ansss=it2;
                }
            }
        }
        cout<<"! "<<ansss<<endl;
    }
    
	return 0;
}