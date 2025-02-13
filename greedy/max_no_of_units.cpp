#include <vector>
#include <iostream>
using namespace std;

bool compare(vector<int> a, vector<int> b) { return a[1] > b[1]; }

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int totalunits = 0, i = 0;
        sort(boxTypes.begin(), boxTypes.end(), compare);
        while (truckSize > 0 && i < boxTypes.size())
        {
            if (boxTypes[i][0] <= truckSize)
            {
                totalunits += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                int cantake = truckSize;
                truckSize -= cantake;
                totalunits += cantake * boxTypes[i][1];
            }
            i++;
        }
        return totalunits;
    }
};