#include <iostream>
#include <string>
#include <vector>
#include "../npy.hpp"

using namespace std;

int test_load(void) {
  size_t i;
  vector<unsigned long> shape;
  vector<double> data;

  npy::LoadArrayFromNumpy("data/f8.npy", shape, data);

  cout << "shape: ";
  for (i=0; i<shape.size()-1; i++)
    cout << shape[i] << ", ";
  cout << shape[i] << endl;

  cout << "data: ";
  for (i=0; i<data.size()-1; i++)
    cout << data[i] << ", ";
  cout << data[i] << endl;

  return 0;
}

int test_save(void) {
  const long unsigned leshape [] = {2,3};
  vector<double> data {1, 2, 3, 4, 5, 6};
  npy::SaveArrayAsNumpy("data/out.npy", false, 2, leshape, data);

  const long unsigned leshape2 [] = {6};
  npy::SaveArrayAsNumpy("data/out2.npy", false, 1, leshape2, data);

  return 0;
}

int main(int argc, char **argv) {
  test_load();

  test_save();

  return 0;
}

