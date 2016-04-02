#ifndef _INTEGER_PRIORITY_QUEUE_HPP_
#define _INTEGER_PRIORITY_QUEUE_HPP_

struct IntegerPriorityQueue;

IntegerPriorityQueue * IntegerPriorityQueueCreate ();

void IntegerPriorityQueueDestroy ( IntegerPriorityQueue * _pPQ );

void IntegerPriorityQueueClear ( IntegerPriorityQueue & _pq );

bool IntegerPriorityQueueIsEmpty ( const IntegerPriorityQueue & _pq );

void IntegerPriorityQueueInsert ( IntegerPriorityQueue & _pq, int _key );

int IntegerPriorityQueueMin ( const IntegerPriorityQueue & _pq );

void IntegerPriorityQueueDeleteMin ( IntegerPriorityQueue & _pq );


#endif //  _INTEGER_PRIORITY_QUEUE_HPP_
