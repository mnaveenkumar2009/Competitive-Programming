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
void prin(vector <vector <pair <ll,ll> > > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j].ss<<' ';
        pc('\n');
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
        f(i,n){
            f(j,n){
                a[i][j]=sc;
            }
        }
        set <ll> ans;
        ll mask=0;
        f(mask,1024){
            vector <vector <pair <ll,ll> > > anew(n,vector <pair<ll,ll> >(n));
            f(i,n){
                f(j,n){
                    anew[i][j].ff=(a[i][j]^mask);
                    anew[i][j].ss=a[i][j];
                }
            }
            // if(mask==0){
            //     prin(anew);
            // }
            sort(anew.begin(),anew.end());
            f(i,n){
                f(j,n){
                    if(i<j)
                    swap(anew[i][j],anew[j][i]);
                }
            }
            sort(anew.begin(),anew.end());
            // if(mask<=8){
            //     prin(anew);
            // }
            f(i,n){
                ll temp=0;
                f(j,n)
                    temp^=anew[(i+j)%n][j].ss;
                ans.insert(temp);
                temp=0;
                f(j,n)
                    temp^=anew[(i+j)%n][n-j-1].ss;
                ans.insert(temp);
                temp=0;
                f(j,n)
                    temp^=anew[n-((i+j)%n)-1][j].ss;
                ans.insert(temp);
                temp=0;
                f(j,n)
                    temp^=anew[j][(i+j)%n].ss;
                ans.insert(temp);
                temp=0;
                f(j,n)
                    temp^=anew[n-j-1][(i+j)%n].ss;
                ans.insert(temp);
                temp=0;
                f(j,n)
                    temp^=anew[j][n-((i+j)%n)-1].ss;
                ans.insert(temp);
            }            
        }

        for(auto it :ans)
            cout<<it<<' ';
        pc('\n');
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