

https://en.cppreference.com/w/cpp/utility/functional/function

class function<R(Args...)>;

R: result_type
Args: Arhuments

//========================================<Source Code(S)>========================================

#include <bits/stdc++.h>
//#include <functional>
//#include <iostream>
using namespace std;
 
void print_num(int i)
{
    std::cout << i << '\n';
}
int square_num(int i)
{
    return (i*i);
}
 
int main()
{
    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);
    
    // Return from function
    std::function<int(int)> sqnum = square_num;
    int r = sqnum(3);
    std::cout << "Shreyas Res Square: "<< r << '\n';
    
    return 0;
}

/*
Try on: https://coliru.stacked-crooked.com/

Code: https://coliru.stacked-crooked.com/a/ef972ae8416605f3


Testing:
#> g++ -std=c++17 -O2 -Wall -pedantic -pthread main.cpp && ./a.out

Output:
-9
Shreyas Res Square: 9

*/

//========================================<Source Code(E)>========================================

