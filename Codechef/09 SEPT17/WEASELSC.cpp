//10 points solution
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
    		cin>>t;
    		while(t--)
    		{
    		    int n,k,j,i;
    		    cin>>n>>k;
    		    vector <int> a(n);
    		    vector < vector <int> > value(100009, vector <int> (0));
    		    f(i,n)
    		    {
    		        sd(a[i]);
    		        value[a[i]].pb(i);
    		    }
    		    set <int> v;
    		    v.insert(-1);
    		    v.insert(n);
    		    set<int>::iterator itlow,itup;
    		    
    		    long long maxi=0;
    		    f(i,100003)
    		    {
    		        int siz=value[i].size();
    		        f(j,siz)
    		        {
    		            itlow=v.lower_bound (value[i][j]);
                        itup=v.lower_bound (value[i][j]);
                      
                        //cout<<*itup<<" "<<*itlow<<" "<<value[i][j]<<" "<<i<<endl;
                        if(itlow!=v.begin())
                        {
                            itlow--;
                        }
                        long long diff= *itup - *itlow -1 ;
                        //cout<<diff<<endl;
                        long long nnn = i;
                        maxi= max(maxi, nnn*diff);
    		        }
    		        f(j,siz){
    		            v.insert(value[i][j]);
    		        }
    		    }
    		    cout<<maxi<<endl;
    		}
    	return 0;
    } 