#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define f(i,n) for(i=0;i<n;i++)
#define ll long long

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ordered_set X;

int main()
{
    ll n;
    cin>>n;
    vector <ll> p(n),q(n);
    ll i,j,k;
    f(i,n)cin>>p[i];
    f(i,n){
        q[p[i]]=i;
    }
    ll x,y;
    cin>>x>>y;
    ll a=0,b=1,m=0;
    X.insert(q[m++]);
    X.insert(q[m++]);
    ll cur_siz=2;
    while(cur_siz!=n){
        //before delete
        ll del1=((cur_siz+2)*x)/(2*y),del2=(((cur_siz+2)*x)/(2*y))+(cur_siz+2)/2;
        if(del1<=a)a++;
        if(del2<=a)a++;
        if(del1<=b)b++;
        if(del2<=b)b++;
        // before permute
        X.insert(q[m++]);
        X.insert(q[m++]);
        a=p[*(X.find_by_order(a))];
        b=p[*(X.find_by_order(b))];
        cur_siz+=2;
    }
    cout<<a<<' '<<b;
    return 0;
}