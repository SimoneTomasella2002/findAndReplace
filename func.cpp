#include "findAndReplace.h"

void checkStartArgs(int argc, char *args[]){

    // Checks if arg. number is valid
    if(argc != 4) 
        throw std::invalid_argument("Number of arguments invalid!");
    
    // Calls function stat to see if file exists
    struct stat sb;
    if(stat(args[1], &sb) != 0) 
        throw std::invalid_argument("File not found!");

    // Checks if file extension is correct (only .txt files are suppported for now)
    std::string fileName = args[1];
    if(fileName.substr(fileName.find_last_of(".")) != ".txt")
        throw std::invalid_argument("File extension not supported!");
}