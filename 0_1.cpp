/*************************************************************************
 **     >  Name : 0_1.cpp
 **     > Author: LiYingXiao (Sweethreart502) 
 **     >  Mail : liyingxiao502@gmail.com
 **     >  Blog : http://blog.csdn.net/u013166575
 **     > Created Time: 2015年11月21日 星期六 23时41分19秒
 **     > Description : 0_1背包问题，在容量的约束下，使得装载的物品价值最大。
 ************************************************************************/

#include <iostream>

// 五个物品的对应重量
int w[6] = { 0 , 2 , 2 , 6 , 5 , 4 } ;
// 五个物品的对应价值
int v[6] = { 0 , 6 , 3 , 5 , 4 , 6 } ;
// 背包总容量
int c = 10 ;
// 每一个物品的状态值
int x[6] = { 0 } ;


// 核心处理函数
void process ( int m[][11] ) ;

// 输出放入情况
void option ( int m[][11] )  ;

int main ( int argc , char * argv[] )
{
    int i ;

    // 初始化价值数组为0
    int m[6][11] = { 0 } ;

    process ( m ) ;

    for ( int i = 1 ; i < 6 ; i++ ) {

        for ( int j = 0 ; j < 11 ; j++ ) {
            if ( m[i][j] / 10 ) 
                std::cout << m[i][j] << "  " ;
            else 
                std::cout << " " << m[i][j] << "  " ;
        }
        std::cout << std::endl ;
    }

    option ( m ) ;

    // 输出情况
    std::cout << "输出装入情况:0表示不装,1表示装" << std::endl ;
    for ( i = 1 ; i <= 5 ; i++ ) {
        if ( x[i] ) {
            std::cout << "1  " ;
        } else {
            std::cout << "0  " ;
        }
    }
    std::cout << std::endl ;

    return 0 ;
}

void process ( int m[][11] )
{
    int i , j ;

    /* 首先解决最后一个物品是否放入 */
    for ( j = 0 ; j <= c ; j++ ) {
        if ( w[5] > j ) {
            m[5][j] = 0 ; 
        } /* 不能放下,价值为零 */
        else {
            m[5][j] = v[5] ;
        }/* 可以放下,价值为其本身价值 */
    }

    /* 从下至上分析 */
    for ( i = 4 ; i >=  1 ; i-- ) { /* 从下至上依次分析每一个物品 */
        for ( j = 0 ; j <= c ; j++ ) { /* 从左至右一次分析j在0~10之间 */
            if ( w[i] > j ) { 
                m[i][j] = m[i+1][j] ;
            } /* 不能放入,则价值为下一行同一列的值 */
            else {
                m[i][j] = ( m[i+1][j] > v[i]+m[i+1][j-w[i]] ) ? m[i+1][j] : v[i]+m[i+1][j-w[i]] ;
                /* 如果放入,则它的价值为当前物品的价值加上下一个物品在剩余容量j减去当前物品重量的条件下的价值 */
            } /* 分析放入的价值大,还是不放的价值大 */
        }
    }
}

void option ( int m[][11] ) 
{
    int i , j = c ; 

    /* 初识情况将j设置为c总容量 */
    for ( i = 1 ; i <= 4 ; i++ ) {
        if ( m[i][j] == m[i+1][j] ) {
            /* 如果该物品价值与下一个物品在当前j下的价值相等,则该物品未放入.因为m数组初始情况是从下到上分析的 */
            x[i] = 0 ;
        } 
        else {
            x[i] = 1 ;
            j -= w[i] ; /* 放入某物品后,要将j减少该物品的重量 */
        }
    }
    /* 最后一个物品是否放入,只需要看当前物品在j下是否价值为零. */
    x[5] = m[5][j] ? 1 : 0 ;
} 
