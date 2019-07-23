#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        string s;
        cin>>s;
        int n=s.length();
        int dots=0,B=0;
        for(int i=0;i<n;i++){
            if(s[i]=='.')dots++;
            if(s[i]=='B')B++;
        }
        cout<<"Case #"<<k<<": ";
        if(dots>=1&&B>=n/2){
            cout<<"Y\n";
        }
        else{
            if(B>=2&&dots>=1){
                cout<<"Y\n";
            }
            else{
                cout<<"N\n";
            }
        }
    }
}