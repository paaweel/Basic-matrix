#ifndef MATRIX
#define MATRIX

#include "Vector.h"

class Matrix {
  Vector **matrix;
  int rows;
  int columns;

public:
  //constructors
  Matrix ();                                                          //default
  Matrix (const Matrix &m1);                                          //copy
  Matrix (const int newRows, const int newColumns);                   //arguments defined size
  Matrix (const int newRows, const int newColumns, const int value);  //same as above, but with a value

  int getRows ();
  int getColumns();

  friend std::ostream & operator<< (std::ostream &out, const Matrix & m1);
  friend std::istream & operator>> (std::istream &in, Matrix & m1);

};

#endif
