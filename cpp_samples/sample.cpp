// g++ -std=c++20 -o program sample.cpp

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <concepts>

template<typename T>
concept Number = std::is_arithmetic_v<T>;

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    auto square = [](Number auto n) {
        return n * n;
    };

    auto squared_numbers = numbers
        | std::views::transform(square);

    std::cout << "Squared Numbers: ";
    for (auto n : squared_numbers) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    auto even_squared_numbers = squared_numbers
        | std::views::filter([](int n) {
            return n % 2 == 0;
        });

    std::cout << "Even Squared Numbers: ";
    for (auto n : even_squared_numbers) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
}
