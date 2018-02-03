    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
     
    int main()
    {
        
        int t;
        cin>>t;
        while(t--)
        {
            int n,m;
            cin>>n>>m;
            if(n==1)
            cout<<m<<endl;
            if(n==2)
            {
                if(m==2)
                {
                    cout<<"4\n";
                }
                if(m==1)
                {
                    cout<<"2\n";
                }
                if(m>=3)
                {
                    int h=m%6;
                    int sum=m/6;
                    sum*=4;
                    if(h<=2)
                    {
                        sum+=h*2;
                    }
                    if(h>=3)
                    {
                        sum+=4;
                    }
                    cout<<sum<<endl;
                }
            }
           else if(n==3)
            {
                if(m==2)
                {
                    cout<<"4\n";
                }
                if(m==1)
                {
                    cout<<"3\n";
                }
                if(m>=3)
                {
                    int h=m%6;
                    int sum=m/6;
                    sum*=4;
                    switch(h)
                    {
                    case 1:sum+=2;break;
                    
                    case 2:sum+=4;
                    if(m>=14)sum--;break;
                    case 3:sum+=4;break;
                    case 4:sum+=4;break;
                    case 5:sum+=4;break;
                    }cout<<sum<<endl;
                }
            }
        }
        return 0;
    }  