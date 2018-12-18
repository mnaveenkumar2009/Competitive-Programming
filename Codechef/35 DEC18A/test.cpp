#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define sort1(a) sort(a.begin(),a.end())
#define sort2(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
#define avg(a,b) ((a+b)/2.0)
inline ll uscan()
{
    ll n=0,c=gc();
    bool check=0;
    if(c=='-')check=1;
    while(c<'0'||c>'9')
    {
        c=gc();
        if(c=='-')check=1;
    }
    while(c<='9'&&c>='0'){
        n=n*10+c-'0';
        c=gc();
    }
    return n+(-2*check*n);
}
#define sc uscan()
void prin(vector <ld> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(vector <vector <ll> > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j]<<' ';
        pc('\n');
    }
    pc('\n');
}
void prin(vector <vector <pair <ll,ll> > > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j].ss<<' ';
        pc('\n');
    }
    pc('\n');
}
int n;
ld r=1;
ll c=0,c2=0;
ld v=0;

bool cir(ld x, ld y){
    return (x*x+y*y)<(r*r);
}

bool dist(ld x1,ld y1, ld x2, ld y2){
    if((x2*y1-y2*x1)*(x2*y1-y2*x1)<((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)))return 1;
    return 0;
}

void f2(vector <ld> &x, vector <ld>& y,ld area){
    c++;
    // if(c>10000)return;
    bool isSomethingthere=0;
    bool isEverythingthere=1;
    ld cx=(x[1]+x[2])/2.0,cy=(y[0]+y[1])/2.0;
    ll thre=0;
    if(c<thre){
        // cout<<c<<'\n';
        ll i;
        f(i,4){
            cout<<x[i]<<' ';
        }
        f(i,4){
            cout<<y[i]<<' ';
        }
        cout<<cx<<' '<<cy<<' '<<area<<'\n';
    }
    // if(area<0.00000001){
    //     // v+=area*0.5;
    //     c2++;
    //     return;
    // }
    
    ll i,j;
    f(j,4){
        bool xxx=cir(x[j],y[j]);
        isEverythingthere&=xxx;
        isSomethingthere|=xxx;
    }
    // if(c==11)cout<<isSomethingthere<<'\n';
    if(x[0]<0&&y[0]<0){
        if(x[3]>0&&y[3]>0){
            isSomethingthere=1;
        }
    }
    // if(c==11)cout<<isSomethingthere<<'\n';
    if(dist(x[0],y[0],x[1],y[1])&&y[0]<0&&y[1]>0){
        isSomethingthere=1;
    }
    // if(c==11)cout<<isSomethingthere<<'\n';
    if(dist(x[0],y[0],x[2],y[2])&&x[0]<0&&x[2]>0){
        isSomethingthere=1;
    }
    // if(c==11)cout<<isSomethingthere<<'\n';
    if(dist(x[3],y[3],x[1],y[1])&&x[1]<0&&x[3]>0){
        isSomethingthere=1;
    }
    // if(c==11)cout<<isSomethingthere<<'\n';
    if(dist(x[3],y[3],x[2],y[2])&&y[2]<0&&y[3]>0){
        isSomethingthere=1;
    }
    // if(c==11)cout<<isSomethingthere<<'\n';

    if(isEverythingthere){
        // f(i,4)
        // cout<<x[i]<<' '<<y[i]<<' ';
        // cout<<area<<'\n';
        v+=area;
    }
    else{
        // f(i,4)
        // cout<<x[i]<<' '<<y[i]<<' ';
        // cout<<area<<'\n';
        
        if(isSomethingthere&&area>=0.000000001){
            area/=4.0;
            // lb lt rb rt
            vector <ld> xnew1={x[0],x[0],(x[0]+x[2])/2,cx};
            vector <ld> ynew1={y[0],(y[0]+y[1])/2.0,y[0],cy};
            vector <ld> xnew2={x[0],x[1],cx,avg(x[1],x[3])};
            vector <ld> ynew2={(y[0]+y[1])/2.0,y[1],cy,avg(y[1],y[3])};
            vector <ld> xnew3={cx,avg(x[1],x[3]),avg(x[2],x[3]),x[3]};
            vector <ld> ynew3={cy,avg(y[1],y[3]),avg(y[3],y[2]),y[3]};
            vector <ld> xnew4={avg(x[0],x[2]),cx,x[2],avg(x[3],x[2])};
            vector <ld> ynew4={avg(y[0],y[2]),cy,y[2],avg(y[3],y[2])};
            
            f2(xnew1,ynew1,area);
            f2(xnew2,ynew2,area);
            f2(xnew4,ynew4,area);
            f2(xnew3,ynew3,area);
        }
        else{
            if(c<thre)
            cout<<"no\n";
        }
    }
}


int main()
{
    vector <ld> x={-4000,-4000, 4000, 4000};
    vector <ld> y={-4000,4000,-4000,4000};
    ld zzz;
    f2(x,y,(x[2]-x[0])*(y[1]-y[0]));
    cout<<c<<'\n';
    cout<<c2<<'\n';
    cout<<fixed<<setprecision(10)<<v<<'\n';
	return 0;
}
//1342245