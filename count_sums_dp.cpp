/*
	Given a number N, print all way to obtain N as sum of addends in {1,3,4}
*/

/*
RECURRENCE RELATION: (factors 1,3,4)
	count_sums(n) => 	1 + sums(n-1)
						3 + sums(n-3)
						4 + sums(n-4)
				
	base cases:
		count_sums(0) == 0
		count_sums(1) == 1
		count_sums(3) == 2
		count_sums(4) == 4
*/

#include<iostream>
#include<vector>

using namespace std;

int count_sums(int n) {	
	
	int count = 0;
	vector<int> count_vec({1,1,2,4});
		
	for(int i = 0; i < n; ++i) {
		if(i>=4) {
			count = count_vec[i-4] + count_vec[i-3] + count_vec[i-1];
			count_vec.push_back(count);
		} else {
			count = count_vec[i];
		}
	}

	return count;
}

int main() {
	int N = 10;
	for(int i = 0; i < N; ++i)
		cout << "i=" << i << " -> " << count_sums(i) << endl;
	return 0;
}