// 10 points solution:
    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    using namespace std;
    #define N 1004
     
    int i,j,k;
    int main() 
    {
        vector <bool> a(N);
        vector <int> p;
        
        a[0]=1;
        a[1]=1;
        int i;
        f(i,N)
            {
            if(a[i]==0)
                {
                p.pb(i);
            
            for(int j=2;j*i<=N;j++)
                {
                a[i*j]=1;
            }
            }
        }
      ///////////////seive over  ///////////////////////
        int n;
        cin>>n;
        vector <long long> aa(n);
      vector <  vector <int> > aaa(n, vector <int> (0,0)) ,count(1000006, vector <int> (n,0));
    	int t;
    	f(i,n)
    	{
    	    cin>>aa[i];
    	    int j=0;
    	        while(aa[i]!=1&&j!=p.size())
    	    { 
    	        if(aa[i]%p[j]==0)
    	        {
    	               for(k=i;k<n;k++)
    	               {
    	                   aaa[k].pb(p[j]);
    	               }
    	                aa[i]/=p[j];
    	        }
    	        else
    	        j++;
    	    }
    	    if(aa[i]!=1)
    	    {
    	        for(k=i;k<n;k++)
    	               {
    	                   aaa[k].pb(aa[i]);
    	               }
    	    }
    	    
    	    sort(aaa[i].begin(),aaa[i].end());
    	}
    	
    	
    	//f(i,n){	    f(j,aaa[i].size())cout<<aaa[i][j]<<" ";cout<<endl;	}
    	cin>>t;
    	while(t--)
    	{  int l,r,count=0;
    	long long x,y;
    	    cin>>l>>r>>x>>y;
    	    l--;r--;
    	    f(k,aaa[r].size())
    	    {
    	        if(aaa[r][k]>=x)break;
    	    }
    	//    cout<<k<<endl;
    	    count-=k;
    	    f(k,aaa[r].size())
    	    {
    	        if(aaa[r][k]>y)break;
    	    }
    	    
    	   // cout<<k<<endl;
    	    count+=k;
    	    if(l)
    	    {
    	       f(k,aaa[l-1].size())
    	    {
    	        if(aaa[l-1][k]>=x)break;
    	    }
    	   //cout<<k<<endl;
    	    count+=k;
    	    f(k,aaa[l-1].size())
    	    {
    	        if(aaa[l-1][k]>y)break;
    	    }
    	    
    	 // cout<<k<<endl;
    	    count-=k; 
    	    }
    	    cout<<count<<endl;
    	}
    }  