#include "BetterPriorityQueue.h"
//#define INF = 999

void BetterPriorityQueue::Update(DNode input) {
    size_t i = this->Contains(input.node->key);
    if (i != 999) {
        if (this->c.at(i).pri > input.pri) {
            //this->c.at(i).pri = input.pri;
            this->c.erase(this->c.begin() + i);
            this->push(input);
        }
    }
    /*for (size_t b = 0; b < this->c.size(); b++) {
        DNode temp = this->top();
        this->pop(); this->c.
        this->push(temp);
    }*/
};

int BetterPriorityQueue::Contains(char key) {
    for (int i = 0; i < this->size(); i++) {
        if (c[i].node->key == key) {
            return i;
        }
    }
    //cout << "No node with given key in queue" << endl;
    return 999;
};