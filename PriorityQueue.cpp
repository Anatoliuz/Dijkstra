//minQueue
#include "PriorityQueue.h"

void PriorityQueue::up(int i) {
        while (i != 0 && a[i].length < a[(i - 1) / 2].length) {
            std::swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
void PriorityQueue::down(int i) {
        while (i < size / 2) {
            int maxI = 2 * i + 1;
            if (2 * i + 2 < size && a[2 * i + 2].length < a[2 * i + 1].length)
                maxI = 2 * i + 2;
            if (a[i].length <= a[maxI].length)
                return;
            std::swap(a[i], a[maxI]);
            i = maxI;
        }
    }
    
   PriorityQueue::PriorityQueue() {
             size = 0;
    }
    
    void PriorityQueue::enqueue(double length, double vertex) {
        assert(size + 1 < MAX_SIZE);
        a[size++] = Elem(length, vertex);
        up(size - 1);
    }
    
    void PriorityQueue::dequeue() {
        assert(size > 0);
        std::swap(a[0], a[--size]);
        down(0);
    }
    int PriorityQueue::top(char c){
        int tempLength = a[0].length;
        int tempVertex  = a[0].vertex;
        if(c == 'l') return tempLength;
        if(c == 'v') return tempVertex;
        else return - 10000;
    }
    bool PriorityQueue::isEmpty() {
        return size == 0;
    }
    