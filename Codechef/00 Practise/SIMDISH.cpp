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
int main() {
    int t=uscan();
    while(t--){
        string s[8];
        int i,j,ans=0;
        f(i,8)
        cin>>s[i];
        f(i,4){
            f(j,4){
                if(s[i]==s[j+4])
                    ans++;
            }
        }
        if(ans>=2)
        cout<<"similar\n";
        else
            cout<<"dissimilar\n";
    }
    return 0;
}
