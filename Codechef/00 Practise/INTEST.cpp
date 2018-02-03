    #include <bits/stdc++.h>
    using namespace std;
    int main() {
    ios_base::sync_with_stdio(false);
        cin.tie(NULL); 
    int q,ans=0,t;
    int n;
    scanf("%d%d",&t,&n);
     
    while(t--){
    cin>>q;
    if(!(q%n))ans++;
    }
    cout<<ans;
    	return 0;
    }  