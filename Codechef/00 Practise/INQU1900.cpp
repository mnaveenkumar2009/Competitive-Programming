#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define ll int
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

int main()
{
    ll t=sc;
    while(t--){
        string s;
        cin>>s;
        ll n = s.length(),i,j;
        ll q=sc;
        ll l0=sc,r0=sc,x0=sc,y0=sc,m=sc;
        ll a[n][n],F[n][n],CFL[n][n],CFR[n][n];
        ll a2[n][n],F2[n][n],CFL2[n][n],CFR2[n][n];

        f(i,n){
            ll low = 0,high = min(i,n-i-1);
            while(low<high){
                if(s[i-low-1]==s[i+low+1])
                    low++;
                else
                    break;
            }
            f(j,n)
                a[i][j] = min(low,j)+1;

            if(i==n-1){
                f(j,n){
                    a2[i][j] = 0;
                }
                continue;
            }

            low = -1,high = min(i,n-i-2);
            while(low<high){
                if(s[i-low-1]==s[i+low+2])
                    low++;
                else
                    break;
            }
            f(j,n)
                a2[i][j] = min(low,j)+1;
        }
        f(i,n)f(j,n)F[i][j]=0;
        f(i,n){
            f(j,n){
                F[i][j] = a[i][j];
                CFL[i][j] = CFR[i][j] = a[i][j];
                F2[i][j] = a2[i][j];
                CFL2[i][j] = CFR2[i][j] = a2[i][j];
                if(i){
                    F[i][j] += F[i-1][j];
                    F2[i][j] += F2[i-1][j];
                    if(j){
                        CFL[i][j] += CFL[i-1][j-1];
                        CFL2[i][j] += CFL2[i-1][j-1];
                    }
                }
            }
        }
        for( i=n-1;i>=0;i--){
            f(j,n){
                if(i!=n-1){
                    if(j){
                        CFR[i][j] += CFR[i+1][j-1];
                        CFR2[i][j] += CFR2[i+1][j-1];
                    }
                }
            }
        }

        // f(i,n){
        //     f(j,n){
        //         cout<<a2[i][j]<<' ';
        //     }cout<<'\n';
        // }
        
        
        ll l = l0,r=r0,x=x0,y=y0;
         

        ll ans=0;
        long long anssss=0;
        while(q--){
            l = 1+ (l+ans)%n;
            r = 1+ (r+ans)%n;
            if(l>r)swap(l,r);
            l--;
            r--;
            x=1+(x+ans)%m;
            y=1+(y+ans)%n;
            if(x>y)swap(x,y);

            ans = 0;

            int xineed=x/2, yineed= (y-1)/2;
            if(yineed<((r-l)/2)){
                if(l+yineed < r-yineed-1){
                    ans = F[r-yineed-1][yineed] - F[l+yineed][yineed];
                }
            }
            else{
                yineed = (r-l)/2;
            }
            ans += CFL[l+yineed][yineed] + CFR[r-yineed][yineed];
            if(l+yineed==r-yineed){
                ans-=a[l+yineed][yineed];
            }
            xineed--;
            if(xineed>=0){
                if(xineed<((r-l)/2)){
                    if(l+xineed < r-xineed-1)
                        ans -= F[r-xineed-1][xineed] - F[l+xineed][xineed];
                }
                else{
                    xineed = (r-l)/2;
                }
                ans -= CFL[l+xineed][xineed] + CFR[r-xineed][xineed];
                if(l+xineed==r-xineed){
                    ans+=a[l+xineed][xineed];
                }
            }
            // cout<<"After odd palins "<<ans<<' '<<xineed<<' '<<yineed<<'\n';

            xineed = floor((x-1)/2.0), yineed = floor((y-2)/2.0);
            r--;
            if(r<l)goto xyzzzzz;
            if(yineed>=0){
                if(yineed<((r-l)/2)){
                    if(l+yineed < r-yineed-1)
                        ans += F2[r-yineed-1][yineed] - F2[l+yineed][yineed];
                }
                else{
                    yineed = (r-l)/2;
                }
                if(yineed>=0){
                    ans += CFL2[l+yineed][yineed] + CFR2[r-yineed][yineed];
                    if(l+yineed==r-yineed){
                        ans-=a2[l+yineed][yineed];
                    }
                }
            }
            xineed--;
            if(xineed>=0){
                if(xineed<((r-l)/2)){
                    if(l+xineed < r-xineed-1)
                        ans -= F2[r-xineed-1][xineed] - F2[l+xineed][xineed];
                }
                else{
                    xineed = (r-l)/2;
                }
                if(xineed>=0){
                    ans -= CFL2[l+xineed][xineed] + CFR2[r-xineed][xineed];
                    if(l+xineed==r-xineed){
                        ans+=a2[l+xineed][xineed];
                    }
                }
            }
            xyzzzzz:
            // cout<<"After even palins "<<ans<<' '<<xineed<<' '<<yineed<<'\n';
            r++;
            // cout<<ans<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<'\n';
            anssss+=ans;
            l++;
            r++;
        }
        cout<<anssss<<'\n';
    }
	return 0;
}