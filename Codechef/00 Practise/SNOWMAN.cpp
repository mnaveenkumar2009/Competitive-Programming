#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector <ll> fib={2,3};
    while(fib.back()<7e10)
        fib.push_back(fib[fib.size()-2]+fib.back());
    ll n;
    while(cin>>n,n)
        if(n==1)
            cout<<"D\n";
        else{
            ll ans=7e9;
            while(n>1){
                auto x=lower_bound(fib.begin(),fib.end(),n);
                if(*x>n)x--;
                if(n-=*x)
                    if(*x>n<<1)
                        ans=min(ans,n);
            }
            ans==7e9? cout<<"L\n":cout<<ans<<'\n';
        }
}