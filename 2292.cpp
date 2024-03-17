#include <iostream>

using namespace std;

int main()
{
    int num = 0;
    int layer = 1;

    cin >> num;

    if (num == 1)
        layer = 1;

    else
    {
        while(1)
        {
            layer++;
            if(num > 3 * layer * (layer - 1) + 1)
                continue;
            else
                break;
        }
    }
    cout << layer;
    return 0;
}
