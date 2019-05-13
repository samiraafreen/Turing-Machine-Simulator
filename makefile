all:tm.cpp
    g++ -g -Wall -o tm tm.cpp

clean:
     $(RM) tm
