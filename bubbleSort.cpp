#include <iostream>

using namespace std;

bool bigger(int &l, int &r)
{
    return l > r;
}

bool smaller(int &l, int &r)
{
    return l < r;
}

void sort(int *tab, int size, bool (*f)(int &l, int &r));

int main()
{

    int size = 8; // declare and define a static array
    int tab[8] = {23, 536, 64, 1, 67, 44, 87, 9};

    sort(tab, size, bigger);

    return 0;
}
/* BUBBLE SORT ALGORITHM */
void sort(int *tab, int size, bool (*f)(int &l, int &r))
{
    int Size = size;
    int i;
    int temp;
    bool b;

    do
    {
        b = false;

        for (int i = 0; i < size - 1; i++)
        {
            if (f(tab[i], tab[i + 1])) // if previous is smaller/larger (depends on f()) than the next
            {
                temp = tab[i]; // switch them
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;

                b = true;
            }
        }
        size--;

    } while (b);

    // print array
    for (int j = 0; j < 8; j++)
    {
        cout << tab[j] << endl;
    }
}
