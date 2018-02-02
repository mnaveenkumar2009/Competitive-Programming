    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    int f2(int i,int n)
    {
        if(i%n==0)
        return n;
        else
        return (i%n);
    }
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {int i;
         int n,j;
         cin>>n;
         cout<<n<<endl;
         f(i,n)
         { cout<<n<<endl;
             f(j,n)
             {
                cout<<j+1<<" "<<f2(i+j+1,n)<<" "<<f2(i+j+2,n);cout<<endl;
             }
         }
        }
     return 0;   
    } 