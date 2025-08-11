class LRUNode {
public:
    int key;
    int val;
    LRUNode* prev;
    LRUNode* next;
    LRUNode(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    int capacity;
    unordered_map<int, LRUNode*> cache;
    LRUNode* head;
    LRUNode* tail;

    void addNode(LRUNode* node) {
        LRUNode* prevEnd = tail->prev;
        prevEnd->next = node;
        node->prev = prevEnd;
        node->next = tail;
        tail->prev = node;
    }

    void deleteNode(LRUNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new LRUNode(-1, -1);
        tail = new LRUNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            LRUNode* node = cache[key];
            deleteNode(node);
            addNode(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            LRUNode* oldNode = cache[key];
            deleteNode(oldNode);
            delete oldNode;
            cache.erase(key);
        }

        LRUNode* newNode = new LRUNode(key, value);
        cache[key] = newNode;
        addNode(newNode);

        if (cache.size() > capacity) {
            LRUNode* toDelete = head->next;
            deleteNode(toDelete);
            cache.erase(toDelete->key);
            delete toDelete;
        }
    }
};
