#include <bits/stdc++.h>
using namespace std;
int N;
bool check(int i, int j){
    if(i < 0 || j < 0)
        return 0;
    if(i >= N || j >= N)
        return 0;
    return 1;
}
int main(){
    cin >> N;
    string s;
    char A[N][N];
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < N; j++){
            A[i][j] = s[j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i][j] == 'K'){
                if(check(i+1, j))
                    A[i+1][j] = '-';
                if(check(i+1, j-1))
                    A[i+1][j-1] = '-';
                if(check(i+1, j+1))
                    A[i+1][j+1] = '-';
                if(check(i, j))
                    A[i][j] = '-';
                if(check(i, j-1))
                    A[i][j-1] = '-';
                if(check(i, j+1))
                    A[i][j+1] = '-';
                if(check(i-1, j))
                    A[i-1][j] = '-';
                if(check(i-1, j-1))
                    A[i-1][j-1] = '-';
                if(check(i-1, j+1))
                    A[i-1][j+1] = '-';
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i][j] == '*'){
                if(check(i+1, j+1)){
                    if(A[i+1][j+1] == '.')
                        continue;
                }
                if(check(i+1, j-1)){
                    if(A[i+1][j-1] == '.')
                        continue;
                }
                if(check(i+1, j+1)){
                    if(A[i+1][j+1] == '-'){
                        A[i+1][j+1] = '.';
                        ans++;
                        continue;
                    }
                }
                if(check(i+1, j-1)){
                    if(A[i+1][j-1] == '-'){
                        A[i+1][j-1] = '.';
                        ans++;
                        continue;
                    }
                }
                ans = -1;
                i = N;
                j = N;
                break;
            }
        }
    }
    cout << ans << '\n';
    
}