    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
     
    int main()
    {
    	int t;
    	sd(t);
    	while(t--)
    	{
    		string s;
    		cin>>s;
    		bool a[10],b[26];
    		vector <int> count(10,0);
    		int i;
    		f(i,10)a[i]=0;
    		f(i,26)b[i]=0;
    		f(i,s.length())
    		{
    			a[s[i]-'0']=1;
    			count[s[i]-'0']++;
    		}
    		//70 is f=5
    		f(i,10)
    		{
    			if(a[7]&&a[i])
    			{
    				b[5+i]=1;
    			}
    			if(a[8]&&a[i])
    			{
    				b[15+i]=1;
    			}
    		}
    		if(a[0]&&a[9])b[25]=1;
    		if(a[6])
    		{
    			f(i,5)
    			{
    				if(a[i+5])
    				{
    					b[i]=1;
    				}
    			}
    		}
    		if(count[8]<2)b[23]=0;
    		if(count[7]<2)b[12]=0;
    		if(count[6]<2)b[1]=0;
    		f(i,26)
    		{
    			if(b[i])
    			{
    				printf("%c",i+65);
    			}
    		}
    		cout<<endl;
    	}
    	return 0;
    } 