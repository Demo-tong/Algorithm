/*************************************************************************
 **	    >  Name : num_triangle.c
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年11月19日 星期四 23时32分00秒
 ************************************************************************/

#include <stdio.h>
#define N 5

int Process ( int n ) ;

int main ( int argc , char * argv[] )
{
//    int n ;

    int max ;
    
//    printf ( "请输入数字三角形的行数:\n" ) ;
//    scanf ( "%d" , &n ) ;

    max = Process ( N ) ;

    printf ( "\n最大路径和为%d.\n" , max ) ;

    return 0 ;
}

// 核心处理函数
int Process ( int n ) 
{
    int a[6][6] = { { 0 } , { 0 } , { 0 } , { 0 } , { 0 } , { 0 } } ;

    int i , j ;

    int t1 , t2 ;

    int max = 0 ;

    // 初始化数字三角形
    printf ( "请输入数字三角形每一行数据信息:\n" ) ;
    for ( i = 1 ; i <= n ; i++ ) {
        printf ( "请输入第%d行数据信息:\n" , i ) ;
        for ( j = 1 ; j <= i ; j++ ) {
            scanf ( "%d" , &a[i][j] ) ;
        }
    }

    // 计算每一行的的每一个元素到起点的最大距离
    for ( i = 2 ; i <= n ; i++ ) {
        for ( j = 1 ; j <= i ; j++ ) {
            t1 = a[i][j] + a[i-1][j-1] ;
            t2 = a[i][j] + a[i-1][j] ;

            // 确定每一个元素位置的最大值
            if ( t1 > t2 ) {
                a[i][j] = t1 ;
            } else {
                a[i][j] = t2 ;
            }
        }
    }

    // 比较最后一行数据信息,输出最大值即可
    for ( i = 1 ; i <= n ; i++ ) {
        if ( a[n][i] > max )   {
            max = a[n][i] ;
        }
    }

    return max ;
}
