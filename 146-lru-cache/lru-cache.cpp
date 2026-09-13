class LRUCache {
public:
class Node{
    public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v){
        key=k;
        val=v;
        prev=nullptr;
        next=nullptr;
    }
};

unordered_map<int, Node*>mpp;
Node* head;
Node* tail;
int k;

    LRUCache(int capacity) {
        this->k=capacity;     
        head = new Node(-1,-1);
        tail= new Node(-1, -1);
        head->next=tail;
        tail->prev=head; 
    }

    void insertatend(Node* node){
        node->next=tail;
        node->prev=tail->prev;
        tail->prev->next=node;
        tail->prev=node;
    }

    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void removefromfront(){
        Node* node=head->next;
        remove(node);
        mpp.erase(node->key);
        delete node;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* node= mpp[key];
            remove(node);
            insertatend(node);
            return node->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            remove(node);
            insertatend(node);
        }
        else{
            Node* node = new Node(key, value);
            mpp[key]=node;
            insertatend(node);
            if(mpp.size()>k){
                removefromfront();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */