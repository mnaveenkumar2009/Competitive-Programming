    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    using namespace std;
    int i,j;
    int main() 
    {
    	int t;
    	cin>>t;
    	while(t--)
    	{   int n,i;
    	
    	    cin>>n;
    	    vector <long long> a(n),d;
    	    int count=0;
    	    long long sum=0;
    	f(i,n)
    	{
    	    cin>>a[i];
    	    if(a[i]>=0)
    	    {
    	        count++;
    	        sum+=a[i];
    	    }
    	    else
    	    {
    	        d.pb(a[i]);
    	    }
    	}
    	sort(d.begin(),d.end());
    	int y=d.size();
    	
        	while(d.size()!=0)
    	   {
    	       if(((d[d.size()-1]+sum)*(count+1))>sum*count)
    	   {
    	       count++;
    	       sum+=d[d.size()-1];
    	       d.pop_back();
    	   }
    	   else
    	   break;
    	   }
    	long long prod=0;
    	f(i,d.size())
    	{
    	  prod+=d[i];  
    	}
    	
    	
    	cout<<(sum*count)+prod<<endl;
    	    
    	}
    } 