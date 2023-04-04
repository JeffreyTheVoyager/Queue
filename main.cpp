#include <iostream>
#include "DynamicQueue.h"

int main() {
    DynamicQueue Queue;
    Queue.insert('a');
    Queue.insert('a');
    Queue.insert('b');
    Queue.insert('b');
    Queue.insert('e');
    Queue.insert('e');
    Queue.insert('f');
    Queue.insert('f');
    Queue.insert('a');
    Queue.insert('g');
    return 0;
}
