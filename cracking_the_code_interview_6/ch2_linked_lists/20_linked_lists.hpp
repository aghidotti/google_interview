#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <memory>
#include <iostream>

template <typename T>
class slist_node {
        slist_node() = default;

public:
        T val;
        slist_node<T> *next = nullptr;
        slist_node(const T &v) : val(v) {}

	~slist_node() {
		if(next != nullptr) delete next;
	}
};


template <typename T>
class dlist_node {
        dlist_node() = default;
public:
	T val;
        dlist_node<T> *prev = nullptr;
        dlist_node<T> *next = nullptr;
        dlist_node(const T &v) : val(v) {}

	~dlist_node() {
		if(prev != nullptr) prev->next = nullptr;
		if(next != nullptr) delete next;
	}
};


template <typename T>
void
push_front(slist_node<T> *&head, const T & val) {
        auto new_node = new slist_node<T>(val);
        if(head != nullptr)
                new_node->next = head;
	head = new_node;

}

template <typename T>
void
push_front(dlist_node<T> *&head, const T & val) {
        auto new_node = new dlist_node<T>(val);
	std::cout << "new_node=" << new_node->val << std::endl;
        if(head != nullptr) {
                new_node->next = head;
		head->prev = new_node;
        }
	head = new_node;
	std::cout << "head=" << head->val << std::endl;

}

template <typename T>
void
print_list(const slist_node<T> *list) {
	auto node = list;
        while(node != nullptr) {
                std::cout << node->val << std::endl;
                node = node->next;
        }
}

template <typename T>
void
print_list(const dlist_node<T> *list) {
        auto node = list;
        while(node != nullptr) {
                std::cout << node->val << std::endl;
                node = node->next;
        }
}

#endif
