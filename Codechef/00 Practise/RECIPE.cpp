    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <iostream>
    #include <algorithm>
    #define f(i,n) for(i=0;i<n;i++)
    #define I std::cin>>
    #define O std::cout<<
    using namespace std;
    int gcd(int a,int b)
        {
        if(b==0)
            {
            return (a);
        }
        else {if(b==1)
            {return 1;}
             else
                 {
                 return(gcd(b,a%b));
             }
             }
        
    }
    int main()
    {
        int t,n,a[10000],j,i,gcd1;
        cin>>t;
     while(t--)
         {
         cin>>n;
         gcd1=1273682;
         f(i,n)
             {
             cin>>a[i];
         }
         f(i,n)
             
        {f(j,n)
        {gcd1=min(gcd(a[i],a[j]),gcd1);}
         }     
         f(i,n)
             {
            a[i]=a[i]/ gcd1;
         }
         f(i,n)
             {cout<<a[i]<<" ";}
         cout<<"\n";
         
     }
    	return 0;
    } 