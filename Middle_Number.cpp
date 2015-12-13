/*************************************************************************
 **	    >  Name : test.cpp
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年12月02日 星期三 12时43分12秒
 **     > Description : 
 ************************************************************************/

#include <iostream>


// 处理函数
double Process ( int a[] , int b[] , int n ) 
{
    // ａ数组左右下标
    int la = 0 , ra = n - 1 ;
    // b数组左右下标
    int lb = 0 , rb = n - 1 ;
    // a,b数组的中位数下标
    int ma , mb ;
    // a,b数组的中位数值
    double fa , fb ;
    // 最终结果
    double middle ;

    while ( ( ( la + 1 ) != ra ) || ( ( lb + 1 ) != rb ) ) {
        // 在两个数组都不是两个元素的时候，一直出于循环中
        ma = ( la + ra ) / 2 ;
        mb = ( lb + rb ) / 2 ;

        if ( n % 2 == 0 ) {
            // 偶数个元素
            fa = ( double ) ( a[ma] + a[ma+1] ) / 2 ;
            fb = ( double ) ( b[mb] + b[mb+1] ) / 2 ;
        } else {
            // 奇数个元素
            fa = a[ma] ;
            fb = b[mb] ;
        }

        // 进行比较，选取两个数组的合适部分，作为下一次处理
        if ( fa <= fb  ) {
            // 选择ａ后部分，ｂ前部分
            la = ma ;
            if ( n % 2 == 0 ) {
                // 偶数个元素，需要将取前一部分的数组元素向后加一个
                rb = mb + 1 ;
            } else {
                rb = mb ;
            }
        } else if ( fa >= fb ) {
            if ( n % 2 == 0 ) {
                ra = ma + 1 ;
            } else {
                ra = ma ;
            }
            lb = mb ;
        }

 //       ma = ( la + ra ) / 2 ;
 //       mb = ( lb + rb ) / 2 ;
        // 计算当前数组元素个数ｎ的值
        n = n / 2 + 1 ;
    }

    // 后续处理
    // 跳出循环，说明已经只剩下四个元素，每个数组剩两个元素，此时进行处理，获取中位数

    /**
     * 对两个有序数组进行排序，然后取得中位数
     */
    int i , j , k = 0 ;
    int tmp[4] ;
    for ( i = la , j = lb ; i <= ra && j <= rb ; ) {
        if ( a[i] <= b[j] ) {
            tmp[k++] = a[i++] ;
        } else {
            tmp[k++] = b[j++] ;
        }
    }

    if ( i <= ra ) {
        while ( i <= ra ) {
            tmp[k++] = a[i++] ;
        }
    } else {
        while ( j<= rb ) {
            tmp[k++] = b[j++] ;
        }
    }

    middle = ( double ) ( tmp[1] + tmp[2] ) / 2 ;

    return middle ;
}

int main ( int argc , char * argv[] )
{
    int n ;
    std::cout << "请输入数组元素个数：" << std::endl ;
    std::cin >> n ;

    // 定义数组ａ与ｂ
    int a[n] , b[n] ;

    std::cout << "请输入ａ数组元素：" << std::endl ;
    for ( int i = 0 ; i < n ; i++ ) {
        std::cin >> a[i] ;
    }

    std::cout << "请输入ｂ数组元素个数：" << std::endl ;
    for ( int i = 0 ; i < n ; i++ ) {
        std::cin >> b[i] ;
    }

    double middle ;
    if ( a[n-1] <= b[0] ) {
        middle = ( double ) ( a[n-1] + b[0] ) / 2 ;    
    } else if ( a[0] >= b[n-1] ) {
        middle = ( double ) ( a[0] + b[n-1] ) / 2 ;
    } else {
        // n表示元素个数，数组下标为0~n-1
        middle = Process ( a , b , n ) ;
    }

    std::cout << "ab数组的中位数为：" << middle << std::endl ;

    return 0 ;
}

