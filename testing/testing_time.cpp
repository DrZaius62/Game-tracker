
#include <ctime>
#include <chrono>
#include <iostream>

int main()
{
    auto const current = std::chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(current);
    std::cout << std::ctime(&currentTime) << std::endl;
}

