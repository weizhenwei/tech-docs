#include <iostream>

using namespace std;

class Test  {  
    int &i;   // int *const i;  
    int &j;   // int *const j;  
    int &k;   // int *const k;   
};  
int main()  
{      
    // This will print 24 on x86_64, i.e. size of 3 pointers  
    cout<<  "size of class Test = "  <<   sizeof(class Test)  <<endl;  
    return 0;  
}

