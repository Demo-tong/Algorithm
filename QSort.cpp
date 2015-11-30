/*************************************************************************
 **	    >  Name : QSort.cpp
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年11月30日 星期一 20时50分59秒
 ************************************************************************/

#include <iostream>

#define N 5

void QSort ( int a[] , int low , int high )
{
    // 首先检查参数合法性
    if ( low >= high ) {
        return ;
    }

    int first = low , last = high ;
    // 以第一个为基准
    int key = a[low] ;

    while ( first < last ) {
        // 后面的与key比较，如果小于key,则更换first值；反之last减一
        while ( first < last && a[last] >= key ) {
            last-- ;
        }
        a[first] = a[last] ;

        // 前面的与key比较，如果大于key,则更换last值；反之first加一
        while ( first < last && a[first] <= key ) {
            first++ ;
        }
        a[last] = a[first] ;
    }

    // 循环结束，将key值存储在当前first/last所在位置
    a[first] = key ;
    // 接下来继续递归调用
    QSort ( a , low , first - 1 ) ;
    QSort ( a , first + 1 , high ) ;
}

// 主函数
int main ( int argc , char * argv[] )
{
    int a[] = { 12 , 13 , 21 , 15 , 32 } ;
    
    // 排序前输出
    std::cout << "before of the Sort :" << std::endl ;
    for ( int i = 0 ; i < N ; i++ ) {
        std::cout << a[i] << " " ;
    }
    std::cout << std::endl ;

    QSort ( a , 0 , N - 1 ) ;

    // 排序后输出
    std::cout << "after of the Sort :" << std::endl ;
    for ( int i = 0 ; i < N ; i++ ) {
        std::cout << a[i] << " " ;
    }
    std::cout << std::endl ;

    return 0 ;
}
