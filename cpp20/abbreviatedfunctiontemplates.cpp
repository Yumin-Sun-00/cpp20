#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T, typename U> // We're using two template type parameters named T and U
T max2(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x > y) ? x : y; // uh oh, we have a narrowing conversion problem here
}


template <typename T, typename U>
auto max3(T x, U y)
{
    return (x > y) ? x : y;
}

// The compiler will automatically convert the function into a function template with each auto parameter becoming an independent template type parameter
auto max4(auto x, auto y)
{
    return (x > y) ? x : y;
}

// There isn’t a concise way to use abbreviated function templates when you want more than one auto parameter to be the same type.
template <typename T>
auto max5(T x, T y) // two parameters of the same type
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << max(1, 2) << '\n';   // will instantiate max(int, int)
    std::cout << max(1.5, 2.5) << '\n'; // will instantiate max(double, double)
    //std::cout << max(2, 3.5) << '\n';  // compile error: Since no non-template match was found, and no template match was found, the function call fails to resolve, and we get a compile error.

    // You might wonder why the compiler didn’t generate function max<double>(double, double)
    // and then use numeric conversion to type convert the int argument to a double.
    // The answer is simple: type conversion is done only when resolving function overloads,
    // not when performing template argument deduction.

    //! Solution 1
    std::cout << max(static_cast<double>(2), 3.5) << '\n'; // convert our int to a double so we can call max(double, double)

    //! Solution 2
    //! If we had written a non-template max(double, double) function
    //! std::cout << max(2, 3.5) << '\n'; // the int argument will be converted to a double
    //!
    //! Solution 3
    //! when the compiler is doing template argument deduction, it won’t do any type conversions.
    //! std::cout << max<double>(2, 3.5) << '\n'; // we've provided actual type double, so the compiler won't use template argument deduction



    // Functions templates with multiple template type parameters
    //! Solution 4: narrowing conversion
    //! using the usual arithmetic rules (8.4 -- Arithmetic conversions),
    //! double takes precedence over int, so our conditional operator will return a double.
    //! But our function is defined as returning a T -- in cases where T resolves to an int,
    //! our double return value will undergo a narrowing conversion to an int,
    //! which will produce a warning (and possible loss of data).
    std::cout << max2(2, 3.5) << '\n'; // cout 3


    //! Solution 5: c++14
    // This is a good use for an auto return type --
    // we’ll let the compiler deduce what the return type should be from the return statement:

    std::cout << max3(2, 3.5) << '\n'; // cout 3.5

    //! Solution 6: c++20
    //! Abbreviated function templates

    return 0;
}
