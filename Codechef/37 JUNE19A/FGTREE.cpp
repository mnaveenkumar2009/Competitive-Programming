#include <bits/stdc++.h>
using namespace std;

int par[104],minileft[104],cftro[104],maxi,n,buffer;
bool done[104];

bool check(int x,int a,int b){
    if(x<0)return 0;
    cout<<"Q "<<x+1<<' '<<a+1<<' '<<b+1<<endl;
    string s;
    cin>>s;
    return s=="Yes";
}

void gotopright(int minnode,int curnode,int left_par){
    if(curnode>=n)return;
    maxi=max(maxi,curnode);
    
    if(done[curnode]){
        if(check(left_par,minileft[left_par],maxi))
            gotopright(minileft[left_par],par[curnode]=left_par,cftro[left_par]);
        else
            gotopright(minileft[curnode],par[curnode]=maxi+1,left_par);
        return;
    }
    done[curnode]=1;
    minileft[curnode]=minnode;
    cftro[curnode]=left_par;
    if(check(curnode,minnode,curnode))
        if(check(left_par,minileft[left_par],curnode))
            gotopright(minileft[left_par],par[curnode]=left_par,cftro[left_par]);
        else
            gotopright(minnode,par[curnode]=curnode+1,left_par);
    else
        if(check(left_par,minileft[left_par],curnode-1)){
            done[curnode]=0;
            maxi--;
            gotopright(minileft[left_par],par[curnode-1]=left_par,cftro[left_par]);
        }
        else
            gotopright(curnode+1,curnode+1,curnode);        
}
int main(){
    int t;
    cin>>t;
    while(t--){
        maxi=0;
        cin>>n;
        memset(done,0,104);
        gotopright(0,0,-1);
        cout<<"A ";
        for(int i=0;i<n;i++)
            cout<<(par[i]<n?(par[i]+1):-1)<<' ';
        cout<<endl;
    }
    return 0;
}