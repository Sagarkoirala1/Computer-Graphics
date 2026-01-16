#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void drawCircle(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, r;
    int x = 0, y, p;

    printf("Enter center (x y): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter radius: ");
    scanf("%d", &r);

initgraph(&gd, &gm, (char *)"");


    y = r;
    p = 1 - r;

    while (x <= y) {
        drawCircle(x1, y1, x, y);
        delay(30);

        x++;
        if (p < 0)
            p = p + 2 * x + 1;
        else {
            y--;
            p = p + 2 * x - 2 * y + 1;
        }
    }

    getch();
    closegraph();
    return 0;
}
