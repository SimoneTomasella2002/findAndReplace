#ifndef FINDANDREPLACE_H
#define FINDANDREPLACE_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <filesystem>
#include <sys/stat.h>

using namespace std;
using namespace filesystem;

// Used to check if user wrote arguments correctly
void checkStartArgs(int, char*[]);

#endif
