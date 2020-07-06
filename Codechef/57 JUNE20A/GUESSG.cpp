#include <bits/stdc++.h>
using namespace std;
#define int long long
char c;
int bb = 0;
bool quer(int x){
    assert(bb++ < 200);
    cout << x << endl;
    cin >> c;
    if(c == 'E')
        exit(0);
    return (c == 'G');
}
signed main(){
    int low = 1, high;
    cin >> high;
    vector <pair <int, int> > Range(1, {low, high});
    while(1){
        vector <pair <int, int> > nRange;
        int sum = 0;
        for(auto i:Range)
            sum += i.second - i.first + 1;
        if(sum <= 3){
            for(auto i:Range){
                for(int j = i.first; j <= i.second; j++)
                    quer(j);
            }
        }
        int x1 = (sum) / 3, x2 = (sum * 2) / 3;
        sum = 0;
        for(auto i:Range){
            if(i.second - i.first + 1 + sum >= x1){
                x1 = x1 - sum - 1 + i.first;
                break;
            }
            sum += i.second - i.first + 1;
        }
        sum = 0;
        for(auto i:Range){
            if(i.second - i.first + 1 + sum >= x2){
                x2 = x2 - sum - 1 + i.first;
                break;
            }
            sum += i.second - i.first + 1;
        }

        bool x = quer(x1);
        if(x){
            if(quer(x1)){
                // >>
                low = x1 + 1;
                for(auto i:Range){
                    if(i.second < low || i.first > high)
                        continue;
                    if(max(low, i.first) <= min(high, i.second))
                        nRange.push_back({max(low, i.first), min(high, i.second)});
                }
                Range = nRange;
            }
            else{
                if(quer(x2)){
                    // low - x1 - 1 + x2 + 1 - high
                    for(auto i:Range){
                        if(i.second >= low && i.first <= x1 - 1)
                            if(max(low, i.first) <= min(x1 - 1, i.second))
                                nRange.push_back({max(low, i.first), min(x1 - 1, i.second)});
                        if(i.second > x2 && i.first <= high)
                            if(max(x2 + 1, i.first) <= min(high, i.second))
                                nRange.push_back({max(x2 + 1, i.first), min(high, i.second)});
                    }
                    sort(nRange.begin(), nRange.end());
                    Range = nRange;
                }
                else{
                    // ><<
                    high = x2 - 1;
                    for(auto i:Range){
                        if(i.second < low || i.first > high)
                            continue;
                        if(max(low, i.first) <= min(high, i.second))
                            nRange.push_back({max(low, i.first), min(high, i.second)});
                    }
                    Range = nRange;
                }
            }
            continue;
        }
        if(quer(x2)){
            // <>
            for(auto i:Range){
                if(i.second >= low && i.first <= x1 - 1)
                    if(max(low, i.first) <= min(x1 - 1, i.second))
                        nRange.push_back({max(low, i.first), min(x1 - 1, i.second)});
                if(i.second >= x2 + 1 && i.first <= high)
                    if(max(x2 + 1, i.first) <= min(high, i.second))
                        nRange.push_back({max(x2 + 1, i.first), min(high, i.second)});
            }
            sort(nRange.begin(), nRange.end());
            Range = nRange;
        }
        else{
            // <<
            high = x2 - 1;
            for(auto i:Range){
                if(i.second < low || i.first > high)
                    continue;
                if(max(low, i.first) <= min(high, i.second))
                    nRange.push_back({max(low, i.first), min(high, i.second)});
            }
            Range = nRange;
        }
    }
}