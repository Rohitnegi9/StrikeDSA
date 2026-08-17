class Solution {
public:
    
    vector<int>tree;
    int n;

    void update(int node, int start, int end, int index, int val){
        if(start==end){
            tree[node] = val;
            return;
        }

        int mid = start+(end-start)/2;

        if(index<=mid)
        update(2*node+1,start,mid,index,val);
        else
        update(2*node+2,mid+1,end,index,val);


        tree[node] = max(tree[2*node+1],tree[2*node+2]);
    }

    int query(int node, int start, int end, int left, int right){
        // out of range
        if(end<left || start>right)
        return 0;


        // complete range ke andar hu
        if(left<=start && end<=right)
        return tree[node];

        // partial range
        int mid = start+(end-start)/2;

        int leftGap = query(2*node+1,start,mid, left,right);
        int rightGap = query(2*node+2,mid+1,end, left,right);

        return max(leftGap,rightGap);
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        // Your code here

        n = 0;

        for(auto &q: queries){
            n = max(n,q[1]);
        }

        tree.resize(4*(n+1),0);
        set<int>obstacles;
        obstacles.insert(0);
        vector<bool>result;

        // set ; 0, 4, 10, 15
        // x = 7
        for(auto &q: queries){

            // Insert Obstacles
            if(q[0]==1){

                int x = q[1];

                // x ke previous aur next jo obstacle hai, unko dhoondna hai
                // first value which is greater than x;

                auto nextIt = obstacles.upper_bound(x);
                auto prevIt = prev(nextIt);

                
                update(0,0,n,x,x-*prevIt);

                if(nextIt!=obstacles.end()){
                    update(0,0,n,*nextIt,*nextIt-x);
                }


               obstacles.insert(x);

            }
            else{

                int x = q[1];
                int sz = q[2];
                
                
                auto nextIt = obstacles.upper_bound(x);
                --nextIt;
                int prevObstacle = *nextIt;


                int completeGap = query(0,0,n,0,prevObstacle);
                int endGap = x-prevObstacle;

                int maxGap = max(completeGap,endGap);

                result.push_back(maxGap>=sz);

            }



            // Find that if that box can pe but into that range
        }

        return result;
    }
};