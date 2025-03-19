/*
* 给定一个整数 n ，返回 n! 结果中尾随零的数量。
提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1
*
示例 1：
输入：n = 3
输出：0
解释：3! = 6 ，不含尾随 0
*
示例 2：
输入：n = 5
输出：1
解释：5! = 120 ，有一个尾随 0
*
示例 3：
输入：n = 0
输出：0

提示：
0 <= n <= 10^4
进阶：你可以设计并实现对数时间复杂度的算法来解决此问题吗？
* */

#include "../normal.h"
class Solution {
public:
    int trailingZeroes(int n) {
        //思路推导：
        //1、排除算出结果，再计算零的方式，因为即使是longlong也无法表示10^4的阶乘
        //2、阶乘后的值后面的零的个数，由乘了多少个10决定
        //3、10 =2*5 10的个数由有几对2*5的组合决定
        //4、因为是阶乘，所以2因子的个数必然比5多,所以阶乘后的值后面的零的个数由5因子的个数决定

        int numFive =0;
        for(int i=5;i<=n;) {
            int temp =i;
            while(temp%5==0) {
                temp /= 5;
                numFive++;
            }
            i+=5;
        }

        return numFive;
    }
};

int main() {
    Solution test;
    cout << test.trailingZeroes(1235);
    //还可以通过数学进行优化

}
