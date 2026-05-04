#include <stdio.h>
#include <string.h>

int main() {
    char str1[100005];
    printf("Please enter a string:");
    scanf("%s", str1);

    int n = strlen(str1);
    
    char t[200005];
    strcpy(t, str1);
    strcat(t, str1);

    int freq[26] = {0};
    int left = 0;
    int sum = 0, maxSum = 0;

    for (int right = 0; right < 2 * n; right++) {

        int curr = t[right] - 'a';   
        while (freq[curr] > 0) {
            int l = t[left] - 'a';
            sum -= (l + 1);
            freq[l]--;
            left++;
        }

        freq[curr]++;
        sum += (curr + 1);
        if (right - left + 1 > n) {
            int l = t[left] - 'a';
            sum -= (l + 1);
            freq[l]--;
            left++;
        }
        if (sum > maxSum)
            maxSum = sum;
    }

    printf("The maximum possible sum of character values is : %d\n", maxSum);
    return 0;
}
