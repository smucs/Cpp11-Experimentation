//playing with C++ for input and output (text files)
//
//
#include <iostream>
#include <fstream>

#include <string>

using std::ofstream;
using std::ifstream;
using std::endl;
using std::string;
using std::cout;
using std::getline;

int main()
{
    string message = "bob";

    ofstream myfile;

    myfile.open("example.txt");

    if(myfile.is_open())
    {
        myfile << "Writing this to a file." << endl;
        myfile << message << endl;
 
        myfile.close();
    }

    ifstream anotherFile;
    message.erase(message.begin(),message.end());

    anotherFile.open("example.txt");

//   anotherFile >> message;
//   cout << message;

//   anotherFile >> message;
//   cout  << message;

    if(anotherFile.is_open())
    {
        while(anotherFile.good())
        {
            getline(anotherFile,message);
            cout << message << endl;
        }
        anotherFile.close();
    }
    else
    {
        cout << "Could not open file" << endl;
    }

   return 0;
}


