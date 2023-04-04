//
// Created by jabraham4849 on 2/24/2023.
//

#ifndef QUEUE_DYNAMICQUEUE_H
#define QUEUE_DYNAMICQUEUE_H

#include <iostream>

struct DynamicNode{
    char info;
    DynamicNode* next;
};

class DynamicQueue {
    int QUEUEMAXSIZE = 4;
    DynamicNode* front;
    DynamicNode *rear;

public:
    DynamicQueue();
    void insert(char x);
    void print();
};


#endif //QUEUE_DYNAMICQUEUE_H
