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
 
inline long int lscan()                 
{
    long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
 
 
inline  int sscan()                     
{register  int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0')
    {
n=n*10+c-'0';
c=gc();
    }
return n;
}
int yyy=0;
int destx,desty,n,m,ex,ey;
bool we;
string a[100];
void f2(vector <int> b,string s,int sx,int sy){
	int sl=s.length();
	int i;
	destx=sx;
	desty=sy;
	f(i,sl){
		int nx=destx,ny=desty;
	//	if(yyy==0)cout<<nx<<" "<<ny<<endl;
		if(b[s[i]-'0']==1){
			nx++;
		}
		if(b[s[i]-'0']==2){
			nx--;
		}
		if(b[s[i]-'0']==3){
			ny++;
		}
		if(b[s[i]-'0']==4){
			ny--;
		}
		if(nx>=n||nx<0||ny>=m||ny<0)we=0;
		else
		{
			if(a[nx][ny]=='#')we=0;
		}
		destx=nx;
		desty=ny;
		if(destx==ex&&desty==ey)break;
	}
	yyy++;
}
int main()
{
	int t=1 ;
	while(t--){
		n=sscan(),m=sscan();
		int i,j,sx,sy;
		f(i,n)cin>>a[i];
		f(i,n){f(j,m){
			
		//cout<<a[i][j];
		if(a[i][j]=='E')ex=i,ey=j;
		if(a[i][j]=='S')sx=i,sy=j;
		}
		//cout<<endl;
		}
		//cout<<endl<<ex<<ey<<sx<<sy<<endl;
		vector <int> b(4);
		b[0]=1;
		b[1]=2;
		b[2]=3;
		b[3]=4;
		string s;
		cin>>s;
	//	cout<<s<<endl;
		int count=0;
		do {
			//cout<<b[0]<<b[1]<<b[2]<<b[3]<<endl;
			we=1;
			f2(b,s,sx,sy);		
			//cout<<destx<<" "<<desty<<endl;	
			if(we&&destx==ex&&desty==ey)count++;
    	} while(next_permutation(b.begin(), b.end()));
		cout<<count;
		
	}
	return 0;
}