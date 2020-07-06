// Con Hull - https://s3.amazonaws.com/codechef_shared/download/Solutions/FEB18/Setter/POINPOLY.cpp
// https://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

class pt {
public:
    LL x, y;
    pt() {}
    pt(int _x, int _y) {
        x = _x;
        y = _y;
    }
    bool operator<(const pt &rhs) const {
        return make_pair(x, y) < make_pair(rhs.x, rhs.y);
    }
    pt operator-(const pt &rhs) const {
        return pt(x - rhs.x, y - rhs.y);
    }
};

LL cross(pt a, pt b) {
    return a.x * (LL) b.y - b.x * (LL) a.y;
}

LL cross(pt a, pt b, pt c) {
    return cross(b - a, c - b);
}

vector<pt> findHull(vector<pt> p, int lower = true) {
    sort(p.begin(), p.end());
    vector<pt> hull;
    for (int i = 0; i < p.size(); i++) {
        int sign = lower ? -1 : 1;
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull[hull.size() - 1], p[i]) * sign >= 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }
    return hull;
}

bool checkGood(vector<pt> &hull, int lower, pt p) {
    const int INF = 1e9 + 10;
    auto it = lower_bound(hull.begin(), hull.end(), p);
    if (it != hull.end()) {
        int idx = it - hull.begin();
        // printf("idx = %d, x = %d, y = %d\n", idx, hull[idx].x, hull[idx].y);
        if (idx != 0) {
            int sign = lower ? 1 : -1;
            return cross(hull[idx - 1], hull[idx], p) * sign > 0;
        }
    }
    return false;
}

bool pointStrictlyInPolyTest(vector<pt> &lower, vector<pt> &upper, pt p) {
    return checkGood(lower, true, p) && checkGood(upper, false, p);
}

void print(vector<pt> p) {
    cout << "{ " << endl;
    for (auto it: p) {
        printf("\t %d, %d\n", it.x, it.y);
    }
    cout << "}" << endl;
}


bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector <pt> convexHull(vector<pt> a) {
    if (a.size() == 1){
        return a;
    }

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
    return a;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, q;
        scanf("%d%d", &n, &q);
        vector<pt> p;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            p.push_back(pt(x, y));
        }
        sort(p.begin(), p.end());
        vector<vector<pt> > Lo, Up;
        while(p.size() >= 3){
            vector <pt> P = convexHull(p), newp;
            reverse(P.begin(), P.end());
            // print(P);
            if(P.size() < 3){
                break;
            }
            vector<pt> lower = findHull(P, true);
            vector<pt> upper = findHull(P, false);
            Lo.push_back(lower);
            Up.push_back(upper);
            for(auto i:p){
                if(pointStrictlyInPolyTest(lower, upper, i))
                    newp.push_back(i);
            }
            p = newp;
        }
        while(q--){
            int x, y;
            cin >> x >> y;
            pt it = pt(x, y);
            int i;
            for(i = 0; i < Lo.size(); i++)
                if(!pointStrictlyInPolyTest(Lo[i], Up[i], it))
                    break;
            cout << i << '\n';
        }
    }
    return 0;
}