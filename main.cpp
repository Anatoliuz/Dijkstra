#include "PriorityQueue.h"
#include "fileWork.h"
#include "Dijkstra.h"
using namespace std;
int main(int argc, char * argv[])
{
    if (argc < 3) {
        cout <<"Error:Not enough args" << endl;
        exit(1);
    }
    else  {
        Dijkstra(argv);
    }

    return 0;
}

