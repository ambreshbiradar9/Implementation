#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    unordered_map<int,int> mm;
    mm[20]=1;
    mm[30]=2;

    for(auto it:mm)
    {
        it.second =40;
        cout<<it.first<<"  "<<it.second<<endl;
        cout<<mm[it.first]<<endl;
    }
   //caution over iterating has maps

    return 0;
}