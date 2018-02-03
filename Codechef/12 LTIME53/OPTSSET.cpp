//10 points solution
    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define sllf(n) scanf("%Lf",&n)
    #define mod 1000000007
    #define mp make_pair
    #define ff first
    #define ss second
    #define ll long long
    #define ld long double 
    long double dist(pair <ld,ld> a,pair<ld,ld> b){
    	long double ans=0;
    	ld asd=a.ff-b.ff;
    	asd*=asd;
    	ld dsa = a.ss-b.ss;
    	dsa*=dsa;
    	return sqrt(dsa+asd);
    } 
    int main()
    {
    	int t=1;
    	cin>>t;
    	while(t--){
    	    int i;
    	    long double answer=0;
    	    int n;
    	    sd(n);
    	    vector < pair <ld,ld> > a(n);
    	    vector <ld> w(n);
    	    f(i,n){
    	    	sllf(a[i].ff);
    	    	sllf(a[i].ss);
    		}
    		f(i,n){
    			sllf(w[i]);
    		}
    		ll j,ite=(1LL<<(n-1));
    		f(j,ite){
    			int num=j;
    			vector <int> taken;
    			taken.pb(0);
    			int count=0;
    			while(num!=0){
    				count++;
    				if(num%2){
    					taken.pb(count);
    				}
    				num/=2;
    			}
    			long double temp=0;
    			f(i,taken.size()-1){
    				temp+=dist(a[taken[i]],a[taken[i+1]]);
    			}
    			temp+=dist(a[taken[0]],a[taken[i]]);
    			ld den=0;
    			f(i,taken.size())den+=w[taken[i]];
    			answer=max(answer,temp/den);
    		}
    		
    		long long anss=answer;
    		int count=0;
    		while(anss!=0){
    			count++;anss/=10;
    		}
    		cout << setprecision(7+count) << answer << '\n';
    	}
    	return 0;
    } 