#include <iostream>
#include <unordered_map>
#include <algorithm>

std::unordered_map<char, int>
get_string_signature(const std::string & s) {

        std::unordered_map<char, int> sig;

/*
	for(int i = 0; i < s.size(); ++i) {
		auto key = s[i];

		if(sig.find(key) == sig.end())
                        sig.insert(std::make_pair(key,0));
                sig[key]++;
	}
*/

	for_each(s.begin(), s.end(), [&sig](const char & key) {
		if(sig.find(key) == sig.end())
                        sig.insert(std::make_pair(key,0));
                sig[key]++;
	});
	return sig;
}

bool
is_permutation(const std::string & s1, const std::string & s2) {


	if(s1.length() != s2.length())
		return false;

	auto s1_signature = get_string_signature(s1);	// O(N)
	auto s2_signature = get_string_signature(s2);	// O(N)

	if(s1_signature.size() != s2_signature.size())
		return false;

	for(auto it = s2_signature.cbegin(); it != s2_signature.cend(); ++it) { // O(N)
		if(s1_signature.find(it->first) == s1_signature.cend())		// O(1) [WC-> O(N)]
			return false;
		if(s1_signature[it->first] != it->second)			// O(1) [WC-> O(N)]
			return false;
	}

	return true;
}

int main() {
	std::string s1 = "abbc";
	std::string s2 = "babc";
	std::string s3 = "abbcd";
	std::string s4 = "abcd";
	std::string s5 = "cbba";

	std::cout << "s1/s2 => " << (is_permutation(s1, s2) ? "true" : "false") << std::endl;
	std::cout << "s1/s3 => " << (is_permutation(s1, s3) ? "true" : "false") << std::endl;
	std::cout << "s1/s4 => " << (is_permutation(s1, s4) ? "true" : "false") << std::endl;
	std::cout << "s1/s5 => " << (is_permutation(s1, s5) ? "true" : "false") << std::endl;

	return 0;
}
