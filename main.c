/*	QUICK SORT - ORIGINAL  	   Written by:  	   Date: */
#include <stdio.h>
#define MAX_ARY_SIZE 12
//	Prototype Declarations
	void quickSort       (int sortData[ ], int left, int right);
	void quickInsertion	 (int sortData[ ], int first, int last);
	void quickMedian (int sortData[ ], int left, int right);
// MAIN
int main (void)
{
	int i ;
	int	ary[ MAX_ARY_SIZE ] = { 89, 72, 3,  15, 21, 57, 61, 44, 19, 98, 5, 77 };// , 39, 59, 61 } ;

	printf("Unsorted array:\n");
	for (i = 0; i < MAX_ARY_SIZE; i++) { printf("Pl enter the values-->"); scanf("%4d", &ary[i]);}
//		printf("%3d", ary[ i ]) ;
	quickSort (ary, 0, MAX_ARY_SIZE - 1) ;

	printf("\nSorted array:   ") ;
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[ i ]) ;
	printf("\n") ;
	return 0 ;
}	// main
//	=================== quickSort ====================
void quickSort (int sortData[ ], int left, int right)
{
#define MIN_SIZE 3          // set to 3 for testing
//	Local Definitions
int sortLeft;
int sortRight;
int pivot;
int hold;
//	Statements
	if ((right - left) > MIN_SIZE)
	  {quickMedian(sortData, left, right);
	   pivot     = sortData [left];
	   sortLeft  = left + 1;
	   sortRight = right;
	   while (sortLeft <= sortRight)
	     {
	      // Find key on left that belongs on right
	      while (sortData [sortLeft] < pivot)
	         sortLeft = sortLeft + 1;
	      // Find key on right that belongs on left
	      while (sortData[sortRight] >= pivot)
	         sortRight = sortRight - 1;
	      if (sortLeft <= sortRight)
	        {
	         hold                = sortData[sortLeft];
	         sortData[sortLeft]  = sortData[sortRight];
	         sortData[sortRight] = hold;
	         sortLeft            = sortLeft  + 1;
	         sortRight           = sortRight - 1;
	        } // if
	     } // while
	   // Prepare for next pass
	   sortData [left]         = sortData [sortLeft - 1];
	   sortData [sortLeft - 1] = pivot;
	   if (left < sortRight)
	       quickSort (sortData, left, sortRight - 1);
	   if (sortLeft < right)
	       quickSort (sortData, sortLeft, right);
	  } // if right
	else
	  quickInsertion (sortData, left, right);
    return;
}	// quickSort

//	=================== Program 12-7 quickInsertion ====================
void quickInsertion (int sortdata[], int first, int last)
{
//	Local Definitions
	int hold;
	int walker;
//	Statements
	for (int current = first + 1; current <= last; current++)
	   {
	    hold   = sortdata[current];
	    for (walker = current - 1; walker >= first && hold < sortdata[walker]; walker--)
             { sortdata[walker + 1] = sortdata[walker];   }
        sortdata[walker + 1] = hold;
	   } // for
	return;
}	// quickInsertion

void quickMedian(int sortData[ ], int left, int right)
{
    int iMiddle = (left + right) / 2;
    int iMaximum = left;
    int iMinimum = right;

    if(sortData[iMiddle] > sortData[iMaximum])
    {
        iMaximum = iMiddle;
    }
    if(sortData[right] > sortData[iMaximum])
    {
        iMaximum = right;
    }
    if(sortData[iMiddle] < sortData[iMinimum])
    {
        iMinimum = iMiddle;
    }
    if(sortData[left] < sortData[iMinimum])
    {
        iMinimum = left;
    }

    int iMedian = 0;

    if(left != iMaximum && left != iMinimum)
    {
        iMedian = left;
    }else if(iMiddle != iMaximum && iMiddle != iMinimum)
    {
        iMedian = iMiddle;
    }
    else
    {
        iMedian = right;
    }

    if(iMedian != left)
    {
        int iTemp = sortData[left];

        sortData[left] = sortData[iMedian];
        sortData[iMedian] = iTemp;
    }
}

