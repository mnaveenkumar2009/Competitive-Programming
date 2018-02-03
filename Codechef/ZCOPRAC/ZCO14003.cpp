    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    int main() {
    	// your code goes here
    	long long n,maxi=0,i;
    	cin>>n;
    	vector <int> a(n);
    	f(i,n)
    	{
    	    cin>>a[i];
    	}
    	vector <long long> b(n);
    	sort(a.begin(),a.end());
    	f(i,n)
    	{
    	    b[i]=(n-i)*a[i];
    	}
    	f(i,n)
    	{maxi=max(maxi,b[i]);
    	}
    	cout<<maxi;
    	return 0;
    }
     