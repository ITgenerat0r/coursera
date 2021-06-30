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

	int GetNumColumns() const {
		return m[0].size();
	};


	//~Matrix();
	
private:
	// vector<int> row;
	vector<vector<int>> m;
};


ostream& operator<<(ostream& stream, Matrix& matrix){
	int r, c;
	r = matrix.GetNumRows();
	c = matrix.GetNumColumns();
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
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
	        stream >> matrix.At(i, j);
	    }
	}
	return stream;
}

bool operator==(Matrix& ml, Matrix& mr){
	if(ml.GetNumColumns() != mr.GetNumColumns()){return false;}
	if(ml.GetNumRows() != mr.GetNumRows()){return false;}
	if (ml.GetNumColumns() != 0 && ml.GetNumRows() != 0){
		for(int i=0; i<ml.GetNumRows(); i++) {
		    for(int j=0; j<ml.GetNumColumns(); j++) {
		        if(ml.At(i, j) != mr.At(i, j)){
		        	return false;
		        }
		    }
		}
	}
	return true;
}

Matrixll; operator+(const Matrix& ml,const Matrix& mr){
	if(ml.GetNumColumns() != mr.GetNumColumns() || ml.GetNumRows() != mr.GetNumRows()){
		throw invalid_argument("invalid argument");
	}
	
	Matrix rm(ml.GetNumRows(), ml.GetNumColumns());

	for(int i=0; i<ml.GetNumRows(); i++) {
	    for(int j=0; j<ml.GetNumColumns(); j++) {
	        rm.At(i, j) = ml.At(i, j) + mr.At(i, j);
	    }
	}
	return rm;
}




int main() {
  Matrix one;
  Matrix two;

  try {
  	cin >> one >> two;
  }
  catch(const std::exception& e) {
  	std::cerr << e.what() << '\n';
  }

  try {
  	cout << one + two << endl;
  }
  catch(const std::exception& e) {
  	std::cerr << e.what() << '\n';
  }
  return 0;
}