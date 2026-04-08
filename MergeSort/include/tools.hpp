#include <vector>
#include <iostream>


std::vector<float> generateRandomVectorFloat(size_t size) {
  std::vector<float> vec(size);
  for (size_t i = 0; i < size; ++i) {
      vec[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX); // Generate random value of type T
  }
  return vec;
}


template<typename T>
std::vector<T> merge(const std::vector<T>& left, const std::vector<T>& right) {
    std::vector<T> result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            ++i;
        } else {
            result.push_back(right[j]);
            ++j;
        }
    }

    // Append any remaining elements from either vector
    result.insert(result.end(), left.begin() + i, left.end());
    result.insert(result.end(), right.begin() + j, right.end());

    return result;
}
  
template<typename T>
std::vector<T> MergeSort(const std::vector<T>& vec) {
    if (vec.size() <= 1) {
        return vec;
    }

    size_t mid = vec.size() / 2;
    std::vector<T> left(vec.begin(), vec.begin() + mid);
    std::vector<T> right(vec.begin() + mid, vec.end());

    left = MergeSort(left);
    right = MergeSort(right);

    return merge(left, right);
}
