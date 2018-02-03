    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
     
     
    int main()
    {
    		int t=1;
    	cin>>t;
    	while(t--){
    		string s;
    		cin>>s;
    		int i,j,n=s.length();
    		int a=0,b=0;
    		f(i,n){
    			if(s[i]=='a')a++;
    			else b++;
    		}
    		//cout<<a<<b;
    		int x,y;
    		cin>>x>>y;
    		float a1=float(a)/float(x);
    		float b1=float(b)/float(y);
    		int group1 = ceil(a1);
    		int group2 = ceil(b1);
    		int gdif=max(group1,group2)-min(group1,group2);
    		if(gdif>1){
    			if(group1>group2){
    				group2=min(group1-1,b);
    				gdif=group1-group2;
    			}
    			else{
    				group1=min(group2-1,a);
    				gdif=group2-group1;
    			}
    		}
    		//cout<<group1<<group2<<gdif<<endl;
    		int g1=group1,g2=group2;
    		if(group1>group2){
    			f(i,group1+group2+1-gdif){
    				if(i%2==0){
    					f(j,a/g1){
    						printf("a");
    					}
    					a-=a/g1;
    					g1--;
    					//x=a/(group1-i/2);
    				}
    				else{
    					f(j,b/g2)printf("b");
    					b-=b/g2;
    					g2--;
    				}
    			}
    			f(i,gdif-1){
    				printf("*");
    				f(j,min(x,a)){
    					printf("a");
    				}
    				a-=x;
    			}
    		}
    		else{
    			f(i,group1+group2-gdif){
    				if(i%2==0){
    					f(j,b/g2){
    						printf("b");
    						
    					}
    					b-=b/g2;
    					g2--;
    					//x=a/(group1-i/2);
    				}
    				else{
    					f(j,a/g1)printf("a");
    					a-=a/g1;
    					g1--;
    				}
    			}
    			f(i,gdif){
    			    if(i)
    				printf("*");
    				f(j,min(y,b)){
    					printf("b");
    				}
    				b-=y;
    			}
    			
    		}
    		cout<<endl;
    	}
    	return 0;
    } 