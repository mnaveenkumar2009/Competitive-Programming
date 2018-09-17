#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
// #define mod 1000000007
#define mod 998244353
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define sort1(a) sort(a.begin(),a.end())
#define sort2(a,n) sort(a,a+n)

inline ll uscan()
{
    ll n=0,c=gc();
    bool check=0;
    if(c=='-')check=1;
    while(c<'0'||c>'9')
    {
        c=gc();
        if(c=='-')check=1;
    }
    while(c<='9'&&c>='0'){
        n=n*10+c-'0';
        c=gc();
    }
    return n+(-2*check*n);
}
#define sc uscan()

void prin(vector <ll> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(vector <vector <ll> > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j]<<' ';
        pc('\n');
    }
    pc('\n');
}
void prin(vector < pair<ll,ll> > a){
    ll i,j;
    f(i,a.size()){
        cout<<a[i].ff<<' '<<a[i].ss<<'\n';
    }
    pc('\n');
}


int main()
{
    ll t=sc;
    while(t--){
        int n=sc;
        vector <vector <ll> >  a(n,vector <ll>(n));
        int i,j,k;
        bool we=1;
        f(i,n){
            f(j,n){
                a[i][j]=sc;
                if(a[i][j]>1)we=0;
            }
        }
        if(we){
            //only 1,0
            
            sort(a.begin(),a.end());
            f(i,n){
                f(j,n){
                    if(i<j)
                    swap(a[i][j],a[j][i]);
                }
            }
            sort(a.begin(),a.end());
            // prin(a);
            set <ll> ans;
            f(i,n){

                ll temp=0;
                f(j,n)
                    temp^=a[(i+j)%n][j];
                ans.insert(temp);
            }
            for(auto it :ans)
                cout<<it<<' ';
            pc('\n');
            continue;
        }
        if(n<8){
            set <ll> ans;
            vector <ll> b(n);
            f(i,n)
                b[i]=i;
            
            do{
                ll xxx=0;
                f(i,n)
                    xxx^=a[b[i]][i];
                ans.insert(xxx);     
            }while(next_permutation(b.begin(),b.end()));
            
            for(auto it:ans){
                cout<<it<<' ';
            }
            pc('\n');
            continue;
        }
        if(n<=14){
            bool pos[1<<n][1024];
            bool pos2[1<<n][1024];
            f(i,1<<n){
                f(j,1024){
                    pos[i][j]=pos2[i][j]=0;
                }
            }
            f(i,1<<n){
                if(__builtin_popcount(i)==7){
                    vector <ll> b;//size 7
                    f(j,n){
                        if((1<<j)&i){
                            b.pb(j);
                        }
                    }
                    do{
                        ll xxx=0;
                        // if(i==191&&b[0]==0&&b[1]==1&&b[2]==2){
                        //     f(j,b.size()){
                        //         cout<<b[j]<<' '; 
                        //     }pc('\n');
                        // }
                        f(j,7){
                            xxx^=a[b[j]][j];
                        }
                        pos[i][xxx]=1;
                    }
                    while(next_permutation(b.begin(),b.end()));
                }
            }
            vector <ll> posi[1<<n];
            f(i,1<<n){
                if(__builtin_popcount(i)==7){
                    f(j,1024){
                        if(pos[i][j]){
                            posi[i].pb(j);
                        }
                    }
                }
            }
            // f(i,1<<n){
            //     if(__builtin_popcount(i)==7){
            //         if(posi[i].size()){
            //             cout<<i<<' ';
            //             f(j,posi[i].size())
            //                 cout<<posi[i][j]<<' ';
            //             cout<<'\n';
            //         }
            //     }
            // }
            f(i,1<<n){
                if(__builtin_popcount(i)==7){
                    vector <ll> b;
                    // cout<<i<<'\n';
                    f(j,n){
                        if(((1<<j)&i)==0){
                            b.pb(j);
                        }
                    }
                    // f(j,b.size()){
                    //     cout<<b[j]<<' '; 
                    // }pc('\n');
                    sort(b.begin(),b.end());
                    do{
                        ll xxx=0;
                        f(j,b.size())
                            xxx^=a[b[j]][j+7];   
                        pos2[i][xxx]=1;   
                        // cout<<xxx<<' '<<i<<'\n';              
                    }
                    while(next_permutation(b.begin(),b.end()));
                }
            }
            set <ll> ans;

            for(int x=0;x<1024;x++){
                ans.insert(x);
            }
            f(i,1<<n){
                if(__builtin_popcount(i)==7){
                    for(auto it:posi[i]){
                        for(auto it2:ans){
                            if(pos2[i][it^it2]){
                                ans.erase(it2);
                            }
                        }
                    }
                }
            }
            for(int x=0;x<1024;x++){
                if(ans.find(x)==ans.end()){
                    cout<<x<<' ';
                }
            }
            pc('\n');
        }
        else{
            ll mask=0;
            f(mask,1024){
                vector <vector <pair <ll,ll> > > anew(n,vector <pair<ll,ll> >(n));
                f(i,n){
                    f(j,n){
                        anew[i][j].ff=a[i][j]&mask;
                        anew[i][j].ss=a[i][j];
                    }
                }
                sort(anew.begin(),anew.end());
                f(i,n){
                    f(j,n){
                        if(i<j)
                        swap(anew[i][j],anew[j][i]);
                    }
                }
                sort(a.begin(),a.end());
                // prin(a);
                set <ll> ans;
                f(i,n){

                    ll temp=0;
                    f(j,n)
                        temp^=a[(i+j)%n][j];
                    ans.insert(temp);
                }
                for(auto it :ans)
                    cout<<it<<' ';
                pc('\n');
                continue;
            }
        }
    }
    return 0;
} 

/*

8
8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1
1 1 1 1 1 1 1 1
2 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 2 3 4 5 6 7 8

*/