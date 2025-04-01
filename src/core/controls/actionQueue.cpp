#include "actionQueue.h"

void ActionQueue::Flush() {
    for(Action* action : queue) {
        delete action;
    }
    queue.clear();
}

void ActionQueue::AddAction(Action *action) {
    queue.push_back(action);
}