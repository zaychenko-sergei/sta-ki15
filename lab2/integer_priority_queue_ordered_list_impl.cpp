#include "integer_priority_queue.hpp"
#include "integer_list.hpp"

#include <cassert>


struct IntegerPriorityQueue
{
	IntegerList m_orderedItems;
};


IntegerPriorityQueue * IntegerPriorityQueueCreate ()
{
	IntegerPriorityQueue * pPQ = new IntegerPriorityQueue;
	IntegerListInit( pPQ->m_orderedItems );
	return pPQ;
}


void IntegerPriorityQueueDestroy ( IntegerPriorityQueue * _pPQ )
{
	IntegerListDestroy( _pPQ->m_orderedItems );
	delete _pPQ;
}


void IntegerPriorityQueueClear ( IntegerPriorityQueue & _pq )
{
	IntegerListClear( _pq.m_orderedItems );
}


bool IntegerPriorityQueueIsEmpty ( const IntegerPriorityQueue & _pq )
{
	return IntegerListIsEmpty( _pq.m_orderedItems );
}


void IntegerPriorityQueueInsert ( IntegerPriorityQueue & _pq, int _key )
{
	IntegerList::Node * pCurrent = _pq.m_orderedItems.m_pFirst;
	while ( pCurrent )
	{
		if ( _key < pCurrent->m_value )
		{
			IntegerListInsertBefore( _pq.m_orderedItems, pCurrent, _key );
			return;
		}

		pCurrent = pCurrent->m_pNext;
	}

	IntegerListPushBack( _pq.m_orderedItems, _key );
}


int IntegerPriorityQueueMin ( const IntegerPriorityQueue & _pq )
{
	assert( ! IntegerPriorityQueueIsEmpty( _pq ) );
	return _pq.m_orderedItems.m_pFirst->m_value;
}


void IntegerPriorityQueueDeleteMin ( IntegerPriorityQueue & _pq )
{
	assert( !IntegerPriorityQueueIsEmpty( _pq ) );
	IntegerListPopFront( _pq.m_orderedItems );
}