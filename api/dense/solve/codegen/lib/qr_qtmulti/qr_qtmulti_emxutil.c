#include "qr_qtmulti.h"
#include "m2c.h"
#include "qr_qtmulti_emxutil.h"

static void emxFreeStruct_cell_wrap_0(cell_wrap_0 *pStruct);
static void emxInitStruct_cell_wrap_0(cell_wrap_0 *pStruct);
static void emxFreeStruct_cell_wrap_0(cell_wrap_0 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

static void emxInitStruct_cell_wrap_0(cell_wrap_0 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 2);
}

void emxFreeMatrix_cell_wrap_0(cell_wrap_0 pMatrix[2])
{
  int i;
  for (i = 0; i < 2; i++) {
    emxFreeStruct_cell_wrap_0(&pMatrix[i]);
  }
}

void emxInitMatrix_cell_wrap_0(cell_wrap_0 pMatrix[2])
{
  int i;
  for (i = 0; i < 2; i++) {
    emxInitStruct_cell_wrap_0(&pMatrix[i]);
  }
}

