#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define gc getchar
#define ll long long

ll ran(){
    return rand()%((ll)1e9)+1;
}
int main()
{
    ll i,j;
    
    srand(time(NULL));
    ll n=1000;
    cout<<n<<'\n';
    vector <ll> a(n);
    f(i,n)a[i]=i+1;
    random_shuffle ( a.begin(), a.end() );
    f(i,n){
        cout<<a[i]<<' ';
    }pc('\n');

    
   	return 0;
}