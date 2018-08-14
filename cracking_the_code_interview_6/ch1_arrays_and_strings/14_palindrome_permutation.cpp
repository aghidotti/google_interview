#include <iostream>
#include <unordered_map>

bool
check(const std::string & str) {

	if(str.size() <= 1)
		return true;

	int num_chars = 0;
	std::unordered_map<char, int> str_signature;

	for(auto it = str.cbegin(); it != str.cend(); ++it) {
		auto & ch = *it;
		if(ch == ' ') continue;
		num_chars++;
		if(str_signature.find(ch) == str_signature.end())
			str_signature.insert(std::make_pair(ch, 0));
		str_signature[ch]++;
	}


	int odd_occurrences = 0;
	for(auto it = str_signature.cbegin(); it != str_signature.cend(); ++it)
		if(it->second % 2) odd_occurrences++;

	if((num_chars % 2) != odd_occurrences)
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

	std::cout << s1 << " -> " << (check(s1) ? "true" : "false" ) << std::endl;
	std::cout << s2 << " -> " << (check(s2) ? "true" : "false" ) << std::endl;
	std::cout << s3 << " -> " << (check(s3) ? "true" : "false" ) << std::endl;
	std::cout << s4 << " -> " << (check(s4) ? "true" : "false" ) << std::endl;
	std::cout << s5 << " -> " << (check(s5) ? "true" : "false" ) << std::endl;
	std::cout << s6 << " -> " << (check(s6) ? "true" : "false" ) << std::endl;
	std::cout << s7 << " -> " << (check(s7) ? "true" : "false" ) << std::endl;
	std::cout << s8 << " -> " << (check(s8) ? "true" : "false" ) << std::endl;
	std::cout << s9 << " -> " << (check(s9) ? "true" : "false" ) << std::endl;
	std::cout << s10 << " -> " << (check(s10) ? "true" : "false" ) << std::endl;

	return 0;
}
