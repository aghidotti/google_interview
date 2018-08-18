#include <iostream>
#include "20_linked_lists.hpp"
#include <vector>

template <typename T>
void
partition(dlist_node<T> *&list, const T &x) {
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

//	print_list(std::static_pointer_cast<slist_node<int>>(list));

	delete list;

}
