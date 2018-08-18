#include <iostream>
#include "20_linked_lists.hpp"
#include <vector>

template <typename T>
void
partition(dlist_node<T>* &list, const T &x) {
	auto current = list;
	while(current != nullptr) {
		auto runner = current;
		while(runner->next != nullptr) {
			if(runner->next->val < x) {
				auto tmp = runner->next;
				runner->next = tmp->next;
				if(runner->next != nullptr) runner->next->prev = runner;
				tmp->next = list;
				if(tmp->next != nullptr) tmp->next->prev = tmp;
				tmp->prev = nullptr;
				list = tmp;
			} else {
				runner = runner->next;
			}
		}
		current = current->next;
	}
}

int
main() {
	std::vector<int> init = { 3,5,8,5,10,2,1 };

	dlist_node<int> *list = nullptr;
	for(auto it = init.rbegin(); it != init.rend(); ++it)
		push_front(list, *it);

	print_list(list);

	std::cout << "--------------------------" << std::endl;

	partition(list, 5);

	print_list(list);

	delete list;

}
