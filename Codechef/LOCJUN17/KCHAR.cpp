    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    bool f2( long long x)
    {
        if(log2(x)==(int)log2(x))
        return 1;
        long long y= log2(x);
        y=pow(2,y);
        return (!f2(y-(x-y)));
    }
    int main() {
    int t;
    cin>>t;
    while(t--)
    {long long k;
        cin>>k;
        char g=f2(k)==0? 'c':'a';
        cout<<g<<endl;
    }
    	return 0;
    }
     