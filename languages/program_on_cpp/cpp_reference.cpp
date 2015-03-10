#include <iostream>

using namespace std;

int main()  {  
    int i = 10;   // A simple integer variable  
    int &j = i;   // A Reference to the variable i  
    j++;   // Incrementing j will increment both i and j.  
    // check by printing values of i and j  
    cout<<  i  <<  j  <<endl; // should print 11 11  
    // Now try to print the address of both variables i and j  
    cout<<  &i  <<  &j  <<endl;  
    // surprisingly both print the same address and make us feel that they are  
    // alias to the same memory location.  
    // In example below we will see what is the reality  

    int m = 5;
    int n = 6;
    int &k = m; 
    k = n; // k和i的值都变成了6，而不是k指向了j。
    cout<<  m  <<  n  <<endl; // should print 6 6  
    k++;
    cout<<  m  <<  n  <<endl; // should print 7 6  


    return 0;  
}

