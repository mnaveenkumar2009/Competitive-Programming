#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
typedef long long int ll;
typedef  double dd;
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,q1,i,j,v,v1,v2;
        cin>>n>>q1;
        char s[n];
        dd ask=sqrt(3);
        ask=ask/2;
        dd x[6]={1,.5,-.5,-1,-.5,.5};
        dd y[6]={0,ask,ask,0,-ask,-ask};
        scanf("%s",&s);
        dd p[n+1],q[n+1],value;
        p[0]=0; q[0]=0;
        for(i=0;i<n;i++){
            v=s[i]-'0';
            p[i+1]=p[i]+x[v];
            q[i+1]=q[i]+y[v];
        }
        for(i=0;i<q1;i++){
            cin>>v1>>v2;
           printf("%0.7lf ",abs(p[v2]-p[v1-1]));
            printf("%0.7lf",abs(q[v2]-q[v1-1]));
            cout<<endl;
        }
    }
}