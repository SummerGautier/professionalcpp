#include <iostream>

// the inputs are not known until runtime, but once known are immutable.
int32_t area (const int32_t length, const int32_t width) {
    // if length or width are negative, that is not a legal scalar value.
    if (length < 0 || width < 0) {
        // just did a new text. throw an exception. If it is not caught, the program terminates.
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

int32_t error_5_5_1 () {
    double user_area {0};
    // length and width immutable and known at compile time.
    constexpr int32_t length {-5};
    constexpr int32_t width {2};

    // try to calculate un-framed area.
    try {
        user_area = area(length, width);
    } catch (std::range_error& e){
        std::cout << "Oops! Bad arguments to area." << std::endl;
        std::cerr << "error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    std::cout << user_area << std::endl;

    // try to calculate framed area.
    user_area = framed_area(length, width);
    std::cout << user_area << std::endl;

    // return success status code.
    return EXIT_SUCCESS;
}

int32_t error_5_5_3 () {
    // area values are negative.
    constexpr int32_t length {-1};
    constexpr int32_t width {-2};

    try {
        // try to calculate negative area.
        area(length, width);
        // if successful, return status code.
        return EXIT_SUCCESS;
    } catch (std::exception& e) {
        // catch and report exception.
        std::cerr << "error: " << e.what() << std::endl;
        // return failure status code.
        return EXIT_FAILURE;
    }
}

int32_t main () {
    return error_5_5_3();
}
