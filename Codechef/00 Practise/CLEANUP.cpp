    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    using namespace std;
    int main() {
        int a,b;
        int t;
        cin>>t;
        while(t--)
        {
            int m,n;
            cin>>n>>m;
            vector <bool> c(n);
            while(m--)
            {
                cin>>a;
                c[a-1]=1;
            }
            vector <int> chef,ass;
            bool we=1;
            f(b,n)
            {if(!c[b]&&we)
            {
                chef.pb(b+1);we=!we;continue;
            }
            if(!c[b]&&1-we)
            {
                ass.pb(b+1);we=!we;
            }
            }
            f(b,chef.size())
            {
                cout<<chef[b]<<" ";
            }cout<<endl;
            
            f(b,ass.size())
            {
                cout<<ass[b]<<" ";
            }cout<<endl;
            
        }
    	return 0;
    }
     