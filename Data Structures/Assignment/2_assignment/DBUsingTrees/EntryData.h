#ifndef ENTRYDATA_h
#define ENTRYDATA_h
using namespace std;
#include <string>
class EntryData
{
public:
    int ID;
    string name;
    int age;
    EntryData();
    EntryData(int id, string nam, int ag);
};

#endif