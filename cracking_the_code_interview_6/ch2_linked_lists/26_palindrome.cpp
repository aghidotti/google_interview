#include <iostream>
#include <vector>
#include <memory>
#include "20_linked_lists.hpp"

template <typename T>
bool
palindrome_simple(const slist_node<T>* list) {

	slist_node<T>* rlist = nullptr;

	auto head_fw = list;
	int length = 0;
	while(head_fw != nullptr) {
		push_front(rlist, head_fw->val);
		head_fw = head_fw->next;
		length++;
	}

	head_fw = list;
	auto head_bw = rlist;
	int cursor = 0;
	while(head_fw != nullptr && cursor < length/2) {
		if(head_fw->val != head_bw->val) {
			delete rlist;
			return false;
		}

		head_fw = head_fw->next;
		head_bw = head_bw->next;
		cursor++;
	}

	delete rlist;
	return true;
}

template <typename T>
bool
palindrome_recursive(const slist_node<T>* list) {
	// still not implemented
	return false;
}

int
main() {

	std::vector<char> pal1 = {'a','b','c','e','d','e','c','b','a'};
	slist_node<char>* list1 = nullptr;
	for(auto it = pal1.begin(); it != pal1.end(); ++it)
		push_front(list1, *it);
	std::cout << (palindrome_simple(list1) ? "OK" : "KO") << std::endl;


	std::vector<char> pal2 = {'a','b','c','e','e','c','b','a'};
        slist_node<char>* list2 = nullptr;
        for(auto it = pal2.begin(); it != pal2.end(); ++it)
                push_front(list2, *it);
	std::cout << (palindrome_simple(list2) ? "OK" : "KO") << std::endl;


	std::vector<char> no_pal1 = {'a','b','c','e','d','c','b','a'};
        slist_node<char>* list3 = nullptr;
        for(auto it = no_pal1.begin(); it != no_pal1.end(); ++it)
                push_front(list3, *it);
	std::cout << (palindrome_simple(list3) ? "OK" : "KO") << std::endl;


	std::vector<char> no_pal2 = {'a','b','c','e','d','c','c','b','a'};
        slist_node<char>* list4 = nullptr;
        for(auto it = no_pal2.begin(); it != no_pal2.end(); ++it)
                push_front(list4, *it);
	std::cout << (palindrome_simple(list4) ? "OK" : "KO") << std::endl;

	delete list1;
	delete list2;
	delete list3;
	delete list4;
}
