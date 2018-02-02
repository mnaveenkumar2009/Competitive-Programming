    //20 points solution
    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
     
    int main() {
    int q,i=0,t,j=0;
    scanf("%d",&t);
    while(t--)
    {
        int count=0;
        int n;
        scanf("%d",&n);
        vector <int> a(n);
        f(i,n)
        {
            scanf("%d",&a[i]);
        }
        f(i,n)
        {
            for(j=i+1;j<n;j++)
            {
                if((a[i]|a[j])==max(a[i],a[j]))count++;
            }
        }
        cout<<count<<endl;
    }
    	return 0;
    }  