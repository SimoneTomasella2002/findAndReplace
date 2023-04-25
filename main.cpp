#include "findAndReplace.h"

int main(int argc, char *argv[]){

    // Just for testing, don't know if will be left in final program
    auto start = std::chrono::steady_clock::now();

    std::ios::sync_with_stdio(false); // Faster cout


    try { checkStartArgs(argc, argv); }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }


    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Program terminated with success!\nTime taken by program is: " << std::chrono::duration<double, std::milli> (diff).count() << " ms\n\n";

    return 0;
}
