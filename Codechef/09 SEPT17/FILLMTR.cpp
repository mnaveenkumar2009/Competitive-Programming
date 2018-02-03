    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
    vector <int> opair(100007),check(100007);
     
    bool we=1;
    class Graph
    {
        int V;
        list<int> *adj;
        list<int> *adj2;
        void DFSUtil(int v, bool visited[],bool value); 
    public:
        
        Graph(int V);   
        void addEdge(int v, int w);  
        void addEdge2(int v, int w);
        void DFS(); 
    };
     
    Graph::Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
        adj2 = new list<int>[V];
    }
     
    void Graph::addEdge(int v, int w)
    {
        adj[v].push_back(w); 
    }
    void Graph::addEdge2(int v, int w)
    {
        adj2[v].push_back(w); 
    }
    void Graph::DFSUtil(int v, bool visited[],bool value)
    {
        visited[v] = true;
        if(check[v]==-1)
        {
        	check[v]=value;
    	}
    	else
    	{
    		if(value!=check[v])we=0;
    	}
        list<int>::iterator i;
        for(i = adj2[v].begin(); i != adj2[v].end(); ++i)
            if(!visited[*i])
                DFSUtil(*i, visited,!value);
            else
            {
                    if(check[*i]!=(!value))we=0;
                
            }    
            
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
            if(!visited[*i])
                DFSUtil(*i, visited,value);   
                 else
            {
                    if(check[*i]!=(value))
                    {we=0;
                    //cout<<v<<" "<<*i<<endl;
                        
                    }
            }    
    } 
    void Graph::DFS()
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
        { 
            DFSUtil(i, visited,0);
        }
    }
    int main()
    {
    	int t;
    	sd(t);
    	while(t--)
    	{	we=1;
    	
    		int n,q,i;
    		sd(n);sd(q);
    		Graph g(n);
    		f(i,n)
            {
            opair[i]=i;
        	check[i]=-1;
    		}
        	//DFS on 0's
        	while(q--)
        	{
        		int l,r,val;
        		sd(l);
        		sd(r);
        		l--;
        		r--;
        		int uuu=1;
        		l = l*uuu;
        		sd(val);
        		if(val==0)
        		{
        			g.addEdge(l, r);
        			g.addEdge(r, l);
    			}
    			else
    			{
    				g.addEdge2(l, r);
    				g.addEdge2(r, l);
    			}
    		}
    		g.DFS();
    		//f(i,n)		{		    cout<<check[i]<<endl;		}
    		if(we)
    		{
    			printf("yes\n");
    		}
    		else
    		{
    			printf("no\n");
    		}
    	}
    	return 0;
    } 