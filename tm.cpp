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
            int state = 0;
            // first line = number of states
            if (count == 0){
                std::string numStates = line;
                numStates = std::stoi(numStates);
                finalStates = new int[numStates];
            }
            // second line = alphabet
            else if (count == 1){
                char[] alphabet = line;
            }
            // third line = list of final states
            else if (count == 2){
                char[] charfinalStates = line;
                for (int i = 0; i < numStates; i++){
                    if (isdigit(charfinalStates[i])){
                        // this could be wrong
                        int finalState = (int)charfinalState[i];
                        finalStates[i] = finalState;
                    }
                } 
            }
            // line 4 = transitions start
            else if (count == 3){
                char[] transition = line;
            }
            count++;

        }
        myfile.close();

        // read the input
    }
    else cout << "Unable to open file \n" << endl;


 
}
