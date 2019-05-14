#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct transition{
    int beginState;
    char read;
    char write;
    char move;
    int endState;
};

int main(int argc, char* argv[]){
    if(argc<3){
        cout << "Invalid input"<<endl;
        exit(0);
    }
    // number of states
    int numStates;
    // number of final states
    vector<int>finalStates;
    vector<char>alphabet;
    vector<transition>trans;
    int transCount = 0;
    // opening the file
    int count = 0;
    string line;
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
            // line 4 = transitions start
            else if (count >= 3){
                trans.push_back(transition());
                trans[transCount].beginState = line[0]-'0';
                trans[transCount].read = line[2];
                trans[transCount].write = line[4];
                trans[transCount].move = line[6];
                trans[transCount].endState = line[8]-'0';
                transCount++;
            }
            count++;
        }
        myfile.close();
    }
    else cout << "Unable to open file \n" << endl;

    cout << "numStates: " << numStates << endl;
    for(unsigned int i = 0;i<finalStates.size();i++){
        std::cout << "finalstates: "<< finalStates[i] << endl;  
    }
    for(unsigned int i = 0;i<alphabet.size();i++){
        std::cout << "alphabet: "<< alphabet[i] << endl;  
    }
    for(unsigned int i = 0;i<trans.size();i++){
        cout << trans[i].beginState << " " << trans[i].read << " " << trans[i].write << " " <<
        trans[i].move << " " << trans[i].endState << endl;
    }

    std::string space = " ";
    std::string str = space.append(argv[2]).append(space);
    std::vector<char> input(str.begin(), str.end());
    int state = 0;
    unsigned int head = 1;
    while(state!=-1){
        for(unsigned int i = 0;i<input.size();i++){
            if(i==head){
                cout << "q"<<state;
            }
            cout << input[i];
        }    
        cout << '\n';
        if(find(finalStates.begin(), finalStates.end(), state) != finalStates.end()) {
            cout << "Input accepted." << endl;
            exit(0);
        } 
        else {
            for(unsigned int i=0;i<trans.size();i++){
                if(trans[i].beginState==state && trans[i].read==input[head]){
                    cout <<"dick";
                    input[head] = trans[i].write;

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

                    state = trans[i].endState;
                    break;
                }
                else if(i==trans.size()-1){
                    state = -1;
                }
            }
        }
    }
    cout << "Input rejected." << endl;
 
}
