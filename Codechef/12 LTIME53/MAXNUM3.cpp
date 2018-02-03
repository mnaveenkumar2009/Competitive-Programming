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
    		int n=s.length();
    		int i;
    		int sum=0;
    		f(i,n){
    			sum+=s[i]-'0';
    			sum%=3;
    		}
    		if((s[n-1]-'0')%2!=0){
    			if(s[n-1]%3==sum&&(s[n-2]-'0')%2==0){
    				f(i,n-1){
    					printf("%c",s[i]);
    				}
    				cout<<endl;
    			}
    			else
    			{
    				printf("-1\n");
    			}
    		}
    		else
    		{
    			
    		
    			bool we=0;
    			int pos=-1;
    			f(i,n-1){
    				int val=s[i]-'0';
    				
    				if(val%3==sum&&s[i]<s[i+1]){
    					pos=i;
    					we=1;
    					break;
    				}
    				if(val%3==sum){
    					pos=i;
    				}
    			}
    			//cout<<i<<" "<<pos<<endl;
    			if(we){
    				f(i,n){
    					if(i!=pos){
    						printf("%c",s[i]);
    					}
    				
    					
    				}
    				cout<<endl;
    				continue;
    			}
    			else
    			{
    				//check is last can be removed
    				if(s[n-1]%3==sum&&(s[n-2]-'0')%2==0){
    					pos=n-1;
    				}
    				if(pos==-1){
    					printf("-1\n");
    				}
    				else{
    					f(i,n){
    					if(i!=pos){
    						printf("%c",s[i]);
    					}	
    				}
    				cout<<endl;
    				}
    			}
    			
    			
    		}
    	}
    	return 0;
    } 