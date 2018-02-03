    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
    #define ll long long
    int getMid(int s, int e) {  return s + (e -s)/2;  }
    long long getSumUtil(ll *st, int ss, int se, int qs, int qe, int si)
    {
        if (qs <= ss && qe >= se)
            return st[si];
        if (se < qs || ss > qe)
            return 0;
        int mid = getMid(ss, se);
        return (getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
               getSumUtil(st, mid+1, se, qs, qe, 2*si+2))%mod;
    }
     
    void updateValueUtil(long long *st, int ss, int se, int i, long long diff, int si)
    {
        if (i < ss || i > se)
            return;
        st[si] = st[si] + diff;
        if (se != ss)
        {
            int mid = getMid(ss, se);
            updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
            updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
        }
    }
    void updateValue(long long arr[], long long *st, int n, int i, long long new_val)
    {
        long long diff = new_val - arr[i];
     
        arr[i] = new_val;
        updateValueUtil(st, 0, n-1, i, diff, 0);
    }
    long long getSum(long long *st, int n, int qs, int qe)
    {
     
        return getSumUtil(st, 0, n-1, qs, qe, 0);
    }
     
    long long constructSTUtil(long long arr[], int ss, int se, long long *st, int si)
    {
        if (ss == se)
        {
            st[si] = arr[ss];
            return arr[ss];
        }
     
        int mid = getMid(ss, se);
        st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
                  constructSTUtil(arr, mid+1, se, st, si*2+2);
        return st[si];
    }
     
    long long *constructST(long long arr[], int n)
    {
        int x = (int)(ceil(log2(n))); 
        int max_size = 2*(int)pow(2, x) - 1; 
        long long *st = new long long[max_size];
        constructSTUtil(arr, 0, n-1, st, 0);
        return st;
    }
     
     
    int main()
    {
    	int t;
    	sd(t);
    	while(t--)
    	{
    		int n,m;
    		sd(n);
    		sd(m);
    		vector < pair < int , pair <int,int> > > query1,query2;
    		int i;
    		f(i,m)
    		{
    			int que;
    			sd(que);
    			int l,r;
    			sd(l);sd(r);
    			l--;r--;
    			if(que==1)
    			{
    				query1.pb( mp(i , mp(l,r)));
    			}
    			else
    			{
    				query2.pb( mp(i , mp(l,r)));
    			}
    		}
    		sort(query2.rbegin(), query2.rend());
    		long long commands[m];
    		f(i,m)commands[i]=0;
    		commands[0]=1;
    		
    		long long *segt=constructST(commands, m);
    		int nocommands=query2.size();
    		f(i,nocommands)
    		{			
    			int num = getSum(segt, m, 0, query2[i].first);
    			int l=query2[i].second.first,r=query2[i].second.second;
    			updateValue(commands, segt, m, l,(commands[l]+ num)%mod);
    			if(query2[i].second.first!=m-1)
    			updateValue(commands, segt, m, r+1, (commands[r+1]- num)%mod);
    		}
    		//f(i,m)		cout<<commands[i]<<endl;
    		f(i,m-1)
    		{
    			commands[i+1]=(commands[i+1]+commands[i])%mod;
    		}
    		f(i,m)
    		{
    		    if(commands[i]<0)
    		    {
    		        commands[i]+=mod;
    		    }
    		}
    		//f(i,m)		cout<<commands[i]<<endl;
    		vector <long long> ans(n,0);
    		
    		f(i,query1.size())
    		{
    			int l=query1[i].second.first,r=query1[i].second.second;
    			int pos=query1[i].first;
    			ans[l]=(ans[l]+commands[pos])%mod;
    			if(r!=n-1)
    			{
    				ans[r+1]=(ans[r+1]-commands[pos])%mod;
    			}
    		//	int j;
    			//f(j,n)		cout<<ans[j]<<" ";cout<<endl;
    		}
    		f(i,n-1)
    		{
    			ans[i+1]=(ans[i+1]+ans[i])%mod;
    		}
    		f(i,n)
    		{
    		    if(ans[i]<0)
    		    {
    		        ans[i]+=mod;
    		    }
    		}
    		f(i,n)printf("%lld ",ans[i]);
    		cout<<endl;
    	}	
    	
    	return 0;
    } 