    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
     
     
    int main() {
        
        long long i;
        long long a,b,sum=0;
        cin>>a>>b;
        f(i,a)
        {
            long long h= b+((i+1)*(i+1));
            long long hh = i+2;
            //square less than h
            h=(long long)(sqrt(h));
            if(h-hh>=0){sum+=((h-hh)+1);}
           // cout<<h<<" "<<sum<<endl;
        }
        cout<<sum;
        
    	return 0;
    }  