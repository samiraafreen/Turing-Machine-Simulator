#include <stdlib>

int main(int argc, char* argv[], char* input){
    
    // opening the file
    string line;
    ifstream myfile (argv[1]);
    if (myfile.is_open()){
        while (getline(myfile, line)){

        }

    }
    else cout << "Unable to open file \n" << endl;


 
}