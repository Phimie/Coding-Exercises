#include <iostream>

class DoublyLinkedList
{
public:
    class Node
    {
    public:
        Node *prev;
        int value;
        Node *next;
        Node(Node *prev, int value, Node *next) : prev(prev), value(value), next(next) {}
    };

private:
    Node *head;
    Node *tail;

    // 修改：正确查找数据节点（索引从0开始，head->next为索引0）
    Node *findNode(int index)
    {
        int i = 0;
        for (Node *p = head->next; p != tail; p = p->next, i++)
        {
            if (i == index)
                return p;
        }
        return nullptr;
    }

public:
    DoublyLinkedList()
    {
        head = new Node(nullptr, 0, nullptr);
        tail = new Node(nullptr, 0, nullptr);
        head->next = tail;
        tail->prev = head;
    }

    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void addFirst(int value)
    {
        Node *next = head->next;
        Node *newNode = new Node(head, value, next);
        head->next = newNode;
        next->prev = newNode;
    }

    void removeFirst()
    {
        if (head->next == tail)
            return; // 空链表检查
        Node *removed = head->next;
        Node *next = removed->next;
        head->next = next;
        next->prev = head;
        delete removed;
    }

    void insert(int index, int value)
    {
        Node *next = findNode(index); // 现在直接找到目标位置节点
        if (next == nullptr)          // 索引越界
        {
            std::cerr << "Index out of bounds" << std::endl;
            return;
        }
        Node *prev = next->prev;
        Node *newNode = new Node(prev, value, next);
        prev->next = newNode;
        next->prev = newNode;
    }

    // 修改：直接定位到要删除的节点
    void remove(int index)
    {
        Node *removed = findNode(index);
        if (removed == nullptr || removed == tail)
        {
            std::cerr << "Index out of bounds" << std::endl;
            return;
        }
        Node *prev = removed->prev;
        Node *next = removed->next;
        prev->next = next;
        next->prev = prev;
        delete removed;
    }

    void addLast(int value)
    {
        Node *prev = tail->prev;
        Node *newNode = new Node(prev, value, tail);
        prev->next = newNode;
        tail->prev = newNode;
    }

    void removeLast()
    {
        if (tail->prev == head)
            return; // 空链表检查
        Node *removed = tail->prev;
        Node *prev = removed->prev;
        prev->next = tail;
        tail->prev = prev;
        delete removed;
    }

    void loop()
    {
        for (Node *p = head->next; p != tail; p = p->next)
        {
            std::cout << p->value << ",";
        }
        std::cout << std::endl;
    }
};

int main()
{
    DoublyLinkedList list1;
    list1.addFirst(8);
    list1.addFirst(7);
    list1.addFirst(4);
    list1.addFirst(1);
    list1.addFirst(2);
    list1.loop(); // 2,1,4,7,8
    list1.removeFirst();
    list1.loop(); // 1,4,7,8
    list1.addLast(7);
    list1.loop();    // 1,4,7,8,7
    list1.remove(2); // 删除索引2（值8），非值7
    list1.loop();    // 1,4,7,7
    list1.removeLast();
    list1.loop(); // 1,4,7
    return 0;
}