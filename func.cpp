#include "findAndReplace.h"

void checkStartArgs(int argc, char *args[]){

    // Checks if arg. number is valid
    if(argc != 4) 
        throw std::invalid_argument("Number of arguments invalid!");
    
    // Calls function stat to see if file exists
    struct stat sb;
    if(stat(args[1], &sb) != 0) 
        throw std::invalid_argument("File not found!");
}