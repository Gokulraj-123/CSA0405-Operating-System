#include<stdio.h>
#define MAX_PAGES 100
#define MAX_FRAMES 10

int pages[MAX_PAGES], frames[MAX_FRAMES], total_pages, total_frames, page_faults;

void initFrames() {
    for (int i = 0; i < total_frames; i++)
        frames[i] = -1;
}

int isPagePresent(int page) {
    for (int i = 0; i < total_frames; i++)
        if (frames[i] == page)
            return 1;
    return 0;
}

int getOptimalReplacement(int start_index) {
    int index = -1, farthest = start_index;
    for (int i = 0; i < total_frames; i++) {
        int j;
        for (j = start_index; j < total_pages; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == total_pages)
            return i;
    }
    return (index == -1) ? 0 : index;
}

void simulateOptimalPageReplacement() {
    initFrames();
    for (int i = 0; i < total_pages; i++) {
        if (!isPagePresent(pages[i])) {
            int index = getOptimalReplacement(i + 1);
            frames[index] = pages[i];
            printf("Page %d loaded into frame %d\n", pages[i], index);
            page_faults++;
        }
    }
}

int main() {
    printf("Enter total number of pages: ");
    scanf("%d", &total_pages);
    printf("Enter the page reference sequence:\n");
    for (int i = 0; i < total_pages; i++)
        scanf("%d", &pages[i]);
    printf("Enter total number of frames: ");
    scanf("%d", &total_frames);
    simulateOptimalPageReplacement();
    printf("Total Page Faults: %d\n", page_faults);
    return 0;
}
