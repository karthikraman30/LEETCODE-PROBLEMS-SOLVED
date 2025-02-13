#include <iostream>
#include <vector>
#include <string_view>
#include <array>
#include <algorithm>

struct Coin
{
    int value;
    std::string_view name;
};

std::vector<Coin> makeChange(int n)
{
    static constexpr std::array coins = {
        Coin{100, "Dollar"},
        Coin{25, "Quarter"},
        Coin{10, "Dime"},
        Coin{5, "Nickel"},
        Coin{1, "Penny"}};

    std::vector<Coin> result;

    for (const auto &coin : coins)
    {
        while (n >= coin.value)
        {
            result.push_back(coin);
            n -= coin.value;
        }
    }

    return result;
}

int main()
{
    int amount;
    std::cout << "Enter the amount in cents: ";
    std::cin >> amount;

    auto change = makeChange(amount);

    std::cout << "To make change for " << amount << " cents, use these coins:\n";
    for (const auto &coin : change)
    {
        std::cout << coin.name << " (" << coin.value << " cents)\n";
    }

    std::cout << "Total number of coins used: " << change.size() << '\n';

    return 0;
}