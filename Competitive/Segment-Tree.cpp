#include<bits/stdc++.h>
using namespace std;
#define ll long long

class SegTree{
    vector<long long int> seg;
public:
    SegTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind, int low, int high, vector<long long int> arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high-low)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1,high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        return;
    }
    long long int query(int ind, int low, int high, int l ,int r){
        if(r<low || l>high) return 0;
        if(low>=l && high <= r) return seg[ind];
        int mid = low + (high-low)/2;
        long long int left = query(2*ind+1,low,mid,l,r);
        long long int right = query(2*ind+2,mid+1,high,l,r);
        return left + right;
    }
    void update(int ind, int low, int high, int i, long long int val){
        if(i>high || i<low) return;
        if(low == high && low == i){
            seg[ind] = val;
            return;
        }
        int mid = low + (high-low)/2;
        if(i<=mid)update(2*ind+1, low, mid, i,val);
        else update(2*ind+2, mid+1,high, i,val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        return;
    }
};
