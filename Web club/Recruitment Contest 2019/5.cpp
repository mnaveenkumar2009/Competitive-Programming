#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
long long summ(vector <long long> a){
    long long ret=0;
    for(auto it:a){
        ret+=it;
    }
    return ret;
}
int main() {

    #define int long long
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    pair <int,int> a[k];
    vector <int> row,col;
    int xxx[1000][2],yyy[1000][2];
    f(i,1000){
        f(j,2)xxx[i][j]=yyy[i][j]=-1;
    }
    f(i,k){
        cin>>a[i].ff>>a[i].ss;
        if(a[i].ss==a[i].ff){
            if(xxx[a[i].ss][0]==-1){
                xxx[a[i].ss][0] = i;
            }
            else{
                if(xxx[a[i].ss][1]==-1){
                    xxx[a[i].ss][1]=i;
                }
                else{
                    if(yyy[a[i].ff][0]==-1){
                        yyy[a[i].ff][0]=i;
                    }
                    else{
                        yyy[a[i].ff][1]=i;
                    }
                }
            }
        }
        else
            if(a[i].ff==1){
                // row.push_back(a[i].ss);
                if(xxx[a[i].ss][0]==-1){
                    xxx[a[i].ss][0] = i;
                }
                else{
                    xxx[a[i].ss][1] = i;
                }
            }
            else{
                // col.push_back(a[i].ff);
                if(yyy[a[i].ff][0]==-1){
                    yyy[a[i].ff][0] = i;
                }
                else{
                    yyy[a[i].ff][1] = i;
                }
            }
    }
    // sort(col.begin(),col.end());
    // sort(row.begin(),row.end());
    // for(auto it:row)cout<<it<<' ';cout<<'\n';
    // for(auto it:col)cout<<it<<' ';cout<<'\n';
    cout<<k<<'\n';
    int xyz = 499;
    while(xyz>=1){
        int i = (499-xyz)/2;
        cout<<xxx[xyz][0]<<' '<<i<<' '<<i<<'\n';
        cout<<xxx[xyz][1]<<' '<<i+xyz<<' '<<i+1<<'\n';
        cout<<yyy[xyz][0]<<' '<<i+1<<' '<<i<<'\n';
        cout<<yyy[xyz][1]<<' '<<i<<' '<<i+xyz<<'\n';
        xyz-=2;
    }

    return 0;
}
