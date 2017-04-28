#include "mpi_get_const.h"
#include "m2c.h"
#include "mpi.h"

static boolean_T ab_isequal(const emxArray_char_T *varargin_1);
static boolean_T ac_isequal(const emxArray_char_T *varargin_1);
static boolean_T b_isequal(const emxArray_char_T *varargin_1);
static boolean_T bb_isequal(const emxArray_char_T *varargin_1);
static boolean_T bc_isequal(const emxArray_char_T *varargin_1);
static boolean_T c_isequal(const emxArray_char_T *varargin_1);
static boolean_T cb_isequal(const emxArray_char_T *varargin_1);
static boolean_T cc_isequal(const emxArray_char_T *varargin_1);
static boolean_T d_isequal(const emxArray_char_T *varargin_1);
static boolean_T db_isequal(const emxArray_char_T *varargin_1);
static boolean_T dc_isequal(const emxArray_char_T *varargin_1);
static boolean_T e_isequal(const emxArray_char_T *varargin_1);
static boolean_T eb_isequal(const emxArray_char_T *varargin_1);
static boolean_T ec_isequal(const emxArray_char_T *varargin_1);
static boolean_T f_isequal(const emxArray_char_T *varargin_1);
static boolean_T fb_isequal(const emxArray_char_T *varargin_1);
static boolean_T fc_isequal(const emxArray_char_T *varargin_1);
static boolean_T g_isequal(const emxArray_char_T *varargin_1);
static boolean_T gb_isequal(const emxArray_char_T *varargin_1);
static boolean_T gc_isequal(const emxArray_char_T *varargin_1);
static boolean_T h_isequal(const emxArray_char_T *varargin_1);
static boolean_T hb_isequal(const emxArray_char_T *varargin_1);
static boolean_T hc_isequal(const emxArray_char_T *varargin_1);
static boolean_T i_isequal(const emxArray_char_T *varargin_1);
static boolean_T ib_isequal(const emxArray_char_T *varargin_1);
static boolean_T isequal(const emxArray_char_T *varargin_1);
static boolean_T j_isequal(const emxArray_char_T *varargin_1);
static boolean_T jb_isequal(const emxArray_char_T *varargin_1);
static boolean_T k_isequal(const emxArray_char_T *varargin_1);
static boolean_T kb_isequal(const emxArray_char_T *varargin_1);
static boolean_T l_isequal(const emxArray_char_T *varargin_1);
static boolean_T lb_isequal(const emxArray_char_T *varargin_1);
static void m2c_error(const emxArray_char_T *varargin_3);
static boolean_T m_isequal(const emxArray_char_T *varargin_1);
static boolean_T mb_isequal(const emxArray_char_T *varargin_1);
static boolean_T n_isequal(const emxArray_char_T *varargin_1);
static boolean_T nb_isequal(const emxArray_char_T *varargin_1);
static boolean_T o_isequal(const emxArray_char_T *varargin_1);
static boolean_T ob_isequal(const emxArray_char_T *varargin_1);
static boolean_T p_isequal(const emxArray_char_T *varargin_1);
static boolean_T pb_isequal(const emxArray_char_T *varargin_1);
static boolean_T q_isequal(const emxArray_char_T *varargin_1);
static boolean_T qb_isequal(const emxArray_char_T *varargin_1);
static boolean_T r_isequal(const emxArray_char_T *varargin_1);
static boolean_T rb_isequal(const emxArray_char_T *varargin_1);
static boolean_T s_isequal(const emxArray_char_T *varargin_1);
static boolean_T sb_isequal(const emxArray_char_T *varargin_1);
static boolean_T t_isequal(const emxArray_char_T *varargin_1);
static boolean_T tb_isequal(const emxArray_char_T *varargin_1);
static boolean_T u_isequal(const emxArray_char_T *varargin_1);
static boolean_T ub_isequal(const emxArray_char_T *varargin_1);
static boolean_T v_isequal(const emxArray_char_T *varargin_1);
static boolean_T vb_isequal(const emxArray_char_T *varargin_1);
static boolean_T w_isequal(const emxArray_char_T *varargin_1);
static boolean_T wb_isequal(const emxArray_char_T *varargin_1);
static boolean_T x_isequal(const emxArray_char_T *varargin_1);
static boolean_T xb_isequal(const emxArray_char_T *varargin_1);
static boolean_T y_isequal(const emxArray_char_T *varargin_1);
static boolean_T yb_isequal(const emxArray_char_T *varargin_1);
static boolean_T ab_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv37[4] = { 'P', 'R', 'O', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv37[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ac_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv62[4] = { 'C', 'A', 'R', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv62[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T b_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv13[6] = { 'D', 'O', 'U', 'B', 'L', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv13[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T bb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv38[3] = { 'M', 'I', 'N' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv38[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T bc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv63[12] = { 'R', 'E', 'Q', 'U', 'E', 'S', 'T', '_', 'N',
    'U', 'L', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv63[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T c_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv14[11] = { 'L', 'O', 'N', 'G', '_', 'D', 'O', 'U', 'B',
    'L', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv14[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T cb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv39[3] = { 'M', 'A', 'X' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv39[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T cc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv64[10] = { 'G', 'R', 'O', 'U', 'P', '_', 'N', 'U', 'L',
    'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv64[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T d_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv15[3] = { 'I', 'N', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv15[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T db_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv40[3] = { 'B', 'O', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv40[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T dc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv65[11] = { 'G', 'R', 'O', 'U', 'P', '_', 'E', 'M', 'P',
    'T', 'Y' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv65[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T e_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv16[8] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv16[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T eb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv41[4] = { 'B', 'A', 'N', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv41[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ec_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv66[13] = { 'S', 'T', 'A', 'T', 'U', 'S', '_', 'I', 'G',
    'N', 'O', 'R', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv66[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T f_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv17[4] = { 'L', 'O', 'N', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv17[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T fb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv42[4] = { 'B', 'X', 'O', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv42[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T fc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv67[9] = { 'I', 'N', 'F', 'O', '_', 'N', 'U', 'L', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv67[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T g_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv18[13] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_',
    'L', 'O', 'N', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv18[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T gb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv43[3] = { 'L', 'O', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv43[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T gc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv68[9] = { 'A', 'R', 'G', 'V', '_', 'N', 'U', 'L', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv68[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T h_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv19[9] = { 'L', 'O', 'N', 'G', '_', 'L', 'O', 'N', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv19[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T hb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv44[4] = { 'L', 'A', 'N', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv44[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T hc_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv69[15] = { 'E', 'R', 'R', 'C', 'O', 'D', 'E', 'S', '_',
    'I', 'G', 'N', 'O', 'R', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 15) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv69[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T i_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv20[13] = { 'L', 'O', 'N', 'G', '_', 'L', 'O', 'N', 'G',
    '_', 'I', 'N', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv20[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ib_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv45[4] = { 'L', 'X', 'O', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv45[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv12[5] = { 'F', 'L', 'O', 'A', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv12[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T j_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv21[18] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_',
    'L', 'O', 'N', 'G', '_', 'L', 'O', 'N', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 18) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 18)) {
      if (!(varargin_1->data[k] == cv21[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T jb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv46[6] = { 'M', 'A', 'X', 'L', 'O', 'C' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv46[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T k_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv22[5] = { 'S', 'H', 'O', 'R', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv22[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T kb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv47[6] = { 'M', 'I', 'N', 'L', 'O', 'C' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv47[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T l_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv23[14] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_',
    'S', 'H', 'O', 'R', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv23[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T lb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv48[7] = { 'O', 'P', '_', 'N', 'U', 'L', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv48[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
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
  emxEnsureCapacity((emxArray__common *)b_varargin_3, i1, sizeof(char));
  loop_ub = varargin_3->size[0] * varargin_3->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_varargin_3->data[i1] = varargin_3->data[i1];
  }

  M2C_error("mpi_get_const:UnknownConstant", "Unknonw constant %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static boolean_T m_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv24[4] = { 'C', 'H', 'A', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv24[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T mb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv49[10] = { 'A', 'N', 'Y', '_', 'S', 'O', 'U', 'R', 'C',
    'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv49[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T n_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv25[13] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_',
    'C', 'H', 'A', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv25[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T nb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv50[7] = { 'A', 'N', 'Y', '_', 'T', 'A', 'G' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv50[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T o_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv26[4] = { 'B', 'Y', 'T', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv26[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ob_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv51[8] = { 'I', 'N', '_', 'P', 'L', 'A', 'C', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv51[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T p_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv27[4] = { '2', 'I', 'N', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv27[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T pb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv52[16] = { 'E', 'R', 'R', 'O', 'R', 'S', '_', 'A', 'R',
    'E', '_', 'F', 'A', 'T', 'A', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 16) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 16)) {
      if (!(varargin_1->data[k] == cv52[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T q_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv28[9] = { 'S', 'H', 'O', 'R', 'T', '_', 'I', 'N', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv28[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T qb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv53[13] = { 'E', 'R', 'R', 'O', 'R', 'S', '_', 'R', 'E',
    'T', 'U', 'R', 'N' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv53[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T r_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv29[9] = { 'F', 'L', 'O', 'A', 'T', '_', 'I', 'N', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv29[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T rb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv54[14] = { 'B', 'S', 'E', 'N', 'D', '_', 'O', 'V', 'E',
    'R', 'H', 'E', 'A', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv54[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T s_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv30[10] = { 'D', 'O', 'U', 'B', 'L', 'E', '_', 'I', 'N',
    'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv30[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T sb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv55[9] = { 'U', 'N', 'D', 'E', 'F', 'I', 'N', 'E', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv55[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T t_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv31[6] = { 'P', 'A', 'C', 'K', 'E', 'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv31[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T tb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv56[5] = { 'I', 'D', 'E', 'N', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv56[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T u_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv32[13] = { 'D', 'A', 'T', 'A', 'T', 'Y', 'P', 'E', '_',
    'N', 'U', 'L', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv32[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T ub_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv57[9] = { 'C', 'O', 'N', 'G', 'R', 'U', 'E', 'N', 'T' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv57[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T v_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv33[10] = { 'C', 'O', 'M', 'M', '_', 'W', 'O', 'R', 'L',
    'D' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv33[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T vb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv58[7] = { 'S', 'I', 'M', 'I', 'L', 'A', 'R' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv58[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T w_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv34[9] = { 'C', 'O', 'M', 'M', '_', 'S', 'E', 'L', 'F' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv34[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T wb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv59[7] = { 'U', 'N', 'E', 'Q', 'U', 'A', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv59[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T x_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv35[9] = { 'C', 'O', 'M', 'M', '_', 'N', 'U', 'L', 'L' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv35[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T xb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv60[18] = { 'M', 'A', 'X', '_', 'P', 'R', 'O', 'C', 'E',
    'S', 'S', 'O', 'R', '_', 'N', 'A', 'M', 'E' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 18) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 18)) {
      if (!(varargin_1->data[k] == cv60[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T y_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv36[3] = { 'S', 'U', 'M' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv36[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T yb_isequal(const emxArray_char_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int k;
  boolean_T exitg1;
  static const char cv61[5] = { 'G', 'R', 'A', 'P', 'H' };

  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (!(varargin_1->size[1] == 0))) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv61[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_p) {
    p = true;
  }

  return p;
}

void mpi_get_const(const emxArray_char_T *name, struct0_T *obj)
{
  int i0;
  int sizepe;
  emxArray_char_T *b_name;
  int loop_ub;
  emxArray_uint8_T *data0;
  MPI_Datatype arg;
  emxArray_char_T *c_name;
  char t4_type[12];
  static const char cv0[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  emxArray_char_T *d_name;
  char * ptr;
  emxArray_char_T *e_name;
  emxArray_char_T *f_name;
  emxArray_char_T *g_name;
  emxArray_char_T *h_name;
  emxArray_char_T *i_name;
  emxArray_char_T *j_name;
  emxArray_char_T *k_name;
  emxArray_char_T *l_name;
  emxArray_char_T *m_name;
  emxArray_char_T *n_name;
  emxArray_char_T *o_name;
  emxArray_char_T *p_name;
  emxArray_char_T *q_name;
  emxArray_char_T *r_name;
  emxArray_char_T *s_name;
  emxArray_char_T *t_name;
  emxArray_char_T *u_name;
  emxArray_char_T *v_name;
  emxArray_char_T *w_name;
  MPI_Comm b_arg;
  emxArray_char_T *x_name;
  char t3_type[8];
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  emxArray_char_T *y_name;
  emxArray_char_T *ab_name;
  MPI_Op c_arg;
  emxArray_char_T *bb_name;
  char t0_type[6];
  static const char cv2[6] = { 'M', 'P', 'I', '_', 'O', 'p' };

  emxArray_char_T *cb_name;
  emxArray_char_T *db_name;
  emxArray_char_T *eb_name;
  emxArray_char_T *fb_name;
  emxArray_char_T *gb_name;
  emxArray_char_T *hb_name;
  emxArray_char_T *ib_name;
  emxArray_char_T *jb_name;
  emxArray_char_T *kb_name;
  emxArray_char_T *lb_name;
  emxArray_char_T *mb_name;
  emxArray_char_T *nb_name;
  int d_arg;
  emxArray_char_T *ob_name;
  char t7_type[3];
  static const char cv3[3] = { 'i', 'n', 't' };

  emxArray_char_T *pb_name;
  void * e_arg;
  emxArray_char_T *qb_name;
  static const char cv4[6] = { 'v', 'o', 'i', 'd', ' ', '*' };

  MPI_Errhandler f_arg;
  emxArray_char_T *rb_name;
  char t8_type[14];
  static const char cv5[14] = { 'M', 'P', 'I', '_', 'E', 'r', 'r', 'h', 'a', 'n',
    'd', 'l', 'e', 'r' };

  emxArray_char_T *sb_name;
  emxArray_char_T *tb_name;
  emxArray_char_T *ub_name;
  emxArray_char_T *vb_name;
  emxArray_char_T *wb_name;
  emxArray_char_T *xb_name;
  emxArray_char_T *yb_name;
  emxArray_char_T *ac_name;
  emxArray_char_T *bc_name;
  emxArray_char_T *cc_name;
  MPI_Request g_arg;
  emxArray_char_T *dc_name;
  char t6_type[11];
  static const char cv6[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  MPI_Group h_arg;
  emxArray_char_T *ec_name;
  char t5_type[9];
  static const char cv7[9] = { 'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p' };

  emxArray_char_T *fc_name;
  MPI_Status * i_arg;
  emxArray_char_T *gc_name;
  static const char cv8[12] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u', 's',
    ' ', '*' };

  MPI_Info j_arg;
  emxArray_char_T *hc_name;
  static const char cv9[8] = { 'M', 'P', 'I', '_', 'I', 'n', 'f', 'o' };

  char ** k_arg;
  emxArray_char_T *ic_name;
  char t2_type[7];
  static const char cv10[7] = { 'c', 'h', 'a', 'r', ' ', '*', '*' };

  int * l_arg;
  char t1_type[5];
  static const char cv11[5] = { 'i', 'n', 't', ' ', '*' };

  emxArray_char_T *jc_name;
  if (5 > name->size[1]) {
    i0 = 0;
    sizepe = 0;
  } else {
    i0 = 4;
    sizepe = name->size[1];
  }

  emxInit_char_T(&b_name, 2);
  loop_ub = b_name->size[0] * b_name->size[1];
  b_name->size[0] = 1;
  b_name->size[1] = sizepe - i0;
  emxEnsureCapacity((emxArray__common *)b_name, loop_ub, sizeof(char));
  loop_ub = sizepe - i0;
  for (sizepe = 0; sizepe < loop_ub; sizepe++) {
    b_name->data[b_name->size[0] * sizepe] = name->data[i0 + sizepe];
  }

  emxInit_uint8_T(&data0, 1);
  if (isequal(b_name)) {
    arg = MPI_FLOAT;
    sizepe = sizeof(MPI_Datatype);
    i0 = data0->size[0];
    data0->size[0] = sizepe;
    emxEnsureCapacity((emxArray__common *)data0, i0, sizeof(unsigned char));
    for (i0 = 0; i0 < 12; i0++) {
      t4_type[i0] = cv0[i0];
    }

    i0 = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity((emxArray__common *)obj->data, i0, sizeof(unsigned char));
    loop_ub = data0->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      obj->data->data[i0] = data0->data[i0];
    }

    i0 = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 12;
    emxEnsureCapacity((emxArray__common *)obj->type, i0, sizeof(char));
    for (i0 = 0; i0 < 12; i0++) {
      obj->type->data[i0] = t4_type[i0];
    }

    obj->nitems = 1;
    ptr = (char *)(&arg);
    for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
      obj->data->data[loop_ub - 1] = *(ptr);
      ptr = ptr + 1;
    }
  } else {
    if (5 > name->size[1]) {
      i0 = 0;
      sizepe = 0;
    } else {
      i0 = 4;
      sizepe = name->size[1];
    }

    emxInit_char_T(&c_name, 2);
    loop_ub = c_name->size[0] * c_name->size[1];
    c_name->size[0] = 1;
    c_name->size[1] = sizepe - i0;
    emxEnsureCapacity((emxArray__common *)c_name, loop_ub, sizeof(char));
    loop_ub = sizepe - i0;
    for (sizepe = 0; sizepe < loop_ub; sizepe++) {
      c_name->data[c_name->size[0] * sizepe] = name->data[i0 + sizepe];
    }

    if (b_isequal(c_name)) {
      arg = MPI_DOUBLE;
      sizepe = sizeof(MPI_Datatype);
      i0 = data0->size[0];
      data0->size[0] = sizepe;
      emxEnsureCapacity((emxArray__common *)data0, i0, sizeof(unsigned char));
      for (i0 = 0; i0 < 12; i0++) {
        t4_type[i0] = cv0[i0];
      }

      i0 = obj->data->size[0];
      obj->data->size[0] = data0->size[0];
      emxEnsureCapacity((emxArray__common *)obj->data, i0, sizeof(unsigned char));
      loop_ub = data0->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        obj->data->data[i0] = data0->data[i0];
      }

      i0 = obj->type->size[0] * obj->type->size[1];
      obj->type->size[0] = 1;
      obj->type->size[1] = 12;
      emxEnsureCapacity((emxArray__common *)obj->type, i0, sizeof(char));
      for (i0 = 0; i0 < 12; i0++) {
        obj->type->data[i0] = t4_type[i0];
      }

      obj->nitems = 1;
      ptr = (char *)(&arg);
      for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
        obj->data->data[loop_ub - 1] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      if (5 > name->size[1]) {
        i0 = 0;
        sizepe = 0;
      } else {
        i0 = 4;
        sizepe = name->size[1];
      }

      emxInit_char_T(&d_name, 2);
      loop_ub = d_name->size[0] * d_name->size[1];
      d_name->size[0] = 1;
      d_name->size[1] = sizepe - i0;
      emxEnsureCapacity((emxArray__common *)d_name, loop_ub, sizeof(char));
      loop_ub = sizepe - i0;
      for (sizepe = 0; sizepe < loop_ub; sizepe++) {
        d_name->data[d_name->size[0] * sizepe] = name->data[i0 + sizepe];
      }

      if (c_isequal(d_name)) {
        arg = MPI_LONG_DOUBLE;
        sizepe = sizeof(MPI_Datatype);
        i0 = data0->size[0];
        data0->size[0] = sizepe;
        emxEnsureCapacity((emxArray__common *)data0, i0, sizeof(unsigned char));
        for (i0 = 0; i0 < 12; i0++) {
          t4_type[i0] = cv0[i0];
        }

        i0 = obj->data->size[0];
        obj->data->size[0] = data0->size[0];
        emxEnsureCapacity((emxArray__common *)obj->data, i0, sizeof(unsigned
          char));
        loop_ub = data0->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          obj->data->data[i0] = data0->data[i0];
        }

        i0 = obj->type->size[0] * obj->type->size[1];
        obj->type->size[0] = 1;
        obj->type->size[1] = 12;
        emxEnsureCapacity((emxArray__common *)obj->type, i0, sizeof(char));
        for (i0 = 0; i0 < 12; i0++) {
          obj->type->data[i0] = t4_type[i0];
        }

        obj->nitems = 1;
        ptr = (char *)(&arg);
        for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
          obj->data->data[loop_ub - 1] = *(ptr);
          ptr = ptr + 1;
        }
      } else {
        if (5 > name->size[1]) {
          i0 = 0;
          sizepe = 0;
        } else {
          i0 = 4;
          sizepe = name->size[1];
        }

        emxInit_char_T(&e_name, 2);
        loop_ub = e_name->size[0] * e_name->size[1];
        e_name->size[0] = 1;
        e_name->size[1] = sizepe - i0;
        emxEnsureCapacity((emxArray__common *)e_name, loop_ub, sizeof(char));
        loop_ub = sizepe - i0;
        for (sizepe = 0; sizepe < loop_ub; sizepe++) {
          e_name->data[e_name->size[0] * sizepe] = name->data[i0 + sizepe];
        }

        if (d_isequal(e_name)) {
          arg = MPI_INT;
          sizepe = sizeof(MPI_Datatype);
          i0 = data0->size[0];
          data0->size[0] = sizepe;
          emxEnsureCapacity((emxArray__common *)data0, i0, sizeof(unsigned char));
          for (i0 = 0; i0 < 12; i0++) {
            t4_type[i0] = cv0[i0];
          }

          i0 = obj->data->size[0];
          obj->data->size[0] = data0->size[0];
          emxEnsureCapacity((emxArray__common *)obj->data, i0, sizeof(unsigned
            char));
          loop_ub = data0->size[0];
          for (i0 = 0; i0 < loop_ub; i0++) {
            obj->data->data[i0] = data0->data[i0];
          }

          i0 = obj->type->size[0] * obj->type->size[1];
          obj->type->size[0] = 1;
          obj->type->size[1] = 12;
          emxEnsureCapacity((emxArray__common *)obj->type, i0, sizeof(char));
          for (i0 = 0; i0 < 12; i0++) {
            obj->type->data[i0] = t4_type[i0];
          }

          obj->nitems = 1;
          ptr = (char *)(&arg);
          for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
            obj->data->data[loop_ub - 1] = *(ptr);
            ptr = ptr + 1;
          }
        } else {
          if (5 > name->size[1]) {
            i0 = 0;
            sizepe = 0;
          } else {
            i0 = 4;
            sizepe = name->size[1];
          }

          emxInit_char_T(&f_name, 2);
          loop_ub = f_name->size[0] * f_name->size[1];
          f_name->size[0] = 1;
          f_name->size[1] = sizepe - i0;
          emxEnsureCapacity((emxArray__common *)f_name, loop_ub, sizeof(char));
          loop_ub = sizepe - i0;
          for (sizepe = 0; sizepe < loop_ub; sizepe++) {
            f_name->data[f_name->size[0] * sizepe] = name->data[i0 + sizepe];
          }

          if (e_isequal(f_name)) {
            arg = MPI_UNSIGNED;
            sizepe = sizeof(MPI_Datatype);
            i0 = data0->size[0];
            data0->size[0] = sizepe;
            emxEnsureCapacity((emxArray__common *)data0, i0, sizeof(unsigned
              char));
            for (i0 = 0; i0 < 12; i0++) {
              t4_type[i0] = cv0[i0];
            }

            i0 = obj->data->size[0];
            obj->data->size[0] = data0->size[0];
            emxEnsureCapacity((emxArray__common *)obj->data, i0, sizeof(unsigned
              char));
            loop_ub = data0->size[0];
            for (i0 = 0; i0 < loop_ub; i0++) {
              obj->data->data[i0] = data0->data[i0];
            }

            i0 = obj->type->size[0] * obj->type->size[1];
            obj->type->size[0] = 1;
            obj->type->size[1] = 12;
            emxEnsureCapacity((emxArray__common *)obj->type, i0, sizeof(char));
            for (i0 = 0; i0 < 12; i0++) {
              obj->type->data[i0] = t4_type[i0];
            }

            obj->nitems = 1;
            ptr = (char *)(&arg);
            for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
              obj->data->data[loop_ub - 1] = *(ptr);
              ptr = ptr + 1;
            }
          } else {
            if (5 > name->size[1]) {
              i0 = 0;
              sizepe = 0;
            } else {
              i0 = 4;
              sizepe = name->size[1];
            }

            emxInit_char_T(&g_name, 2);
            loop_ub = g_name->size[0] * g_name->size[1];
            g_name->size[0] = 1;
            g_name->size[1] = sizepe - i0;
            emxEnsureCapacity((emxArray__common *)g_name, loop_ub, sizeof(char));
            loop_ub = sizepe - i0;
            for (sizepe = 0; sizepe < loop_ub; sizepe++) {
              g_name->data[g_name->size[0] * sizepe] = name->data[i0 + sizepe];
            }

            if (f_isequal(g_name)) {
              arg = MPI_LONG;
              sizepe = sizeof(MPI_Datatype);
              i0 = data0->size[0];
              data0->size[0] = sizepe;
              emxEnsureCapacity((emxArray__common *)data0, i0, sizeof(unsigned
                char));
              for (i0 = 0; i0 < 12; i0++) {
                t4_type[i0] = cv0[i0];
              }

              i0 = obj->data->size[0];
              obj->data->size[0] = data0->size[0];
              emxEnsureCapacity((emxArray__common *)obj->data, i0, sizeof
                                (unsigned char));
              loop_ub = data0->size[0];
              for (i0 = 0; i0 < loop_ub; i0++) {
                obj->data->data[i0] = data0->data[i0];
              }

              i0 = obj->type->size[0] * obj->type->size[1];
              obj->type->size[0] = 1;
              obj->type->size[1] = 12;
              emxEnsureCapacity((emxArray__common *)obj->type, i0, sizeof(char));
              for (i0 = 0; i0 < 12; i0++) {
                obj->type->data[i0] = t4_type[i0];
              }

              obj->nitems = 1;
              ptr = (char *)(&arg);
              for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
                obj->data->data[loop_ub - 1] = *(ptr);
                ptr = ptr + 1;
              }
            } else {
              if (5 > name->size[1]) {
                i0 = 0;
                sizepe = 0;
              } else {
                i0 = 4;
                sizepe = name->size[1];
              }

              emxInit_char_T(&h_name, 2);
              loop_ub = h_name->size[0] * h_name->size[1];
              h_name->size[0] = 1;
              h_name->size[1] = sizepe - i0;
              emxEnsureCapacity((emxArray__common *)h_name, loop_ub, sizeof(char));
              loop_ub = sizepe - i0;
              for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                h_name->data[h_name->size[0] * sizepe] = name->data[i0 + sizepe];
              }

              if (g_isequal(h_name)) {
                arg = MPI_UNSIGNED_LONG;
                sizepe = sizeof(MPI_Datatype);
                i0 = data0->size[0];
                data0->size[0] = sizepe;
                emxEnsureCapacity((emxArray__common *)data0, i0, sizeof(unsigned
                  char));
                for (i0 = 0; i0 < 12; i0++) {
                  t4_type[i0] = cv0[i0];
                }

                i0 = obj->data->size[0];
                obj->data->size[0] = data0->size[0];
                emxEnsureCapacity((emxArray__common *)obj->data, i0, sizeof
                                  (unsigned char));
                loop_ub = data0->size[0];
                for (i0 = 0; i0 < loop_ub; i0++) {
                  obj->data->data[i0] = data0->data[i0];
                }

                i0 = obj->type->size[0] * obj->type->size[1];
                obj->type->size[0] = 1;
                obj->type->size[1] = 12;
                emxEnsureCapacity((emxArray__common *)obj->type, i0, sizeof(char));
                for (i0 = 0; i0 < 12; i0++) {
                  obj->type->data[i0] = t4_type[i0];
                }

                obj->nitems = 1;
                ptr = (char *)(&arg);
                for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
                  obj->data->data[loop_ub - 1] = *(ptr);
                  ptr = ptr + 1;
                }
              } else {
                if (5 > name->size[1]) {
                  i0 = 0;
                  sizepe = 0;
                } else {
                  i0 = 4;
                  sizepe = name->size[1];
                }

                emxInit_char_T(&i_name, 2);
                loop_ub = i_name->size[0] * i_name->size[1];
                i_name->size[0] = 1;
                i_name->size[1] = sizepe - i0;
                emxEnsureCapacity((emxArray__common *)i_name, loop_ub, sizeof
                                  (char));
                loop_ub = sizepe - i0;
                for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                  i_name->data[i_name->size[0] * sizepe] = name->data[i0 +
                    sizepe];
                }

                if (h_isequal(i_name)) {
                  arg = MPI_LONG_LONG;
                  sizepe = sizeof(MPI_Datatype);
                  i0 = data0->size[0];
                  data0->size[0] = sizepe;
                  emxEnsureCapacity((emxArray__common *)data0, i0, sizeof
                                    (unsigned char));
                  for (i0 = 0; i0 < 12; i0++) {
                    t4_type[i0] = cv0[i0];
                  }

                  i0 = obj->data->size[0];
                  obj->data->size[0] = data0->size[0];
                  emxEnsureCapacity((emxArray__common *)obj->data, i0, sizeof
                                    (unsigned char));
                  loop_ub = data0->size[0];
                  for (i0 = 0; i0 < loop_ub; i0++) {
                    obj->data->data[i0] = data0->data[i0];
                  }

                  i0 = obj->type->size[0] * obj->type->size[1];
                  obj->type->size[0] = 1;
                  obj->type->size[1] = 12;
                  emxEnsureCapacity((emxArray__common *)obj->type, i0, sizeof
                                    (char));
                  for (i0 = 0; i0 < 12; i0++) {
                    obj->type->data[i0] = t4_type[i0];
                  }

                  obj->nitems = 1;
                  ptr = (char *)(&arg);
                  for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
                    obj->data->data[loop_ub - 1] = *(ptr);
                    ptr = ptr + 1;
                  }
                } else {
                  if (5 > name->size[1]) {
                    i0 = 0;
                    sizepe = 0;
                  } else {
                    i0 = 4;
                    sizepe = name->size[1];
                  }

                  emxInit_char_T(&j_name, 2);
                  loop_ub = j_name->size[0] * j_name->size[1];
                  j_name->size[0] = 1;
                  j_name->size[1] = sizepe - i0;
                  emxEnsureCapacity((emxArray__common *)j_name, loop_ub, sizeof
                                    (char));
                  loop_ub = sizepe - i0;
                  for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                    j_name->data[j_name->size[0] * sizepe] = name->data[i0 +
                      sizepe];
                  }

                  if (i_isequal(j_name)) {
                    arg = MPI_LONG_LONG_INT;
                    sizepe = sizeof(MPI_Datatype);
                    i0 = data0->size[0];
                    data0->size[0] = sizepe;
                    emxEnsureCapacity((emxArray__common *)data0, i0, sizeof
                                      (unsigned char));
                    for (i0 = 0; i0 < 12; i0++) {
                      t4_type[i0] = cv0[i0];
                    }

                    i0 = obj->data->size[0];
                    obj->data->size[0] = data0->size[0];
                    emxEnsureCapacity((emxArray__common *)obj->data, i0, sizeof
                                      (unsigned char));
                    loop_ub = data0->size[0];
                    for (i0 = 0; i0 < loop_ub; i0++) {
                      obj->data->data[i0] = data0->data[i0];
                    }

                    i0 = obj->type->size[0] * obj->type->size[1];
                    obj->type->size[0] = 1;
                    obj->type->size[1] = 12;
                    emxEnsureCapacity((emxArray__common *)obj->type, i0, sizeof
                                      (char));
                    for (i0 = 0; i0 < 12; i0++) {
                      obj->type->data[i0] = t4_type[i0];
                    }

                    obj->nitems = 1;
                    ptr = (char *)(&arg);
                    for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
                      obj->data->data[loop_ub - 1] = *(ptr);
                      ptr = ptr + 1;
                    }
                  } else {
                    if (5 > name->size[1]) {
                      i0 = 0;
                      sizepe = 0;
                    } else {
                      i0 = 4;
                      sizepe = name->size[1];
                    }

                    emxInit_char_T(&k_name, 2);
                    loop_ub = k_name->size[0] * k_name->size[1];
                    k_name->size[0] = 1;
                    k_name->size[1] = sizepe - i0;
                    emxEnsureCapacity((emxArray__common *)k_name, loop_ub,
                                      sizeof(char));
                    loop_ub = sizepe - i0;
                    for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                      k_name->data[k_name->size[0] * sizepe] = name->data[i0 +
                        sizepe];
                    }

                    if (j_isequal(k_name)) {
                      arg = MPI_UNSIGNED_LONG_LONG;
                      sizepe = sizeof(MPI_Datatype);
                      i0 = data0->size[0];
                      data0->size[0] = sizepe;
                      emxEnsureCapacity((emxArray__common *)data0, i0, sizeof
                                        (unsigned char));
                      for (i0 = 0; i0 < 12; i0++) {
                        t4_type[i0] = cv0[i0];
                      }

                      i0 = obj->data->size[0];
                      obj->data->size[0] = data0->size[0];
                      emxEnsureCapacity((emxArray__common *)obj->data, i0,
                                        sizeof(unsigned char));
                      loop_ub = data0->size[0];
                      for (i0 = 0; i0 < loop_ub; i0++) {
                        obj->data->data[i0] = data0->data[i0];
                      }

                      i0 = obj->type->size[0] * obj->type->size[1];
                      obj->type->size[0] = 1;
                      obj->type->size[1] = 12;
                      emxEnsureCapacity((emxArray__common *)obj->type, i0,
                                        sizeof(char));
                      for (i0 = 0; i0 < 12; i0++) {
                        obj->type->data[i0] = t4_type[i0];
                      }

                      obj->nitems = 1;
                      ptr = (char *)(&arg);
                      for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
                        obj->data->data[loop_ub - 1] = *(ptr);
                        ptr = ptr + 1;
                      }
                    } else {
                      if (5 > name->size[1]) {
                        i0 = 0;
                        sizepe = 0;
                      } else {
                        i0 = 4;
                        sizepe = name->size[1];
                      }

                      emxInit_char_T(&l_name, 2);
                      loop_ub = l_name->size[0] * l_name->size[1];
                      l_name->size[0] = 1;
                      l_name->size[1] = sizepe - i0;
                      emxEnsureCapacity((emxArray__common *)l_name, loop_ub,
                                        sizeof(char));
                      loop_ub = sizepe - i0;
                      for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                        l_name->data[l_name->size[0] * sizepe] = name->data[i0 +
                          sizepe];
                      }

                      if (k_isequal(l_name)) {
                        arg = MPI_SHORT;
                        sizepe = sizeof(MPI_Datatype);
                        i0 = data0->size[0];
                        data0->size[0] = sizepe;
                        emxEnsureCapacity((emxArray__common *)data0, i0, sizeof
                                          (unsigned char));
                        for (i0 = 0; i0 < 12; i0++) {
                          t4_type[i0] = cv0[i0];
                        }

                        i0 = obj->data->size[0];
                        obj->data->size[0] = data0->size[0];
                        emxEnsureCapacity((emxArray__common *)obj->data, i0,
                                          sizeof(unsigned char));
                        loop_ub = data0->size[0];
                        for (i0 = 0; i0 < loop_ub; i0++) {
                          obj->data->data[i0] = data0->data[i0];
                        }

                        i0 = obj->type->size[0] * obj->type->size[1];
                        obj->type->size[0] = 1;
                        obj->type->size[1] = 12;
                        emxEnsureCapacity((emxArray__common *)obj->type, i0,
                                          sizeof(char));
                        for (i0 = 0; i0 < 12; i0++) {
                          obj->type->data[i0] = t4_type[i0];
                        }

                        obj->nitems = 1;
                        ptr = (char *)(&arg);
                        for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
                          obj->data->data[loop_ub - 1] = *(ptr);
                          ptr = ptr + 1;
                        }
                      } else {
                        if (5 > name->size[1]) {
                          i0 = 0;
                          sizepe = 0;
                        } else {
                          i0 = 4;
                          sizepe = name->size[1];
                        }

                        emxInit_char_T(&m_name, 2);
                        loop_ub = m_name->size[0] * m_name->size[1];
                        m_name->size[0] = 1;
                        m_name->size[1] = sizepe - i0;
                        emxEnsureCapacity((emxArray__common *)m_name, loop_ub,
                                          sizeof(char));
                        loop_ub = sizepe - i0;
                        for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                          m_name->data[m_name->size[0] * sizepe] = name->data[i0
                            + sizepe];
                        }

                        if (l_isequal(m_name)) {
                          arg = MPI_UNSIGNED_SHORT;
                          sizepe = sizeof(MPI_Datatype);
                          i0 = data0->size[0];
                          data0->size[0] = sizepe;
                          emxEnsureCapacity((emxArray__common *)data0, i0,
                                            sizeof(unsigned char));
                          for (i0 = 0; i0 < 12; i0++) {
                            t4_type[i0] = cv0[i0];
                          }

                          i0 = obj->data->size[0];
                          obj->data->size[0] = data0->size[0];
                          emxEnsureCapacity((emxArray__common *)obj->data, i0,
                                            sizeof(unsigned char));
                          loop_ub = data0->size[0];
                          for (i0 = 0; i0 < loop_ub; i0++) {
                            obj->data->data[i0] = data0->data[i0];
                          }

                          i0 = obj->type->size[0] * obj->type->size[1];
                          obj->type->size[0] = 1;
                          obj->type->size[1] = 12;
                          emxEnsureCapacity((emxArray__common *)obj->type, i0,
                                            sizeof(char));
                          for (i0 = 0; i0 < 12; i0++) {
                            obj->type->data[i0] = t4_type[i0];
                          }

                          obj->nitems = 1;
                          ptr = (char *)(&arg);
                          for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
                            obj->data->data[loop_ub - 1] = *(ptr);
                            ptr = ptr + 1;
                          }
                        } else {
                          if (5 > name->size[1]) {
                            i0 = 0;
                            sizepe = 0;
                          } else {
                            i0 = 4;
                            sizepe = name->size[1];
                          }

                          emxInit_char_T(&n_name, 2);
                          loop_ub = n_name->size[0] * n_name->size[1];
                          n_name->size[0] = 1;
                          n_name->size[1] = sizepe - i0;
                          emxEnsureCapacity((emxArray__common *)n_name, loop_ub,
                                            sizeof(char));
                          loop_ub = sizepe - i0;
                          for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                            n_name->data[n_name->size[0] * sizepe] = name->
                              data[i0 + sizepe];
                          }

                          if (m_isequal(n_name)) {
                            arg = MPI_CHAR;
                            sizepe = sizeof(MPI_Datatype);
                            i0 = data0->size[0];
                            data0->size[0] = sizepe;
                            emxEnsureCapacity((emxArray__common *)data0, i0,
                                              sizeof(unsigned char));
                            for (i0 = 0; i0 < 12; i0++) {
                              t4_type[i0] = cv0[i0];
                            }

                            i0 = obj->data->size[0];
                            obj->data->size[0] = data0->size[0];
                            emxEnsureCapacity((emxArray__common *)obj->data, i0,
                                              sizeof(unsigned char));
                            loop_ub = data0->size[0];
                            for (i0 = 0; i0 < loop_ub; i0++) {
                              obj->data->data[i0] = data0->data[i0];
                            }

                            i0 = obj->type->size[0] * obj->type->size[1];
                            obj->type->size[0] = 1;
                            obj->type->size[1] = 12;
                            emxEnsureCapacity((emxArray__common *)obj->type, i0,
                                              sizeof(char));
                            for (i0 = 0; i0 < 12; i0++) {
                              obj->type->data[i0] = t4_type[i0];
                            }

                            obj->nitems = 1;
                            ptr = (char *)(&arg);
                            for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
                              obj->data->data[loop_ub - 1] = *(ptr);
                              ptr = ptr + 1;
                            }
                          } else {
                            if (5 > name->size[1]) {
                              i0 = 0;
                              sizepe = 0;
                            } else {
                              i0 = 4;
                              sizepe = name->size[1];
                            }

                            emxInit_char_T(&o_name, 2);
                            loop_ub = o_name->size[0] * o_name->size[1];
                            o_name->size[0] = 1;
                            o_name->size[1] = sizepe - i0;
                            emxEnsureCapacity((emxArray__common *)o_name,
                                              loop_ub, sizeof(char));
                            loop_ub = sizepe - i0;
                            for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                              o_name->data[o_name->size[0] * sizepe] =
                                name->data[i0 + sizepe];
                            }

                            if (n_isequal(o_name)) {
                              arg = MPI_UNSIGNED_CHAR;
                              sizepe = sizeof(MPI_Datatype);
                              i0 = data0->size[0];
                              data0->size[0] = sizepe;
                              emxEnsureCapacity((emxArray__common *)data0, i0,
                                                sizeof(unsigned char));
                              for (i0 = 0; i0 < 12; i0++) {
                                t4_type[i0] = cv0[i0];
                              }

                              i0 = obj->data->size[0];
                              obj->data->size[0] = data0->size[0];
                              emxEnsureCapacity((emxArray__common *)obj->data,
                                                i0, sizeof(unsigned char));
                              loop_ub = data0->size[0];
                              for (i0 = 0; i0 < loop_ub; i0++) {
                                obj->data->data[i0] = data0->data[i0];
                              }

                              i0 = obj->type->size[0] * obj->type->size[1];
                              obj->type->size[0] = 1;
                              obj->type->size[1] = 12;
                              emxEnsureCapacity((emxArray__common *)obj->type,
                                                i0, sizeof(char));
                              for (i0 = 0; i0 < 12; i0++) {
                                obj->type->data[i0] = t4_type[i0];
                              }

                              obj->nitems = 1;
                              ptr = (char *)(&arg);
                              for (loop_ub = 1; loop_ub <= sizepe; loop_ub++) {
                                obj->data->data[loop_ub - 1] = *(ptr);
                                ptr = ptr + 1;
                              }
                            } else {
                              if (5 > name->size[1]) {
                                i0 = 0;
                                sizepe = 0;
                              } else {
                                i0 = 4;
                                sizepe = name->size[1];
                              }

                              emxInit_char_T(&p_name, 2);
                              loop_ub = p_name->size[0] * p_name->size[1];
                              p_name->size[0] = 1;
                              p_name->size[1] = sizepe - i0;
                              emxEnsureCapacity((emxArray__common *)p_name,
                                                loop_ub, sizeof(char));
                              loop_ub = sizepe - i0;
                              for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                                p_name->data[p_name->size[0] * sizepe] =
                                  name->data[i0 + sizepe];
                              }

                              if (o_isequal(p_name)) {
                                arg = MPI_BYTE;
                                sizepe = sizeof(MPI_Datatype);
                                i0 = data0->size[0];
                                data0->size[0] = sizepe;
                                emxEnsureCapacity((emxArray__common *)data0, i0,
                                                  sizeof(unsigned char));
                                for (i0 = 0; i0 < 12; i0++) {
                                  t4_type[i0] = cv0[i0];
                                }

                                i0 = obj->data->size[0];
                                obj->data->size[0] = data0->size[0];
                                emxEnsureCapacity((emxArray__common *)obj->data,
                                                  i0, sizeof(unsigned char));
                                loop_ub = data0->size[0];
                                for (i0 = 0; i0 < loop_ub; i0++) {
                                  obj->data->data[i0] = data0->data[i0];
                                }

                                i0 = obj->type->size[0] * obj->type->size[1];
                                obj->type->size[0] = 1;
                                obj->type->size[1] = 12;
                                emxEnsureCapacity((emxArray__common *)obj->type,
                                                  i0, sizeof(char));
                                for (i0 = 0; i0 < 12; i0++) {
                                  obj->type->data[i0] = t4_type[i0];
                                }

                                obj->nitems = 1;
                                ptr = (char *)(&arg);
                                for (loop_ub = 1; loop_ub <= sizepe; loop_ub++)
                                {
                                  obj->data->data[loop_ub - 1] = *(ptr);
                                  ptr = ptr + 1;
                                }
                              } else {
                                if (5 > name->size[1]) {
                                  i0 = 0;
                                  sizepe = 0;
                                } else {
                                  i0 = 4;
                                  sizepe = name->size[1];
                                }

                                emxInit_char_T(&q_name, 2);
                                loop_ub = q_name->size[0] * q_name->size[1];
                                q_name->size[0] = 1;
                                q_name->size[1] = sizepe - i0;
                                emxEnsureCapacity((emxArray__common *)q_name,
                                                  loop_ub, sizeof(char));
                                loop_ub = sizepe - i0;
                                for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                                  q_name->data[q_name->size[0] * sizepe] =
                                    name->data[i0 + sizepe];
                                }

                                if (p_isequal(q_name)) {
                                  arg = MPI_2INT;
                                  sizepe = sizeof(MPI_Datatype);
                                  i0 = data0->size[0];
                                  data0->size[0] = sizepe;
                                  emxEnsureCapacity((emxArray__common *)data0,
                                                    i0, sizeof(unsigned char));
                                  for (i0 = 0; i0 < 12; i0++) {
                                    t4_type[i0] = cv0[i0];
                                  }

                                  i0 = obj->data->size[0];
                                  obj->data->size[0] = data0->size[0];
                                  emxEnsureCapacity((emxArray__common *)
                                                    obj->data, i0, sizeof
                                                    (unsigned char));
                                  loop_ub = data0->size[0];
                                  for (i0 = 0; i0 < loop_ub; i0++) {
                                    obj->data->data[i0] = data0->data[i0];
                                  }

                                  i0 = obj->type->size[0] * obj->type->size[1];
                                  obj->type->size[0] = 1;
                                  obj->type->size[1] = 12;
                                  emxEnsureCapacity((emxArray__common *)
                                                    obj->type, i0, sizeof(char));
                                  for (i0 = 0; i0 < 12; i0++) {
                                    obj->type->data[i0] = t4_type[i0];
                                  }

                                  obj->nitems = 1;
                                  ptr = (char *)(&arg);
                                  for (loop_ub = 1; loop_ub <= sizepe; loop_ub++)
                                  {
                                    obj->data->data[loop_ub - 1] = *(ptr);
                                    ptr = ptr + 1;
                                  }
                                } else {
                                  if (5 > name->size[1]) {
                                    i0 = 0;
                                    sizepe = 0;
                                  } else {
                                    i0 = 4;
                                    sizepe = name->size[1];
                                  }

                                  emxInit_char_T(&r_name, 2);
                                  loop_ub = r_name->size[0] * r_name->size[1];
                                  r_name->size[0] = 1;
                                  r_name->size[1] = sizepe - i0;
                                  emxEnsureCapacity((emxArray__common *)r_name,
                                                    loop_ub, sizeof(char));
                                  loop_ub = sizepe - i0;
                                  for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                                    r_name->data[r_name->size[0] * sizepe] =
                                      name->data[i0 + sizepe];
                                  }

                                  if (q_isequal(r_name)) {
                                    arg = MPI_SHORT_INT;
                                    sizepe = sizeof(MPI_Datatype);
                                    i0 = data0->size[0];
                                    data0->size[0] = sizepe;
                                    emxEnsureCapacity((emxArray__common *)data0,
                                                      i0, sizeof(unsigned char));
                                    for (i0 = 0; i0 < 12; i0++) {
                                      t4_type[i0] = cv0[i0];
                                    }

                                    i0 = obj->data->size[0];
                                    obj->data->size[0] = data0->size[0];
                                    emxEnsureCapacity((emxArray__common *)
                                                      obj->data, i0, sizeof
                                                      (unsigned char));
                                    loop_ub = data0->size[0];
                                    for (i0 = 0; i0 < loop_ub; i0++) {
                                      obj->data->data[i0] = data0->data[i0];
                                    }

                                    i0 = obj->type->size[0] * obj->type->size[1];
                                    obj->type->size[0] = 1;
                                    obj->type->size[1] = 12;
                                    emxEnsureCapacity((emxArray__common *)
                                                      obj->type, i0, sizeof(char));
                                    for (i0 = 0; i0 < 12; i0++) {
                                      obj->type->data[i0] = t4_type[i0];
                                    }

                                    obj->nitems = 1;
                                    ptr = (char *)(&arg);
                                    for (loop_ub = 1; loop_ub <= sizepe; loop_ub
                                         ++) {
                                      obj->data->data[loop_ub - 1] = *(ptr);
                                      ptr = ptr + 1;
                                    }
                                  } else {
                                    if (5 > name->size[1]) {
                                      i0 = 0;
                                      sizepe = 0;
                                    } else {
                                      i0 = 4;
                                      sizepe = name->size[1];
                                    }

                                    emxInit_char_T(&s_name, 2);
                                    loop_ub = s_name->size[0] * s_name->size[1];
                                    s_name->size[0] = 1;
                                    s_name->size[1] = sizepe - i0;
                                    emxEnsureCapacity((emxArray__common *)s_name,
                                                      loop_ub, sizeof(char));
                                    loop_ub = sizepe - i0;
                                    for (sizepe = 0; sizepe < loop_ub; sizepe++)
                                    {
                                      s_name->data[s_name->size[0] * sizepe] =
                                        name->data[i0 + sizepe];
                                    }

                                    if (r_isequal(s_name)) {
                                      arg = MPI_FLOAT_INT;
                                      sizepe = sizeof(MPI_Datatype);
                                      i0 = data0->size[0];
                                      data0->size[0] = sizepe;
                                      emxEnsureCapacity((emxArray__common *)
                                                        data0, i0, sizeof
                                                        (unsigned char));
                                      for (i0 = 0; i0 < 12; i0++) {
                                        t4_type[i0] = cv0[i0];
                                      }

                                      i0 = obj->data->size[0];
                                      obj->data->size[0] = data0->size[0];
                                      emxEnsureCapacity((emxArray__common *)
                                                        obj->data, i0, sizeof
                                                        (unsigned char));
                                      loop_ub = data0->size[0];
                                      for (i0 = 0; i0 < loop_ub; i0++) {
                                        obj->data->data[i0] = data0->data[i0];
                                      }

                                      i0 = obj->type->size[0] * obj->type->size
                                        [1];
                                      obj->type->size[0] = 1;
                                      obj->type->size[1] = 12;
                                      emxEnsureCapacity((emxArray__common *)
                                                        obj->type, i0, sizeof
                                                        (char));
                                      for (i0 = 0; i0 < 12; i0++) {
                                        obj->type->data[i0] = t4_type[i0];
                                      }

                                      obj->nitems = 1;
                                      ptr = (char *)(&arg);
                                      for (loop_ub = 1; loop_ub <= sizepe;
                                           loop_ub++) {
                                        obj->data->data[loop_ub - 1] = *(ptr);
                                        ptr = ptr + 1;
                                      }
                                    } else {
                                      if (5 > name->size[1]) {
                                        i0 = 0;
                                        sizepe = 0;
                                      } else {
                                        i0 = 4;
                                        sizepe = name->size[1];
                                      }

                                      emxInit_char_T(&t_name, 2);
                                      loop_ub = t_name->size[0] * t_name->size[1];
                                      t_name->size[0] = 1;
                                      t_name->size[1] = sizepe - i0;
                                      emxEnsureCapacity((emxArray__common *)
                                                        t_name, loop_ub, sizeof
                                                        (char));
                                      loop_ub = sizepe - i0;
                                      for (sizepe = 0; sizepe < loop_ub; sizepe
                                           ++) {
                                        t_name->data[t_name->size[0] * sizepe] =
                                          name->data[i0 + sizepe];
                                      }

                                      if (s_isequal(t_name)) {
                                        arg = MPI_DOUBLE_INT;
                                        sizepe = sizeof(MPI_Datatype);
                                        i0 = data0->size[0];
                                        data0->size[0] = sizepe;
                                        emxEnsureCapacity((emxArray__common *)
                                                          data0, i0, sizeof
                                                          (unsigned char));
                                        for (i0 = 0; i0 < 12; i0++) {
                                          t4_type[i0] = cv0[i0];
                                        }

                                        i0 = obj->data->size[0];
                                        obj->data->size[0] = data0->size[0];
                                        emxEnsureCapacity((emxArray__common *)
                                                          obj->data, i0, sizeof
                                                          (unsigned char));
                                        loop_ub = data0->size[0];
                                        for (i0 = 0; i0 < loop_ub; i0++) {
                                          obj->data->data[i0] = data0->data[i0];
                                        }

                                        i0 = obj->type->size[0] * obj->
                                          type->size[1];
                                        obj->type->size[0] = 1;
                                        obj->type->size[1] = 12;
                                        emxEnsureCapacity((emxArray__common *)
                                                          obj->type, i0, sizeof
                                                          (char));
                                        for (i0 = 0; i0 < 12; i0++) {
                                          obj->type->data[i0] = t4_type[i0];
                                        }

                                        obj->nitems = 1;
                                        ptr = (char *)(&arg);
                                        for (loop_ub = 1; loop_ub <= sizepe;
                                             loop_ub++) {
                                          obj->data->data[loop_ub - 1] = *(ptr);
                                          ptr = ptr + 1;
                                        }
                                      } else {
                                        if (5 > name->size[1]) {
                                          i0 = 0;
                                          sizepe = 0;
                                        } else {
                                          i0 = 4;
                                          sizepe = name->size[1];
                                        }

                                        emxInit_char_T(&u_name, 2);
                                        loop_ub = u_name->size[0] * u_name->
                                          size[1];
                                        u_name->size[0] = 1;
                                        u_name->size[1] = sizepe - i0;
                                        emxEnsureCapacity((emxArray__common *)
                                                          u_name, loop_ub,
                                                          sizeof(char));
                                        loop_ub = sizepe - i0;
                                        for (sizepe = 0; sizepe < loop_ub;
                                             sizepe++) {
                                          u_name->data[u_name->size[0] * sizepe]
                                            = name->data[i0 + sizepe];
                                        }

                                        if (t_isequal(u_name)) {
                                          arg = MPI_PACKED;
                                          sizepe = sizeof(MPI_Datatype);
                                          i0 = data0->size[0];
                                          data0->size[0] = sizepe;
                                          emxEnsureCapacity((emxArray__common *)
                                                            data0, i0, sizeof
                                                            (unsigned char));
                                          for (i0 = 0; i0 < 12; i0++) {
                                            t4_type[i0] = cv0[i0];
                                          }

                                          i0 = obj->data->size[0];
                                          obj->data->size[0] = data0->size[0];
                                          emxEnsureCapacity((emxArray__common *)
                                                            obj->data, i0,
                                                            sizeof(unsigned char));
                                          loop_ub = data0->size[0];
                                          for (i0 = 0; i0 < loop_ub; i0++) {
                                            obj->data->data[i0] = data0->data[i0];
                                          }

                                          i0 = obj->type->size[0] * obj->
                                            type->size[1];
                                          obj->type->size[0] = 1;
                                          obj->type->size[1] = 12;
                                          emxEnsureCapacity((emxArray__common *)
                                                            obj->type, i0,
                                                            sizeof(char));
                                          for (i0 = 0; i0 < 12; i0++) {
                                            obj->type->data[i0] = t4_type[i0];
                                          }

                                          obj->nitems = 1;
                                          ptr = (char *)(&arg);
                                          for (loop_ub = 1; loop_ub <= sizepe;
                                               loop_ub++) {
                                            obj->data->data[loop_ub - 1] = *(ptr);
                                            ptr = ptr + 1;
                                          }
                                        } else {
                                          if (5 > name->size[1]) {
                                            i0 = 0;
                                            sizepe = 0;
                                          } else {
                                            i0 = 4;
                                            sizepe = name->size[1];
                                          }

                                          emxInit_char_T(&v_name, 2);
                                          loop_ub = v_name->size[0] *
                                            v_name->size[1];
                                          v_name->size[0] = 1;
                                          v_name->size[1] = sizepe - i0;
                                          emxEnsureCapacity((emxArray__common *)
                                                            v_name, loop_ub,
                                                            sizeof(char));
                                          loop_ub = sizepe - i0;
                                          for (sizepe = 0; sizepe < loop_ub;
                                               sizepe++) {
                                            v_name->data[v_name->size[0] *
                                              sizepe] = name->data[i0 + sizepe];
                                          }

                                          if (u_isequal(v_name)) {
                                            arg = MPI_DATATYPE_NULL;
                                            sizepe = sizeof(MPI_Datatype);
                                            i0 = data0->size[0];
                                            data0->size[0] = sizepe;
                                            emxEnsureCapacity((emxArray__common *)
                                              data0, i0, sizeof(unsigned char));
                                            for (i0 = 0; i0 < 12; i0++) {
                                              t4_type[i0] = cv0[i0];
                                            }

                                            i0 = obj->data->size[0];
                                            obj->data->size[0] = data0->size[0];
                                            emxEnsureCapacity((emxArray__common *)
                                              obj->data, i0, sizeof(unsigned
                                              char));
                                            loop_ub = data0->size[0];
                                            for (i0 = 0; i0 < loop_ub; i0++) {
                                              obj->data->data[i0] = data0->
                                                data[i0];
                                            }

                                            i0 = obj->type->size[0] * obj->
                                              type->size[1];
                                            obj->type->size[0] = 1;
                                            obj->type->size[1] = 12;
                                            emxEnsureCapacity((emxArray__common *)
                                              obj->type, i0, sizeof(char));
                                            for (i0 = 0; i0 < 12; i0++) {
                                              obj->type->data[i0] = t4_type[i0];
                                            }

                                            obj->nitems = 1;
                                            ptr = (char *)(&arg);
                                            for (loop_ub = 1; loop_ub <= sizepe;
                                                 loop_ub++) {
                                              obj->data->data[loop_ub - 1] =
                                                *(ptr);
                                              ptr = ptr + 1;
                                            }
                                          } else {
                                            if (5 > name->size[1]) {
                                              i0 = 0;
                                              sizepe = 0;
                                            } else {
                                              i0 = 4;
                                              sizepe = name->size[1];
                                            }

                                            emxInit_char_T(&w_name, 2);
                                            loop_ub = w_name->size[0] *
                                              w_name->size[1];
                                            w_name->size[0] = 1;
                                            w_name->size[1] = sizepe - i0;
                                            emxEnsureCapacity((emxArray__common *)
                                              w_name, loop_ub, sizeof(char));
                                            loop_ub = sizepe - i0;
                                            for (sizepe = 0; sizepe < loop_ub;
                                                 sizepe++) {
                                              w_name->data[w_name->size[0] *
                                                sizepe] = name->data[i0 + sizepe];
                                            }

                                            if (v_isequal(w_name)) {
                                              b_arg = MPI_COMM_WORLD;
                                              sizepe = sizeof(MPI_Comm);
                                              i0 = data0->size[0];
                                              data0->size[0] = sizepe;
                                              emxEnsureCapacity
                                                ((emxArray__common *)data0, i0,
                                                 sizeof(unsigned char));
                                              for (i0 = 0; i0 < 8; i0++) {
                                                t3_type[i0] = cv1[i0];
                                              }

                                              i0 = obj->data->size[0];
                                              obj->data->size[0] = data0->size[0];
                                              emxEnsureCapacity
                                                ((emxArray__common *)obj->data,
                                                 i0, sizeof(unsigned char));
                                              loop_ub = data0->size[0];
                                              for (i0 = 0; i0 < loop_ub; i0++) {
                                                obj->data->data[i0] =
                                                  data0->data[i0];
                                              }

                                              i0 = obj->type->size[0] *
                                                obj->type->size[1];
                                              obj->type->size[0] = 1;
                                              obj->type->size[1] = 8;
                                              emxEnsureCapacity
                                                ((emxArray__common *)obj->type,
                                                 i0, sizeof(char));
                                              for (i0 = 0; i0 < 8; i0++) {
                                                obj->type->data[i0] = t3_type[i0];
                                              }

                                              obj->nitems = 1;
                                              ptr = (char *)(&b_arg);
                                              for (loop_ub = 1; loop_ub <=
                                                   sizepe; loop_ub++) {
                                                obj->data->data[loop_ub - 1] =
                                                  *(ptr);
                                                ptr = ptr + 1;
                                              }
                                            } else {
                                              if (5 > name->size[1]) {
                                                i0 = 0;
                                                sizepe = 0;
                                              } else {
                                                i0 = 4;
                                                sizepe = name->size[1];
                                              }

                                              emxInit_char_T(&x_name, 2);
                                              loop_ub = x_name->size[0] *
                                                x_name->size[1];
                                              x_name->size[0] = 1;
                                              x_name->size[1] = sizepe - i0;
                                              emxEnsureCapacity
                                                ((emxArray__common *)x_name,
                                                 loop_ub, sizeof(char));
                                              loop_ub = sizepe - i0;
                                              for (sizepe = 0; sizepe < loop_ub;
                                                   sizepe++) {
                                                x_name->data[x_name->size[0] *
                                                  sizepe] = name->data[i0 +
                                                  sizepe];
                                              }

                                              if (w_isequal(x_name)) {
                                                b_arg = MPI_COMM_SELF;
                                                sizepe = sizeof(MPI_Comm);
                                                i0 = data0->size[0];
                                                data0->size[0] = sizepe;
                                                emxEnsureCapacity
                                                  ((emxArray__common *)data0, i0,
                                                   sizeof(unsigned char));
                                                for (i0 = 0; i0 < 8; i0++) {
                                                  t3_type[i0] = cv1[i0];
                                                }

                                                i0 = obj->data->size[0];
                                                obj->data->size[0] = data0->
                                                  size[0];
                                                emxEnsureCapacity
                                                  ((emxArray__common *)obj->data,
                                                   i0, sizeof(unsigned char));
                                                loop_ub = data0->size[0];
                                                for (i0 = 0; i0 < loop_ub; i0++)
                                                {
                                                  obj->data->data[i0] =
                                                    data0->data[i0];
                                                }

                                                i0 = obj->type->size[0] *
                                                  obj->type->size[1];
                                                obj->type->size[0] = 1;
                                                obj->type->size[1] = 8;
                                                emxEnsureCapacity
                                                  ((emxArray__common *)obj->type,
                                                   i0, sizeof(char));
                                                for (i0 = 0; i0 < 8; i0++) {
                                                  obj->type->data[i0] =
                                                    t3_type[i0];
                                                }

                                                obj->nitems = 1;
                                                ptr = (char *)(&b_arg);
                                                for (loop_ub = 1; loop_ub <=
                                                     sizepe; loop_ub++) {
                                                  obj->data->data[loop_ub - 1] =
                                                    *(ptr);
                                                  ptr = ptr + 1;
                                                }
                                              } else {
                                                if (5 > name->size[1]) {
                                                  i0 = 0;
                                                  sizepe = 0;
                                                } else {
                                                  i0 = 4;
                                                  sizepe = name->size[1];
                                                }

                                                emxInit_char_T(&y_name, 2);
                                                loop_ub = y_name->size[0] *
                                                  y_name->size[1];
                                                y_name->size[0] = 1;
                                                y_name->size[1] = sizepe - i0;
                                                emxEnsureCapacity
                                                  ((emxArray__common *)y_name,
                                                   loop_ub, sizeof(char));
                                                loop_ub = sizepe - i0;
                                                for (sizepe = 0; sizepe <
                                                     loop_ub; sizepe++) {
                                                  y_name->data[y_name->size[0] *
                                                    sizepe] = name->data[i0 +
                                                    sizepe];
                                                }

                                                if (x_isequal(y_name)) {
                                                  b_arg = MPI_COMM_NULL;
                                                  sizepe = sizeof(MPI_Comm);
                                                  i0 = data0->size[0];
                                                  data0->size[0] = sizepe;
                                                  emxEnsureCapacity
                                                    ((emxArray__common *)data0,
                                                     i0, sizeof(unsigned char));
                                                  for (i0 = 0; i0 < 8; i0++) {
                                                    t3_type[i0] = cv1[i0];
                                                  }

                                                  i0 = obj->data->size[0];
                                                  obj->data->size[0] =
                                                    data0->size[0];
                                                  emxEnsureCapacity
                                                    ((emxArray__common *)
                                                     obj->data, i0, sizeof
                                                     (unsigned char));
                                                  loop_ub = data0->size[0];
                                                  for (i0 = 0; i0 < loop_ub; i0
                                                       ++) {
                                                    obj->data->data[i0] =
                                                      data0->data[i0];
                                                  }

                                                  i0 = obj->type->size[0] *
                                                    obj->type->size[1];
                                                  obj->type->size[0] = 1;
                                                  obj->type->size[1] = 8;
                                                  emxEnsureCapacity
                                                    ((emxArray__common *)
                                                     obj->type, i0, sizeof(char));
                                                  for (i0 = 0; i0 < 8; i0++) {
                                                    obj->type->data[i0] =
                                                      t3_type[i0];
                                                  }

                                                  obj->nitems = 1;
                                                  ptr = (char *)(&b_arg);
                                                  for (loop_ub = 1; loop_ub <=
                                                       sizepe; loop_ub++) {
                                                    obj->data->data[loop_ub - 1]
                                                      = *(ptr);
                                                    ptr = ptr + 1;
                                                  }
                                                } else {
                                                  if (5 > name->size[1]) {
                                                    i0 = 0;
                                                    sizepe = 0;
                                                  } else {
                                                    i0 = 4;
                                                    sizepe = name->size[1];
                                                  }

                                                  emxInit_char_T(&ab_name, 2);
                                                  loop_ub = ab_name->size[0] *
                                                    ab_name->size[1];
                                                  ab_name->size[0] = 1;
                                                  ab_name->size[1] = sizepe - i0;
                                                  emxEnsureCapacity
                                                    ((emxArray__common *)ab_name,
                                                     loop_ub, sizeof(char));
                                                  loop_ub = sizepe - i0;
                                                  for (sizepe = 0; sizepe <
                                                       loop_ub; sizepe++) {
                                                    ab_name->data[ab_name->size
                                                      [0] * sizepe] = name->
                                                      data[i0 + sizepe];
                                                  }

                                                  if (y_isequal(ab_name)) {
                                                    c_arg = MPI_SUM;
                                                    sizepe = sizeof(MPI_Op);
                                                    i0 = data0->size[0];
                                                    data0->size[0] = sizepe;
                                                    emxEnsureCapacity
                                                      ((emxArray__common *)data0,
                                                       i0, sizeof(unsigned char));
                                                    for (i0 = 0; i0 < 6; i0++) {
                                                      t0_type[i0] = cv2[i0];
                                                    }

                                                    i0 = obj->data->size[0];
                                                    obj->data->size[0] =
                                                      data0->size[0];
                                                    emxEnsureCapacity
                                                      ((emxArray__common *)
                                                       obj->data, i0, sizeof
                                                       (unsigned char));
                                                    loop_ub = data0->size[0];
                                                    for (i0 = 0; i0 < loop_ub;
                                                         i0++) {
                                                      obj->data->data[i0] =
                                                        data0->data[i0];
                                                    }

                                                    i0 = obj->type->size[0] *
                                                      obj->type->size[1];
                                                    obj->type->size[0] = 1;
                                                    obj->type->size[1] = 6;
                                                    emxEnsureCapacity
                                                      ((emxArray__common *)
                                                       obj->type, i0, sizeof
                                                       (char));
                                                    for (i0 = 0; i0 < 6; i0++) {
                                                      obj->type->data[i0] =
                                                        t0_type[i0];
                                                    }

                                                    obj->nitems = 1;
                                                    ptr = (char *)(&c_arg);
                                                    for (loop_ub = 1; loop_ub <=
                                                         sizepe; loop_ub++) {
                                                      obj->data->data[loop_ub -
                                                        1] = *(ptr);
                                                      ptr = ptr + 1;
                                                    }
                                                  } else {
                                                    if (5 > name->size[1]) {
                                                      i0 = 0;
                                                      sizepe = 0;
                                                    } else {
                                                      i0 = 4;
                                                      sizepe = name->size[1];
                                                    }

                                                    emxInit_char_T(&bb_name, 2);
                                                    loop_ub = bb_name->size[0] *
                                                      bb_name->size[1];
                                                    bb_name->size[0] = 1;
                                                    bb_name->size[1] = sizepe -
                                                      i0;
                                                    emxEnsureCapacity
                                                      ((emxArray__common *)
                                                       bb_name, loop_ub, sizeof
                                                       (char));
                                                    loop_ub = sizepe - i0;
                                                    for (sizepe = 0; sizepe <
                                                         loop_ub; sizepe++) {
                                                      bb_name->data
                                                        [bb_name->size[0] *
                                                        sizepe] = name->data[i0
                                                        + sizepe];
                                                    }

                                                    if (ab_isequal(bb_name)) {
                                                      c_arg = MPI_PROD;
                                                      sizepe = sizeof(MPI_Op);
                                                      i0 = data0->size[0];
                                                      data0->size[0] = sizepe;
                                                      emxEnsureCapacity
                                                        ((emxArray__common *)
                                                         data0, i0, sizeof
                                                         (unsigned char));
                                                      for (i0 = 0; i0 < 6; i0++)
                                                      {
                                                        t0_type[i0] = cv2[i0];
                                                      }

                                                      i0 = obj->data->size[0];
                                                      obj->data->size[0] =
                                                        data0->size[0];
                                                      emxEnsureCapacity
                                                        ((emxArray__common *)
                                                         obj->data, i0, sizeof
                                                         (unsigned char));
                                                      loop_ub = data0->size[0];
                                                      for (i0 = 0; i0 < loop_ub;
                                                           i0++) {
                                                        obj->data->data[i0] =
                                                          data0->data[i0];
                                                      }

                                                      i0 = obj->type->size[0] *
                                                        obj->type->size[1];
                                                      obj->type->size[0] = 1;
                                                      obj->type->size[1] = 6;
                                                      emxEnsureCapacity
                                                        ((emxArray__common *)
                                                         obj->type, i0, sizeof
                                                         (char));
                                                      for (i0 = 0; i0 < 6; i0++)
                                                      {
                                                        obj->type->data[i0] =
                                                          t0_type[i0];
                                                      }

                                                      obj->nitems = 1;
                                                      ptr = (char *)(&c_arg);
                                                      for (loop_ub = 1; loop_ub <=
                                                           sizepe; loop_ub++) {
                                                        obj->data->data[loop_ub
                                                          - 1] = *(ptr);
                                                        ptr = ptr + 1;
                                                      }
                                                    } else {
                                                      if (5 > name->size[1]) {
                                                        i0 = 0;
                                                        sizepe = 0;
                                                      } else {
                                                        i0 = 4;
                                                        sizepe = name->size[1];
                                                      }

                                                      emxInit_char_T(&cb_name, 2);
                                                      loop_ub = cb_name->size[0]
                                                        * cb_name->size[1];
                                                      cb_name->size[0] = 1;
                                                      cb_name->size[1] = sizepe
                                                        - i0;
                                                      emxEnsureCapacity
                                                        ((emxArray__common *)
                                                         cb_name, loop_ub,
                                                         sizeof(char));
                                                      loop_ub = sizepe - i0;
                                                      for (sizepe = 0; sizepe <
                                                           loop_ub; sizepe++) {
                                                        cb_name->data
                                                          [cb_name->size[0] *
                                                          sizepe] = name->
                                                          data[i0 + sizepe];
                                                      }

                                                      if (bb_isequal(cb_name)) {
                                                        c_arg = MPI_MIN;
                                                        sizepe = sizeof(MPI_Op);
                                                        i0 = data0->size[0];
                                                        data0->size[0] = sizepe;
                                                        emxEnsureCapacity
                                                          ((emxArray__common *)
                                                           data0, i0, sizeof
                                                           (unsigned char));
                                                        for (i0 = 0; i0 < 6; i0
                                                             ++) {
                                                          t0_type[i0] = cv2[i0];
                                                        }

                                                        i0 = obj->data->size[0];
                                                        obj->data->size[0] =
                                                          data0->size[0];
                                                        emxEnsureCapacity
                                                          ((emxArray__common *)
                                                           obj->data, i0, sizeof
                                                           (unsigned char));
                                                        loop_ub = data0->size[0];
                                                        for (i0 = 0; i0 <
                                                             loop_ub; i0++) {
                                                          obj->data->data[i0] =
                                                            data0->data[i0];
                                                        }

                                                        i0 = obj->type->size[0] *
                                                          obj->type->size[1];
                                                        obj->type->size[0] = 1;
                                                        obj->type->size[1] = 6;
                                                        emxEnsureCapacity
                                                          ((emxArray__common *)
                                                           obj->type, i0, sizeof
                                                           (char));
                                                        for (i0 = 0; i0 < 6; i0
                                                             ++) {
                                                          obj->type->data[i0] =
                                                            t0_type[i0];
                                                        }

                                                        obj->nitems = 1;
                                                        ptr = (char *)(&c_arg);
                                                        for (loop_ub = 1;
                                                             loop_ub <= sizepe;
                                                             loop_ub++) {
                                                          obj->data->
                                                            data[loop_ub - 1] = *
                                                            (ptr);
                                                          ptr = ptr + 1;
                                                        }
                                                      } else {
                                                        if (5 > name->size[1]) {
                                                          i0 = 0;
                                                          sizepe = 0;
                                                        } else {
                                                          i0 = 4;
                                                          sizepe = name->size[1];
                                                        }

                                                        emxInit_char_T(&db_name,
                                                          2);
                                                        loop_ub = db_name->size
                                                          [0] * db_name->size[1];
                                                        db_name->size[0] = 1;
                                                        db_name->size[1] =
                                                          sizepe - i0;
                                                        emxEnsureCapacity
                                                          ((emxArray__common *)
                                                           db_name, loop_ub,
                                                           sizeof(char));
                                                        loop_ub = sizepe - i0;
                                                        for (sizepe = 0; sizepe <
                                                             loop_ub; sizepe++)
                                                        {
                                                          db_name->data
                                                            [db_name->size[0] *
                                                            sizepe] = name->
                                                            data[i0 + sizepe];
                                                        }

                                                        if (cb_isequal(db_name))
                                                        {
                                                          c_arg = MPI_MAX;
                                                          sizepe = sizeof(MPI_Op);
                                                          i0 = data0->size[0];
                                                          data0->size[0] =
                                                            sizepe;
                                                          emxEnsureCapacity
                                                            ((emxArray__common *)
                                                             data0, i0, sizeof
                                                             (unsigned char));
                                                          for (i0 = 0; i0 < 6;
                                                               i0++) {
                                                            t0_type[i0] = cv2[i0];
                                                          }

                                                          i0 = obj->data->size[0];
                                                          obj->data->size[0] =
                                                            data0->size[0];
                                                          emxEnsureCapacity
                                                            ((emxArray__common *)
                                                             obj->data, i0,
                                                             sizeof(unsigned
                                                              char));
                                                          loop_ub = data0->size
                                                            [0];
                                                          for (i0 = 0; i0 <
                                                               loop_ub; i0++) {
                                                            obj->data->data[i0] =
                                                              data0->data[i0];
                                                          }

                                                          i0 = obj->type->size[0]
                                                            * obj->type->size[1];
                                                          obj->type->size[0] = 1;
                                                          obj->type->size[1] = 6;
                                                          emxEnsureCapacity
                                                            ((emxArray__common *)
                                                             obj->type, i0,
                                                             sizeof(char));
                                                          for (i0 = 0; i0 < 6;
                                                               i0++) {
                                                            obj->type->data[i0] =
                                                              t0_type[i0];
                                                          }

                                                          obj->nitems = 1;
                                                          ptr = (char *)(&c_arg);
                                                          for (loop_ub = 1;
                                                               loop_ub <= sizepe;
                                                               loop_ub++) {
                                                            obj->data->
                                                              data[loop_ub - 1] =
                                                              *(ptr);
                                                            ptr = ptr + 1;
                                                          }
                                                        } else {
                                                          if (5 > name->size[1])
                                                          {
                                                            i0 = 0;
                                                            sizepe = 0;
                                                          } else {
                                                            i0 = 4;
                                                            sizepe = name->size
                                                              [1];
                                                          }

                                                          emxInit_char_T
                                                            (&eb_name, 2);
                                                          loop_ub =
                                                            eb_name->size[0] *
                                                            eb_name->size[1];
                                                          eb_name->size[0] = 1;
                                                          eb_name->size[1] =
                                                            sizepe - i0;
                                                          emxEnsureCapacity
                                                            ((emxArray__common *)
                                                             eb_name, loop_ub,
                                                             sizeof(char));
                                                          loop_ub = sizepe - i0;
                                                          for (sizepe = 0;
                                                               sizepe < loop_ub;
                                                               sizepe++) {
                                                            eb_name->
                                                              data[eb_name->
                                                              size[0] * sizepe] =
                                                              name->data[i0 +
                                                              sizepe];
                                                          }

                                                          if (db_isequal(eb_name))
                                                          {
                                                            c_arg = MPI_BOR;
                                                            sizepe = sizeof
                                                              (MPI_Op);
                                                            i0 = data0->size[0];
                                                            data0->size[0] =
                                                              sizepe;
                                                            emxEnsureCapacity
                                                              ((emxArray__common
                                                                *)data0, i0,
                                                               sizeof(unsigned
                                                                char));
                                                            for (i0 = 0; i0 < 6;
                                                                 i0++) {
                                                              t0_type[i0] =
                                                                cv2[i0];
                                                            }

                                                            i0 = obj->data->
                                                              size[0];
                                                            obj->data->size[0] =
                                                              data0->size[0];
                                                            emxEnsureCapacity
                                                              ((emxArray__common
                                                                *)obj->data, i0,
                                                               sizeof(unsigned
                                                                char));
                                                            loop_ub =
                                                              data0->size[0];
                                                            for (i0 = 0; i0 <
                                                                 loop_ub; i0++)
                                                            {
                                                              obj->data->data[i0]
                                                                = data0->data[i0];
                                                            }

                                                            i0 = obj->type->
                                                              size[0] *
                                                              obj->type->size[1];
                                                            obj->type->size[0] =
                                                              1;
                                                            obj->type->size[1] =
                                                              6;
                                                            emxEnsureCapacity
                                                              ((emxArray__common
                                                                *)obj->type, i0,
                                                               sizeof(char));
                                                            for (i0 = 0; i0 < 6;
                                                                 i0++) {
                                                              obj->type->data[i0]
                                                                = t0_type[i0];
                                                            }

                                                            obj->nitems = 1;
                                                            ptr = (char *)
                                                              (&c_arg);
                                                            for (loop_ub = 1;
                                                                 loop_ub <=
                                                                 sizepe; loop_ub
                                                                 ++) {
                                                              obj->data->
                                                                data[loop_ub - 1]
                                                                = *(ptr);
                                                              ptr =
                                                                ptr + 1;
                                                            }
                                                          } else {
                                                            if (5 > name->size[1])
                                                            {
                                                              i0 = 0;
                                                              sizepe = 0;
                                                            } else {
                                                              i0 = 4;
                                                              sizepe =
                                                                name->size[1];
                                                            }

                                                            emxInit_char_T
                                                              (&fb_name, 2);
                                                            loop_ub =
                                                              fb_name->size[0] *
                                                              fb_name->size[1];
                                                            fb_name->size[0] = 1;
                                                            fb_name->size[1] =
                                                              sizepe - i0;
                                                            emxEnsureCapacity
                                                              ((emxArray__common
                                                                *)fb_name,
                                                               loop_ub, sizeof
                                                               (char));
                                                            loop_ub = sizepe -
                                                              i0;
                                                            for (sizepe = 0;
                                                                 sizepe <
                                                                 loop_ub; sizepe
                                                                 ++) {
                                                              fb_name->
                                                                data
                                                                [fb_name->size[0]
                                                                * sizepe] =
                                                                name->data[i0 +
                                                                sizepe];
                                                            }

                                                            if (eb_isequal
                                                                (fb_name)) {
                                                              c_arg = MPI_BAND;
                                                              sizepe = sizeof
                                                                (MPI_Op);
                                                              i0 = data0->size[0];
                                                              data0->size[0] =
                                                                sizepe;
                                                              emxEnsureCapacity
                                                                ((emxArray__common
                                                                  *)data0, i0,
                                                                 sizeof(unsigned
                                                                  char));
                                                              for (i0 = 0; i0 <
                                                                   6; i0++) {
                                                                t0_type[i0] =
                                                                  cv2[i0];
                                                              }

                                                              i0 = obj->
                                                                data->size[0];
                                                              obj->data->size[0]
                                                                = data0->size[0];
                                                              emxEnsureCapacity
                                                                ((emxArray__common
                                                                  *)obj->data,
                                                                 i0, sizeof
                                                                 (unsigned char));
                                                              loop_ub =
                                                                data0->size[0];
                                                              for (i0 = 0; i0 <
                                                                   loop_ub; i0++)
                                                              {
                                                                obj->data->
                                                                  data[i0] =
                                                                  data0->data[i0];
                                                              }

                                                              i0 = obj->
                                                                type->size[0] *
                                                                obj->type->size
                                                                [1];
                                                              obj->type->size[0]
                                                                = 1;
                                                              obj->type->size[1]
                                                                = 6;
                                                              emxEnsureCapacity
                                                                ((emxArray__common
                                                                  *)obj->type,
                                                                 i0, sizeof(char));
                                                              for (i0 = 0; i0 <
                                                                   6; i0++) {
                                                                obj->type->
                                                                  data[i0] =
                                                                  t0_type[i0];
                                                              }

                                                              obj->nitems = 1;
                                                              ptr = (char *)
                                                                (&c_arg);
                                                              for (loop_ub = 1;
                                                                   loop_ub <=
                                                                   sizepe;
                                                                   loop_ub++) {
                                                                obj->data->
                                                                  data[loop_ub -
                                                                  1] = *(ptr);
                                                                ptr =
                                                                  ptr + 1;
                                                              }
                                                            } else {
                                                              if (5 > name->
                                                                  size[1]) {
                                                                i0 = 0;
                                                                sizepe = 0;
                                                              } else {
                                                                i0 = 4;
                                                                sizepe =
                                                                  name->size[1];
                                                              }

                                                              emxInit_char_T
                                                                (&gb_name, 2);
                                                              loop_ub =
                                                                gb_name->size[0]
                                                                * gb_name->size
                                                                [1];
                                                              gb_name->size[0] =
                                                                1;
                                                              gb_name->size[1] =
                                                                sizepe - i0;
                                                              emxEnsureCapacity
                                                                ((emxArray__common
                                                                  *)gb_name,
                                                                 loop_ub, sizeof
                                                                (char));
                                                              loop_ub = sizepe -
                                                                i0;
                                                              for (sizepe = 0;
                                                                   sizepe <
                                                                   loop_ub;
                                                                   sizepe++) {
                                                                gb_name->
                                                                  data
                                                                  [gb_name->
                                                                  size[0] *
                                                                  sizepe] =
                                                                  name->data[i0
                                                                  + sizepe];
                                                              }

                                                              if (fb_isequal
                                                                  (gb_name)) {
                                                                c_arg = MPI_BXOR;
                                                                sizepe = sizeof
                                                                  (MPI_Op);
                                                                i0 = data0->
                                                                  size[0];
                                                                data0->size[0] =
                                                                  sizepe;
                                                                emxEnsureCapacity
                                                                  ((emxArray__common
                                                                    *)data0, i0,
                                                                   sizeof
                                                                   (unsigned
                                                                    char));
                                                                for (i0 = 0; i0 <
                                                                     6; i0++) {
                                                                  t0_type[i0] =
                                                                    cv2[i0];
                                                                }

                                                                i0 = obj->
                                                                  data->size[0];
                                                                obj->data->size
                                                                  [0] =
                                                                  data0->size[0];
                                                                emxEnsureCapacity
                                                                  ((emxArray__common
                                                                    *)obj->data,
                                                                   i0, sizeof
                                                                   (unsigned
                                                                    char));
                                                                loop_ub =
                                                                  data0->size[0];
                                                                for (i0 = 0; i0 <
                                                                     loop_ub; i0
                                                                     ++) {
                                                                  obj->
                                                                    data->
                                                                    data[i0] =
                                                                    data0->
                                                                    data[i0];
                                                                }

                                                                i0 = obj->
                                                                  type->size[0] *
                                                                  obj->
                                                                  type->size[1];
                                                                obj->type->size
                                                                  [0] = 1;
                                                                obj->type->size
                                                                  [1] = 6;
                                                                emxEnsureCapacity
                                                                  ((emxArray__common
                                                                    *)obj->type,
                                                                   i0, sizeof
                                                                   (char));
                                                                for (i0 = 0; i0 <
                                                                     6; i0++) {
                                                                  obj->
                                                                    type->
                                                                    data[i0] =
                                                                    t0_type[i0];
                                                                }

                                                                obj->nitems = 1;
                                                                ptr = (char *)
                                                                  (&c_arg);
                                                                for (loop_ub = 1;
                                                                     loop_ub <=
                                                                     sizepe;
                                                                     loop_ub++)
                                                                {
                                                                  obj->
                                                                    data->
                                                                    data[loop_ub
                                                                    - 1] = *(ptr);
                                                                  ptr =
                                                                    ptr + 1;
                                                                }
                                                              } else {
                                                                if (5 >
                                                                    name->size[1])
                                                                {
                                                                  i0 = 0;
                                                                  sizepe = 0;
                                                                } else {
                                                                  i0 = 4;
                                                                  sizepe =
                                                                    name->size[1];
                                                                }

                                                                emxInit_char_T
                                                                  (&hb_name, 2);
                                                                loop_ub =
                                                                  hb_name->size
                                                                  [0] *
                                                                  hb_name->size
                                                                  [1];
                                                                hb_name->size[0]
                                                                  = 1;
                                                                hb_name->size[1]
                                                                  = sizepe - i0;
                                                                emxEnsureCapacity
                                                                  ((emxArray__common
                                                                    *)hb_name,
                                                                   loop_ub,
                                                                   sizeof(char));
                                                                loop_ub = sizepe
                                                                  - i0;
                                                                for (sizepe = 0;
                                                                     sizepe <
                                                                     loop_ub;
                                                                     sizepe++) {
                                                                  hb_name->
                                                                    data
                                                                    [hb_name->size
                                                                    [0] * sizepe]
                                                                    = name->
                                                                    data[i0 +
                                                                    sizepe];
                                                                }

                                                                if (gb_isequal
                                                                    (hb_name)) {
                                                                  c_arg =
                                                                    MPI_LOR;
                                                                  sizepe =
                                                                    sizeof
                                                                    (MPI_Op);
                                                                  i0 =
                                                                    data0->size
                                                                    [0];
                                                                  data0->size[0]
                                                                    = sizepe;
                                                                  emxEnsureCapacity
                                                                    ((emxArray__common
                                                                      *)data0,
                                                                     i0, sizeof
                                                                     (unsigned
                                                                      char));
                                                                  for (i0 = 0;
                                                                      i0 < 6; i0
                                                                      ++) {
                                                                    t0_type[i0] =
                                                                      cv2[i0];
                                                                  }

                                                                  i0 = obj->
                                                                    data->size[0];
                                                                  obj->
                                                                    data->size[0]
                                                                    =
                                                                    data0->size
                                                                    [0];
                                                                  emxEnsureCapacity
                                                                    ((emxArray__common
                                                                      *)
                                                                     obj->data,
                                                                     i0, sizeof
                                                                     (unsigned
                                                                      char));
                                                                  loop_ub =
                                                                    data0->size
                                                                    [0];
                                                                  for (i0 = 0;
                                                                      i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                    obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                  }

                                                                  i0 = obj->
                                                                    type->size[0]
                                                                    * obj->
                                                                    type->size[1];
                                                                  obj->
                                                                    type->size[0]
                                                                    = 1;
                                                                  obj->
                                                                    type->size[1]
                                                                    = 6;
                                                                  emxEnsureCapacity
                                                                    ((emxArray__common
                                                                      *)
                                                                     obj->type,
                                                                     i0, sizeof
                                                                     (char));
                                                                  for (i0 = 0;
                                                                      i0 < 6; i0
                                                                      ++) {
                                                                    obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t0_type[i0];
                                                                  }

                                                                  obj->nitems =
                                                                    1;
                                                                  ptr = (char *)
                                                                    (&c_arg);
                                                                  for (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                  {
                                                                    obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                    ptr =
                                                                      ptr + 1;
                                                                  }
                                                                } else {
                                                                  if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                    i0 = 0;
                                                                    sizepe = 0;
                                                                  } else {
                                                                    i0 = 4;
                                                                    sizepe =
                                                                      name->
                                                                      size[1];
                                                                  }

                                                                  emxInit_char_T
                                                                    (&ib_name, 2);
                                                                  loop_ub =
                                                                    ib_name->size
                                                                    [0] *
                                                                    ib_name->size
                                                                    [1];
                                                                  ib_name->size
                                                                    [0] = 1;
                                                                  ib_name->size
                                                                    [1] = sizepe
                                                                    - i0;
                                                                  emxEnsureCapacity
                                                                    ((emxArray__common
                                                                      *)ib_name,
                                                                     loop_ub,
                                                                     sizeof(char));
                                                                  loop_ub =
                                                                    sizepe - i0;
                                                                  for (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                  {
                                                                    ib_name->data
                                                                      [ib_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                  }

                                                                  if (hb_isequal
                                                                      (ib_name))
                                                                  {
                                                                    c_arg =
                                                                      MPI_LAND;
                                                                    sizepe =
                                                                      sizeof
                                                                      (MPI_Op);
                                                                    i0 =
                                                                      data0->size
                                                                      [0];
                                                                    data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                    emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                    for (i0 = 0;
                                                                      i0 < 6; i0
                                                                      ++) {
                                                                      t0_type[i0]
                                                                      = cv2[i0];
                                                                    }

                                                                    i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                    obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                    emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                    loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                    for (i0 = 0;
                                                                      i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                    }

                                                                    i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                    obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                    obj->
                                                                      type->
                                                                      size[1] =
                                                                      6;
                                                                    emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                    for (i0 = 0;
                                                                      i0 < 6; i0
                                                                      ++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t0_type[i0];
                                                                    }

                                                                    obj->nitems =
                                                                      1;
                                                                    ptr = (char *)
                                                                      (&c_arg);
                                                                    for (loop_ub
                                                                      = 1;
                                                                      loop_ub <=
                                                                      sizepe;
                                                                      loop_ub++)
                                                                    {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                    }
                                                                  } else {
                                                                    if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                    } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                    }

                                                                    emxInit_char_T
                                                                      (&jb_name,
                                                                      2);
                                                                    loop_ub =
                                                                      jb_name->size
                                                                      [0] *
                                                                      jb_name->size
                                                                      [1];
                                                                    jb_name->size
                                                                      [0] = 1;
                                                                    jb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                    emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)jb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                    loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                    for (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                    {
                                                                      jb_name->data
                                                                      [jb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                    }

                                                                    if
                                                                      (ib_isequal
                                                                      (jb_name))
                                                                    {
                                                                      c_arg =
                                                                      MPI_LXOR;
                                                                      sizepe =
                                                                      sizeof
                                                                      (MPI_Op);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      t0_type[i0]
                                                                      = cv2[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      6;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t0_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&c_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                    } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&kb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      kb_name->size
                                                                      [0] *
                                                                      kb_name->size
                                                                      [1];
                                                                      kb_name->size
                                                                      [0] = 1;
                                                                      kb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)kb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      kb_name->data
                                                                      [kb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (jb_isequal
                                                                      (kb_name))
                                                                      {
                                                                      c_arg =
                                                                      MPI_MAXLOC;
                                                                      sizepe =
                                                                      sizeof
                                                                      (MPI_Op);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      t0_type[i0]
                                                                      = cv2[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      6;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t0_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&c_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&lb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      lb_name->size
                                                                      [0] *
                                                                      lb_name->size
                                                                      [1];
                                                                      lb_name->size
                                                                      [0] = 1;
                                                                      lb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)lb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      lb_name->data
                                                                      [lb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (kb_isequal
                                                                      (lb_name))
                                                                      {
                                                                      c_arg =
                                                                      MPI_MINLOC;
                                                                      sizepe =
                                                                      sizeof
                                                                      (MPI_Op);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      t0_type[i0]
                                                                      = cv2[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      6;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t0_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&c_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&mb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      mb_name->size
                                                                      [0] *
                                                                      mb_name->size
                                                                      [1];
                                                                      mb_name->size
                                                                      [0] = 1;
                                                                      mb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)mb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      mb_name->data
                                                                      [mb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (lb_isequal
                                                                      (mb_name))
                                                                      {
                                                                      c_arg =
                                                                      MPI_OP_NULL;
                                                                      sizepe =
                                                                      sizeof
                                                                      (MPI_Op);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      t0_type[i0]
                                                                      = cv2[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      6;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t0_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&c_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&nb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      nb_name->size
                                                                      [0] *
                                                                      nb_name->size
                                                                      [1];
                                                                      nb_name->size
                                                                      [0] = 1;
                                                                      nb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)nb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      nb_name->data
                                                                      [nb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (mb_isequal
                                                                      (nb_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_ANY_SOURCE;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      t7_type[i0]
                                                                      = cv3[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      3;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t7_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&ob_name,
                                                                      2);
                                                                      loop_ub =
                                                                      ob_name->size
                                                                      [0] *
                                                                      ob_name->size
                                                                      [1];
                                                                      ob_name->size
                                                                      [0] = 1;
                                                                      ob_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)ob_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      ob_name->data
                                                                      [ob_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (nb_isequal
                                                                      (ob_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_ANY_TAG;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      t7_type[i0]
                                                                      = cv3[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      3;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t7_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&pb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      pb_name->size
                                                                      [0] *
                                                                      pb_name->size
                                                                      [1];
                                                                      pb_name->size
                                                                      [0] = 1;
                                                                      pb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)pb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      pb_name->data
                                                                      [pb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (ob_isequal
                                                                      (pb_name))
                                                                      {
                                                                      e_arg =
                                                                      MPI_IN_PLACE;
                                                                      sizepe =
                                                                      sizeof
                                                                      (void *);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      t0_type[i0]
                                                                      = cv4[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      6;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t0_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&e_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&qb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      qb_name->size
                                                                      [0] *
                                                                      qb_name->size
                                                                      [1];
                                                                      qb_name->size
                                                                      [0] = 1;
                                                                      qb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)qb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      qb_name->data
                                                                      [qb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (pb_isequal
                                                                      (qb_name))
                                                                      {
                                                                      f_arg =
                                                                      MPI_ERRORS_ARE_FATAL;
                                                                      sizepe =
                                                                      sizeof
                                                                      (MPI_Errhandler);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 14;
                                                                      i0++) {
                                                                      t8_type[i0]
                                                                      = cv5[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      14;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 14;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t8_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&f_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&rb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      rb_name->size
                                                                      [0] *
                                                                      rb_name->size
                                                                      [1];
                                                                      rb_name->size
                                                                      [0] = 1;
                                                                      rb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)rb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      rb_name->data
                                                                      [rb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (qb_isequal
                                                                      (rb_name))
                                                                      {
                                                                      f_arg =
                                                                      MPI_ERRORS_RETURN;
                                                                      sizepe =
                                                                      sizeof
                                                                      (MPI_Errhandler);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 14;
                                                                      i0++) {
                                                                      t8_type[i0]
                                                                      = cv5[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      14;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 14;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t8_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&f_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&sb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      sb_name->size
                                                                      [0] *
                                                                      sb_name->size
                                                                      [1];
                                                                      sb_name->size
                                                                      [0] = 1;
                                                                      sb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)sb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      sb_name->data
                                                                      [sb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (rb_isequal
                                                                      (sb_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_BSEND_OVERHEAD;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      t7_type[i0]
                                                                      = cv3[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      3;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t7_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&tb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      tb_name->size
                                                                      [0] *
                                                                      tb_name->size
                                                                      [1];
                                                                      tb_name->size
                                                                      [0] = 1;
                                                                      tb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)tb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      tb_name->data
                                                                      [tb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (sb_isequal
                                                                      (tb_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_UNDEFINED;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      t7_type[i0]
                                                                      = cv3[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      3;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t7_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&ub_name,
                                                                      2);
                                                                      loop_ub =
                                                                      ub_name->size
                                                                      [0] *
                                                                      ub_name->size
                                                                      [1];
                                                                      ub_name->size
                                                                      [0] = 1;
                                                                      ub_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)ub_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      ub_name->data
                                                                      [ub_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (tb_isequal
                                                                      (ub_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_IDENT;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      t7_type[i0]
                                                                      = cv3[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      3;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t7_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&vb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      vb_name->size
                                                                      [0] *
                                                                      vb_name->size
                                                                      [1];
                                                                      vb_name->size
                                                                      [0] = 1;
                                                                      vb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)vb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      vb_name->data
                                                                      [vb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (ub_isequal
                                                                      (vb_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_CONGRUENT;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      t7_type[i0]
                                                                      = cv3[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      3;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t7_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&wb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      wb_name->size
                                                                      [0] *
                                                                      wb_name->size
                                                                      [1];
                                                                      wb_name->size
                                                                      [0] = 1;
                                                                      wb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)wb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      wb_name->data
                                                                      [wb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (vb_isequal
                                                                      (wb_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_SIMILAR;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      t7_type[i0]
                                                                      = cv3[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      3;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t7_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&xb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      xb_name->size
                                                                      [0] *
                                                                      xb_name->size
                                                                      [1];
                                                                      xb_name->size
                                                                      [0] = 1;
                                                                      xb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)xb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      xb_name->data
                                                                      [xb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (wb_isequal
                                                                      (xb_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_UNEQUAL;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      t7_type[i0]
                                                                      = cv3[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      3;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t7_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&yb_name,
                                                                      2);
                                                                      loop_ub =
                                                                      yb_name->size
                                                                      [0] *
                                                                      yb_name->size
                                                                      [1];
                                                                      yb_name->size
                                                                      [0] = 1;
                                                                      yb_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)yb_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      yb_name->data
                                                                      [yb_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (xb_isequal
                                                                      (yb_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_MAX_PROCESSOR_NAME;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      t7_type[i0]
                                                                      = cv3[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      3;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t7_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&ac_name,
                                                                      2);
                                                                      loop_ub =
                                                                      ac_name->size
                                                                      [0] *
                                                                      ac_name->size
                                                                      [1];
                                                                      ac_name->size
                                                                      [0] = 1;
                                                                      ac_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)ac_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      ac_name->data
                                                                      [ac_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (yb_isequal
                                                                      (ac_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_GRAPH;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      t7_type[i0]
                                                                      = cv3[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      3;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t7_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&bc_name,
                                                                      2);
                                                                      loop_ub =
                                                                      bc_name->size
                                                                      [0] *
                                                                      bc_name->size
                                                                      [1];
                                                                      bc_name->size
                                                                      [0] = 1;
                                                                      bc_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)bc_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      bc_name->data
                                                                      [bc_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (ac_isequal
                                                                      (bc_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_CART;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      t7_type[i0]
                                                                      = cv3[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      3;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 3;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t7_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&cc_name,
                                                                      2);
                                                                      loop_ub =
                                                                      cc_name->size
                                                                      [0] *
                                                                      cc_name->size
                                                                      [1];
                                                                      cc_name->size
                                                                      [0] = 1;
                                                                      cc_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)cc_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      cc_name->data
                                                                      [cc_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (bc_isequal
                                                                      (cc_name))
                                                                      {
                                                                      g_arg =
                                                                      MPI_REQUEST_NULL;
                                                                      sizepe =
                                                                      sizeof
                                                                      (MPI_Request);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 11;
                                                                      i0++) {
                                                                      t6_type[i0]
                                                                      = cv6[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      11;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 11;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t6_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&g_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&dc_name,
                                                                      2);
                                                                      loop_ub =
                                                                      dc_name->size
                                                                      [0] *
                                                                      dc_name->size
                                                                      [1];
                                                                      dc_name->size
                                                                      [0] = 1;
                                                                      dc_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)dc_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      dc_name->data
                                                                      [dc_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (cc_isequal
                                                                      (dc_name))
                                                                      {
                                                                      h_arg =
                                                                      MPI_GROUP_NULL;
                                                                      sizepe =
                                                                      sizeof
                                                                      (MPI_Group);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 9;
                                                                      i0++) {
                                                                      t5_type[i0]
                                                                      = cv7[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      9;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 9;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t5_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&h_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&ec_name,
                                                                      2);
                                                                      loop_ub =
                                                                      ec_name->size
                                                                      [0] *
                                                                      ec_name->size
                                                                      [1];
                                                                      ec_name->size
                                                                      [0] = 1;
                                                                      ec_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)ec_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      ec_name->data
                                                                      [ec_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (dc_isequal
                                                                      (ec_name))
                                                                      {
                                                                      h_arg =
                                                                      MPI_GROUP_EMPTY;
                                                                      sizepe =
                                                                      sizeof
                                                                      (MPI_Group);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 9;
                                                                      i0++) {
                                                                      t5_type[i0]
                                                                      = cv7[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      9;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 9;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t5_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&h_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&fc_name,
                                                                      2);
                                                                      loop_ub =
                                                                      fc_name->size
                                                                      [0] *
                                                                      fc_name->size
                                                                      [1];
                                                                      fc_name->size
                                                                      [0] = 1;
                                                                      fc_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)fc_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      fc_name->data
                                                                      [fc_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (ec_isequal
                                                                      (fc_name))
                                                                      {
                                                                      i_arg =
                                                                      MPI_STATUS_IGNORE;
                                                                      sizepe =
                                                                      sizeof
                                                                      (MPI_Status
                                                                      *);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 12;
                                                                      i0++) {
                                                                      t4_type[i0]
                                                                      = cv8[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      12;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 12;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t4_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&i_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&gc_name,
                                                                      2);
                                                                      loop_ub =
                                                                      gc_name->size
                                                                      [0] *
                                                                      gc_name->size
                                                                      [1];
                                                                      gc_name->size
                                                                      [0] = 1;
                                                                      gc_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)gc_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      gc_name->data
                                                                      [gc_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (fc_isequal
                                                                      (gc_name))
                                                                      {
                                                                      j_arg =
                                                                      MPI_INFO_NULL;
                                                                      sizepe =
                                                                      sizeof
                                                                      (MPI_Info);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 8;
                                                                      i0++) {
                                                                      t3_type[i0]
                                                                      = cv9[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      8;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 8;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t3_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&j_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&hc_name,
                                                                      2);
                                                                      loop_ub =
                                                                      hc_name->size
                                                                      [0] *
                                                                      hc_name->size
                                                                      [1];
                                                                      hc_name->size
                                                                      [0] = 1;
                                                                      hc_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)hc_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      hc_name->data
                                                                      [hc_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (gc_isequal
                                                                      (hc_name))
                                                                      {
                                                                      k_arg =
                                                                      MPI_ARGV_NULL;
                                                                      sizepe =
                                                                      sizeof
                                                                      (char **);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 7;
                                                                      i0++) {
                                                                      t2_type[i0]
                                                                      = cv10[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      7;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 7;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t2_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&k_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i0 = 0;
                                                                      sizepe = 0;
                                                                      } else {
                                                                      i0 = 4;
                                                                      sizepe =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      emxInit_char_T
                                                                      (&ic_name,
                                                                      2);
                                                                      loop_ub =
                                                                      ic_name->size
                                                                      [0] *
                                                                      ic_name->size
                                                                      [1];
                                                                      ic_name->size
                                                                      [0] = 1;
                                                                      ic_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)ic_name,
                                                                      loop_ub,
                                                                      sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      ic_name->data
                                                                      [ic_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (hc_isequal
                                                                      (ic_name))
                                                                      {
                                                                      l_arg =
                                                                      MPI_ERRCODES_IGNORE;
                                                                      sizepe =
                                                                      sizeof(int
                                                                      *);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 5;
                                                                      i0++) {
                                                                      t1_type[i0]
                                                                      = cv11[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      5;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 5;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t1_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&l_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      e_arg =
                                                                      NULL;
                                                                      sizepe =
                                                                      sizeof
                                                                      (void *);
                                                                      i0 =
                                                                      data0->size
                                                                      [0];
                                                                      data0->size
                                                                      [0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)data0,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      t0_type[i0]
                                                                      = cv4[i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      data0->size
                                                                      [0];
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->data,
                                                                      i0, sizeof
                                                                      (unsigned
                                                                      char));
                                                                      loop_ub =
                                                                      data0->size
                                                                      [0];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      obj->
                                                                      data->
                                                                      data[i0] =
                                                                      data0->data
                                                                      [i0];
                                                                      }

                                                                      i0 =
                                                                      obj->
                                                                      type->
                                                                      size[0] *
                                                                      obj->
                                                                      type->
                                                                      size[1];
                                                                      obj->
                                                                      type->
                                                                      size[0] =
                                                                      1;
                                                                      obj->
                                                                      type->
                                                                      size[1] =
                                                                      6;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)
                                                                      obj->type,
                                                                      i0, sizeof
                                                                      (char));
                                                                      for (i0 =
                                                                      0; i0 < 6;
                                                                      i0++) {
                                                                      obj->
                                                                      type->
                                                                      data[i0] =
                                                                      t0_type[i0];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&e_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      1; loop_ub
                                                                      <= sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub
                                                                      - 1] =
                                                                      *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }

                                                                      emxInit_char_T
                                                                      (&jc_name,
                                                                      2);
                                                                      i0 =
                                                                      jc_name->size
                                                                      [0] *
                                                                      jc_name->size
                                                                      [1];
                                                                      jc_name->size
                                                                      [0] = 1;
                                                                      jc_name->size
                                                                      [1] =
                                                                      name->
                                                                      size[1] +
                                                                      1;
                                                                      emxEnsureCapacity
                                                                      ((emxArray__common
                                                                      *)jc_name,
                                                                      i0, sizeof
                                                                      (char));
                                                                      loop_ub =
                                                                      name->
                                                                      size[1];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      jc_name->data
                                                                      [jc_name->size
                                                                      [0] * i0] =
                                                                      name->
                                                                      data
                                                                      [name->size
                                                                      [0] * i0];
                                                                      }

                                                                      jc_name->data
                                                                      [jc_name->size
                                                                      [0] *
                                                                      name->
                                                                      size[1]] =
                                                                      '\x00';
                                                                      m2c_error
                                                                      (jc_name);
                                                                      emxFree_char_T
                                                                      (&jc_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&ic_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&hc_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&gc_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&fc_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&ec_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&dc_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&cc_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&bc_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&ac_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&yb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&xb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&wb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&vb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&ub_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&tb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&sb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&rb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&qb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&pb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&ob_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&nb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&mb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&lb_name);
                                                                      }

                                                                      emxFree_char_T
                                                                      (&kb_name);
                                                                    }

                                                                    emxFree_char_T
                                                                      (&jb_name);
                                                                  }

                                                                  emxFree_char_T
                                                                    (&ib_name);
                                                                }

                                                                emxFree_char_T
                                                                  (&hb_name);
                                                              }

                                                              emxFree_char_T
                                                                (&gb_name);
                                                            }

                                                            emxFree_char_T
                                                              (&fb_name);
                                                          }

                                                          emxFree_char_T
                                                            (&eb_name);
                                                        }

                                                        emxFree_char_T(&db_name);
                                                      }

                                                      emxFree_char_T(&cb_name);
                                                    }

                                                    emxFree_char_T(&bb_name);
                                                  }

                                                  emxFree_char_T(&ab_name);
                                                }

                                                emxFree_char_T(&y_name);
                                              }

                                              emxFree_char_T(&x_name);
                                            }

                                            emxFree_char_T(&w_name);
                                          }

                                          emxFree_char_T(&v_name);
                                        }

                                        emxFree_char_T(&u_name);
                                      }

                                      emxFree_char_T(&t_name);
                                    }

                                    emxFree_char_T(&s_name);
                                  }

                                  emxFree_char_T(&r_name);
                                }

                                emxFree_char_T(&q_name);
                              }

                              emxFree_char_T(&p_name);
                            }

                            emxFree_char_T(&o_name);
                          }

                          emxFree_char_T(&n_name);
                        }

                        emxFree_char_T(&m_name);
                      }

                      emxFree_char_T(&l_name);
                    }

                    emxFree_char_T(&k_name);
                  }

                  emxFree_char_T(&j_name);
                }

                emxFree_char_T(&i_name);
              }

              emxFree_char_T(&h_name);
            }

            emxFree_char_T(&g_name);
          }

          emxFree_char_T(&f_name);
        }

        emxFree_char_T(&e_name);
      }

      emxFree_char_T(&d_name);
    }

    emxFree_char_T(&c_name);
  }

  emxFree_char_T(&b_name);
  emxFree_uint8_T(&data0);
}

void mpi_get_const_initialize(void)
{
}

void mpi_get_const_terminate(void)
{
}
