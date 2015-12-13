/*************************************************************************
 **	    >  Name : FDG_combine.cpp
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年11月22日 星期日 14时15分03秒
 **     > Description : 非递归实现归并排序。
 ************************************************************************/
#include <iostream>

#define Max 5

// 数组合并算法
void MergeArray ( int * a , int left , int middle , int right , int n ) 
{
	int * p = new int[n] ;

	int i = left , j = middle + 1 , k = 0 ;

	// 架循环使得两个数组按照大小顺序存储在ｐ数组中
	while ( i <= middle && j <= right ) {
		if ( a[i] < a[j] ) {
			p[k++] = a[i++] ;
		} else {
			p[k++] = a[j++] ;
		}
	}

	while ( i <= middle ) {
		p[k++] = a[i++] ;
	}

	while ( j <= right ) {
		p[k++] = a[j++] ;
	}

	// 将合并后的信息赋值给原数组
	for ( i = 0 ; i < n ; i++ ) {
		a[left+i] = p[i] ;
	}

	delete [] p ;
}

// 归并排序算法
void MergeSort ( int * a , int n )
{
	int length = 1 ;
	int begin ;

	for ( length = 1 ; length < n ; length *= 2 ) {
		//  每一次的分组划分合并处理,都是从下标0开始的
		begin = 0 ;
		while ( ( begin + 2 * length ) < n ) {
			// 调用合并函数,实现两两小数组合并
			MergeArray ( a , begin , ( 2*begin + 2*length -1 ) / 2 , begin + 2*length - 1 , 2*length ) ;
			// 循环到下一对合并的小数组
			begin += 2*length ;
		} 

		// 如果剩下的长度不足够2*length但begin+length<n,则继续将其合并
		if ( ( begin + length ) < n ) {
			MergeArray ( a , begin , begin + length - 1 , n - 1 , n ) ;
		}
		
	}
}

int main (  ) 
{
	int array[Max] = { 0 } ;

	std::cout << "Please input the " << Max << " elements of the array : " << std::endl ;
	for ( int i = 0 ; i < Max ; i++ ) {
		std::cin >> array[i] ;
	}

	// 调用归并排序函数
	MergeSort ( array , Max ) ;

	// 排序结束后的数组进行输出展示
	std::cout << std::endl << "The sorted array is : " << std::endl ;
	for ( int i = 0 ; i < Max ; i++ ) {
		std::cout << array[i] << " " ;
	}

	std::cout << std::endl ;

	return 0 ;
}
