#include <iostream>
using namespace std;
#include <algorithm>

struct item
{
public:
    int price;
    int weight;
};

bool comp_ratio(item a, item b)
{
    double r1 = (double)a.price / (double)a.weight;
    double r2 = (double)b.price / (double)b.weight;
    return r1 > r2;
}

double fraction_knapsack(int w, item arr[], int n)
{
    sort(arr, arr + n, comp_ratio);
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {

        // If adding Item won't overflow,
        // add it completely
        if (arr[i].weight <= w)
        {
            w -= arr[i].weight;
            res += arr[i].price;
        }

        // If we can't add current Item,
        // add fractional part of it
        else
        {
            res += arr[i].price * ((double)w / (double)arr[i].weight);
            break;
        }
    }

    // Returning final value
    return res;
}

int main()
{
    int W = 50;
    item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << fraction_knapsack(W, arr, N);
    return 0;
}