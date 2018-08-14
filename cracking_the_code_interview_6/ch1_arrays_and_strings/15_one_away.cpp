#include <iostream>

bool
is_one_away_iterative(const std::string & s1, const std::string & s2) {

	const std::string & shorter = ((s1.size() <= s2.size()) ? s1 : s2);
        const std::string & longer = ((s1.size() <= s2.size()) ? s2 : s1);
	auto length_diff = static_cast<int>(longer.size() - shorter.size());

	if(length_diff > 1)
		return false;

	bool already_changed = false;
	for(int i = 0, j = 0; i < shorter.size(); ++i, ++j) {
		if(shorter[i] != longer[j]) {
			if(already_changed)
				return false;
			already_changed = true;
			j+=length_diff;
		}
	}

	return true;
}

bool
is_one_away_recursive_impl(const std::string & s1, const std::string & s2, bool already_changed) {

	const std::string & shorter = ((s1.size() <= s2.size()) ? s1 : s2);
	const std::string & longer = ((s1.size() <= s2.size()) ? s2 : s1);

	auto length_diff = static_cast<int>(longer.size() - shorter.size());

	if(length_diff > 1)
		return false;
	if(already_changed && shorter.size() != longer.size())
		return false;
	if(shorter.size() == 0 && longer.size() == 0)
		return true;
	if(shorter.size() == 1 && longer.size() == 1)
		return already_changed ? (shorter[0] == longer[0]) : true;
	else {
		// stop on first difference
		for(int idx = 0; idx < shorter.size(); ++idx) {
			if(shorter[idx] != longer[idx])
				return (already_changed ? false : is_one_away_recursive_impl(shorter.substr(idx+1), longer.substr(idx+1+length_diff), true));
		}
	}

	return true;
}

bool
is_one_away_recursive(const std::string & str, const std::string & ed)
{
	return is_one_away_recursive_impl(str, ed, false);
}


int main() {

	std::string str1 = "pale"; 	std::string ed1 = "ple";
	std::string str2 = "pales"; 	std::string ed2 = "pale";
	std::string str3 = "pale"; 	std::string ed3 = "bale";
	std::string str4 = "pale"; 	std::string ed4 = "bake";

	std::cout << str1 << "," << ed1 << " -> " << (is_one_away_recursive(str1, ed1) ? "true" : "false") << std::endl;
	std::cout << str2 << "," << ed2 << " -> " << (is_one_away_recursive(str2, ed2) ? "true" : "false") << std::endl;
	std::cout << str3 << "," << ed3 << " -> " << (is_one_away_recursive(str3, ed3) ? "true" : "false") << std::endl;
	std::cout << str4 << "," << ed4 << " -> " << (is_one_away_recursive(str4, ed4) ? "true" : "false") << std::endl;

	std::cout << str1 << "," << ed1 << " -> " << (is_one_away_iterative(str1, ed1) ? "true" : "false") << std::endl;
	std::cout << str2 << "," << ed2 << " -> " << (is_one_away_iterative(str2, ed2) ? "true" : "false") << std::endl;
	std::cout << str3 << "," << ed3 << " -> " << (is_one_away_iterative(str3, ed3) ? "true" : "false") << std::endl;
	std::cout << str4 << "," << ed4 << " -> " << (is_one_away_iterative(str4, ed4) ? "true" : "false") << std::endl;

	return 0;
}
