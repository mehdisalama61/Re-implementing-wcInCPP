#include <iostream>
#include <fstream>

using namespace std;

int nbytes(fstream &file){

    file.seekg(0, ios::end);
    return file.tellg();
}

int nlines(fstream &file){
    string line;
    int lines = 0;
    
    while (getline(file,line)){
        lines++;
    }
    return lines;
}

int nwords(fstream &file){
    string line;
    int words = 0;
    while(getline(file,line)){
        int i = 1;
        while(line[i]){
            if ((isspace(line[i])) && !(isspace(i-1)))
            {
                words++;
            }
            i++;
        }
    }
    return words;
}



int main(int argc, char *argv[]){
    
    
    return 0;
}