#include <iostream>

int32_t area (int32_t length, int32_t width) {
    if (length < 0) {
       throw std::range_error("Length must be non-negative.");
    }

    if (width < 0) {
       throw std::range_error("Width must be non-negative");
    }
    
    return length * width;
}

void error_5_5_1 () {
    double user_area = area (-5,-2);
    std::cout << user_area << std::endl;
}

int main () {
    error_5_5_1();
    return 0;
}