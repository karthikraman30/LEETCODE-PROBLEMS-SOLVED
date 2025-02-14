#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct item
{
    int value;
    int weight;
};
class Solution
{
public:
    bool static compare(item a, item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalknapsack(int w, vector<item> arr, int n)
    {
        sort(arr.begin(), arr.end(), compare);
        double totalvalue = 0.0;
        int currentweight = 0;

        for (int i = 0; i < n; i++)
        {
            if (currentweight + arr[i].weight <= w)
            {
                currentweight += arr[i].weight;
                totalvalue += arr[i].value;
            }
            else
            {
                int remain = w - currentweight;
                totalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;
            }
        }
        return totalvalue;
    }
};

int main()
{
    int n, weight;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<item> arr(n);
    cout << "Enter the item value and weight";
    for (int i = 0; i < n; i++)
    {
        cout << "Item" << i + 1 << "(value weight)";
        cin >> arr[i].value >> arr[i].weight;
    }

    cout << "Enter the knapsack capactity: ";
    cin >> weight;

    Solution obj;
    double ans = obj.fractionalknapsack(weight, arr, n);
    cout << "The maximumm value is: " << ans;
    return 0;
}