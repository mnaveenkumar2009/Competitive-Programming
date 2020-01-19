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
#define sort(a) sort(a.begin(),a.end())
#define sortn(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
inline ll uscan(){
    ll n=0,c=gc();bool check=0;
    while(c<'0'||c>'9'){if(c=='-')check=1;c=gc();}
    while(c<='9'&&c>='0'){n=n*10+c-'0';c=gc();}
    return check?-n:n;
}
#define sc uscan()
void prin(vector <ll> a){
    for(auto it:a)cout<<it<<' ';pc('\n');
}
void prin(vector <vector <ll> > a){
    for(auto vec:a){for(auto it:vec)cout<<it<<' ';pc('\n');}pc('\n');
}
void prin(vector <pair <ll,ll> > a){
    for(auto it:a)cout<<it.ff<<' '<<it.ss<<'\n';pc('\n');
}
int main()
{
    ll t=sc;
    while(t--){
        // ll n=sc;
        ll i,j,k;
        string s1,s2;
        cin>>s1>>s2;
        vector <pair<char,int> > a,b;
        ll n=s1.length(),n2=s2.length();
        a.pb(mp(s1[0],1));
        f(i,n-1){
            if(s1[i+1]==s1[i]){
                a[a.size()-1].ss++;
            }
            else{
                a.pb(mp(s1[i+1],1));
            }
        }
        b.pb(mp(s2[0],1));
        f(i,n2-1){
            if(s2[i+1]==s2[i]){
                b[b.size()-1].ss++;
            }
            else{
                b.pb(mp(s2[i+1],1));
            }
        }
 
        n=a.size(),n2=b.size();
        i=0,j=0;
        if(n!=n2){
            cout<<"NO\n";
            continue;
        }
        f(i,n){
            if((a[i].ff!=b[i].ff)||(a[i].ss>b[i].ss))break;
        }
        if(i==n){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}