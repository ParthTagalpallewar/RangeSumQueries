#include<bits/stdc++.h>
#define ll long long
using namespace std;

class SegmentTree{
private:
    vector<ll> tree;
    int size;


    void buildTree(int idx, int l, int r, vector<int> &arr){
        if(l == r){
            tree[idx] = arr[l];
            return;
        }

        int mid = (l+r)/2;
        buildTree(2*idx+1, l, mid, arr);
        buildTree(2*idx+2, mid+1, r, arr);

        tree[idx] = tree[2*idx+1]+tree[2*idx+2];
    }

    int innerQuery(int idx, int l, int r, int ql, int qr){
        // out of range of current query
        if (ql > r || qr < l)
            return 0;

        // query l and r is inside range
        if(ql <= l && qr >= r) return tree[idx];

        int mid = (l+r)/2;

        int left = innerQuery(2*idx+1, l, mid, ql, qr);
        int right = innerQuery(2*idx+2, mid+1, r, ql, qr);
        return left+right;
    }

    void innerUpdate(int idx, int i, int num, int l, int r){
        if(l == r){
            tree[idx] = num;
            return;
        }

        int mid = (l + r) / 2;

        if(i <= mid)
            innerUpdate(2 * idx + 1, i, num, l, mid);
        else
            innerUpdate(2 * idx + 2, i, num, mid + 1, r);

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }



public:
    SegmentTree(vector<int> &arr){
        size = arr.size();
        tree.resize(4*size);
        buildTree(0, 0, size-1, arr);
    }

    int query(int l, int r){
        return innerQuery(0, 0, size-1, l, r);
    }

    int update(int idx, int num){
        innerUpdate(0, idx, num, 0, size-1);
    }

    void print(){
        for(auto &i: tree)
            cout << i << " ";
    }
};

int main(){

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    SegmentTree st(arr);

    st.update(2, 0);
    cout << st.query(0,5);

    return 0;
}