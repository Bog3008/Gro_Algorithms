#include <iostream>

using namespace std;

int main()
{
    int length = 29;                            // длинна участка, требующая разбиения 
    int tc = 4;                                // колличество участков
    size_t const portion = length/tc;
    size_t rem = length % tc;
    for(int i = 0; i < tc; i++){
        cout << portion + (i < rem)<< " ";
    }
}

/*
тк остаток от деления всегда меньше числа, на которое мы делим => достаточно прибавлять по 1 к каждому подучастку,
пока остаток от деления не израсходутся на остальные части
*/
