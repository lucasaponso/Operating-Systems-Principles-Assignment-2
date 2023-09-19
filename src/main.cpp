#include "../includes/Loader.h"
#include "../includes/pcb.h"
#include "../includes/algorithms.h"

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
        cerr << "Usage: " << argv[0] << " <algorithm> <filename> [timeQuantum]" << endl;
        cerr << "Valid algorithms: fifo, sjf, rr" << endl;
        return 1;
    }

    string algorithm = argv[0];
    string filename = argv[1];
    ifstream inputFile(filename);

    if (!inputFile)
    {
        cerr << "Error: Unable to open file " << filename << endl;
        return 1;
    }

    if (algorithm == "./fifo" && argc == 2) 
    {
        queue<pcb> processes = Loader::readFile(filename);
        run_fifo(processes);
    } 
    else if (algorithm == "./sjf" && argc == 2) 
    {
        queue<pcb> processes = Loader::readFile(filename);
        run_sjf(processes);
    } 
    else if (algorithm == "./rr" && argc == 3) 
    {
        int timeQuantum = std::stoi(argv[2]);
        queue<pcb> processes = Loader::readFile(filename);
        run_rr(processes, timeQuantum);
    } 
    else 
    {
        cerr << "Invalid or missing arguments." << endl;
        return 1;
    }

    return 0;
}
