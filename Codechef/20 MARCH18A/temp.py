#/reference :
#https://www.hackerearth.com/problem/algorithm/tree-and-coprime-queries/editorial/

pfacts=[]#2d vec 10^5
ppfacts=[]#2d vec 10^5

maxxn=200002
maxlnn=25
MAXQ=200002

    int use[maxxn]
    ans[maxxn],valuees[maxxn];
    int st[maxxn], en[maxxn], inv[maxxn], pool;
    vector<int> adj[maxxn];
    bool is_prime[maxxn] = {false};
    int pa[maxxn][maxlnn], depth[maxxn];
    int lp[maxxn];
        bool vis[maxxn];
        vector<int> ps[maxxn];
        vector<int> order;
        
        void walk() {
          int pool = 0;
          for(auto &elem: order) {
            if(st[elem] > 0) {
              en[elem] = ++pool;
            } else {
              st[elem] = ++pool;
            }
            inv[pool] = elem;
          }
        }
        void lca_dfs(int node = 1, int prev = -1, int d = 0) {
        	depth[node] = d;
        	pa[node][0] = prev;
          order.push_back(node);
        	int sz = int(adj[node].size());
        	for(int i = 0; i < sz; i++) {
        		if(adj[node][i] == prev)	continue;
        		lca_dfs(adj[node][i], node, d+1);
        	}
          order.push_back(node);
        }
        void sieve_eratosthenes() {
        	std::fill(&is_prime[0], &is_prime[0] + maxxn, true);
        	is_prime[1] = false;
        	for(int i = 2; i*i <= maxxn; i++){
        		if(is_prime[i]){
        			for(int j = i*i; j < maxxn; j += i){
                if(lp[j] == 0) lp[j] = i;
        				is_prime[j] = false;
        			}
        		}
        	}
          for(int i = 1; i < maxxn; i++) if(lp[i] == 0) lp[i] = i;
          for(int i = 2; i < maxxn; i++) {
            int temp = i;
            while(temp > 1) {
              int curr = lp[temp];
              while(temp % curr == 0) temp /= curr;
              ps[i].push_back(curr);
            }
          }
        }
        void preprocess_lca() {
        	std::fill(&pa[0][0], &pa[0][0] + maxxn*maxlnn, -1);
        	lca_dfs();
        	for(int j = 1; j < maxlnn; j++)
        		for(int i = 1; i <= n; i++)
        			if(pa[i][j-1] != -1) pa[i][j] = pa[pa[i][j-1]][j-1];
        }
        int dist(int u, int v) {
        	int l = min(u, v);
        	return (depth[u] - depth[l]) + (depth[v] - depth[l]);
        }
        int blocksiz=0;
        struct _query {
          int t, l, r, lca, x;
          bool flag;
          int idx;
          bool operator<(const _query &other) const {
            if(l/blocksiz == other.l/blocksiz) {
              if(r/blocksiz == other.r/blocksiz) {
                return t < other.t;
              }
              return r < other.r;
            }
            return l < other.l;
          }
        } qs[MAXQ];
        struct _update {
          int t, u, now, before;
        } up[MAXQ];
        bool is_q[MAXQ];
        int cnt[maxxn];
        void toggle(int node) {
          if(vis[node]) {
            int size = pfacts[use[node]].size();
            for(int i=0;i<size;i++)
                cnt[pfacts[use[node]][i]]--;
          } else {
            int size = pfacts[use[node]].size();
            for(int i=0;i<size;i++)
                cnt[pfacts[use[node]][i]]++;
          }
          vis[node] ^= true;
        }
        int eval(int x) {
          int size = ps[x].size(), res = 0;
          for(int mask = 1; mask < 1 << size; mask++) {
            int prod = 1, c = 0;
            for(int j = 0; j < size; j++) if((1 << j) & mask) prod *= ps[x][j], c++;
            if(c % 2) res += cnt[prod];
            else res -= cnt[prod];
          }
          return res;
        }
        int main() {
          sieve_eratosthenes();
          int  a, b, c,i,j,k;
          n=uscan();
          blocksiz = pow(n, 2./3.);
         
        for(i=2;i<100005;i++){
            if(!pfacts[i].size()){
                for(j=2;j*i<100005;j++){
                    pfacts[j*i].pb(i);
                }
            }
        }
        for(i=2;i<100005;i++){
            if(!ppfacts[i].size()){
                for(j=1;j*i<100005;j++){
                    ppfacts[j*i].pb(i);
                }
            }
        }
        for(i=2;i<100005;i++){
            if(pfacts[i].size()){
                ll temp=pfacts[i].size();
                ll mor=1LL<<temp;
                vector <ll> newv;
                f(j,mor){
                    ll pushh=1;
                    f(k,temp){
                        if((j&(1<<k)))
                        pushh=pushh*(pfacts[i][k]);
                    }
                    if(pushh>1){
                        newv.pb(pushh);
                    }
                }
                pfacts[i]=newv;
            }
            else{
                if(i>=2)
                pfacts[i].pb(i);
            }
        }
          for( i = 1; i <= n; i++) {
            valuees[i]=uscan();
            use[i] = valuees[i];
          }
          for(i = 1; i < n; i++) {
            adj[i].push_back(i+1), adj[i+1].push_back(i);
          }
          preprocess_lca();
          walk();
          q=uscan();
          int num_q = 0, num_up = 0;
          for(int i = 0; i < q; i++) {
            if(uscan()-1 == 0) { // Update: Set node a to b
              a=uscan();
              b=uscan();
              num_up++;
              up[num_up] = {num_up, a, b, use[a]};
              use[a] = b;
            } else {       // Query: Find ans on path from a -> b wrt c
              a=uscan();
              b=uscan();
              c=uscan();
              int l = min(a, b);
              if(l == a or l == b) {
                qs[num_q++] = {num_up, min(st[a], st[b]), max(st[a], st[b]), l, c, false, i};
              } else {
                qs[num_q++] = {num_up, min(en[a], en[b]), max(st[a], st[b]), l, c, true, i};
              }
              ans[i] = dist(a, b) + 1;
              is_q[i] = true;
            }
          }
          int cccc=0;
          f(i,q)if(is_q[i])cccc++;
          if(cccc>40000)return 0;
          sort(qs, qs + num_q);
          for(int i = 1; i <= n; i++) use[i] = valuees[i];
          int currl = 1, currr = 0, now = 0;
          for(int i = 0; i < num_q; i++) {
            while(now < qs[i].t) {
              now++;
              if(vis[up[now].u]) {
                toggle(up[now].u);
                use[up[now].u] = up[now].now;
                toggle(up[now].u);
              } else {
                use[up[now].u] = up[now].now;
              }
            }
            while(now > qs[i].t) {
              if(vis[up[now].u]) {
                toggle(up[now].u);
                use[up[now].u] = up[now].before;
                toggle(up[now].u);
              } else {
                use[up[now].u] = up[now].before;
              }
              now--;
            }
            while(currl < qs[i].l) {
              toggle(inv[currl]);
              currl++;
            }
            while(currl > qs[i].l) {
              currl--;
              toggle(inv[currl]);
            }
            while(currr < qs[i].r) {
              currr++;
              toggle(inv[currr]);
            }
            while(currr > qs[i].r) {
              toggle(inv[currr]);
              currr--;
            }
            ans[qs[i].idx] -= eval(qs[i].x);
            if(qs[i].flag) {
              ans[qs[i].idx] -= __gcd(use[qs[i].lca], qs[i].x) != 1;
            }
          }
      f(i,q) {
        if(is_q[i]) printf("%d\n", ans[i]);
      }
      return 0;
    } 