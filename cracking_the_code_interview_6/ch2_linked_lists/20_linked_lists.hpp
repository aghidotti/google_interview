#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <memory>
#include <iostream>

template <typename T>
class slist_node {
        slist_node() = default;

public:
        T val;
        std::shared_ptr<slist_node<T>> next = nullptr;
        slist_node(T &v) : val(v) {}
};


template <typename T>
class dlist_node : public slist_node<T> {
        dlist_node() = default;
public:
        std::shared_ptr<dlist_node<T>> prev = nullptr;
        dlist_node(T &v) : slist_node<T>(v) {}
};


template <typename T>
void
push_front(std::shared_ptr<slist_node<T>> & head, T & val) {
        auto new_node = std::make_shared<slist_node<T>>(val);
        if(head == nullptr)
                head = new_node;
        else {
                new_node->next = head;
                head = new_node;
        }
}

template <typename T>
void
push_front(std::shared_ptr<dlist_node<T>> & head, T & val) {
        auto new_node = std::make_shared<dlist_node<T>>(val);
        if(head == nullptr)
                head = new_node;
        else {
                new_node->next = head;
		head->prev = new_node;
                head = new_node;
        }
}

template <typename T>
void
print_list(std::shared_ptr<slist_node<T>> & list) {
        auto node = list;
        while(node != nullptr) {
                std::cout << node->val << std::endl;
                node = node->next;
        }
}


#endif
