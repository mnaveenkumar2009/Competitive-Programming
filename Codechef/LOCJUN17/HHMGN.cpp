#include <bits/stdc++.h>
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
 
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--)
    {int i;
      long long n,s;
      cin>>n>>s;
      vector <int> a(n+1),sum(n);
      a[n]=INT_MAX;
      f(i,n)
      {
          scanf("%d",&a[i]);
      }
    
    sort(a.begin(),a.end());
    sum[0]=a[0];
    f(i,n-1)
    {
        sum[i+1]=a[i+1]+sum[i];
    }
    
    if(sum[n-1]<s)
    {
        cout<<"-1\n";continue;
    }
    
    if(sum[n-1]==s)
    {
        cout<<a[n-1]<<endl;continue;
    }
    if(s%n==0&&s/n<=a[0])
    {
        cout<<s/n<<endl;continue;
    }
    f(i,n)
    {
    if(i==n-1)
        {
            cout<<"-1\n";
            break;
        }
        if((s-sum[i])%(n-i-1)==0&&(s-sum[i])/(n-i-1)<=a[i+1]&(s-sum[i])/(n-i-1)>=a[i])
        {
        cout<<(s-sum[i])/(n-i-1)<<endl;break;
        }
    }
        
    }
	return 0;
}