#include <iostream> // cout, cin

// Global constant expression.
constexpr int32_t max = 100;

// Utility function for calculating arbitrary values.
void use (int32_t number) {
    // constant expressions are known at compile time.
    constexpr int32_t c1 = max + 7;
    // const are not known at compile time, but once known are immutable.
    const int32_t c2 = number + 7;
    // printing the result of the operations.
    std::cout << "c1: " << c1 << " c2: " << c2 << std::endl;
    return;
}

void computation_4_4_1 () {
    // Always initialize variables.
    int32_t integer_a {0};
    int32_t integer_b {0};
    
    // Obtain users input for locals.
    std::cout << "Enter two integers: ";
    std::cin >> integer_a >> integer_b;

    // If statement chooses between two alternatives.
    if (integer_a < integer_b) {
        std::cout << "max: " << integer_b << std::endl;
    } else {
        std::cout << "max: " << integer_a << std::endl;
    }
}

void computation_4_3_0 () {
    // Initializing variables before operating.
    // Reserver the memory space for later.
    constexpr double PI {3.14159};
    double circumference {0};
    int32_t radius {0};

    // Obtain user input for these locals.
    std::cout << "Enter the circle's radius: " << std::endl;
    std::cin >> radius;
    
    // Calculate our dependent variable (circumference).
    circumference = PI * radius * 2;

    // Report the results to the user.
    std::cout << "Circumference: " << circumference << std::endl;
    use(circumference);
}

int main () {
    computation_4_4_1();
    return 0;
}