#include <iostream>


bool
urlify(std::string & str, int length) {

	int num_ws = 0;
	for(int i = 0; i < length; ++i) {
		if(str[i] == ' ')
			num_ws++;
	}

	int extra_buf = static_cast<int>(str.size()) - (num_ws * 2 + length);
	if(extra_buf < 0)
		return false;

	int i = str.size() - extra_buf;
	for(int j = length - 1; j >= 0; --j) {
		if(str[j] == ' ') {
			str[--i] = '0';
			str[--i] = '2';
			str[--i] = '%';
		} else {
			str[--i] = str[j];
		}
	}

	return true;
}

bool
test_urlify(std::string & str, std::string & expected) {

	if(str == expected){
                std::cout << "OK" << std::endl;
		return true;
	}
        else{
		std::cout << "KO" << std::endl;
		return false;
	}
}

int main() {

	int src_length = 13;
	std::string src = "Mr John Smith    ";
	std::string expected = "Mr%20John%20Smith";

	urlify(src, src_length);

	std::cout << src << std::endl;

	test_urlify(src, expected);

	return 0;
}
