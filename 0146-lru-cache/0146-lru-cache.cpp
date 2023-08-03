#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    
    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void moveToHead(Node* node) {
        removeNode(node);
        addToFront(node);
    }
    
    void evict() {
        Node* toEvict = tail->prev;
        removeNode(toEvict);
        cache.erase(toEvict->key);
        delete toEvict;
    }
    
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1); // Dummy head node
        tail = new Node(-1, -1); // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            addToFront(newNode);
            cache[key] = newNode;
            if (cache.size() > capacity) {
                evict();
            }
        }
    }
    
    ~LRUCache() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
