#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream file;
    file.open("text.txt", ios::in | ios::out | ios :: binary);
    if (file.is_open())
    {
        cout<<"hello"<<endl;
    }
    file.close();
    return 0;
}