#include <bits/stdc++.h>
using namespace std;
#define MAX 1e6
#define ll long long
ll dist[55][55],init[55][55],n;
bool floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                {
                    if((dist[i][k] + dist[k][j])<dist[i][j]&&init[i][j]!=MAX){
                        // cout<<i<<' '<<j<<' '<<k<<'\n';
                        return 0;
                    }
                }
                    dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
            }
        }
    }
    // for(int k = 0; k < n; k++){
    //     for(int i = 0; i < n; i++){
    //         cout<<dist[k][i]<<' ';
    //     }
    //     cout<<'\n';
    // }
    return 1;
}
int main(){
    int t,kkk=1;
    cin>>t;
    while(t--){
        int m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=init[i][j]=1e6;
            }
        }
        while(m--){
            int x,y,z;
            cin>>x>>y>>z;
            x--;y--;
            init[y][x]=dist[y][x]=z;
            init[x][y]=dist[x][y]=z;
        }
        cout<<"Case #"<<kkk++<<": ";
        if(floyd()){
            cout<<(n*(n-1))/2<<'\n';
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i<j){
                        cout<<i+1<<' ' <<j+1<<' '<<dist[i][j]<<'\n';
                    }
                }
            }
        }
        else{
            cout<<"Impossible\n";
        }
    }

}