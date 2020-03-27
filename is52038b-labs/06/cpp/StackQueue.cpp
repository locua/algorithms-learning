#include <iostream>

#include "Stack.hpp"
#include "Queue.hpp"

using namespace std;

static Stack *s;
static Queue *q;

void prepare() {
}

int main(int argc, char *argv[]) {
  prepare();
  cout << q->dequeue();
  cout << s->pop();
  cout << s->pop();
  cout << q->dequeue();
  s->pop();
  q->dequeue();
  cout << s->pop();
  cout << q->dequeue();
  cout << s->pop();
  cout << q->dequeue() << endl;
  s->pop();
  q->dequeue();
}
