/*************************************************************************
 **     >  Name : 0_1.cpp
 **     > Author: LiYingXiao (Sweethreart502) 
 **     >  Mail : liyingxiao502@gmail.com
 **     >  Blog : http://blog.csdn.net/u013166575
 **     > Created Time: 2015年11月27日 星期五 09时11分19秒
 ************************************************************************/
#include<iostream>

#define N 4

using namespace std;

int min(int a, int b){
    return a>b?b:a;
}

int judge ( int n ) {
    if( n % 2 )         // n为奇数，则取n/2下标数字为中位数
        return n / 2 ;
    else            // n为偶数，则取n/2-1下标数字为中位数
        return n / 2 - 1 ;
}

// 寻找中位数的核心函数
int search ( int a[], int b[], int length )
{
    int a_begin = 0, a_end = length ;
    int b_begin = 0, b_end = length ;
    int n = length ;
    int i , j ;

    while ( n != 1 ) {
        i = judge ( n ) ;   // i为当前的中位数下标值
        j = i + 1 ;        // j为中位数的后一位下标

        // 不能理解if条件后处理的思路
        if ( a[i + a_begin] < b[i + b_begin] )
        {
            // 获取a数组后一部分，b数组前一部分
            a_begin = a_end - j ;
            b_end = j + b_begin ;
            n = a_end - a_begin ;
        }
        else {
            // 获取a数组前一部分，b数组后一部分
            a_end = j + a_begin ;
            b_begin = b_end - j ;
            n = a_end - a_begin ;
        } /* end of if-else */

        /*
         * 如果是前一部分，则只需要将end修改为j+begin即可；
         * 如果是后一部分，则需要将begin修改为end - j才可以。
         * */
    } /* while循环的结束 */

    return min ( a[a_begin] , b[b_begin] ) ; /* 比较小的为中位数 */
}

// 主函数
int main () {
    int a[10] , b[10] ;
    int i , j ;

    for (i = 0 ; i < N ; i++ ) {
        std::cin >> a[i] ;
    }

    for (i = 0 ; i < N ; i++ ) {
        std::cin >> b[i] ;
    }

    std::cout << search ( a , b , N ) << std::endl ;

    return 0 ;
}
