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
    ll a[100006][4];
    long long f2(ll x,int i){
        ll ans=a[i][0];
        ans+=a[i][1]*x;
        ans+=a[i][2]*x*x;
        ans+=a[i][3]*x*x*x;
        return ans;
    }
     
    int main()
    {
        
    	int t=sscan() ;
    	while(t--){
    	    int  n=sscan();
    	    
    	    int i,j;
    	    bool we=1;
    	    
    	    f(i,n)
    	    f(j,4)
    	    {
    	        a[i][j]=sscan();
    	        if(j==2||j==3){
    	            if(a[i][j])we=0;
    	        }
    	    }
    	    int q=sscan();
    	    if(we){
    	        int siz=0;
                vector <pair <ll,ll> > qn2,qn;
                
                f(i,n){
                    qn2.pb(mp(a[i][1],a[i][0]));
                }
                sort(qn2.begin(),qn2.end());
                int nnn=0;
                //erasing duplicate slopes
                f(i,n){
                    if(nnn){
                        if(qn2[i].ff==qn2[i-1].ff){
                            qn[nnn-1].ss=min(qn[nnn-1].ss,qn2[i].ss);
                        }
                        else
                        {
                           qn.pb(qn2[i]); 
                           nnn++;
                        }
                    }
                    else{
                        qn.pb(qn2[i]);
                        nnn++;
                    }
                }
                n=nnn;
                ll flag=-1;
                vector <ll> flags,posi;
                j=0;
                //ff is slope |||||ss is y intercept
                while(1){
                    flag=-1;
                    int j2=-1;
                    for(i=j+1;i<n;i++){
                        if(qn[j].ss<=qn[i].ss)continue;
                        ll xxx=(qn[j].ss-qn[i].ss)/(qn[i].ff-qn[i].ff);
                        if(xxx>=flag){
                            flag=xxx;
                            j2=i;
                        }
                    }
                    if(siz==0){
                    flags.pb(flag);
                    posi.pb(j);
                    j=j2;
                    siz++;    
                    }
                    else
                    {
                        if(flags[siz-1]>flag){
                            flags.pb(flag);
                            posi.pb(j);
                            j=j2;
                            siz++; 
                        }
                        else{
                            break;
                        }
                    }
                    if(j2==-1)break;
                }
                
                while(q--){
                    ll x=uscan();
                    int low = 0, high = siz; 
                        while (low != high) {
                                int mid = (low + high) / 2;
                        if (flags[mid] <= x) 
                            low = mid + 1;
                        else 
                            high = mid;
                        
                        }
                    int poss=posi[low];
                    ll ans=qn[poss].ff*x;
                    ans+=qn[poss].ss;
                }
    	    }
    	    else
    	    {
    	        while(q--){
    	            ll x=uscan();
    	            ll maxi=LLONG_MAX;
    	            f(i,n){
    	                maxi=min(maxi,f2(x,i));
    	            }
    	            printf("%lld\n",maxi);
    	        }
    	    }
    	    
    	}
    	
    	return 0;
    } 