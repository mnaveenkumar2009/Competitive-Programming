#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define gc getchar
#define ll long long
int main()
{
    ll i,j;
    
    srand(time(NULL));
    ll t=100000;
    cout<<t<<'\n';

    f(i,t){
        cout<<(rand())%1000000000+1<<' '<<rand()%1000000000+1<<' '<<'\n';
    }
   	return 0;
}