// score 10.562
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
     
    int main()
    {   
        
        int n,m;
        cin>>n>>m;
        
        int i,j,maxi=0,maxj=0;
        long long maxx=0;
        f(i,n){
            f(j,n){
                long long x;
                cin>>x;
                
                if(x>maxx){
                    maxi=i+1;
                    maxj=j+1;
                    maxx=x;
                }
            }
        }
        //cout<<maxi<<maxj<<endl;
        vector <int> a,b;
        f(i,n-maxj+1){
            if(m==0)break;
            a.pb(maxi);
            b.pb(maxj+i);
            m--;
        }
        f(i,maxi-1){
            if(m==0)break;
            a.pb(maxi-i-1);
            b.pb(n);
            m--;
        }
        
        i=0;j=n-1;
        while(m){
            if(((i%n+1)!=maxi||(j%n+1)<maxj)&&((j%n+1)!=n||(i%n+1)>maxi))
            {
            a.pb(i%n+1);
            b.pb(j%n+1);
            m--;}
            j--;
            if(j<0)j+=n;
            
            if(j%n==n-1)i++;
            
        }
        
        f(i,a.size()){
            printf("%d %d\n",a[i],b[i]);
        }
     
        return 0;
    } 

