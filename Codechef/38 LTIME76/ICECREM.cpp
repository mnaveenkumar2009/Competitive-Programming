#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
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
    #define int long long
    ll t=sc;
    while(t--){
        ll n = sc;
        vl w(n), p(n), v(n);
        f(i,n){
            w[i]=sc;
            p[i]=sc;
            v[i]=sc;
        }
        int n1 = n/2, n2 = n - n1;
        ll ans = 0;
        vector <pair <ll, ll> > search_vec;
        f(mask1, 1 << n1){
            ll wait_time = 0;
            ll value = 0;
            bool possible = 1;
            f(j, n1){
                if(mask1 & (1<<j)){
                    if(wait_time > w[j]){
                        possible = 0;
                        break;
                    }
                    value += v[j];
                    wait_time += p[j];
                }
            }
            if(possible){
                search_vec.push_back({wait_time, value});
            }
        }
        sort(search_vec);
        vector <ll> maxi(search_vec.size());
        maxi[0] = search_vec[0].ss;
        f(i, search_vec.size()){
            if(i)
                maxi[i] = max(maxi[i-1], search_vec[i].ss);
        }   
        f(mask2, 1<<n2){
            int wait_time = 0;
            ll value = 0, tolerance = 1e15;
            bool possible = 1;
            f(j, n2){
                if(mask2 & (1<<j)){
                    if(wait_time > w[n1 + j]){
                        possible = 0;
                        break;
                    }
                    tolerance = min(tolerance, w[n1 + j] - wait_time);
                    value += v[n1 + j];
                    wait_time += p[n1 + j];
                }
            }
            if(possible){
                int posi = upper_bound(search_vec.begin(), search_vec.end(), mp((ll)tolerance, (ll)1e15)) - search_vec.begin();
                if(posi == search_vec.size())
                    posi--;
                if(search_vec[posi].ff > tolerance){
                    posi--;
                }
                if(posi >= 0)
                    ans = max(ans, value + maxi[posi]);
                else
                    ans = max(ans, value);
            }
        }
        cout << ans <<'\n';
    }
	return 0;
}