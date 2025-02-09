#include <iostream>
#include <vector>
#include <algorithm>

void computation_4_6_1 () {
    // create a vector of integers.
    std::vector <int32_t> v = {5, 7, 9, 4, 6, 8};
    // create a vector of size 6 all initialized to zero.
    std::vector <int32_t> v_zeros(6);

    // iterate through a vector by index.
    for (int32_t index {0}; index < v.size(); ++index) {
        // reference an item by index [].
        std::cout << v[index] << std::endl;
    }

    return;
}

void computation_4_6_2 () {
    // create an empty vector.
    std::vector<double> v;
    // add an element to the end of the list.
    v.push_back(2.7);
    v.push_back(5.6);
    v.push_back(7.9);

    // the size should be three.
    std::cout << v.size() << std::endl;
}

void computation_4_6_3 () {
    // create an empty vector to hold temperature (doubles).
    std::vector<double> temps {};
    // infinite loop for getting user input.
    double temp {0};
    // stop once we have five elements.
    while (temps.size() < 5) {
        std::cin >> temp;
        // push back temp into vector.
        temps.push_back(temp);
    }
    
    // sort the temperatures in-place.
    std::sort(temps.begin(), temps.end());
    // print out final vector
    for (double temp : temps) {
        std::cout << temp << ",";
    }
}

int main () {
    computation_4_6_3();

    // return signal success.
    return 0;
}