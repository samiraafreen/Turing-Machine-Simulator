#include <stdlib>
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char* argv[], char* input){
    // number of states
    int numStates;
    // number of final states
    int[] finalStates;
    int count;
    // opening the file
    string line;
    ifstream myfile (argv[1]);
    if (myfile.is_open()){
        while (getline(myfile, line)){
            std::string numStates = line[0];
            numStates = std::stoi(numStates);
            finalStates = new int[numStates];
            count++;
            if (count == 2) {
                
            }
        }

    }
    else cout << "Unable to open file \n" << endl;


 
}
