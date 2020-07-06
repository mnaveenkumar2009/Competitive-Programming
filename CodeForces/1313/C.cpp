#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, sum_a = 0;
    cin >> n;
    vector <int> ans, a(n), pos, pre(n), suf(n), jps(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    stack <pair <int, int> > pre_stack, suf_stack;
    pre[0] = a[0];
    pre_stack.push({a[0], 0});
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + a[i];
        while(!pre_stack.empty()){
            auto T = pre_stack.top();
            if(T.first > a[i]){
                pre_stack.pop();
                if(!pre_stack.empty())
                    pre[i] -= abs((pre_stack.top().second) - T.second) * (T.first - a[i]);
                else
                    pre[i] -= (T.second + 1) * (T.first - a[i]);
            }
            else
                break;
        }
        pre_stack.push({a[i], i});
    }
    suf[n-1] = a[n-1];
    suf_stack.push({a[n-1], n-1});
    for(int i = n - 2; i >= 0; i--){
        suf[i] = suf[i+1] + a[i];
        while(!suf_stack.empty()){
            auto T = suf_stack.top();
            if(T.first > a[i]){
                suf_stack.pop();
                if(!suf_stack.empty())
                    suf[i] -= abs((suf_stack.top().second) - T.second) * (T.first - a[i]);
                else
                    suf[i] -= abs(n - T.second) * (T.first - a[i]);
            }
            else
                break;
        }
        suf_stack.push({a[i], i});
    }


    for(int i = 0; i < n; i++){
        // cout << pre[i] << ' ' << suf[n-i-1] << '\n';
        jps[i] = suf[i] + pre[i] - a[i];
    }
    {
        int i = max_element(jps.begin(), jps.end()) - jps.begin();
        vector <int> A = a;
        int sum = 0;
        for(int j = i - 1; j >= 0; j--){
            if(A[j] > A[j+1])
                A[j] = A[j+1];
        }
        for(int j = i + 1; j < n; j++){
            if(A[j] > A[j-1])
                A[j] = A[j-1];
        }
        for(int j = 0; j < n; j++){
            sum += A[j];
        }
        if(sum_a < sum){
            sum_a = sum;
            ans = A;
        }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}