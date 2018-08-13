#include <iostream>
#include <algorithm>

bool all_unique_chars_bitmask(const std::string & s) {
	char mask = 0;
	for(auto it = s.cbegin(); it != s.cend(); ++it) {
		char c = 1 << static_cast<int>(*it);
                if(c & mask)
			return false;
                else mask |= c;
        }
	return true;
}

bool all_unique_chars(const std::string & s) {

	std::vector<bool> alphabeth(128,false);

	for(auto it = s.cbegin(); it != s.cend(); ++it) {
		if(alphabeth[static_cast<int>(*it)])
			return false;
		else alphabeth[*it] = true;
	}
	return true;
}

bool all_unique_chars_no_ds(std::string & s) {
	std::sort(s.begin(), s.end());	// O(N log N)
	char cur = s.front();
	for(auto it = s.cbegin()+1; it != s.cend(); ++it) {	// O(N)
		if(*it == cur)
			return false;
		cur = *it;
	};
	return true;
}


int main() {

	// suppose char encoding ASCII 7-bit => 128 possible chars
	// otherwise need more storage
	std::string str_ok = "qwertyuiopasdf";
	std::string str_ko = "aabbciemdperng";

	std::cout << str_ok << " -> " << (all_unique_chars(str_ok) ? "true" : "false") << std::endl;
	std::cout << str_ko << " -> " << (all_unique_chars(str_ko) ? "true" : "false") << std::endl;

	std::cout << str_ok << " -> " << (all_unique_chars_no_ds(str_ok) ? "true" : "false") << std::endl;
	std::cout << str_ko << " -> " << (all_unique_chars_no_ds(str_ko) ? "true" : "false") << std::endl;

	std::cout << str_ok << " -> " << (all_unique_chars_bitmask(str_ok) ? "true" : "false") << std::endl;
	std::cout << str_ko << " -> " << (all_unique_chars_bitmask(str_ko) ? "true" : "false") << std::endl;


	return 0;
}
