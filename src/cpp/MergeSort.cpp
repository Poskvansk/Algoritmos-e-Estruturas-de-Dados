#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int>& nums);

vector<int> merge(vector<int> arr1, vector<int> arr2) {

    vector<int> result = vector<int>();

    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        }
        else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    while(i < arr1.size()) {
        result.push_back(arr1[i]);
        i++;
    }

    while(j < arr2.size()) {
        result.push_back(arr2[j]);
        j++;
    }

    return result;
}

vector<int> merge_sort(vector<int>& nums) {

    if(nums.size() <= 1) return nums;

    vector<int> left = vector<int>(nums.begin(), nums.begin() + nums.size()/2);
    vector<int> right = vector<int>(nums.begin() + nums.size()/2, nums.end());

    left = merge_sort(left);
    right = merge_sort(right);

    vector<int> result = merge(left, right);

    return result;
}

void print_vector(vector<int>& nums) {

    for (size_t i = 0; i < nums.size(); i++) {
        if (i == nums.size() - 1) {
            cout << nums[i] << endl;
        }
        else {
            cout << nums[i] << ", ";
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    
    vector<int> v1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> v2 = {8, 3, 25, 5, 11, 22, 21, 27, 26, 10};

    cout << "Antes da ordenação: " << endl;
    print_vector(v1);
    print_vector(v2);

    v1 = merge_sort(v1);
    v2 = merge_sort(v2);
    
    cout << "Após ordenação: " << endl;
    print_vector(v1);
    print_vector(v2);

    return 0;
}
