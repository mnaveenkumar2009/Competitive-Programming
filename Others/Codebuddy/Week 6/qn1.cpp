// O(n)
#include <bits/stdc++.h>

using namespace std;
int value(char c){
    switch(toupper(c)){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return -1;
}
int solve(string s){
    int n=s.length(),ans=0;
    for(int i=0;i<n-1;i++){
        ans+=(2*(value(s[i])>=value(s[i+1]))-1)*value(s[i]);
    }
    ans+=value(s[n-1]);
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<solve(s)<<'\n';
    }
}


/*
    7
    VI
    6
    VII
    7
    VIII
    8
    IX
    9
    MDC
    1600
    MCD
    1400
    MCDL
    1450
*/