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
#define sort(a) sort(a.begin(),a.end())
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
void prin(set <ll> a){
    for(auto it:a)cout<<it<<' ';pc('\n');
}
void prin(vector <vector <ll> > a){
    for(auto vec:a){for(auto it:vec)cout<<it<<' ';pc('\n');}pc('\n');
}
void prin(vector <pair <ll,ll> > a){
    for(auto it:a)cout<<it.ff<<' '<<it.ss<<'\n';pc('\n');
}
vvl a(100,vl (100,1));
ll n,m,i,j;
bool che(ll l, ll r,ll l2,ll r2){
    if(l2>=n||r2>=m||l2<0||r2<0)return 0;
    return (a[l][r]==a[l2][r2]);
}
ll num(ll l2,ll r2){
    if(l2>=n||r2>=m||l2<0||r2<0)return 0;
    return (a[l2][r2]);
}
int main()
{
    ll t=sc;
    while(t--){
        n=sc,m=sc,i,j;
        f(i,n){
            f(j,m){
                a[i][j]=0;
            }
        }
        int p1[4]={1,4,3,2},p2[4]={3,2,1,4};
        if(min(n,m)==2){
            if(max(n,m)==2)cout<<2<<'\n';
            else{
                cout<<3<<'\n';
            }
        }
        if(min(n,m)==1){
            if(max(n,m)>2){
                cout<<2<<'\n';
            }
            else{
                cout<<1<<'\n';
            }
        }
        if(min(n,m)>=3){
            cout<<4<<'\n';
            f(i,n){
                if((i>>1)&1){
                    f(j,m)
                        a[i][j]=p2[j&3];
                }
                else{
                    f(j,m)
                        a[i][j]=p1[j&3];
                }
            }
        }
        else{
            
            if(m==1&&n==2){
                cout<<"1\n1\n";
                continue;
            }
            if(m==1&&n==1){
                cout<<"1\n";
                continue;
            }
            if(m==2&&n==1){
                cout<<"1 1\n";
                continue;
            }
            if(m==1){
                f(i,n){
                    cout<< ((i/2)&1)+1<<'\n';
                }
                continue;
            }
            if(n==1){
                f(i,m){
                    cout<< ((i/2)&1)+1<<' ';
                }cout<<'\n';
                continue;
            }
            if(n==2){
                f(i,m){
                    if(i%3==0){
                        cout<<1<<' ';
                    }
                    if(i%3==1){
                        cout<<2<<' ';
                    }
                    if(i%3==2){
                        cout<<3<<' ';
                    }
                }
                cout<<'\n';
                f(i,m){
                    if(i%3==0){
                        cout<<1<<' ';
                    }
                    if(i%3==1){
                        cout<<2<<' ';
                    }
                    if(i%3==2){
                        cout<<3<<' ';
                    }
                }
                cout<<'\n';
                continue;
            }
            else{
                f(i,n){
                    if(i%3==0){
                        a[i][0]=a[i][1]=1;
                    }
                    if(i%3==1){
                        a[i][0]=a[i][1]=2;
                    }
                    if(i%3==2){
                        a[i][0]=a[i][1]=3;
                    }
                }
            }
        }
        f(i,n){
            f(j,m){
                cout<<a[i][j]<<' ';
            }pc('\n');
        }
        // ll yyy=101;
        // while(yyy--){
        //     bool we=1;
        //     f(i,n){
        //         f(j,m){
        //             set <ll> xxx;
        //             bool we2=1;
        //             if(che(i,j,i+1,j+1)){
        //                 we2=0;
        //             }
        //             xxx.insert(num(i+1,j+1));
        //             if(che(i,j,i-1,j-1)){
        //                 we2=0;
        //             }
        //             if(che(i,j,i+1,j-1)){
        //                 we2=0;
        //             }
        //             xxx.insert(num(i+1,j-1));
        //             xxx.insert(num(i-1,j-1));
        //             if(che(i,j,i-1,j+1)){
        //                 we2=0;
        //             }
        //             xxx.insert(num(i-1,j+1));
        //             if(che(i,j,i-2,j)){
        //                 we2=0;
        //             }
        //             xxx.insert(num(i-2,j));
        //             if(che(i,j,i+2,j)){
        //                 we2=0;
        //             }
        //             xxx.insert(num(i+2,j));

        //             if(che(i,j,i,j+2)){
        //                 we2=0;
        //             }
        //             xxx.insert(num(i,j+2));
        //             if(che(i,j,i,j-2)){
        //                 we2=0;
        //             }
        //             xxx.insert(num(i,j-2));
        //             ll k;
        //             // if(!we2)
        //             {
        //                 if(!yyy){prin(xxx);
        //                 cout<<i<<' '<<j<<' '<<a[i][j]<<'\n';}
        //                 f(k,4){
        //                     if(xxx.find(k+1)==xxx.end()){
        //                         a[i][j]=k+1;break;
        //                     }
        //                 }
        //                 if(k==4)a[i][j]++;
        //                 a[i][j]%=4;
        //                 if(a[i][j]==0)a[i][j]=4;
        //             }
        //             we&=we2;
        //             // for(auto it:xxx)cout<<it<<' ';pc('\n');
        //         }
        //     }
        //     if(we)break;
        // }
        // f(i,n){
        //     f(j,m){
        //         cout<<a[i][j]<<' ';
        //     }pc('\n');
        // }
    }
	return 0;
}