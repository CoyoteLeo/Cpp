#include <iostream>
#include <string>
using namespace std;

template <typename t>
void ItrSearch(const t a[], int lowEnd, int highEnd, t key, bool& found, int& location)
{
    int first = lowEnd;
    int last = highEnd;
    int mid;
    found = false;  // so far
    while ((first <= last) && !(found))
    {
        mid = (first + last) / 2;
        if (key == a[mid])
        {
            found = true;
            location = mid;
        }
        else if (key < a[mid])
            last = mid - 1;
        else if (key > a[mid])
            first = mid + 1;
    }
}

template <typename t>
void recBinSrch(const t a[], int lowEnd, int highEnd, t key, bool& found, int& location)
{
    found = false;
    if (lowEnd > highEnd)
        return;
    int mid = (lowEnd + highEnd) / 2;
    if (key == a[mid])
    {
        found = true;
        location = mid;
    }
    else if (key < a[mid])
        recBinSrch(a, lowEnd, mid - 1, key, found, location);
    else if (key > a[mid])
        recBinSrch(a, mid + 1, highEnd, key, found, location);
}

#define ARRAY_SIZE 10

int main()
{
    int a[ARRAY_SIZE];
    const int finalIndex = ARRAY_SIZE - 1;
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
        a[i] = 3 * i;
    cout << "Array contains:\n";
    for (i = 0; i < ARRAY_SIZE; i++)
        cout << a[i] << " ";
    cout << endl;
    int key, location;
    bool found;
    cout << "Enter number to be located: ";
    cin >> key;
    cout << "\nTesting Template Iterative Binary Search\n";
    ItrSearch(a, 0, finalIndex, key, found, location);
    if (found)
        cout << key << " is in index location " << location << endl;
    else
        cout << key << " is not in the array." << endl;
    cout << "\nTesting Template Recursive Binary Search\n";
    recBinSrch(a, 0, finalIndex, key, found, location);
    if (found)
        cout << key << " is in index location " << location << endl;
    else
        cout << key << " is not in the array." << endl;

    string t[5];
    string ch;
    cout << "Enter number to be located: ";
    cin >> ch;
    cout << "\nTesting Template Iterative Binary Search\n";
    ItrSearch(t, 0, finalIndex, ch, found, location);
    if (found)
        cout << ch << " is in index location " << location << endl;
    else
        cout << ch << " is not in the array." << endl;
    cout << "\nTesting Template Recursive Binary Search\n";
    recBinSrch(t, 0, finalIndex, ch, found, location);
    if (found)
        cout << ch << " is in index location " << location << endl;
    else
        cout << ch << " is not in the array." << endl;
    system("pause");
    return 0;
}