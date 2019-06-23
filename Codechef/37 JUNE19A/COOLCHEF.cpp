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
    #define double long double
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
    inline ll fpow(ll n, ll k) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = (r * n)% mod; n = (n * n) % mod;} return r;}


    int main()
    {

        #define MAXX 300006
        ll inv[MAXX+5];
        ll fac[MAXX+5],ifac[MAXX+5],i;
        fac[0]=ifac[0]=inv[0]=1;
        f(i,MAXX){
            fac[i+1]=((i+1)*fac[i])%mod;
            ifac[i+1]=fpow(fac[i+1],mod-2);
            inv[i+1]=fpow(i+1,mod-2);
        }
        int n=sc,q=sc;
        vector <ll> a(n);
        unordered_map <ll,ll> xxx;
        ll j,k,coun=1;
        vector <ll> pos[300009];
        f(i,n){
            a[i]=sc;
            if(!xxx[a[i]]){
                xxx[a[i]]=coun++;
            }
            pos[xxx[a[i]]].pb(i);
            a[i]=xxx[a[i]];
        }
        // f(i,n){
        //     cout<<a[i]<<' ';
        // }cout<<'\n';
        
        const int NBLOCKS =min(n,1050);
        #define quer(l,r,num) (upper_bound(pos[num].begin(),pos[num].end(),r)-lower_bound(pos[num].begin(),pos[num].end(),l))
        ll bsiz=n/NBLOCKS;
        ll pre[NBLOCKS+2][NBLOCKS+2];
        f(i,NBLOCKS+2){
            f(j,NBLOCKS+2)pre[i][j]=1;
        }
        f(i,NBLOCKS){
            ll ans=1;
            ll star=i*bsiz;
            for(j=star;j<n;j++){
                // cout<<i<<' '<<star <<' '<<j<<' '<<a[j]<<' '<<quer(star,j,a[j])<<'\n';
                ans*=((j-star+1)*inv[quer(star,j,a[j])])%mod;
                ans%=mod;
                if((j+1)%bsiz==0){
                    pre[i][j/bsiz]=ans;
                }
            }
        }
        // cout<<"pre\n";
        // f(i,2){
        //     f(j,2)cout<<pre[i][j]<<'\n';
        // }
        // cout<<"preend\n";
        ll ans=0;
        while(q--){
            ll l=sc*ans;
            l+=sc;
            ll r=sc*ans;
            r+=sc;
            l%=n;r%=n;
            if(l>r)swap(l,r);
            if(l/bsiz==r/bsiz){
                ans=1;
                for(int i=l;i<=r;i++){
                    ans*=((i-l+1)*inv[quer(l,i,a[i])])%mod;
                    ans%=mod;
                }
                cout<<ans<<'\n';
                continue;
            }
            
            ll lblock = (l/bsiz)+1;
            if((l)%bsiz==0)lblock--;
            ll rblock = (r/bsiz)-1;
            ans=pre[lblock][rblock];
            // cout<<ans<<'\n';
            ll curl=lblock*bsiz,curr=((rblock+1)*bsiz)-1;
            ll csiz=((rblock-lblock)+1)*bsiz;
            // cout<<l<<' '<<r<<' '<<lblock<<' '<<rblock<<' '<<curl<<' '<<curr<<'\n';
            while(curl>l){
                csiz++;
                ans*=(csiz*inv[quer(curl-1,curr,a[curl-1])])%mod;
                ans%=mod;
                curl--;
            }
            while(r>curr){
                csiz++;
                ans*=(csiz*inv[quer(curl,curr+1,a[curr+1])])%mod;
                ans%=mod;
                curr++;
            }

            cout<<ans<<'\n';
        }
        return 0;
    }
