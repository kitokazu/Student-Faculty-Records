#include <string>
#include <iostream>
#include "GenQueue.h"
#include "List.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char **agrv) {
    GenQueue<int> *queue = new GenQueue<int>;
    queue->insert(1);
    cout << queue->remove() << endl;
    delete queue;

}