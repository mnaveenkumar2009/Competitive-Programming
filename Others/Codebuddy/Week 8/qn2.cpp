#include <bits/stdc++.h>
using namespace std;

vector <bool> visited(26,0),isitthereinthewords(26,0);

vector <int> stak,adj[26];
void topodfs(int pos){
    visited[pos]=1;

    for(int i=0;i<adj[pos].size();i++)
        if(!visited[adj[pos][i]])
            topodfs(adj[pos][i]);
    stak.push_back(pos);
}

int main(){
    string s1,s2;
    int n1,n2;
    while(cin>>s2){//s1<s2
        n1=s1.length();
        n2=s2.length();
        for(int i=0;i<min(n1,n2);i++){
            if(s1[i]!=s2[i]){
                adj[s1[i]-'a'].push_back(s2[i]-'a');
                break;
            }
        }
        for(int i=0;i<n1;i++)
            isitthereinthewords[s1[i]-'a']=1;
        for(int i=0;i<n2;i++)
            isitthereinthewords[s2[i]-'a']=1;
        
        s1=s2;
    }
    for(int i=0; i<26;i++){
        if(!visited[i]){
            topodfs(i);
        }
    }
    for(int i=stak.size()-1;i>=0;i--){
        if(isitthereinthewords[stak[i]])
            cout<<(char)(stak[i]+'a')<<'\n';
    }
}