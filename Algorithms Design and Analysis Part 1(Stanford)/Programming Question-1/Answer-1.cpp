#include <stdio.h>
#include <vector>
using namespace std;


long long int countInversion(vector<int> &data, vector<int> &tempData, int first, int last)
{
    if (first == last) {
        return 0;
    }
    int mid = (first + last) >> 1;
    long long int leftNum = countInversion(data, tempData, first, mid);
    long long int rightNum = countInversion(data, tempData, mid + 1, last);
    long long int splitNum = 0;
    int i = first, j = first, k = mid + 1;
    while (j <= mid && k <= last) {
        if (data[j] <= data[k]) {
            tempData[i++] = data[j++];
        }
        else {
            splitNum += mid - j + 1;
            tempData[i++] = data[k++];
        }
    }
    while (j <= mid) {
        tempData[i++] = data[j++];
    }
    while (k <= last) {
        tempData[i++] = data[k++];
    }
    for (int i = first; i <= last; ++i) {
        data[i] = tempData[i];
    }
    return leftNum + rightNum + splitNum;
}

long long int numOfInversion(vector<int> &data) {
    vector<int> tempData(data.size());
    return  countInversion(data, tempData, 0, data.size() - 1);
}

int main()
{
    freopen("f://IntegerArray.txt", "r", stdin);
    vector<int> data;
    int num;
    while (scanf("%d", &num) != EOF) {
        data.push_back(num);
    }
    long long int ans = numOfInversion(data);
    printf("%lld\n", ans);
    return 0;
}