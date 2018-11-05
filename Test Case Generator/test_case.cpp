#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define gc getchar
#define ll long long

ll ran(ll modu){
    return (rand()%modu)+1;
}
int main()
{
    ll i,j;
    
    srand(time(NULL));
    ll n=1e2-rand()%3,q=1e2-rand()%2;
    cout<<n<<' '<<q<<'\n';
    f(i,n){
        cout<<(ll)(ran(1e9))<<' ';
    }
    cout<<'\n';
    while(q--){
        if(q%2){
            cout<<2<<' '<<ran(n)<<' '<<ran(1e9)<<'\n';
        }
        else{
            ll l=ran(n),r=ran(n);
            if(l>r)swap(l,r);
            cout<<1<<' '<<l<<' '<<r<<'\n';
        }
    }
   	return 0;
}