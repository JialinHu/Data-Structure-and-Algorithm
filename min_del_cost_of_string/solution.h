/*
*   given a string and an array of cost
*   example:
*   string a = "aabb"
*   vector<int> c = {1,3,2,4}
*   make each letter just once appeared
*   a = "aabb" -> "ab"
*   min_cost = 1 + 2 = 3
*   specially, if a = "aaaaa"
*   erase every 'a'
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

std::string g_str;

std::vector<int> g_cost;

int min_del_cost(std::string &S, std::vector<int> &C);

int check_del_min_cost();