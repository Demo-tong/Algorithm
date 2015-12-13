/*************************************************************************
 **	    >  Name : Task.c
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年12月02日 星期三 08时28分23秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int n , a[21][21] , sum , best , b[21], c[21] , d[21] ;

void Process ( int m ) {
    int i , j ;

    if ( m > n ) {
        if ( best == -1 || sum < best ) {
            best = sum ;
        }
        // c数组存储的是ｉ工作分配给某个工人，将其拷贝给ｄ数组
        memcpy ( d , c , sizeof ( d ) ) ;
        return ;
    }

    // 对当前第m号工作进行处理
    for ( j = 1 ; j <= n ; j++ ) {
        if ( !b[j] ) {
            sum += a[m][j] ;    // sum加上此时的费用
            b[j]=1 ;            // 修改此时的分配状态
            c[m] = j ;          // 第ｍ号工作被分配给ｊ号工人

            if ( sum < best || best == -1 ) {
                // 此时无解或者sum>best则递归下一个工作
                Process ( m + 1 ) ;
            }

            // 递归结束后，使其回到之前的状态
            sum -= a[m][j] ;    // 减去ｍ号工作对于ｊ号工人的费用
            b[j] = 0 ;          // 并将其状态设置为未分配
        }
    }
}


// 主函数
int main ( int argc , char * argv[] ) {
    // 定义循环变量
    int i , j ;

    // 输入作业数以及人数Ｎ
    printf ( "请输入作业数：" ) ;
    scanf ( "%d" , &n ) ;

    // 输入每一个任务对于每一个工人的费用
    for ( i = 1 ; i <= n ; i++ ) {
        printf ( "请输入第%d个工人的工作费用：\n" , i ) ;
        for ( j = 1 ; j <= n ; j++ ) {
            scanf ( "%d" , &a[i][j] ) ;
        }
    }

    // 初始化变量
    sum = 0 ;
    best = -1 ;

    Process ( 1 ) ;

    printf ( "最小总费用为：%d\n", best ) ;
    printf ( "作业" ) ;
    for ( i = 1 ; i <= n ; i++ ) {
        printf ( "%3d", i ) ;
    }
   
    // 根据ｄ数组输出最优的任务分配结果。
    printf ( "分别分给第" ) ;
    for ( i = 1 ; i <= n ; i++ ) {
        printf ( "%3d" , d[i] ) ;
    }
    puts ( "个工人！\n 此时作业分配完毕！\n" ) ;

    return 0;
}
