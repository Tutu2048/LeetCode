#include  "../normal.h"
/*����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
ʾ�� 1:

����: nums = [1,3,5,6], target = 5
���: 2
ʾ�� 2:

����: nums = [1,3,5,6], target = 2
���: 1
ʾ�� 3:

����: nums = [1,3,5,6], target = 7
���: 4
�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int left = 0,right = nums.size()-1;
        int mid= (left + right)/2;
        while(left <= right) {
            if (target == nums[mid]) return mid;
            if(target <nums[mid]) right = mid-1;
            else left = mid+1;
            mid = (left + right)/2;
        }
        return left;
    }
};
int main() {
    Solution test;
    vector<int>  v{1,3,5,6};
    cout << test.searchInsert(v,5) << endl;
    cout << test.searchInsert(v,2) << endl;
    cout << test.searchInsert(v,7) << endl;

}