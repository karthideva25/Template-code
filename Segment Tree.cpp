class SegmentTree{
    vector<int> seg;
    int n;
public:
    SegmentTree(){
        
    }
    SegmentTree(vector<int>& arr){
        n = arr.size();
        seg.resize(4*n);
        build(0,0,n-1,arr);
    }
    int rangeQuery(int l, int r){
        return query(0,0,n-1,l,r);
    }
    void pointUpdates(int pos, int val){
        update(0,0,n-1,pos,val);
    }
private:
    void build(int ind, int low, int high, vector<int>& arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    int query(int ind, int low, int high, int l, int r){
        // no overlap low high l r || l r low high
        if(high < l or r < low){
            return 0;
        }
        // complete overlap l low high r
        else if(l <= low and high <= r){
            return seg[ind];
        }
        // partial overlap
        int mid = (low + high) / 2;
        return query(2*ind+1, low, mid, l, r)
        + query(2*ind+2, mid+1, high, l, r);
    }
    void update(int ind, int low, int high, int pos, int val){
        // no overlap low high pos || pos low high
        if(pos > high or pos < low){
            return;
        }
        // complete overlap low pos high
        if(low == pos and high == pos){
            seg[ind] = val;
            return;
        }
        // partial overlap case
        int mid = (low + high) >> 1;
        update(2*ind+1, low, mid, pos, val);
        update(2*ind+2, mid+1, high, pos, val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    
};
class NumArray {
public:
    SegmentTree seg;
    NumArray(vector<int>& nums) {
        SegmentTree tree(nums);
        this->seg = tree;
    }
    
    void update(int index, int val) {
        seg.pointUpdates(index,val);
    }
    
    int sumRange(int left, int right) {
        return seg.rangeQuery(left,right);
    }
};
















#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> seg;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int idx, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r) {
        // No overlap
        if (r < low || high < l)
            return 0;

        // Complete overlap
        if (l <= low && high <= r)
            return seg[idx];

        // Partial overlap
        int mid = (low + high) / 2;
        return query(2 * idx + 1, low, mid, l, r) +
               query(2 * idx + 2, mid + 1, high, l, r);
    }

    void update(int idx, int low, int high, int pos, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int rangeQuery(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void pointUpdate(int pos, int val) {
        update(0, 0, n - 1, pos, val);
    }
};


int main(){
    vector<int> arr = {1,2,3,4,5};
    SegmentTree seg(arr);
    seg.rangeQuery(2,3);
    seg.pointUpdate(2,5);
    seg.rangeQuery(2,3);
    return 0;
}
