#include "BetterPriorityQueue.h"

void BetterPriorityQueue::Update() {
    while (!this->empty()) {
        DNode temp = this->top();
        this->pop();
        this->push(temp);
    }
};

int BetterPriorityQueue::Contains(char key) {
    for (int i = 0; i < this->size(); i++) {
        if (c[i].node->key == key) {
            return i;
        }
    }
    cout << "No node with given key in queue" << endl;
    return NULL;
};