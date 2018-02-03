//20 points solution
    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
    #define ff first
    #define ss second
    #define ll long long
    #define MAX 10000000
    using namespace std;
    int maxi,maxi2,a[100000];
    class Graph
    {
        int V;
        list<int> *adj;
        void DFSUtil(int v, bool visited[],bool x);
    public:
        Graph(int V);   // Constructor
     
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
    }
     
    void Graph::DFSUtil(int v, bool visited[],bool x)
    {
        
        visited[v] = true;
        //cout<<v<<' ';
        
        if(a[v]){
            x=1;
        }
        if(x){
            if(v>maxi){
                maxi2=maxi;
                maxi=v;
            }
            else
            {
                if(v>maxi2)maxi2=v;
            }
        }
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i, visited,x);
    }
     
     
    void Graph::DFS(int v)
    {
        
        bool *visited = new bool[V];
        bool x=0;
        for (int i = 0; i < V; i++)
            visited[i] = false;
        DFSUtil(v, visited,x);
    }
    int main()
    {   
        int t;
        sd(t);
        while(t--){
            int i;
            int n,m;
            sd(n);
            sd(m);
            Graph g(n+5);
            f(i,n+5)a[i]=0;
            f(i,n-1){
                int u,v;
                sd(u);
                sd(v);
                u--;v--;
                g.addEdge(u,v);
                g.addEdge(v,u);
            }
            
            while(m--){
                int xxx,c;
                sd(xxx);
                sd(c);
                if(xxx==1){
                    a[c-1]=1;
                }
                else
                {
                    maxi=-2;
                    maxi2=-2;
                    g.DFS(c-1);
                    printf("%d\n",maxi2+1);
                }
            }
        }
     
        return 0;
    }  