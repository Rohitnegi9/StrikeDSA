#include<iostream>
using namespace std;

// How our trieNode will look like

class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;

        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};



class Trie{
    public:

    TrieNode *root;

    Trie(){
        root = new TrieNode();
    }

    // insert

    void insert(string word){
        TrieNode* curr = root;

        for(char ch: word){
            int index = ch-'a';

            if(curr->children[index]==NULL){
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }

    
    bool search(string word){
        TrieNode* curr = root;

        for(char ch: word){
            int index = ch-'a';

            if(curr->children[index]==NULL){
                return false;
            }

            curr = curr->children[index];
        }

        return curr->isEnd;
    }


    bool prefix(string word){
        TrieNode* curr = root;

        for(char ch: word){
            int index = ch-'a';

            if(curr->children[index]==NULL){
                return false;
            }

            curr = curr->children[index];
        }

        return true;
    }

};




int main(){

    Trie trie;

    trie.insert("car");
    trie.insert("card");
    trie.insert("carrom");
    trie.insert("app");
    trie.insert("apple");
    trie.insert("apps");
    trie.insert("base");
    trie.insert("back");

    cout<<trie.search("car")<<endl;
    cout<<trie.search("card")<<endl;
    cout<<trie.search("carromss")<<endl;
    cout<<trie.search("ba")<<endl;
    cout<<trie.search("base")<<endl;
    cout<<trie.search("app")<<endl;

    cout<<trie.prefix("car")<<endl;
    cout<<trie.prefix("card")<<endl;
    cout<<trie.prefix("carromss")<<endl;
    cout<<trie.prefix("ba")<<endl;
    cout<<trie.prefix("base")<<endl;
    cout<<trie.prefix("app")<<endl;
    cout<<trie.prefix("apk")<<endl;


    return 0;


}