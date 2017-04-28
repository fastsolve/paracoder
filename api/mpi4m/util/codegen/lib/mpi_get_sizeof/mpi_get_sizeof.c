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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i2, sizeof(char));
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
  emxArray_char_T *c_typename;
  emxArray_char_T *d_typename;
  emxArray_char_T *e_typename;
  emxArray_char_T *f_typename;
  emxArray_char_T *g_typename;
  emxArray_char_T *h_typename;
  emxArray_char_T *i_typename;
  emxArray_char_T *j_typename;
  emxArray_char_T *k_typename;
  emxArray_char_T *l_typename;
  emxArray_char_T *m_typename;
  emxArray_char_T *n_typename;
  emxArray_char_T *o_typename;
  emxArray_char_T *p_typename;
  emxArray_char_T *q_typename;
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
  emxEnsureCapacity((emxArray__common *)b_typename, loop_ub, sizeof(char));
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

    emxInit_char_T(&c_typename, 2);
    loop_ub = c_typename->size[0] * c_typename->size[1];
    c_typename->size[0] = 1;
    c_typename->size[1] = i1 - i0;
    emxEnsureCapacity((emxArray__common *)c_typename, loop_ub, sizeof(char));
    loop_ub = i1 - i0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_typename->data[c_typename->size[0] * i1] = typename->data[i0 + i1];
    }

    if (c_strcmp(c_typename)) {
      n = sizeof(MPI_Status);
    } else {
      if (5 > typename->size[1]) {
        i0 = 0;
        i1 = 0;
      } else {
        i0 = 4;
        i1 = typename->size[1];
      }

      emxInit_char_T(&d_typename, 2);
      loop_ub = d_typename->size[0] * d_typename->size[1];
      d_typename->size[0] = 1;
      d_typename->size[1] = i1 - i0;
      emxEnsureCapacity((emxArray__common *)d_typename, loop_ub, sizeof(char));
      loop_ub = i1 - i0;
      for (i1 = 0; i1 < loop_ub; i1++) {
        d_typename->data[d_typename->size[0] * i1] = typename->data[i0 + i1];
      }

      if (d_strcmp(d_typename)) {
        n = sizeof(MPI_Aint);
      } else {
        if (5 > typename->size[1]) {
          i0 = 0;
          i1 = 0;
        } else {
          i0 = 4;
          i1 = typename->size[1];
        }

        emxInit_char_T(&e_typename, 2);
        loop_ub = e_typename->size[0] * e_typename->size[1];
        e_typename->size[0] = 1;
        e_typename->size[1] = i1 - i0;
        emxEnsureCapacity((emxArray__common *)e_typename, loop_ub, sizeof(char));
        loop_ub = i1 - i0;
        for (i1 = 0; i1 < loop_ub; i1++) {
          e_typename->data[e_typename->size[0] * i1] = typename->data[i0 + i1];
        }

        if (e_strcmp(e_typename)) {
          n = sizeof(MPI_Op);
        } else {
          if (5 > typename->size[1]) {
            i0 = 0;
            i1 = 0;
          } else {
            i0 = 4;
            i1 = typename->size[1];
          }

          emxInit_char_T(&f_typename, 2);
          loop_ub = f_typename->size[0] * f_typename->size[1];
          f_typename->size[0] = 1;
          f_typename->size[1] = i1 - i0;
          emxEnsureCapacity((emxArray__common *)f_typename, loop_ub, sizeof(char));
          loop_ub = i1 - i0;
          for (i1 = 0; i1 < loop_ub; i1++) {
            f_typename->data[f_typename->size[0] * i1] = typename->data[i0 + i1];
          }

          if (f_strcmp(f_typename)) {
            n = sizeof(MPI_Datatype);
          } else {
            if (5 > typename->size[1]) {
              i0 = 0;
              i1 = 0;
            } else {
              i0 = 4;
              i1 = typename->size[1];
            }

            emxInit_char_T(&g_typename, 2);
            loop_ub = g_typename->size[0] * g_typename->size[1];
            g_typename->size[0] = 1;
            g_typename->size[1] = i1 - i0;
            emxEnsureCapacity((emxArray__common *)g_typename, loop_ub, sizeof
                              (char));
            loop_ub = i1 - i0;
            for (i1 = 0; i1 < loop_ub; i1++) {
              g_typename->data[g_typename->size[0] * i1] = typename->data[i0 +
                i1];
            }

            emxInit_char_T(&h_typename, 2);
            emxInit_char_T(&i_typename, 2);
            emxInit_char_T(&j_typename, 2);
            emxInit_char_T(&k_typename, 2);
            emxInit_char_T(&l_typename, 2);
            emxInit_char_T(&m_typename, 2);
            emxInit_char_T(&n_typename, 2);
            emxInit_char_T(&o_typename, 2);
            emxInit_char_T(&p_typename, 2);
            emxInit_char_T(&q_typename, 2);
            if (g_strcmp(g_typename)) {
              n = 8;
            } else {
              if (5 > typename->size[1]) {
                i0 = 0;
                i1 = 0;
              } else {
                i0 = 4;
                i1 = typename->size[1];
              }

              loop_ub = q_typename->size[0] * q_typename->size[1];
              q_typename->size[0] = 1;
              q_typename->size[1] = i1 - i0;
              emxEnsureCapacity((emxArray__common *)q_typename, loop_ub, sizeof
                                (char));
              loop_ub = i1 - i0;
              for (i1 = 0; i1 < loop_ub; i1++) {
                q_typename->data[q_typename->size[0] * i1] = typename->data[i0 +
                  i1];
              }

              if (h_strcmp(q_typename)) {
                n = 8;
              } else {
                if (5 > typename->size[1]) {
                  i0 = 0;
                  i1 = 0;
                } else {
                  i0 = 4;
                  i1 = typename->size[1];
                }

                loop_ub = p_typename->size[0] * p_typename->size[1];
                p_typename->size[0] = 1;
                p_typename->size[1] = i1 - i0;
                emxEnsureCapacity((emxArray__common *)p_typename, loop_ub,
                                  sizeof(char));
                loop_ub = i1 - i0;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  p_typename->data[p_typename->size[0] * i1] = typename->data[i0
                    + i1];
                }

                if (i_strcmp(p_typename)) {
                  n = 4;
                } else {
                  if (5 > typename->size[1]) {
                    i0 = 0;
                    i1 = 0;
                  } else {
                    i0 = 4;
                    i1 = typename->size[1];
                  }

                  loop_ub = o_typename->size[0] * o_typename->size[1];
                  o_typename->size[0] = 1;
                  o_typename->size[1] = i1 - i0;
                  emxEnsureCapacity((emxArray__common *)o_typename, loop_ub,
                                    sizeof(char));
                  loop_ub = i1 - i0;
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    o_typename->data[o_typename->size[0] * i1] = typename->
                      data[i0 + i1];
                  }

                  if (j_strcmp(o_typename)) {
                    n = 4;
                  } else {
                    if (5 > typename->size[1]) {
                      i0 = 0;
                      i1 = 0;
                    } else {
                      i0 = 4;
                      i1 = typename->size[1];
                    }

                    loop_ub = n_typename->size[0] * n_typename->size[1];
                    n_typename->size[0] = 1;
                    n_typename->size[1] = i1 - i0;
                    emxEnsureCapacity((emxArray__common *)n_typename, loop_ub,
                                      sizeof(char));
                    loop_ub = i1 - i0;
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      n_typename->data[n_typename->size[0] * i1] =
                        typename->data[i0 + i1];
                    }

                    if (k_strcmp(n_typename)) {
                      n = 4;
                    } else {
                      if (5 > typename->size[1]) {
                        i0 = 0;
                        i1 = 0;
                      } else {
                        i0 = 4;
                        i1 = typename->size[1];
                      }

                      loop_ub = m_typename->size[0] * m_typename->size[1];
                      m_typename->size[0] = 1;
                      m_typename->size[1] = i1 - i0;
                      emxEnsureCapacity((emxArray__common *)m_typename, loop_ub,
                                        sizeof(char));
                      loop_ub = i1 - i0;
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        m_typename->data[m_typename->size[0] * i1] =
                          typename->data[i0 + i1];
                      }

                      if (l_strcmp(m_typename)) {
                        n = 2;
                      } else {
                        if (5 > typename->size[1]) {
                          i0 = 0;
                          i1 = 0;
                        } else {
                          i0 = 4;
                          i1 = typename->size[1];
                        }

                        loop_ub = l_typename->size[0] * l_typename->size[1];
                        l_typename->size[0] = 1;
                        l_typename->size[1] = i1 - i0;
                        emxEnsureCapacity((emxArray__common *)l_typename,
                                          loop_ub, sizeof(char));
                        loop_ub = i1 - i0;
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          l_typename->data[l_typename->size[0] * i1] =
                            typename->data[i0 + i1];
                        }

                        if (m_strcmp(l_typename)) {
                          n = 2;
                        } else {
                          if (5 > typename->size[1]) {
                            i0 = 0;
                            i1 = 0;
                          } else {
                            i0 = 4;
                            i1 = typename->size[1];
                          }

                          loop_ub = k_typename->size[0] * k_typename->size[1];
                          k_typename->size[0] = 1;
                          k_typename->size[1] = i1 - i0;
                          emxEnsureCapacity((emxArray__common *)k_typename,
                                            loop_ub, sizeof(char));
                          loop_ub = i1 - i0;
                          for (i1 = 0; i1 < loop_ub; i1++) {
                            k_typename->data[k_typename->size[0] * i1] =
                              typename->data[i0 + i1];
                          }

                          if (n_strcmp(k_typename)) {
                            n = 1;
                          } else {
                            if (5 > typename->size[1]) {
                              i0 = 0;
                              i1 = 0;
                            } else {
                              i0 = 4;
                              i1 = typename->size[1];
                            }

                            loop_ub = j_typename->size[0] * j_typename->size[1];
                            j_typename->size[0] = 1;
                            j_typename->size[1] = i1 - i0;
                            emxEnsureCapacity((emxArray__common *)j_typename,
                                              loop_ub, sizeof(char));
                            loop_ub = i1 - i0;
                            for (i1 = 0; i1 < loop_ub; i1++) {
                              j_typename->data[j_typename->size[0] * i1] =
                                typename->data[i0 + i1];
                            }

                            if (o_strcmp(j_typename)) {
                              n = 1;
                            } else {
                              if (5 > typename->size[1]) {
                                i0 = 0;
                                i1 = 0;
                              } else {
                                i0 = 4;
                                i1 = typename->size[1];
                              }

                              loop_ub = i_typename->size[0] * i_typename->size[1];
                              i_typename->size[0] = 1;
                              i_typename->size[1] = i1 - i0;
                              emxEnsureCapacity((emxArray__common *)i_typename,
                                                loop_ub, sizeof(char));
                              loop_ub = i1 - i0;
                              for (i1 = 0; i1 < loop_ub; i1++) {
                                i_typename->data[i_typename->size[0] * i1] =
                                  typename->data[i0 + i1];
                              }

                              if (p_strcmp(i_typename)) {
                                n = 1;
                              } else {
                                i0 = h_typename->size[0] * h_typename->size[1];
                                h_typename->size[0] = 1;
                                h_typename->size[1] = typename->size[1] + 1;
                                emxEnsureCapacity((emxArray__common *)h_typename,
                                                  i0, sizeof(char));
                                loop_ub = typename->size[1];
                                for (i0 = 0; i0 < loop_ub; i0++) {
                                  h_typename->data[h_typename->size[0] * i0] =
                                    typename->data[typename->size[0] * i0];
                                }

                                h_typename->data[h_typename->size[0] *
                                  typename->size[1]] = '\x00';
                                m2c_error(h_typename);
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

            emxFree_char_T(&g_typename);
            emxFree_char_T(&q_typename);
            emxFree_char_T(&p_typename);
            emxFree_char_T(&o_typename);
            emxFree_char_T(&n_typename);
            emxFree_char_T(&m_typename);
            emxFree_char_T(&l_typename);
            emxFree_char_T(&k_typename);
            emxFree_char_T(&j_typename);
            emxFree_char_T(&i_typename);
            emxFree_char_T(&h_typename);
          }

          emxFree_char_T(&f_typename);
        }

        emxFree_char_T(&e_typename);
      }

      emxFree_char_T(&d_typename);
    }

    emxFree_char_T(&c_typename);
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
