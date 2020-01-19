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
void prin(vector <vector <ll> > a){
    for(auto vec:a){for(auto it:vec)cout<<it<<' ';pc('\n');}pc('\n');
}
void prin(vector <pair <ll,ll> > a){
    for(auto it:a)cout<<it.ff<<' '<<it.ss<<'\n';pc('\n');
}
int main()
{
    ll n=sc,i,j,k,l;
    ll a[16]={8, 9, 1, 13, 3, 12, 7, 5, 0, 2, 4, 11, 6, 10, 15, 14};
    ll b[n][n];
    f(i,4){
        f(j,4){
            b[i][j] = a[i*4 + j];
        }
    }
    f(i,n/4){
        f(j,n/4){
            f(k,4){
                f(l,4){
                    b[i*4+k][j*4+l] = (i*(n/4) + j)*16 + b[k][l];
                }
            }
        }
    }
    f(i,n){
        ll aaa=0;
        f(j,n){
            aaa^=b[i][j];
        }
        // cout<<aaa<<'\n';
    }
    f(i,n){
        f(j,n){
            cout<<b[i][j]<<' ';
        }
        cout<<'\n';
    }
	return 0;
}