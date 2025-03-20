// 2025-03-20 10:06:51
// 295 数据流的中位数 
//中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。 
// 例如 arr = [2,3,4] 的中位数是 3 。
// 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。 
// 
//
// 实现 MedianFinder 类: 
// MedianFinder() 初始化 MedianFinder 对象。 
// void addNum(int num) 将数据流中的整数 num 添加到数据结构中。 
// double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10⁻⁵ 以内的答案将被接受。 
// 
//
// 示例 1： 
//输入
//["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
//[[], [1], [2], [], [3], []]
//输出
//[null, null, null, 1.5, null, 2.0]
//解释
//MedianFinder medianFinder = new MedianFinder();
//medianFinder.addNum(1);    // arr = [1]
//medianFinder.addNum(2);    // arr = [1, 2]
//medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
//medianFinder.addNum(3);    // arr[1, 2, 3]
//medianFinder.findMedian(); // return 2.0 
//
// 提示: 
// -10⁵ <= num <= 10⁵ 
// 在调用 findMedian 之前，数据结构中至少有一个元素 
// 最多 5 * 10⁴ 次调用 addNum 和 findMedian 
// Related Topics 设计 双指针 数据流 排序 堆（优先队列） 👍 1098 👎 0




#include "../normal.h"
//leetcode submit region begin(Prohibit modification and deletion)
class MedianFinder {
public:
    MedianFinder()  {
    }

    void addNum(int num) {
        if(maxNums.empty()||num<=maxNums.top()){
            maxNums.push(num);
        }else{
            minNums.push(num);
        }

        if(maxNums.size()> minNums.size()+1){
            int tmp = maxNums.top();
            maxNums.pop();
            minNums.push(tmp);
        }else if(minNums.size()>maxNums.size()){
            int tmp = minNums.top();
            minNums.pop();
            maxNums.push(tmp);
        }
    }
    
    double findMedian() {
        if(maxNums.empty()){
            return 0;
        }
        if((maxNums.size()+minNums.size())%2 ==1){
            return maxNums.top();
        }
        return (maxNums.top()+minNums.top())/2.0;
    }
    void print(){
        cout<<"maxNums:";
        priority_queue<int,vector<int>,std::less<int>> tmp = maxNums;
        while(!tmp.empty()){
            cout<<tmp.top()<<" ";
            tmp.pop();
        }
        cout<<endl;
        cout<<"minNums:";
        priority_queue<int,vector<int>,std::greater<int>> tmp2 = minNums;
        while(!tmp2.empty()){
            cout<<tmp2.top()<<" ";
            tmp2.pop();
        }
        cout<<endl;
    }
private:
    //大于中位数的放min，小于中位数的放max,中位数放在max的top，或者（max+min）/2.0
    priority_queue<int,vector<int>,std::less<int>> maxNums;//升序,大顶堆
    priority_queue<int,vector<int>,std::greater<int>> minNums;//降序,小顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//leetcode submit region end(Prohibit modification and deletion)

int main(){

    // [[],[-1],[],[-2],[],[-3],[],[-4],[],[-5],[]]

    MedianFinder* obj = new MedianFinder();
    cout<<obj->findMedian()<<endl;
    obj->addNum(-1);
    cout<<obj->findMedian()<<endl;
    obj->addNum(-2);
    cout<<obj->findMedian()<<endl;
    obj->addNum(-3);
    cout<<obj->findMedian()<<endl;
    obj->addNum(-4);
    cout<<obj->findMedian()<<endl;
    obj->addNum(-5);
    cout<<obj->findMedian()<<endl;
    obj->print();
}