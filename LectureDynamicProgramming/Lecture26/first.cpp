#include<iostream>
using namespace std;


class SegmentTree{
    public:
    vector<int>tree;
    int n;
   // array ka size hai original wala
    SegmentTree(vector<int>&arr){
        n = arr.size();
        tree.resize(4*n);
        // buildTree;
        buildTree(0,0,n-1,arr);
    }

    void buildTree(int node,int start, int end, vector<int>&arr){
        
        if(start==end){
            tree[node]= arr[start];
            return;
        }

        int mid = start+(end-start)/2;

        buildTree(2*node+1,start,mid,arr);
        buildTree(2*node+2,mid+1,end,arr);


        tree[node] = tree[2*node+1]+tree[2*node+2];
    }

    int rangeQuerry(int node, int start, int end, int left, int right){
        // 1: Out of range
        if(end<left || start>right){
            return 0;
        }
        // 2: Completely range ke andar hai
        if(left<=start && end<=right){
            return tree[node];
        }
        // 3: Partial range

        int mid = start+(end-start)/2;

        int leftSum = rangeQuerry(2*node+1,start,mid,left,right);
        int rightSum = rangeQuerry(2*node+2,mid+1,end,left,right);

        return leftSum+rightSum;
    }


    void updateQuerry(int node, int start, int end, int index, int val){

        if(start==end){
            tree[node] = val;
            return;
        }

        int mid = start+(end-start)/2;

        if(index<=mid){
            updateQuerry(2*node+1,start,mid,index,val);
        }
        else{
            updateQuerry(2*node+2,mid+1,end,index,val);
        }

        tree[node] = tree[2*node+1]+tree[2*node+2];
    }
};


int main(){

    vector<int>arr = {1,5,2,6,91,8,6,8,90,11,23,10,2,4,8,19};

    SegmentTree st(arr);
    int n = arr.size();

    // 3,8 --> Range query ka answer kya hai
    // left = 3, right = 8

    cout<<st.rangeQuerry(0,0,n-1,3,8);

    st.updateQuerry(0,0,n-1,4,5);
    cout<<endl;
    cout<<st.rangeQuerry(0,0,n-1,3,8);


}