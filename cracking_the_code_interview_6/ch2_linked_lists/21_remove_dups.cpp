#include <iostream>
#include "20_linked_lists.hpp"

template <typename T>
void
remove_dups(slist_node<T> *list) {
	auto current = list;
	while(current != nullptr) {
		auto runner = current;
		while(runner->next != nullptr) {
			if(runner->next->val == current->val) {
				auto to_delete = runner->next;
				runner->next = to_delete->next;
				to_delete->next = nullptr;
				delete to_delete;
			} else {
				runner = runner->next;
			}
		}
		current = current->next;
	}
}

int main() {

	slist_node<int> *list = nullptr;

	push_front(list, 2);
	push_front(list, 1);
	push_front(list, 1);
	push_front(list, 2);
	push_front(list, 4);
	push_front(list, 5);
	push_front(list, 1);
	push_front(list, 2);
	push_front(list, 3);

	print_list(list);

	std::cout << "-------------------------------------------" << std::endl;

	remove_dups(list);

	print_list(list);

	std::cout << "-------------------------------------------" << std::endl;

	delete list;
}
