#include <bits/stdc++.h>
using namespace std;
long long a[3],b[3];
#define m(a) max(max(a[0],a[1]),a[2])
int main(){
    cin>>a[0];
    while(cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2])
        cout<<(((abs(a[0]-b[0])%2+abs(a[1]-b[1])%2+abs(a[2]-b[2])%2)%3!=0)^(m(a)==0)^(m(b)==0)) + ((m(a)==0)^(m(b)==0))<<'\n';
}