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
    #define gc getchar
    #define pc putchar
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
    #define ld long double
    int main()
    {
    	int t=sscan();
    	while(t--){
    		ll k=uscan(),b=uscan(),a=uscan(),temp;
    		int i;
    		if(k==2){
    			if((a+b)%3)printf("NO\n");
    			else
    			printf("YES\n");
    			continue;
    		}
    		temp=(a+b)%10+a+b;
    		if(k==3){
    			if((temp)%3)printf("NO\n");
    			else
    			printf("YES\n");
    			continue;
    		}
    		ll qu=(k-3)/4;
    		ll rem=(k-3)%4;
    		vector <ll> aa(4,0);
    		ll sum=temp%10;
    		aa[0]=temp%10;
    		f(i,4){
    			if(i){
    			aa[i]=(2*aa[i-1])%10;
    			sum+=aa[i];
    			}
    		}
    		//cout<<aa[0]<<" "<<aa[1]<<" "<<aa[2]<<" "<<aa[3]<<endl;
    		
    		temp+=qu*sum;
    		f(i,rem)temp+=aa[i];
    		if(temp%3)
    		printf("NO\n");
    		else
    		printf("YES\n");
    	}
    	return 0;
    } 