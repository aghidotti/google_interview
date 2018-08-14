#include <iostream>
#include <sstream>
#include <string>


std::string
compress_string(const std::string & str) {

	if(str.length() <= 2)
		return str;

	int counter = 1;
	char c = '\0';
	int ss_length = 0;
	std::stringstream ss;

	for(int i = 0; i < str.length(); ++i) {
		if(str[i] == c) counter++;
		else {
			ss << c << counter;
			ss_length += 2;
			if(ss_length >= str.length())
				return str;
			c = str[i];
			counter = 1;
		}
	}

	return ss.str();
}

int main() {

	std::string s1 = "aabcccccaaa";
	std::string s2 = "abc";
	std::string s3 = "";
	std::string s4 = "aaaaaaabccccccc";

	std::cout << compress_string(s1) << std::endl;
	std::cout << compress_string(s2) << std::endl;
	std::cout << compress_string(s3) << std::endl;
	std::cout << compress_string(s4) << std::endl;

	return 0;
}
