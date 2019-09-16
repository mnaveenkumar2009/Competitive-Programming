#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
int k = 950;
pair <pair <int,int>,int> a[950];
int main() {

    #define ll long long
    ll n,m;
    cin>>n>>m>>k;
    // int b[k];
    f(i,k){
        cin>>a[i].ff.ff>>a[i].ff.ss;
        a[i].ss=i;
        // b[i] = a[i].ff;
    }

    // printAllSubsets(b, k, 59);
    pair <int,int> ans[k];
    f(i,k){
        ans[i]={-1,-1};
    }

    f(i,k){
        if(a[i].ff.ff==a[i].ff.ss&&a[i].ff.ff==1){
            a[i].ff.ss=-INT_MAX;
        }
        else
            a[i].ff.ss=-a[i].ff.ss;
    }
    sort(a,a+k);
    reverse(a,a+k);
    f(i,k){
        if(a[i].ff.ss==-INT_MAX){
            a[i].ff.ss=1;
        }
        else
            a[i].ff.ss=-a[i].ff.ss;
    }
    // random_shuffle(a,a+k);
    int check[350][350];
    f(i,350)f(j,350)check[i][j]=0;
    // cout<<a[0].ff.ff<<' '<<a[0].ff.ss<<'\n';
    f(tile,k){
        if(a[tile].ff.ff==1&&a[tile].ff.ss>1){
            cout<<"tile "<<tile+1<<' '<<a[tile].ff.ss<<'\n';
        } 
        //46
        f(i,350){
            if(ans[tile].ff!=-1)break;
            
            f(j,350){
                if(!check[i][j]){
                    if(i+a[tile].ff.ff-1>=350)continue;
                    if(j+a[tile].ff.ss-1>=350)continue;
                    bool we=1;
                    f(i2,a[tile].ff.ff){
                        f(j2,a[tile].ff.ss){
                            if(check[i+i2][j+j2]){
                                we = 0;
                                break;
                            }
                        }
                        if(!we)break;
                    }
                    if(we){
                        // if(i==0&&j==0)cout<<"f"<<tile<<'\n';
                        ans[tile] = {i,j};
                        f(i2,a[tile].ff.ff){
                            f(j2,a[tile].ff.ss){
                                check[i+i2][j+j2]=1+tile;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    int temmm =0 ;
    cout<<948<<'\n';
    f(i,k){
        if(ans[i].ff==-1){
            temmm++;
            cout<<a[i].ff.ff<<' '<<a[i].ff.ss<<' ';
            cout<<a[i].ss<<' '<<ans[i].ff<<' '<<ans[i].ss<<'\n';
        }
    }
    cout<<temmm<<'\n';

    cout<<'\n'<<'\n';
    f(i,n){
        f(j,m){
            printf("%3d ",check[i][j]);
        }
        cout<<'\n';
    }
    return 0;
}
