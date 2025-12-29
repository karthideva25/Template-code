class Fenwick {
    vector<int> bit;
    int n;

public:
    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // Point update: add val at index i
    void update(int i, int val) {
        for (; i <= n; i += i & -i) {
            bit[i] += val;
        }
    }

    // Prefix sum from 1 to i
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }

    // Range sum [l, r]
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};
