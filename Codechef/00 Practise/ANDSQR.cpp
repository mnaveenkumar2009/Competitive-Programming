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

void prin1d(vector <ll> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin2d(vector <vector <ll> > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j]<<' ';
        pc('\n');
    }
    pc('\n');
}
void prin1d(vector < pair<pair<ll,ll>,ll> > a){
    ll i,j;
    f(i,a.size()){
        cout<<a[i].ff.ff<<' '<<a[i].ff.ss<<' '<<a[i].ss<<'\n';
    }
    pc('\n');
}
#define MAX 300009
ll n;
ll tree[MAX] = {0};  // To store segment tree
ll lazy[MAX] = {0};  // To store pending updates
void updateRange(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}

ll queryRange(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    ll mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}
#define modify(l,r,x) updateRange(1,0,n-1,l,r,x)
#define query(l,r) queryRange(1,0,n-1,l,r)
int main()
{
    ll ttt=uscan();
    while(ttt--){
        n=sc;
        ll q=sc,i,j,k;
        memset(lazy,0,sizeof(lazy));
        memset(tree,0,sizeof(tree));
        vector <ll> a(n);
        vector <ll> bits[32];
        f(i,n){
            a[i]=sc;
            f(j,32){
                if(!((1ll<<j)&a[i])){
                    bits[j].pb(i);
                }
            }
        }
        f(i,32)bits[i].pb(n);
        // cout<<"bits\n";
        // f(i,5){
        //     f(j,bits[i].size()){
        //         cout<<bits[i][j]<<' ';
        //     }pc('\n');
        // }
        vector <pair<ll,ll> > sq[n]; 
        f(i,n){
            vector <pair <ll,ll> > nums;
            vector <pair<ll,ll> > los(32,mp(-1,-1));
            f(j,32){
                if((a[i]&(1LL<<j))==0)
                    continue;
                los[j].ff=*lower_bound(bits[j].begin(),bits[j].end(),i);
                los[j].ss=j;
            }
            sort1(los);
            ll num=a[i];
            nums.pb(mp(num,i));
            // cout<<"los\n";
            // f(j,32)cout<<los[j].ff<<' '<<los[j].ss<<' ';pc('\n');
            f(j,32){
                if(los[j].ss==-1)continue;
                if(j!=31){
                    if(los[j].ff==los[j+1].ff){
                        num|=(1LL<<los[j].ss);
                        num^=(1LL<<los[j].ss);
                        continue;
                    }
                }
                num|=(1LL<<los[j].ss);
                num^=(1LL<<los[j].ss);
                ll r=los[j].ff;
                nums.pb(mp(num,r));
            }
            // cout<<i<<' '<<"nums\n";
            // f(j,nums.size()){
            //     cout<<nums[j].ff<<' '<<nums[j].ss<<'\n';
            // }pc('\n');
            
            
            // if(((ll)sqrt(a[i])*(ll)sqrt(a[i]))==a[i]){
            //     sq[i].pb(mp(i,i));
            // }
            f(j,nums.size()){
                ll xxx=nums[j].ff;
                if((ll)sqrt(xxx)*(ll)sqrt(xxx)==xxx){
                    if(nums[j].ss==n)
                        continue;
                    if(j==nums.size()-1)
                        sq[i].pb(mp(nums[j].ss,n-1));
                    else
                        sq[i].pb(mp(nums[j].ss,nums[j+1].ss-1));
                }
            }
            
        }
        // cout<<"ranges\n";
        // f(i,n){
        //     cout<<i<<' '<<"\n";
        //     f(j,sq[i].size())cout<<sq[i][j].ff<<' '<<sq[i][j].ss<<"  ";
        //     pc('\n');
        // }
        vector <pair<pair<ll,ll>,ll> > que(q);
        f(i,q){
            ll l=sc,r=sc;
            que[i].ff.ff=l;
            que[i].ff.ss=r;
            que[i].ss=i;
        }
        sort1(que);
        // cout<<"que\n";
        // prin1d(que);
        f(i,n){
            // update seg tree
            f(j,sq[i].size()){
                modify(sq[i][j].ff,sq[i][j].ss,1);
            }
        }
        // cout<<"tree\n";
        // f(i,n){
        //     cout<<query(i,i)<<' ';
        // }pc('\n');
        ll prevl=0,ii;
        ll ans[q];
        f(ii,q){
            ll l=que[ii].ff.ff-1;
            ll r=que[ii].ff.ss-1;
            for(i=prevl;i<l;i++){
                // un update seg tree
                f(j,sq[i].size()){
                    modify(sq[i][j].ff,sq[i][j].ss,-1);
                }
            }
            prevl=l;
            // cout<<query(l,r+1)<<'\n';
            ans[que[ii].ss]=query(l,r);
        }
        f(i,q){
            cout<<ans[i]<<'\n';
        }
    }
	return 0;
} 