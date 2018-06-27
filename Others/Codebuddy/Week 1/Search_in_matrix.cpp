using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define ll long long
#define gc getchar
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
    int t=uscan(),i,j;
    while(t--){
        //O(m+n)
        int n=uscan(),m=uscan();
        bool a[200000]={0};
        f(i,m*n)
          a[uscan()]=1;
        int x=uscan();
        cout<<a[x]<<'\n';
    }
	return 0;
} 