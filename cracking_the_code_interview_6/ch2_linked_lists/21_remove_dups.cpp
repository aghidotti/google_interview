#include <iostream>
#include <forward_list>
#include <algorithm>

void
remove_dups(std::forward_list<int> & list) {

	for(auto head = list.begin(); head != list.end(); ++head) {
		auto val = *head;
		for(auto runner = head; runner != list.end(); ++runner) {
			auto it = std::next(runner);
			if(it != list.end() && *it == val)
				list.erase_after(runner);
		}
	}
}


int main() {

	auto flist = std::forward_list<int>();

	flist.push_front(1);
	flist.push_front(2);
	flist.push_front(1);
	flist.push_front(3);
	flist.push_front(2);
	flist.push_front(4);
	flist.push_front(5);
	flist.push_front(2);
	flist.push_front(1);

	for_each(flist.cbegin(), flist.cend(),
			[](const int & val) { std::cout << val << std::endl; });

	std::cout << "-------------------------------------------" << std::endl;

	remove_dups(flist);

        for_each(flist.cbegin(), flist.cend(),
                        [](const int & val) { std::cout << val << std::endl; });

	std::cout << "-------------------------------------------" << std::endl;


}
