#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
#define MP make_pair
#define PB push_back
#define ll long long
#define int long long
#define f(i,x,n) for(int i=x;i<n;i++)
#define ld long double
#define mod 1000000007
int n,m;
int vis[200005];
vector <int> ans;
int se[2][200005];
vector <array <int,3> > gp[200005];
int sp=0;
pair <int,int> dfs(int i,int state)
{
	// cout<<i<<" "<<state<<endl;
	if(se[state][i])
	{
		if(state==1)
			sp=1;
		// if(state==1)
		// {
		// 	vector <int> temp;
		// 	temp.push_back(ans[ans.size()-1]);
		// 	ans.pop_back();
		// 	for(auto i: ans)
		// 		temp.push_back(i);
		// 	ans=temp;
		// }
		return {i,state};
	}
	se[state][i]++;
	for(auto j: gp[i])
	{
		if(j[1]==state&&vis[j[2]]==0)
		{
			vis[j[2]]=1;
			pair <int,int> ret=dfs(j[0],state^1);
			// cout<<j[0]<<endl;
			if(ret.ff!=0)
			{
				if(se[ret.ss][ret.ff]>0)
					ans.push_back(j[2]);
				vis[j[2]]=2;
				se[state][i]--;
				return ret;
			}
			vis[j[2]]=2;
		}
	}
	se[state][i]--;
	return {0,0};
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		sp=0;
		cin>>n>>m;
		ans.clear();
		f(i,1,n+1)
		{
			gp[i].clear();
		}
		f(i,1,m+1)
		{
			int u,v;
			vis[i]=0;
			cin>>u>>v;
			gp[u].push_back({v,0,i});
			gp[v].push_back({u,1,i});
		}
		f(i,1,n+1)
		{
			dfs(i,0);
			if(ans.size()>0)
				break;	
		}
		// f(i,1,n+1)
		// {
		// 	for(auto &j: gp[i])
		// 		j[1]^=1;
		// }
		// f(i,1,m+1)
		// 	vis[i]=0;
		// if(ans.size()==0)
		// {
		// 	// cout<<"Idhar\n";
		// 	f(i,1,n+1)
		// 	{
		// 		if(ans.size()>0)
		// 			break;	
		// 		dfs(i,0);
		// 	}
		// 	reverse(ans.begin(), ans.end());
		// }
		if(ans.size()==0)
			cout<<":(\n";
		else
		{
			reverse(ans.begin(), ans.end());
			cout<<":)\n";
			cout<<ans.size()<<'\n';
			int jj=-1;
			if(sp==1)
			{
				for(auto i: ans)
				{
					if(jj==-1)
						jj=i;
					else
						cout<<i<<" ";
				}
				cout<<jj<<"\n";
			}
			else
			{
				for(auto i: ans)
					cout<<i<<" ";
				cout<<'\n';
			}
		}
	}
	return 0;
}