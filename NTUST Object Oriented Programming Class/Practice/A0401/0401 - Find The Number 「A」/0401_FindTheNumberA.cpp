#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>  // for g++

using namespace std;

typedef float Number;

int main()
{
      Number numbers[30] = { 0 }, aNumber = 0;
      string line1, line2;
      while (getline(cin, line1) && getline(cin, line2))
      {
            // string to input string stream
            istringstream inputStringStream1(line1), inputStringStream2(line2);

            if (!(inputStringStream2 >> aNumber))
            {
                  break;  // or throw error
            }

            int lastMinDistnaceIndex = -1;
            Number minDistance = numeric_limits<Number>::infinity();  // or any large enough number

            for (int i = 0, c; (c = inputStringStream1.peek()) != 13 && c != -1; ++i)
            {
                  inputStringStream1 >> numbers[i];

                  // compute min distance
                  Number distance = fabs(numbers[i] - aNumber);
                  if (distance <= minDistance)
                  {
                        minDistance = distance;
                        lastMinDistnaceIndex = i;
                  }
            }

            // output
            for (int i = 0; i <= lastMinDistnaceIndex; ++i)
            {
                  if (fabs(numbers[i] - aNumber) == minDistance)
                  {
                        cout << numbers[i];
                        if (i != lastMinDistnaceIndex)
                        {
                              cout << " + ";
                        }
                  }
            }
            cout << endl;
      }

      // system("pause");
}
