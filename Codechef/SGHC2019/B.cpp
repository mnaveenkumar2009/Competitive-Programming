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


const ll N = 2e6+2;
ll n;
vector <ll> tree[2 * N], sumtree[2 * N];

ll query(ll l, ll r, ll x) {
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            int pos = lower_bound(tree[l].begin(), tree[l].end(), x) - tree[l].begin();
            if(pos == tree[l].size())
                pos--;
            if(tree[l][pos] > x)
                pos--;
            if(pos >= 0){
                res += sumtree[l][pos];
            }
            l++;
        }
        if (r&1) {
            r--;
            int pos = lower_bound(tree[r].begin(), tree[r].end(), x) - tree[r].begin();
            if(pos == tree[r].size())
                pos--;
            if(tree[r][pos] > x)
                pos--;
            if(pos >= 0){
                res += sumtree[r][pos];
            }
        }
    }
    return res;
}
// tree[n+i] is a[i]
int main()
{
    n = sc;
    vl a(n),sum(n);
    f(i,n){
        a[i] = sc;
        sum[i] = a[i];
        if(i)
            sum[i] += sum[i-1];
        tree[n+i].pb(a[i]);
        int j = n+i;
        while(j = j/2)
            tree[j].pb(a[i]);
    }
    f(i,2*n){
        sort(tree[i]);
        sumtree[i] = tree[i];
        int nn = sumtree[i].size();
        f(j,nn-1)
            sumtree[i][j+1] += sumtree[i][j];        
    }
    ll q = sc;

    while(q--){
        ll l = sc-1, r = sc-1, y = sc;
        ll xxx = sum[r];
        if(l)
            xxx -= sum[l-1];
        if(y>xxx){
            cout<<-1<<'\n';
            continue;
        }
        ll low = 0, high = 1e9+4;
        while(low!=high){
            ll mid = (low+high)/2;
            ll temp = query(l, r + 1, mid);
            if(temp >= y){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        cout<<query(l, r + 1, low)<<'\n';
    }

	return 0;
}