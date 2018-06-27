#include <bits/stdc++.h>
using namespace std;
bool isv(char c){
    c=toupper(c);
    return ((c-'A')*(c-'E')*(c-'I')*(c-'O')*(c-'U'))==0;
}
int main(){
    string s;
    int ans=0;
    while(cin>>s){
        int v=0;
        ans+=3;
        for(int i=0;i<s.length();i++){
            if(isv(s[i]))
                v++;
            
            if(i>2)
                if(!isv(s[i-3])&&!isv(s[i-2])&&!isv(s[i-1])&&!isv(s[i])){
                    v=0;
                    break;
                }
        }
        if( (2*v) < s.length() ){
            ans+=2;
        }
    }
    cout<<ans;
}