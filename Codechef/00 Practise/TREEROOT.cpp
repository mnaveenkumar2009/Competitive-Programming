#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        int ans=0;
        while(n--){
            cin>>x;
            ans+=x;
            cin>>x;
            ans-=x;
        }
        cout<<ans<<'\n';
    }
}