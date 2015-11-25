/*************************************************************************
 **	    >  Name : Order.c
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年11月23日 星期一 01时07分34秒
 ************************************************************************/

/*
 * 选择排序
 * 选择排序的改进
 *
 * 冒泡排序
 * 冒泡排序的改进
 *
 * 插入排序
 *
 * 归并排序(二路归并)
 * 归并排序(自然排序)
 *
 * 快速排序
 *
 * 堆排序
 *
 * */

#include <stdio.h>

#define N 5

// 选择排序
void order1 ( int a[] ) ;

// 选择排序的改进( ERROR )
void order1_0 ( int a[] ) ;

// 冒泡排序
void order2 (int a[] ) ;

// 冒泡排序的改进
void order2_0 ( int a[] ) ;

// 输出结果
void print ( int a[] ) ;

/* 主函数 */
int main ( int argc , char * argv[] )
{
    int a[] = { 4 , 2 , 7 , 1 , 9 } ;

    // 选择排序
    order2_0 ( a ) ;

    // 输出结果
    print ( a ) ;

    return 0 ;
}

/* 选择排序 */
void order1 ( int a[] )
{
    int i , j ;
    int t ;

    for ( i = 0 ; i < N ; i++ ) {
        for ( j = i+1 ; j < N ; j++ ) {
            if ( a[i] > a[j] ) {
                t = a[i] ;
                a[i] =a[j] ;
                a[j] = t ;
            }
        }
    }
}

/* 选择排序的改进 */
void order1_0 ( int a[] )
{
    int i , j ;
    int t , min , index ;

    for ( i = 0 ; i < N ; i++ ) {
        min = a[i] ;
        index = i ;
        for ( j = i+1 ; j < N ; j++ ) {
            if ( min > a[j] ) {
                min = a[j] ;
                index = j ;
                // 交换
                t = a[i] ;
                a[i] = a[j] ;
                a[j] = t ;
            }
        }
    }
}

/* 冒泡排序 */
void order2 ( int a[] )
{
    int i , j ;
    int t ;

    for ( i = 0 ; i < N ; i++ ) {
        for ( j = 0 ; j < N - 1 ; j++ ) {
            if ( a[i] < a[j] ) {
                t = a[i] ;
                a[i] = a[j] ;
                a[j] = t ;
            }
        }
    }
}

/* 冒泡排序的改进 */
void order2_0 ( int a[] ) 
{
    int i , j ;
    int t , max , index ;

    for ( i = 0 ; i < N ; i++ ) {
        max = a[i] ;
        index = i ;
        for ( j = 0 ; j < N - 1 ; j++ ) {
            if ( max < a[j] ) {
                max = a[j] ;
                index = j ;
                t = a[i] ;
                a[i] = a[j] ;
                a[j] = t ;
            }
        }
    }
}

/* 输出函数 */
void print ( int a[] )
{
    int i ;

    for ( i = 0 ; i < N ; i++ ) {
        printf ( "%d " , a[i] ) ;
    }
    printf ( "\n" ) ;
}
