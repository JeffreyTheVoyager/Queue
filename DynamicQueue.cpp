//
// Created by jabraham4849 on 2/24/2023.
//

#include "DynamicQueue.h"

DynamicQueue::DynamicQueue() {
    this->front = nullptr;
    this->rear = nullptr;
}


void DynamicQueue::insert(char x) {
    std::cout << "Read key " << x << ". ";

    DynamicNode* newQueue = new DynamicNode();
    newQueue->info = x;
    newQueue->next = nullptr;

    // Check if Queue is empty
    if(this->front == nullptr){
        // Making rear and front pointer
        this->front = this->rear = newQueue;
        this->QUEUEMAXSIZE--;

        std::cout << "Inserting " << x << " in rear. ";
        this->print();
        return;
    }

    DynamicNode* p = this->front;

    int pos = 0;
    while(p != nullptr){
        if(p->info == x){

            // Check rear duplicate
            // Return since duplicate is already in rear
            if(this->rear->info == x){
                std::cout << "Key " << x << " is already rear. ";
                this->print();
                return;
            }

            // Check front duplicate
            // Remove front to rear
           if(this->front->info == x){
               //Shift front pointer
               this->front = this->front->next;
               this->rear->next = newQueue;
               this->rear = newQueue;

               std::cout << "Key already in queue, moving " << x << " to rear. ";
               this->print();
               return;
           }

            // Check Middle duplicate
           DynamicNode* tmp = this->front;
           for(int i = 2; i < pos; i++){
               while(tmp->next->next != nullptr){
                   tmp = tmp->next;
               }
           }

           tmp->next = tmp->next->next;
           this->rear->next = newQueue;
           this->rear = newQueue;

           std::cout << "Key already in queue, moving " << x << " to rear. ";
           this->print();
           return;
        }
        pos++;
        p= p->next;
    }

    // Check if Queue Max size is reach
    // Removing the front
    if(this->QUEUEMAXSIZE <= 0){
        std::cout << " Queue is full, removing front. ";
        this->front = this->front->next;
        QUEUEMAXSIZE++;
    }

    // Insert element to rear
    this->rear->next = newQueue;
    this->rear = newQueue;
    this->QUEUEMAXSIZE--;

    std::cout << "Inserting " << x << " in rear. ";
    this->print();
}



void DynamicQueue::print() {
    DynamicNode* p = this->front;
    std::cout << "Queue: ";
    while(p != nullptr){
        std::cout << p->info << "->";
        p = p->next;
    }
    std::cout << '\n';
}