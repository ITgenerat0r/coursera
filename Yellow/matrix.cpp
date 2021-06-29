#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>


using namespace std;

class Matrix
{
public:
	Matrix(){
		m.clear();
	};

	Matrix(int num_rows, int num_cols){
		m.clear();
		vector<int> tmp;
		if (num_rows < 0 || num_cols < 0){
			throw out_of_range("out of range");
		}
		while(num_cols-- > 0) {
		    tmp.push_back(0);
		}
		while(num_rows-- > 0) {
		    m.push_back(tmp);
		}
	};

	void Reset(int num_rows, int num_cols){
		m.clear();
		vector<int> tmp;
		if (num_rows < 0 || num_cols < 0){
			throw out_of_range("out of range");
		}
		while(num_cols--) {
		    tmp.push_back(0);
		}
		while(num_rows--) {
		    m.push_back(tmp);
		}
	};

	int At(int row, int col) const {
		if (row > m.size()-1 || col > m[0].size()-1){
			throw out_of_range("out of range");
		}
		return m[row][col];
	};

	int& At(int row, int col){
		if (row > m.size()-1 || col > m[0].size()-1){
			throw out_of_range("out of range");
		}
		return m[row][col];
	};

	int GetNumRows() const {
		return m.size();
	};

	int GetNumCols() const {
		return m[0].size();
	};


	//~Matrix();
	
private:
	// vector<int> row;
	vector<vector<int>> m;
};


ostream& operator<<(ostream& stream, const Matrix& matrix){
	int r, c;
	r = matrix.GetNumRows();
	c = matrix.GetNumCols();
	stream << r << " " << c << endl;
	if (r == 0 || c == 0){
		return stream;
	}
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			stream << matrix.At(i, j) << ' ';
		}
		stream << endl;
	}
    return stream;
}

istream& operator>>(istream& stream, Matrix& matrix){
	int r, c;
	stream >> r >> c;
	matrix.Reset(r, c);
	if (r == 0 || c == 0){
		return stream;
	}
	int tmp = c;
	while(r--) {
		c = tmp;
	    while(c--) {
	        stream >> matrix.At(r, c);
	    }
	}
	return stream;
}

bool operator==(Matrix& ml, Matrix& mr){
	if(ml.GetNumCols() != mr.GetNumCols()){return false;}
	if(ml.GetNumRows() != mr.GetNumRows()){return false;}
	if (ml.GetNumCols() != 0 && ml.GetNumRows() != 0){
		for(int i=0; i<ml.GetNumRows(); i++) {
		    for(int j=0; j<ml.GetNumCols(); j++) {
		        if(ml.At(i, j) != mr.At(i, j)){
		        	return false;
		        }
		    }
		}
	}
	return true;
}

Matrix& operator+(Matrix& ml, Matrix& mr){
	if(ml.GetNumCols() != mr.GetNumCols() || ml.GetNumRows() != mr.GetNumRows()){
		throw invalid_argument("invalid argument");
	}
	
	Matrix rm(ml.GetNumRows(), ml.GetNumCols());

	for(int i=0; i<ml.GetNumRows(); i++) {
	    for(int j=0; j<ml.GetNumCols(); j++) {
	        rm.At(i, j) = ml.At(i, j) + mr.At(i, j);
	    }
	}
	return rm;
}

int main() {
  Matrix one;
  Matrix two;
  cin >> one;
  cout << endl;
  cin >> two;
  if(one == two){
  	cout << "true" << endl;
  } else {
  	cout << "false" << endl;
  }
  cout << one + two << endl;
  return 0;
}