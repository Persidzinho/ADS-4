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
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int lval = arr[left];
      int rval = arr[right];
      int cntL = 0, cntR = 0;
      while (left < len && arr[left] == lval) { ++cntL; ++left; }
      while (right >= 0 && arr[right] == rval) { ++cntR; --right; }
      if (lval == rval)
        count += cntL * (cntL - 1) / 2;
      else
        count += cntL * cntR;
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
    int lb = i + 1, ub = len;
    while (lb < ub) {
      int mid = lb + (ub - lb) / 2;
      if (arr[mid] < target) lb = mid + 1;
      else ub = mid;
    }
    int low = lb;
    lb = i + 1; ub = len;
    while (lb < ub) {
      int mid = lb + (ub - lb) / 2;
      if (arr[mid] <= target) lb = mid + 1;
      else ub = mid;
    }
    int high = lb;
    count += (high - low);
  }
  return count;
}
