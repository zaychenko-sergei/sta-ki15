#include "integer_priority_queue.hpp"
#include "integer_vector.hpp"

#include <cassert>


struct IntegerPriorityQueue
{
	IntegerVector m_orderedItems;
};


IntegerPriorityQueue * IntegerPriorityQueueCreate ()
{
	IntegerPriorityQueue * pPQ = new IntegerPriorityQueue;
	IntegerVectorInit( pPQ->m_orderedItems );
	return pPQ;
}


void IntegerPriorityQueueDestroy ( IntegerPriorityQueue * _pPQ )
{
	IntegerVectorDestroy( _pPQ->m_orderedItems );
	delete _pPQ;
}


void IntegerPriorityQueueClear ( IntegerPriorityQueue & _pq )
{
	IntegerVectorClear( _pq.m_orderedItems );
}


bool IntegerPriorityQueueIsEmpty ( const IntegerPriorityQueue & _pq )
{
	return _pq.m_orderedItems.m_nUsed == 0;
}


void IntegerPriorityQueueInsert ( IntegerPriorityQueue & _pq, int _key )
{
	for ( int i = 0; i < _pq.m_orderedItems.m_nUsed; i++ )
		if ( _key < _pq.m_orderedItems.m_pData[ i ] )
		{
			IntegerVectorInsertAt( _pq.m_orderedItems, i, _key );
			return;
		}

	IntegerVectorPushBack( _pq.m_orderedItems, _key );
}


int IntegerPriorityQueueMin ( const IntegerPriorityQueue & _pq )
{
	assert( ! IntegerPriorityQueueIsEmpty( _pq ) );
	return _pq.m_orderedItems.m_pData[ 0 ];
}


void IntegerPriorityQueueDeleteMin ( IntegerPriorityQueue & _pq )
{
	assert( !IntegerPriorityQueueIsEmpty( _pq ) );
	IntegerVectorDeleteAt( _pq.m_orderedItems, 0 );
}