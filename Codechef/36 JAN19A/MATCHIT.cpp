#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
// #define sort(a) sort(a.begin(),a.end())
#define sortn(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
inline ll uscan(){
    ll n=0,c=gc();bool check=0;
    while(c<'0'||c>'9'){if(c=='-')check=1;c=gc();}
    while(c<='9'&&c>='0'){n=n*10+c-'0';c=gc();}
    return check?-n:n;
}
#define sc uscan()
void prin(vector <ll> a){
    for(auto it:a)cout<<it<<' ';pc('\n');
}
void prin(vector <vector <ll> > a){
    for(auto vec:a){cout<<vec.size()/2<<' ';for(auto it:vec)cout<<it<<' ';pc('\n');}//pc('\n');
}
void prin(vector <pair <ll,ll> > a){
    for(auto it:a)cout<<it.ff<<' '<<it.ss<<'\n';pc('\n');
}
vvl a(2000,vl(2000,0));
// bool onc=1;
ll score(vvl prr){
    ll i,ret=0;
    for(auto it:prr){
        f(i,it.size()/2){
            // if(onc)
            // cout<<it[i<<1]<<' '<<it[(i<<1)|1]<<'\n';
            ret+=a[it[i<<1]-1][it[(i<<1)|1]-1];
        }
    }
    // onc=0;
    return ret;
}
int main()
{
    ll n=sc,m=sc,i,j;
    vvl b(n,vl(n,0));
    f(i,2*m){
        ll x=sc-1,y=sc-1;
        b[x][y]=1;
    }
    f(i,n){
        f(j,n){
            a[i][j]=sc;
        }
    }
    bool printing=0;
    // prin(b);
    vector <pair <ll,vvl> > ans;
    vvl prr;
    vl pr;
    f(i,n){
        if(i%2==0){
            f(j,n){
                // cout<<i<<' '<<j<<' '<<printing<<'\n';
                if(b[i][j]){
                    printing=!printing;
                    if(!printing){
                        pr.pb(i+1);
                        pr.pb(j+1);
                        prr.pb(pr);
                        pr.erase(pr.begin(),pr.end());
                    }
                }
                if(printing){
                    
                    pr.pb(i+1);
                    pr.pb(j+1);
                }

            }
        }
        else{
            for(j=n-1;j>=0;j--){
                // cout<<i<<' '<<j<<' '<<printing<<'\n';
                if(b[i][j]){
                    printing=!printing;
                    if(!printing){
                        pr.pb(i+1);
                        pr.pb(j+1);
                        prr.pb(pr);
                        pr.erase(pr.begin(),pr.end());
                    }
                }
                if(printing){
                    pr.pb(i+1);
                    pr.pb(j+1);
                }

            }
        }
    }
    ans.pb(mp(score(prr),prr));
    prr.erase(prr.begin(),prr.end());
    pr.erase(pr.begin(),pr.end());
    f(i,n){
        if(i%2){
            f(j,n){
                // cout<<i<<' '<<j<<' '<<printing<<'\n';
                if(b[i][j]){
                    printing=!printing;
                    if(!printing){
                        pr.pb(i+1);
                        pr.pb(j+1);
                        prr.pb(pr);
                        pr.erase(pr.begin(),pr.end());
                    }
                }
                if(printing){
                    // cout<<i+1<<' '<<j+1<<' ';
                    pr.pb(i+1);
                    pr.pb(j+1);
                }

            }
        }
        else{
            for(j=n-1;j>=0;j--){
                // cout<<i<<' '<<j<<' '<<printing<<'\n';
                if(b[i][j]){
                    printing=!printing;
                    if(!printing){
                        pr.pb(i+1);
                        pr.pb(j+1);
                        prr.pb(pr);
                        pr.erase(pr.begin(),pr.end());
                    }
                }
                if(printing){
                    pr.pb(i+1);
                    pr.pb(j+1);
                }

            }
        }
    }
    ans.pb(mp(score(prr),prr));
    prr.erase(prr.begin(),prr.end());
    pr.erase(pr.begin(),pr.end());


    f(j,n){
        if(j%2){
            f(i,n){
                // cout<<i<<' '<<j<<' '<<printing<<'\n';
                if(b[i][j]){
                    printing=!printing;
                    if(!printing){
                        pr.pb(i+1);
                        pr.pb(j+1);
                        prr.pb(pr);
                        pr.erase(pr.begin(),pr.end());
                    }
                }
                if(printing){
                    // cout<<i+1<<' '<<j+1<<' ';
                    pr.pb(i+1);
                    pr.pb(j+1);
                }

            }
        }
        else{
            for(i=n-1;i>=0;i--){
                // cout<<i<<' '<<j<<' '<<printing<<'\n';
                if(b[i][j]){
                    printing=!printing;
                    if(!printing){
                        pr.pb(i+1);
                        pr.pb(j+1);
                        prr.pb(pr);
                        pr.erase(pr.begin(),pr.end());
                    }
                }
                if(printing){
                    pr.pb(i+1);
                    pr.pb(j+1);
                }

            }
        }
    }
    ans.pb(mp(score(prr),prr));
    prr.erase(prr.begin(),prr.end());
    pr.erase(pr.begin(),pr.end());

    f(j,n){
        if(j%2==0){
            f(i,n){
                // cout<<i<<' '<<j<<' '<<printing<<'\n';
                if(b[i][j]){
                    printing=!printing;
                    if(!printing){
                        pr.pb(i+1);
                        pr.pb(j+1);
                        prr.pb(pr);
                        pr.erase(pr.begin(),pr.end());
                    }
                }
                if(printing){
                    // cout<<i+1<<' '<<j+1<<' ';
                    pr.pb(i+1);
                    pr.pb(j+1);
                }

            }
        }
        else{
            for(i=n-1;i>=0;i--){
                // cout<<i<<' '<<j<<' '<<printing<<'\n';
                if(b[i][j]){
                    printing=!printing;
                    if(!printing){
                        pr.pb(i+1);
                        pr.pb(j+1);
                        prr.pb(pr);
                        pr.erase(pr.begin(),pr.end());
                    }
                }
                if(printing){
                    pr.pb(i+1);
                    pr.pb(j+1);
                }

            }
        }
    }
    ans.pb(mp(score(prr),prr));
    prr.erase(prr.begin(),prr.end());
    pr.erase(pr.begin(),pr.end());

    sort(ans.rbegin(),ans.rend());
    // cout<<ans[0].ff<<' '<<ans[1].ff<<'\n';
    // cout<<ans[0].ff<<' '<<ans[1].ff<<'\n';
    prin(ans[0].ss);
	return 0;
}