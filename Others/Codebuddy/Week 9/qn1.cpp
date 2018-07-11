#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <string> path;
string s;
void split(){
    ll i=0;
    string g;
    while(i!=s.length()){
        if(s[i]=='/'){
            //split
            path.push_back(g);
            g="";
        }
        else{
            g.push_back(s[i]);
        }
        i++;
    }
    if(g.length())
        path.push_back(g);
}
int main()
{
    ll i;
    cin>>s;
    split();
    vector <string> dir;
    for(i=0;i<path.size();i++){
        if(path[i].size()==0||path[i]==".")
            continue;
        if(path[i]==".."){
            if(dir.size())
                dir.pop_back();
        }
        else{
            dir.push_back(path[i]);
        }
    }

    if(!dir.size())
        cout<<'/';
    for(i=0;i<dir.size();i++)
        cout<<'/'<<dir[i];

	return 0;
}