#include "findAndReplace.h"

// argv[1] = original file name
// argv[2] = text to delete
// argv[3] = text to add

int main(int argc, char *argv[]){

    // Just for testing, don't know if will be left in final program
    auto start = std::chrono::steady_clock::now();

    std::ios::sync_with_stdio(false); // Faster cout


    try { checkStartArgs(argc, argv); }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    
    // Saving arguments in strings (better readability, probably gonna be eliminated for efficiency)
    string nameOfFile = string(argv[1]);
    string textToDelete = string(argv[2]);
    string textToAdd = string(argv[3]);
    

    // Creating aux variables for future operations
    string newFileName = (nameOfFile+"_new");
    int delTextDim = string(textToDelete).length();


    // Checking if file already exists
    if ( exists(newFileName) )
        remove(newFileName);


    // Opening file
    fstream oldFile;
    fstream newFile;
    oldFile.open(nameOfFile, ios::out | ios::in);
    newFile.open(newFileName, ios::app);


    // Reading line by line
    string fileLine;
    while(getline(oldFile, fileLine)){
    	
        // Code to check every line, find substring = textToDelete
        // Preparing substitution
        int currentPos = 0;
        while((currentPos = fileLine.find(textToDelete)) != -1){            
            fileLine.erase(currentPos, delTextDim);
            fileLine.insert(currentPos, textToAdd);
        }
        
        // Writing new lines to the file
        newFile << fileLine;
    }
	

	// Closing file
	oldFile.close();
    remove(nameOfFile);
    
    newFile.close();
    rename(newFileName, nameOfFile);


    // Finishing timer stuff
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Program terminated with success!\nTime taken by program is: " << std::chrono::duration<double, std::milli> (diff).count() << " ms\n\n";


    return 0;
}
