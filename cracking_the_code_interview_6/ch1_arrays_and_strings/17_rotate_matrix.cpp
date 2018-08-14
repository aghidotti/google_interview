#include <iostream>
#include <vector>

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void print(std::vector<int> & matrix, int N) {
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; j++)
			std::cout << matrix[i*N+j] << " ";
		std::cout << std::endl;
	}
}

void rotate(std::vector<int> & matrix, int N) {

	for(int i = 0; i < N; ++i) {
		for(int j = i; j < N; ++j) {
			// transpose
			// (i,j)  <==> (j, i)
			// i*N+j  <==> j*N+i
			swap(matrix[i*N+j], matrix[j*N+i]);
		}
		for(int j = 0; j<N/2; ++j)
			swap(matrix[i*N+j], matrix[i*N+(N-1+j)]);
	}
}

inline int
sub2ind(int i, int j, int N) {
	return (i*N+j);
}

void
rotate_layers(std::vector<int> & matrix, int start, int N) {
	if(start >= N/2)
		return;
	else {
		for(int i = start; i < (N-start)-1; ++i) {

			int & top = matrix[ sub2ind(start,i,N) ];
			int & left = matrix[ sub2ind(N-i-1,start,N) ];
			int & bottom = matrix[ sub2ind(N-start-1,N-i-1,N) ];
			int & right = matrix[ sub2ind(i,N-start-1,N) ];

			int tmp = top;
			top = left;
			left = bottom;
			bottom = right;
			right = tmp;
		}

		rotate_layers(matrix, start+1, N);
	}
}

int main() {

	const int N = 5;
	std::vector<int> matrix; matrix.reserve(N*N);

	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			matrix[i*N+j] = i*N+j;

	print(matrix, N);

	rotate_layers(matrix, 0, N);

	print(matrix, N);

	return 0;
}
