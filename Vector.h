#ifndef VECTOR
#define VECTOR

#include <iostream>

class Vector {
  int *vec;
  int size;
public:
  //Costructors
  Vector();                                     //default
  Vector(const Vector & v);                     //copy
  Vector(const int n);                          //n-sized, with pre-declared value
  Vector(const int n, const int value);         //n-sized, value passed as argument

  //Destructor
  ~Vector();
  //Getters
  int getSize();

  //math
  Vector operator+ (const Vector & v1);         //natural addition
  Vector operator- (const Vector & v1);         //natural subtraction
  Vector operator* (const int n);               //multiply by a number
  Vector operator* (const Vector & v1);         //multiply elements respectivly
  Vector & operator+= (const Vector & v1);      //same as +, but in-place
  Vector & operator-= (const Vector & v1);      //same as -, but in-place
  Vector & operator*= (const int n);            //same as * integer, but in-place
  Vector & operator*= (const Vector & v1);      //same as *, but in-place

  //logic
  bool operator== (const Vector &v1);
  bool operator!= (const Vector &v1);

  //in/out
  friend std::ostream & operator<< (std::ostream &out, const Vector &v1);
  friend std::istream & operator>> (std::istream &in, Vector &v1);

  //index
  int operator[] (const int i);                 //access i-th element

};


#endif
