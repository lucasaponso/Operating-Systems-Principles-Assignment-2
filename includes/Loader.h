#ifndef FILE_READER_H
#define FILE_READER_H

#include "pcb.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
using std::queue;
using std::vector;
using std::map;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;
using std::stoi;

class Loader 
{
    public:
        static queue<pcb> readFile(const string &filename);
};

#endif // FILE_READER_H
