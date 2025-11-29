#include <iostream>
#include <fstream>

using namespace std;

void reset(fstream &file){
    file.clear();
    file.seekg(0, ios::beg);
}

int nbytes(fstream &file){
    reset(file);
    file.seekg(0, ios::end);
    return file.tellg();
}

int nlines(fstream &file){
    reset(file);
    string line;
    int lines = 0;
    
    while (getline(file,line)){
        lines++;
    }

    return lines;
}

int nwords(fstream &file){
    reset(file);
    string line;
    int words = 0;
    while(getline(file,line)){
        bool in_word = false;
        for (char c: line){
            if (isspace(c)){
                in_word = false;
            }
            else{
                if (!in_word){
                    words++;
                    in_word = true;
                }
            }
        }
    }
    return words;
}

int nchars(fstream &file){
    reset(file);
    string line;
    int chars = 0;
    while(getline(file,line)){
        for(char c : line){
            if (!isspace(c)){
                chars++;
            }
        }
    }
    return chars;
}

int main(int argc, char *argv[]){
    if (argc < 2){
        cout<<"Error."<<endl;
        return 1;
    }

    else if (argc == 2)
    {
        string filename = argv[1];
        fstream file(filename, ios::in | ios::out | ios::binary);
        if(!file.is_open()){
            cout<<"Error. Couldn't open the file specified."<<endl;
            return 1;
        }
        cout<<nbytes(file)<<" "<<nlines(file)<<" "<<nwords(file)<<" "<<nchars(file)<<endl;
        file.close();
        return 0;
    }
    if (argc == 3){
        string filename = argv[2];

        fstream file(filename, ios::in | ios::out | ios::binary);
        
        string flag = argv[1];
        
        if(!file.is_open()){
            cout<<"Error. Couldn't open the file specified."<<endl;
            return 1;
        }

        if (flag == "-c") {
            cout << nbytes(file) << endl;
        }
        else if (flag == "-l") {
            cout << nlines(file) << endl;
        }
        else if (flag == "-w") {
            cout << nwords(file) << endl;
        }
        else if (flag == "-m") {
            cout << nchars(file) << endl;
        }

        else {
            cout << "Unknown flag: " << flag << endl;
            return 1;
        }
        file.close();
        return 0;
    }
}