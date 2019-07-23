#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int c=1;
    cin>>s;
    while(cin>>s>>s){
        for(auto &i:s)
            i=152-i;
        cout<<"Case #"<<c++<<": "<<s<<'\n';
    }
}