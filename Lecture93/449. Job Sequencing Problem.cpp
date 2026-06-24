bool comp(pair<int,int>&a, pair<int,int>&b){
    return a.first>=b.first;
}

int findEmptySpace(int u, vector<int>&parent){
    if(u==parent[u])
    return u;

    return parent[u] = findEmptySpace(parent[u],parent);
}

class Solution {
public:
    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        // code here
        // we have to sort the array on the basis of profit;

        vector<pair<int,int>>arr;
        int n = deadline.size();

        for(int i=0;i<n;i++){
            arr.push_back({profit[i],deadline[i]});
        }
         
        // profit wala: desceneding order 
        sort(arr.begin(),arr.end(),comp);

        int totalProfit = 0, totalTask = 0;
        // vector<bool>dead(n+1,0);
        vector<int>parent(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }

        for(int i=0;i<n;i++){
            int slot = arr[i].second;


            slot = findEmptySpace(slot,parent);

            // while(slot){
            //     if(dead[slot]==0)
            //         break;
            //     slot--;
            // }

            if(slot>0){
                parent[slot] = slot-1;
                totalTask++;
                totalProfit+= arr[i].first;
            }
        }

        vector<int>result;
        result.push_back(totalTask);
        result.push_back(totalProfit);
        return result;
    }
};