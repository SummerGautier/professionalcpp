#include <iostream> // cout, cin
#include <math.h>

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

// Utility function for suqareing int32. Using _local to differentiate from std::square
int32_t square_local(int32_t x) {
    return x * x;
}

void computation_4_4_2_1 () {
    // local variables are intialized.
    int32_t iterator {0};
    int32_t square {0};

    // print the squares of zero to one hundred.
    while (iterator < 100) {
        int32_t square_iterator = square_local(iterator);
        std::cout << iterator << '\t' << square_iterator << '\n';
        ++iterator;
    }

    // local variables are initialized.
    char alpha {'a'};
    char current {'a'};

    // print the increasing offset char until we reach letter z.
    for (int offset{0}; current < 'z'; ++offset) {
        current = char(alpha + offset);
        std::cout << current << std::endl;
    }
}

void computation_4_4_1_3 () {
    // local variables are initialized.
    char response {' '};

    // obtain response from user.
    std::cout << "Do you prefer fish?" << std::endl;
    std::cin >> response;

    // switch case only accepts integer or enumerate types.
    switch (response) {
        case 'Y':
            std::cout << "Great! You are in luck today." << std::endl;
            break;
        case 'N':
            std::cout << "That's unfortunate. It's all we have." << std::endl;
            break;
        case 'M':
            std::cout << "Maybe? Well, perhaps I can persaude you..." << std::endl;
            break;
        default:
            std::cout << "Try the fish anyways." << std::endl;
            break;
    }
}

void computation_4_4_1_1 () {
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

void computation_4_4_1_0 () {
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
    computation_4_4_2_1();
    return 0;
}