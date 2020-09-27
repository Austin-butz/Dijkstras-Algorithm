#include "BetterPriorityQueue.h"

void BetterPriorityQueue::Update(DNode input) {
    size_t i = this->Contains(input.node->key);
    if (i != 999) {
        if (this->c.at(i).pri > input.pri) {
            this->c.erase(this->c.begin() + i);
            this->push(input);
        }
    }
};

int BetterPriorityQueue::Contains(char key) {
    for (int i = 0; i < this->size(); i++) {
        if (c[i].node->key == key) {
            return i;
        }
    }
    return 999;
};