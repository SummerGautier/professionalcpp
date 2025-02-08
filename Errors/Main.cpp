#include <iostream>

// the inputs are not known until runtime, but once known are immutable.
int32_t area (const int32_t length, const int32_t width) {
    // if length or width are negative, that is not a legal scalar value.
    if (length < 0 || width < 0) {
        // throw an exception. If it is not caught, the program terminates.
       throw std::range_error("Both Length and Width must be non-negative.");
    }
    // calculate area and return.
    return length * width;
}

// frame size is known at compile time.
constexpr int32_t frame_size {5};
// the inputs are not known until runtime, but once known are immutable.
int32_t framed_area (const int32_t length, const int32_t width) {
    // call area with frame_size subtracted.
    return area(length-frame_size, width-frame_size);
}

int error_5_5_1 () {
    double user_area {0};
    // length and width immutable and known at compile time.
    constexpr int32_t length {5};
    constexpr int32_t width {2};

    // try to calculate un-framed area.
    try {
        user_area = area(length, width);
    } catch (std::range_error e){
        std::cout << "Oops! Bad arguments to area." << std::endl;
        return EXIT_FAILURE;
    }
    
    std::cout << user_area << std::endl;

    // try to calculate framed area.
    user_area = framed_area(length, width);
    std::cout << user_area << std::endl;

    return EXIT_SUCCESS;
}

int error_5_5_3 () {
    constexpr int32_t length {-1};
    constexpr int32_t width {-2};

    try {
        area(length, width);
        return EXIT_SUCCESS;
    } catch (std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}

int main () {
    return error_5_5_3();
}