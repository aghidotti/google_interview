#include <iostream>
#include "20_linked_lists.hpp"

template <typename T>
void
remove_dups(std::shared_ptr<slist_node<T>> & list) {
	auto current = list;
	while(current != nullptr) {
		auto runner = current;
		while(runner->next != nullptr) {
			if(runner->next->val == current->val) {
				runner->next = runner->next->next;
			} else {
				runner = runner->next;
			}
		}
		current = current->next;
	}
}

int main() {

	std::shared_ptr<slist_node<int>> list = nullptr;

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


}
