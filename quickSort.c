/*************************************************************************
 **	    >  Name : quickSort.c
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年12月13日 星期日 14时39分20秒
 **     > Description: 
 ************************************************************************/
#include <stdio.h>

void printArray ( int a[] , int length )
{
    int i ; 

    for ( i = 0 ; i < length ; i++ ) {
        printf ( "%d " , a[i] ) ;
    }
    printf ( "\n" ) ;
}

void quickSort ( int a[] , int low , int high )
{
    if ( low >= high ) {
        return ; 
    }
    
    int start = low , end = high ;
    int key = a[start] ;

    while ( start < end ) {
        while ( start < end && a[end] >= key ) {
            end-- ;
        }

        a[start] = a[end] ;

        while ( start < end && a[start] <= key ) {
            start++ ;
        }

        a[end] = a[start] ;
    }

    a[start] = key ;

    quickSort ( a , low , start - 1 ) ;
    quickSort ( a , start + 1 , high ) ;
}

int main ( int argc , char * argv[] )
{
    int a[] = { 2 , 4 , 5 , 3 , 8 } ;
    int length = sizeof ( a ) / sizeof ( int ) ;

    printArray ( a , length ) ;

    quickSort ( a , 0 , length - 1 ) ;

    printArray ( a , length ) ;

    return 0 ;
}

