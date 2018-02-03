    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
    vector <int> totdist(200008,0);
    int f2(int i,int j,int sum){
        if(i==j)return 0;
        
        int fir=min(i,j);
        int sec=max(i,j);
        int ans=0;
        if(fir==0){
            ans=totdist[sec-1];
        }
        else
        {
            ans=totdist[sec-1]-totdist[fir-1];
        }
        return min(sum-ans,ans);
    }
     
    int main()
    {
    	int t=1;
    	cin>>t;
    	while(t--){
    	    int n,q;
    	    sd(n);sd(q);
    	    int aa[n][2];
    	    int dist[n][2];
    	    vector < vector <pair < int,pair<int,int> > > > a(n, vector <pair < int,pair<int,int> > >(0));
    	    int i,j;
    	    f(i,2*n)totdist[i]=0;
    	    f(i,n){
    	        int h;
    	        sd(h);
    	        f(j,h){
    	            int g;
    	            sd(g);
    	            a[i].pb(mp(g,mp(0,0)));
    	        }
    	    }
    	    f(i,n){
    	        int v1,v2,w;
    	        sd(v1);sd(v2);sd(w);
    	        v1--;v2--;
    	        aa[i][1]=v1;
    	        aa[(i+1)%n][0]=v2;
    	        dist[i][1]=w;
    	        
    	    }
    	   // f(i,n)cout<<aa[i][0]<<" "<<aa[i][1]<<endl;
    	    f(i,n){
    	        int sum=0,sum2=0;
    	        int sizz=a[i].size();
    	        
    	        f(j,sizz)sum+=a[i][j].first;
    	        
    	        int g=aa[i][0];
    	        int h=aa[i][1];
    	        //cout<<g<<h<<endl;
    	        for(j=g;j%sizz!=h;j++){
    	            sum2+=a[i][j%sizz].first;
    	        }
    	        dist[i][0]=min(sum2,sum-sum2);
    	        sum2=a[i][g].first;
    	        for(j=(g+1)%sizz;j%sizz!=g;j++){
    	            a[i][j%sizz].second.first=min(sum2,sum-sum2);
    	            sum2+=a[i][j%sizz].first;
    	        }
    	        sum2=a[i][h].first;
    	        for(j=(h+1)%sizz;j%sizz!=h;j++){
    	            a[i][j%sizz].second.second=min(sum2,sum-sum2);
    	            sum2+=a[i][j%sizz].first;
    	        }
    	       // cout<<sum<<endl;
    	    }
    	    int sum=0;
    	    
    	    f(i,2*n){
    	        sum+=dist[i/2][i%2];
    	        if(i)totdist[i]=totdist[i-1];
    	        totdist[i]+=dist[i/2][i%2];
    	    }
    	    /*
    	    f(i,n){
    	        cout<<aa[i][0]<<" "<<aa[i][1]<<" "<<dist[i][0]<<" "<<dist[i][1]<<endl;
    	        f(j,a[i].size())cout<<a[i][j].first<<" "<<a[i][j].second.first<<" "<<a[i][j].second.second<<endl;cout<<endl;
    	    }
    	    */
    	    //cout<<q<<endl;
    	    //f(i,2*n)cout<<totdist[i]<<" ";cout<<endl;
    	    while(q--){
    	        int c1,c2,v1,v2;
    	        sd(v1);sd(c1);sd(v2);sd(c2);
    	        c1--;c2--;v1--;v2--;
    	        int ans1=a[c1][v1].second.first+a[c2][v2].second.first;
    	        int ans2=a[c1][v1].second.first+a[c2][v2].second.second;
    	        int ans3=a[c1][v1].second.second+a[c2][v2].second.first;
    	        int ans4=a[c1][v1].second.second+a[c2][v2].second.second;
    	        
    	        //cout<<ans1<<ans2<<ans3<<ans4<<endl;
    	        
    	        ans2+=f2(c1*2,c2*2+1,sum);
    	        ans3+=f2(c1*2+1,c2*2,sum);
    	        ans1+=f2(c1*2,c2*2,sum);
    	        ans4+=f2(c1*2+1,c2*2+1,sum);
    	       // cout<<ans1<<ans2<<ans3<<ans4<<endl;
    	        printf("%d\n",min(min(ans1,ans2),min(ans3,ans4)));
    	    }
    	}
    	return 0;
    } 