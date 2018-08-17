#include <iostream>
#include <forward_list>

template <typename T>
T kth_to_last(const std::forward_list<T> & list, unsigned int k) {

	auto cursor_back = list.begin();
	auto cursor_forward = list.begin();
	int cursor_cnt = 0;

	while(k > cursor_cnt)  {
		cursor_forward++;
		cursor_cnt++;
		if(cursor_forward == list.end())
			throw std::out_of_range("k >= list length");
	}

	while(std::next(cursor_forward) != list.end()) {
		cursor_forward++;
		cursor_back++;
	}

	return *cursor_back;

}

int main() {
	std::forward_list<char> list = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	int list_size = 0;
	for(auto it = list.begin(); it != list.end(); ++it)
		list_size++;

	auto first = kth_to_last(list, list_size - 1);	std::cout << ((first == 'a') ? "OK" : "KO") << std::endl;
	auto second = kth_to_last(list, list_size - 2);	std::cout << ((second == 'b') ? "OK" : "KO") << std::endl;

	auto sec_to_last = kth_to_last(list, 1);	std::cout << ((sec_to_last == 'y') ? "OK" : "KO") << std::endl;
	auto last = kth_to_last(list, 0);		std::cout << ((last == 'z') ? "OK" : "KO") << std::endl;

	// error cases
	try{
		auto error1 = kth_to_last(list, -1);
	} catch(const std::exception & e1) {
		std::cout << e1.what() << std::endl;
	}

	try{
		auto error2 = kth_to_last(list, list_size);
	} catch(const std::exception & e2) {
		std::cout << e2.what() << std::endl;
	}
}
