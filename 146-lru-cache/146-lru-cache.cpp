struct Node{
    public:
      int key,val;
      Node* prev;
      Node* next;
      Node(int key_,int val_){
          key = key_;
          val = val_;
      }
};

class LRUCache {
public:
    unordered_map<int,Node*>um;
    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void insertnode(Node* node){
        head-> next-> prev = node;
        node-> next = head -> next;
        
        head -> next = node;
        node -> prev = head;
    }
    
    void deletenode(Node* node){
        node -> next -> prev = node -> prev;
        node -> prev -> next = node -> next;
    }
    
    int get(int key_) {
        int ans = -1;
        if(um.find(key_)!=um.end()){
            ans = um[key_]->val;
            deletenode(um[key_]);
            um.erase(key_);
            insertnode(new Node(key_,ans));
            um[key_] = head -> next;
        }
        return ans;
    }
    
    void put(int key_, int val_) {
        if(um.find(key_)!=um.end()){
            deletenode(um[key_]);
            um.erase(key_);
        }
        if(um.size()==cap){
            um.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        insertnode(new Node(key_,val_));
        um[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */