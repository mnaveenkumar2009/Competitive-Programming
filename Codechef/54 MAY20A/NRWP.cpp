#include <bits/stdc++.h>
using namespace std;


/*
1
3 3 9
1 4 2
-1 -2 3
-3 -2 -3
1 1 3
1 2 1
1 3 2
3 1 3
3 2 4
3 3 2
2 2 2
2 1 2
2 3 2

77
*/
#define int long long

#define SIZZZ 202

int H[1002][1002], P[1002][1002], PP[1002][1002], HH[202];
int p[202], x[202], y[202], n, ans[202];
vector <int> adj[202];
bitset <SIZZZ> Ans[202];
int root[202];
int num_of_it = 0;
void f(bitset <SIZZZ> F, bitset <SIZZZ> Fixd, int r){
    // cout << num_of_it++ << '\n';
    // cout << F << ' ' << Fixd << ' ' << r << '\n';
    for(int i = 1; i <= n; i++){
        if(F[i])
            p[i] = -abs(p[i]);
        else
            p[i] = abs(p[i]);
    }
    // fix elements
    for(int i = 1; i <= n; i++){
        if(!i)i = 1;
        if(root[i] != r)continue;
        if(Fixd[i]){
            int Fixd_sum = HH[i], rem = 0;
            for(auto child:adj[i]){
                if(Fixd[child]){
                    Fixd_sum += p[child];
                }
                else{
                    rem += abs(p[child]);
                }
            }
            for(auto child:adj[i]){
                if(!Fixd[child]){
                    int rem2 = rem - abs(p[child]);
                    if((Fixd_sum + rem2 < 0) && (F[i] == 0)){
                        Fixd[child] = 1;
                        F[child] = 0;
                        p[child] = abs(p[child]);
                        i = 0;
                        continue;
                    }
                    if((Fixd_sum - rem2 >= 0) && (F[i] == 1)){
                        Fixd[child] = 1;
                        F[child] = 1;
                        p[child] = -abs(p[child]);
                        i = 0;
                        continue;
                    }
                }
            }
        }
        else{
            int Fixd_sum = HH[i], rem = 0;
            for(auto child:adj[i]){
                if(Fixd[child]){
                    Fixd_sum += p[child];
                }
                else{
                    rem += abs(p[child]);
                }
            }
            if(abs(Fixd_sum) >= rem){
                Fixd[i] = 1;
                if(Fixd_sum < 0){F[i] = 1;p[i] = -abs(p[i]);}
                i = 0;
                continue;
            }
        }
    }
    
    // cout << F << ' ' << Fixd << ' ' << r << '\n';
    // check if done
    bool we = 1;
    for(int i = 1; i <= n; i++){
        if(root[i] == r && !Fixd[i]){
            we = 0;
        }
    }
    if(we){
        // job done
        for(int i = 1; i <= n; i++){
            if(F[i])
                p[i] = -abs(p[i]);
            else
                p[i] = abs(p[i]);
        }
        int Hs = 0, Es = 0;
        for(int i = 1; i <= n; i++){
            if(root[i] == r){
                int ADJ_sum = 0;
                for(auto child:adj[i]){
                    ADJ_sum += p[child];
                }
                Es += p[i] * ADJ_sum;
                Hs += p[i] * HH[i];
            }
        }
        assert(Es%2==0);
        int curans = Hs + Es/2;
        
        if(ans[r] < curans){
            ans[r] = curans;
            Ans[r] = F;
        }
    }
    else{
        // set another guy
        vector <pair <int, int> > REM[5];
        for(int i = 1; i <= n; i++){
            if(root[i] == r && !Fixd[i]){
                int rem = 0, rem2 = 0;
                for(auto ch:adj[i]){
                    rem += Fixd[ch];
                    rem2 += !Fixd[ch];
                }
                REM[rem].push_back({rem2, i});
            }
        }
        for(int i = 4; i >= 0; i--){
            if(REM[i].size() != 0){
                int ind = (*min_element(REM[i].begin(), REM[i].end())).second;
                Fixd[ind] = 1;
                F[ind] = 1;
	            f(F, Fixd, r);
                F[ind] = 0;
	            f(F, Fixd, r);
                break;
            }
        }
    }
}
bool vis[202];

void dfs(int node, int r){
    root[node] = r;
    vis[node] = 1;
    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(i, r);
        }
    }
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
	    int w, h;
	    cin >> h >> w >> n;
	    memset(P, 0, sizeof(P));
	    memset(PP, 0, sizeof(PP));
	    for(int i = 1; i <= h; i++){
	        for(int j = 1; j <= w; j++){
	            cin >> H[i][j];
	        }
	    }
	    for(int i = 1; i <= n; i++){
	        adj[i].clear();
	        cin >> x[i] >> y[i] >> p[i];
	        P[x[i]][y[i]] = p[i];
	        PP[x[i]][y[i]] = i;
	        HH[i] = H[x[i]][y[i]];
	    }
	    
	    for(int i = 1; i <= n; i++){
	        int x0 = x[i], y0 = y[i];
	        if(PP[x0-1][y0])adj[i].push_back(PP[x0-1][y0]);
	        if(PP[x0+1][y0])adj[i].push_back(PP[x0+1][y0]);
	        if(PP[x0][y0-1])adj[i].push_back(PP[x0][y0-1]);
	        if(PP[x0][y0+1])adj[i].push_back(PP[x0][y0+1]);
	    }
	    int r = 0;
	    memset(vis, 0, sizeof(vis));
	    for(int i = 1; i <= n; i++){
	        if(!vis[i]){
	            dfs(i, r++);
	        }
	    }
	   // cout << "Root\n";
	   // for(int i = 1; i <= n; i++){
	   //     cout << root[i] << ' ';
	   // }cout << '\n';
	    bitset <SIZZZ> Anss = 0;
	    for(int i = 0; i < r; i++){
	        ans[i] = -1;
	        bitset <SIZZZ> F = 0, fixD = 0;
	        f(F, fixD, i);
	    }
	    int anss = 0;
	    for(int i = 0; i < r; i++){
	        anss += ans[i];
	    }
	    cout << anss << '\n';
	    for(int i = 0; i < r; i++){
	        for(int j = 1; j <= n; j++){
	            if(root[j] == i){
	                Anss[j] = Ans[i][j];
	            }
	        }
	       // Anss |= Ans[i];
	    }
	    for(int i = 1; i <= n; i++){
	        cout << (Anss[i]? -1:1) << ' ';
	    }cout << '\n';
	}
}