#include <iostream>
#include <vector>

struct Point {
        const int x;
        const int y;
        Point(int xp, int yp) : x(xp), y(yp){}
};

template <typename T>
class
Matrix
{
	std::vector<T> data;

	int sub2ind(int r, int c) const { return r*cols+c; }
public:
	const int cols;
	const int rows;
	Matrix(int width, int height) :
		cols(width), rows(height) { data.reserve(rows*cols); }

	const T & get(int r, int c) const {
		return data[ sub2ind(r,c) ];
	}

	const T & get(const Point & p) const {
		return get(p.y, p.x);
	}

	void set(int r, int c, const T & val) {
		data[ sub2ind(r,c) ] = val;
	}

	void set(const Point & p, const T & val) {
		set(p.y, p.x, val);
	}

	void print() {
		for(int i = 0; i < rows; ++i){
			for(int j = 0; j < cols; ++j) {
				std::cout << get(i,j) << " ";
			}
			std::cout << std::endl;
		}
	}

};

template <typename T>
void
zero_matrix_impl(const Matrix<T> & mat, int row_tl, int col_tl, int row_br, int col_br, std::vector<Point> & zeros) {

        for(int i = row_tl; i < row_br; ++i) {
                for(int j = col_tl; j < col_br; ++j) {
                        if(mat.get(i,j) == 0) {
                                zero_matrix_impl(mat, i+1, 0, mat.rows, j, zeros);
                                zero_matrix_impl(mat, i+1, j+i, mat.rows, mat.cols, zeros);
				zeros.push_back(Point(j,i));
                        }
                }
        }

}

template <typename T>
void
zero_matrix(Matrix<T> & mat) {

	std::vector<Point> zeros;

	zero_matrix_impl(mat, 0, 0, mat.rows, mat.cols, zeros);

	for(int z=0; z < zeros.size(); ++z) {
		auto p = zeros[z];
		for(int r = 0; r < mat.rows; ++r) mat.set(r, p.x, 0);
		for(int c = 0; c < mat.cols; ++c) mat.set(p.y, c, 0);
	}

}

int main() {

	const int N = 3;
	const int M = 4;

	Matrix<int> m1(M,N);

	for(int i = 0; i < m1.rows; ++i)
		for(int j = 0; j < m1.cols; ++j)
			m1.set(i,j,(i*m1.rows+j+3)%(M*N));

	m1.print();

	zero_matrix(m1);

	m1.print();

	return 0;
}
