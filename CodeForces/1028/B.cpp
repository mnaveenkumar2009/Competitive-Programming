#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define f(i,n) for(i=0;i<n;i++)
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
    ll t=1,kkk=0;
    f(kkk,t){
        ll n=uscan(),m=uscan(),i;

        string s1,s2;
        f(i,2230){
            s1.pb('3');
        }
        f(i,2230){
            s2.pb('6');
        }
        s1[s1.length()-1]='4';
        cout<<s1<<'\n'<<s2<<'\n';
        // cout<<s1.length();
    }
    return 0;
}