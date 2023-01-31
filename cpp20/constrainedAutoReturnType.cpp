#include <vector>
#include <array>
#include <iostream>
#include <concepts>

// compiled time check on type

std::floating_point auto foo(
        std::floating_point auto a,
        std::floating_point auto b
)
{
    return a*b;
}

int* getObject() { return nullptr; }

// define my own concept
template<class T>
concept notPointer = !std::is_pointer_v<T>;

int main()
{
    // attribute maybe_unused: Suppresses warnings on unused entities.
    [[maybe_unused]] const std::floating_point auto p = foo(4.5f,8.0);


    [[maybe_unused]] const notPointer auto obj = getObject();
    //return p;
}
