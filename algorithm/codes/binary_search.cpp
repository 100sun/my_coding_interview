/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void binsearch ( int n,

const int S[ ],

int x,

int & location )

{

int low,high,mid;

location = 0, high=n, low=1;

while (low<=high && location==0){
    cout << low << " "<< high << " \n";
    mid = (low+high)/2;
    if(x==S[mid]) location = mid;
    else if(x<S[mid]) high=mid-1;
    else low=mid+1;
}
}

int main()
{
int S[5]={1,2,3,4,5};
int location;
binsearch(5,S,3, location);
cout << location;
    return 0;
}

