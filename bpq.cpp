#include "bpq.h"

void BetterPriorityQueue::update() {
int i = 0;
};

bool BetterPriorityQueue::contains(GraphNode *input) {
    for (int i = 0; i < this->size(); i++) {
        if (c[i].node->key == input->key) {
            return true;
        }
    }
    return false;
};