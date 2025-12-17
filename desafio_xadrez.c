#include <stdio.h>

typedef struct { int x, y; } Pos;
typedef struct { int dx, dy; } Vec;

static void slide(Pos *p, Vec v, int steps, const char *label) {
    for (int i = 0; i < steps; i++) {
        p->x += v.dx; p->y += v.dy;
        printf("%s -> (%d,%d)\n", label, p->x, p->y);
    }
}

static void knight(Pos *p, Vec v, const char *label) {
    p->x += v.dx; p->y += v.dy;
    printf("%s -> (%d,%d)\n", label, p->x, p->y);
}

int main() {
    Pos bishop = {4,4}, rook = {4,4}, queen = {4,4}, kn = {4,4};

    slide(&bishop, (Vec){+1,+1}, 5, "Bispo NE");      // diagonal
    slide(&rook,   (Vec){+1, 0}, 5, "Torre E");       // horizontal
    slide(&queen,  (Vec){-1, 0}, 8, "Rainha W");      // horizontal

    knight(&kn, (Vec){+1,+2}, "Cavalo L");            // (dx,dy) do L
    return 0;
}
