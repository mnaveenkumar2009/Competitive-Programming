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
    ll n=1e5-rand()%3;
    cout<<n<<'\n';
    f(i,n){
        cout<<(ll)(ran(2e9)-1e9)<<' ';
    }
   	return 0;
}