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

// 快速排序
void order5 ( int a[] ) ;
void QSort ( int a[] , int low , int high ) ;
// 输出结果
void print ( int a[] ) ;

/* 主函数 */
int main ( int argc , char * argv[] )
{
    int a[] = { 4 , 2 , 7 , 1 , 9 } ;

    // 选择排序
    order5 ( a ) ;

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

// 快速排序
void order5 ( int a[] )
{
    QSort ( a , 0 , N - 1 ) ;
}

void QSort ( int a[] , int low , int high )
{
    // 首先检查参数合法性
    if ( low >= high ) {
        // 这个条件一定要写对，否则运行没有效果，一段时间里总是会忽略这个条件的检查。＃我就在这里错了一次＃
        return ;
    }

    int first = low ;
    int last = high ;
    int key = a[low] ;  // 将第一个元素作为key

    while ( first < last ) {
        // 在后面找比key小的数
        while ( first < last && a[last] >= key ) {
            // last值大，则继续
            last-- ;
        } 
        // 否则它小于key，则将a[first]修改为当前的a[last]
        a[first] = a[last] ;

        // 从前面找比key大的数
        while ( first < last && a[first] <= key ) {
            // first值小，则继续
            first++ ;
        }
        // 否则它大于key，则将a[last]修改为当前的a[first]
        a[last] = a[first] ;
    }

    // 循环结束，则将key放入a[first]或者a[last],当前的last=first
    a[first] = key ;

    // 以key位置为分界线，继续递归
    QSort ( a , low , first - 1 ) ;
    QSort ( a , first + 1 , high ) ;
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
