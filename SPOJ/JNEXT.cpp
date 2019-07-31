#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int i;
        for(i=n-1;i>=1;i--){
            if(a[i]>a[i-1]){
                for(int j=n-1;j>=i;j--){
                    if(a[j]>a[i-1]){
                        swap(a[i-1],a[j]);
                        break;
                    }
                }
                reverse(a+i,a+n);
                break;
            }
        }
        if(i==0){cout<<-1<<'\n';continue;}
        for( i=0;i<n;i++)
            cout<<a[i];
        cout<<'\n';
    }
}