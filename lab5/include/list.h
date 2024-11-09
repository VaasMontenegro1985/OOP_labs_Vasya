#include <iostream>
#pragma once
#include <memory>

template <class T>
class Node{
    private:
        T data;
        std::shared_ptr<Node<T>> next;

    public:    
        Node() : data(T()), next(nullptr) {}

        Node(const T& value) : data(value), next(nullptr) {}

        Node(const T& value, Node* nextNode) : data(value), next(nextNode) {}
};


template <class T>
class ListIter {
    private:
        std::shared_ptr<Node<T>> current;
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        ListIter(std::shared_ptr<Node<T>> node = nullptr) : current(node) {}

        ListIter(const ListIter &other) : current(other.current) {}

        reference operator*() const {
            if (current == nullptr) {
                throw std::runtime_error("Dereferencing null iterator");
            }
            return current->data;
        }

        pointer operator->() const {
            if (current == nullptr) {
                throw std::runtime_error("Dereferencing null iterator");
            }
            return &(current->data);
        }

        ListIter& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        ListIter operator++(int) {
            ListIter temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const ListIter& other) const {
            return current == other.current;
        }

        bool operator!=(const ListIter& other) const {
            return !(*this == other);
        }
};

template <class T>
class LinkedList {
private:
    std::shared_ptr<Node<T>> head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void push_front(const T& value) {
        std::shared_ptr<Node<T>> newNode = new Node<T>(value, head);
        head = newNode;
    }

    void pop_front() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    T front() const {
        if (head) {
            return head->data;
        }
        throw std::runtime_error("List is empty");
    }

    bool empty() const {
        return head == nullptr;
    }

    void clear() {
        while (head) {
            pop_front();
        }
    }

    void print() const {
        std::shared_ptr<Node<T>> current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
