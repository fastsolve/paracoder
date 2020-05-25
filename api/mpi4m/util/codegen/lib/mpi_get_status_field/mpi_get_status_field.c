#include "mpi_get_status_field.h"
#include "m2c.h"
#include "mpi.h"

static void b_m2c_error(const emxArray_char_T *varargin_3);
static MPI_Status m2c_castdata(const emxArray_uint8_T *data);
static void m2c_error(const emxArray_char_T *varargin_3);
static void b_m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error("mpi_get_status_field:UnknownField", "Unknown field name %s\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static MPI_Status m2c_castdata(const emxArray_uint8_T *data)
{
  return *(MPI_Status*)(&data->data[0]);
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error("m2c_opaque_obj:WrongInput",
            "Incorrect data type %s. Expected MPI_Status.\n",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

int mpi_get_status_field(const struct0_T *stat, const emxArray_char_T *field)
{
  int output;
  boolean_T p;
  int k;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_char_T *b_stat;
  int i;
  static const char cv[10] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u', 's'
  };

  MPI_Status t_stat;
  const MPI_Status * stat_ptr;
  int exitg2;
  static const char cv1[6] = { 's', 'o', 'u', 'r', 'c', 'e' };

  static const char cv2[10] = { 'M', 'P', 'I', '_', 'S', 'O', 'U', 'R', 'C', 'E'
  };

  static const char cv3[3] = { 't', 'a', 'g' };

  static const char cv4[7] = { 'M', 'P', 'I', '_', 'T', 'A', 'G' };

  static const char cv5[5] = { 'e', 'r', 'r', 'o', 'r' };

  static const char cv6[9] = { 'M', 'P', 'I', '_', 'E', 'R', 'R', 'O', 'R' };

  p = (stat->type->size[1] == 10);
  if (p && (stat->type->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(stat->type->data[k] == cv[k])) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  b_p = (int)p;
  emxInit_char_T(&b_stat, 2);
  if (!b_p) {
    i = b_stat->size[0] * b_stat->size[1];
    b_stat->size[0] = 1;
    b_stat->size[1] = stat->type->size[1] + 1;
    emxEnsureCapacity_char_T(b_stat, i);
    k = stat->type->size[1];
    for (i = 0; i < k; i++) {
      b_stat->data[i] = stat->type->data[i];
    }

    b_stat->data[stat->type->size[1]] = '\x00';
    m2c_error(b_stat);
  }

  t_stat = m2c_castdata(stat->data);
  stat_ptr = (&t_stat);
  b_p = false;
  if (field->size[1] == 6) {
    k = 0;
    do {
      exitg2 = 0;
      if (k < 6) {
        if (field->data[k] != cv1[k]) {
          exitg2 = 1;
        } else {
          k++;
        }
      } else {
        b_p = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }

  if (b_p) {
    output = stat_ptr->MPI_SOURCE;
  } else {
    b_p = false;
    if (field->size[1] == 10) {
      k = 0;
      do {
        exitg2 = 0;
        if (k < 10) {
          if (field->data[k] != cv2[k]) {
            exitg2 = 1;
          } else {
            k++;
          }
        } else {
          b_p = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }

    if (b_p) {
      output = stat_ptr->MPI_SOURCE;
    } else {
      b_p = false;
      if (field->size[1] == 3) {
        k = 0;
        do {
          exitg2 = 0;
          if (k < 3) {
            if (field->data[k] != cv3[k]) {
              exitg2 = 1;
            } else {
              k++;
            }
          } else {
            b_p = true;
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }

      if (b_p) {
        output = stat_ptr->MPI_TAG;
      } else {
        b_p = false;
        if (field->size[1] == 7) {
          k = 0;
          do {
            exitg2 = 0;
            if (k < 7) {
              if (field->data[k] != cv4[k]) {
                exitg2 = 1;
              } else {
                k++;
              }
            } else {
              b_p = true;
              exitg2 = 1;
            }
          } while (exitg2 == 0);
        }

        if (b_p) {
          output = stat_ptr->MPI_TAG;
        } else {
          b_p = false;
          if (field->size[1] == 5) {
            k = 0;
            do {
              exitg2 = 0;
              if (k < 5) {
                if (field->data[k] != cv5[k]) {
                  exitg2 = 1;
                } else {
                  k++;
                }
              } else {
                b_p = true;
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }

          if (b_p) {
            output = stat_ptr->MPI_ERROR;
          } else {
            b_p = false;
            if (field->size[1] == 9) {
              k = 0;
              do {
                exitg2 = 0;
                if (k < 9) {
                  if (field->data[k] != cv6[k]) {
                    exitg2 = 1;
                  } else {
                    k++;
                  }
                } else {
                  b_p = true;
                  exitg2 = 1;
                }
              } while (exitg2 == 0);
            }

            if (b_p) {
              output = stat_ptr->MPI_ERROR;
            } else {
              i = b_stat->size[0] * b_stat->size[1];
              b_stat->size[0] = 1;
              b_stat->size[1] = field->size[1] + 1;
              emxEnsureCapacity_char_T(b_stat, i);
              k = field->size[1];
              for (i = 0; i < k; i++) {
                b_stat->data[i] = field->data[i];
              }

              b_stat->data[field->size[1]] = '\x00';
              b_m2c_error(b_stat);
              output = -1;
            }
          }
        }
      }
    }
  }

  emxFree_char_T(&b_stat);

  return output;
}

void mpi_get_status_field_initialize(void)
{
}

void mpi_get_status_field_terminate(void)
{
}
