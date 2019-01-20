#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector <ll> fibo;
    fibo.push_back(2);
    fibo.push_back(3);
    while(fibo[fibo.size()-1]<1e10)
        fibo.push_back(fibo[fibo.size()-2]+fibo[fibo.size()-1]);
    ll n;
    while(cin>>n,n)
        if(n==1)
            cout<<"D\n";
        else{
            ll ans=1e11;
            while(n>1){
                auto x=lower_bound(fibo.begin(),fibo.end(),n);
                if(*x>n)x--;
                if(n-=*x)
                    if(*x>n<<1)
                        ans=min(ans,n);
            }
            if(ans==1e11)
                cout<<"L\n";
            else
                cout<<ans<<'\n';
        }
}