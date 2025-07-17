#include <iostream>

class DoublyCircularLinkedList
{
public:
    class Node
    {
    public:
        Node *prev;
        int value;
        Node *next;
        Node(Node *prev, int value, Node *next)
        {
            this->next = next;
            this->prev = prev;
            this->value = value;
        }
    };

    Node *dummy = new Node(nullptr, -1, nullptr);
    DoublyCircularLinkedList() // 构造函数初始化dummy
    {
        dummy->prev = dummy;
        dummy->next = dummy;
    }
    ~DoublyCircularLinkedList() // 析构函数逐个删除节点内存
    {
        Node *cur = dummy->next;
        while (cur != dummy)
        {
            Node *next = cur->next;
            delete cur;
            cur = next;
        }
        delete dummy;
    }

public:
    void addFirst(int value)
    {
        Node *newNode = new Node(dummy, value, dummy->next);
        dummy->next->prev = newNode;
        dummy->next = newNode;
    }

    void addLast(int value)
    {
        Node *newNode = new Node(dummy->prev, value, dummy);
        dummy->prev->next = newNode;
        dummy->prev = newNode;
    }

    void removeFirst()
    {
        Node *removed = dummy->next;
        if (removed == dummy)
        {
            std::cerr << "无法删除哑元" << std::endl;
            return;
        }
        dummy->next = removed->next;
        Node *removedNext = removed->next;
        removedNext->prev = dummy;
        delete removed;
    }

    void removeLast()
    {
        Node *removed = dummy->prev;
        if (removed == dummy)
        {
            std::cerr << "无法删除哑元" << std::endl;
            return;
        }
        Node *removedPrev = removed->prev;
        dummy->prev = removedPrev;
        removedPrev->next = dummy;
        delete removed;
    }

    Node *findByValue(int value)
    {
        Node *cur = dummy->next;
        while (cur != dummy)
        {
            if (cur->value == value)
            {
                return cur;
            }
            cur = cur->next;
        }
        return nullptr;
    }

    void removeByValue(int value)
    {
        Node *removed = findByValue(value);
        if (removed == nullptr)
        {
            return;
        }
        Node *removedPrev = removed->prev;
        Node *removedNext = removed->next;
        removedPrev->next = removedNext;
        removedNext->prev = removedPrev;
        delete removed;
    }

    void loop()
    {
        Node *cur = dummy->next;
        while (cur != dummy)
        {
            std::cout << cur->value << ",";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    DoublyCircularLinkedList list;
    list.addFirst(5);
    list.addFirst(4);
    list.addFirst(3);
    list.addFirst(2);
    list.addFirst(1);
    list.addFirst(0);
    list.loop();
    list.addLast(9);
    list.loop();
    list.removeFirst();
    list.loop();
    list.removeLast();
    list.loop();
    list.removeByValue(2);
    list.loop();
    return 0;
}