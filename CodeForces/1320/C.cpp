#include <bits/stdc++.h>
using namespace std;
#define int long long
 
#define N 1000005
int a[N];
long long tree[N<<2],lazy[N<<2];
 
void build(int node,int start,int end)
{
    if(start==end)
    {
        tree[node] = a[start];
    }
    else
    {
        int mid = (int)((start+end)/2);
        build(2*node+1,start,mid);
        build(2*node+2,mid+1,end);
        tree[node] = tree[2*node+1]>tree[2*node+2]?tree[2*node+1]:tree[2*node+2];
    }
}
 
void updateRange(int node,int start,int end,int l,int r,int val)
{
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(start!=end)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end || r < start || l > end) return;
    if(start>=l && end<=r)
    {
        tree[node] += val;
        if(start!=end)
        {
            lazy[2*node+1] += val;
            lazy[2*node+2] += val;
        }
        return;
    }
    int mid = (start+end)/2;
    updateRange(2*node+1,start,mid,l,r,val);
    updateRange(2*node+2,mid+1,end,l,r,val);
    tree[node] = tree[2*node+1]>tree[2*node+2]?tree[2*node+1]:tree[2*node+2];
}
 
int query(int node,int start,int end,int l,int r)
{
    if(start > end || r < start || l > end) return -1e13;
    if(lazy[node]!=0)
    {
        tree[node]+=lazy[node];
        if(start!=end)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(start>=l && end<=r)
    {
        return tree[node];
    }
    int mid = (start+end)/2;
    int p1 = query(2*node+1,start,mid,l,r);
    int p2 =query(2*node+2,mid+1,end,l,r);
    return p1>p2?p1:p2;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, p;
    int ans = -1e9;
    int A_m = -1e13, B_m = -1e13;
    cin >> n >> m >> p;
    pair <int, int> A[n], B[m];
    for(int i = 0; i < n; i++){
        cin >> A[i].first >> A[i].second;
        A_m = max(A_m, -A[i].second);
    }
    for(int i = 0; i < m; i++){
        cin >> B[i].first >> B[i].second;
        B_m = max(B_m, -B[i].second);
    }
    ans = A_m + B_m;
    sort(A, A + n);
    sort(B, B + m);

    for(int i = m - 2; i >= 0; i--){
        B[i].second = min(B[i].second, B[i+1].second);
    }
    for(int i = n - 2; i >= 0; i--){
        A[i].second = min(A[i].second, A[i+1].second);
    }
    for(int i = N - 1; i >= 0; i--){
        a[i] = 1e13;
    }
    for(int i = 0; i < n; i++){
        a[A[i].first - 1] = A[i].second;
    }
    for(int i = N - 2; i >= 0; i--){
        a[i] = min(a[i + 1], a[i]);
    }
    for(int i = 0; i < N; i++){
        a[i] = -a[i];
    }
    pair <pair <int, int> , int > Q[p];
    for(int i = 0; i < p; i++){
        cin >> Q[i].first.second >> Q[i].first.first >> Q[i].second;
    }
    sort(Q, Q + p);
    build(0, 0, N - 1);
    // for(int i = 0; i < 10; i++)cout << a[i] << ' '; 

    for(int i = 0; i < p; i++){
        int armor = Q[i].first.first;
        int pos = lower_bound(B, B + m, make_pair(armor, (int)1e10)) - B;
        if(pos == m)break;
        // cout << armor << ' ' << B[pos].first << '\n';
        int arm_cost = B[pos].second;
        updateRange(0, 0, N - 1, Q[i].first.second, N - 1, Q[i].second);
        // cout << arm_cost << '\n';
        ans = max(ans, query(0, 0, N - 1, 0, N - 1) - arm_cost);
        // cout <<  query(0, 0, N - 1, 0, N - 1) << '\n';
    }

    cout << ans << '\n';
}