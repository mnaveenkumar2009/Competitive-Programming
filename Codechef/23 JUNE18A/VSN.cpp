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
inline ll uscan()
{
    ll n=0,c=gc();
    bool we=0;
    if(c=='-')we=1;
    while(c<'0'||c>'9'){
        c=gc();
        if(c=='-')we=1;
    }
    while(c<='9'&&c>='0'){
        n=n*10+c-'0';
        c=gc();
    }
    return n+(-2*we*n);
}
    
    int main()
    {
        ll  t=uscan();
        while(t--){
            ld px=uscan();
            ld py=uscan();
            ld pz=uscan();
            ld qx=uscan();
            ld qy=uscan();
            ld qz=uscan();
            ld dx=uscan();
            ld dy=uscan();
            ld dz=uscan();
            ld cx=uscan();
            ld cy=uscan();
            ld cz=uscan();
            ld r=uscan();
            ld low=0,high=4e9;
            ld mid;
            while(abs(low-high)>(1e-8)){
                mid=(low+high)/(2.0);
                ld u1=cx-px;
                ld u2=cy-py;
                ld u3=cz-pz;
                ld v1=px-(qx+dx*mid);
                ld v2=py-(qy+dy*mid);
                ld v3=pz-(qz+dz*mid);
                ld temp = pow(u2 * v3 - v2 * u3,2)+pow(v1 * u3 - u1 * v3,2)+pow(u1 * v2 - v1 * u2,2);
                ld temp2=v1*v1+v2*v2+v3*v3;
                if(sqrt(temp)/sqrt(temp2)>=r){
                    high=mid;
                }
                else{
                    low=mid+0.00000001;
                }
            }
            printf("%0.8Lf\n",mid);
        }
        return 0;
    }  