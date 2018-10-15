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
#define vl vector <ll> 
#define vvl vector <vector <ll> >
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
ll ds(ll n){
    ll ans=0;
    while(n!=0){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
vvl sum(300, vl (300,0));
ll get_sum(ll l1,ll r1, ll l2, ll r2){
    ll ret=0;
    ret=sum[l2][r2];
    // cout<<ret<<' ';
    if(l1-1>=0){
        ret-=sum[l1-1][r2];
    }
    if(r1-1>=0){
        ret-=sum[l2][r1-1];
    }
    if((l1-1)>=0&&(r1-1)>=0)
        ret+=sum[l1-1][r1-1];
    return ret;
}
int main()
{
    ll n=sc,m=sc,i,j,k;
    vvl a(n,vl(m,0));
    f(i,n){
        string s;
        cin>>s;
        f(j,m){
            a[i][j]=s[j]-'0';
        }
    }
    // prin(a);
    ll q=sc;
    vl quer(q);
    f(i,q)quer[i]=sc;
    vl ans(n);
    f(i,n){
        f(j,m){
            // 0 bottom left
            if((i+j)&1){
                sum[i][j]=(a[i][j]!=1);
            }
            else{
                sum[i][j]=(a[i][j]!=0);
            }            
        }
    }
    f(i,n){
        f(j,m){
            if(i-1>=0){
                sum[i][j]+=sum[i-1][j];
            }
            if(j-1>=0){
                sum[i][j]+=sum[i][j-1];
            }
            if((i-1>=0)&&(j-1>=0)){
                sum[i][j]-=sum[i-1][j-1];
            }
        }
    }
    // cout<<"sum\n";
    // prin(sum);

    ll temp;
    f(temp,n){
        ll anss=INT_MAX;
        // temp*temp
        ll siz=temp+1;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                // i,j to i+siz-1,j+siz-1
                if(i+siz-1>=n||j+siz-1>=n)break;
                ll xwq=get_sum(i,j,i+siz-1,j+siz-1);
                // cout<<xwq<<' ';
                anss=min(min(xwq,siz*siz-xwq),anss);
            }
        }
        // cout<<'\n';
        ans[temp]=anss;
    }
    // prin(ans);
    f(i,q){
        f(j,n){
            if(ans[n-j-1]<=quer[i])break;
        }
        cout<<n-j<<'\n';
    }
    return 0;
}