#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
int k = 714;
pair <pair <int,int>,int> a[714];
bool comp(pair <pair <int,int>,int> x, pair <pair <int,int>,int> y){
    return (x.ff.ff*x.ff.ss)>(y.ff.ff*y.ff.ss);
}
int main() {

    #define ll long long
    ll n,m;
    cin>>n>>m>>k;
    n/=1000;
    m/=1000;
    
    f(i,k){
        cin>>a[i].ff.ff>>a[i].ff.ss;
        a[i].ff.ff/=1000;
        a[i].ff.ss/=1000;
        a[i].ss=i;
        // b[i] = a[i].ff;
    }

    pair <int,int> ans[k];
    f(i,k){
        ans[i]={-1,-1};
    }

    // f(i,k)a[i].ff.ss=-a[i].ff.ss;
    sort(a,a+k,comp);
    // reverse(a,a+k);
    // f(i,k)a[i].ff.ss=-a[i].ff.ss;
    // f(i,k){
    //     if(a[i].ss==39){
    //         swap(a[0],a[i]);
    //         break;
    //     }
    // }
    // f(i,10)
    //     cout<<a[i].ff.ff<<' '<<a[i].ff.ss<<' '<<a[i].ss<<'\n';
    
    int check[500][500];
    f(i,500)f(j,500)check[i][j]=0;
    // cout<<a[0].ff.ff<<' '<<a[0].ff.ss<<'\n';
    f(tile,k){
        if(a[tile].ff.ff==73&&a[tile].ff.ss== 1){
            // cout<<"tile "<<tile<<'\n';
            //118
        }
        f(j,500){
            if(ans[tile].ff!=-1)break;
            f(i,500){
                if(!check[i][j]){
                    if(i+a[tile].ff.ff-1>=500)continue;
                    if(j+a[tile].ff.ss-1>=500)continue;
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
    int temmm =0;
    cout<<713<<'\n';
    f(i,k){
        if(ans[i].ff!=-1){
            temmm++;
            // cout<<a[i].ff.ff<<' '<<a[i].ff.ss<<' ';
            // cout<<a[i].ss<<' '<<ans[i].ff*1000<<' '<<ans[i].ss*1000<<'\n';
            // if(temmm==5)break;
        }
        else{
            cout<<a[i].ff.ff<<' '<<a[i].ff.ss<<' ';
            cout<<a[i].ss<<'\n';
        }
    }
    cout<<temmm<<'\n';
    cout<<'\n'<<'\n';
    f(i,500){
        f(j,500){
            printf("%3d ",check[i][j]);
        }
        cout<<'\n';
    }
    return 0;
}
