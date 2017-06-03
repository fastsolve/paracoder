#include "mpi_get_status_field.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxInitStruct_struct0_T(struct0_T *pStruct);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("mpi_get_status_field:UnknownField", "Unknown field name %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_uint8_T(&pStruct->data);
  emxFree_char_T(&pStruct->type);
}

static void emxInitStruct_struct0_T(struct0_T *pStruct)
{
  emxInit_uint8_T(&pStruct->data, 1);
  emxInit_char_T(&pStruct->type, 2);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i1;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i1 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, (int)sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Status.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

void emxDestroy_struct0_T(struct0_T emxArray)
{
  emxFreeStruct_struct0_T(&emxArray);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void emxInit_struct0_T(struct0_T *pStruct)
{
  emxInitStruct_struct0_T(pStruct);
}

int mpi_get_status_field(const struct0_T *stat, const emxArray_char_T *field)
{
  int output;
  boolean_T p;
  boolean_T b_p;
  int k;
  int exitg8;
  int i0;
  boolean_T exitg7;
  emxArray_char_T *b_stat;
  static const char cv0[10] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u', 's'
  };

  emxArray_uint8_T *data;
  MPI_Status t_stat;
  const MPI_Status * stat_ptr;
  emxArray_char_T *b_field;
  boolean_T guard1 = false;
  int exitg6;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  static const char cv1[6] = { 's', 'o', 'u', 'r', 'c', 'e' };

  int exitg5;
  static const char cv2[10] = { 'M', 'P', 'I', '_', 'S', 'O', 'U', 'R', 'C', 'E'
  };

  int exitg4;
  static const char cv3[3] = { 't', 'a', 'g' };

  int exitg3;
  static const char cv4[7] = { 'M', 'P', 'I', '_', 'T', 'A', 'G' };

  int exitg2;
  static const char cv5[5] = { 'e', 'r', 'r', 'o', 'r' };

  int exitg1;
  static const char cv6[9] = { 'M', 'P', 'I', '_', 'E', 'R', 'R', 'O', 'R' };

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg8 = 0;
    if (k < 2) {
      i0 = stat->type->size[k];
      if (i0 != 9 * k + 1) {
        exitg8 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg8 = 1;
    }
  } while (exitg8 == 0);

  if (b_p && (!(stat->type->size[1] == 0))) {
    k = 0;
    exitg7 = false;
    while ((!exitg7) && (k < 10)) {
      if (!(stat->type->data[k] == cv0[k])) {
        b_p = false;
        exitg7 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emxInit_char_T(&b_stat, 2);
    i0 = b_stat->size[0] * b_stat->size[1];
    b_stat->size[0] = 1;
    b_stat->size[1] = stat->type->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)b_stat, i0, (int)sizeof(char));
    k = stat->type->size[1];
    for (i0 = 0; i0 < k; i0++) {
      b_stat->data[b_stat->size[0] * i0] = stat->type->data[stat->type->size[0] *
        i0];
    }

    b_stat->data[b_stat->size[0] * stat->type->size[1]] = '\x00';
    m2c_error(b_stat);
    emxFree_char_T(&b_stat);
  }

  emxInit_uint8_T(&data, 1);
  i0 = data->size[0];
  data->size[0] = stat->data->size[0];
  emxEnsureCapacity((emxArray__common *)data, i0, (int)sizeof(unsigned char));
  k = stat->data->size[0];
  for (i0 = 0; i0 < k; i0++) {
    data->data[i0] = stat->data->data[i0];
  }

  t_stat = *(MPI_Status*)(&data->data[0]);
  stat_ptr = (&t_stat);
  p = false;
  emxFree_uint8_T(&data);
  if (field->size[1] == 6) {
    k = 0;
    do {
      exitg6 = 0;
      if (k + 1 < 7) {
        if (field->data[k] != cv1[k]) {
          exitg6 = 1;
        } else {
          k++;
        }
      } else {
        p = true;
        exitg6 = 1;
      }
    } while (exitg6 == 0);
  }

  emxInit_char_T(&b_field, 2);
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (p) {
    guard3 = true;
  } else {
    p = false;
    if (field->size[1] == 10) {
      k = 0;
      do {
        exitg5 = 0;
        if (k + 1 < 11) {
          if (field->data[k] != cv2[k]) {
            exitg5 = 1;
          } else {
            k++;
          }
        } else {
          p = true;
          exitg5 = 1;
        }
      } while (exitg5 == 0);
    }

    if (p) {
      guard3 = true;
    } else {
      p = false;
      if (field->size[1] == 3) {
        k = 0;
        do {
          exitg4 = 0;
          if (k + 1 < 4) {
            if (field->data[k] != cv3[k]) {
              exitg4 = 1;
            } else {
              k++;
            }
          } else {
            p = true;
            exitg4 = 1;
          }
        } while (exitg4 == 0);
      }

      if (p) {
        guard2 = true;
      } else {
        p = false;
        if (field->size[1] == 7) {
          k = 0;
          do {
            exitg3 = 0;
            if (k + 1 < 8) {
              if (field->data[k] != cv4[k]) {
                exitg3 = 1;
              } else {
                k++;
              }
            } else {
              p = true;
              exitg3 = 1;
            }
          } while (exitg3 == 0);
        }

        if (p) {
          guard2 = true;
        } else {
          p = false;
          if (field->size[1] == 5) {
            k = 0;
            do {
              exitg2 = 0;
              if (k + 1 < 6) {
                if (field->data[k] != cv5[k]) {
                  exitg2 = 1;
                } else {
                  k++;
                }
              } else {
                p = true;
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }

          if (p) {
            guard1 = true;
          } else {
            p = false;
            if (field->size[1] == 9) {
              k = 0;
              do {
                exitg1 = 0;
                if (k + 1 < 10) {
                  if (field->data[k] != cv6[k]) {
                    exitg1 = 1;
                  } else {
                    k++;
                  }
                } else {
                  p = true;
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
            }

            if (p) {
              guard1 = true;
            } else {
              i0 = b_field->size[0] * b_field->size[1];
              b_field->size[0] = 1;
              b_field->size[1] = field->size[1] + 1;
              emxEnsureCapacity((emxArray__common *)b_field, i0, (int)sizeof
                                (char));
              k = field->size[1];
              for (i0 = 0; i0 < k; i0++) {
                b_field->data[b_field->size[0] * i0] = field->data[field->size[0]
                  * i0];
              }

              b_field->data[b_field->size[0] * field->size[1]] = '\x00';
              b_m2c_error(b_field);
              output = -1;
            }
          }
        }
      }
    }
  }

  if (guard3) {
    output = stat_ptr->MPI_SOURCE;
  }

  if (guard2) {
    output = stat_ptr->MPI_TAG;
  }

  if (guard1) {
    output = stat_ptr->MPI_ERROR;
  }

  emxFree_char_T(&b_field);

  return output;
}

void mpi_get_status_field_initialize(void)
{
}

void mpi_get_status_field_terminate(void)
{
}
