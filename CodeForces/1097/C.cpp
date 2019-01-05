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
#define vl vector <ll>
#define vvl vector <vector <ll> >
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
    f(i,a.size()/2){
        cout<<a[i]<<' ';
    }pc('\n');

    f(i,a.size()/2){
        cout<<a[a.size()/2+i]<<' ';
    }pc('\n');
}
void prin(ll a[],ll n){
    ll i;
    f(i,n/2){
        cout<<a[i]<<' ';
    }pc('\n');

    f(i,n/2){
        cout<<a[n/2+i]<<' ';
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
    ll n=sc,i,j,k;
    multiset <ll>  lef,rig;
    ll zer=0;
    f(i,n){
        string s;
        cin>>s;
        ll num=0;
        bool we=0,we1=0;
        f(j,s.length()){
            if(s[j]=='('){
                num++;
            }
            else{
                num--;
            }
            if(num<0){
                we=1;break;
            }
        }
        num=0;
        f(j,s.length()){
            if(s[s.length()-j-1]==')'){
                num++;
            }
            else{
                num--;
            }
            if(num<0){
                we1=1;break;
            }
        }

        if(we&&we1)continue;
        // cout<<s<<'\n';


        num=0;
        bool leff=0,rigg=0;
        f(j,s.length()){
            if(s[j]=='('){
                num++;
            }
            else{
                num--;
            }
        }
        if(num>0){
            lef.insert(num);
        }
        if(num<0){
            rig.insert(-num);
        }
        if(num==0){
            zer++;
        }
    }
    // for(auto it:lef){
    //     cout<<it<<' ';
    // }
    // cout<<'\n';
    // for(auto it:rig){
    //     cout<<it<<' ';
    // }
    // cout<<'\n';
    // cout<<zer<<'\n';
    ll ans=zer/2;
    for(auto it:lef){
        if(rig.find(it)!=rig.end()) {
            ans++;
            rig.erase(rig.find(it));
        }
    }

    cout<<ans<<'\n';
    
    return 0;
}