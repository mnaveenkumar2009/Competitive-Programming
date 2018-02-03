    //40 points solution
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
    int main(){
    	int t;
    	cin>>t;
    	int dp[500005];
    		dp[0]=0;
    		dp[1]=2;
    		dp[2]=3;
    		int i;
    		f(i,500005){
    			if(i){
    			    
    			    if(dp[i-1]<i){
    		
    		        dp[i]=dp[i-1]*2+2;
    	            }
    	            else
    	            {
    		        int a=dp[i-1]-i;
    		        dp[i]=(a*2+3);
    	            }
    			}
    		}
    	while(t--){
    		int m,x=0,y=1;
    		m=sscan();
    		x=sscan();
    		y=sscan();
    		int yyy=m;
    		
    	//	f(i,100)cout<<dp[i]<<endl;
    		if(x==0){
    			
    			cout<<(m^(dp[m/2-1]+1))<<endl;
    		}
    		else
    		{
    			
    			int a[2][m];
    			int i;
    			f(i,m){
    				a[0][i]=i+1;
    			}
    			int xxx=1;
    			while(m>2){
    				int pos=m/2;
    				pos*=x;
    				pos/=y;
    				
    				int count=0,count1=-1;
    				f(i,m){
    					
    					if(i%2){
    						
    						if((i/2)!=pos){
    						a[xxx][m/2+count1]=a[1-xxx][i];
    						count1++;}
    					}
    					else
    					{
    						
    						if((i/2)!=pos){
    							a[xxx][count]=a[1-xxx][i];
    							count++;
    						}
    					}
    				}
    				m-=2;
    				xxx=1-xxx;
    			}	
    			int xx=0;
    			f(i,m)xx=xx^a[1-xxx][i];
    			printf("%d\n",xx);
    		}		
    	}
    	return 0;
    }