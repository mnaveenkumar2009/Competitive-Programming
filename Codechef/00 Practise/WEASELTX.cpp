    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
     
    vector <long long> depthxor(262144+2,0),initxor(262144+2,0);
    vector < vector <long long> > answer(262144+2 , vector <long long> (0,0)); 
    int maxdepth=0;
     
     
    class Graph
    {
        int V;
        list<int> *adj;   
        void DFSUtil(int v, bool visited[],int depth); 
    public:
        Graph(int V);
        void addEdge(int v, int w);  
        void DFS(int v);  
    };
     
    Graph::Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
     
    void Graph::addEdge(int v, int w)
    {
        adj[v].push_back(w); 
        adj[w].pb(v);
    }
     
    void Graph::DFSUtil(int v, bool visited[], int depth)
    {
    	maxdepth=max(depth,maxdepth);
        visited[v] = true;
        depthxor[depth]=initxor[v]^depthxor[depth];
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i, visited,depth+1);
    }
     
    void Graph::DFS(int v)
    {
    	
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        DFSUtil(v, visited,0);
    }
     
     
    long long ans(long long k)
    {	
        return (answer[262144-k][0]);
    }
    int main()
    {
    		int n,q;
    		sd(n);
    		sd(q);
    		Graph g(n+2);
    		int i,u,v;
    		int ugh=0;
    		ugh++;
    		f(i,n-1)
    		{
    			sd(u);
    			sd(v);
    			g.addEdge(u,v);
    		}
    		//cout<<"r";
    		f(i,n)
    		{
    			slld(initxor[i]);
    		}
    		
    		g.DFS(0);
    		long long rrr=0; 
    		answer[0].resize(262144);
    		f(i,262144)
    		{
    		    int u=log2(i+1);
    		    answer[i+1].resize(262144/(1<<(u+1)));
    		    //rrr+=answer[i].size();
    		}
    		//cout<<rrr<<endl;
    		f(i,n)
    		{
    		    answer[0][i]=depthxor[i];
    		}
    	//	cout<<endl;
    		//f(i,10)		{			cout<<answer[i].size()<<endl;		}
    		f(i,262144/2)
    		{
    		    answer[1][i]=answer[0][i*2]^answer[0][i*2 + 1];
    		}
    		for(i=2;i<=262144;i++)
    		{
    		    int anssize=answer[i].size();
    		    int dist,j;
    		    for(dist=20;dist>=0;dist--)
    		    {
    		        if(i&(1<<dist))break;
    		    }
    		    dist= (1<<dist);
    		    int dist2=dist;
    		    dist = i-dist;
    		    if(!dist)
    		    {
    		        f(j,anssize)
    		        {
    		            answer[i][j]= answer[0][j*2*dist2] ^ answer[0][j*2*dist2+dist2];
    		        }
    		        continue;
    		    }
    		    //if(i<64)
    		    //cout<<i<<" "<<dist<<" "<<dist2<<endl;
    /*
    mask
     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 
     1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1 
     0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0  1  0 
     0  1  1  0  0  1  1  0  0  1  1  0  0  1  1  0  0  1  1  0  0  1  1  0  0  1  1  0  0  1  1  0  0 
     0  1  0  0  0  1  0  0  0  1  0  0  0  1  0  0  0  1  0  0  0  1  0  0  0  1  0  0  0  1  0  0  0 
     0  1  1  1  1  0  0  0  0  1  1  1  1  0  0  0  0  1  1  1  1  0  0  0  0  1  1  1  1  0  0  0  0 
     0  1  0  1  0  0  0  0  0  1  0  1  0  0  0  0  0  1  0  1  0  0  0  0  0  1  0  1  0  0  0  0  0 
     0  1  1  0  0  0  0  0  0  1  1  0  0  0  0  0  0  1  1  0  0  0  0  0  0  1  1  0  0  0  0  0  0 
     0  1  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0 
     0  1  1  1  1  1  1  1  1  0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  0  0  0  0  0  0  0  0 
     0  1  0  1  0  1  0  1  0  0  0  0  0  0  0  0  0  1  0  1  0  1  0  1  0  0  0  0  0  0  0  0  0 
     0  1  1  0  0  1  1  0  0  0  0  0  0  0  0  0  0  1  1  0  0  1  1  0  0  0  0  0  0  0  0  0  0 
     0  1  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0 
     0  1  1  1  1  0  0  0  0  0  0  0  0  0  0  0  0  1  1  1  1  0  0  0  0  0  0  0  0  0  0  0  0 
     0  1  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0 
     0  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
     0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
     */
                //if(i==1)cout<<"er"<<" "<<dist<<" "<<dist2<<endl;
    		    f(j,anssize)
    		    {
    		        int diff = answer[i-dist2].size() /(2*answer[i].size());
    		        //if(i==3&&j==0)cout<<diff<<"xs"<<endl;
    		        answer[i][j]= answer[i-dist2][j*2*diff]^answer[i-dist2][j*2*diff + diff];
    		    }
    		}
    	//	f(i,64)		{		    cout<<answer[i][0]<<endl;		}
    	//cout<<answer[0][0]<<endl;
            //cout<<endl;
            answer[262144].pb(depthxor[0]);
            while(q--)
    		{
    			long long k;
    			slld(k);
    			printf("%lld\n",ans(k%262144));
    		}
    	return 0;
    } 