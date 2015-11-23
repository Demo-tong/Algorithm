/* 0_1问题的三维,即在两个约束条件的约束下 */
#include<stdio.h>  
#include<stdlib.h>  
#include<iostream>  
#include<queue>  
#include<climits>  
#include<cstring>  

using namespace std;  

// 背包总容量
int c = 5 ;
// 背包总体积
int t = 10 ;
// 每一个物品的重量
int w[] = { 0 , 2 , 3 , 1 , 4 } ;  
// 每一个物品的体积
int s[] = { 0 , 4 , 5 , 7 , 8 } ;
// 每一个物品的价值
int v[] = { 0 , 8 , 3 , 2 , 4 } ;
// 物品的状态
int x[5];  


/* 0-1背包问题 */
void package0_1 ( int m[][11][11] )   
{  
    // 采用从底到顶的顺序来设置m[i][j][k]的值  
    int i , j , k ;
    // 首先分析最后一个物品
    for ( j = 0 ; j <= c ; j++ ) {
        for ( k = 0 ; k <= t ; k++ ) {
            if ( w[4] <= j && s[4] <= k ) {
                /* 重量和体积同时满足条件,则放入 */
                m[4][j][k] = v[4] ;
            } else {
                /* 任何一个不满足,则不放入 */
                m[4][j][k] = 0 ;
            }
        }
    }

    //对剩下的n-1个物品进行放置。  
    for( i = 3 ; i >= 1 ; i--) {
        for(int j = 0 ; j <= c ; j++) { 
            for ( k = 0 ; k <= t ; k++ ) {
                if ( w[i] <= j && s[i] <= k ) {
                    /* 重量和体积同时满足条件 */
                    m[i][j][k] = ( m[i+1][j][k] > v[i]+m[i+1][j-w[i]][k-s[i]] ) ? m[i+1][j][k] : v[i]+m[i+1][j-w[i]][k-s[i]] ;
                }
                else {
                    m[i][j][k] = m[i+1][j][k] ;
                }
            }
        }  
    }
}


void answer ( int m[][11][11] )
{  
    int i , j = c , k = t ;  

    // 遍历m数组,从第一个货物遍历,判断是否装入
    for ( i = 1 ; i <= 3 ; i++ ) { 
        if ( m[i][j][k] == m[i+1][j][k] ) { // 如果当前物品的价值与下一个物品价值相等,说明没有装i物品
            x[i] = 0;  
        }
        else { // 否则装进去
            x[i] = 1;  
            j = j - w[i];  
            k = k - s[i] ;
        }      
    }
    // 如果n物品在当前剩余容量j下非零,则表示装入该物品
    x[4] = m[i][j][k] ? 1 : 0 ;   
}

// 主函数
int main()  
{  
    // 5个物品,总重量为10,总体积为10
    // m数组分析中存储剩余空间为j时,当前的最大价值
    int m[5][11][11]={0};  // 初始化为0

    // 分析并存储m数组
    package0_1 ( m ) ;  

    
    // 具体的装载信息
    answer(m);  

    // 输出最优解
    cout << "The best answer is:\n";  
    for ( int i = 1 ; i <= 4 ; i++ ) { 
        cout << x[i] << " ";  
    }
    std::cout << std::endl ;

    return 0;  
} 
