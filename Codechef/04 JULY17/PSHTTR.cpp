   //30 points solution
    #include<bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back 
    using namespace std;
     vector <int> p;
     class Graph
    {
        int V;   
        list<int> *adj; // Pointer to an array containing adjacency lists
     
        // A recursive function used by printAllPaths()
        void printAllPathsUtil(int , int , bool [], int [], int &);
     
    public:
        Graph(int V);   // Constructor
        void addEdge(int u, int v);
        void printAllPaths(int s, int d);
    };
     
    Graph::Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
     
    void Graph::addEdge(int u, int v)
    {
        adj[u].push_back(v); // Add v to uâ��s list.
    }
     
    // Prints all paths from 's' to 'd'
    void Graph::printAllPaths(int s, int d)
    {
        // Mark all the vertices as not visited
        bool *visited = new bool[V];
     
        // Create an array to store paths
        int *path = new int[V];
        int path_index = 0; // Initialize path[] as empty
     
        // Initialize all vertices as not visited
        for (int i = 0; i < V; i++)
            visited[i] = false;
     
        // Call the recursive helper function to print all paths
        printAllPathsUtil(s, d, visited, path, path_index);
    }
     
    // A recursive function to print all paths from 'u' to 'd'.
    // visited[] keeps track of vertices in current path.
    // path[] stores actual vertices and path_index is current
    // index in path[]
    void Graph::printAllPathsUtil(int u, int d, bool visited[],
                                  int path[], int &path_index)
    {
        // Mark the current node and store it in path[]
        visited[u] = true;
        path[path_index] = u;
        path_index++;
     
        // If current vertex is same as destination, then print
        // current path[]
        if (u == d)
        {
            for (int i = 0; i<path_index; i++)
                p.pb(path[i]);
            
        }
        else // If current vertex is not destination
        {
            // Recur for all the vertices adjacent to current vertex
            list<int>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (!visited[*i])
                    printAllPathsUtil(*i, d, visited, path, path_index);
        }
     
        path_index--;
        visited[u] = false;
    }
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        { int n,m,i,u,v;
            scanf("%d",&n);
            long long a[n+5][n+5],b;
            Graph g(n+5);
            f(i,n-1)
            {
                scanf("%d%d%lld",&u,&v,&b);
                a[u][v]=b;
                a[v][u]=b;
                g.addEdge(u,v);
                g.addEdge(v,u);
            }
            scanf("%d",&m);
            while(m--)
            {   p.erase(p.begin(),p.end());
                scanf("%d%d%lld",&u,&v,&b);
                long long xo=0;
                g.printAllPaths(u,v);
                f(i,p.size()-1)
                {
                    if(a[p[i]][p[i+1]]<=b)
                    {
                        xo = xo ^ a[p[i]][p[i+1]];
                    }
                }
                printf("%lld\n",xo);
            }
            
        }
     
        return 0;
    } 