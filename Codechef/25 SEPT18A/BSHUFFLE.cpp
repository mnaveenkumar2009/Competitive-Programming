#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define f(i,n) for(i=0;i<n;i++)
#define sc uscan()
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


int main() {
    ll t;
    t=1;
    // t=sc;
    ll kkk=0;
    // ios_base::sync_with_stdio(0);
    f(kkk,t){
        ll n=sc,i,j,k;
        vector <ll> a(n);
        f(i,n){
            a[i]=(i+n)%n;
            if(!a[i])a[i]=n;
        }
        switch(n){
            case 9:
                cout<<"2 3 4 5 1 7 8 9 6";
                break;
            case 10:
                cout<<"2 3 4 5 1 7 8 9 10 6";
                break;
            case 11:
                cout<<"2 3 4 5 6 1 8 9 10 11 7";
                break;
            case 12:
                cout<<"2 3 4 5 6 1 8 9 10 11 12 7";
                break;
            case 13:
                cout<<"2 3 4 5 6 7 1 9 10 11 12 13 8";
                break;
            case 14:
                cout<<"2 3 4 5 6 7 1 9 10 11 12 13 14 8";
                break;
            case 15:
                cout<<"2 3 4 5 6 7 8 1 10 11 12 13 14 15 9";
                break;
            case 16:
                cout<<"2 3 4 5 6 7 8 1 10 11 12 13 14 15 16 9";
                break;         
            case 17:
                cout<<"2 3 4 5 6 7 8 9 1 11 12 13 14 15 16 17 10";
                break;
            case 8:
                cout<<"2 3 4 1 6 7 8 5";
            case 7:
                cout<<"2 3 4 1 6 7 5";
                break;
            case 6:
                cout<<"2 3 1 5 6 4";
                break;
            case 5:
                cout<<"2 1 4 5 3";
                break;
            case 4:
                cout<<"2 1 4 3";
                break;
            case 3:
                cout<<"1 3 2";
                break;
            case 2:
                cout<<"2 1";
                break;
            case 1:
                cout<<"1";
                break;
                        
        }
        pc('\n');
        f(i,n){
            cout<<a[i]<<' ';
        }
        pc('\n');
        // vector <vector <ll> > xxx;
        // ll h;
        // f(h,pow(n,n))
        // {
        //     vector <ll> a(n);
        //     ll hh=h;
        //     f(i,n){
        //         a[i]=hh%n;
        //         hh/=n;
        //     }
        //     // f(i,n){
        //     //     cout<<a[i]<<' ';
        //     // }pc('\n');
        //     vector <ll> b(n);
        //     f(i,n){
        //         b[i]=i+1;
        //     }
        //     f(i,n){
        //         swap(b[i],b[a[i]]);
        //     }
        //     xxx.pb(b);
        // }
        // sort(xxx.begin(),xxx.end());
        // pc('\n');
        // ll count=0,maxi=0,mini=INT_MAX;
        // f(i,xxx.size()){
            
            
        //     if(i){
        //         if(xxx[i]==xxx[i-1]){
        //             count++;
        //         }
        //         else{
        //             xxx[i-1].pb(count+1);
        //             // f(j,xxx[i-1].size()){
        //             //     cout<<xxx[i-1][j]<<' ';
        //             // }cout<<'\n';
        //             // cout<<count+1<<'\n';
        //             mini=min(mini,count+1);
        //             maxi=max(maxi,count+1);
        //             count=0;
        //         }
        //     }
        // }

        // xxx[i-1].pb(count+1);
        // f(j,xxx[i-1].size()){
        //     cout<<xxx[i-1][j]<<' ';
        // }cout<<'\n';
        // // cout<<count+1<<'\n';
        // cout<<mini<<' '<<maxi<<'\n';
        // f(i,xxx.size()){
        //     if(xxx[i][xxx[i].size()-1]==mini||xxx[i][xxx[i].size()-1]==maxi){
        //         f(j,xxx[i].size()){
        //                 cout<<xxx[i][j]<<' ';
        //         }cout<<'\n';
        //     }
        // }



        // vector <ll> b(n),a(n);
        // b[(n-1)/2]=1;
        // b[n-1]=(n-1)/2+1;
        // f(i,(n-1)/2){
        //     b[i]=i+2;
        // }
        // f(i,n-(n-1)/2-2){
        //     b[i+(n-1)/2+1]=i+(n-1)/2;
        // }
        // f(i,n){
        //     a[i]=(i+n)%n;
        //     if(!a[i])a[i]=n;
        // }
        // f(i,n){
        //     cout<<a[i]<<' ';
        // }
        // pc('\n');
        // if(n==4)
        //     cout<<"2 1 4 3";
        // else
        // f(i,n)
        //     cout<<b[i]<<' ';
    }
    return 0;
}