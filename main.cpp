#include <string>
#include <iostream>
#include "GenQueue.h"
#include "Registrar.h"

using namespace std;

int main(int argc, char **agrv) {
    GenQueue<int> *queue = new GenQueue<int>;
    queue->insert(1);
    queue->insert(3);
    queue->insert(5);
    cout << queue->remove() << endl;
    cout << queue->remove() << endl;
    cout << queue->remove() << endl;
    delete queue;

}