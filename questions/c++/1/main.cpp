//http://cppstudio.com/post/1328/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    multiset<int> a;
    for(auto item: nums1){
        a.insert(item);
    }
    for(auto item: nums1){
        a.insert(item);
    }
    return a.count(a.max_size() / 2)
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
