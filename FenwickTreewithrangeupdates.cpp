#include <bits/stdc++.h>
using namespace std;

class Fenwick {
    int n;
    vector<long long> bit;

public:
    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // add value v at index i
    void add(int i, long long v) {
        while (i <= n) {
            bit[i] += v;
            i += i & -i;
        }
    }

    // sum from 1 to i
    long long sum(int i) {
        long long s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    // add v to range [l, r]
    void range_add(int l, int r, long long v) {
        add(l, v);
        if (r + 1 <= n)
            add(r + 1, -v);
    }

    // get value at index i
    long long point_query(int i) {
        return sum(i);
    }
};
