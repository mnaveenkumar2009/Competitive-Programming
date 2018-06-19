#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
         
int main() {
    int q,i=0,t;
    long long n,m;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,c;
        cin>>n>>k>>c;
        vector <long long> a(n);
        f(i,n)
        {
            scanf("%lld",&a[i]);
        }
        sort(a.begin(),a.end());
        int count=0;
        bool we=0;
        while(1){
            int y=k-1;
            i=0;
            while(y--){
                int yy=a[i];
                a.erase(a.begin()+i);
                int low = 0, high = a.size();
                while (low != high) {
                    int mid = (low + high) / 2; 
                    if (a[mid] < yy*c) {
                        low = mid + 1;
                    }
                    else {
                        high = mid;
                    }
                }
                i=high;
                if(i==a.size()){
                    we=1;
                    break;
                }
            }
            if(!we)
            {
                a.erase(a.begin()+i);
            }
            if(!we)
            count++;
            if(a.size()==0||we)break;
        } 
        cout<<count<<endl;     
    }
    return 0;
}   