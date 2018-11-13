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

void prin(vector <ll> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(ll a[],ll n){
    ll i;
    f(i,n){
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
void prin(vector < pair<ll,ll> > a){
    ll i,j;
    f(i,a.size()){
        cout<<a[i].ff<<' '<<a[i].ss<<'\n';
    }
    pc('\n');
}
#define vl vector <ll> 
#define vvl vector <vector <ll> >
#define vpl vector <pair <ll,ll> >

ll nc2(ll n){
    return (n*(n-1))/2;
}

int main()
{
    ll tt=sc,kkk;

    f(kkk,tt){
        ll n=sc;
        ld p=sc,q=sc;
        vector <ld> a(n);
        ll i,j,k;
        f(i,n){
            a[i]=sc;
        }
        if(n<3){cout<<-1<<'\n';continue;}
        
        //sort1(a);
        multiset <ld> xxx;
        f(i,n){
            xxx.insert(a[i]);
        }
        ld ans=1e18,x1,y1,z1;
        f(i,n){
            for(j=i+1;j<n;j++){
                xxx.erase(xxx.find(a[i]));
                xxx.erase(xxx.find(a[j]));
                // for(auto it:xxx){
                //     cout<<it<<' ';
                // }cout<<'\n';
                ld a1=a[i],b1=a[j];
                ld temp=a1*a1+b1*b1;
                temp-=(2.0*a1*b1*p)/q;
                temp=sqrt(temp);
                multiset <ld>::iterator itlow=xxx.lower_bound(temp);
                if(itlow==xxx.end()){
                    itlow--;
                }
                if(*itlow>temp)
                {
                    if(itlow==xxx.begin()){

                        xxx.insert(a[i]);
                        xxx.insert(a[j]);
                        continue;
                    }
                    itlow--;
                }
                // cout<<"fa";
                ld c=*itlow;
                xxx.insert(a[i]);
                xxx.insert(a[j]);
                ld nans=a1*a1+b1*b1-c*c;
                nans/=2.0*a1*b1;
                if(abs(nans)>=1)continue;
                if(nans<(p/q))continue;
                // cout<<a1<<' '<<b1<<' '<<c<<'\n';
                // cout<<nans<<'\n';
                // cout<<p/q<<'\n';
                if(ans>nans){
                    ans=nans;
                    x1=a1;
                    y1=b1;
                    z1=c;
                }
            }
        }
        // cout<<x1<<' '<<y1<<' '<<z1<<'\n';
        f(i,n){
            if(a[i]==x1){
                x1=i+1;
                break;
            }
        }
        f(i,n){
            if(i+1==x1)continue;
            if(a[i]==y1){
                y1=i+1;
                break;
            }
        }
        f(i,n){
            if(i+1==x1)continue;
            if(i+1==y1)continue;
            if(a[i]==z1){
                z1=i+1;
                break;
            }
        }
        if(ans==1e18)
        cout<<-1<<'\n';
        else{
            cout<<z1<<' '<<y1<<' '<<x1<<'\n';
        }
    }

    return 0;
}