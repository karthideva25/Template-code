#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    struct Node {
        long long sum;
        int mn;
    };

    int n;
    vector<Node> tree;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    // Identity element (neutral node)
    Node identity() {
        return {0, INT_MAX};
    }

    // Merge two nodes
    Node merge(const Node &a, const Node &b) {
        return {
            a.sum + b.sum,
            min(a.mn, b.mn)
        };
    }

    // Build from array (1-indexed)
    void build(int idx, int l, int r, const vector<int> &arr) {
        if (l == r) {
            tree[idx] = {arr[l], arr[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx, l, mid, arr);
        build(2 * idx + 1, mid + 1, r, arr);
        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    // Point update: arr[pos] = val
    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            tree[idx] = {val, val};
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);
        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    // Range query [ql, qr]
    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r)
            return identity();
        if (ql <= l && r <= qr)
            return tree[idx];
        int mid = (l + r) / 2;
        return merge(
            query(2 * idx, l, mid, ql, qr),
            query(2 * idx + 1, mid + 1, r, ql, qr)
        );
    }
};
