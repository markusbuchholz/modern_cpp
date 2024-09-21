# **C++11 to C++20**

The following guide will help you quickly upgrade from C++11 to C++20 by covering the key features introduced in C++14, C++17, and C++20.
Each feature includes examples to illustrate how they work, enabling you to adopt modern C++ programming practices.

---

## **Table of Contents**

- [C++14 Features](#c14-features)
  - [Generic Lambdas](#1-generic-lambdas)
  - [Return Type Deduction for Normal Functions](#2-return-type-deduction-for-normal-functions)
  - [Variable Templates](#3-variable-templates)
  - [Binary Literals](#4-binary-literals)
  - [Digit Separators](#5-digit-separators)
  - [\[Deprecated\] Attribute](#6-deprecated-attribute)
- [C++17 Features](#c17-features)
  - [Structured Bindings](#1-structured-bindings)
  - [If and Switch with Initializer](#2-if-and-switch-with-initializer)
  - [Fold Expressions](#3-fold-expressions)
  - [Constexpr If](#4-constexpr-if)
  - [Inline Variables](#5-inline-variables)
  - [Template Argument Deduction for Class Templates](#6-template-argument-deduction-for-class-templates)
  - [New Standard Library Components](#7-new-standard-library-components)
    - [std::optional](#a-stdoptional)
    - [std::variant](#b-stdvariant)
    - [std::any](#c-stdany)
    - [std::string_view](#d-stdstring_view)
    - [std::filesystem](#e-stdfilesystem)
  - [New Attributes](#8-new-attributes-nodiscard-maybe_unused-fallthrough)
- [C++20 Features](#c20-features)
  - [Concepts](#1-concepts)
  - [Ranges Library](#2-ranges-library)
  - [Modules](#3-modules)
  - [Coroutines](#4-coroutines)
  - [Designated Initializers](#5-designated-initializers)
  - [Three-Way Comparison Operator (`<=>`)](#6-three-way-comparison-operator-)
  - [Enhanced `constexpr`](#7-enhanced-constexpr)
  - [`consteval` and `constinit`](#8-consteval-and-constinit)
    - [`consteval`](#a-consteval)
    - [`constinit`](#b-constinit)
  - [Abbreviated Function Templates](#9-abbreviated-function-templates)
  - [Calendar and Time Zone Library](#10-calendar-and-time-zone-library)
  - [`std::format`](#11-stdformat)
  - [`std::span`](#12-stdspan)
  - [`std::jthread`](#13-stdjthread)
  - [Bit Manipulation Functions](#14-bit-manipulation-functions)
  - [Range-Based `for` Loop with Initializer](#15-range-based-for-loop-with-initializer)

---

## **C++14 Features**

### 1. Generic Lambdas

**Description:** Lambdas can have parameters with `auto` types, making them generic.

**Example:**

```cpp
auto add = [](auto a, auto b) {
    return a + b;
};

int sum_int = add(1, 2);           // sum_int = 3
double sum_double = add(1.5, 2.5); // sum_double = 4.0
```

### 2. Return Type Deduction for Normal Functions

**Description:** Functions can deduce their return type automatically without specifying it explicitly.

**Example:**

```cpp
auto multiply(int a, int b) {
    return a * b;
}

int result = multiply(3, 4); // result = 12
```

### 3. Variable Templates

**Description:** Templates can now be applied to variables, not just functions and classes.

**Example:**

```cpp
template<typename T>
constexpr T pi = T(3.1415926535897932385);

double pi_double = pi<double>;
float pi_float = pi<float>;
```

### 4. Binary Literals

**Description:** You can write binary numbers directly using the `0b` or `0B` prefix.

**Example:**

```cpp
int binary = 0b1010; // binary = 10 in decimal
```

### 5. Digit Separators

**Description:** Use single quotes (`'`) to make numeric literals more readable.

**Example:**

```cpp
int large_number = 1'000'000; // Easier to read as one million
```

### 6. `[[deprecated]]` Attribute

**Description:** Mark functions or variables as deprecated to generate compiler warnings when they are used.

**Example:**

```cpp
[[deprecated("Use new_function() instead")]]
void old_function() {
    // ...
}

void new_function() {
    // ...
}

int main() {
    old_function(); // Generates a compiler warning
    return 0;
}
```

---

## **C++17 Features**

### 1. Structured Bindings

**Description:** Unpack tuples, pairs, or structs into individual variables.

**Example:**

```cpp
#include <tuple>
#include <iostream>

int main() {
    std::tuple<int, double, std::string> t(1, 2.5, "hello");

    auto [i, d, s] = t;
    std::cout << i << ", " << d << ", " << s << '\n';

    return 0;
}
```

### 2. If and Switch with Initializer

**Description:** Initialize variables within `if` or `switch` statements.

**Example:**

```cpp
if (int x = compute_value(); x > 0) {
    std::cout << "Positive: " << x << '\n';
} else {
    std::cout << "Non-positive: " << x << '\n';
}
```

### 3. Fold Expressions

**Description:** Simplify variadic templates by applying an operator to all arguments.

**Example:**

```cpp
template<typename... Args>
auto sum(Args... args) {
    return (args + ...); // Right fold
}

int total = sum(1, 2, 3, 4); // total = 10
```

### 4. Constexpr If

**Description:** Compile-time conditional statements.

**Example:**

```cpp
template<typename T>
void check_type(T t) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integral type\n";
    } else {
        std::cout << "Non-integral type\n";
    }
}
```

### 5. Inline Variables

**Description:** Define variables in header files without violating the One Definition Rule.

**Example:**

```cpp
// config.h
struct Config {
    static inline int max_value = 100;
};

// main.cpp
#include "config.h"
#include <iostream>

int main() {
    std::cout << Config::max_value << '\n';
    return 0;
}
```

### 6. Template Argument Deduction for Class Templates

**Description:** Allow class templates to deduce template arguments from constructor arguments.

**Example:**

```cpp
#include <utility>

int main() {
    std::pair p(1, 2.0); // Deduces to std::pair<int, double>
    return 0;
}
```

### 7. New Standard Library Components

#### a. `std::optional`

Represents an optional value.

```cpp
#include <optional>
#include <iostream>

std::optional<int> find_value(bool found) {
    if (found) {
        return 42;
    } else {
        return std::nullopt;
    }
}

int main() {
    auto result = find_value(true);
    if (result) {
        std::cout << "Found: " << *result << '\n';
    } else {
        std::cout << "Not found\n";
    }
    return 0;
}
```

#### b. `std::variant`

Type-safe union that can hold one of several types.

```cpp
#include <variant>
#include <iostream>

int main() {
    std::variant<int, std::string> data;

    data = 10;
    std::cout << std::get<int>(data) << '\n';

    data = "Hello";
    std::cout << std::get<std::string>(data) << '\n';

    return 0;
}
```

#### c. `std::any`

Holds a value of any type.

```cpp
#include <any>
#include <iostream>

int main() {
    std::any value = 5;
    value = std::string("Hello");

    if (value.type() == typeid(std::string)) {
        std::cout << std::any_cast<std::string>(value) << '\n';
    }

    return 0;
}
```

#### d. `std::string_view`

A non-owning reference to a string.

```cpp
#include <string_view>
#include <iostream>

void print(std::string_view sv) {
    std::cout << sv << '\n';
}

int main() {
    std::string str = "Hello, World!";
    print(str);

    print("C++17 string_view");

    return 0;
}
```

#### e. `std::filesystem`

Operations for file system paths, directories, and files.

```cpp
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::path p = "test.txt";

    if (fs::exists(p)) {
        std::cout << "File size: " << fs::file_size(p) << " bytes\n";
    } else {
        std::cout << "File does not exist\n";
    }

    return 0;
}
```

### 8. New Attributes: `[[nodiscard]]`, `[[maybe_unused]]`, `[[fallthrough]]`

**Example:**

```cpp
[[nodiscard]] int compute() {
    return 42;
}

int main() {
    compute(); // Compiler may warn: ignoring nodiscard value
    return 0;
}
```

---

## **C++20 Features**

### 1. Concepts

**Description:** Constraints for template parameters, making templates easier to use and debug.

**Example:**

```cpp
#include <concepts>
#include <iostream>

template<typename T>
concept Number = std::is_arithmetic_v<T>;

template<Number T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(2, 3) << '\n';          // Works with integers
    std::cout << add(2.5, 3.5) << '\n';      // Works with doubles
    // add("a", "b"); // Error: const char* does not satisfy Number

    return 0;
}
```

### 2. Ranges Library

**Description:** A new way to work with collections, providing lazy evaluation and composition.

**Example:**

```cpp
#include <ranges>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers = {0, 1, 2, 3, 4, 5};

    auto even_numbers = numbers | std::views::filter([](int n) {
        return n % 2 == 0;
    });

    for (int n : even_numbers) {
        std::cout << n << ' '; // Output: 0 2 4
    }

    return 0;
}
```

### 3. Modules

**Description:** Replace header files to improve compilation times and code organization.

> **Note:** Compiler support for modules varies.

**Example:**

```cpp
// math.ixx
export module math;

export int add(int a, int b) {
    return a + b;
}

// main.cpp
import math;
#include <iostream>

int main() {
    std::cout << add(3, 4) << '\n'; // Output: 7
    return 0;
}
```

### 4. Coroutines

**Description:** Support for asynchronous programming via coroutines.

**Example:**

```cpp
#include <coroutine>
#include <iostream>

struct Generator {
    struct promise_type {
        int current_value;
        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }
        Generator get_return_object() {
            return Generator{ std::coroutine_handle<promise_type>::from_promise(*this) };
        }
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_void() {}
        void unhandled_exception() { std::exit(1); }
    };

    std::coroutine_handle<promise_type> handle;

    Generator(std::coroutine_handle<promise_type> h) : handle(h) {}
    ~Generator() { handle.destroy(); }

    bool next() {
        handle.resume();
        return !handle.done();
    }

    int value() {
        return handle.promise().current_value;
    }
};

Generator counter(int max) {
    for (int i = 0; i < max; ++i)
        co_yield i;
}

int main() {
    auto gen = counter(5);
    while (gen.next()) {
        std::cout << gen.value() << ' ';
    }
    // Output: 0 1 2 3 4

    return 0;
}
```

### 5. Designated Initializers

**Description:** Initialize specific members of a struct or class.

**Example:**

```cpp
struct Point {
    int x;
    int y;
};

int main() {
    Point p = {.y = 10, .x = 5}; // Members can be initialized out of order
    std::cout << p.x << ", " << p.y << '\n'; // Output: 5, 10
    return 0;
}
```

### 6. Three-Way Comparison Operator (`<=>`)

**Description:** Simplifies the creation of comparison operators.

**Example:**

```cpp
#include <compare>
#include <iostream>

struct Version {
    int major;
    int minor;

    auto operator<=>(const Version&) const = default;
};

int main() {
    Version v1{1, 0};
    Version v2{1, 1};

    if (v1 < v2) {
        std::cout << "v1 is less than v2\n";
    }

    return 0;
}
```

### 7. Enhanced `constexpr`

**Description:** More expressions and functions can be evaluated at compile-time, including those involving loops and conditionals.

**Example:**

```cpp
constexpr int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

static_assert(factorial(5) == 120, "Compile-time factorial");
```

### 8. `consteval` and `constinit`

#### a. `consteval`

**Description:** Functions that must be evaluated at compile-time.

**Example:**

```cpp
consteval int square(int n) {
    return n * n;
}

int main() {
    constexpr int result = square(5); // OK
    // int runtime_result = square(5); // Error: square must be evaluated at compile-time
    return 0;
}
```

#### b. `constinit`

**Description:** Ensures that a variable is initialized at compile-time.

**Example:**

```cpp
constinit int config_value = 100;

int main() {
    // config_value is guaranteed to be initialized
    return 0;
}
```

### 9. Abbreviated Function Templates

**Description:** Simplify template function syntax using `auto`.

**Example:**

```cpp
auto multiply(auto a, auto b) {
    return a * b;
}

int main() {
    std::cout << multiply(3, 4) << '\n';      // Output: 12
    std::cout << multiply(2.5, 4.0) << '\n';  // Output: 10.0
    return 0;
}
```

### 10. Calendar and Time Zone Library

**Description:** Standardized support for time zones and calendars.

**Example:**

```cpp
#include <chrono>
#include <iostream>

int main() {
    using namespace std::chrono;
    auto now = system_clock::now();
    zoned_time current_time{current_zone(), now};

    std::cout << "Current time: " << current_time << '\n';
    return 0;
}
```

### 11. `std::format`

**Description:** Type-safe and efficient string formatting.

**Example:**

```cpp
#include <format>
#include <iostream>

int main() {
    std::string message = std::format("Hello, {}! The answer is {}.", "Alice", 42);
    std::cout << message << '\n';
    return 0;
}
```

### 12. `std::span`

**Description:** A view over a contiguous sequence of objects.

**Example:**

```cpp
#include <span>
#include <vector>
#include <iostream>

void print(std::span<int> data) {
    for (int n : data) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    print(arr);

    std::vector<int> vec = {6, 7, 8, 9, 10};
    print(vec);

    return 0;
}
```

### 13. `std::jthread`

**Description:** A joining thread that automatically joins in its destructor.

**Example:**

```cpp
#include <thread>
#include <iostream>

void worker() {
    std::cout << "Worker thread is running\n";
}

int main() {
    std::jthread jt(worker);
    // No need to call jt.join(); it joins automatically
    return 0;
}
```

### 14. Bit Manipulation Functions

**Description:** New functions for bit manipulation in the `<bit>` header.

**Example:**

```cpp
#include <bit>
#include <iostream>

int main() {
    unsigned int x = 0b0101'0000;

    // Count leading zeros
    int lz = std::countl_zero(x);
    std::cout << "Leading zeros: " << lz << '\n';

    // Count trailing zeros
    int tz = std::countr_zero(x);
    std::cout << "Trailing zeros: " << tz << '\n';

    // Popcount
    int pc = std::popcount(x);
    std::cout << "Number of set bits: " << pc << '\n';

    return 0;
}
```

### 15. Range-Based `for` Loop with Initializer

**Description:** Declare and initialize variables within the range-based `for` loop.

**Example:**

```cpp
#include <vector>
#include <iostream>

int main() {
    for (std::vector<int> vec = {1, 2, 3, 4, 5}; int n : vec) {
        std::cout << n << ' ';
    }
    // vec is not accessible here
    return 0;
}
```

---
