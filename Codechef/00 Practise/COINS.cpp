    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    vector <long long> a(10000001);
     
    long long fn(long long x)
    {
        
            if(x>=10000001)
            {
                return (fn(x/2)+fn(x/3)+fn(x/4));
            }
            return(a[x]);
        
    }
    int main() {
        long long j,n;
        f(j,12)
        {
        a[j]=j;
        }
        for(j=12;j<10000001;j++)
        {
        a[j]=max(j,a[j/2]+a[j/3]+a[j/4]);
        }
        int i=scanf("%lld",&n);
        while(i!=EOF)
        {
            printf("%lld\n",fn(n));
            i=scanf("%lld",&n);
        }
    	return 0;
    } 