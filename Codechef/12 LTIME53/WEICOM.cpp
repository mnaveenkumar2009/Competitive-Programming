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
     
     #define ll long long
    vector <ll> ans(100,0);
    bool f3(ll n,ll k,vector <ll> a){
    	ll sum=0,i,sum2=0;
    	
    	f(i,n){
    		sum+=a[i]*a[i];
    		sum2+=a[i];
    		if(a[i]>n-1)return 0;
    	}
    	ll totc=n*(n-1);
    	totc/=2;
    	if(sum2!=totc)return 0;
    	if(sum==k)return 1;
    	return 0;
    }
    void f2(ll n,ll k,vector <ll> a,ll pos,ll val){
    	int i;
    	if(pos==n-1)
    	{
    	    //if(a[0]==1&&a[1]==2&&a[2]==2)cout<<val<<endl;
    	a[n-1]=val;
    		
    	if(f3(n,k,a)){
    		f(i,n)ans[i]=a[i];
    	}
    	
    	return	;
    	}
    	int j;
    	vector <ll> b[val+1];
    	f(i,val+1){
    		b[i].resize(n);
    	}
    	f(j,val+1)
    	f(i,pos)b[j][i]=a[i];
    	
    	f(i,val+1){
    		b[i][pos]=i;
    		f2(n,k,b[i],pos+1,val-i);
    	}
    	
    } 
     
    int main()
    {
    	int t=1;
    	cin>>t;
    	while(t--){
    	    int i;
    		long long k,n;
    		slld(n);slld(k);
    		
    		ll totc=n*(n-1);
    		totc/=2;
    		f(i,n)ans[i]=-1;
    		vector <ll> a(n,0);
    		f2(n,k,a,0,totc);
    		
    		//f(i,n)cout<<ans[i]<<" ";cout<<endl;
    		if(ans[0]==-1){
    		    printf("-1\n");
    		    continue;
    		}
    		//construct matrix
    		int answer[n][n],j;
    		f(i,n){
    			f(j,n)answer[i][j]=-1;
    		}
    		
    		for(i=n-1;i>=0;i--){
    			for(j=n-1;j>=0;j--){
    				if(j==i)answer[i][j]=0;
    				if(ans[i]){
    					if(j!=i&&answer[i][j]==-1){
    						answer[i][j]=1;
    						answer[j][i]=0;
    						ans[i]--;
    					}
    				}
    			}
    		}
    		
    		
    		f(i,n){
    			f(j,n){
    				printf("%d",answer[i][j]);
    			}printf("\n");
    		}
    	}
    	return 0;
    } 