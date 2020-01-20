#include <bits/stdc++.h>
using namespace std;
int t,smask;


int main(){
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		smask=0;
		int n=s.length();
		for(auto it:s)smask|=(1<<(it-'0'));		
		vector <vector <int> > dp(n,vector <int> (1024,0));
        vector <int> pos(10,-1);

        for(int i=0;i<n;i++)dp[i][0]=1;

		dp[0][1<<(s[0]-'0')]=1;
        pos[s[0]-'0']=0;
		for(int i=1;i<n;i++){
            // if(pos[s[i]-'0']==-1)
		    dp[i][1<<(s[i]-'0')]=1;
		    for(int mask=0;mask<1024;mask++){
		        if((mask&(1<<(s[i]-'0')))){
                    int maxi=0;
                    for(int num=0;num<10;num++){
                        if(pos[num]!=-1&&(mask&(1<<num)&&(num!=s[i]-'0'))){
                            if(i==5&&mask==7){
                                // cout<<num<<dp[pos[num]][mask^(1<<(s[i]-'0'))]<<' '<<dp[pos[num]][mask]<<' '<<(mask^(1<<(s[i]-'0')))<<'\n';
                            }
		                    dp[i][mask]+=dp[pos[num]][mask^(1<<(s[i]-'0'))];
                            maxi=max(maxi,dp[pos[num]][mask]);
                        }
                    }
                    dp[i][mask]+=maxi;
		        }
                else{
                    // for(int num=0;num<10;num++)
                    //     if(pos[num]!=-1&&(mask&(1<<num)&&(num!=s[i]-'0')))
		            //         dp[i][mask]+=dp[pos[num]][mask];
                }
                // if(mask)
                // dp[i][mask]+=dp[i-1][mask];
                
		    }
            pos[s[i]-'0']=i;
		}
        for(int j=0;j<8;j++){
        for(int i=0;i<n;i++){
            
                cout<<dp[i][j]<<' ';
            }cout<<'\n';
        }
		cout<<dp[n-1][smask]<<'\n';
	}
}
