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
void prin(ll a[],ll n){
    ll i;
    f(i,n){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(vector <vector <char> > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j];
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
#define vl vector <ll> 
#define vvl vector <vector <ll> >
#define vpl vector <pair <ll,ll> >
#define vvc vector <vector <char> > 

vvc anss(4,vector<char> (4,1));


int main(){
    ll t=sc;
    vvc notpos(4,vector <char>(4,0));
    notpos[0][0]='g';
    notpos[0][1]='r';
    notpos[0][2]='i';
    notpos[0][3]='d';
    notpos[1][0]='s';
    notpos[1][1]='n';
    notpos[1][2]='o';
    notpos[1][3]='t';
    notpos[2][0]='p';
    notpos[2][1]='o';
    notpos[2][2]='s';
    notpos[2][3]='s';
    notpos[3][0]='i';
    notpos[3][1]='b';
    notpos[3][2]='l';
    notpos[3][3]='e';
    while(t--){
        ll n=sc,i,j,k;
        set <string > aa;
        f(i,n){
            string s,s1;
            cin>>s;
            s1=s;
            reverse(s.begin(), s.end());            
            aa.insert(min(s,s1));
        }
                
        if(aa.size()>8){
            prin(notpos);
            continue;
        }

        vector <string> a,b;
        for(auto it:aa){
            a.pb(it);
        }
        while(a.size()<8){
            a.pb("....");
        }
        sort1(a);
        f(mask,1<<8){
            if(__builtinpopcount(mask)==4){
                // 8C4
                ll mask2;
                vector <string> horiz;
                f(i,8){
                    if(mask&(1<<i)){
                        horiz.pb(a[i]);
                    }
                }
                for(auto it:horiz){
                    cout<<it<<' ';
                }
                vector <string> ccc=horiz;
                f(mask2,1<<4){
                    f(i,4){
                        if((1<<i)&mask2){
                            reverse(horiz[i].begin(),horiz[i].end());
                        }
                    }
                    f(i,4){

                    }
                    horiz=ccc;
                }
            }
        }
        if(anss[0][0]==1){
            prin(notpos);
        }
        else{
            prin(anss);            
        }

    }
}