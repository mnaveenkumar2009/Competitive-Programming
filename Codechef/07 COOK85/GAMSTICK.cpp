    #include<bits/stdc++.h>
     
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    using namespace std;
    int main()
    {
    	int i,j,n,m;
    	int t;
    	sd(t);
    	while(t--)
    	{
    	long long n,x1,x2,y1,y2;
    	slld(n);
    	slld(x1);
    	slld(y1);
    	slld(x2);
    	slld(y2);
    	bool we=0,mmm=0;
    	if(x1==x2)
    	{
    		bool same=0;
    		if(y1>y2&&y1<=(n+1)/2 )
    		{
    			we=1;
    		}
    		if(y1<y2&&y1>=((n+2)/2)){
    			we=1;
    		}
    		
    		if(y1<y2&&y1<((n+2)/2)&&y2>=((n+2)/2)){
    			long long d1=((n+1)/2),d2=((n+2)/2);
    			d1-=y1;
    			d2-=y2;
    			d1= abs(d1);d2=abs(d2);
    			if(d1==d2&&n%2==0)mmm=1;
    			if(d1<=d2) 
    			{
    				we=1;
    			}
    			if(n%2==0)
    			{
    				if(d1==d2+1)mmm=1;
    			}
    			
    		}
    		if(y1>y2&&y1>(n+1)/2 && y2<=(n+1)/2 )
    		{
    				long long d1=((n+2)/2),d2=((n+1)/2);
    			d1-=y1;
    			d2-=y2;
    			d1= abs(d1);d2=abs(d2);
    			if(d1==d2&&n%2==0)mmm=1;
    			
    			if(d1<=d2) 
    			{
    				we=1;
    			}
    			if(n%2==0)
    			{
    				if(d1==d2+1)mmm=1;
    			}
    		}
    	}
    	else
    	{
    		if(y1>y2&&y1<=(n+1)/2 )
    		{
    			we=1;
    		}
    		if(y1<y2&&y1>=((n+2)/2)){
    			we=1;
    		}
    		if(y2>y1&&y2<=(n+1)/2 )
    		{
    			if(abs(y1-y2)==1)mmm=1;
    		}
    		if(y2<y1&&y2>=((n+2)/2)){
    			if(abs(y1-y2)==1)mmm=1;
    		}
    		
    		if(y1==y2)
    		{
    			mmm=1;
    		}
    		
    		
    		
    		if(y1<y2&&y1<((n+2)/2)&&y2>=((n+2)/2)){
    			long long d1=((n+1)/2),d2=((n+2)/2);
    			d1-=y1;
    			d2-=y2;
    			d1= abs(d1);d2=abs(d2);
    			if(d1==d2)mmm=1;
    			
    			if(d1>d2)
    			{
    				if(d1-d2<=2&&n%2==0)mmm=1;
    				if(d1-d2<=1&&n%2)mmm=1;
    			}
    			if(d1<d2)
    			{
    				if(n%2)we=1;
    				if(n%2==0)
    				{
    					if(d2-d1<=1)mmm=1;
    					else
    					we=1;
    				}
    			}
    		}
    		if(y1>y2&&y1>(n+1)/2 && y2<=(n+1)/2 )
    		{
    				long long d1=((n+2)/2),d2=((n+1)/2);
    			d1-=y1;
    			d2-=y2;
    			d1= abs(d1);d2=abs(d2);
    			if(d1==d2)mmm=1;
    				if(d1>d2)
    			{
    				if(d1-d2<=2&&n%2==0)mmm=1;
    				if(d1-d2<=1&&n%2)mmm=1;
    			}
    			if(d1<d2)
    			{
    				if(n%2)we=1;
    				if(n%2==0)
    				{
    					if(d2-d1<=1)mmm=1;
    					else
    					we=1;
    				}
    			}
    			
    		}
    	}
    	
    	if(mmm)
    	{
    		printf("Draw\n");
    	}
    	else
    	{
    		if(we)
    		{
    		printf("Miron\n");	
    		}
    		else
    		{
    		printf("Slava\n");	
    		}
    	}
    	}
    	return 0;
    } 