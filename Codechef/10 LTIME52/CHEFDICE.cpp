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
    	int t,i;
    	cin>>t;
    	while(t--)
    	{
    		int n;
    	cin>>n;
    		bool we=1;
    		vector <int> a(n);
    		vector < vector <int> > adj(7, vector <int>(0));
    		int i;
    		f(i,n)
    		{
    			sd(a[i]);
    			a[i]--;
    			
    			if(i!=0)
    			{if(a[i]==a[i-1])we=0;
    				adj[a[i]].pb(a[i-1]);
    				adj[a[i-1]].pb(a[i]);
    			}
    		}
    		int j;
    		f(i,7){
    			sort(adj[i].begin(),adj[i].end());
    		}
    		bool ad[7][7];
    		f(i,7){
    			f(j,7)
    		if(binary_search(adj[i].begin(), adj[i].end(), j)){
    			ad[i][j]=1;
    		}
    		else
    		ad[i][j]=0;
    		}
    		f(i,6)ad[i][i]=1;
    		//f(i,6){			f(j,6)cout<<ad[i][j]<<" ";cout<<endl;		}
    		int ans[6];
    		f(i,6)ans[i]=-1;
    		while(1){
    			int loop=6;
    			while(loop--){
    				//f(i,6){			f(j,6)cout<<ad[i][j]<<" ";cout<<endl;		}cout<<endl;
    					f(i,6)
    					{
    					int count=0;
    					int y=0;
    					f(j,6)if(ad[i][j]==0){
    						count++;y=j;
    					}
    					if(count==2||count==3){
    						f(j,6){
    							int jj;
    							f(jj,6){
    								if(jj!=i&&j!=i){
    									if(ad[i][j]&&ad[i][jj]&&ans[j]!=jj&&ans[j]!=-1){
    										ad[j][jj]=1;
    										ad[jj][j]=1;
    									}
    								}
    							}
    						}
    					}
    					if(count==1)
    					{
    					//	cout<<count<<endl;
    						ans[i]=y;
    						ans[y]=i;
    							f(j,6)
    						if(j!=i){	ad[j][y]=1;ad[y][j]=1;			}
    					}
    					if(count==0)we=0;			
    					}
    				}
    		
    		bool ii=1;
    		f(i,6)if(ans[i]==-1){ii=0;
    							bool che=0;
    				f(i,6)
    				{	
    					f(j,6)
    					{
    						if(ad[i][j]&&ans[i]==-1)
    						{
    							int jj;
    							f(jj,6){
    								if(ad[j][jj]&&!ad[i][jj])
    								{
    							//	cout<<i<<j<<jj<<endl;
    									ans[i]=jj;
    									ans[jj]=i;
    									int uf;
    									f(uf,6)
    										if(uf!=i&&ad[i][uf]){	ad[jj][uf]=1;ad[uf][jj]=1;			}
    									che=1;
    									break;
    								}
    							}
    							if(che)break;
    						}
    					}
    					if(che)break;
    				}
    				if(!che)
    				{
    					f(i,6){
    						if(ans[i]==-1)
    						f(j,6){
    							if(!ad[i][j]){
    								ad[i][j]=1;
    								ad[j][i]=1;
    								che=1;
    								break;
    							}
    						}
    						if(che)break;
    					}
    				}
    				break;
    			}
    		if(ii)break;
    		if(!we)break;
    		}
    		
    		if(we)
    		{
    			f(i,6)cout<<ans[i]+1<<" ";
    			cout<<endl;
    		}
    		else
    		{
    			printf("-1\n");
    		}
    	}
    } 