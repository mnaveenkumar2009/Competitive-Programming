#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n];
	    multiset <int> X;
	    set <int> miss;
	    vector <int> ans;
	    for(int i = 0; i < n + 10; i++){
	        miss.insert(i);
	    }
	    for(int i = 0; i < n; i++){
	        cin >> a[i];
	        X.insert(a[i]);
	        miss.erase(a[i]);
	    }
	   // for(int i = 0; i < n; i++){
	   //     bool we = 1;
	   //     int maxi = 0;
	   //     for(int j = 0; j < n; j++){
	   //         if(a[j] < maxi){
	   //             we = 0;
	   //             break;
	   //         }
	   //         maxi = a[j];
	   //     }
	   //     if(we)break;
	   //     if(a[i] != i){
    //             for(int j = i + 1; j < n; j++){
    //                 if(a[j] == i){
    //                     int y = a[j];
    //                     X.erase(X.find(a[j]));
    //                     a[j] = *miss.begin();
    //                     miss.erase(miss.begin());
    //                     if(X.find(y) == X.end()){
    //                         miss.insert(y);
    //                     }
    //                     X.insert(a[j]);
    //                     ans.push_back(j);
    //                 }
    //             }
    //             int y = a[i];
    //             X.erase(X.find(a[i]));
    //             a[i] = *miss.begin();
    //             miss.erase(miss.begin());
    //             if(X.find(y) == X.end()){
    //                 miss.insert(y);
    //             }
    //             X.insert(a[i]);
    //             ans.push_back(i);
	   //     }
	   // }
	   while(1){
	        int i = *miss.begin();
	        if(i > n - 1){
	            bool we = 1;
	            for(int j = 0; j < n; j++){
	                if(a[j] != j){
	                    for(int k = j + 1; k < n; k++){
	                        if(a[k] == j){
	                            i = k;
	                            break;
	                        }
	                    }
	                    we = 0;
	                    break;
	                }
	            }
	            if(we)break;
	        }
            int y = a[i];
            X.erase(X.find(a[i]));
            a[i] = *miss.begin();
            miss.erase(miss.begin());
            if(X.find(y) == X.end()){
                miss.insert(y);
            }
            X.insert(a[i]);
            ans.push_back(i);
	   }
	    cout << ans.size() << '\n';
	    for(auto i:ans)cout << i + 1 << ' ';cout << '\n';
		
	}
	return 0;
}