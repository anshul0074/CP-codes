#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* next[26];
    bool istr=false;
    TrieNode(){
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
};
class Trie {
    public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    void insert(string word) {
        TrieNode* ptr=root;
        for(int i=0;i<word.size();i++){
            if(ptr->next[word[i]-'a']==NULL){
                ptr->next[word[i]-'a']=new TrieNode();
            }
            ptr=ptr->next[word[i]-'a'];
        }
        ptr->istr=true;
    }
    bool search(string word) {
        TrieNode* ptr=root;
        for(int i=0;i<word.size();i++){
            if(ptr==NULL){
                return false;
            }
            ptr=ptr->next[word[i]-'a'];
        }
        if(ptr==NULL or ptr->istr==false){
            return false;
        }
        return true;
    }
    bool isprefix(string prefix) {
        TrieNode* ptr=root;
        for(int i=0;i<prefix.size();i++){
            ptr=ptr->next[prefix[i]-'a'];
            if(ptr==NULL){
                return false;
            }
        }
        return true;
    }
};
int main(){
    Trie* trie = new Trie();
    trie->insert("realisation");
    cout<<trie->search("realisation")<<"\n";   
    cout<<trie->search("real")<<"\n";     
    cout<<trie->isprefix("real")<<"\n"; 
    trie->insert("realise");
    cout<<trie->search("realise")<<"\n";     
}