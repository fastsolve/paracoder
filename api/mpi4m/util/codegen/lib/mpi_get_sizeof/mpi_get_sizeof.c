#include "mpi_get_sizeof.h"
#include "m2c.h"
#include "mpi.h"

static boolean_T b_strcmp(const emxArray_char_T *a);
static boolean_T c_strcmp(const emxArray_char_T *a);
static boolean_T d_strcmp(const emxArray_char_T *a);
static boolean_T e_strcmp(const emxArray_char_T *a);
static boolean_T f_strcmp(const emxArray_char_T *a);
static boolean_T g_strcmp(const emxArray_char_T *a);
static boolean_T h_strcmp(const emxArray_char_T *a);
static boolean_T i_strcmp(const emxArray_char_T *a);
static boolean_T j_strcmp(const emxArray_char_T *a);
static boolean_T k_strcmp(const emxArray_char_T *a);
static boolean_T l_strcmp(const emxArray_char_T *a);
static void m2c_error(const emxArray_char_T *varargin_3);
static boolean_T m_strcmp(const emxArray_char_T *a);
static boolean_T n_strcmp(const emxArray_char_T *a);
static boolean_T o_strcmp(const emxArray_char_T *a);
static boolean_T p_strcmp(const emxArray_char_T *a);
static boolean_T b_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv0[7] = { 'R', 'e', 'q', 'u', 'e', 's', 't' };

  b_bool = false;
  if (a->size[1] == 7) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 8) {
        if (a->data[kstr] != cv0[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T c_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv1[6] = { 'S', 't', 'a', 't', 'u', 's' };

  b_bool = false;
  if (a->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 7) {
        if (a->data[kstr] != cv1[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T d_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv2[4] = { 'A', 'i', 'n', 't' };

  b_bool = false;
  if (a->size[1] == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 5) {
        if (a->data[kstr] != cv2[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T e_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv3[2] = { 'O', 'p' };

  b_bool = false;
  if (a->size[1] == 2) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 3) {
        if (a->data[kstr] != cv3[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T f_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv4[8] = { 'D', 'a', 't', 'a', 't', 'y', 'p', 'e' };

  b_bool = false;
  if (a->size[1] == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 9) {
        if (a->data[kstr] != cv4[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T g_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv5[6] = { 'D', 'O', 'U', 'B', 'L', 'E' };

  b_bool = false;
  if (a->size[1] == 6) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 7) {
        if (a->data[kstr] != cv5[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T h_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv6[4] = { '2', 'I', 'N', 'T' };

  b_bool = false;
  if (a->size[1] == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 5) {
        if (a->data[kstr] != cv6[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T i_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv7[5] = { 'F', 'L', 'O', 'A', 'T' };

  b_bool = false;
  if (a->size[1] == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 6) {
        if (a->data[kstr] != cv7[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T j_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv8[3] = { 'I', 'N', 'T' };

  b_bool = false;
  if (a->size[1] == 3) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 4) {
        if (a->data[kstr] != cv8[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T k_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv9[8] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D' };

  b_bool = false;
  if (a->size[1] == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 9) {
        if (a->data[kstr] != cv9[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T l_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv10[5] = { 'S', 'H', 'O', 'R', 'T' };

  b_bool = false;
  if (a->size[1] == 5) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 6) {
        if (a->data[kstr] != cv10[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static void m2c_error(const emxArray_char_T *varargin_3)
{
  emxArray_char_T *b_varargin_3;
  int i2;
  int loop_ub;
  emxInit_char_T(&b_varargin_3, 2);
  i2 = b_varargin_3->size[0] * b_varargin_3->size[1];
  b_varargin_3->size[0] = 1;
  b_varargin_3->size[1] = varargin_3->size[1];
  emxEnsureCapacity_char_T(b_varargin_3, i2);
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_varargin_3->data[i2] = varargin_3->data[i2];
  }

  M2C_error("mpi_get_sizeof:UnknownType", "Unknonw datatype %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static boolean_T m_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv11[14] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_',
    'S', 'H', 'O', 'R', 'T' };

  b_bool = false;
  if (a->size[1] == 14) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 15) {
        if (a->data[kstr] != cv11[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T n_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv12[4] = { 'C', 'H', 'A', 'R' };

  b_bool = false;
  if (a->size[1] == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 5) {
        if (a->data[kstr] != cv12[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T o_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv13[13] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_',
    'C', 'H', 'A', 'R' };

  b_bool = false;
  if (a->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 14) {
        if (a->data[kstr] != cv13[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

static boolean_T p_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv14[4] = { 'B', 'Y', 'T', 'E' };

  b_bool = false;
  if (a->size[1] == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr + 1 < 5) {
        if (a->data[kstr] != cv14[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return b_bool;
}

int mpi_get_sizeof(const emxArray_char_T *typename)
{
  int n;
  int i0;
  int i1;
  emxArray_char_T *b_typename;
  int loop_ub;
  n = 0;
  if (5 > typename->size[1]) {
    i0 = 0;
    i1 = 0;
  } else {
    i0 = 4;
    i1 = typename->size[1];
  }

  emxInit_char_T(&b_typename, 2);
  loop_ub = b_typename->size[0] * b_typename->size[1];
  b_typename->size[0] = 1;
  b_typename->size[1] = i1 - i0;
  emxEnsureCapacity_char_T(b_typename, loop_ub);
  loop_ub = i1 - i0;
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_typename->data[b_typename->size[0] * i1] = typename->data[i0 + i1];
  }

  if (b_strcmp(b_typename)) {
    n = sizeof(MPI_Request);
  } else {
    if (5 > typename->size[1]) {
      i0 = 0;
      i1 = 0;
    } else {
      i0 = 4;
      i1 = typename->size[1];
    }

    loop_ub = b_typename->size[0] * b_typename->size[1];
    b_typename->size[0] = 1;
    b_typename->size[1] = i1 - i0;
    emxEnsureCapacity_char_T(b_typename, loop_ub);
    loop_ub = i1 - i0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_typename->data[b_typename->size[0] * i1] = typename->data[i0 + i1];
    }

    if (c_strcmp(b_typename)) {
      n = sizeof(MPI_Status);
    } else {
      if (5 > typename->size[1]) {
        i0 = 0;
        i1 = 0;
      } else {
        i0 = 4;
        i1 = typename->size[1];
      }

      loop_ub = b_typename->size[0] * b_typename->size[1];
      b_typename->size[0] = 1;
      b_typename->size[1] = i1 - i0;
      emxEnsureCapacity_char_T(b_typename, loop_ub);
      loop_ub = i1 - i0;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_typename->data[b_typename->size[0] * i1] = typename->data[i0 + i1];
      }

      if (d_strcmp(b_typename)) {
        n = sizeof(MPI_Aint);
      } else {
        if (5 > typename->size[1]) {
          i0 = 0;
          i1 = 0;
        } else {
          i0 = 4;
          i1 = typename->size[1];
        }

        loop_ub = b_typename->size[0] * b_typename->size[1];
        b_typename->size[0] = 1;
        b_typename->size[1] = i1 - i0;
        emxEnsureCapacity_char_T(b_typename, loop_ub);
        loop_ub = i1 - i0;
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_typename->data[b_typename->size[0] * i1] = typename->data[i0 + i1];
        }

        if (e_strcmp(b_typename)) {
          n = sizeof(MPI_Op);
        } else {
          if (5 > typename->size[1]) {
            i0 = 0;
            i1 = 0;
          } else {
            i0 = 4;
            i1 = typename->size[1];
          }

          loop_ub = b_typename->size[0] * b_typename->size[1];
          b_typename->size[0] = 1;
          b_typename->size[1] = i1 - i0;
          emxEnsureCapacity_char_T(b_typename, loop_ub);
          loop_ub = i1 - i0;
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_typename->data[b_typename->size[0] * i1] = typename->data[i0 + i1];
          }

          if (f_strcmp(b_typename)) {
            n = sizeof(MPI_Datatype);
          } else {
            if (5 > typename->size[1]) {
              i0 = 0;
              i1 = 0;
            } else {
              i0 = 4;
              i1 = typename->size[1];
            }

            loop_ub = b_typename->size[0] * b_typename->size[1];
            b_typename->size[0] = 1;
            b_typename->size[1] = i1 - i0;
            emxEnsureCapacity_char_T(b_typename, loop_ub);
            loop_ub = i1 - i0;
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_typename->data[b_typename->size[0] * i1] = typename->data[i0 +
                i1];
            }

            if (g_strcmp(b_typename)) {
              n = 8;
            } else {
              if (5 > typename->size[1]) {
                i0 = 0;
                i1 = 0;
              } else {
                i0 = 4;
                i1 = typename->size[1];
              }

              loop_ub = b_typename->size[0] * b_typename->size[1];
              b_typename->size[0] = 1;
              b_typename->size[1] = i1 - i0;
              emxEnsureCapacity_char_T(b_typename, loop_ub);
              loop_ub = i1 - i0;
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_typename->data[b_typename->size[0] * i1] = typename->data[i0 +
                  i1];
              }

              if (h_strcmp(b_typename)) {
                n = 8;
              } else {
                if (5 > typename->size[1]) {
                  i0 = 0;
                  i1 = 0;
                } else {
                  i0 = 4;
                  i1 = typename->size[1];
                }

                loop_ub = b_typename->size[0] * b_typename->size[1];
                b_typename->size[0] = 1;
                b_typename->size[1] = i1 - i0;
                emxEnsureCapacity_char_T(b_typename, loop_ub);
                loop_ub = i1 - i0;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  b_typename->data[b_typename->size[0] * i1] = typename->data[i0
                    + i1];
                }

                if (i_strcmp(b_typename)) {
                  n = 4;
                } else {
                  if (5 > typename->size[1]) {
                    i0 = 0;
                    i1 = 0;
                  } else {
                    i0 = 4;
                    i1 = typename->size[1];
                  }

                  loop_ub = b_typename->size[0] * b_typename->size[1];
                  b_typename->size[0] = 1;
                  b_typename->size[1] = i1 - i0;
                  emxEnsureCapacity_char_T(b_typename, loop_ub);
                  loop_ub = i1 - i0;
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_typename->data[b_typename->size[0] * i1] = typename->
                      data[i0 + i1];
                  }

                  if (j_strcmp(b_typename)) {
                    n = 4;
                  } else {
                    if (5 > typename->size[1]) {
                      i0 = 0;
                      i1 = 0;
                    } else {
                      i0 = 4;
                      i1 = typename->size[1];
                    }

                    loop_ub = b_typename->size[0] * b_typename->size[1];
                    b_typename->size[0] = 1;
                    b_typename->size[1] = i1 - i0;
                    emxEnsureCapacity_char_T(b_typename, loop_ub);
                    loop_ub = i1 - i0;
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      b_typename->data[b_typename->size[0] * i1] =
                        typename->data[i0 + i1];
                    }

                    if (k_strcmp(b_typename)) {
                      n = 4;
                    } else {
                      if (5 > typename->size[1]) {
                        i0 = 0;
                        i1 = 0;
                      } else {
                        i0 = 4;
                        i1 = typename->size[1];
                      }

                      loop_ub = b_typename->size[0] * b_typename->size[1];
                      b_typename->size[0] = 1;
                      b_typename->size[1] = i1 - i0;
                      emxEnsureCapacity_char_T(b_typename, loop_ub);
                      loop_ub = i1 - i0;
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_typename->data[b_typename->size[0] * i1] =
                          typename->data[i0 + i1];
                      }

                      if (l_strcmp(b_typename)) {
                        n = 2;
                      } else {
                        if (5 > typename->size[1]) {
                          i0 = 0;
                          i1 = 0;
                        } else {
                          i0 = 4;
                          i1 = typename->size[1];
                        }

                        loop_ub = b_typename->size[0] * b_typename->size[1];
                        b_typename->size[0] = 1;
                        b_typename->size[1] = i1 - i0;
                        emxEnsureCapacity_char_T(b_typename, loop_ub);
                        loop_ub = i1 - i0;
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          b_typename->data[b_typename->size[0] * i1] =
                            typename->data[i0 + i1];
                        }

                        if (m_strcmp(b_typename)) {
                          n = 2;
                        } else {
                          if (5 > typename->size[1]) {
                            i0 = 0;
                            i1 = 0;
                          } else {
                            i0 = 4;
                            i1 = typename->size[1];
                          }

                          loop_ub = b_typename->size[0] * b_typename->size[1];
                          b_typename->size[0] = 1;
                          b_typename->size[1] = i1 - i0;
                          emxEnsureCapacity_char_T(b_typename, loop_ub);
                          loop_ub = i1 - i0;
                          for (i1 = 0; i1 < loop_ub; i1++) {
                            b_typename->data[b_typename->size[0] * i1] =
                              typename->data[i0 + i1];
                          }

                          if (n_strcmp(b_typename)) {
                            n = 1;
                          } else {
                            if (5 > typename->size[1]) {
                              i0 = 0;
                              i1 = 0;
                            } else {
                              i0 = 4;
                              i1 = typename->size[1];
                            }

                            loop_ub = b_typename->size[0] * b_typename->size[1];
                            b_typename->size[0] = 1;
                            b_typename->size[1] = i1 - i0;
                            emxEnsureCapacity_char_T(b_typename, loop_ub);
                            loop_ub = i1 - i0;
                            for (i1 = 0; i1 < loop_ub; i1++) {
                              b_typename->data[b_typename->size[0] * i1] =
                                typename->data[i0 + i1];
                            }

                            if (o_strcmp(b_typename)) {
                              n = 1;
                            } else {
                              if (5 > typename->size[1]) {
                                i0 = 0;
                                i1 = 0;
                              } else {
                                i0 = 4;
                                i1 = typename->size[1];
                              }

                              loop_ub = b_typename->size[0] * b_typename->size[1];
                              b_typename->size[0] = 1;
                              b_typename->size[1] = i1 - i0;
                              emxEnsureCapacity_char_T(b_typename, loop_ub);
                              loop_ub = i1 - i0;
                              for (i1 = 0; i1 < loop_ub; i1++) {
                                b_typename->data[b_typename->size[0] * i1] =
                                  typename->data[i0 + i1];
                              }

                              if (p_strcmp(b_typename)) {
                                n = 1;
                              } else {
                                i0 = b_typename->size[0] * b_typename->size[1];
                                b_typename->size[0] = 1;
                                b_typename->size[1] = typename->size[1] + 1;
                                emxEnsureCapacity_char_T(b_typename, i0);
                                loop_ub = typename->size[1];
                                for (i0 = 0; i0 < loop_ub; i0++) {
                                  b_typename->data[b_typename->size[0] * i0] =
                                    typename->data[typename->size[0] * i0];
                                }

                                b_typename->data[b_typename->size[0] *
                                  typename->size[1]] = '\x00';
                                m2c_error(b_typename);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  emxFree_char_T(&b_typename);
  return n;
}

void mpi_get_sizeof_initialize(void)
{
}

void mpi_get_sizeof_terminate(void)
{
}
