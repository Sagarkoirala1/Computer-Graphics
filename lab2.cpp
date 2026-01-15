 #include <stdio.h>
#include <graphics.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, k, dx, dy, x, y;

    // 1. Get input in the console window FIRST
    printf("Enter the coordinates of first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    // 2. Initialize graphics after getting input
    initgraph(&gd, &gm, (char*)"");

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    x = x1;
    y = y1;

    putpixel(x, y, WHITE);

    if (dx >= dy) {
        k = 2 * dy - dx;
        for (int i = 0; i < dx; i++) {
            if (k < 0) {
                x = x + 1;
                k = k + 2 * dy;
            } else {
                x = x + 1;
                y = y + 1;
                k = k + 2 * dy - 2 * dx;
            }
            putpixel(x, y, WHITE);
            delay(50); // Reduced delay for smoother drawing
        }
    } else {
        k = 2 * dx - dy;
        for (int i = 0; i < dy; i++) {
            if (k < 0) {
                y = y + 1;
                k = k + 2 * dx;
            } else {
                y = y + 1;
                x = x + 1;
                k = k + 2 * dx - 2 * dy;
            }
            putpixel(x, y, WHITE);
            delay(50);
        }
    }

    printf("\nDrawing complete. Press any key in the graphics window to exit.");
    getch();
    closegraph();
    return 0;
}