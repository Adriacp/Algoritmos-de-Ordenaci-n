#include "../include/tools.hpp"

int main() {
    size_t size = 10; // Size of the vector to sort
    std::vector<float> vec = generateRandomVectorFloat(size);

    std::cout << "Original vector:" << std::endl;
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<float> sortedVec = MergeSort(vec);

    std::cout << "Sorted vector:" << std::endl;
    for (const auto& num : sortedVec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}