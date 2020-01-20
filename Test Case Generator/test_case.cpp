#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define gc getchar
#define ll long long
#define ld long double

ll ran(ll modu){
    return (rand()%modu)+1;
}
int main()
{
    ll i,j;
    srand(time(NULL));
    ll t=1e5;
    cout<<t<<'\n';
    while(t--){
        int n = ran(1e9);
        cout << n << '\n';
        ld P = rand()%1001;
        ld Q = rand()%(1001-(int)P);
        ld R = 1000 - (P+Q);
        P/=1000.0;
        Q/=1000.0;
        R/=1000.0;
        cout << P << ' ' << Q << ' ' << R << '\n';
    }
   	return 0;
}