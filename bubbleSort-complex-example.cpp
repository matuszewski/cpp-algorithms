#include <iostream> /* cin, cout*/
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

using namespace std;

void randomizeArray(int *tab, int size);
void printArray(int *tab, int size);

bool larger(int &l, int &r);
bool smaller(int &l, int &r);

/*  SORTING  */
void sort(int *tab, int size, bool (*f)(int &l, int &r)); //smaller or larger

/*  SEARCHING  */
bool linearSearch(int *tab, int size, int find);
bool devideAndConquerSearch(int *tab, int size, int find);

int main()
{
    int size = 8;

    int *tab = new int[size];
    int x = 23;
    int y = 34;

    tab[0] = 23; // staticly given values
    tab[1] = 536;
    tab[2] = 64;
    tab[3] = 1;
    tab[4] = 67;
    tab[5] = 44;
    tab[6] = 87;
    tab[7] = 9;

    randomizeArray(tab, size);

    cout << "---------------- unsorted: ---------------" << endl;
    printArray(tab, size);
    cout << "------------------------------------------" << endl;
    cout << endl;

    sort(tab, size, larger);
    cout << "----------- sorted ascending: ------------" << endl;
    printArray(tab, size);
    cout << "------------------------------------------" << endl;
    cout << endl;

    if (devideAndConquerSearch(tab, size, x))
    {
        cout << "\tvalue " << x << " is present in an array" << endl;
    }
    else
    {
        cout << "\tvalue " << x << " isn't present in an array" << endl;
    }
    if (devideAndConquerSearch(tab, size, y))
    {
        cout << "\tvalue " << y << " is present in an array" << endl;
    }
    else
    {
        cout << "\tvalue " << y << " isn't present in an array" << endl;
    }
    cout << endl;

    sort(tab, size, smaller);
    cout << "---------- sorted descending: ------------" << endl;
    printArray(tab, size);
    cout << "------------------------------------------" << endl;
    cout << endl;

    randomizeArray(tab, size);
    sort(tab, size, larger);
    cout << "----------- sorted ascending: ------------" << endl;
    printArray(tab, size);
    cout << "------------------------------------------" << endl;
    cout << endl;

    if (linearSearch(tab, size, 8))
    {
        cout << "value 8 exist in array" << endl;
    }

    delete[] tab;
    return 0;
}

void randomizeArray(int *tab, int size)
{
    srand(time(NULL)); //generate pseudorandom seed

    for (int i = 0; i < size; i++) // fill the array with random values
    {
        tab[i] = rand() % 100 + 1; // from 1 to 100
    }
}

void printArray(int *tab, int size)
{
    /*  for (int i = 0; i < size; i++)  // printing array indexes
    {
        cout << i << "\t";
    }
    
    cout << endl;
    */
    for (int i = 0; i < size; i++)
    {
        cout.width(5);
        cout << tab[i];
    }
    cout << endl;
}

bool larger(int &l, int &r)
{
    return l > r;
}

bool smaller(int &l, int &r)
{
    return l < r;
}

/* BUBBLE SORT ALGORITHM */
void sort(int *tab, int size, bool (*f)(int &l, int &r))
{
    int Size = size;
    int i;
    int temp;
    bool again;

    do
    {
        again = false;

        for (int i = 0; i < size - 1; i++) // repeat the comparison size-1 times
        {
            if (f(tab[i], tab[i + 1])) // if previous is smaller/larger (depends on f()) than next
            {
                temp = tab[i];       //
                tab[i] = tab[i + 1]; //  switch them
                tab[i + 1] = temp;   //

                again = true; // if the switch was made, repeat
            }
        }
        size--;

    } while (again);
}

/* LINEAR SEARCH ALGORITHM */
bool linearSearch(int *tab, int size, int find)
{
    for (int i = 0; i < size; i++)
    {
        if (tab[i] == find)
        {
            return true;
        }
    }
    return false;
}

/* DEVIDE AND CONQUER SEARCHING ALGORITHM */              // faster than linear search
bool devideAndConquerSearch(int *tab, int size, int find) // this works only while the array is sorted in ascending order
{
    int left = 0;
    int right = size;
    int n;

    // checking if the sougth number is smaller than the smallest value or larger than the largest
    if (find < tab[0] || tab[size - 1] < find)
    {
        return false; // if so, that number does not exist in the array
    }

    while (left < right)
    {
        n = (left + right) / 2;
        if (tab[n] < find)
        {
            left = n + 1;
        }
        else if (tab[n] > find)
        {
            right = n;
        }
        else if (tab[n] == find)
        {
            return true;
        }
    }
    return false;
}
