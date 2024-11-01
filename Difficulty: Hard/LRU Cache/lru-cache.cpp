//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  
    class DDL {
      public:
        int key;
        int value;
        DDL *prv, *next;
    
        DDL(int k, int v) {
            key = k;
            value = v;
            prv = NULL;
            next = NULL;
        }
    };
    
    int cp, len;
    DDL* head, *tail;
    unordered_map<int, DDL*> mp;
    

    // Helper function to remove a node from its current position
    void removeNode(DDL* node) {
        DDL* b = node->prv;
        DDL* f = node->next;
        b->next = f;
        f->prv = b;
    }

    // Helper function to add a node right after the head
    void addToFront(DDL* node) {
        node->next = head->next;
        node->prv = head;
        head->next->prv = node;
        head->next = node;
    }

  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        cp = cap;
        len = 0;
        head = new DDL(-1, -1);
        tail = new DDL(-1, -1);
        head->next = tail;
        tail->prv = head;
    }

    ~LRUCache() {
        mp.clear();
        delete head;
        delete tail;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            DDL* node = mp[key];
            removeNode(node);  // Move it to the front as it's accessed
            addToFront(node);
            return node->value;
        } else {
            return -1;
        }
    }

    // Function for storing key-value pair.
    void set(int key, int value) {
        if (mp.find(key) != mp.end()) {
            DDL* node = mp[key];
            removeNode(node);  // Remove it from the current position
            node->value = value;  // Update value
            addToFront(node);  // Move to front
        } else {
            if (len == cp) {  // Cache is full
                DDL* lru = tail->prv;
                removeNode(lru);  // Remove the LRU element
                mp.erase(lru->key);
                delete lru;
                len--;
            }
            DDL* newNode = new DDL(key, value);
            mp[key] = newNode;
            addToFront(newNode);
            len++;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "SET") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends