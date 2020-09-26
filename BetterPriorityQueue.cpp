#include "BetterPriorityQueue.h"

void BetterPriorityQueue::Update() {
    int i = 0;
    while (!this->empty()) {
        DNode temp = this->top();
        this->pop();
        if (temp.visited == true) {
            temp.pri = i;
            this->push(temp);
        }
        else this->push(temp);
        i += 1;
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