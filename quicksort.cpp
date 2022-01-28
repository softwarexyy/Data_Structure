#include <iostream>

using namespace std;

const int SIZE = 17;
// Debug
void printarr(int arr[], int nums) {
	for (int i = 0; i < nums; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << endl;
}
void qsort_swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

// 对arr从begin开始到end结束排序(end指向尾后元素)
void qsort(int arr[], int begin, int end) {
	if (begin >= end || begin == end - 1) {
		return;
	}

	int pivot = arr[begin];		// 选中第一个元素
	// 比pivot大的移动到后面，比pivot小的移动到后面
	int left = begin + 1;
	int right = end - 1;
	int mid = 0;
	while (left < right) {
		while (left < right && arr[left] < pivot) {
			left++;
		}
		while (left < right && arr[right] >= pivot) {
			right--;
		}
		if (left != right) {
			qsort_swap(arr[left], arr[right]);
		}
	}
	// 此时 left == right，单趟结束
	if (arr[left] < pivot) {
		qsort_swap(arr[begin], arr[left]);
		mid = left;
	} else {
		qsort_swap(arr[begin], arr[left-1]);
		mid = left - 1;
	}

	// 从这里递归
	qsort(arr, begin, mid);
	qsort(arr, mid+1, end);
}

int main() {
	int arr[SIZE] = {
		3,1,1,1,5,6,7,8,4,2,10,11,2,45,12,7,1
	};	
	qsort(arr, 0, SIZE);
	printarr(arr, SIZE);
	return 0;
}


