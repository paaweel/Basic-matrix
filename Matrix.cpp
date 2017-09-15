#include "Matrix.h"

Matrix::Matrix () : rows {2}, columns {2} {
  matrix = new Vector* [rows];
  for (int i = 0; i < rows; ++i) {
    matrix[i] = new Vector (columns);
  }
}

Matrix::Matrix (const Matrix &m1) : rows {m1.rows}, columns {m1.columns} {
  matrix = new Vector* [rows];
  for (int i = 0; i < rows; ++i) {
    matrix[i] = new Vector (*m1.matrix[i]);
  }
}

Matrix::Matrix (const int newRows, const int newColumns) : rows {newRows}, columns {newColumns} {
  matrix = new Vector* [rows];
  for (int i = 0; i < rows; ++i) {
    matrix[i] = new Vector (columns);
  }
}

Matrix::Matrix (const int newRows, const int newColumns, const int value) : rows {newRows}, columns {newColumns} {
  matrix = new Vector* [rows];
  for (int i = 0; i < rows; ++i) {
    matrix[i] = new Vector (columns, value);
  }
}

std::ostream & operator<< (std::ostream &out, const Matrix & m1) {
  for (int i = 0; i < m1.rows; ++i)
    out << *m1.matrix[i];
  return out;
}

std::istream & operator>> (std::istream &in, Matrix & m1) {
  for (int i = 0; i < m1.rows; ++i)
    in >> *m1.matrix[i];
  return in;
}
