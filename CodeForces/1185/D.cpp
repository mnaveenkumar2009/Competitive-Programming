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
bool checkap(vector <ll> &a){
    sort(a);
    int i,n=a.size();
    for(i=2;i<n;i++){
        if((a[i-1]-a[i-2])!=(a[i]-a[i-1]))break;
    }
    return i==n;
}
int main()
{
    ll n=sc;
    if(n<=3){
        cout<<1;
        return 0;
    }
    ll i,j,k,ans=-1,d;
    vl a(n),b;
    f(i,n){
        a[i]=sc;
    }
    b=a;
 
    sort(a);
    if(checkap(a)){
        f(i,n){
            if(b[i]==a[0]){
                cout<<i+1;
                return 0;
            }
        } 
        return 0;
    }
    {
        d=a[n-1]-a[n-2];
        for(i=n-3;i>=0;i--){
            if(a[i+1]-a[i]!=d){
                break;
            }
        }
        ans=a[i];
        a.erase(a.begin()+i);
        if(checkap(a)){
            f(i,n){
                if(b[i]==ans){
                    // cout<<"fir";
                    cout<<i+1;
                    return 0;
                }
            } 
        }
    }
 
    {
        a=b;
        sort(a);
        i=n-1;
        ans=a[i];
        a.erase(a.begin()+i);
        if(checkap(a)){
            f(i,n){
                if(b[i]==ans){
                    // cout<<"fir";
                    cout<<i+1;
                    return 0;
                }
            } 
        }
    }
    {
        a=b;
        sort(a);
        i=n-2;
        ans=a[i];
        a.erase(a.begin()+i);
        if(checkap(a)){
            f(i,n){
                if(b[i]==ans){
                    cout<<i+1;
                    return 0;
                }
            } 
        }
    }
    
    cout<<-1;
    return 0;
}