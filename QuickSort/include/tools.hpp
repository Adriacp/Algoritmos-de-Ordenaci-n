#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>


std::vector<float> generateRandomVectorFloat(size_t size) {
  std::srand(std::time(nullptr)); // Seed the random number generator
  std::vector<float> vec(size);
  for (size_t i = 0; i < size; ++i) {
      vec[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX); // Generate random value of type T
  }
  return vec;
}
  
template<typename T>
std::vector<T> QuickSort(const std::vector<T>& vec) {
  if (vec.size() <= 1) {
      return vec;
  }

  T pivot = vec[vec.size() / 2];
  std::vector<T> left;
  std::vector<T> right;
  for (size_t i = 0; i < vec.size(); ++i) {
      if (i == vec.size() / 2) continue; // Skip the pivot element
      if (vec[i] < pivot) {
          left.push_back(vec[i]);
      } else {
          right.push_back(vec[i]);
      }
  }

  left = QuickSort(left);
  right = QuickSort(right);
  // Combine the sorted left, pivot, and right
  std::vector<T> result;
  result.reserve(left.size() + 1 + right.size());
  result.insert(result.end(), left.begin(), left.end());
  result.push_back(pivot);
  result.insert(result.end(), right.begin(), right.end());
  return result;
}
