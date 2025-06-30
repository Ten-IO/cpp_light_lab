# Queue
> **Queue** : linear data structure _First In, First Out_.

\+ Keynote : First added will be removed first.

Usage:
- CPU Schedule : processes queue
- Printer : print jobs managed in queue
- Breadth-First Search (BFS) : graph bridge algorithm - access pull out (dequeue) or access put in (enqueue)
- Network traffic : buffers IO systems
- Analogy : model such as banks, supermarkets.

\+ Keyword :
---
- enqueue : add element to queue
- dequeue : remove elemet from queue
- front/peek :  access front element without remove
- rear : access last element without remove
- empty : `front=-1`, `rear=-1`

\+ Implementation
---
- as `array`
- as `linked list`

## 01 - Queue as Array
- Relies on `fixed-size Array`
- allocate only first time

\+ Limitation
---
- usually fixed max size
- not space-efficient : does not reuse space, enqueues can get overflow.

### 101 - Circular queue
\+ Keynote : 
- Modulo arithmetic - `modulo % size` to wrap in domain, enqueue/dequeue with modulo
- Full condition - `check (rear+1) % size with front` when zero based indexing
- Empty condition - `front == -1`
- Start front -> rear -> go back front (bound by modulo)

## 02 - Queue as Linked List
- Relies on `Linked List`
- allocate memory for new elements
- <u>Choice 1</u> : `enqueue` at *List tail*, `dequeue` at *List head*
- <u>Choice 2</u> : `enqueue` at *List head*, `dequeue` at *List tail*

\+ Limitation
---
- performance lies on Linked List