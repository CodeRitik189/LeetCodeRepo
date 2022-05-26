struct Node{
    Node* child[26];
    bool fl;
    
    Node(){
       for(int i=0;i<26;i++){
           child[i] = NULL;
       }
        fl = false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
       root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        int i = 0;
        
        while(i<word.size()){
           if(!node->child[word[i]-'a']){
               node->child[word[i]-'a'] = new Node();
           }
           node = node->child[word[i]-'a'];
           i++;
        }
         node -> fl = true;
    }
    
    bool search(string word) {
        Node* node = root;
        int i = 0;
        
        while(i<word.size()){
           if(!node->child[word[i]-'a']){
               return false;
           }
           node = node->child[word[i]-'a'];
           i++;
        }
         return node->fl;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        int i = 0;
        
        while(i<prefix.size()){
           if(!node->child[prefix[i]-'a']){
               return false;
           }
           node = node->child[prefix[i]-'a'];
           i++;
        }
         return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */