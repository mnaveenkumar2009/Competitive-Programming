    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
    #define ff first
    #define ss second
    #define ll long long
    #define gc getchar_unlocked
    #define pc putchar_unlocked
    inline unsigned long long uscan()
    {
        unsigned long long n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0'){
    n=n*10+c-'0';
    c=gc();}
    return n;
    }
     
    inline long int lscan()                 
    {
        long int n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0'){
    n=n*10+c-'0';
    c=gc();}
    return n;
    }
     
     
    inline  int sscan()                     
    {register  int n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0')
        {
    n=n*10+c-'0';
    c=gc();
        }
    return n;
    }
     
    int main() {
        ll n=uscan(),q=uscan();
        ll d=sqrt(n);
        d++;
        vector <ll> a(n);
        int i;
        f(i,n){
            a[i]=uscan();
            if(i)a[i]=a[i-1]^a[i];
        }
        //100489 max n
        d*=d;
        n=d;
        d=sqrt(d);
        
        ll lasst=a[a.size()-1];
        while(a.size()!=n){
            a.pb(lasst);
        }
        vector < vector <ll> > aa(d, vector <ll>(d,0)),bb(d, vector <ll>(d,0));
        f(i,n){
            aa[i/d][i%d]=a[i];
            bb[i/d][i%d]=a[i];
        }
        //cout<<d<<" "<<n<<endl;
        //f(i,n)cout<<aa[i/d][i%d]<<" ";cout<<endl;
        f(i,d){
            sort(bb[i].begin(),bb[i].end());
        }
        vector <ll> lazy(d,0);//max 317
        while(q--){
            int que=sscan();
            if(que==1){
                ll pos=uscan(),x=uscan();
                
                pos--;
                
                x=x^(aa[pos/d][pos%d])^lazy[pos/d];
                if(pos!=0)
                {
                    int pos2=pos-1;
                    x=x^(aa[pos2/d][pos2%d])^lazy[pos2/d];
                }
                bool we=0;
                while(pos%d!=0){
                    we=1;
                    aa[pos/d][pos%d]^=x;
                    pos++;
                }
                if(we){
                    //change bb
                    i=(pos/d)-1;
                    bb[i]=aa[i];
                    sort(bb[i].begin(),bb[i].end());
                }
                for(i=pos/d;i<d;i++)lazy[i]^=x;
            }
            else
            {
                ll pos=uscan(),k=uscan();
                ll noc=pos/d;
                pos-=noc*d;
                ll ans=0;
                vector <ll> :: iterator low,up;
                f(i,noc){
                    ll check=lazy[i]^k;
                    low=lower_bound(bb[i].begin(),bb[i].end(),check);
                    up=upper_bound(bb[i].begin(),bb[i].end(),check);
                    ans+=up-low;
                }
                if(i<d){
                    ll check=lazy[i]^k;
                    for(int j=0;j<pos;j++){
                        if(check==aa[i][j])ans++;
                    }    
                }
                printf("%lld\n",ans);
            }
            //f(i,n)cout<<aa[i/d][i%d]<<" ";cout<<endl;
            //f(i,n)cout<<bb[i/d][i%d]<<" ";cout<<endl;
            //f(i,d)cout<<lazy[i]<<" ";cout<<endl;
        }
    	return 0;
    } 