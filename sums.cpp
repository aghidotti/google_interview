/*
	Given a number N, print all way to obtain N as sum of addends in {1,3,4}
*/

#include<iostream>
#include<vector>

using namespace std;

void print_addends(vector<int> &addends) {
	if(addends.size() == 0) {
		cout << "no addends" << endl;
	} else {
		for(int i = 0; i < addends.size()-1; ++i)
			cout << addends[i] << "+";
		cout << addends.back() << endl;
	}
}

/*
RECURRENCE RELATION: (factors 1,3,4)
	sums(n) => 	1 + sums(n-1)
				3 + sums(n-3)
				4 + sums(n-4)
*/


void sums(vector<int> &addends, int n) {
	if(n == 0) {
		print_addends(addends);
	} else if(n < 3) {
		addends.push_back(1); sums(addends, n-1); addends.pop_back();
	} else if(n < 4) {
		addends.push_back(1); sums(addends, n-1); addends.pop_back();
		addends.push_back(3); sums(addends, n-3); addends.pop_back();
	} else {
		addends.push_back(1); sums(addends, n-1); addends.pop_back();
		addends.push_back(3); sums(addends, n-3); addends.pop_back();
		addends.push_back(4); sums(addends, n-4); addends.pop_back();
	}
}

void sums(int n) {
	vector<int> addends;
	return sums(addends, n);
}

int main() {
	const int N = 10;
	for(int i = 0; i < N; ++i){
		cout << "n=" << i << endl;
		sums(i);
		cout << endl;
	} 
	return 0;
}