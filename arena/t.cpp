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

void prin(vector <ll> a){
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
void prin(vector < pair<ll,ll> > a){
    ll i,j;
    f(i,a.size()){
        cout<<a[i].ff<<' '<<a[i].ss<<'\n';
    }
    pc('\n');
}

int main()
{
    int t=uscan();
    while(t--){
        ll h1=sc,w1=sc,i,j,k;
        vector < vector <ll> > a(h1,vector <ll> (w1));
        
        string s1;
        cin>>s1;
        f(i,h1){
            f(j,w1){
                a[i][j]=s1[i*w1+j]-'0';
            }
        }
        ll h2=sc,w2=sc;
        vector < vector <ll> > b(h2,vector <ll> (w2));
        #define vvl vector <vector <ll> >
        vvl sum_d(h2,vector <ll> (w2,0));
        vvl sum_h(h2,vector <ll> (w2,0));
        vvl sum_v(h2,vector <ll> (w2,0));
        string s2;
        cin>>s2;
        
        f(i,h2){
            f(j,w2){
                b[i][j]=s2[i*w2+j]-'0';
                sum_d[i][j]=sum_h[i][j]=sum_v[i][j]=b[i][j];
            }
        }
        cout<<"sumd\n";
        prin(sum_d);
        cout<<"sum_h\n";
        prin(sum_h);
        cout<<"sum_v\n";
        prin(sum_v);
        
        ll gh=__gcd(h1,h2),gw=__gcd(w1,w2);
        
        ll he1=h2/gh,he2=h1/gh,we1=w2/gw,we2=w1/gw;
        cout<<he1<<' '<<we1<<' '<<he2<<' '<<we2<<'\n';
        ll ans=0;
        
        f(i,h1){
            f(j,w1){
                ll casex;
                pair <ll,ll> top_right=mp(i*he1,j*we1+we1-1);
                pair <ll,ll> top_left=mp(i*he1,j*we1);
                pair <ll,ll> bottom_left=mp(i*he1+he1-1,j*we1);
                pair <ll,ll> bottom_right=mp(i*he1+he1-1,j*we1+we1-1);
                pair <ll,ll> points[4];
                points[0].ff=top_left.ff/he2;
                points[0].ss=top_left.ss/we2;
                points[1].ff=top_right.ff/he2;
                points[1].ss=top_right.ss/we2;
                points[2].ff=bottom_left.ff/he2;
                points[2].ss=bottom_left.ss/we2;
                points[3].ff=bottom_right.ff/he2;
                points[3].ss=bottom_right.ss/we2;
                
                if(points[0]==points[2]){
                    if(points[0]==points[3]){
                        casex=1;
                    }
                    else{
                        casex=3;
                    }
                }
                else{
                    if(points[0]==points[1]){
                        casex=4;
                    }
                    else{
                        casex=2;
                    }
                }
                ll number_of_ones=0;
                switch(casex){
                    case 1:
                        if(b[points[0].ff][points[0].ss])
                            number_of_ones=he1*we1;
                        break;
                    case 2:
                        // 2 horizontal + 2 vertical + 1 diag + 4 corners
                        break;
                    case 3:
                        // one horizontal + 2 sides
                        number_of_ones=;
                        number_of_ones+=;
                        number_of_ones+=;
                        break;
                    case 4:
                        // one vertical + 2 sides
                        number_of_ones=;
                        number_of_ones+=;
                        number_of_ones+=;
                        break;
                }
                ans+=(a[i][j]*number_of_ones)+((1-a[i][j])*(he1*he2-number_of_ones));
            }
        }
        cout<<ans<<'\n';
    }
	return 0;
} 