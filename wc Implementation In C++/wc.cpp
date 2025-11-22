#include <iostream>
#include <fstream>

using namespace std;

int main(){
    fstream file;
    file.open("text.txt", ios::in | ios::out | ios :: binary);
    if (file.is_open())
    {
        /*
        
        string buffer;
        do
        {
            
            file >> buffer;
            cout << buffer<< endl;
            cout<<file.tellg()<<endl;
        } while (!file.eof());
        
        */
        file.seekg(0, ios::end);
        cout<<file.tellg()<<endl;

    }
    file.close();
    return 0;
}