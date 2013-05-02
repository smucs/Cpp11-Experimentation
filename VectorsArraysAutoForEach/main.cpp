
// Examples of 'new' C++ features based on lecture by Bjarne Stroustrap
// Bjarne talk notes: - http://www.swansea.ac.uk/media/C++11%20Swansea.pdf
// Additional materials - http://www.cplusplus.com/articles/EzywvCM9
// Compile with:  g++ -std=c++11 -o test main.cpp 
//

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(int argc, char* argv[])
{
    // Uniform initalisation
    int a[] = {1,2,3};

    vector<int> v {1,2,3};

    vector<string> geekHeros = {"Dahl", "Kernighan", "Mcllroy", "Ritchie", "Stepanov"};

    // Using a strongly typed itterator to move though the list
    // the C++03 way
    for (std::vector<int>::const_iterator ci = v.begin(); ci != v.end(); ++ci)
    {
        cout << *ci << endl;
    }
    
    // Using an auto typed itterator to move though the list
    // the C++11 way
    for (auto ci = v.cbegin(); ci != v.cend(); ++ci)
    {
        // notice the dedicated cbegin() and cend() member functions which return a const_iterator 
        cout << *ci << endl;
    }
 
    // Using the foreach
    // the C++03 way
    for (std::vector<string>::iterator i = geekHeros.begin(); i != geekHeros.end(); ++i)
    {
        cout << *i << endl;
    }
    
    // the C++11 way
    for (string &item: geekHeros)
    {
    // item will become, in order, all the things stored in v
    // notice how we're referencing the item, that allows us to change it
        cout << item << endl;
    }

}
