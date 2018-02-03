    #include <stdio.h>
    #include <math.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
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
     
    ll gcdExtended(ll a, ll b, ll *x, ll *y)
    {
        if (a == 0)
        {
            *x = 0, *y = 1;
            return b;
        }
     
        ll x1, y1;
        ll gcd = gcdExtended(b%a, a, &x1, &y1);
        *x = y1 - (b/a) * x1;
        *y = x1;
     
        return gcd;
    }
     
    ll modInverse(ll a, ll m)
    {
        ll x, y;
        ll g = gcdExtended(a, m, &x, &y);
        ll res = (x%m + m) % m;
        return res;
        
    }
     
     
    int main()
    {
        
    	int t=sscan() ;
    	while(t--){
    	    long long  n=uscan(),p=uscan(),q=uscan();
    	    ll a[n];
    	    
    	    ll  factors[12][2];
    	    ll nnn=p;
    	    for(int o=0;o<12;o++)
            {
                factors[o][0]=0;
                factors[o][1]=0;
            }
            ll count=0;
            while (nnn%2 == 0)
            {   
                if(!count)
                {
                factors[count][0]=2;
                factors[count++][1]=2;
                }
                else
                {
                factors[count-1][0]*=2;
                }
                nnn = nnn/2;
            }
     
            for (ll i = 3; i <= sqrt(nnn); i = i+2)
            {
                while (nnn%i == 0)
                {   
                    if(count){
                        if(factors[count-1][0]%i!=0)
                        {
                            factors[count][0]=i;
                            factors[count++][1]=i;
                        }
                        else
                        {
                            factors[count-1][0]*=i; 
                        }
                        nnn = nnn/i;
                    }
                    else
                    {
                        factors[count][0]=i;
                        factors[count++][1]=i;
                        nnn/=i;
                    }
                }
            }
            if(!count&&nnn>2){
            factors[count][0]=nnn;
            factors[count++][1]=nnn;
            nnn=1;
            }
        
            if (nnn > 2)
            {
                if(factors[count-1][0]%nnn!=0)
                {
                    factors[count][0]=nnn;
                    factors[count++][1]=nnn;
                }
                else
                factors[count-1][0]*=nnn; 
            }
            
            
            
    	     ll factsize=count;//max 9
    	     ll prod[n][factsize],init[n][factsize];
    	     ll coun[n][factsize];
    	     ll modin[n][factsize];
    	    ll i,j;
    	    f(i,n)
    	    {
    	        a[i]=uscan();
    	        f(j,factsize){
    	            coun[i][j]=0;    
    	            if(i&&prod[i-1][j]){
    	                coun[i][j]=coun[i-1][j];
    	                prod[i][j]=(prod[i-1][j]*a[i])%(factors[j][0]);
    	                init[i][j]=init[i-1][j];    
    	                if(prod[i][j]!=0){
    	                while(prod[i][j]%factors[j][1]==0){
    	                    prod[i][j]/=factors[j][1];
    	                    coun[i][j]++;
    	                }
    	                modin[i][j]=modInverse(prod[i][j],factors[j][0]);}
    	                else
    	                modin[i][j]=1;
    	            }
    	            else{
    	                init[i][j]=i-1;
    	                prod[i][j]=a[i]%factors[j][0];
    	                if(prod[i][j]!=0){
    	                while(prod[i][j]%factors[j][1]==0){
    	                    prod[i][j]/=factors[j][1];
    	                    coun[i][j]++;
    	                }
    	                modin[i][j]=modInverse(prod[i][j],factors[j][0]);}
    	                else
    	                modin[i][j]=1;
    	            }
    	        }
    	    }
    	    /*
    	    f(i,n){
    	        f(j,n){
    	            printf("prod:%lld init:%lld count:%lld       ",prod[i][j],init[i][j],coun[i][j]);
    	        }
    	        printf("\n");
    	    }*/
    	    
    	    
    	    ll blen=q/64;
    	    blen+=2;
    	     ll b[blen];
    	    f(i,blen){
    	        b[(int)i]=uscan();
    	    }
    	    
    	     ll l,r,ans=0;
    	    
    	     ll modin2[factsize];
    	    f(i,factsize){
    	        modin2[i]=modInverse(p/factors[i][0],factors[i][0]);
    	        modin2[i]*=(p/factors[i][0]);
    	        modin2[i]%=p;
    	    }
    	     ll fact[factsize][40];
    	     ll siz[factsize];
    	    f(i,factsize){
    	       j=1;
    	       while(pow(factors[i][1],j)!=factors[i][0]){
    	          fact[i][j-1]=pow(factors[i][1],j);
    	          j++;
    	       }
    	       
    	       fact[i][j-1]=factors[i][0];
    	       siz[i]=j;
    	    }
    	    
    	    f(j,q){
    	        if((j&63)==0){
    	          l= (b[(j/64)]+ans)%n; 
    	          r=(b[(j/64)+1]+ans)%n;
    	        }
    	        else
    	        {
    	            l=(ans+l)%n;r=(r+ans)%n;
    	        }
    	        if(l>r){
    	            ll t = l;
    	            l=r;
    	            r=t;
    	        }
    	        ans=0;
    	        
    	        
    	        f(i,factsize){
    	            
    	            if(init[l][i]==init[r][i]){
        	            ll rem=prod[r][i];
        	            ll cou=coun[r][i];
        	            if(l!=0){
        	                cou-=coun[l-1][i];
        	            }
        	            if(cou<siz[i]){
        	            if(l!=0)
        	            rem=(rem*modin[l-1][i])%factors[i][0];
        	            if(cou)
        	            {rem*=fact[i][cou-1];
        	            rem%=factors[i][0];}
        	            ans=(ans+(rem*modin2[i]))%p;
        	            }
    	            }
    	        }
    	        
    	        ans++;
    	        if(ans==p)ans=0;
    	        
    	    }
    	    printf("%lld\n",(ans));
    	    
    	}
    	
    	return 0;
    }  