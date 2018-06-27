#include <bits/stdc++.h>
using namespace std;

int main(){
    long long ans = 1,m,z;
    cin>>z>>m>>m;
    for ( long long i = z-1; i <= z+m-2;i++){
        ans = (ans*i)%1000000007;
    }
    cout<<ans;
}