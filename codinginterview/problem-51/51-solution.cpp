// #include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int InversePairs(vector<int> data){
            if(data.size()==0){
                return 0;
            }
            long long count = 0;
            int start = 0;
            int end = int(data.size())-1;
            vector<int> data_tmp;
            for(auto iter=data.begin();iter != data.end();iter++){
                data_tmp.push_back(*iter);
            }
            count = InversePairs(data, data_tmp, 0, end);

            return count%1000000007;

        }    
    private:
        long long InversePairs(vector<int>& data, vector<int>& copy, int low, int high){
            if(low==high){
                copy[low] = data[low];
                return 0;
            }
            long long left;
            long long right;
            int length = (high-low)>>2; // half length
            left = InversePairs(copy, data, low, (low+(length)));
            right = InversePairs(copy, data, (low+(length)+1), high);
            int i = low+(length);
            int j = high;

            int copy_index = high;
            long long count = 0;
            while(i>=low && j>=(low+(length)+1)){
                if(data[i] > data[j]){
                    count += j-(low+(length));
                    copy[copy_index--] = data[i--];
                }
                else
                {
                    copy[copy_index--] = data[j--];
                }
            }

            for(;i>=low;i--){
                copy[copy_index--] = data[i];
            }
            for(;j>=(low+(length)+1);j--)
            {
                copy[copy_index--] = data[j];
            }
            return left+count+right;
        }
};

// auto 关键词是在声明时根据其初始化表达式自动推断其类型 