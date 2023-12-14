// #include "./answer.cpp"
#include "./answer_no_exception.cpp"

#include <cassert>
#include <memory>
int case1()
{
    auto obj = std::make_unique<LRUCache>(1);
    assert(obj->get(1) == -1);
    obj->put(1, 1);
    assert(obj->get(1) == 1);
    obj->put(2, 2);
    assert(obj->get(1) == -1);
    assert(obj->get(2) == 2);
    return 0;
}
int case2()
{
    auto obj = std::make_unique<LRUCache>(2);
    assert(obj->get(1) == -1);
    obj->put(1, 1);
    obj->put(2, 2);
    assert(obj->get(1) == 1);
    assert(obj->get(2) == 2);
    obj->put(3, 3);
    obj->put(4, 4);
    assert(obj->get(1) == -1);
    assert(obj->get(2) == -1);
    assert(obj->get(3) == 3);
    return 0;
}
int case3()
{
    auto obj = std::make_unique<LRUCache>(3);
    assert(obj->get(1) == -1);
    obj->put(1, 1);
    obj->put(2, 2);
    obj->put(3, 3);
    assert(obj->get(1) == 1);
    assert(obj->get(2) == 2);
    assert(obj->get(3) == 3);
    obj->put(4, 4);
    assert(obj->get(1) == -1);
    assert(obj->get(2) == 2);
    assert(obj->get(3) == 3);

    assert(obj->get(4) == 4);
    return 0;
}
int case4(){
    auto obj = std::make_unique<LRUCache>(2);
    obj->put(2, 1);
    obj->put(2, 2);
    assert(obj->get(2) == 2);
    obj->put(1, 1);
    obj->put(4, 1);
    assert(obj->get(2) == -1);
    return 0;
}
int main()
{
    case1();
    case2();
    case3();
    case4();
    return 0;
}