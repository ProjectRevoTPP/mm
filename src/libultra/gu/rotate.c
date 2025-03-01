#include "global.h"

void guRotateF(float m[4][4], float a, float x, float y, float z) {
    static float D_80097F90 = 0.017453292; // TODO this is PI / 180.0, we should define pi somewhere
    float sine;
    float cosine;
    float ab;
    float bc;
    float ca;
    float t;
    float xs;
    float ys;
    float zs;

    guNormalize(&x, &y, &z);

    a = a * D_80097F90;

    sine = __sinf(a);
    cosine = __cosf(a);

    ab = x * y * (1 - cosine);
    bc = y * z * (1 - cosine);
    ca = z * x * (1 - cosine);

    guMtxIdentF(m);

    xs = x * sine;
    ys = y * sine;
    zs = z * sine;

    t = x * x;
    m[0][0] = (1 - t) * cosine + t;
    m[2][1] = bc - xs;
    m[1][2] = bc + xs;
    t = y * y;
    m[1][1] = (1 - t) * cosine + t;
    m[2][0] = ca + ys;
    m[0][2] = ca - ys;
    t = z * z;
    m[2][2] = (1 - t) * cosine + t;
    m[1][0] = ab - zs;
    m[0][1] = ab + zs;
}

void guRotate(Mtx* m, float a, float x, float y, float z) {
    float mf[4][4];
    guRotateF(mf, a, x, y, z);
    guMtxF2L(mf, m);
}
