#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll int
#define ld long double
#define gc getchar
#define pc putchar
#define sort(a) sort(a.begin(),a.end())
#define sortn(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
inline ll uscan(){
    ll n=0,c=gc();bool check=0;
    while(c<'0'||c>'9'){if(c=='-')check=1;c=gc();}
    while(c<='9'&&c>='0'){n=n*10+c-'0';c=gc();}
    return check?-n:n;
}
#define sc uscan()
void prin(vector <ll> a){
    for(auto it:a)cout<<it<<' ';pc('\n');
}
void prin(vector <vector <ll> > a){
    for(auto vec:a){for(auto it:vec)cout<<it<<' ';pc('\n');}pc('\n');
}
void prin(vector <pair <ll,ll> > a){
    for(auto it:a)cout<<it.ff<<' '<<it.ss<<'\n';pc('\n');
}

    #define NNN 80001
ll nos=0,coun=1,nov=0;
set <ll> tag[NNN],tagv[NNN];
vl tagg[NNN];
ll scor(ll i,ll j){
    ll comm=0;
    for(auto it:tagg[i]){
        if(binary_search(tagg[j].begin(), tagg[j].end(),it))comm++;
    }
    return min(min((ll)tagg[i].size()-comm,(ll)tagg[j].size()-comm),comm);
}
int main()
{
    ll n=sc,i,j,k;
    vl elements[n],elementsv[n];
    unordered_map <string,ll> hashcode;
    bool xxx=1;

    f(i,n){
        char c;
        cin>>c;
        if(c=='H'){
            ll m=sc;
            while(m--){
                string s;
                cin>>s;
                if(!hashcode[s])
                    hashcode[s]=coun++;
                tag[nos].insert(hashcode[s]);
            }
            elements[nos].pb(i);
            nos++;
        }
        else{
            xxx^=1;
            ll m=sc;
            while(m--){
                string s;
                cin>>s;
                if(!hashcode[s])
                    hashcode[s]=coun++;
                tagv[nov].insert(hashcode[s]);
            }
            elementsv[nov].pb(i);
            if(xxx){                
                nov++;
            }
        }
    }
    // cout<<"ola1";
    f(i,nov){
        elements[nos]=elementsv[i];
        tag[nos++]=tagv[i];        
    }
    // cout<<"elements\n";
    // cout<<nos<<'\n';
    // f(i,nos){
    //     for(auto it:elements[i]){
    //         cout<<it<<' ';
    //     }pc('\n');
    // }
    n=nos;
    f(i,n){
        for(auto it:tag[i]){
            tagg[i].pb(it);
        }
    }
    
    // f(i,min(n,10)){
    //     f(j,min(n,10)){
    //         cout<<scor(i,j)<<' ';
    //     }
    //     cout<<'\n';
    // }
    // return 0;
    vl prin(1,0);
    set <ll> remain;
    f(i,n-1)remain.insert(i+1);

    
    srand(time(NULL));
    ll cur=rand()%n;
    // cout<<cur<<'\n';
    while(remain.size()){
        ll maxi=*remain.begin();
        // if(remain.size()%1000==0)
        // cout<<remain.size()<<'\n';
        ll xas=0;
        for(auto it:remain){
            xas++;
            if(xas>2000)break;
            if(scor(cur,it)>scor(cur,maxi)){
                maxi=it;
            }
        }
        prin.pb(maxi);
        remain.erase(maxi);
        cur=maxi;
    }
    cout<<prin.size()<<'\n';
    for(auto it:prin){
        // cout<<it<<'\n';
        for(auto itt:elements[it]){
            cout<<itt<<' ';
        }
        pc('\n');
    }
	return 0;
}