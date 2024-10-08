#include <iostream>
#include <memory>
#include <vector>
#include <random>
#include <algorithm>

class Node : public std::enable_shared_from_this<Node>
{
private:
    int data_;
    std::shared_ptr<Node> next_ = nullptr;

public:
    Node(int data) : data_{data}, next_{nullptr}
    {
    }

    std::shared_ptr<Node> getNext()
    {
        return next_;
    }

    void setNext(std::shared_ptr<Node> node)
    {
        next_ = node;
    }

    int getData()
    {
        return data_;
    }

    void setData(int data)
    {
        data_ = data;
    }
};

class LinkedList
{
private:
    int size_ = 0;
    std::shared_ptr<Node> head_ = nullptr;
    std::shared_ptr<Node> tail_ = nullptr;

public:
    LinkedList(int &&data)
    {
        head_ = std::make_shared<Node>(data);
        size_++;
    }

    void appendToTail(int &&data)
    {
        std::shared_ptr<Node> tail = std::make_shared<Node>(data);
        if (size_ == 1)
        {
            tail_ = tail;
            head_->setNext(tail_);
            size_++;
            return;
        }
        tail_->setNext(tail);
        tail_ = tail;
        size_++;
    }

    std::shared_ptr<Node> search(const int &&data)
    {
        std::shared_ptr<Node> node = head_;
        while (node != nullptr)
        {
            if (node->getData() == data)
                return node;
            node = node->getNext();
        }
        return nullptr;
    }

    void sortList()
    {
        
    }

    void showList()
    {
        std::cout << "Linked list: ";
        std::shared_ptr<Node> node = head_;
        while (node != nullptr)
        {
            std::cout << node->getData() << " ";
            node = node->getNext();
        }
        std::cout << std::endl;
    }

    void showList(std::shared_ptr<Node> node)
    {
        std::cout << "Linked list: ";
        if (node == nullptr)
            return;
        while (node != nullptr)
        {
            std::cout << node->getData() << " ";
            node = node->getNext();
        }
        std::cout << std::endl;
    }

    void deleteDuplicate()
    {
        std::shared_ptr<Node> node = head_;
        std::shared_ptr<Node> preNode = node;
        std::vector<int> v;
        v.push_back(node->getData());

        node = node->getNext();
        while (node != nullptr)
        {
            for (auto i : v)
            {
                if (node->getData() == i)
                {
                    preNode->setNext(node->getNext());
                    node = preNode;
                }
            }
            v.push_back(node->getData());
            preNode = node;
            node = node->getNext();
        }
    }

    std::shared_ptr<Node> returnKToLast(int &&Kth)
    {
        if (Kth < 1 || Kth > size_)
            return nullptr;

        std::shared_ptr<Node> node = head_;

        if (Kth == 1)
            return node;

        for (int i = 0; i < Kth - 1; i++)
        {
            if (node->getNext() == nullptr)
                return nullptr;
            node = node->getNext();
        }
        return node;
    }

    void deleteMiddleNode()
    {
        std::shared_ptr<Node> node = head_;
        std::shared_ptr<Node> preNode = node;
        if (size_ < 3)
            return;

        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<> dist(2, size_ - 1);
        int randNum = dist(mt);
        std::cout << "Random: " << randNum << std::endl;

        for (int i = 0; i < randNum - 1; i++)
        {
            preNode = node;
            node = node->getNext();
        }
        preNode->setNext(node->getNext());
        node = preNode;
    }

    std::shared_ptr<Node> partition(int &&par)
    {
        std::shared_ptr<Node> head = head_;

        std::shared_ptr<Node> equalPar = std::make_shared<Node>(0);
        std::shared_ptr<Node> greaterPar = std::make_shared<Node>(0);
        std::shared_ptr<Node> lessPar = std::make_shared<Node>(0);
        std::shared_ptr<Node> less{lessPar}, greater{greaterPar}, equal{equalPar};

        while (head != nullptr)
        {
            // std::cout << __LINE__ << " | loop" << std::endl;
            if (head->getData() == par)
            {
                equal->setNext(head);
                equal = equal->getNext();
            }
            else if (head->getData() < par)
            {
                less->setNext(head);
                less = less->getNext();
            }
            else
            {
                greater->setNext(head);
                greater = greater->getNext();
            }

            head = head->getNext();
        }

        greater->setNext(nullptr);
        equal->setNext(greaterPar->getNext());
        less->setNext(equalPar->getNext());
        std::shared_ptr<Node> ret = lessPar->getNext();
        return ret;
    }

    bool palindrome()
    {
        std::vector<int> v;
        std::shared_ptr<Node> node = head_;

        while (node != nullptr)
        {
            v.push_back(node->getData());
            node = node->getNext();
        }

        node = head_;
        std::reverse(v.begin(), v.end());
        while (node != nullptr)
        {
            if (node->getData() != *v.begin())
                return false;
            v.erase(v.begin());
            node = node->getNext();
        }
        return true;
    }

    //
};

int main()
{
    LinkedList linkedList(1);
    linkedList.appendToTail(2);
    linkedList.appendToTail(3);
    linkedList.appendToTail(4);
    linkedList.appendToTail(5);
    linkedList.appendToTail(6);
    linkedList.appendToTail(5);
    linkedList.appendToTail(4);
    linkedList.appendToTail(3);
    linkedList.appendToTail(2);
    linkedList.appendToTail(1);
    linkedList.appendToTail(2);
    linkedList.showList();

    // 1. Delete duplicate:
    // linkedList.deleteDuplicate();
    // linkedList.showList();

    // 2. Return Kth to last
    // std::shared_ptr<Node> fromK = linkedList.returnKToLast(5);
    // linkedList.showList(fromK);

    // 3. Delete middle node
    // linkedList.deleteMiddleNode();
    // linkedList.showList();

    // 4. Partition
    // std::shared_ptr<Node> partition = linkedList.partition(10);
    // linkedList.showList(partition);

    // 5. Palindrome
    std::cout << "Palindrome: " << linkedList.palindrome() << std::endl;

    return 0;
}