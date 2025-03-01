#include "global.h"

void MtxConv_F2L(MatrixInternal* m1, MtxF* m2) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            s32 value = (m2->mf[i][j] * 0x10000);
            m1->intPart[i][j] = value >> 16;
            m1->fracPart[i][j] = value;
        }
    }
}

void MtxConv_L2F(MtxF* m1, MatrixInternal* m2) {
    guMtxL2F(m1, (Mtx*)m2);
}
