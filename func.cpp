#include "findAndReplace.h"

void checkStartArgs(int argc, char *args[]){

    if ( argc != 4 ) 
        throw invalid_argument("Number of arguments invalid!");
    
    // Calls function stat to see if file exists
    if ( !exists(args[1]) ) 
        throw invalid_argument("File not found!");

    string fileName = args[1];
    if ( fileName.substr(fileName.find_last_of(".")) != ".txt" )
        throw invalid_argument("File extension not supported!");

    if ( string(args[2]) == string(args[3]) )
        throw invalid_argument("Text to delete and to add are the same!");
}