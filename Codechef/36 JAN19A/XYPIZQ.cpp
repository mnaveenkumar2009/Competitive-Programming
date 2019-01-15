#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gc getchar
inline ll uscan(){
    ll n=0,c=gc();bool check=0;
    while(c<'0'||c>'9'){if(c=='-')check=1;c=gc();}
    while(c<='9'&&c>='0'){n=n*10+c-'0';c=gc();}
    return check?-n:n;
}
#define sc uscan()
int main()
{
    ll t=sc;
    while(t--){
        ll n=sc,t=sc,x=sc,y=sc,z=sc,num,den=2*n+1;
        if(x>z)
            if(t==1||t==3)t=4-t;
        
        if(x==z)
            num=y-1+(y<x)*2;
        else{
            if(t==1)
                num=2*n-y;
            if(t==2||t==4)
                num=(2*n+1)-(2*y);
            if(t==3)
                num=2*n+1-(y-1);
        }
        ll gc=__gcd(num,den);
        num/=gc;den/=gc;
        cout<<num<<' '<<den<<'\n';
    }
	return 0;
}