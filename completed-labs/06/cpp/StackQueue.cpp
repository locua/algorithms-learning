#include <iostream>

#include "Stack.hpp"
#include "Queue.hpp"

using namespace std;

static Stack *s;
static Queue *q;

void prepare() {
  q = new Queue();
  s = new Stack();

  q -> enqueue(3);
  q -> enqueue(5);
  q -> enqueue(0);
  q -> enqueue(4);
  q -> enqueue(2);
  q -> enqueue(0);
  
  s -> push(0);
  s -> push(0);
  s -> push(1);
  s -> push(0);
  s -> push(5);
  s -> push(3);

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
