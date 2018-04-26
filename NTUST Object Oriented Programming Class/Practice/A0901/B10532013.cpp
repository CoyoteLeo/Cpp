#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, q, p1, p2, *pos, counter;
    while (cin >> n >> m >> q)
    {
        counter = 1;
        pos = new int[n + 1]();
        for (int i = 0; i < n + 1; i++)
            pos[i] = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> p1 >> p2;
            if (pos[p1] != 0 && pos[p2] == 0)
            {
                pos[p2] = pos[p1];
            }
            else if (pos[p2] != 0 && pos[p1] == 0)
            {
                pos[p1] = pos[p2];
            }
            else if (pos[p1] == 0 && pos[p2] == 0)
            {
                pos[p1] = pos[p2] = counter++;
            }
            else
            {
                for (int j = 0; j < n + 1; j++)
                {
                    int temp = pos[p2];
                    if (pos[j] == temp)
                        pos[j] = pos[p1];
                }
            }
        }
        // push someone that he is not belong to any relationship
        for (int i = 1; i < n + 1; i++)
        {
            if (pos[i] == 0)
            {
                pos[i] = counter++;
            }
        }
        for (int i = 0; i < q; i++)
        {
            cin >> p1 >> p2;
            if (pos[p1] == pos[p2])
            {
                cout << ":)" << endl;
            }
            else
            {
                cout << ":(" << endl;
            }
        }
        delete[] pos;
    }
    return 0;
}