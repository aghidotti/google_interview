#include <iostream>
#include <unordered_map>
#include <algorithm>

template <typename T>
inline bool
is_in_range(T val, T lower, T upper) { return lower <= val && val <= upper; }

char
to_lower(char c) {

        char to_low_dist = 'Z' - 'z';
        if(is_in_range(c,'A','Z'))
                return (c - to_low_dist);
        return c;
}

bool
check_naive(const std::string & str) {

	if(str.size() <= 1)
		return true;

	int num_chars = 0;
	std::unordered_map<char, int> str_signature;

	for(auto it = str.cbegin(); it != str.cend(); ++it) {
		auto ch = to_lower(*it);
		if(!is_in_range(ch, 'a', 'z')) continue;

		num_chars++;
		if(str_signature.find(ch) == str_signature.end())
			str_signature.insert(std::make_pair(ch, 0));
		str_signature[ch]++;
	}


	int odd_occurrences = 0;
	for(auto it = str_signature.cbegin(); it != str_signature.cend(); ++it) {
		if(it->second % 2) odd_occurrences++;
	}

	if((num_chars % 2) != odd_occurrences)
		return false;

	return true;
}

bool
check_bitmask(std::string & str) {

	int bitmask = 0;
	std::for_each(str.begin(), str.end(), [&bitmask](char c) {
		auto lower = to_lower(c);
		if(is_in_range(lower,'a','z'))
			bitmask ^= (1 << static_cast<int>(lower));
	});

	while(bitmask > 0 && (bitmask % 2) == 0)
		bitmask = bitmask >> 1;

	if(bitmask > 1)
		return false;

	return true;
}

int main() {

	std::string s1 = "abba";
	std::string s2 = "ab ba";
	std::string s3 = "acbba";
	std::string s4 = "acdba";
	std::string s5 = "aaaa";
	std::string s6 = "aaaaa";
	std::string s7 = "a";
	std::string s8 = " ";
	std::string s9 = "";
	std::string s10 = "Tact coa";

	std::cout << s1 << " -> " << (check_naive(s1) ? "true" : "false" ) << std::endl;
	std::cout << s2 << " -> " << (check_naive(s2) ? "true" : "false" ) << std::endl;
	std::cout << s3 << " -> " << (check_naive(s3) ? "true" : "false" ) << std::endl;
	std::cout << s4 << " -> " << (check_naive(s4) ? "true" : "false" ) << std::endl;
	std::cout << s5 << " -> " << (check_naive(s5) ? "true" : "false" ) << std::endl;
	std::cout << s6 << " -> " << (check_naive(s6) ? "true" : "false" ) << std::endl;
	std::cout << s7 << " -> " << (check_naive(s7) ? "true" : "false" ) << std::endl;
	std::cout << s8 << " -> " << (check_naive(s8) ? "true" : "false" ) << std::endl;
	std::cout << s9 << " -> " << (check_naive(s9) ? "true" : "false" ) << std::endl;
	std::cout << s10 << " -> " << (check_naive(s10) ? "true" : "false" ) << std::endl;

	std::cout << "-------------------------" << std::endl;

        std::cout << s1 << " -> " << (check_bitmask(s1) ? "true" : "false" ) << std::endl;
        std::cout << s2 << " -> " << (check_bitmask(s2) ? "true" : "false" ) << std::endl;
        std::cout << s3 << " -> " << (check_bitmask(s3) ? "true" : "false" ) << std::endl;
        std::cout << s4 << " -> " << (check_bitmask(s4) ? "true" : "false" ) << std::endl;
        std::cout << s5 << " -> " << (check_bitmask(s5) ? "true" : "false" ) << std::endl;
        std::cout << s6 << " -> " << (check_bitmask(s6) ? "true" : "false" ) << std::endl;
        std::cout << s7 << " -> " << (check_bitmask(s7) ? "true" : "false" ) << std::endl;
        std::cout << s8 << " -> " << (check_bitmask(s8) ? "true" : "false" ) << std::endl;
        std::cout << s9 << " -> " << (check_bitmask(s9) ? "true" : "false" ) << std::endl;
        std::cout << s10 << " -> " << (check_bitmask(s10) ? "true" : "false" ) << std::endl;


	return 0;
}
