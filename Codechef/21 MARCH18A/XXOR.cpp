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
#define gc getchar
#define pc putchar
inline unsigned long long uscan()
{
    unsigned long long n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
} 
 
int main()
{
    int n,q,i,j;
    n=uscan();q=uscan();
    vector <int> a(n);
    int a2[100000][31],c1[100000][31];
    for(i=0;i<n;i++){
        a[i]=uscan();
    }

    for(i=0;i<n;i++)
    {
    j=0;
    while(a[i]!=0){
    a2[i][j]=a[i]%2;
    a[i]=a[i]/2;
    j++;
    }
    }
    for (i=0;i<31;i++)
    {
        if (a2[0][i]==1)
            c1[0][i]+=1;
    }
    for (i=1;i<n;i++){
        for(j=0;j<31;j++)
        {
            if(a2[i][j]==0)
            {
                c1[i][j]=c1[i-1][j];
            }
            else 
                if(a2[i][j]==1)
            {
                c1[i][j]=c1[i-1][j]+1;
            }
        }
    }
    while(q--)
    {
        int l,r,an[31],ans=0;
        l=uscan();
        r=uscan();
        for(i=0;i<31;i++)
        {
            int xxx=0,yyy=0;
            if(l>1)
            {
            yyy=c1[r-1][i]-c1[l-2][i];
            xxx=(r-(l-1))-yyy;
            }
            else if(l==1)
            {
            
            yyy=c1[r-1][i];
            xxx=(r-(l-1))-yyy;
            }
            if(xxx>yyy)
            an[i]=1;
            else if(yyy>=xxx)
            an[i]=0;
        }
        int fac=1;
        for (i=0;i<31;i++)
        {
            if(an[i]==1)
                ans=ans+fac;
            fac=fac*2;
        }
        printf("%d\n",ans);
    }
} 