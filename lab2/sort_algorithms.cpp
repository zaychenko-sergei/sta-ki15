#include "sort_algorithms.hpp"

#include <algorithm>
#include <memory.h>
#include <stdlib.h>


void bubbleSort ( int* _pData, int _N )
{
    for ( int i = 0; i < _N - 1; i++ )
        for ( int j = _N - 1; j > i; j-- )
            if ( _pData[ j - 1 ] > _pData[ j ] )
				std::swap( _pData[ j ], _pData[ j - 1 ] );
}


void insertionSort ( int* _pData, const int _N )
{
    for ( int i = 1; i < _N; i++ )
    {
        int j = i;
        while ( j && ( _pData[ j ] < _pData[ j - 1 ] ) )
        {
            std::swap( _pData[ j ], _pData[ j - 1 ] );
            --j;
        }
    }
}

void selectionSort ( int* _pData, const int _N )
{
    for ( int i = 0; i < _N - 1; i++ )
    {
        int lowIndex = i;
        for ( int j = i + 1; j < _N; j++ )
            if ( _pData[ j ] < _pData[ lowIndex ] )
                lowIndex = j;

        std::swap( _pData[ lowIndex ], _pData[ i ] );
    }
}


void mergeSorted ( const int * _pFirst,  int _firstSize,
                   const int * _pSecond, int _secondSize,
                   int * _pTarget )
{
    int firstIndex = 0, secondIndex = 0, targetIndex = 0;
    while ( firstIndex < _firstSize && secondIndex < _secondSize )
    {
        if ( _pFirst[ firstIndex ] <= _pSecond[ secondIndex ] )
        {
            _pTarget[ targetIndex ] = _pFirst[ firstIndex ];
            ++ firstIndex;
        }

        else
        {
            _pTarget[ targetIndex ] = _pSecond[ secondIndex ];
            ++ secondIndex;
        }

        ++ targetIndex;
    }

    if ( firstIndex < _firstSize )
        memcpy( _pTarget + targetIndex,
                _pFirst + firstIndex, 
                sizeof( int ) * ( _firstSize - firstIndex ) 
        );

    else if ( secondIndex < _secondSize )
        memcpy( _pTarget + targetIndex,
                _pSecond + secondIndex, 
                sizeof( int ) * ( _secondSize - secondIndex ) 
        );
}


void mergeSort ( int * _pData, int _N )
{
    if ( _N < 10 )
        selectionSort( _pData, _N );

    else
    {
        int halfSize = _N / 2;
        int otherHalfSize = _N - halfSize;

        int * pFirstHalf = new int[ halfSize ];
        memcpy( pFirstHalf, _pData, sizeof( int ) * halfSize );

        int * pSecondHalf = new int[ otherHalfSize ];
        memcpy( pSecondHalf, _pData + halfSize, sizeof( int ) * otherHalfSize );

        mergeSort( pFirstHalf,  halfSize );
        mergeSort( pSecondHalf, otherHalfSize );

        mergeSorted( pFirstHalf, halfSize, pSecondHalf, otherHalfSize, _pData );

        delete[] pFirstHalf;
        delete[] pSecondHalf;
    }
}


void randomShuffle ( int * _pData, int _N )
{
	for ( int i = 0; i < _N; i++ )
	{
		int j = i + ( rand() % ( _N - i ) );
		std::swap( _pData[ i ], _pData[ j ] );
	}
}


int partition ( int * _pData, int _low, int _high )
{
	int pivot = _pData[ _low ];
	int i = _low, j = _high + 1;

	while ( true )
	{
		while ( _pData[ ++i ] < pivot )
			if ( i == _high )
				break;

		while ( pivot < _pData[ --j ] )
			if ( j == _low )
				break;

		if ( i >= j )
			break;

		std::swap( _pData[ i ], _pData[ j ] );
	}

	std::swap( _pData[ _low ], _pData[ j ] );

	return j;
}


void quickSortInternal ( int * _pData, int _low, int _high )
{
	if ( _low >= _high )
		return;

	if ( ( _high - _low ) < 10 )
	{
		selectionSort( _pData + _low, ( _high - _low + 1 ) );
		return;
	}

	int j = partition( _pData, _low, _high );

	quickSortInternal ( _pData, _low, j - 1 );
	quickSortInternal ( _pData, j + 1, _high );
}


void quickSort ( int * _pData, int _N )
{
	randomShuffle( _pData, _N );
	quickSortInternal( _pData, 0, _N - 1 );
}


void sink ( int * _pData, int _pos, int N )
{
	while ( 2 * _pos <= N )
	{
		int childPos = 2 * _pos;
		if ( childPos < N && _pData[ childPos ] < _pData[ childPos + 1 ] )
			++childPos;

		if ( !( _pData[ _pos ] < _pData[ childPos ] ) )
			break;

		std::swap( _pData[ _pos ], _pData[ childPos ] );
		_pos = childPos;
	}
}

void heapSort ( int * _pData, int _N )
{
	for ( int k = _N / 2; k >= 1; k-- )
		sink( _pData - 1, k, _N );

	while ( _N > 1 )
	{
		std::swap( _pData[ 0 ], _pData[ _N - 1 ] );
		sink( _pData - 1, 1, -- _N );
	}
}
