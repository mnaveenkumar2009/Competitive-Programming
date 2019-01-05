#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)

int main()
{
    bool dp[2][301][301][301][4];
    int i,j,k,l,m,n;
    f(i,2)
        f(j,301)
            f(k,301)
                f(l,301)
                    f(m,4){
                        dp[i][j][k][l][m]=1;
                        if(m!=2&&i)
                            dp[i][j][k][l][m]&=dp[i-1][j][k][l][m];
                        if(m!=1&&j)
                            dp[i][j][k][l][m]&=dp[i][j-1][k][l][(m+1)&3];
                        if(m!=0&&k)
                            dp[i][j][k][l][m]&=dp[i][j][k-1][l][(m+2)&3];
                        if(m!=3&&l)
                            dp[i][j][k][l][m]&=dp[i][j][k][l-1][(m+3)&3];
                        dp[i][j][k][l][m]^=1;
                    }
    cin>>n;
    while(cin>>n){
        int b[4]={0},x;
        while(n--){
            cin>>x;
            b[x&3]++;
        }
        b[0]&=1;
        if(dp[b[0]][b[1]][b[2]][b[3]][0])
            cout<<"Ghayeeth\n";
        else
            cout<<"Siroj\n";
    }
}