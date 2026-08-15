class SegmentTree {
public:
    vector<long long>tree;
    vector<long long>lazy;
    int n;

    SegmentTree(vector<int>& arr) {
        // Your initialization code here
        n = arr.size();
        tree.resize(4*n);
        lazy.resize(4*n,0);
        buildTree(0,0,n-1,arr);
    }


    void buildTree(int node, int start, int end, vector<int>&arr){
        if(start==end){
            tree[node]=arr[start];
            return;
        }

        int mid = start+(end-start)/2;

        buildTree(2*node+1,start,mid,arr);
        buildTree(2*node+2,mid+1,end,arr);

        tree[node] = tree[2*node+1]+tree[2*node+2];
    }

    void updateChild(int node, int start, int end){
        // child ko update karne ki jarurat nahi hai

        if(lazy[node]==0)
        return;

        // child ko update ki jarurat hai
        if(start==end){
            lazy[node] = 0;
            return;
        }


        // warna update karo maje mein
        int mid = start+(end-start)/2;

        // left child ke node ki value increase karni hai
        // right child ke node ki value ko increase karna hai

        int leftChild = 2*node+1;
        int rightChild = 2*node+2;

        tree[leftChild] += lazy[node]*(mid-start+1);
        tree[rightChild] += lazy[node]*(end-mid);


        lazy[leftChild]+=lazy[node];
        lazy[rightChild]+=lazy[node];
        
        // I have already given update to my children now mark it zero
        lazy[node] = 0;
    }


    void updateQuerry(int node, int start, int end, int left, int right, int val){
        // no overlapping
        if(end<left || start>right){
            return;
        }

        // complete overlap;
        if(left<=start && end<=right){
            tree[node]+= 1LL*val*(end-start+1);
            lazy[node]+=val;
            return;
        }


         // left bhi jaa raha th, right side bhi jaa raha th
        // children ke liye koi bhi update hai, agar hai toh unke child ko update kar dena
        updateChild(node,start,end);



        // partial overlap

        int mid = start+(end-start)/2;
        updateQuerry(2*node+1,start,mid, left,right,val);
        updateQuerry(2*node+2,mid+1, end, left,right,val);

        tree[node] = tree[2*node+1]+tree[2*node+2];

    }


    long long rangeQuery(int node, int start, int end, int left, int right){
        // out of range: 0
        if(end<left || start>right){
            return 0;
        }

        // within range ke andar hai
        if(left<=start && end<=right)
        return tree[node];


        // left bhi jaa raha th, right side bhi jaa raha th
        // children ke liye koi bhi update hai, agar hai toh unke child ko update kar dena

        updateChild(node,start,end);

        int mid = start+(end-start)/2;

        int leftSum = rangeQuery(2*node+1,start,mid,left,right);
        int rightSum = rangeQuery(2*node+2,mid+1,end,left,right);

        return leftSum+rightSum;

    }


    
    void update(int left, int right, int val) {
        // Your code here

        updateQuerry(0,0,n-1,left,right,val);
    }
    
    long long query(int left, int right) {
        // Your code here

        return rangeQuery(0,0,n-1,left,right);

    }
};