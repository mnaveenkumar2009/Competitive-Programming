//11 points solution
    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    //#define mod 1000000007
    #define mp make_pair
    #define ll unsigned long long 
     
    int getMid(int s, int e) {  return s + (e -s)/2;  }
    ll getSumUtil(ll *st, int ss, int se, int qs, int qe, int si)
    {
        if (qs <= ss && qe >= se)
            return st[si];
        if (se < qs || ss > qe)
            return 0;
        int mid = getMid(ss, se);
        return (getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
               getSumUtil(st, mid+1, se, qs, qe, 2*si+2));
    }
     
    void updateValueUtil(ll *st, int ss, int se, int i, ll diff, int si)
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
    void updateValue(ll arr[], ll *st, int n, int i, ll new_val)
    {
        ll diff = new_val - arr[i];
     
        arr[i] = new_val;
        updateValueUtil(st, 0, n-1, i, diff, 0);
    }
    ll getSum(ll *st, int n, int qs, int qe)
    {
     
        return getSumUtil(st, 0, n-1, qs, qe, 0);
    }
     
    ll constructSTUtil(ll arr[], int ss, int se, ll *st, int si)
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
     
    ll *constructST(ll arr[], int n)
    {
        int x = (int)(ceil(log2(n))); 
        int max_size = 2*(int)pow(2, x) - 1; 
        ll *st = new ll[max_size];
        constructSTUtil(arr, 0, n-1, st, 0);
        return st;
    }
    int main()
    {
    	int m,n,q;
    	cin>>m>>n>>q;
    	//cout<<m<<n<<q<<endl;
    	int i;
    	long long a[n+2];
    	ll b[n],b2[n];
    	f(i,n)b[i]=b2[i]=0;
    	f(i,n-1)
    	{   
    	    slld(a[i]);
    	    //cout<<a[i]<<endl;
    	}
    	ll *st = constructST(b, n);
    	ll *st2 = constructST(b2, n);
    	while(q--)
    	{
    	   // f(i,n)	{	    cout<<b[i]<<" "	;}cout<<endl;
    	    //f(i,n)	{	    cout<<b2[i]<<" ";	}cout<<endl;
    	    int que;
    	    sd(que);
    	    //cout<<que<<endl;
    	    if(que==1)
    	    {
    	        int i1,i2,j1,j2;
    	        sd(i1);sd(j1);sd(i2);sd(j2);
    	        j1--;
    	        j2--;
    	        if(j1>j2)
    	        {
    	            int t=j1;
    	            j1=j2;
    	            j2=t;
    	        }
    	        ll c;
    	        cin>>c;
    	        updateValue(b, st, n, j1,(b[j1]+ c));
    	        if(j2+1<n)
    	        updateValue(b2, st2, n, j2+1,(b2[j2+1]+ c));
    	    }
    	    else
    	    {
    	        int i1,j2;
    	        sd(i1);
    	        sd(j2);
    	        cout<<getSum(st, n, 0, j2-1)-getSum(st2, n, 0, j2-1)<<endl;
    	    }
    	}
    	//ll o = 100000 * 10000000000000;
    	//cout<<o;
    	return 0;
    } 