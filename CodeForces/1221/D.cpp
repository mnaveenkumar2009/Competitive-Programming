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
    ll q= sc;
    while(q--){
        ll n =sc;
        vl a(n), b(n);
        vl dp0(n,0), dp1(n,0), dp2(n,0); // uncha, change
        ll i,j,k;
        f(i,n){
            a[i]=sc;
            b[i]=sc;
        }
        dp0[0] = 0;
        dp1[0] = b[0];
        dp2[0] = 2*b[0];
        f(i,n){
            if(i){
                if(a[i] == a[i-1]){
                    dp0[i] = min(dp1[i-1], dp2[i-1]);
                }
                else{
                    dp0[i] = dp0[i-1];
                    if(a[i] != a[i-1] + 1){
                        dp0[i] = min(dp0[i], dp1[i-1]);
                    }
                    if(a[i] != a[i-1] + 2){
                        dp0[i] = min(dp0[i], dp2[i-1]);
                    }
                }
                if(a[i] + 1 == a[i-1]){
                    dp1[i] = b[i] + min(dp1[i-1], dp2[i-1]);
                }
                else{
                    dp1[i] = b[i] + dp0[i-1];
                    if(a[i] +1 != a[i-1] +1){
                        dp1[i] = min(dp1[i], b[i] + dp1[i-1]);
                    }
                    if(a[i] +1 != a[i-1] +2){
                        dp1[i] = min(dp1[i], b[i] + dp2[i-1]);
                    }
                }
                if(a[i] + 2 == a[i-1]){
                    dp2[i] = 2*b[i] + min(dp1[i-1], dp2[i-1]);
                }
                else{
                    dp2[i] = 2*b[i] + dp0[i-1];
                    if(a[i] +2 != a[i-1] +1){
                        dp2[i] = min(dp2[i], 2*b[i] + dp1[i-1]);
                    }
                    if(a[i] +2 != a[i-1] +2){
                        dp2[i] = min(dp2[i], 2*b[i] + dp2[i-1]);
                    }
                }
            }
        }
        // prin(a);
        // prin(b);
        // prin(dp0);
        // prin(dp1);
        cout << min(dp0[n-1], min(dp1[n-1], dp2[n-1])) << '\n';
    }
    
	return 0;
}