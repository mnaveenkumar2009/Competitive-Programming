#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 3000000007
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
    vector <ll> p;
    vector <bool > isp(3000000,1);
    isp[0]=isp[1]=0;
    for(int i=2;i<3000000;i++){
        if(isp[i]){
            for(int j=2;i*j<3000000;j++){
                isp[i*j]=0;
            }
        }
    }
    for(int i=0;i<3000000;i++){
        if(isp[i])p.pb(i);
    }
    ll t=sc;
    while(t--){
        ll n=sc,i;
        vl a(n+1,1);
        // for(int i=0;i<n;i++){
        //     a[i]*=p[i];
        // }
        // for(int i=0;i<n;i++){
        //     a[i]*=p[(i+1)%n];
        // }
        f(i,n+1){
            if(i*2>n+1)break;
            a[i*2]=i+2;
        }
        unordered_map <ll,bool>xxx;
        if(a[n-1]!=1)xxx[2*a[n-1]]=1;
        f(i,n){
            if(a[i]==1){
                // a[i]=a[i-1]+a[i+1];
                ll j;
                f(j,10000){
                    if(__gcd(2*j+3,a[i-1])==1&&__gcd(2*j+3,a[(i+1)%n])==1){
                        if(__gcd(2*j+3,a[i-2])==1&&!xxx[a[(i+1)%n]*(2*j+3)]&&!xxx[a[i-1]*(2*j+3)]){
                            if(((i+2)%n)<i){
                                if(__gcd(2*j+3,a[(i+2)%n])==1)
                                    break;
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
                a[i]=2*j+3;
            }
            if(i)
            xxx[a[i]*a[i-1]]=1;
        }
            if(__gcd(a[0],a[n-1])!=1||__gcd(a[0],a[n-2])!=1){
                // a[i]=a[i-1]+a[i+1];
                ll j;
                f(j,10000){
                    if(__gcd(j+6,a[n-1])==1&&__gcd(j+6,a[1])==1){
                        if(__gcd(j+6,a[n-2])==1&&!xxx[a[1]*(j+6)]&&!xxx[a[n-1]*(j+6)]){
                            if(2){
                                if(__gcd(j+6,a[2])==1)
                                    break;
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
                a[0]=j+6;
            }
            if(__gcd(a[1],a[n-1])!=1){
                // a[i]=a[i-1]+a[i+1];
                ll j;
                f(j,10000){
                    if(__gcd(j+6,a[n-1])==1&&__gcd(j+6,a[2])==1){
                        if(__gcd(j+6,a[0])==1&&!xxx[a[2]*(j+6)]&&!xxx[a[0]*(j+6)]&&__gcd(j+6,a[3])==1){
                            break;
                        }
                    }
                }
                a[1]=j+6;
            }
        // prin(a);
        // f(i,n)if(a[i]==17)cout<<i<<'\n';
        vl b(n);
        f(i,n){
            b[i]=a[i]*a[(i+1)%n];
        }
        // prin(b);
        prin(b);
        // set <ll> x;
        // f(i,n){
        //     x.insert(b[i]);
        //     if(__gcd(b[i],b[(i+1)%n])==1)cout<<"1 "<<i<<'\n';
        //     if(__gcd(b[(i+2)%n],__gcd(b[i],b[(i+1)%n]))!=1)cout<<"2 "<<i<<'\n';
        // }
        // // cout <<x.size()<<'\n';
        // if(x.size()!=n){
        //     cout<<n<<' '<<x.size()<<'\n';
        // }
    }
	return 0;
}