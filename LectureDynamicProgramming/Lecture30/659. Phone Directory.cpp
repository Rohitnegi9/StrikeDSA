class TrieNode{
    public:

    TrieNode *children[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }

    ~TrieNode(){
        for(int i=0;i<26;i++){
            delete children[i];
        }
    }
};

class Solution {
public:

    void insert(TrieNode *curr , string &word){

        for(char ch: word){
            int index = ch-'a';

            if(curr->children[index]==NULL){
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }

    void getResult(TrieNode* curr, string &word, vector<string>&ans){
        if(curr->isEnd==true){
            ans.push_back(word);
        }

        for(int i=0;i<26;i++){
            if(curr->children[i]){
                char ch = 'a'+i;
                word.push_back(ch);
                getResult(curr->children[i],word,ans);
                word.pop_back();
            }
        }
    }


    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // Your code here
        
        TrieNode *root = new TrieNode();
         
         for(int i=0;i<n;i++){
            insert(root, contact[i]);
         }

         // prefix answer niklna
         vector<vector<string>>result;
         string prefix = "";
         bool isMatch = true;

         TrieNode *curr = root;

         for(char ch: s){

            int index = ch-'a';
            prefix.push_back(ch);

            if(isMatch==false){
                result.push_back({"0"});
                continue;
            }

            if(curr->children[index]==NULL){
                result.push_back({"0"});
                isMatch = false;
                continue;
            }


            curr = curr->children[index];
            vector<string>ans;
            string word = prefix;
            getResult(curr,word,ans);
            result.push_back(ans);
         }


         delete root;

         return result;

    }

};

