#include "Vector.h"

Vector::Vector () {
  size = 2;
  const int value = 2;

  vec = new int [size];

  for (int i = 0; i < size; ++i) {
    vec [i] = value;
  }
}

Vector::Vector (const Vector & v) {
  size = v.size;

  vec = new int [size];

  for (int i = 0; i < size; ++i) {
    vec [i] = v.vec[i];
  }
}

Vector::Vector (const int n) : size {n} {
  const int value = 2;

  vec = new int [size];

  for (int i = 0; i < size; ++i) {
    vec [i] = value;
  }
}

Vector::Vector (const int n, const int value) : size {n} {

  vec = new int [size];

  for (int i = 0; i < size; ++i) {
    vec [i] = value;
  }
}

Vector::~Vector() {
  delete vec;
}
