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
            long long mini=1000000009,n;
            cin>>n;int i;
            vector <long long> a(n);
            f(i,n)
            {
                cin>>a[i];
            }sort(a.begin(),a.end());
            f(i,n-1)
            {
                mini=min(mini,a[i+1]-a[i]);
            }
            cout<<mini<<endl;
        }
    	return 0;
    }
     