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

//destructor
Matrix::~Matrix() {
  for (int i = 0; i < rows; ++i)
    delete matrix[i];
  delete matrix;
}


//in/out
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

//getters
int Matrix::getRows () {
  return rows;
}

int Matrix::getColumns () {
  return columns;
}

//math
Matrix Matrix::operator+ (const Matrix & m1) {
  if (m1.rows != rows || m1.columns != columns) {
    std::cout << "Sizes do not match\n"
              << "Exit\n";
    exit(1);
  }

  Matrix sum (m1);
  for (int i = 0;  i < rows; ++i)
    *sum.matrix[i] += *matrix[i];
  return sum;
}

Matrix Matrix::operator- (const Matrix & m1) {
  if (m1.rows != rows || m1.columns != columns) {
    std::cout << "Sizes do not match\n"
              << "Exit\n";
    exit(1);
  }

  Matrix difference (m1);
  for (int i = 0;  i < rows; ++i)
    *difference.matrix[i] -= *matrix[i];
  return difference;
}

Matrix Matrix::operator* (const int n) {
  for (int i = 0;  i < rows; ++i)
    *matrix[i] *= n;
  return *this;
}

Matrix & Matrix::operator+= (const Matrix & m1) {
  if (m1.rows != rows || m1.columns != columns) {
    std::cout << "Sizes do not match\n"
              << "Exit\n";
    exit(1);
  }

  for (int i = 0;  i < rows; ++i)
    *matrix[i] += *m1.matrix[i];
  return *this;
}

Matrix & Matrix::operator-= (const Matrix & m1) {
  if (m1.rows != rows || m1.columns != columns) {
    std::cout << "Sizes do not match\n"
              << "Exit\n";
    exit(1);
  }

  for (int i = 0;  i < rows; ++i)
    *matrix[i] -= *m1.matrix[i];
  return *this;
}

Matrix & Matrix::operator*= (const int n) {
  for (int i = 0;  i < rows; ++i)
    *matrix[i] *= n;
  return *this;
}

//logic
bool Matrix::operator== (const Matrix & m1) {
  if (m1.rows != rows || m1.columns != columns) {
    return false;
  }
  for (int i = 0; i < rows; ++i) {
    if (*matrix[i] != *m1.matrix[i])
      return false;
  }
  return true;
}

bool Matrix::operator!= (const Matrix & m1) {
  if (m1.rows != rows || m1.columns != columns) {
    return true;
  }
  for (int i = 0; i < rows; ++i) {
    if (*matrix[i] != *m1.matrix[i])
      return true;
  }
  return false;
}

//index
Vector & Matrix::operator[] (const int i) {
  return *matrix[i];
}

Matrix & Matrix::operator= (const Matrix & m1) {
  if (rows == m1.rows) {
    for (int i = 0; i < rows; ++i) {
      *matrix[i] = *m1.matrix[i];
    }
    return *this;
  }

  for (int i = 0; i < rows; ++i)
    delete matrix[i];
  delete matrix;

  rows = m1.rows;
  columns = m1.columns;
  matrix = new Vector* [rows];
  for (int i = 0; i < rows; ++i) {
    matrix[i] = new Vector (*m1.matrix[i]);
  }
  return *this;
}
