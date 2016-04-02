#include "integer_priority_queue.hpp"
#include "integer_list.hpp"

#include <cassert>


struct IntegerPriorityQueue
{
	IntegerList m_unorderedItems;
};


IntegerPriorityQueue * IntegerPriorityQueueCreate ()
{
	IntegerPriorityQueue * pPQ = new IntegerPriorityQueue;
	IntegerListInit( pPQ->m_unorderedItems );
	return pPQ;
}


void IntegerPriorityQueueDestroy ( IntegerPriorityQueue * _pPQ )
{
	IntegerListDestroy( _pPQ->m_unorderedItems );
	delete _pPQ;
}



void IntegerPriorityQueueClear ( IntegerPriorityQueue & _pq )
{
	IntegerListClear( _pq.m_unorderedItems );
}


bool IntegerPriorityQueueIsEmpty ( const IntegerPriorityQueue & _pq )
{
	return IntegerListIsEmpty( _pq.m_unorderedItems );
}


void IntegerPriorityQueueInsert ( IntegerPriorityQueue & _pq, int _key )
{
	IntegerListPushBack( _pq.m_unorderedItems, _key );
}


IntegerList::Node * IntegerPriorityQueueMinNode ( const IntegerPriorityQueue & _pq )
{
	if ( IntegerPriorityQueueIsEmpty( _pq ) )
		return nullptr;

	IntegerList::Node * pMinimal = _pq.m_unorderedItems.m_pFirst;
	IntegerList::Node * pCurrent = pMinimal->m_pNext;
	while ( pCurrent )
	{
		if ( pCurrent->m_value < pMinimal->m_value )
			pMinimal = pCurrent;

		pCurrent = pCurrent->m_pNext;
	}

	return pMinimal;
}


int IntegerPriorityQueueMin ( const IntegerPriorityQueue & _pq )
{
	IntegerList::Node * pMinNode = IntegerPriorityQueueMinNode( _pq );
	assert( pMinNode != nullptr );

	return pMinNode->m_value;
}


void IntegerPriorityQueueDeleteMin ( IntegerPriorityQueue & _pq )
{
	IntegerList::Node * pMinNode = IntegerPriorityQueueMinNode( _pq );
	assert( pMinNode != nullptr );

	IntegerListDeleteNode( _pq.m_unorderedItems, pMinNode );
}