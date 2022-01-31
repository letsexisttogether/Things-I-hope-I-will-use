#include <list>
#include <vector>
#include <cmath>

using std::list; using std::vector; using std::find;


template <class T> 
class HashTable
{
private:
    typedef vector<list<T>> VL;

    VL mainListForDiv;
    VL mainListForMulty;
    int M;
   
    auto findValue(T value, bool  isDiv = true)
    {
        int key = 0;
        isDiv ? key = value % M : key = M * fmod(value * 0.6180339, 1);
        return isDiv ? find(mainListForDiv[key].begin(), mainListForDiv[key].end(), value)
            : find(mainListForMulty[key].begin(), mainListForMulty[key].end(), value);
    }

public:
    HashTable(int m) : M(m) 
    {
        mainListForDiv.resize(M);
        mainListForMulty.resize(M);
    }
    
    void push(T value, bool isDiv = true)
    {
        // If division method is selected we use k mod M
        // else for multyplication method we use M * k * C mod 1
        isDiv ? mainListForDiv[value % M].push_back(value) :
                mainListForMulty[M * fmod(value * 0.6180339, 1)].push_back(value);
    }

    void pop(T value, bool isDiv)
    {
        int key = 0;
        isDiv ? key = value % M : key = M * fmod(value * 0.6180339, 1);
        isDiv ? mainListForDiv[key].erase(findValue(value, isDiv))
            : mainListForMulty[key].erase(findValue(value, isDiv));
    }
    // Checks if the value is in the table
    bool exits(T value, bool isDiv)
    {
        return isDiv ? findValue(value, true) != mainListForDiv.end()
            : findValue(value, false) != mainListForMulty.end();
    }

    // Give an opportunity to print elements of current hash table
    VL GetDivVec() { return mainListForDiv; }
    VL GetMultyVec() { return mainListForMulty; }

};
