#include <iostream>
#include <vector>
#include "20_linked_lists.hpp"

template <typename T>
T kth_to_last(const slist_node<T> *list, unsigned int k) {

	auto cursor_back = list;
	auto cursor_forward = list;
	unsigned int cursor_cnt = 0;

	while(k > cursor_cnt)  {
		cursor_forward = cursor_forward->next;
		cursor_cnt++;
		if(cursor_forward == nullptr)
			throw std::out_of_range("k >= list length");
	}

	while(cursor_forward->next != nullptr) {
		cursor_forward = cursor_forward->next;
		cursor_back = cursor_back->next;
	}

	return cursor_back->val;

}

int main() {
	std::vector<char> items = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	slist_node<char> *list = nullptr;
	for(auto it = items.rbegin(); it != items.rend(); ++it)
		push_front(list, *it);

	print_list(list);

	std::cout << "---------------------" << std::endl;

	int list_size = 0;
	auto node = list;
	while(node != nullptr) {
		list_size++;
		node = node->next;
	}

	auto first = kth_to_last(list, list_size - 1);	std::cout << ((first == 'a') ? "OK" : "KO") << std::endl;
	auto second = kth_to_last(list, list_size - 2);	std::cout << ((second == 'b') ? "OK" : "KO") << std::endl;

	auto sec_to_last = kth_to_last(list, 1);	std::cout << ((sec_to_last == 'y') ? "OK" : "KO") << std::endl;
	auto last = kth_to_last(list, 0);		std::cout << ((last == 'z') ? "OK" : "KO") << std::endl;

	// error cases
	try{
		kth_to_last(list, -1);
	} catch(const std::exception & e1) {
		std::cout << e1.what() << std::endl;
	}

	try{
		kth_to_last(list, list_size);
	} catch(const std::exception & e2) {
		std::cout << e2.what() << std::endl;
	}

	delete list;
}
