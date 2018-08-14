#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

int
compressed_char_length(int counter) {
	if(counter > 0)
		return (1 + std::to_string(counter).length());
	else return 0;
}

int
compressed_string_length(const std::string & str) {

	if(str.length() == 0)
		return 0;

	int length = 0;

	char c = '\0';
	int counter = 0;

	for(int i = 0; i < str.length(); ++i) {
		if(str[i] != c) {
			length += compressed_char_length(counter);
			counter = 1;
			c = str[i];
		} else counter++;
	}

	length += compressed_char_length(counter);
	return length;
}

void
append_compressed_char(std::string & str, char c, int counter) {
	if(counter > 0) {
		str.push_back(c);
		auto scount = std::to_string(counter);
		for(int j = 0; j < scount.length(); ++j)
			str.push_back(scount[j]);
	}
}

std::string
compress_string(const std::string & str) {

	int clength = compressed_string_length(str);

	if(str.length() <= 2 || str.length() <= clength)
		return str;

	std::string res; res.reserve(clength);

	char c = '\0';
	int counter = 0;
	for(int i = 0; i < str.length(); ++i) {
		if(str[i] != c) {
			append_compressed_char(res, c, counter);
			counter = 1;
			c = str[i];

		} else counter ++;
	}

	append_compressed_char(res, c, counter);
	return res;
}

int main() {

	std::string s1 = "aabcccccaaa";
	std::string s2 = "abc";
	std::string s3 = "";
	std::string s4 = "aaaaaaabccccccc";
	std::string s5 = "aaaaaaaaaaaaaaaaaaaaaaabccccccc";

	std::cout << compress_string(s1) << std::endl;
	std::cout << compress_string(s2) << std::endl;
	std::cout << compress_string(s3) << std::endl;
	std::cout << compress_string(s4) << std::endl;
	std::cout << compress_string(s5) << std::endl;

	return 0;
}
