#include <iostream>
#include <vector>
#include "20_linked_lists.hpp"

template <typename T>
slist_node<T>*
sum_lists_fw_impl(T & carry, const slist_node<T>* list1, const slist_node<T>* list2) {
	if(list1 == nullptr && list2 == nullptr) {
		carry = 0;
		return nullptr;
	} else {

		auto out_carry = 0;
		auto tail = sum_lists_fw_impl(out_carry,list1->next,list2->next);
		auto digit_res = list1->val + list2->val + out_carry;
		auto head = new slist_node<T>(digit_res%10);
		head->next = tail;
		carry = (digit_res >= 10);
		return head;
	}
}

template <typename T>
slist_node<T>*
sum_lists_fw(slist_node<T>* list1, slist_node<T>* list2) {
	// first compare lenghts and pad the head of the shorter with zeros
	auto head1 = list1; auto head2 = list2;
	while(list1 != nullptr || list2 != nullptr) {
		if(list1 == nullptr  && list2 != nullptr) {
			push_front(head1,0);
			list2 = list2->next;
		} else if(list2 == nullptr && list1 != nullptr) {
			push_front(head2,0);
			list1 = list1->next;
		} else {
			list1 = list1->next;
			list2 = list2->next;
		}
	}

	// then recursion
	auto carry = 0;
	auto tail = sum_lists_fw_impl(carry, head1, head2);
	if(carry > 0) {
		push_front(tail, carry);
	}
	return tail;
}

template <typename T>
slist_node<T>*
sum_lists_impl(const T & carry, const slist_node<T>* list1, const slist_node<T>* list2) {
	if(list1 == nullptr && list2 == nullptr) {
		if(carry > 0) {
			return new slist_node<T>(carry);
		} else {
			return nullptr;
		}
	} else {
		auto add1 = (list1 != nullptr) ? list1->val : 0;
		auto add2 = (list2 != nullptr) ? list2->val : 0;
		auto res = add1 + add2 + carry;
		auto new_carry = (res >= 10) ? 1 : 0;
		auto node = new slist_node<T>(res%10);
		node->next = sum_lists_impl(new_carry,
				((list1 != nullptr) ? list1->next : nullptr),
				((list2 != nullptr) ? list2->next : nullptr));
		return node;
	}
}

template <typename T>
slist_node<T>*
sum_lists(const slist_node<T>* list1, const slist_node<T>* list2) {
	return sum_lists_impl(0,list1,list2);
}


int
main() {
	std::vector<int> digits1 = {6,1,7};
	std::vector<int> digits2 = {9,5};

	slist_node<int>* list1 = nullptr;
	slist_node<int>* list2 = nullptr;

	std::cout << "------------ BW ORDER --------------" << std::endl;

	for(auto it = digits1.cbegin(); it != digits1.cend(); ++it)
		push_front(list1, *it);

        for(auto it = digits2.cbegin(); it != digits2.cend(); ++it)
                push_front(list2, *it);

	print_list(list1); std::cout << "------------------" << std::endl;
	print_list(list2); std::cout << "------------------" << std::endl;

	auto res = sum_lists(list1,list2);
	print_list(res);

	std::cout << "------------ FW ORDER --------------" << std::endl;

	delete list1;
	delete list2;
	delete res;

	list1 = nullptr;
	list2 = nullptr;
	res = nullptr;

	for(auto it = digits1.crbegin(); it != digits1.crend(); ++it)
                push_front(list1, *it);

        for(auto it = digits2.crbegin(); it != digits2.crend(); ++it)
                push_front(list2, *it);

        print_list(list1); std::cout << "------------------" << std::endl;
        print_list(list2); std::cout << "------------------" << std::endl;

        res = sum_lists_fw(list1,list2);
        print_list(res);


	delete list1;
	delete list2;
	delete res;


}
