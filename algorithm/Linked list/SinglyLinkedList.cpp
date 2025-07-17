#include <iostream>
// 单向链表
class SinglyLinkedList
{

private:
    // 节点类
    class Node
    {
    public:
        int value;
        Node *next;
        Node(int value, Node *next)
        {
            this->value = value;
            this->next = next;
        }
    };

private:
    Node *head = new Node(0, nullptr);

private:
    Node *findLast()
    {
        Node *p;
        for (p = head->next; p->next != nullptr; p = p->next)
        {
        }
        return p;
    }

    Node *findNode(int index)
    {
        int i = -1;
        for (Node *p = head; p != nullptr; p = p->next, i++)
        {
            if (i == index)
            {
                return p;
            }
        }
        return nullptr;
    }

public:
    ~SinglyLinkedList()
    {
        Node *curr = head;
        while (curr)
        {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void removeFirst()
    {
        if (head == nullptr)
        {
            std::cerr << "没找到" << std::endl;
            return;
        }

        Node *oldHead = head; // 先保存旧节点
        head = head->next;    // 把头指针指向第二个节点
        delete oldHead;       // 释放旧节点的内容
    }

    void remove(int index)
    {
        Node *prev = findNode(index - 1); // 上一个节点
        if (prev == nullptr)
        {
            std::cerr << "没找到" << std::endl;
            return;
        }
        Node *removed = prev->next; // 被删除的节点
        prev->next = removed->next;
        delete removed; // 释放被删除的节点内存
    }

    int get(int index)
    {
        Node *node = findNode(index);
        if (node == nullptr)
        {
            std::cerr << "没找到" << std::endl;
            return -1;
        }
        return node->value;
    }

    void insert(int index, int value)
    {
        Node *prev = findNode(index - 1); // 找到上一个节点
        if (prev == nullptr)
        {
            std::cerr << "找不到" << std::endl;
            return;
        }
        prev->next = new Node(value, prev->next);
    }

    void addFirst(int value)
    {
        head->next = new Node(value, head->next);
    }

    void addLast(int value)
    {
        Node *last = findLast(); // 有哑元节点,不用判断链表为空的情况了
        last->next = new Node(value, nullptr);
    }

    void loop()
    {
        Node *pointer = head->next;
        while (pointer != nullptr)
        {
            std::cout << pointer->value << ",";

            pointer = pointer->next;
        }
    }

    void loop2()
    {
        for (Node *pointer = head->next; pointer != nullptr; pointer = pointer->next)
        {
            std::cout << pointer->value << ",";
        }
    }

    // 递归遍历
    void loop3()
    {
        recursion(head->next);
        std::cout << std::endl;
    }

    void recursion(Node *cur)
    {
        if (cur == nullptr)
        {
            return;
        }
        std::cout << cur->value << ",";
        recursion(cur->next);
    }
};

int main()
{
    SinglyLinkedList list;
    list.addFirst(1);
    list.addFirst(2);
    list.addFirst(3);
    list.addFirst(4);
    list.loop();
    std::cout << std::endl;
    list.insert(2, 5);
    list.loop();
    std::cout << std::endl;
    list.removeFirst();
    list.loop();
    std::cout << std::endl;
    list.insert(3, 8);
    list.loop();
    std::cout << std::endl;
    list.remove(1);
    list.loop();
    std::cout << std::endl;
    list.addLast(9);
    list.loop2();
    std::cout << std::endl;
    std::cout << list.get(2) << std::endl;
    list.loop3();
    return 0;
}