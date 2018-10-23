#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
inline ll uscan()
{
    ll n=0,c=gc();
    bool check=0;
    if(c=='-')check=1;
    while(c<'0'||c>'9')
    {
        c=gc();
        if(c=='-')check=1;
    }
    while(c<='9'&&c>='0'){
        n=n*10+c-'0';
        c=gc();
    }
    return n+(-2*check*n);
}  
#define sc uscan()
#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000.000000
#define ld long double
using namespace std;
bool bellmanford(vector<pair<pair<ll,ll>,ld> > edges,int source,int ver,int edge)
{
    ld dist[100000];
    for(int i=0;i<=ver;++i)
        dist[i]=-inf;
    dist[source]=0;
    for (int i = 1; i <= ver; i++){
        for (int j = 0; j < edge; j++){
            int u = edges[j].first.first;
            int v = edges[j].first.second;
            ld weight = edges[j].second;
            if (dist[u] != -inf && (ld)dist[u]+weight > (ld)dist[v])
                dist[v] = (ld)dist[u] + (ld)weight; 
        }
    }
    
    for (int i = 0; i< edge; i++){ 
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        ld weight = edges[i].second;
        if (dist[u] != -inf && dist[u]+weight > dist[v]){
            return 0;
        }
    }
    // for(int i=1;i<=ver;++i)
    //     cout<<dist[i]<<" ";
    return 1;
    
}
int main()
{
    int n;
    cin>>n;
    int cnt=1;
    while(n)
    {
        string s;
        map<string,int> m;
        for(int i=0;i<n;++i){
            cin>>s; 
            m[s]=i+1;
        }
        int num;
        cin>>num;
        string s1,s2;
        ld r;
        vector<pair<pair<ll,ll>,ld> > edges;
        ll nn=0;
        bool we=0;
        for(int i=0;i<num;++i)
        {
            cin>>s1>>r>>s2;
            // cout<<s1<<' '<<r<<' '<<s2<<'\n';
            if(s1==s2)
            {
                // cout<<"s";
                if(r>1)we=1;
                nn++;
                continue;
            }
            edges.push_back(make_pair(make_pair(m[s1],m[s2]),log(r)));
        }
        num=num-nn;
        cout<<"Case "<<cnt<<":"<<" ";
        cnt++;
        // cout<<we<<'\n';
        if(bellmanford(edges,1,n,num)&&!we)
            cout<<"No"<<endl;
        else 
            cout<<"Yes"<<endl;
        cin>>n;
    }   
}