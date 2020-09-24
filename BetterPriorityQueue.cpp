#include "BetterPriorityQueue.h"

void BetterPriorityQueue::Update() {
int i = 0;
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