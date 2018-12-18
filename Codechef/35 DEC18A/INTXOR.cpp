#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(cin>>n){
        int i,j,k;
        int b[n],a[n];

        cout<<"1 1 3 4"<<endl;
        cin>>b[0];
        cout<<"1 3 4 "<<n<<endl;
        cin>>b[1];
        cout<<"1 2 3 5"<<endl;
        cin>>b[2];
        
        for(i=0;i<n-6;i++){
            int x=i+4;
            cout<<1<<' '<<x<<' '<<x+1<<' '<<x+2<<endl;
            cin>>b[i+3];
        }
        
        cout<<"1 2 "<<n-2<<' '<<n-1<<endl;
        cin>>b[n-3];
        cout<<"1 1 "<<n-1<<' '<<n<<endl;
        cin>>b[n-2];
        cout<<"1 1 2 "<<n<<endl;
        cin>>b[n-1];

        a[1]=b[0]^b[1]^b[n-1];
        a[n-2]=b[0]^b[1]^b[n-2];
        a[n-3]=b[n-1]^b[n-2]^b[n-3];
        
        for(i=n-4;i>=3;i--){
            a[i]=a[i+1]^a[i+2]^b[i];
        }
        a[2]=b[2]^a[1]^a[4];
        a[0]=b[0]^a[2]^a[3];
        a[n-1]=b[1]^a[2]^a[3];
        
        cout<<2<<endl;
        for(i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
        cin>>n;
    }
	return 0;
}