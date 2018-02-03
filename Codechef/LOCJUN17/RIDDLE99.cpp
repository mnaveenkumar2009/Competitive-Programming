    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
     
    using namespace std;
     
    int main() {
        int t;
        cin>>t;
        while(t--)
        {
           long long a,b,m;
           scanf("%lld%lld%lld",&a,&b,&m);
           long long d,e;
           d=a/m;
           e=b/m;
           d*=m;e*=m;
           if(d!=a)
           {
               d+=m;
           }
           if(e-d>=0)
           cout<<((e-d)/m)+1<<endl;
            else
            cout<<"0\n";
        }
    	return 0;
    } 