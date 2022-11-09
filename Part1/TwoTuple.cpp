#include <iostream>

#include "TwoTuple.h"

TwoTuple::TwoTuple(int _position, int _length) : position(_position), length(_length) { }

void TwoTuple::displayTuple( ) {
   std::cout << "(" << position << ", " << length << ")";
}
