// Copyright 2021 NNTU-CS
#include "alg.h"

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            int leftVal = arr[left];
            int rightVal = arr[right];
            int leftCnt = 0;
            int rightCnt = 0;

            while (left + leftCnt <= right && arr[left + leftCnt] == leftVal) {
                ++leftCnt;
            }
            while (right - rightCnt >= left && arr[right - rightCnt] == rightVal) {
                ++rightCnt;
            }

            count += leftCnt * rightCnt;
            left += leftCnt;
            right -= rightCnt;
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];

        int left = i + 1;
        int right = len - 1;
        int first = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (first != -1) {
            int last = first;
            left = first;
            right = len - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) {
                    last = mid;
                    left = mid + 1;
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            count += (last - first + 1);
            while (i + 1 < len && arr[i] == arr[i + 1]) {
                ++i;
            }
        }
    }
    return count;
}
