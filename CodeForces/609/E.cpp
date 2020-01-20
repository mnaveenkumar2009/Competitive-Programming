#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200006
vector <pair <int,ll> > adj[MAXN],;

pair <ll,pair <int,int> > edges[MAXN];  

void kruskal(){
    long long minimumCost = 0;
    for(int i = 0; i < edges;++i)
    {        
        int x = p[i].second.first;
        int y = p[i].second.second;    
        if(root(x) != root(y)){
            minimumCost += p[i].first;
            union1(x, y);
        }
    }
    return minimumCost;
}
int main(){
    int n,m;
    cin >> n >> m;


}