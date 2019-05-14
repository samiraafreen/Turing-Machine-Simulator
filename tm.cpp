#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

/* struct to store transition rules*/
struct transition{
    int beginState;
    char read;
    char write;
    char move;
    int endState;
};

int main(int argc, char* argv[]){
    // number of states
    int numStates;
    // vector of final states
    vector<int>finalStates;
    /* vector of alphabet characters*/
    vector<char>alphabet;
    /* vector of transition rules*/
    vector<transition>trans;
    /* number of transition rules*/
    int transCount = 0;
    int count = 0;
    string line;
    /* opening file */
    ifstream myfile (argv[1]);
    if (myfile.is_open()){
        while (getline(myfile, line)){
            // first line = number of states
            if (count == 0){
                numStates = line[0]-'0';
            }
            // second line = alphabet
            else if (count == 1){
                for(unsigned int i=0;i<line.length();i++){
                    alphabet.push_back(line[i]);
                }
            }
            // third line = list of final states
            else if (count == 2){
                for(unsigned int i=0;i<line.length();i++){
                    if(isdigit(line[i])){
                        int state = line[i]-'0';
                        finalStates.push_back(state);
                    }
                }
            }
            // line 4 = reading transition rules
            else if (count >= 3){
                trans.push_back(transition());
                /* for each transition line, the initial state will always be at index 0, read character at index 2, etc... */
                trans[transCount].beginState = line[0]-'0';
                trans[transCount].read = line[2];
                trans[transCount].write = line[4];
                trans[transCount].move = line[6];
                trans[transCount].endState = line[8]-'0';
                transCount++;
            }
            /* increment count to keep track of what line we are on */
            count++;
        }
        myfile.close();
    }
    else cout << "Unable to open file \n" << endl;
    numStates++;

    /* set up tape with spaces at either end */
    std::string space = " ";
    std::string str;
    if(argc==3){
        str = space.append(argv[2]).append(space);
    }
    else{
        str = space.append(space);
    }
    /* tape */
    std::vector<char> input(str.begin(), str.end());
    /* current state */
    int state = 0;
    /* current tape head position*/
    unsigned int head = 1;
    /* while state is not reject state*/
    while(state!=-1){   
        /* checking if state is accept state */ 
        if(find(finalStates.begin(), finalStates.end(), state) != finalStates.end()) {
            cout << "Input accepted." << endl;
            exit(0);
        } 
        else {
            /* traversing through transition list to find transition that matches */
            for(unsigned int i=0;i<trans.size();i++){
                if(trans[i].beginState==state && trans[i].read==input[head]){
                    /* write character */
                    input[head] = trans[i].write;

                    /* move tape head */
                    if(trans[i].move=='>'){
                        head++;
                        if(head>input.size()){
                            input.push_back(' ');
                        }
                    }
                    if(trans[i].move=='<'){
                        head--;
                        if(head<0){
                            cout << "Tape head has moved past the left edge." << endl;
                            exit(0);
                        }
                    }

                    /* change state */
                    state = trans[i].endState;
                    break;
                }
                /* if no matching transition is found, change state to reject */
                else if(i==trans.size()-1){
                    state = -1;
                }
            }
        }
    }
    cout << "Input rejected." << endl;
 
}
