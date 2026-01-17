#include <graphics.h>
#include <stdio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    float x1, y1, x2, y2;
    float dx, dy, x, y, steps, xinc, yinc;
    int i;

    initgraph(&gd, &gm, (char*)"");

    printf("Enter starting point (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter ending point (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    xinc = dx / steps;
    yinc = dy / steps;

    x = x1;
    y = y1;

    for (i = 0; i <= steps; i++) {
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
        x += xinc;
        y += yinc;
        delay(20);
    }

    getch();
    closegraph();
    return 0;
}
