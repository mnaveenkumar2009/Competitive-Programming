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
// vector <bool> vis(200009,0);
vector <ll> divi[200004];

void seive(){
    ll i,j,k;

    for(i=2;i<200006;i++){
        if(divi[i].size()==0){
            divi[i].pb(i);
            for(j=2;j*i<200004;j++){
                divi[j*i].pb(i);
            }
        }
    }
}
int main()
{
    ll tt=sc,kkk;
    seive();
    f(kkk,tt){
        ll n=sc,maxi=0,i,j,k=sc;
        vl a(n);
        vl b1(100005,0),b2(100005,0);
        f(i,n){
            a[i]=sc;
        }
        ll l=0,r=n-1;
        if(n>1000)
        {
            // ll block=sqrt(n);
            ll approxans,star;
            for(star=1;star<n-1;star+=10000){
                approxans=star-1;
                ll xxx=1e5+4;
                vl b11(100005,0),b22(100005,0);
                f(i,approxans+1){
                    b11[a[i]]++;
                }
                for(i=approxans+1;i<n;i++){
                    b22[a[i]]++;
                }
                f(i,100005){
                    if(b11[i]>=k){
                        b11[i+1]+=b11[i]/k;
                        b11[i]%=k;
                    }
                    if(b22[i]>=k){
                        b22[i+1]+=b22[i]/k;
                        b22[i]%=k;
                    }
                }

                while(b11[xxx]==b22[xxx]&&xxx)xxx--;
                if(b11[xxx]>b22[xxx])break;
            }
            approxans=star-10000;
            l=max(star-10000,0LL);
            r=star+1;
            if(star>=n-1)r=n-1;
            f(i,l+1){
                b1[a[i]]++;
            }
            for(i=r;i<n;i++){
                b2[a[i]]++;
            }
            f(i,100005){
                if(b1[i]>=k){
                    b1[i+1]+=b1[i]/k;
                    b1[i]%=k;
                }
                if(b2[i]>=k){
                    b2[i+1]+=b2[i]/k;
                    b2[i]%=k;
                }
            }
            // cout<<l<<' '<<r<<'\n';
            // f(i,7){
            //     cout<<b1[i]<<' ';
            // }pc('\n');
            // f(i,7){
            //     cout<<b2[i]<<' ';
            // }pc('\n');
        }
        b1[a[0]]++;
        b2[a[n-1]]++;
        ll maxi1=a[0],maxi2=a[n-1];
        if(n>1000)
        {
            b1[a[0]]--;
            b2[a[n-1]]--;
            for(i=100004;i>=0;i--){
                if(b1[i])break;
            }
            maxi1=max(maxi1,i);
            for(i=100004;i>=0;i--){
                if(b2[i])break;
            }
            // maxi1=max(maxi1,i);
            maxi2=max(maxi2,i);
        }
        while(abs(r-l)!=1){
            // cout<<l<<' '<<r<<'\n';
            if(maxi1<maxi2){
                // increase l
                l++;
                b1[a[l]]++;
                i=0;
                while(b1[a[l]+i]>=k){
                    b1[a[l]+i]-=k;
                    i++;
                    b1[a[l]+i]++;
                }
                maxi1=max(a[l]+i,maxi1);
            }
            else{
                if(maxi2<maxi1){
                    // dec r
                    r--;
                    b2[a[r]]++;
                    i=0;
                    while(b2[a[r]+i]>=k){
                        b2[a[r]+i]-=k;
                        i++;
                        b2[a[r]+i]++;
                    }
                    maxi2=max(a[r]+i,maxi2);
                }
                else{
                    // maxi1=maxi2
                    if(b1[maxi1]<b2[maxi1]){
                            l++;
                            b1[a[l]]++;
                            i=0;
                            while(b1[a[l]+i]>=k){
                                b1[a[l]+i]-=k;
                                i++;
                                b1[a[l]+i]++;
                            }
                            maxi1=max(a[l]+i,maxi1);

                    }
                    else{
                        if(b1[maxi2]>b2[maxi2]){
                            //dec r
                            r--;
                            b2[a[r]]++;
                            i=0;
                            while(b2[a[r]+i]>=k){
                                b2[a[r]+i]-=k;
                                i++;
                                b2[a[r]+i]++;
                            }
                            maxi2=max(a[r]+i,maxi2);
                        }
                        else{
                            while(b1[maxi1]==b2[maxi2]){
                                b1[maxi1]=b2[maxi1]=0;
                                maxi1--;
                                maxi2--;
                                if(!maxi1)break;
                            }
                            if(maxi1==0){
                                r--;
                                b2[a[r]]++;
                                i=0;
                                while(b2[a[r]+i]>=k){
                                    b2[a[r]+i]-=k;
                                    i++;
                                    b2[a[r]+i]++;
                                }
                                maxi2=max(a[r]+i,maxi2);
                            }
                        }
                    }
                }
            }
        }
        // f(i,6)cout<<b1[i]<<' ';pc('\n');
        // f(i,6)cout<<b2[i]<<' ';pc('\n');
        cout<<l+1<<'\n';

    }

    return 0;
}