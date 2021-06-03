#include "solution.h"

int min_del_cost(std::string &S, std::vector<int> &C)
{
    
    int size = S.size();

    if (1 == size)
    {
        return C.at(0);
    }

    int min_cost = 0;

    auto str = S.begin();
    auto str_next = str + 1;

    while (str_next != S.end())
    {
        if (*str != *str_next)
        {
            if (str_next - str > 1)
            {
                //has repeated letter
                int repeated_times = str_next - str;

                int* costs = new int[repeated_times];

                for (int i = 0; i < repeated_times; ++i)
                {
                    costs[i] = C.at(str - S.begin() + i);
                }

                std::sort(costs, costs + repeated_times - 1);

                for(int i = 0; i < repeated_times - 1; ++i)
                {
                    min_cost += costs[i];
                }

                delete []costs;
            }
            str = str_next;
            ++str_next;
        }
        else
        {
            ++str_next;
        }
    }

    if (str_next - str > 1)
    {
        //means there still has 1 letter repeated from str to S.end()
        int repeated_times = str_next - str;

        int* costs = new int[repeated_times];

        for (int i = 0; i < repeated_times; ++i)
        {
            costs[i] = C.at(str - S.begin() + i);
        }

        std::sort(costs, costs + repeated_times - 1);

        for (int i = 0; i < repeated_times - 1; ++i)
        {
            min_cost += costs[i];
        }

        delete[]costs;
    }

    return min_cost;
}

int check_del_min_cost()
{
    std::string S = "ababa";
    std::vector<int> C = { 1, 3, 2, 4, 5 };
    return min_del_cost(S, C);
}

int check_del_min_cost(std::string &s, std::vector<int> &c)
{
    return min_del_cost(s, c);
}
