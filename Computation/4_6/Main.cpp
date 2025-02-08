#include <iostream>
#include <vector>

int main () {
    // create a vector of integers.
    std::vector <int32_t> v = {5, 7, 9, 4, 6, 8};
    // create a vector of size 6 all initialized to zero.
    std::vector <int32_t> v_zeros(6);

    // iterate through a vector by index;
    for (int32_t index; index < v.size(); ++index) {
        // reference an item by index []
        std::cout << v[index] << std::endl;
    }
}