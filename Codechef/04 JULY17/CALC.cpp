    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
     
    int main() {
    long long n,b;
    int q;
    cin>>q;
     
    while(q--)
    {  
        scanf("%lld%lld",&n,&b);
        long long h=n/(2*b),maxi=0,temp;
        //h , h+1
        //x close to n/2 , n-x mi=ultiple of b
        temp=h*b;
        temp=n-temp;
        maxi=((n-temp)/b)*temp;
        h+=1;
        if(h*b<=n){
        temp=h*b;
        temp=n-temp;
        maxi=max(maxi,((n-temp)/b)*temp);
        }
        
        h-=2;
        if(h>=0)
        {
        temp=h*b;
        temp=n-temp;
        maxi=max(maxi,((n-temp)/b)*temp);
            
        }
        printf("%lld\n",maxi);
        
    }
    	return 0;
    } 