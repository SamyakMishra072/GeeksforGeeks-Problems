#include <bits/stdc++.h>
using namespace std;

struct Line {
    long long m, c; // y = m*x + c
    Line(long long _m, long long _c) : m(_m), c(_c) {}
    
    long long eval(long long x) const { return m*x + c; }
    
    // intersection point with another line
    // returns x-coordinate of intersection (as double)
    double intersectX(const Line &other) const {
        return double(other.c - c) / (m - other.m);
    }
};

struct ConvexHullTrick {
    deque<Line> dq;

    // Add line y = m*x + c, slopes must be added in decreasing order for min query
    void addLine(long long m, long long c) {
        Line newLine(m, c);
        while(dq.size() >= 2) {
            auto &l1 = dq[dq.size()-2];
            auto &l2 = dq[dq.size()-1];
            // check if l2 is useless
            double x1 = l1.intersectX(l2);
            double x2 = l1.intersectX(newLine);
            if(x2 <= x1) dq.pop_back();
            else break;
        }
        dq.push_back(newLine);
    }

    // Query min value at x (assumes queries are in non-decreasing x)
    long long query(long long x) {
        while(dq.size() >= 2 && dq[0].eval(x) >= dq[1].eval(x)) dq.pop_front();
        return dq[0].eval(x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ConvexHullTrick cht;
    int n; 
    cin >> n; // number of operations
    for(int i=0; i<n; i++){
        string op;
        cin >> op;
        if(op == "add") {
            long long m, c;
            cin >> m >> c;
            cht.addLine(m, c);
        } else if(op == "query") {
            long long x;
            cin >> x;
            cout << cht.query(x) << "\n";
        }
    }
}
