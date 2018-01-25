    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    using namespace std;
     
    int main() {
        int t;
        cin>>t;
        while(t--)
        {
            int u,v;
            cin>>u>>v;
            long long x=u+v;
            x=(x*(x+1));
            x/=2;
            cout<<x+u+1<<endl;
        }
    	return 0;
    }
