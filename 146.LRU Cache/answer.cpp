#include <unordered_map>
#include <list>
#include <exception>

class LRUNode
{
public:
    LRUNode *front = nullptr;
    LRUNode *back = nullptr;
    int key = -1;
    int value = -1;
    LRUNode(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCache
{
private:
    int size = 0;
    LRUNode *first = nullptr;
    LRUNode *last = nullptr;

    std::unordered_map<int, LRUNode *> map;

    int capacity;
    int dequeue()
    {
        auto first = this->first;
        if (first != nullptr)
        {
            auto back = first->back;
            if (back != nullptr)
            {
                back->front = nullptr;
            }
            auto k = first->key;
            this->first = back;
            if (back == nullptr)
            {
                this->last = nullptr;
            }
            delete first;
            return k;
        }
        return -1;
    }
    LRUNode *push(int key, int value)
    {
        auto newNode = new LRUNode(key, value);
        if (this->last != nullptr)
        {
            this->last->back = newNode;
            newNode->front = this->last;
        }
        this->last = newNode;
        this->size++;
        if (this->first == nullptr)
        {
            this->first = newNode;
        }
        else if (this->size > this->capacity) // 当first为nullptr时，size应该为0
        {
            auto key = this->dequeue();
            if (key >= 0)
            {
                this->map.erase(key);
            }
            this->size--;
        }
        return newNode;
    }
    void mark_used(LRUNode *node)
    {
        auto back = node->back;
        if (back != nullptr)
        {
            back->front = node->front;
        }
        else
        {
            return;
        }
        if (node->front != nullptr)
        {
            node->front->back = back;
        }
        else
        {
            this->first = back;
        }
        node->front = this->last;
        if (this->last == nullptr)
        {
            this->first = node;
        }
        else
        {
            this->last->back = node;
        }
        node->back = nullptr;
        this->last = node;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->map = std::unordered_map<int, LRUNode *>(capacity + 1);
    }
    ~LRUCache()
    {
        this->map.clear();

        auto node = this->first;
        while (node != nullptr)
        {
            auto next = node->back;
            delete node;
            node = next;
        }
    }

    int get(int key)
    {
        try
        {
            auto result = this->map.at(key);
            this->mark_used(result);
            return result->value;
        }
        catch (const std::exception &e)
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        auto &exist_value = this->map[key];

        if (exist_value != nullptr)
        {
            exist_value->value = value;
            this->mark_used(exist_value);
        }
        else
        {
            exist_value = this->push(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
