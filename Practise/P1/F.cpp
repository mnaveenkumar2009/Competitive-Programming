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
#include <bits/stdc++.h>
#define ll long long
const ll N = 2e6+2;
ll n;
ll tree[2 * N] = {0};

void modify(ll p, ll value) {  // set value at position p
    for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = max(tree[p], tree[p^1]);
}

ll query(ll l, ll r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res,tree[l++]);
        if (r&1) res = max(res,tree[--r]);
    }
    return res;
}

int main()
{
    n = sc;
    ll i,j,k;
    vl B(n),F(n), D(n);
    set <ll> Bs, Fs;
    unordered_map <ll, ll> Bm, Fm;
    set < pair<pair <ll,ll>, ll> > A;
    f(i,n){
        B[i]=sc;
        F[i]=sc;
        Bs.insert(B[i]);
        Fs.insert(F[i]);
        D[i]=sc;
    }
    int c = 0;
    for(auto it: Bs){
        Bm[it] = c++;
    }
    c = 0;
    for(auto it: Fs){
        Fm[it] = c++;
    }
    f(i,n){
        B[i] = Bm[B[i]];
        F[i] = Fm[F[i]];
        auto lb = A.lower_bound({{B[i],F[i]},-1});
        if(lb!=A.end()){
            if((*lb).first == mp(B[i],F[i])){
                D[i] += (*lb).second;
                A.erase(lb);
                A.insert({{B[i],F[i]},D[i]});
            }
            else{
                A.insert({{B[i],F[i]},D[i]});
            }
        }
        else{
            A.insert({{B[i],F[i]},D[i]});
        }
    }
    for(auto it: A){
        // cout<<it.ff.ff<<' '<<it.ff.ss<<' '<<it.ss<<'\n';
    }
    n = 1e6;
    vector <pair <ll,ll> > modifications;
    ll prevL = (*A.begin()).ff.ff;
    for(auto it:A){
        ll R = it.ff.ss;
        ll Val = it.ss;
        if(prevL != it.ff.ff){
            for(auto modifying : modifications){
                if(query(modifying.ff, modifying.ff+1) < modifying.ss){
                    // cout<<"in "<<modifying.ff<<' '<<modifying.ss<<'\n';
                    modify(modifying.ff, modifying.ss);
                }
            }
            // cout<<'\n';
            modifications.clear();
        }
        Val +=  query(0,R);
        // cout<<query(0,R)<<'\n';
        modifications.push_back({R, Val});
        prevL = it.ff.ff;
    }
    for(auto modifying : modifications){
        if(query(modifying.ff, modifying.ff+1) < modifying.ss){
                    // cout<<modifying.ff<<' '<<modifying.ss<<'\n';
            modify(modifying.ff, modifying.ss);
        }
    }
    modifications.clear();
    ll maxi = 0;
    f(i,n){
        maxi = max(maxi, query(i,i+1));
    }
    cout<<maxi<<'\n';
	return 0;
}