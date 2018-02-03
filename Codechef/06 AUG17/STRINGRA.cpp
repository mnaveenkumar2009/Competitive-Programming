    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    int main() {
    int q,i=0,t,j=0;
    long long n,m;
    scanf("%d",&t);
    while(t--)
    {
        bool we=1;
        int n,m;
        sd(n);sd(m);
        vector < vector <int> > v( n+1 , vector <int> (0,0));
        vector <int> ans(n+1,-1),pos(n+1,0);
        while(m--)
        {
            int a,b;
            sd(a);sd(b);
            if(a>=b){we=0;///////first cond
            }
            else
            {
                v[b].pb(a);
            }
        }
        f(i,n+1)
        {
            sort(v[i].begin(),v[i].end());
        }
        
        for(i=1;i<n+1;i++)
        {   if(v[i].size()==0){we=0;
            break;}
            else{
            if(v[i][0]!=i-v[i].size()){
                we=0;
                break;
            }}
            
            f(j,v[i].size()-1)
            {
                if(v[i][j+1]!=v[i][j]+1){we=0;break;}
            }
            
            if(we)
            {   if(v[i][0]!=0)
                {   if(pos[v[i][0]]==0)
                    pos[v[i][0]]=i;
                    else
                    we=0;
                }
            }
            
        }
        if(we){
        
        int xxx=1;
        for(i=1;i<n+1;i++)
        {
            if(ans[i]==-1)
            {
            ans[i]=xxx;
            xxx++;
            }
            
            ans[pos[i]]=ans[i];
            printf("%d ",ans[i]);
        }
        printf("\n");
        }
        else
        {
            printf("-1\n");
        }
        
        
    }
        
     
    	return 0;
    }  