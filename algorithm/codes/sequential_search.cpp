/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void seqsearch(int n,

               const int S[],

               int x,

               int &location)

{

    location = 1;

    while (location <= n && S[location] != x)

        location++;

    if (location > n)

        location = 0;
}

int main()
{
    int S[5] = {1, 2, 3, 4, 5};
    int location;
    seqsearch(5, S, 6, location);
    cout << location;
    return 0;
}
