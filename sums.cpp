/*
	Given a number N, print all way to obtain N as sum of addends in {1,3,4}
*/

/*
RECURRENCE RELATION: (factors 1,3,4)
	sums(n) => 	1 + sums(n-1)
				3 + sums(n-3)
				4 + sums(n-4)
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print_addends(vector<int> &addends) { // O(addends.size())
	if(addends.size() == 0) {
		cout << "no addends" << endl;
	} else {
		for(int i = 0; i < addends.size()-1; ++i)
			cout << addends[i] << "+";
		cout << addends.back() << endl;
	}
}


void sums(vector<int> &addends, vector<int> &factors, int n) {	
	
	if(n == 0){
		print_addends(addends);
	} else {
		for(int i = 0; i < factors.size(); ++i) { // O(factors.size())
			if(n >= factors[i]) {
					addends.push_back(factors[i]); 
					sums(addends, factors, n-factors[i]); 
					addends.pop_back();
			}
		}
	}	
}

void sums(int n, vector<int> &factors) {
	if(factors.size() == 0)
		return;
	
	sort(factors.rbegin(), factors.rend()); // nlog(n)
	vector<int> addends;
	return sums(addends, factors, n);
}

int main() {

	const int N = 10;
	vector<int> factors({1,3,4});
	
	for(int i = 0; i < N; ++i){
		cout << "n=" << i << endl;
		sums(i, factors);
		cout << endl;
	} 
	return 0;
}