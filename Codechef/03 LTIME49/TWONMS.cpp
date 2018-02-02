    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    using namespace std;
     
    int main() {
        long a,b,n;
        int t;
        cin>>t;
        while(t--)
        {
            cin>>a>>b>>n;
            if(n%2)
            a*=2;
            cout<<max(a,b)/min(a,b)<<endl;
        }
    	return 0;
    }
     
