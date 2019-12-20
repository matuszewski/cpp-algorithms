
void inkrementujTablice(float **t, int, int);

void inkrementujTablice(float **t, int r1, int r2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < r2; j++)
        {
            t[i][j]++;
        }
    }
}

void transponujTablice(float **wejsciowa, float **wyjsciowa, int r1, int r2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < r2; j++)
        {
            wyjsciowa[j][i] = wejsciowa[i][j];
        }
    }
}
