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
  const int value = 0;

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

int Vector::getSize() {
  return size;
}

Vector Vector::operator+ (const Vector & v1) {
  if (size != v1.size) {
    std::cout << "Sizes do not match, aborting";
    exit(1);
  }
  Vector sum (size);
  for (int i = 0; i < size; ++i) {
    sum.vec[i] = vec[i] + v1.vec[i];
  }
  return sum;
}

Vector Vector::operator- (const Vector & v1) {
  if (size != v1.size) {
    std::cout << "Sizes do not match, aborting";
    exit(1);
  }
  Vector difference (size);
  for (int i = 0; i < size; ++i) {
    difference.vec[i] = vec[i] - v1.vec[i];
  }
  return difference;
}

Vector Vector::operator* (const int n) {
  Vector result (size);
  for (int i = 0; i < size; ++i) {
    result.vec[i] *= n;
  }
  return result;
}

Vector Vector::operator* (const Vector & v1) {
  if (size != v1.size) {
    std::cout << "Sizes do not match, aborting";
    exit(1);
  }
  Vector product (size);
  for (int i = 0; i < size; ++i) {
    product.vec[i] = vec[i] * v1.vec[i];
  }
  return product;
}

Vector & Vector::operator+= (const Vector & v1) {
  if (size != v1.size) {
    std::cout << "Sizes do not match, aborting";
    exit(1);
  }
  for (int i = 0; i < size; ++i) {
    vec[i] += v1.vec[i];
  }
  return *this;
}

Vector & Vector::operator-= (const Vector & v1) {
  if (size != v1.size) {
    std::cout << "Sizes do not match, aborting";
    exit(1);
  }
  for (int i = 0; i < size; ++i) {
    vec[i] += v1.vec[i];
  }
  return *this;
}

Vector & Vector::operator*= (const int n) {
  for (int i = 0; i < 0; ++i)
    vec[i] *= n;
  return *this;
}

Vector & Vector::operator*= (const Vector & v1) {
  if (size != v1.size) {
    std::cout << "Sizes do not match, aborting";
    exit(1);
  }
  for (int i = 0; i < size; ++i) {
    vec[i] *= v1.vec[i];
  }
  return *this;
}
