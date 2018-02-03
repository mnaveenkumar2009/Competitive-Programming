    #include <bits/stdc++.h>
    using namespace std;
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
    #define gc getchar
    #define pc putchar
    inline unsigned long long uscan()
    {
        unsigned long long n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0'){
    n=n*10+c-'0';
    c=gc();}
    return n;
    }
     
    inline long int lscan()                 
    {
        long int n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0'){
    n=n*10+c-'0';
    c=gc();}
    return n;
    }
     
     
    inline  int sscan()                     
    {register  int n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0')
        {
    n=n*10+c-'0';
    c=gc();
        }
    return n;
    }
    string lcs( string X, string Y, int m, int n )
    {
       int L[m+1][n+1];
     
       for (int i=0; i<=m; i++)
       {
         for (int j=0; j<=n; j++)
         {
           if (i == 0 || j == 0)
             L[i][j] = 0;
           else if (X[i-1] == Y[j-1])
             L[i][j] = L[i-1][j-1] + 1;
           else
             L[i][j] = max(L[i-1][j], L[i][j-1]);
         }
       }
       int index = L[m][n];
       string lcs;
       int i,j;
       f(i,index){
           lcs.pb('3');
       }
       i = m, j = n;
       while (i > 0 && j > 0)
       {
          if (X[i-1] == Y[j-1])
          {
              lcs[index-1] = X[i-1];
              i--; j--; index--;  
          }
     
          else if (L[i-1][j] > L[i][j-1])
             i--;
          else
             j--;
       }
     
       return lcs;
    }
     
    string rd(string a){
        int n=a.length(),i;
        string ret;
        ret.pb(a[0]);
        f(i,n){
            if(i){
                if(a[i]!=ret[ret.size()-1])ret.pb(a[i]);
            }
        }
        return ret;
    }
    int main()
    {
        int t=1;
        t=sscan();
        while(t--){
            int n=sscan(),m=sscan();
            string a,b;
            cin>>a>>b;
            int j,k,i;
            string ans;
            j=0;k=0;
            a=rd(a);
            b=rd(b);
            n=a.length();
            m=b.length();
           // cout<<a<<" "<<b<<endl;
            string ss=lcs(a,b,n,m);
            
            f(i,ss.length()){
                while(a[j]!=ss[i]||b[k]!=ss[i]){
                    if(a[j]==ss[i])
                        {
                            ans.pb(b[k]);
                            k++;
                        }
                    else
                        if(b[k]==ss[i]){
                            ans.pb(a[j]);
                            j++;
                        }
                        else
                        {
                            ans.pb(a[j]);
                            ans.pb(b[k]);
                            j++;
                            k++;
                        }
                }
                ans.pb(ss[i]);
                j++;
                k++;
            }
            while(j!=n){
                ans.pb(a[j]);j++;
            }
            while(k!=m)ans.pb(b[k]),k++;
            int count=1;
            f(i,ans.length()-1)if(ans[i]!=ans[i+1])count++;
            //cout<<ss<<endl;
            //cout<<ans<<endl;
            cout<<count<<endl;
        }
    	return 0;
    } 