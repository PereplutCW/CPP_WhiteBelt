#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
private:
  int numRows;
  int numColumns;

  vector<vector<int>> elements;

public:
  Matrix() {
    numRows = 0;
    numColumns = 0;
  }

  Matrix(int newNumRows, int newNumColumns) {
    Reset(newNumRows, newNumColumns);
  }

  void Reset(int newNumRows, int newNumColumns) {
    if (newNumRows < 0) {
      throw out_of_range("newNumRows must be >= 0");
    }
    if (newNumColumns < 0) {
      throw out_of_range("newNumColumns must be >= 0");
    }
    if (newNumRows == 0 || newNumColumns == 0) {
      newNumRows = newNumColumns = 0;
    }

    numRows = newNumRows;
    numColumns = newNumColumns;
    elements.assign(newNumRows, vector<int>(newNumColumns));
  }

  int At(int row, int column) const {
    return elements.at(row).at(column);
  }

  int& At(int row, int column) {
    return elements.at(row).at(column);
  }

  int GetNumRows() const {
    return numRows;
  }

  int GetNumColumns() const {
    return numColumns;
  }
};

 bool operator==(const Matrix& one, const Matrix& two) {
   if (one.GetNumRows() != two.GetNumRows()) {
     return false;
   }
   if (one.GetNumColumns() != two.GetNumColumns()) {
     return false;
   }
   for (int row = 0; row < one.GetNumRows(); ++row) {
     for (int column = 0; column < one.GetNumColumns(); ++column) {
       if (one.At(row, column) != two.At(row, column)) {
         return false;
       }
     }
   }
   return true;
 };

 Matrix operator+(const Matrix& one, const Matrix& two) {
   if (one.GetNumRows() != two.GetNumRows()) {
     throw invalid_argument("Dismatched number of rows");
   }
   if (one.GetNumColumns() != two.GetNumColumns()) {
     throw invalid_argument("Dismatched number of columns");
   }
   Matrix result(one.GetNumRows(), one.GetNumColumns());
   for (int row = 0; row < result.GetNumRows(); ++row) {
      for (int column = 0; column < result.GetNumColumns(); ++column) {
        result.At(row, column) = one.At(row, column) + two.At(row, column);
      }
    }
   return result;
 }

 istream& operator>>(istream& input, Matrix& matrix) {
   int numRows, numColumns;
   input >> numRows >> numColumns;

   matrix.Reset(numRows, numColumns);
   for (int row = 0; row < numRows; ++row) {
     for (int column = 0; column < numColumns; ++column) {
       input >> matrix.At(row, column);
     }
   }
   return input;
 }

 ostream& operator<<(ostream& output, const Matrix& matrix) {
   output << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
   for (int row = 0; row < matrix.GetNumRows(); ++row) {
     for (int column = 0; column < matrix.GetNumColumns(); ++column) {
       if (column > 0) {
         output << " ";
       }
       output << matrix.At(row, column);
     }
     output << endl;
   }
   return output;
 }

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
