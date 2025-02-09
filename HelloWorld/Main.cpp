#include <iostream>
#include <cmath>

void keep_window_open() {
    std::cin.get();
    std::cin.get();
}

int main () {
    int32_t entry_a {0};
    int32_t entry_b {0};
    int32_t entry_c {0};

    std::cout << "Enter three values: ";
    std::cin >> entry_a >> entry_b >> entry_c;

    int32_t least_value {0};
    least_value = std::min(std::min(entry_a, entry_b), entry_c);
    int32_t max_value {0};
    max_value = std::max(std::max(entry_a, entry_b), entry_c);
    int32_t median_value {0};
    median_value = std::min(std::max(entry_a, entry_b), entry_c);
    
    std::cout << "least: " << least_value << std::endl;
    std::cout << "most: " << max_value << std::endl;
    std::cout << "median: " << median_value << std::endl;
    
    keep_window_open();
    return 0;
}