#include "integer_priority_queue.hpp"
#include "integer_vector.hpp"

#include <cassert>


struct IntegerPriorityQueue
{
	IntegerVector m_unorderedItems;
};


IntegerPriorityQueue * IntegerPriorityQueueCreate ()
{
	IntegerPriorityQueue * pPQ = new IntegerPriorityQueue;
	IntegerVectorInit( pPQ->m_unorderedItems );
	return pPQ;
}


void IntegerPriorityQueueDestroy ( IntegerPriorityQueue * _pPQ )
{
	IntegerVectorDestroy( _pPQ->m_unorderedItems );
	delete _pPQ;
}



void IntegerPriorityQueueClear ( IntegerPriorityQueue & _pq )
{
	IntegerVectorClear( _pq.m_unorderedItems );
}


bool IntegerPriorityQueueIsEmpty ( const IntegerPriorityQueue & _pq )
{
	return _pq.m_unorderedItems.m_nUsed == 0;
}


void IntegerPriorityQueueInsert ( IntegerPriorityQueue & _pq, int _key )
{
	IntegerVectorPushBack( _pq.m_unorderedItems, _key );
}


int IntegerPriorityQueueMinPosition  ( const IntegerPriorityQueue & _pq )
{
	if ( IntegerPriorityQueueIsEmpty( _pq ) )
		return -1;

	int minIndex = 0;
	for ( int i = 1; i < _pq.m_unorderedItems.m_nUsed; i++ )
		if ( _pq.m_unorderedItems.m_pData[ i ] < _pq.m_unorderedItems.m_pData[ minIndex ] )
			minIndex = i;

	return minIndex;
}


int IntegerPriorityQueueMin ( const IntegerPriorityQueue & _pq )
{
	int minPosition = IntegerPriorityQueueMinPosition( _pq );
	assert( minPosition != -1 );

	return _pq.m_unorderedItems.m_pData[ minPosition ];
}


void IntegerPriorityQueueDeleteMin ( IntegerPriorityQueue & _pq )
{
	int minPosition = IntegerPriorityQueueMinPosition( _pq );
	assert( minPosition != -1 );

	IntegerVectorDeleteAt( _pq.m_unorderedItems, minPosition );
}