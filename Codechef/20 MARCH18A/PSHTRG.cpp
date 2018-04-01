#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define slld(n) scanf("%lld",&n)
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define gc getchar
#define pc putchar
inline unsigned long long uscan()
{
    unsigned long long n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
} 
 
inline  ll sscan()                     
{
ll n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0')
    {
n=n*10+c-'0';
c=gc();
    }
return n;
}
const ll N = 1e5;
ll n,q,logge=20; 
vector <ll> t[2 * N];//2*n*3

void build(){ 
  for (ll i = n - 1; i > 0; --i) {
      vector <ll> temp;
      ll j;
      f(j,logge){
          temp.pb(t[i<<1][j]);
          temp.pb(t[i<<1|1][j]);
      }
      sort(temp.begin(),temp.end());
      vector <ll> s;
      f(j,logge){
          s.pb(temp[logge+j]);
      }
      t[i]=s;
    }
}

void modify(ll p, ll value) {
    vector <ll> temp(logge);
    for(int i=0;i<logge;i++)
    temp[i]=-1;
    temp[logge-1]=value;
    for (t[p += n] = temp; p > 1; p >>= 1){
        vector <ll> temp2;
        ll j;
        f(j,logge){
            temp2.pb(t[p][j]);
            temp2.pb(t[p^1][j]);
        }
        sort(temp2.begin(),temp2.end());
        vector <ll> s;
        f(j,logge){
            s.pb(temp2[j+logge]);
        }
        t[p>>1] = s;
    }
}

ll query(ll l, ll r) {  // sum on llerval [l, r)
  ll res = 0;
  vector <ll> ans;
  ll i;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1){
        f(i,logge)
        ans.pb(t[l][i]);
        l++;
    } 
    if (r&1){
        --r;
        f(i,logge)
        ans.pb(t[r][i]);
    }
  }
sort(ans.begin(),ans.end());
  ll nn=ans.size();
  //f(i,nn)cout<<ans[i]<<" ";cout<<endl;
  f(i,nn-2){
      if(ans[nn-i-3]<=-1)break;
      if(ans[nn-i-1]<ans[nn-i-2]+ans[nn-i-3]){
          res=ans[nn-i-1]+ans[nn-i-2]+ans[nn-i-3];
          break;
      }
  }
  return res;
}


int main() {
    cin>>n>>q;
    vector <ll> temp(logge);
    

    ll i,j;
    f(i,logge){
        temp[i]=-1;
    }
    for(ll i=0;i<n;++i){
        temp[logge-1]=sscan();
        t[n+i]=temp;
    }
    build();
    /*
    f(i,2*n){
        cout<<i<<" ";
        if(i)
        f(j,3){
            cout<<t[i][j]<<" ";
        }cout<<endl;
    }
    */
    while(q--){
        if(sscan()==1){
            int l=sscan()-1,r=uscan();
            modify(l,r);
        }
        else{
            int l=sscan()-1,r=sscan();
            cout<<query(l,r)<<endl;
        }
    }
    return 0;
}
/*

5 4
3 1 8 9 7
2 1 5
1 2 12
2 1 3
2 2 5
*/