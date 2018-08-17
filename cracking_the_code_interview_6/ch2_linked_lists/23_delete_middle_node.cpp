#include <iostream>
#include <vector>
#include "20_linked_lists.hpp"

template <typename T>
void
delete_middle_node(std::shared_ptr<slist_node<T>> & node_to_del) {
	if(node_to_del != nullptr) {
		auto next_node = node_to_del->next;
		node_to_del->val = node_to_del->next->val;
		node_to_del->next = node_to_del->next->next;
		next_node->next = nullptr;
	} else {
		throw std::runtime_error("node_to_del == nullptr");
	}
}

int
main() {
	std::vector<char> init = {'q','w','e','r','t','y'};

	std::shared_ptr<slist_node<char>> list = nullptr;
	for(auto it = init.rbegin(); it != init.rend(); ++it)
		push_front(list, *it);

	print_list(list);

	std::cout << "--------------------" << std::endl;

	auto node_to_del = list;
	for(int i = 0; i < 3; ++i) {
		node_to_del = node_to_del->next;
	}


	delete_middle_node(node_to_del);

	print_list(list);

}
