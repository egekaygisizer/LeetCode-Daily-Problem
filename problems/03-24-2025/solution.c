#include <stdio.h>
#include <stdlib.h>

// compare func (for qsort)
int compare(const void *a, const void *b) {
    int* meeting1 = *(int**)a;
    int* meeting2 = *(int**)b;

    return meeting1[0] == meeting2[0] ? meeting1[1]-meeting2[1] : meeting1[0]-meeting2[0];
}

int countDays(int days, int** meetings, int meetingsSize, int* meetingsColSize) {
    qsort(meetings, meetingsSize, sizeof(int*), compare);

    int idx = 0, start = meetings[idx][0], end = meetings[idx++][1];        

    while (idx < meetingsSize) {
        if (meetings[idx][0] > end) {
            days -= (end-start+1);
            start = meetings[idx][0];
            end = meetings[idx][1];
        } else
            end = end > meetings[idx][1] ? end : meetings[idx][1];
        
        ++idx;
    }

    return days - (end-start+1);
}