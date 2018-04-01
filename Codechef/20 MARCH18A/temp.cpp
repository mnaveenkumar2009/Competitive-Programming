 #include <iostream>
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define inf 1000000000000
    #define mod 1000000007
    #define pb push_back
    #define mp make_pair
    #define all(v) v.begin(),v.end()
    #define S second
    #define F first
    #define boost1 ios::sync_with_stdio(false);
    #define boost2 cin.tie(0);
    #define mem(a,val) memset(a,val,sizeof a)
    #define endl "\n"
    #define maxn 100001
     
    vector<int>v[maxn];
    int block[maxn],block_no,start[355],finish[355],divi[355][100005];
    int chainno,chainhead[maxn],chainindex[maxn],sz,pos,posinbasearray[maxn],basearray[maxn];
    int h[maxn],size[maxn],par[maxn][25],a[maxn];
    vector<int>factors[100005],prime_factors[100005];
    int divisible[100005],val,limit=350;
     
     
    void seive()
    {
        int i,j,x;
        for(i=1;i<=100001;i++)
        {
            for(j=i;j<=100001;j+=i)
            factors[j].pb(i);
        }
        for(i=2;i<=100001;i++)
        {
            x=i;
            for(j=2;j*j<=x;j++)
            {
                if(x%j)
                continue;
                prime_factors[i].pb(j);
                while(x%j==0)
                x/=j;
            }
            if(x>1)
            prime_factors[i].pb(x);
            assert(prime_factors[i].size()<=6);
        }
    }
    void dfs(int cur,int p)
    {
        par[cur][0]=p;
        if(p!=-1)
        h[cur]=h[p]+1;
        size[cur]=1;
        for(int i=1;i<20;i++)
        {
            if(par[cur][i-1]!=-1)
            par[cur][i]=par[par[cur][i-1]][i-1];
        }
        for(int i=0;i<v[cur].size();i++)
        {
            if(v[cur][i]==p)
            continue;
            dfs(v[cur][i],cur);
            size[cur]+=size[v[cur][i]];
        }
    }
    int lca(int v,int u)
    { 
        if(h[v]<h[u])swap(v,u); 
        for(int i=20-1;i>=0;i--)
        { 
            if(par[v][i]!=-1&&h[par[v][i]] >=h[u])
            { 
                v=par[v][i];
            } 
        } 
        if(v==u)
        return u;
        for(int i=20-1;i>=0;i--)
        { 
            if(par[v][i]-par[u][i]) 
            v=par[v][i],u=par[u][i];
        } 
        return par[v][0];
    }
    void hld(int cur,int p)
    {
        if(chainhead[chainno]==-1)
        chainhead[chainno]=cur;
        posinbasearray[cur]=pos;
        basearray[pos]=a[cur];
        pos++;
        chainindex[cur]=chainno;
        int sc=0;
        for(int i=0;i<v[cur].size();i++)
        {
            if(v[cur][i]==p)
            continue;
            if(size[v[cur][i]]>size[sc])
            sc=v[cur][i];
        }
        if(sc)
        hld(sc,cur);
        for(int i=0;i<v[cur].size();i++)
        {
            if(v[cur][i]==p || v[cur][i]==sc)
            continue;
            chainno++;
            hld(v[cur][i],cur);
        }
    }
    void query(int l,int r)
    {
        //assert(l<=r);
        if(l>r)return;
        int sze=prime_factors[val].size();
        for(int mask=1;mask<(1<<sze);mask++)
        {
            int req=1;
            for(int i=0;i<sze;i++)
            {
                if(mask&(1<<i))
                req=req*prime_factors[val][i];
            }
            if(req>100001)
            continue;
            assert(req!=0);
            int bl=block[l];
            int br=block[r];
            if(bl==br)
            {
                for(int i=l;i<=r;i++)
                divisible[req]+=(basearray[i]%req==0);
            }
            else
            {
                for(int i=bl+1;i<=br-1;i++)
                divisible[req]+=divi[i][req];
                for(int i=l;i<=finish[bl];i++)
                divisible[req]+=(basearray[i]%req==0);
                for(int i=start[br];i<=r;i++)
                divisible[req]+=(basearray[i]%req==0);
            }
        }
    }
    void query_up(int x,int y,int f)
    {
        int ychain=chainindex[y];
        while(1)
        {
            int xchain=chainindex[x];
            if(xchain==ychain)
            {
                if(f)
                query(posinbasearray[y],posinbasearray[x]);
                else
                query(posinbasearray[y]+1,posinbasearray[x]);
                break;
            }
            query(posinbasearray[chainhead[xchain]],posinbasearray[x]);
            x=chainhead[xchain];
            x=par[x][0];
        }
        return;
    }
    int main()
    {
        boost1;boost2;
        int i,j,n,q,x,y,type,ind,pre_val,mask,req,got,position,block_id,sze,lc;
     
        mem(par,-1);
        for(i=0;i<maxn;i++)
        chainhead[i]=-1;
        
        seive();
        
        cin>>n;
        for(i=1;i<=n;i++)
        cin>>a[i];
        for(i=1;i<=n-1;i++)
        {
            v[i].pb(i+1);
            v[i+1].pb(i);
        }
        cin>>q;
        dfs(1,-1);
     
        pos=1;
        chainno=1;
        hld(1,-1);
        sz=pos-1;
     
        for(i=1;i<=sz;i++)
        {
            block_no++;
            start[block_no]=i;
            for(j=i;j<=min(i+limit-1,sz);j++)
            block[j]=block_no;
            finish[block_no]=min(sz,i+limit-1);
            i=i+limit-1;
        }
        assert(block_no<=350);
        
        for(i=1;i<=block_no;i++)
        {
            for(j=start[i];j<=finish[i];j++)
            {
                x=basearray[j];
                for(auto it:factors[x])
                divi[i][it]++;
            }
        }
     
        while(q--)
        {
            cin>>type;
            if(type==1)
            {
                cin>>ind>>val;
                pre_val=a[ind];
                a[ind]=val;
     
                position=posinbasearray[ind];
                basearray[position]=val;
                block_id=block[position];
     
                for(auto it:factors[pre_val])
                divi[block_id][it]--;
                for(auto it:factors[val])
                divi[block_id][it]++;
            }
            else
            {
                cin>>x>>y>>val;
     
                sze=prime_factors[val].size();
                for(mask=1;mask<(1<<sze);mask++)
                {
                    req=1;
                    for(i=0;i<sze;i++)
                    {
                        if(mask&(1<<i))
                        req*=prime_factors[val][i];
                    }
                    if(req>100001)
                    continue;
                    divisible[req]=0;
                }
     
                lc=lca(x,y);
                query_up(x,lc,1);
                query_up(y,lc,0);
     
                got=0;
                for(mask=1;mask<(1<<sze);mask++)
                {
                    req=1;
                    for(i=0;i<sze;i++)
                    {
                        if(mask&(1<<i))
                        req*=prime_factors[val][i];
                    }
                    if(req>100001)
                    continue;
                    if(__builtin_popcount(mask)%2)
                    got+=divisible[req];
                    else
                    got-=divisible[req];
                }
                assert(got>=0);
                cout<<h[x]+h[y]-2*h[lc]+1-got<<endl;
            }
        }
        return 0;
    }