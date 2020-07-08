#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define slld(n) scanf("%lld",&n)
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
inline ll uscan()
{
    ll n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
int main()
{
    int i;
    int n=uscan();
    vector <int> a(n);
    f(i,n){
        cin>>a[i];
    }
    vector <int> b=a;

    bool we=1;
    int count =0;
    int N=n;
    while(we){
        count++;
        if(count>50)break;
        f(i,n-1){
            if(a[i]-a[i+1]>=2){
                a[i]--;
                a[i+1]++;
                i++;
            }
        }
        int maxi=0;
        f(i,N){
            maxi=max(a[i],maxi);
        }
        int pos=0;
        f(i,N)if(a[i]==maxi){
            pos=i;
            break;
        }
        for(i=pos;i<N;i++){
            a[i]=a[i+1];
        }
        a[N-1]=maxi;
        N--;
        bool we2=1;
        f(i,n-1){
            if(a[i+1]<a[i])we2=0;
        }
       // f(i,n)cout<<a[i]<<" ";cout<<endl;
        if(we2)break;

    }
    sort(b.begin(),b.end());
    //f(i,n)cout<<a[i]<<" ";
    if(b!=a){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
	return 0;
} 