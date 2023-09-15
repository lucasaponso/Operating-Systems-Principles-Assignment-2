#include "../includes/Loader.h"
#include "../includes/pcb.h"
#include "../includes/fifo.h"
#include <iostream>
#include <fstream>
#include <queue>

using std::string;
using std::endl;
using std::ifstream;
using std::queue;
using std::cerr;
using std::cout;

int main(int argc, char* argv[]) 
{
    if (argc < 2 || argc > 3) 
    {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream inputFile(filename);

    if (!inputFile)
    {
        cerr << "Error: Unable to open file " << filename << endl;
        return 1;
    }

    queue<pcb> processes = Loader::readFile(filename);
    run(processes);

    return 0;
}
