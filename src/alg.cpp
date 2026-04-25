// Copyright 2021 NNTU-CS
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
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] < target) {
        left = mid + 1;
      } else if (arr[mid] > target) {
        right = mid - 1;
      } else {
        int l = mid;
        while (l >= i + 1 && arr[l] == target) {
          --l;
        }
        int r = mid;
        while (r < len && arr[r] == target) {
          ++r;
        }
        count += (r - l - 1);
        break;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int lb = i + 1;
    int ub = len;
    while (lb < ub) {
      int mid = lb + (ub - lb) / 2;
      if (arr[mid] < target) {
        lb = mid + 1;
      } else {
        ub = mid;
      }
    }
    int low = lb;
    lb = i + 1;
    ub = len;
    while (lb < ub) {
      int mid = lb + (ub - lb) / 2;
      if (arr[mid] <= target) {
        lb = mid + 1;
      } else {
        ub = mid;
      }
    }
    int high = lb;
    count += (high - low);
  }
  return count;
}
