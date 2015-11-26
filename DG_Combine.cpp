/*************************************************************************
 **	    >  Name : none.c
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年11月26日 星期四 21时24分50秒
 ************************************************************************/
#include <iostream>

using namespace std ;
// 数组定义以及初始化
int a[] = { 23 , 65 , 12 , 3 , 8 , 76 , 345 , 90 , 21 , 75 , 34 , 61 } ;
// 数组长度变量
int len = sizeof ( a ) / sizeof ( a[0] ) ;
// 定义数组指针
int * tmp = new int[len] ;

// 合并数组函数
void mergeArray ( int * a , int * tmp , int left , int middle , int right ) {
	int i = left , j = middle ;
	int m = middle + 1 , n = right ; 
	int k = 0 ;

	// 通过循环获得排好序的数组元素存储在temp中
	while ( i <= j && m <= n ) {
		if ( a[i] <= a[m] ) {
			tmp[k++] = a[i++] ;
        }
		else {
			tmp[k++] = a[m++] ;
	    }
    }

	while ( i <= j ) {
		tmp[k++] = a[i++] ;
    }
	while ( m <= n ) {
		tmp[k++] = a[m++] ;
    }

	// 通过for循环使得原数组a改变与temp保持一致
	for ( i = 0 ; i < k ; i++ )
		a[left + i] = tmp[i] ;
}

// 归并排序算法
void mergeSort ( int * a , int * tmp , int left , int right ) 
{
	if ( left < right ) {
		int middle = ( left + right ) / 2  ;
		mergeSort ( a , tmp , left , middle ) ;
		mergeSort ( a , tmp , middle + 1 , right ) ;
		mergeArray ( a , tmp , left , middle , right ) ;
	}
}

// 主函数
int main()
{
	// 调用排序函数
	mergeSort ( a , tmp, 0, len - 1 ) ;

	// 输出排好顺序的数组变量
	for ( int i = 0 ; i < len ; i++ ) {
        std::cout << a[i] << " " ;
    }
    std::cout << std::endl ;

	return 0;
}
