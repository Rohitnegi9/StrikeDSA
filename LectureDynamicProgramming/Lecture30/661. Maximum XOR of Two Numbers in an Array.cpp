class TrieNode{
    public:

    TrieNode *children[2];

    TrieNode(){
        children[0]=NULL;
        children[1] = NULL;
    }


    ~TrieNode(){
        delete children[0];
        delete children[1];
    }


};

class Solution {
public:

    void insert(TrieNode *curr, int num){

        // total 31 bit insert
        for(int i=30;i>=0;i--){
            int bit = (num>>i) & 1;

            if(curr->children[bit]==NULL){
                curr->children[bit] = new TrieNode();
            }

            curr = curr->children[bit];
        }
    }

    int getMaxOr(TrieNode *curr, int num){
        
        int answer = 0;

        for(int i=30;i>=0;i--){
            int bit = (num>>i) & 1;
            int opposite = 1-bit;

            if(curr->children[opposite]){
                answer = answer | (1<<i);
                curr = curr->children[opposite];
            }
            else{
                curr = curr->children[bit];
            }
        }

        return answer;

    }


    int findMaximumXOR(vector<int>& nums) {
        // Your code here
        TrieNode *root = new TrieNode();


        for(int i=0;i<nums.size();i++){
            insert(root,nums[i]);
        }


        int result = 0;
        for(int i=0;i<nums.size();i++){
            int maxOr = getMaxOr(root,nums[i]);
            result = max(result,maxOr);
        }

        delete root;

        return result;
    }
};