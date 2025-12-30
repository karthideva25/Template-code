class SegmentTree {
    vector<long long> seg, lazy;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        lazy.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int node, int start, int end, vector<int>& arr) {
        if (start == end) {
            seg[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid, arr);
        build(2 * node + 2, mid + 1, end, arr);
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            int mid = (start + end) / 2;
            int left = 2 * node + 1;
            int right = 2 * node + 2;

            // Apply lazy to children
            seg[left] += (mid - start + 1) * lazy[node];
            seg[right] += (end - mid) * lazy[node];

            lazy[left] += lazy[node];
            lazy[right] += lazy[node];

            lazy[node] = 0;
        }
    }

    void rangeUpdate(int node, int start, int end, int l, int r, int val) {
        if (r < start || end < l)
            return;

        if (l <= start && end <= r) {
            seg[node] += (end - start + 1) * val;
            lazy[node] += val;
            return;
        }

        push(node, start, end);

        int mid = (start + end) / 2;
        rangeUpdate(2 * node + 1, start, mid, l, r, val);
        rangeUpdate(2 * node + 2, mid + 1, end, l, r, val);

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;

        if (l <= start && end <= r)
            return seg[node];

        push(node, start, end);

        int mid = (start + end) / 2;
        return query(2 * node + 1, start, mid, l, r) +
               query(2 * node + 2, mid + 1, end, l, r);
    }

    // Helpers
    void updateRange(int l, int r, int val) {
        rangeUpdate(0, 0, n - 1, l, r, val);
    }

    long long rangeQuery(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};
