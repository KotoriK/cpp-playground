#include <unordered_map>
// 珍爱生命远离try...catch
class LRUNode
{
public:
    LRUNode *front = nullptr;
    LRUNode *back = nullptr;
    int key;
    int value;
    LRUNode(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCache
{
private:
    int capacity;
    int size = 0;

    LRUNode *first = nullptr;
    LRUNode *last = nullptr;

    std::unordered_map<int, LRUNode *> map;

    LRUNode *dequeue()
    {
        auto first = this->first;
        if (first != nullptr)
        {
            auto back = first->back;
            if (back == nullptr)
            {
                this->last = nullptr;
            }
            else
            {
                back->front = nullptr;
            }
            this->first = back;
            this->size--;

            // 清理
            first->back = nullptr;
            return first;
        }
        return nullptr;
    }
    LRUNode *push(int key, int value)
    {
        this->size++;
        if (this->size > this->capacity) // 当first为nullptr时，size应该为0
        {
            auto node = this->dequeue();
            if (node != nullptr)
            {
                this->map.erase(node->key);
                if (this->last == nullptr)
                {
                    this->first = node;
                    // node->front = nullptr; 不需要，因为node是dequeue得来
                }
                else
                {
                    this->last->back = node;
                    node->front = this->last;
                }
                this->last = node;

                node->back = nullptr;
                node->key = key;
                node->value = value;
                return node;
            }
        }
        auto newNode = new LRUNode(key, value);

        if (this->last == nullptr)
        {
            this->first = newNode;
        }
        else
        {
            this->last->back = newNode;
            newNode->front = this->last;
        }
        this->last = newNode;

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
        auto resultIter = this->map.find(key);
        if (resultIter == this->map.end())
        {
            return -1;
        }
        else
        {
            auto result = resultIter->second;
            this->mark_used(result);
            return result->value;
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
