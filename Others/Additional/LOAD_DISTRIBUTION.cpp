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
#define vvl vector <vector <ll> >
#define vl vector <ll>

int main() {
    ll n,i,j,k;
    cin>>n;
    ll L[n],R[n],T[n],W[n];
    ld num[n],den[n];
    ll P[24]={4, 4 ,10 ,10, 4, 4, 4, 4, 4, 4, 4 ,10, 10, 10, 4, 4 ,4, 4, 4, 4, 4 ,4 ,4 ,4};
    vector <bool> is4(24,0);
    f(i,24){
        if(P[i]==4){
            is4[i]=1;
            cout<<i+1<<' ';
        }
    }
    cout<<'\n';
    f(i,n){
        cin>>L[i];
    }
    f(i,n){
        cin>>R[i];
    }
    f(i,n){
        cin>>T[i];
    }
    f(i,n){
        cin>>W[i];
    }
    f(i,n){
        num[i]=T[i];
        den[i]=0;
        f(j,24){
            if(is4[j]){
                if((j<=R[i]-1)&&(j>=L[i]-1))
                    den[i]++;
            }
        }
    }
    // f(i,n){
    //     cout<<num[i]<<' '<<den[i]<<'\n';
    // }
    ll ans=0;

    ll LIMIT=20;
    vector <ll> hours[24];
    f(i,24){
        if(is4[i]){
            // cout<<"Hr "<<i<<'\n';
            vector <pair <ld,ll> > xxx;
            f(j,n){
                if((i<=R[j]-1)&&(i>=L[j]-1))
                    if(num[j])
                    xxx.pb(mp(num[j]/den[j],j));
            }
            sort1(xxx);
            reverse(xxx.begin(),xxx.end());
            for(auto it:xxx){
                // cout<<it.ff<<' '<<it.ss<<'\n';
            }
            // cout<<'\n';
            ll lim=LIMIT;
            f(j,xxx.size()){
                if(!(xxx[j].ff))break;
                ll pos=xxx[j].ss;
                if(lim>=W[pos]){
                    hours[i].pb(pos);
                    lim-=W[pos];
                    ans+=4*W[pos];
                    num[pos]--;
                }
            }
            f(j,xxx.size()){
                den[xxx[j].ss]--;
            }
        }
    }
    f(i,n){
        den[i]=0;
        f(j,24){
            if(!is4[j]){
                if((j<=R[i]-1)&&(j>=L[i]-1))
                    den[i]++;
            }
        }
    }
    // cout<<ans<<'\n';
    f(i,24){
        if(!is4[i]){
            vector <pair <ld,ll> > xxx;
            f(j,n){
                if((i<=R[j]-1)&&(i>=L[j]-1))
                    if(num[j])
                    xxx.pb(mp(num[j]/den[j],j));
            }
            sort1(xxx);
            reverse(xxx.begin(),xxx.end());
            ll lim=LIMIT;
            f(j,xxx.size()){
                if(!(xxx[j].ff))break;
                ll pos=xxx[j].ss;
                if(lim>=W[pos]){
                    hours[i].pb(pos);
                    lim-=W[pos];
                    ans+=4*W[pos];
                    num[pos]--;
                }
            }
            f(j,xxx.size()){
                den[xxx[j].ss]--;
            }
        }
    }
    f(i,24){
        cout<<"Hour "<<i+1<<": ";
        for(auto it:hours[i]){
            cout<<it+1<<' ';
        }
        cout<<'\n';
    }
    f(i,n){
        ans+=W[i]*num[i]*10;
    }
    cout<<ans<<'\n';
	return 0;
}

/*

IN:
6
2 4 6 4 5 11
4 18 8 12 10 19
3 3 3 3 6 4
4 4 4 5 5 6

OUT:
1 2 5 6 7 8 9 10 11 15 16 17 18 19 20 21 22 23 24 
Hour 1: 
Hour 2: 1 
Hour 3: 1 
Hour 4: 1 
Hour 5: 5 4 2 
Hour 6: 5 3 4 2 
Hour 7: 5 3 4 2 
Hour 8: 5 3 
Hour 9: 5 
Hour 10: 5 
Hour 11: 6 
Hour 12: 
Hour 13: 
Hour 14: 
Hour 15: 6 
Hour 16: 6 
Hour 17: 6 
Hour 18: 
Hour 19: 
Hour 20: 
Hour 21: 
Hour 22: 
Hour 23: 
Hour 24: 
420

*/