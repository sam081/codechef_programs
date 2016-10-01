#include <iostream>
using namespace std;
int main()
{
    int a,result;
    cout<<"1\n";
    cout<<"3 1 1 3\n";
    cout<<"3 2 2 4\n";
    cin>>result;
    switch(result)
    {
    case 0:
        a=5;
        break;
    case 1:
        a=3;
        break;
    case 2:
        a=1;
        break;
    case -1:
        a=4;
        break;
    case -2:
        a=2;
        break;
    }
    cout<<"2\n";
    cout<<a;
    return 0;
}
