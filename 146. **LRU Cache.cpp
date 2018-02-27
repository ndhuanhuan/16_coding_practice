//http://bangbingsyb.blogspot.com/2014/11/leetcode-lru-cache.html

class LRUCache{
public:

     struct Node {
        int val;
        int key;
        Node *next;
        Node *prev;
        Node(int k, int v):key(k),val(v) {}
    };

    int maxSize;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> keyToNode;


    LRUCache(int capacity) {
        maxSize = capacity;
        head = NULL;
        tail = NULL;
        keyToNode.clear();
    }

    int get(int key) {
        if(keyToNode.count(key)==0) return -1;
        moveToEnd(key);
        return keyToNode[key]->val;
    }

    void set(int key, int value) {
        if(get(key)!=-1)
        {
                keyToNode[key]->val =value;
                return;
        }
        if(isFull()) removeHead();
        insertToEnd(key,value);

    }
    bool isFull()
    {
        return keyToNode.size()>=maxSize;
    }

    void insertToEnd(int key,int value)
    {
        if(isFull()||keyToNode.count(key)!=0)
        {
            return;
        }
        Node *nd = new Node(key,value);
        keyToNode[key] = nd;
        if(!head)
        {
            head = tail =nd;
        }
        else
        {
            tail->next = nd;
            nd ->prev = tail;
            tail = tail->next;
        }
    }
    
    void removeHead()
    {
        if(!head) return;
        keyToNode.erase(head->key);
        Node *temp = head;
        if(head==tail)
            head = tail =NULL;
        else
        {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }
    
    void moveToEnd(int key)
    {
        if(keyToNode.count(key)==0||keyToNode[key]==tail) return;
        Node *nd = keyToNode[key];
        if(nd==head)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {
            nd->prev->next = nd->next;
            nd ->next ->prev = nd->prev;
        }
        
        tail->next = nd;
        nd->prev = tail;
        nd->next =NULL;
        tail = tail->next;
    
    
    }

};
