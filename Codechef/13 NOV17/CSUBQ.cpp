    #include <bits/stdc++.h>
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
    #define ll long
    #define MAX 10000000 
    #define getsum getSum
    #define getsum2 getSum2
    ll tree[MAX] = {0};
    ll lazy[MAX] = {0}; 
    ll tree2[MAX] = {0};
    ll lazy2[MAX] = {0}; 
     
    void updateRangeUtil(int si, int ss, int se, int us,
                         int ue, ll diff)
    {
        if (lazy[si] != 0)
        {
            tree[si] += (se-ss+1)*lazy[si];
            if (ss != se)
            {
                lazy[si*2 + 1]   += lazy[si];
                lazy[si*2 + 2]   += lazy[si];
            }
     
            lazy[si] = 0;
        }
        if (ss>se || ss>ue || se<us)
            return ;
     
        if (ss>=us && se<=ue)
        {
            tree[si] += (se-ss+1)*diff;
     
            if (ss != se)
            {
                lazy[si*2 + 1]   += diff;
                lazy[si*2 + 2]   += diff;
            }
            return;
        }
        int mid = (ss+se)/2;
        updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
        updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
        tree[si] = tree[si*2+1] + tree[si*2+2];
    }
    void updateRangeUtil2(int si, int ss, int se, int us,
                         int ue, ll diff)
    {
        if (lazy2[si] != 0)
        {
            tree2[si] += (se-ss+1)*lazy2[si];
            if (ss != se)
            {
                lazy2[si*2 + 1]   += lazy2[si];
                lazy2[si*2 + 2]   += lazy2[si];
            }
     
            lazy2[si] = 0;
        }
        if (ss>se || ss>ue || se<us)
            return ;
     
        if (ss>=us && se<=ue)
        {
            tree2[si] += ((ll)(se-ss+1))*diff;
     
            if (ss != se)
            {
                lazy2[si*2 + 1]   += diff;
                lazy2[si*2 + 2]   += diff;
            }
            return;
        }
        int mid = (ss+se)/2;
        updateRangeUtil2(si*2+1, ss, mid, us, ue, diff);
        updateRangeUtil2(si*2+2, mid+1, se, us, ue, diff);
        tree2[si] = tree2[si*2+1] + tree2[si*2+2];
    }
      
    void updateRange(int n, int us, int ue, ll diff)
    {
       updateRangeUtil(0, 0, n-1, us, ue, diff);
    }
    void updateRange2(int n, int us, int ue, ll diff)
    {
       updateRangeUtil2(0, 0, n-1, us, ue, diff);
    }
     
    ll getSumUtil(int ss, int se, int qs, int qe, int si)
    {
      
        if (lazy[si] != 0)
        {
            tree[si] += ((ll)(se-ss+1))*lazy[si];
            if (ss != se)
            {
                lazy[si*2+1] += lazy[si];
                lazy[si*2+2] += lazy[si];
            }
            lazy[si] = 0;
        }
     
        if (ss>se || ss>qe || se<qs)
            return 0;
     
        if (ss>=qs && se<=qe)
            return tree[si];
     
        int mid = (ss + se)/2;
        return getSumUtil(ss, mid, qs, qe, 2*si+1) +
               getSumUtil(mid+1, se, qs, qe, 2*si+2);
    }
    ll getSum(int n, int qs, int qe)
    {
        return getSumUtil(0, n-1, qs, qe, 0);
    }
     
    ll getSumUtil2(int ss, int se, int qs, int qe, int si)
    {
      
        if (lazy2[si] != 0)
        {
            tree2[si] += ((ll)(se-ss+1))*lazy2[si];
            if (ss != se)
            {
                lazy2[si*2+1] += lazy2[si];
                lazy2[si*2+2] += lazy2[si];
            }
            lazy2[si] = 0;
        }
     
        if (ss>se || ss>qe || se<qs)
            return 0;
     
        if (ss>=qs && se<=qe)
            return tree2[si];
     
        int mid = (ss + se)/2;
        return getSumUtil2(ss, mid, qs, qe, 2*si+1) +
               getSumUtil2(mid+1, se, qs, qe, 2*si+2);
    }
    ll getSum2(int n, int qs, int qe)
    {
        return getSumUtil2(0, n-1, qs, qe, 0);
    }
     
    void constructSTUtil(ll arr[], int ss, int se, int si)
    {
        
        if (ss > se)
            return ;
        if (ss == se)
        {
            tree[si] = arr[ss];
            return;
        }
        
        int mid = (ss + se)/2;
        constructSTUtil(arr, ss, mid, si*2+1);
        constructSTUtil(arr, mid+1, se, si*2+2);
     
        tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
    }
     
    void constructST(ll arr[], int n)
    {
        constructSTUtil(arr, 0, n-1, 0);
    }
     
    void constructSTUtil2(ll arr[], int ss, int se, int si)
    {
        
        if (ss > se)
            return ;
        if (ss == se)
        {
            tree2[si] = arr[ss];
            return;
        }
        
        int mid = (ss + se)/2;
        constructSTUtil(arr, ss, mid, si*2+1);
        constructSTUtil(arr, mid+1, se, si*2+2);
     
        tree2[si] = tree2[si*2 + 1] + tree2[si*2 + 2];
    }
     
    void constructST2(ll arr[], int n)
    {
        constructSTUtil2(arr, 0, n-1, 0);
    }
    #include <time.h>
    int main()
    {
        
    	    int c1=0,c2=0,c1c=0,c2c=0;
    	    int n=sscan(),q=sscan();
    	    ll L,R;
    	    slld(L);
    	    slld(R);
    	    ll a[n],b[n];
    	    int i;
    	    
    	    set <int> aa,bb;
    	    set <int>::iterator it,itt;
    	    f(i,n)a[i]=b[i]=0;
    	    constructST(a, n);constructST2(b, n);
    	    if(q<=100000)
    	    while(q--){
    	        int qq=sscan();
    	        if(qq==1)
    	        {  // c1+=clock()-c2c;
    	           //c1c=clock();
    	            int x=sscan();
    	            ll y=uscan();
    	            x--;
    	            int h=0;
    	            if(y>R)h=2;
    	            else
    	            {
    	                if(y>=L)h=1;
    	            }
    	            if(h==a[x])continue;
    	            
    	            int lll,rrr;
    	            ll val;
    	            
    	            it=aa.lower_bound(x);
    	            itt=bb.lower_bound(x);
    	            if(a[x]&&h==0){
    	                lll=x;rrr=n-1;
    	                val=0;
    	                ++it;
                        if(it!=aa.end()){
                            rrr=(*(it))-1;
                        }
                        --it;
                    
                        ll sass=*it;
                    
                    if(it!=aa.begin())
    	                updateRangeUtil(0, 0, n-1, lll, rrr, *(--it)-sass);
    	            else
    	                updateRangeUtil(0, 0, n-1, lll, rrr, -sass);
    	            
    	            if(*it!=sass)it++;
    	            aa.erase (it);    
    	            
    	            
    	            }
    	            if(a[x]==2){
    	            lll=x;rrr=n-1;
    	            
    	            
    	                
    	            ++itt;
                    if(itt!=bb.end()){
                        
                        rrr=(*(itt))-1;
                        
                    }
                    --itt;
                    ll sass=*itt;
                    
                    if(itt!=bb.begin())
    	            updateRangeUtil2(0, 0, n-1, lll, rrr, *(--itt)-sass);
    	            else
    	            updateRangeUtil2(0, 0, n-1, lll, rrr, -(sass));
    	            
    	            if(*itt!=sass)itt++;
    	            bb.erase (itt); 
    	            
    	            }
    	            
    	            
    	            if(h&&a[x]==0)
    	            {
    	                
    	                rrr=n-1;
    	                if(it!=aa.end()){
    	                    rrr= *(it)-1;
    	                }
    	                
    	                if(it!=aa.begin())
    	                updateRangeUtil(0, 0, n-1, x, rrr, x-*(--it));
    	                else
    	                updateRangeUtil(0, 0, n-1, x, rrr, x+1);
    	                aa.insert(x);
    	            }
    	           // cout<<x<<" "<<(getsum(n,x,x))<<endl;
    	            if(h==2){
    	                rrr=n-1;
    	                if(itt!=bb.end()){
    	                    rrr= *(itt)-1;
    	                }
    	                if(itt!=bb.begin())
    	                updateRangeUtil2(0, 0, n-1, x, rrr, x-*(--itt));
    	                else
    	                updateRangeUtil2(0, 0, n-1, x, rrr, x+1);
    	                
    	                bb.insert(x);
    	            }
    	            a[x]=h;    
    	        }
    	        else
    	        {
    	            //c2+=clock()-c1c;
    	            //c2c=clock();
    	            int l=sscan(),r=sscan();
    	            l--;r--;
    	            ll ans=0;
    	            set <int>::iterator it2=aa.lower_bound(l);
    	            set <int>::iterator it3=bb.lower_bound(l);
    	            if(it2!=aa.end())
    	            if(*it2<=r)
    	            ans+=getSum(n, *it2, r);
    	            if(it3!=bb.end())
    	            if(*it3<=r)
    	            ans-=getSum2(n, *it3, r);
    	            
    	            if(it2!=aa.end())
    	            if(*it2<=r)
    	            ans-=((ll)l)*((ll)(r+1-(*it2)));
    	            if(it3!=bb.end())
    	            if(*it3<=r)
    	            ans+=((ll)l)*((ll)(r+1-(*it3)));
    	            printf("%lld\n",ans);
    	        }
                  
    	    }
    	    else
    	    while(q--){
    	        int qq=sscan();
    	        if(qq==1)
    	        {  
    	            
    	            int x=sscan();
    	            ll y=uscan();
    	            x--;
    	            int h=0;
    	            if(y>R)h=2;
    	            else
    	            {
    	                if(y>=L)h=1;
    	            }
    	            if(h==a[x])continue;
    	            
    	            int lll,rrr;
    	            ll val;
    	            
    	            it=aa.lower_bound(x);
    	            itt=bb.lower_bound(x);
    	            if(a[x]&&h==0){
    	                lll=x;rrr=n-1;
    	                val=0;
    	                ++it;
                        if(it!=aa.end()){
                            rrr=(*(it))-1;
                        }
                        --it;
                    
                        ll sass=*it;
                    
                    if(it!=aa.begin())
    	                updateRangeUtil(0, 0, n-1, lll, rrr, *(--it)-sass);
    	            else
    	                updateRangeUtil(0, 0, n-1, lll, rrr, -sass);
    	            
    	            if(*it!=sass)it++;
    	            aa.erase (it);    
    	            
    	            
    	            }
    	            if(a[x]==2){
    	            lll=x;rrr=n-1;
    	            
    	            
    	                
    	            ++itt;
                    if(itt!=bb.end()){
                        
                        rrr=(*(itt))-1;
                        
                    }
                    --itt;
                    ll sass=*itt;
                    
                    if(itt!=bb.begin())
    	            updateRangeUtil(0, 0, n-1, lll, rrr, sass-(*(--itt)) );
    	            else
    	            updateRangeUtil(0, 0, n-1, lll, rrr, (sass));
    	            
    	            if(*itt!=sass)itt++;
    	            bb.erase (itt); 
    	            
    	            }
    	            
    	            
    	            if(h&&a[x]==0)
    	            {
    	                
    	                rrr=n-1;
    	                if(it!=aa.end()){
    	                    rrr= *(it)-1;
    	                }
    	                
    	                if(it!=aa.begin())
    	                updateRangeUtil(0, 0, n-1, x, rrr, x-*(--it));
    	                else
    	                updateRangeUtil(0, 0, n-1, x, rrr, x+1);
    	                
    	                aa.insert(x);
    	            }
    	           // cout<<x<<" "<<(getsum(n,x,x))<<endl;
    	            if(h==2){
    	                rrr=n-1;
    	                if(itt!=bb.end()){
    	                    rrr= *(itt)-1;
    	                }
    	                if(itt!=bb.begin())
    	                updateRangeUtil(0, 0, n-1, x, rrr, *(--itt)-x);
    	                else
    	                updateRangeUtil(0, 0, n-1, x, rrr, -(x+1) );
    	                
    	                bb.insert(x);
    	            }
    	            a[x]=h;    
    	        }
    	        else
    	        {
    	           
    	            int l=sscan(),r=sscan();
    	            l--;r--;
    	            ll ans=0;
    	            set <int>::iterator it2=aa.lower_bound(l);
    	            set <int>::iterator it3=bb.lower_bound(l),it4;
    	            
    	            
    	            if(it2!=aa.end())
    	            if(*it2<=r)
    	            ans+=getSum(n, *it2, r);
    	            /*if(it3!=bb.end())
    	            if(*it3<=r)
    	            ans-=getSum2(n, *it3, r);*/
    	            if(it2!=aa.end())
    	            if(*it2<=r)
    	            if(it3!=bb.begin()){
    	                it4=--it3;
    	                it3++;
    	              ans+=  ((ll)( min(*it3,r+1)-*it2))*((ll)(*it4+1));
    	            }
    	            
    	            if(it2!=aa.end())
    	            if(*it2<=r)
    	            ans-=((ll)l)*((ll)(r+1-(*it2)));
    	            if(it3!=bb.end())
    	            if(*it3<=r)
    	            ans+=((ll)l)*((ll)(r+1-(*it3)));
    	            printf("%lld\n",ans);
    	        }
                  
    	    }
                  
    	    
    	
    	return 0;
    } 