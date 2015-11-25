/*************************************************************************
 **	    >  Name : Nature_combine.cpp
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年11月24日 星期二 21时32分40秒
 ************************************************************************/

#include <iostream>
#define N 10

// 定义全局数组,记录每个子数组的其实坐标
int array[N] ;

// 两个数组合并函数
void MergeArray ( int a[] , int left , int right , int mid )
{
    // 循环变量i,j分别为两部分数组的检测指针
    int i = left , j = mid + 1 , k = 0 , m , p ; 

    int b[N] ;

    while ( i <= mid && j <=right ) {
        if ( a[i] <= a[j] ) {
            b[k++] = a[i++] ;
        } else {
            b[k++] = a[j++] ;
        }
    }

    while ( i <= mid ) {
        b[k++] = a[i++] ;
    }

    while ( j <= right ) {
        b[k++] = a[j++] ;
    }

    for ( p = 0 , m = left ; m <= right ; p++ , m++ ) {
        a[m] = b[p] ;
    }
}

// 扫描算法
int Pass ( int a[] , int n )  
{
    int num = 0 , i ;
    int biger = a[0] ;
    array[num++] = 0 ;  // 将全局数组下标为0的值记为0

    for ( i = 1 ; i < n ; i++ ) {
        if ( a[i] >= biger ) {
            biger = a[i] ;
        } else {
            array[num++] = i ;
            biger = a[i] ;
        }
    }

    // array数组存储每一组有序的数组的起始元素的下标,同时存储最后一个元素的下标+1,为了方便最后一组元素的合并也需要!!!
    array[num++] = N ;

    return num ;        // num此时为数组最后一个元素下标+1
}

// 归并排序的自然实现
void MergeSort ( int a[] , int n , int left , int right ) 
{
    int i ; 

    int num = Pass ( a , n ) ;
    
    while ( num != 2 ) {
        // num = 2 说明已经排序完成即只存储了下标为1的元素
        // 每循环一次,执行一次pass函数

        for ( i = 0 ; i < num ; i += 2 ) {
	    // array[i]即合并数据的起点; array[i+2]后一组的后面一组的起点-1即合并数据的终点; array[i+1]后一组的起点-1即合并数据的中点
            MergeArray ( a , array[i] , array[i+2] - 1 , array[i+1] - 1 ) ;

//            num = Pass ( a, n ) ;
        }
	num = Pass ( a , n ) ;
    }
}

// 主函数
int main (  )
{
    int a[N] ;
    int i ;

    std::cout << "Printf input the num :" << std::endl ;
    for ( i = 0 ; i < N ; i++ ) {
        std::cin >> a[i] ;
    }
	
    MergeSort ( a , N , 0 ,N - 1 ) ;

    std::cout << "Output the num :" << std::endl ;
    for ( i = 0 ; i < N ; i++ ) {
        std::cout << a[i] << " " ;
    }

    std::cout << std::endl ;

	return 0 ;
}
