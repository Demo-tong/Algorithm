/*************************************************************************
 **	    >  Name : mergeSort.c
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年12月13日 星期日 13时34分19秒
 **     > Description: 分治法递归实现归并排序
 ************************************************************************/
#include <stdio.h>

void printArray ( int a[] , int length )
{
    int i ;

    printf ( "Elements of the Array:\n" ) ;
    for ( i = 0 ; i < length ; i++ ) {
        printf ( "%d " , a[i] ) ;
    }

    printf ( "\n" ) ;
}

void mergeArray ( int a[] , int left , int mid , int right )
{
    int i = left , j = mid ;
    int m = mid + 1 , n = right ;
    int k = 0 , temp[right + 1] ;

    while ( i <= j && m <= n ) {
        if ( a[i] <= a[m] ) {
            temp[k++] = a[i++] ;
        } else {
            temp[k++] = a[m++] ;
        }
    }

    if ( i <= j ) {
        while ( i <= j ) {
            temp[k++] = a[i++] ;
        }
    } else {
        while ( m <= n ) {
            temp[k++] = a[m++] ;
        }
    }

    for ( i = 0 ; i < k ; i++ ) {
        a[left + i] = temp[i] ;
    }
}

void mergeSort ( int a[] , int left , int right )
{
    if ( left >= right ) {
        return ;
    } 

    int mid = ( left + right ) / 2 ;
    mergeSort ( a , left , mid ) ;
    mergeSort ( a , mid + 1 , right ) ;

    mergeArray ( a , left , mid , right ) ;
}
 
int main ( int argc , char * argv[] )
{
    int a[] = { 2, 7, 3, 5, 6 }  ;

    int length = sizeof (a) / sizeof ( int ) ;

    printArray ( a , length ) ;

    mergeSort ( a , 0 , length - 1 ) ;

    printArray ( a , length ) ;

//    printf ( "length = %d\n" , length ) ;

    return 0 ;
}

