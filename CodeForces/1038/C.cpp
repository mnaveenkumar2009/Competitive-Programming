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
    ll t=1;
    ll kkk=0;
    ios_base::sync_with_stdio(0);
    f(kkk,t){
        ll n=uscan(),i,j;
        vector <ll> a,b;
        f(i,n){
            a.pb(uscan());
        }
        f(i,n){
            b.pb(uscan());
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll A=0,B=0;
        i=n-1,j=n-1;
        int count=0;
        while(i!=-1||j!=-1){
            if(i!=-1){
                if(j!=-1){
                    if(count%2){
                        //Bs turn
                        if(a[i]>b[j]){
                            i--;
                        }
                        else{
                            B+=b[j--];
                        }
                    }
                    else{
                        //As turn
                        if(a[i]<b[j]){
                            j--;
                        }
                        else{
                            A+=a[i--];
                        }
                    }
                    count++;
                }
                else{
                    if(count%2){
                        //Bs turn
                        i--;
                    }
                    else{
                        A+=a[i--];
                    }
                    count++;
                }
            }
            else{
                //j!=-1
                if(count%2){
                    //bs turn
                    B+=b[j--];
                }
                else{
                    j--;
                }
                count++;
            }
        }
        cout<<A-B<<'\n';
    }
    return 0;
}