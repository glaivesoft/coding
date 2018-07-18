
// g++ -std=c++11 -o map map.cpp

/*
 | map             | unordered_map
 ---------------------------------------------------------
 Ordering        | increasing  order   | no ordering
 | (by default)        |
 
 Implementation  | Self balancing BST  | Hash Table
 | like Red-Black Tree |
 
 search time     | log(n)              | O(1) -> Average
 |                     | O(n) -> Worst Case
 
 Insertion time  | log(n) + Rebalance  | Same as search
 
 Deletion time   | log(n) + Rebalance  | Same as search
 */


// GNU
// #include <bits/stdc++.h>

// LLVM
#include <unordered_map>
#include <map>
#include <iostream>

int main()
{
    // Unordered map
    // std::unordered_map<int, int> order;
    std::map<int, int> order;
 
    // Mapping values to keys
    order[5] = 10;
    order[3] = 5;
    order[20] = 100;
    order[1] = 1;
 
    // Iterating the map and printing unordered values
    for (auto i = order.begin(); i != order.end(); i++) {
        std::cout << i->first << " : " << i->second << '\n';
    }
    
    /*
     map:
     1 : 1
     3 : 5
     5 : 10
     20 : 100
     
     unordered_map:
     1 : 1
     3 : 5
     20 : 100
     5 : 10
     */
}

