#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(long long i = 0; i < n;i++)
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        long long a[n];
        f(i,n){
            cin>>a[i];
        }
        sort(a,a+n);
        long long coun = 0,coun2 = 0;  
        for(long long i = 0;i < n ;i++){
            if(a[i] == a[k-1]){
                coun++;
                if(i<=k-1)
                    coun2++;
            }
        }
        // counCcoun2;
        cout<<binomialCoeff(coun,coun2)<<'\n';
    }
}