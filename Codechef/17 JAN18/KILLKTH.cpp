//5 points solution
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
    vector <string> ss;
    void subString(string s, int n) 
    {
        for (int i = 0; i < n; i++) 
            for (int len = 1; len <= n - i; len++)
                ss.pb(s.substr(i, len));
    }
    int main()
    {
        string s;
        cin>>s;
        subString(s,s.length());
        sort(ss.begin(),ss.end());
        string sss="";
        int i;
        f(i,ss.size())sss+=ss[i];
        //cout<<sss<<endl;
        ll q=sscan(),g=0;
        while(q--){
            ll p=uscan(),m=uscan(),k=(p*g)%m+1;
            char ans=sss[k-1];
            putchar(ans);
            putchar('\n');
            g+=ans;
        }
    	return 0;
    }     