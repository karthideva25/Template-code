class FenwickTree{
    vector<int> bit,arr;
    int n;
public:
    FenwickTree(){}
    FenwickTree(vector<int>& nums){
        n = nums.size();
        bit.resize(n+1,0);
        arr = vector<int>(nums.begin(),nums.end());
        build(arr);
    }
    void update(int id, int val){
        upd(id+1,-arr[id]);
        arr[id] = val;
        upd(id+1,arr[id]);
    }
    int rangeQuery(int l, int r){
        if (l == 0){
            return query(r+1);
        }
        return query(r+1) - query(l);
    }
    void print(){
        for(int i=1;i<=n;i++){
            cout << bit[i] << " ";
        }
        cout << endl;
    }
private:
    void build(vector<int>& arr){
        for(int i=0;i<n;i++){
            upd(i+1,arr[i]);
        }
    }
    // 1 to id sum will return
    // always remember BIT is 1 Based
    int query(int id){
        int sum = 0;
        while(id > 0){
            sum += bit[id];
            id -= (id & -id);
        }
        return sum;
    }
    // always remember BIT is 1 Based
    // starts with id and goes till n and add exponentially
    void upd(int id, int val){
        while(id <= n){
            bit[id] += val;
            id += (id & -id);
        }
    }
};

class NumArray {
    FenwickTree tree;
public:
    NumArray(vector<int>& nums) {
        FenwickTree tre(nums);
        this->tree = tre;
    }
    
    void update(int index, int val) {
        tree.update(index,val);
    }
    
    int sumRange(int left, int right) {
        return tree.rangeQuery(left,right);
    }
};
