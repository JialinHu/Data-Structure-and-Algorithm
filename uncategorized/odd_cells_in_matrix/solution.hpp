#include<vector>

int odd_cells(int m, int n, std::vector<std::vector<int>> &indicies)
{
    int result = 0;

    /* init row recorder */
    int *rows = new int[m];
    for(int i = 0; i < m; ++i)
    {
        rows[i] = 0;
    }

    /* init col recorder */
    int *cols = new int[n];
    for(int i = 0; i < n; ++i)
    {
        cols[i] = 0;
    }

    /* recorders recording how many times a row or col is +1, then mod by 2*/
    for(auto it = indicies.begin(); it != indicies.end(); ++it)
    {
        rows[it->at(0)] = (rows[it->at(0)] + 1) % 2;
        cols[it->at(1)] = (cols[it->at(1)] + 1) % 2;
    }

    /* calculate all*/
    int iRowOdd = 0;
    int iColOdd = 0;

    for(int i = 0; i < m; ++i)
    {
        if(rows[i] == 1)
        {
            iRowOdd += 1;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        if(cols[i] == 1)
        {
            iColOdd += 1;
        }
    }

    /* calculate result */
    result = (iRowOdd * n + iColOdd * m) - 2 * (iRowOdd * iColOdd);

    return result;
}