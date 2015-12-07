/*************************************************************************
 **	    >  Name : sum.cpp
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年11月02日 星期一 18时39分30秒
 ************************************************************************/

#include <iostream>

/* 前ｎ项累加求和 */

class Sum {
    private :
        static int n ;
        static int sum ;
    public :
        Sum () {
            ++n ;   // n初始化为０，因此累加时必须先加１
            sum += n ;
        }
        // 初始化函数
        static void setSum () {
            n = 0 ;
            sum = 0 ;
        }
        // 获得sum值
        static int getSum () {
            return sum ;    
        }
} ;

int Sum::n = 0 ;
int Sum::sum = 0 ;

int Add ( int N ) {
    // 首先初始化变量n,sum
    Sum::setSum () ;    

    // 随后定义一个数组，元素为N,则调用N次构造函数，即实现求和
    Sum *a = new Sum[N] ;

    delete [] a ;

    a = 0 ;

    return Sum::getSum () ;
}

int main ( int argc , char * argv[] )
{
    std::cout << Add (100) << std::endl ;

    return 0 ;
}
