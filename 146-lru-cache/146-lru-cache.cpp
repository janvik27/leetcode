class LRUCache {
public:
    //initializing the doubly linked list
    class node{
        public:
        int key, val;
        node* next;
        node* prev;
        
        node(int k,int v)
        {
            key= k;
            val=v;
        }
    };
    
    node* head= new node(-1,-1);
    node* tail= new node(-1,-1);
    
    int cap;
    unordered_map<int,node*> m;
    
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next= tail;
        tail->prev= head;
    }
    
    void addnode(node* newnode)
    {
        node* temp = head->next;
        newnode->next= temp;
        newnode->prev= head;
        head->next= newnode;
        temp->prev= newnode;
    }
    
    void deletenode(node* delnode)
    {
        node* prevnode= delnode->prev;
        node* nextnode= delnode->next;
        prevnode->next= nextnode;
        nextnode->prev= prevnode;
    }
    
    int get(int key) {
        if(m.find(key) != m.end())
        {
            node* resnode= m[key];
            int res= resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key]= head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //if the key to be inserted already exists in hashmap with a diff value
        if(m.find(key) != m.end())
        {
            node* existingnode= m[key];
            // m.erase(key);
            deletenode(existingnode);
        }
        
        //if the capacity is full
        else if(m.size()== cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        node* newnode= new node(key,value);
        addnode(newnode);
        m[key]= head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */