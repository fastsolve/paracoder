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
  emxEnsureCapacity_char_T(b_varargin_3, i1);
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
  char t4_type[12];
  static const char cv0[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  char * ptr;
  MPI_Comm b_arg;
  char t3_type[8];
  static const char cv1[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  MPI_Op c_arg;
  char t0_type[6];
  static const char cv2[6] = { 'M', 'P', 'I', '_', 'O', 'p' };

  int d_arg;
  char t7_type[3];
  static const char cv3[3] = { 'i', 'n', 't' };

  void * e_arg;
  static const char cv4[6] = { 'v', 'o', 'i', 'd', ' ', '*' };

  MPI_Errhandler f_arg;
  char t8_type[14];
  static const char cv5[14] = { 'M', 'P', 'I', '_', 'E', 'r', 'r', 'h', 'a', 'n',
    'd', 'l', 'e', 'r' };

  MPI_Request g_arg;
  char t6_type[11];
  static const char cv6[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  MPI_Group h_arg;
  char t5_type[9];
  static const char cv7[9] = { 'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p' };

  MPI_Status * i_arg;
  static const char cv8[12] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u', 's',
    ' ', '*' };

  MPI_Info j_arg;
  static const char cv9[8] = { 'M', 'P', 'I', '_', 'I', 'n', 'f', 'o' };

  char ** k_arg;
  char t2_type[7];
  static const char cv10[7] = { 'c', 'h', 'a', 'r', ' ', '*', '*' };

  int * l_arg;
  char t1_type[5];
  static const char cv11[5] = { 'i', 'n', 't', ' ', '*' };

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
  emxEnsureCapacity_char_T(b_name, loop_ub);
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
    emxEnsureCapacity_uint8_T(data0, i0);
    for (i0 = 0; i0 < 12; i0++) {
      t4_type[i0] = cv0[i0];
    }

    i0 = obj->data->size[0];
    obj->data->size[0] = data0->size[0];
    emxEnsureCapacity_uint8_T(obj->data, i0);
    loop_ub = data0->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      obj->data->data[i0] = data0->data[i0];
    }

    i0 = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 12;
    emxEnsureCapacity_char_T(obj->type, i0);
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

    loop_ub = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    b_name->size[1] = sizepe - i0;
    emxEnsureCapacity_char_T(b_name, loop_ub);
    loop_ub = sizepe - i0;
    for (sizepe = 0; sizepe < loop_ub; sizepe++) {
      b_name->data[b_name->size[0] * sizepe] = name->data[i0 + sizepe];
    }

    if (b_isequal(b_name)) {
      arg = MPI_DOUBLE;
      sizepe = sizeof(MPI_Datatype);
      i0 = data0->size[0];
      data0->size[0] = sizepe;
      emxEnsureCapacity_uint8_T(data0, i0);
      for (i0 = 0; i0 < 12; i0++) {
        t4_type[i0] = cv0[i0];
      }

      i0 = obj->data->size[0];
      obj->data->size[0] = data0->size[0];
      emxEnsureCapacity_uint8_T(obj->data, i0);
      loop_ub = data0->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        obj->data->data[i0] = data0->data[i0];
      }

      i0 = obj->type->size[0] * obj->type->size[1];
      obj->type->size[0] = 1;
      obj->type->size[1] = 12;
      emxEnsureCapacity_char_T(obj->type, i0);
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

      loop_ub = b_name->size[0] * b_name->size[1];
      b_name->size[0] = 1;
      b_name->size[1] = sizepe - i0;
      emxEnsureCapacity_char_T(b_name, loop_ub);
      loop_ub = sizepe - i0;
      for (sizepe = 0; sizepe < loop_ub; sizepe++) {
        b_name->data[b_name->size[0] * sizepe] = name->data[i0 + sizepe];
      }

      if (c_isequal(b_name)) {
        arg = MPI_LONG_DOUBLE;
        sizepe = sizeof(MPI_Datatype);
        i0 = data0->size[0];
        data0->size[0] = sizepe;
        emxEnsureCapacity_uint8_T(data0, i0);
        for (i0 = 0; i0 < 12; i0++) {
          t4_type[i0] = cv0[i0];
        }

        i0 = obj->data->size[0];
        obj->data->size[0] = data0->size[0];
        emxEnsureCapacity_uint8_T(obj->data, i0);
        loop_ub = data0->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          obj->data->data[i0] = data0->data[i0];
        }

        i0 = obj->type->size[0] * obj->type->size[1];
        obj->type->size[0] = 1;
        obj->type->size[1] = 12;
        emxEnsureCapacity_char_T(obj->type, i0);
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

        loop_ub = b_name->size[0] * b_name->size[1];
        b_name->size[0] = 1;
        b_name->size[1] = sizepe - i0;
        emxEnsureCapacity_char_T(b_name, loop_ub);
        loop_ub = sizepe - i0;
        for (sizepe = 0; sizepe < loop_ub; sizepe++) {
          b_name->data[b_name->size[0] * sizepe] = name->data[i0 + sizepe];
        }

        if (d_isequal(b_name)) {
          arg = MPI_INT;
          sizepe = sizeof(MPI_Datatype);
          i0 = data0->size[0];
          data0->size[0] = sizepe;
          emxEnsureCapacity_uint8_T(data0, i0);
          for (i0 = 0; i0 < 12; i0++) {
            t4_type[i0] = cv0[i0];
          }

          i0 = obj->data->size[0];
          obj->data->size[0] = data0->size[0];
          emxEnsureCapacity_uint8_T(obj->data, i0);
          loop_ub = data0->size[0];
          for (i0 = 0; i0 < loop_ub; i0++) {
            obj->data->data[i0] = data0->data[i0];
          }

          i0 = obj->type->size[0] * obj->type->size[1];
          obj->type->size[0] = 1;
          obj->type->size[1] = 12;
          emxEnsureCapacity_char_T(obj->type, i0);
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

          loop_ub = b_name->size[0] * b_name->size[1];
          b_name->size[0] = 1;
          b_name->size[1] = sizepe - i0;
          emxEnsureCapacity_char_T(b_name, loop_ub);
          loop_ub = sizepe - i0;
          for (sizepe = 0; sizepe < loop_ub; sizepe++) {
            b_name->data[b_name->size[0] * sizepe] = name->data[i0 + sizepe];
          }

          if (e_isequal(b_name)) {
            arg = MPI_UNSIGNED;
            sizepe = sizeof(MPI_Datatype);
            i0 = data0->size[0];
            data0->size[0] = sizepe;
            emxEnsureCapacity_uint8_T(data0, i0);
            for (i0 = 0; i0 < 12; i0++) {
              t4_type[i0] = cv0[i0];
            }

            i0 = obj->data->size[0];
            obj->data->size[0] = data0->size[0];
            emxEnsureCapacity_uint8_T(obj->data, i0);
            loop_ub = data0->size[0];
            for (i0 = 0; i0 < loop_ub; i0++) {
              obj->data->data[i0] = data0->data[i0];
            }

            i0 = obj->type->size[0] * obj->type->size[1];
            obj->type->size[0] = 1;
            obj->type->size[1] = 12;
            emxEnsureCapacity_char_T(obj->type, i0);
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

            loop_ub = b_name->size[0] * b_name->size[1];
            b_name->size[0] = 1;
            b_name->size[1] = sizepe - i0;
            emxEnsureCapacity_char_T(b_name, loop_ub);
            loop_ub = sizepe - i0;
            for (sizepe = 0; sizepe < loop_ub; sizepe++) {
              b_name->data[b_name->size[0] * sizepe] = name->data[i0 + sizepe];
            }

            if (f_isequal(b_name)) {
              arg = MPI_LONG;
              sizepe = sizeof(MPI_Datatype);
              i0 = data0->size[0];
              data0->size[0] = sizepe;
              emxEnsureCapacity_uint8_T(data0, i0);
              for (i0 = 0; i0 < 12; i0++) {
                t4_type[i0] = cv0[i0];
              }

              i0 = obj->data->size[0];
              obj->data->size[0] = data0->size[0];
              emxEnsureCapacity_uint8_T(obj->data, i0);
              loop_ub = data0->size[0];
              for (i0 = 0; i0 < loop_ub; i0++) {
                obj->data->data[i0] = data0->data[i0];
              }

              i0 = obj->type->size[0] * obj->type->size[1];
              obj->type->size[0] = 1;
              obj->type->size[1] = 12;
              emxEnsureCapacity_char_T(obj->type, i0);
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

              loop_ub = b_name->size[0] * b_name->size[1];
              b_name->size[0] = 1;
              b_name->size[1] = sizepe - i0;
              emxEnsureCapacity_char_T(b_name, loop_ub);
              loop_ub = sizepe - i0;
              for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                b_name->data[b_name->size[0] * sizepe] = name->data[i0 + sizepe];
              }

              if (g_isequal(b_name)) {
                arg = MPI_UNSIGNED_LONG;
                sizepe = sizeof(MPI_Datatype);
                i0 = data0->size[0];
                data0->size[0] = sizepe;
                emxEnsureCapacity_uint8_T(data0, i0);
                for (i0 = 0; i0 < 12; i0++) {
                  t4_type[i0] = cv0[i0];
                }

                i0 = obj->data->size[0];
                obj->data->size[0] = data0->size[0];
                emxEnsureCapacity_uint8_T(obj->data, i0);
                loop_ub = data0->size[0];
                for (i0 = 0; i0 < loop_ub; i0++) {
                  obj->data->data[i0] = data0->data[i0];
                }

                i0 = obj->type->size[0] * obj->type->size[1];
                obj->type->size[0] = 1;
                obj->type->size[1] = 12;
                emxEnsureCapacity_char_T(obj->type, i0);
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

                loop_ub = b_name->size[0] * b_name->size[1];
                b_name->size[0] = 1;
                b_name->size[1] = sizepe - i0;
                emxEnsureCapacity_char_T(b_name, loop_ub);
                loop_ub = sizepe - i0;
                for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                  b_name->data[b_name->size[0] * sizepe] = name->data[i0 +
                    sizepe];
                }

                if (h_isequal(b_name)) {
                  arg = MPI_LONG_LONG;
                  sizepe = sizeof(MPI_Datatype);
                  i0 = data0->size[0];
                  data0->size[0] = sizepe;
                  emxEnsureCapacity_uint8_T(data0, i0);
                  for (i0 = 0; i0 < 12; i0++) {
                    t4_type[i0] = cv0[i0];
                  }

                  i0 = obj->data->size[0];
                  obj->data->size[0] = data0->size[0];
                  emxEnsureCapacity_uint8_T(obj->data, i0);
                  loop_ub = data0->size[0];
                  for (i0 = 0; i0 < loop_ub; i0++) {
                    obj->data->data[i0] = data0->data[i0];
                  }

                  i0 = obj->type->size[0] * obj->type->size[1];
                  obj->type->size[0] = 1;
                  obj->type->size[1] = 12;
                  emxEnsureCapacity_char_T(obj->type, i0);
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

                  loop_ub = b_name->size[0] * b_name->size[1];
                  b_name->size[0] = 1;
                  b_name->size[1] = sizepe - i0;
                  emxEnsureCapacity_char_T(b_name, loop_ub);
                  loop_ub = sizepe - i0;
                  for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                    b_name->data[b_name->size[0] * sizepe] = name->data[i0 +
                      sizepe];
                  }

                  if (i_isequal(b_name)) {
                    arg = MPI_LONG_LONG_INT;
                    sizepe = sizeof(MPI_Datatype);
                    i0 = data0->size[0];
                    data0->size[0] = sizepe;
                    emxEnsureCapacity_uint8_T(data0, i0);
                    for (i0 = 0; i0 < 12; i0++) {
                      t4_type[i0] = cv0[i0];
                    }

                    i0 = obj->data->size[0];
                    obj->data->size[0] = data0->size[0];
                    emxEnsureCapacity_uint8_T(obj->data, i0);
                    loop_ub = data0->size[0];
                    for (i0 = 0; i0 < loop_ub; i0++) {
                      obj->data->data[i0] = data0->data[i0];
                    }

                    i0 = obj->type->size[0] * obj->type->size[1];
                    obj->type->size[0] = 1;
                    obj->type->size[1] = 12;
                    emxEnsureCapacity_char_T(obj->type, i0);
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

                    loop_ub = b_name->size[0] * b_name->size[1];
                    b_name->size[0] = 1;
                    b_name->size[1] = sizepe - i0;
                    emxEnsureCapacity_char_T(b_name, loop_ub);
                    loop_ub = sizepe - i0;
                    for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                      b_name->data[b_name->size[0] * sizepe] = name->data[i0 +
                        sizepe];
                    }

                    if (j_isequal(b_name)) {
                      arg = MPI_UNSIGNED_LONG_LONG;
                      sizepe = sizeof(MPI_Datatype);
                      i0 = data0->size[0];
                      data0->size[0] = sizepe;
                      emxEnsureCapacity_uint8_T(data0, i0);
                      for (i0 = 0; i0 < 12; i0++) {
                        t4_type[i0] = cv0[i0];
                      }

                      i0 = obj->data->size[0];
                      obj->data->size[0] = data0->size[0];
                      emxEnsureCapacity_uint8_T(obj->data, i0);
                      loop_ub = data0->size[0];
                      for (i0 = 0; i0 < loop_ub; i0++) {
                        obj->data->data[i0] = data0->data[i0];
                      }

                      i0 = obj->type->size[0] * obj->type->size[1];
                      obj->type->size[0] = 1;
                      obj->type->size[1] = 12;
                      emxEnsureCapacity_char_T(obj->type, i0);
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

                      loop_ub = b_name->size[0] * b_name->size[1];
                      b_name->size[0] = 1;
                      b_name->size[1] = sizepe - i0;
                      emxEnsureCapacity_char_T(b_name, loop_ub);
                      loop_ub = sizepe - i0;
                      for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                        b_name->data[b_name->size[0] * sizepe] = name->data[i0 +
                          sizepe];
                      }

                      if (k_isequal(b_name)) {
                        arg = MPI_SHORT;
                        sizepe = sizeof(MPI_Datatype);
                        i0 = data0->size[0];
                        data0->size[0] = sizepe;
                        emxEnsureCapacity_uint8_T(data0, i0);
                        for (i0 = 0; i0 < 12; i0++) {
                          t4_type[i0] = cv0[i0];
                        }

                        i0 = obj->data->size[0];
                        obj->data->size[0] = data0->size[0];
                        emxEnsureCapacity_uint8_T(obj->data, i0);
                        loop_ub = data0->size[0];
                        for (i0 = 0; i0 < loop_ub; i0++) {
                          obj->data->data[i0] = data0->data[i0];
                        }

                        i0 = obj->type->size[0] * obj->type->size[1];
                        obj->type->size[0] = 1;
                        obj->type->size[1] = 12;
                        emxEnsureCapacity_char_T(obj->type, i0);
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

                        loop_ub = b_name->size[0] * b_name->size[1];
                        b_name->size[0] = 1;
                        b_name->size[1] = sizepe - i0;
                        emxEnsureCapacity_char_T(b_name, loop_ub);
                        loop_ub = sizepe - i0;
                        for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                          b_name->data[b_name->size[0] * sizepe] = name->data[i0
                            + sizepe];
                        }

                        if (l_isequal(b_name)) {
                          arg = MPI_UNSIGNED_SHORT;
                          sizepe = sizeof(MPI_Datatype);
                          i0 = data0->size[0];
                          data0->size[0] = sizepe;
                          emxEnsureCapacity_uint8_T(data0, i0);
                          for (i0 = 0; i0 < 12; i0++) {
                            t4_type[i0] = cv0[i0];
                          }

                          i0 = obj->data->size[0];
                          obj->data->size[0] = data0->size[0];
                          emxEnsureCapacity_uint8_T(obj->data, i0);
                          loop_ub = data0->size[0];
                          for (i0 = 0; i0 < loop_ub; i0++) {
                            obj->data->data[i0] = data0->data[i0];
                          }

                          i0 = obj->type->size[0] * obj->type->size[1];
                          obj->type->size[0] = 1;
                          obj->type->size[1] = 12;
                          emxEnsureCapacity_char_T(obj->type, i0);
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

                          loop_ub = b_name->size[0] * b_name->size[1];
                          b_name->size[0] = 1;
                          b_name->size[1] = sizepe - i0;
                          emxEnsureCapacity_char_T(b_name, loop_ub);
                          loop_ub = sizepe - i0;
                          for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                            b_name->data[b_name->size[0] * sizepe] = name->
                              data[i0 + sizepe];
                          }

                          if (m_isequal(b_name)) {
                            arg = MPI_CHAR;
                            sizepe = sizeof(MPI_Datatype);
                            i0 = data0->size[0];
                            data0->size[0] = sizepe;
                            emxEnsureCapacity_uint8_T(data0, i0);
                            for (i0 = 0; i0 < 12; i0++) {
                              t4_type[i0] = cv0[i0];
                            }

                            i0 = obj->data->size[0];
                            obj->data->size[0] = data0->size[0];
                            emxEnsureCapacity_uint8_T(obj->data, i0);
                            loop_ub = data0->size[0];
                            for (i0 = 0; i0 < loop_ub; i0++) {
                              obj->data->data[i0] = data0->data[i0];
                            }

                            i0 = obj->type->size[0] * obj->type->size[1];
                            obj->type->size[0] = 1;
                            obj->type->size[1] = 12;
                            emxEnsureCapacity_char_T(obj->type, i0);
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

                            loop_ub = b_name->size[0] * b_name->size[1];
                            b_name->size[0] = 1;
                            b_name->size[1] = sizepe - i0;
                            emxEnsureCapacity_char_T(b_name, loop_ub);
                            loop_ub = sizepe - i0;
                            for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                              b_name->data[b_name->size[0] * sizepe] =
                                name->data[i0 + sizepe];
                            }

                            if (n_isequal(b_name)) {
                              arg = MPI_UNSIGNED_CHAR;
                              sizepe = sizeof(MPI_Datatype);
                              i0 = data0->size[0];
                              data0->size[0] = sizepe;
                              emxEnsureCapacity_uint8_T(data0, i0);
                              for (i0 = 0; i0 < 12; i0++) {
                                t4_type[i0] = cv0[i0];
                              }

                              i0 = obj->data->size[0];
                              obj->data->size[0] = data0->size[0];
                              emxEnsureCapacity_uint8_T(obj->data, i0);
                              loop_ub = data0->size[0];
                              for (i0 = 0; i0 < loop_ub; i0++) {
                                obj->data->data[i0] = data0->data[i0];
                              }

                              i0 = obj->type->size[0] * obj->type->size[1];
                              obj->type->size[0] = 1;
                              obj->type->size[1] = 12;
                              emxEnsureCapacity_char_T(obj->type, i0);
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

                              loop_ub = b_name->size[0] * b_name->size[1];
                              b_name->size[0] = 1;
                              b_name->size[1] = sizepe - i0;
                              emxEnsureCapacity_char_T(b_name, loop_ub);
                              loop_ub = sizepe - i0;
                              for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                                b_name->data[b_name->size[0] * sizepe] =
                                  name->data[i0 + sizepe];
                              }

                              if (o_isequal(b_name)) {
                                arg = MPI_BYTE;
                                sizepe = sizeof(MPI_Datatype);
                                i0 = data0->size[0];
                                data0->size[0] = sizepe;
                                emxEnsureCapacity_uint8_T(data0, i0);
                                for (i0 = 0; i0 < 12; i0++) {
                                  t4_type[i0] = cv0[i0];
                                }

                                i0 = obj->data->size[0];
                                obj->data->size[0] = data0->size[0];
                                emxEnsureCapacity_uint8_T(obj->data, i0);
                                loop_ub = data0->size[0];
                                for (i0 = 0; i0 < loop_ub; i0++) {
                                  obj->data->data[i0] = data0->data[i0];
                                }

                                i0 = obj->type->size[0] * obj->type->size[1];
                                obj->type->size[0] = 1;
                                obj->type->size[1] = 12;
                                emxEnsureCapacity_char_T(obj->type, i0);
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

                                loop_ub = b_name->size[0] * b_name->size[1];
                                b_name->size[0] = 1;
                                b_name->size[1] = sizepe - i0;
                                emxEnsureCapacity_char_T(b_name, loop_ub);
                                loop_ub = sizepe - i0;
                                for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                                  b_name->data[b_name->size[0] * sizepe] =
                                    name->data[i0 + sizepe];
                                }

                                if (p_isequal(b_name)) {
                                  arg = MPI_2INT;
                                  sizepe = sizeof(MPI_Datatype);
                                  i0 = data0->size[0];
                                  data0->size[0] = sizepe;
                                  emxEnsureCapacity_uint8_T(data0, i0);
                                  for (i0 = 0; i0 < 12; i0++) {
                                    t4_type[i0] = cv0[i0];
                                  }

                                  i0 = obj->data->size[0];
                                  obj->data->size[0] = data0->size[0];
                                  emxEnsureCapacity_uint8_T(obj->data, i0);
                                  loop_ub = data0->size[0];
                                  for (i0 = 0; i0 < loop_ub; i0++) {
                                    obj->data->data[i0] = data0->data[i0];
                                  }

                                  i0 = obj->type->size[0] * obj->type->size[1];
                                  obj->type->size[0] = 1;
                                  obj->type->size[1] = 12;
                                  emxEnsureCapacity_char_T(obj->type, i0);
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

                                  loop_ub = b_name->size[0] * b_name->size[1];
                                  b_name->size[0] = 1;
                                  b_name->size[1] = sizepe - i0;
                                  emxEnsureCapacity_char_T(b_name, loop_ub);
                                  loop_ub = sizepe - i0;
                                  for (sizepe = 0; sizepe < loop_ub; sizepe++) {
                                    b_name->data[b_name->size[0] * sizepe] =
                                      name->data[i0 + sizepe];
                                  }

                                  if (q_isequal(b_name)) {
                                    arg = MPI_SHORT_INT;
                                    sizepe = sizeof(MPI_Datatype);
                                    i0 = data0->size[0];
                                    data0->size[0] = sizepe;
                                    emxEnsureCapacity_uint8_T(data0, i0);
                                    for (i0 = 0; i0 < 12; i0++) {
                                      t4_type[i0] = cv0[i0];
                                    }

                                    i0 = obj->data->size[0];
                                    obj->data->size[0] = data0->size[0];
                                    emxEnsureCapacity_uint8_T(obj->data, i0);
                                    loop_ub = data0->size[0];
                                    for (i0 = 0; i0 < loop_ub; i0++) {
                                      obj->data->data[i0] = data0->data[i0];
                                    }

                                    i0 = obj->type->size[0] * obj->type->size[1];
                                    obj->type->size[0] = 1;
                                    obj->type->size[1] = 12;
                                    emxEnsureCapacity_char_T(obj->type, i0);
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

                                    loop_ub = b_name->size[0] * b_name->size[1];
                                    b_name->size[0] = 1;
                                    b_name->size[1] = sizepe - i0;
                                    emxEnsureCapacity_char_T(b_name, loop_ub);
                                    loop_ub = sizepe - i0;
                                    for (sizepe = 0; sizepe < loop_ub; sizepe++)
                                    {
                                      b_name->data[b_name->size[0] * sizepe] =
                                        name->data[i0 + sizepe];
                                    }

                                    if (r_isequal(b_name)) {
                                      arg = MPI_FLOAT_INT;
                                      sizepe = sizeof(MPI_Datatype);
                                      i0 = data0->size[0];
                                      data0->size[0] = sizepe;
                                      emxEnsureCapacity_uint8_T(data0, i0);
                                      for (i0 = 0; i0 < 12; i0++) {
                                        t4_type[i0] = cv0[i0];
                                      }

                                      i0 = obj->data->size[0];
                                      obj->data->size[0] = data0->size[0];
                                      emxEnsureCapacity_uint8_T(obj->data, i0);
                                      loop_ub = data0->size[0];
                                      for (i0 = 0; i0 < loop_ub; i0++) {
                                        obj->data->data[i0] = data0->data[i0];
                                      }

                                      i0 = obj->type->size[0] * obj->type->size
                                        [1];
                                      obj->type->size[0] = 1;
                                      obj->type->size[1] = 12;
                                      emxEnsureCapacity_char_T(obj->type, i0);
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

                                      loop_ub = b_name->size[0] * b_name->size[1];
                                      b_name->size[0] = 1;
                                      b_name->size[1] = sizepe - i0;
                                      emxEnsureCapacity_char_T(b_name, loop_ub);
                                      loop_ub = sizepe - i0;
                                      for (sizepe = 0; sizepe < loop_ub; sizepe
                                           ++) {
                                        b_name->data[b_name->size[0] * sizepe] =
                                          name->data[i0 + sizepe];
                                      }

                                      if (s_isequal(b_name)) {
                                        arg = MPI_DOUBLE_INT;
                                        sizepe = sizeof(MPI_Datatype);
                                        i0 = data0->size[0];
                                        data0->size[0] = sizepe;
                                        emxEnsureCapacity_uint8_T(data0, i0);
                                        for (i0 = 0; i0 < 12; i0++) {
                                          t4_type[i0] = cv0[i0];
                                        }

                                        i0 = obj->data->size[0];
                                        obj->data->size[0] = data0->size[0];
                                        emxEnsureCapacity_uint8_T(obj->data, i0);
                                        loop_ub = data0->size[0];
                                        for (i0 = 0; i0 < loop_ub; i0++) {
                                          obj->data->data[i0] = data0->data[i0];
                                        }

                                        i0 = obj->type->size[0] * obj->
                                          type->size[1];
                                        obj->type->size[0] = 1;
                                        obj->type->size[1] = 12;
                                        emxEnsureCapacity_char_T(obj->type, i0);
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

                                        loop_ub = b_name->size[0] * b_name->
                                          size[1];
                                        b_name->size[0] = 1;
                                        b_name->size[1] = sizepe - i0;
                                        emxEnsureCapacity_char_T(b_name, loop_ub);
                                        loop_ub = sizepe - i0;
                                        for (sizepe = 0; sizepe < loop_ub;
                                             sizepe++) {
                                          b_name->data[b_name->size[0] * sizepe]
                                            = name->data[i0 + sizepe];
                                        }

                                        if (t_isequal(b_name)) {
                                          arg = MPI_PACKED;
                                          sizepe = sizeof(MPI_Datatype);
                                          i0 = data0->size[0];
                                          data0->size[0] = sizepe;
                                          emxEnsureCapacity_uint8_T(data0, i0);
                                          for (i0 = 0; i0 < 12; i0++) {
                                            t4_type[i0] = cv0[i0];
                                          }

                                          i0 = obj->data->size[0];
                                          obj->data->size[0] = data0->size[0];
                                          emxEnsureCapacity_uint8_T(obj->data,
                                            i0);
                                          loop_ub = data0->size[0];
                                          for (i0 = 0; i0 < loop_ub; i0++) {
                                            obj->data->data[i0] = data0->data[i0];
                                          }

                                          i0 = obj->type->size[0] * obj->
                                            type->size[1];
                                          obj->type->size[0] = 1;
                                          obj->type->size[1] = 12;
                                          emxEnsureCapacity_char_T(obj->type, i0);
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

                                          loop_ub = b_name->size[0] *
                                            b_name->size[1];
                                          b_name->size[0] = 1;
                                          b_name->size[1] = sizepe - i0;
                                          emxEnsureCapacity_char_T(b_name,
                                            loop_ub);
                                          loop_ub = sizepe - i0;
                                          for (sizepe = 0; sizepe < loop_ub;
                                               sizepe++) {
                                            b_name->data[b_name->size[0] *
                                              sizepe] = name->data[i0 + sizepe];
                                          }

                                          if (u_isequal(b_name)) {
                                            arg = MPI_DATATYPE_NULL;
                                            sizepe = sizeof(MPI_Datatype);
                                            i0 = data0->size[0];
                                            data0->size[0] = sizepe;
                                            emxEnsureCapacity_uint8_T(data0, i0);
                                            for (i0 = 0; i0 < 12; i0++) {
                                              t4_type[i0] = cv0[i0];
                                            }

                                            i0 = obj->data->size[0];
                                            obj->data->size[0] = data0->size[0];
                                            emxEnsureCapacity_uint8_T(obj->data,
                                              i0);
                                            loop_ub = data0->size[0];
                                            for (i0 = 0; i0 < loop_ub; i0++) {
                                              obj->data->data[i0] = data0->
                                                data[i0];
                                            }

                                            i0 = obj->type->size[0] * obj->
                                              type->size[1];
                                            obj->type->size[0] = 1;
                                            obj->type->size[1] = 12;
                                            emxEnsureCapacity_char_T(obj->type,
                                              i0);
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

                                            loop_ub = b_name->size[0] *
                                              b_name->size[1];
                                            b_name->size[0] = 1;
                                            b_name->size[1] = sizepe - i0;
                                            emxEnsureCapacity_char_T(b_name,
                                              loop_ub);
                                            loop_ub = sizepe - i0;
                                            for (sizepe = 0; sizepe < loop_ub;
                                                 sizepe++) {
                                              b_name->data[b_name->size[0] *
                                                sizepe] = name->data[i0 + sizepe];
                                            }

                                            if (v_isequal(b_name)) {
                                              b_arg = MPI_COMM_WORLD;
                                              sizepe = sizeof(MPI_Comm);
                                              i0 = data0->size[0];
                                              data0->size[0] = sizepe;
                                              emxEnsureCapacity_uint8_T(data0,
                                                i0);
                                              for (i0 = 0; i0 < 8; i0++) {
                                                t3_type[i0] = cv1[i0];
                                              }

                                              i0 = obj->data->size[0];
                                              obj->data->size[0] = data0->size[0];
                                              emxEnsureCapacity_uint8_T
                                                (obj->data, i0);
                                              loop_ub = data0->size[0];
                                              for (i0 = 0; i0 < loop_ub; i0++) {
                                                obj->data->data[i0] =
                                                  data0->data[i0];
                                              }

                                              i0 = obj->type->size[0] *
                                                obj->type->size[1];
                                              obj->type->size[0] = 1;
                                              obj->type->size[1] = 8;
                                              emxEnsureCapacity_char_T(obj->type,
                                                i0);
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

                                              loop_ub = b_name->size[0] *
                                                b_name->size[1];
                                              b_name->size[0] = 1;
                                              b_name->size[1] = sizepe - i0;
                                              emxEnsureCapacity_char_T(b_name,
                                                loop_ub);
                                              loop_ub = sizepe - i0;
                                              for (sizepe = 0; sizepe < loop_ub;
                                                   sizepe++) {
                                                b_name->data[b_name->size[0] *
                                                  sizepe] = name->data[i0 +
                                                  sizepe];
                                              }

                                              if (w_isequal(b_name)) {
                                                b_arg = MPI_COMM_SELF;
                                                sizepe = sizeof(MPI_Comm);
                                                i0 = data0->size[0];
                                                data0->size[0] = sizepe;
                                                emxEnsureCapacity_uint8_T(data0,
                                                  i0);
                                                for (i0 = 0; i0 < 8; i0++) {
                                                  t3_type[i0] = cv1[i0];
                                                }

                                                i0 = obj->data->size[0];
                                                obj->data->size[0] = data0->
                                                  size[0];
                                                emxEnsureCapacity_uint8_T
                                                  (obj->data, i0);
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
                                                emxEnsureCapacity_char_T
                                                  (obj->type, i0);
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

                                                loop_ub = b_name->size[0] *
                                                  b_name->size[1];
                                                b_name->size[0] = 1;
                                                b_name->size[1] = sizepe - i0;
                                                emxEnsureCapacity_char_T(b_name,
                                                  loop_ub);
                                                loop_ub = sizepe - i0;
                                                for (sizepe = 0; sizepe <
                                                     loop_ub; sizepe++) {
                                                  b_name->data[b_name->size[0] *
                                                    sizepe] = name->data[i0 +
                                                    sizepe];
                                                }

                                                if (x_isequal(b_name)) {
                                                  b_arg = MPI_COMM_NULL;
                                                  sizepe = sizeof(MPI_Comm);
                                                  i0 = data0->size[0];
                                                  data0->size[0] = sizepe;
                                                  emxEnsureCapacity_uint8_T
                                                    (data0, i0);
                                                  for (i0 = 0; i0 < 8; i0++) {
                                                    t3_type[i0] = cv1[i0];
                                                  }

                                                  i0 = obj->data->size[0];
                                                  obj->data->size[0] =
                                                    data0->size[0];
                                                  emxEnsureCapacity_uint8_T
                                                    (obj->data, i0);
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
                                                  emxEnsureCapacity_char_T
                                                    (obj->type, i0);
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

                                                  loop_ub = b_name->size[0] *
                                                    b_name->size[1];
                                                  b_name->size[0] = 1;
                                                  b_name->size[1] = sizepe - i0;
                                                  emxEnsureCapacity_char_T
                                                    (b_name, loop_ub);
                                                  loop_ub = sizepe - i0;
                                                  for (sizepe = 0; sizepe <
                                                       loop_ub; sizepe++) {
                                                    b_name->data[b_name->size[0]
                                                      * sizepe] = name->data[i0
                                                      + sizepe];
                                                  }

                                                  if (y_isequal(b_name)) {
                                                    c_arg = MPI_SUM;
                                                    sizepe = sizeof(MPI_Op);
                                                    i0 = data0->size[0];
                                                    data0->size[0] = sizepe;
                                                    emxEnsureCapacity_uint8_T
                                                      (data0, i0);
                                                    for (i0 = 0; i0 < 6; i0++) {
                                                      t0_type[i0] = cv2[i0];
                                                    }

                                                    i0 = obj->data->size[0];
                                                    obj->data->size[0] =
                                                      data0->size[0];
                                                    emxEnsureCapacity_uint8_T
                                                      (obj->data, i0);
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
                                                    emxEnsureCapacity_char_T
                                                      (obj->type, i0);
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

                                                    loop_ub = b_name->size[0] *
                                                      b_name->size[1];
                                                    b_name->size[0] = 1;
                                                    b_name->size[1] = sizepe -
                                                      i0;
                                                    emxEnsureCapacity_char_T
                                                      (b_name, loop_ub);
                                                    loop_ub = sizepe - i0;
                                                    for (sizepe = 0; sizepe <
                                                         loop_ub; sizepe++) {
                                                      b_name->data[b_name->size
                                                        [0] * sizepe] =
                                                        name->data[i0 + sizepe];
                                                    }

                                                    if (ab_isequal(b_name)) {
                                                      c_arg = MPI_PROD;
                                                      sizepe = sizeof(MPI_Op);
                                                      i0 = data0->size[0];
                                                      data0->size[0] = sizepe;
                                                      emxEnsureCapacity_uint8_T
                                                        (data0, i0);
                                                      for (i0 = 0; i0 < 6; i0++)
                                                      {
                                                        t0_type[i0] = cv2[i0];
                                                      }

                                                      i0 = obj->data->size[0];
                                                      obj->data->size[0] =
                                                        data0->size[0];
                                                      emxEnsureCapacity_uint8_T
                                                        (obj->data, i0);
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
                                                      emxEnsureCapacity_char_T
                                                        (obj->type, i0);
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

                                                      loop_ub = b_name->size[0] *
                                                        b_name->size[1];
                                                      b_name->size[0] = 1;
                                                      b_name->size[1] = sizepe -
                                                        i0;
                                                      emxEnsureCapacity_char_T
                                                        (b_name, loop_ub);
                                                      loop_ub = sizepe - i0;
                                                      for (sizepe = 0; sizepe <
                                                           loop_ub; sizepe++) {
                                                        b_name->data
                                                          [b_name->size[0] *
                                                          sizepe] = name->
                                                          data[i0 + sizepe];
                                                      }

                                                      if (bb_isequal(b_name)) {
                                                        c_arg = MPI_MIN;
                                                        sizepe = sizeof(MPI_Op);
                                                        i0 = data0->size[0];
                                                        data0->size[0] = sizepe;
                                                        emxEnsureCapacity_uint8_T
                                                          (data0, i0);
                                                        for (i0 = 0; i0 < 6; i0
                                                             ++) {
                                                          t0_type[i0] = cv2[i0];
                                                        }

                                                        i0 = obj->data->size[0];
                                                        obj->data->size[0] =
                                                          data0->size[0];
                                                        emxEnsureCapacity_uint8_T
                                                          (obj->data, i0);
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
                                                        emxEnsureCapacity_char_T
                                                          (obj->type, i0);
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

                                                        loop_ub = b_name->size[0]
                                                          * b_name->size[1];
                                                        b_name->size[0] = 1;
                                                        b_name->size[1] = sizepe
                                                          - i0;
                                                        emxEnsureCapacity_char_T
                                                          (b_name, loop_ub);
                                                        loop_ub = sizepe - i0;
                                                        for (sizepe = 0; sizepe <
                                                             loop_ub; sizepe++)
                                                        {
                                                          b_name->data
                                                            [b_name->size[0] *
                                                            sizepe] = name->
                                                            data[i0 + sizepe];
                                                        }

                                                        if (cb_isequal(b_name))
                                                        {
                                                          c_arg = MPI_MAX;
                                                          sizepe = sizeof(MPI_Op);
                                                          i0 = data0->size[0];
                                                          data0->size[0] =
                                                            sizepe;
                                                          emxEnsureCapacity_uint8_T
                                                            (data0, i0);
                                                          for (i0 = 0; i0 < 6;
                                                               i0++) {
                                                            t0_type[i0] = cv2[i0];
                                                          }

                                                          i0 = obj->data->size[0];
                                                          obj->data->size[0] =
                                                            data0->size[0];
                                                          emxEnsureCapacity_uint8_T
                                                            (obj->data, i0);
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
                                                          emxEnsureCapacity_char_T
                                                            (obj->type, i0);
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

                                                          loop_ub = b_name->
                                                            size[0] *
                                                            b_name->size[1];
                                                          b_name->size[0] = 1;
                                                          b_name->size[1] =
                                                            sizepe - i0;
                                                          emxEnsureCapacity_char_T
                                                            (b_name, loop_ub);
                                                          loop_ub = sizepe - i0;
                                                          for (sizepe = 0;
                                                               sizepe < loop_ub;
                                                               sizepe++) {
                                                            b_name->data
                                                              [b_name->size[0] *
                                                              sizepe] =
                                                              name->data[i0 +
                                                              sizepe];
                                                          }

                                                          if (db_isequal(b_name))
                                                          {
                                                            c_arg = MPI_BOR;
                                                            sizepe = sizeof
                                                              (MPI_Op);
                                                            i0 = data0->size[0];
                                                            data0->size[0] =
                                                              sizepe;
                                                            emxEnsureCapacity_uint8_T
                                                              (data0, i0);
                                                            for (i0 = 0; i0 < 6;
                                                                 i0++) {
                                                              t0_type[i0] =
                                                                cv2[i0];
                                                            }

                                                            i0 = obj->data->
                                                              size[0];
                                                            obj->data->size[0] =
                                                              data0->size[0];
                                                            emxEnsureCapacity_uint8_T
                                                              (obj->data, i0);
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
                                                            emxEnsureCapacity_char_T
                                                              (obj->type, i0);
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

                                                            loop_ub =
                                                              b_name->size[0] *
                                                              b_name->size[1];
                                                            b_name->size[0] = 1;
                                                            b_name->size[1] =
                                                              sizepe - i0;
                                                            emxEnsureCapacity_char_T
                                                              (b_name, loop_ub);
                                                            loop_ub = sizepe -
                                                              i0;
                                                            for (sizepe = 0;
                                                                 sizepe <
                                                                 loop_ub; sizepe
                                                                 ++) {
                                                              b_name->
                                                                data
                                                                [b_name->size[0]
                                                                * sizepe] =
                                                                name->data[i0 +
                                                                sizepe];
                                                            }

                                                            if (eb_isequal
                                                                (b_name)) {
                                                              c_arg = MPI_BAND;
                                                              sizepe = sizeof
                                                                (MPI_Op);
                                                              i0 = data0->size[0];
                                                              data0->size[0] =
                                                                sizepe;
                                                              emxEnsureCapacity_uint8_T
                                                                (data0, i0);
                                                              for (i0 = 0; i0 <
                                                                   6; i0++) {
                                                                t0_type[i0] =
                                                                  cv2[i0];
                                                              }

                                                              i0 = obj->
                                                                data->size[0];
                                                              obj->data->size[0]
                                                                = data0->size[0];
                                                              emxEnsureCapacity_uint8_T
                                                                (obj->data, i0);
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
                                                              emxEnsureCapacity_char_T
                                                                (obj->type, i0);
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

                                                              loop_ub =
                                                                b_name->size[0] *
                                                                b_name->size[1];
                                                              b_name->size[0] =
                                                                1;
                                                              b_name->size[1] =
                                                                sizepe - i0;
                                                              emxEnsureCapacity_char_T
                                                                (b_name, loop_ub);
                                                              loop_ub = sizepe -
                                                                i0;
                                                              for (sizepe = 0;
                                                                   sizepe <
                                                                   loop_ub;
                                                                   sizepe++) {
                                                                b_name->
                                                                  data
                                                                  [b_name->size
                                                                  [0] * sizepe] =
                                                                  name->data[i0
                                                                  + sizepe];
                                                              }

                                                              if (fb_isequal
                                                                  (b_name)) {
                                                                c_arg = MPI_BXOR;
                                                                sizepe = sizeof
                                                                  (MPI_Op);
                                                                i0 = data0->
                                                                  size[0];
                                                                data0->size[0] =
                                                                  sizepe;
                                                                emxEnsureCapacity_uint8_T
                                                                  (data0, i0);
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
                                                                emxEnsureCapacity_uint8_T
                                                                  (obj->data, i0);
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
                                                                emxEnsureCapacity_char_T
                                                                  (obj->type, i0);
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

                                                                loop_ub =
                                                                  b_name->size[0]
                                                                  * b_name->
                                                                  size[1];
                                                                b_name->size[0] =
                                                                  1;
                                                                b_name->size[1] =
                                                                  sizepe - i0;
                                                                emxEnsureCapacity_char_T
                                                                  (b_name,
                                                                   loop_ub);
                                                                loop_ub = sizepe
                                                                  - i0;
                                                                for (sizepe = 0;
                                                                     sizepe <
                                                                     loop_ub;
                                                                     sizepe++) {
                                                                  b_name->
                                                                    data
                                                                    [b_name->size
                                                                    [0] * sizepe]
                                                                    = name->
                                                                    data[i0 +
                                                                    sizepe];
                                                                }

                                                                if (gb_isequal
                                                                    (b_name)) {
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
                                                                  emxEnsureCapacity_uint8_T
                                                                    (data0, i0);
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
                                                                  emxEnsureCapacity_uint8_T
                                                                    (obj->data,
                                                                     i0);
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
                                                                  emxEnsureCapacity_char_T
                                                                    (obj->type,
                                                                     i0);
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

                                                                  loop_ub =
                                                                    b_name->
                                                                    size[0] *
                                                                    b_name->
                                                                    size[1];
                                                                  b_name->size[0]
                                                                    = 1;
                                                                  b_name->size[1]
                                                                    = sizepe -
                                                                    i0;
                                                                  emxEnsureCapacity_char_T
                                                                    (b_name,
                                                                     loop_ub);
                                                                  loop_ub =
                                                                    sizepe - i0;
                                                                  for (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                  {
                                                                    b_name->
                                                                      data[b_name
                                                                      ->size[0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                  }

                                                                  if (hb_isequal
                                                                      (b_name))
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
                                                                    emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                    emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                    emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                    loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                    b_name->
                                                                      size[0] =
                                                                      1;
                                                                    b_name->
                                                                      size[1] =
                                                                      sizepe -
                                                                      i0;
                                                                    emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                    loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                    for (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                    {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                    }

                                                                    if
                                                                      (ib_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (jb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (kb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (lb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (mb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (nb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (ob_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (pb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (qb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (rb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (sb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (tb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (ub_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (vb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (wb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (xb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (yb_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (ac_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (bc_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (cc_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (dc_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (ec_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (fc_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (gc_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      loop_ub =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      sizepe -
                                                                      i0;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      loop_ub);
                                                                      loop_ub =
                                                                      sizepe -
                                                                      i0;
                                                                      for
                                                                      (sizepe =
                                                                      0; sizepe <
                                                                      loop_ub;
                                                                      sizepe++)
                                                                      {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      sizepe] =
                                                                      name->
                                                                      data[i0 +
                                                                      sizepe];
                                                                      }

                                                                      if
                                                                      (hc_isequal
                                                                      (b_name))
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (data0, i0);
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
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i0);
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
                                                                      emxEnsureCapacity_char_T
                                                                      (obj->type,
                                                                      i0);
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

                                                                      i0 =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      b_name->size
                                                                      [1] =
                                                                      name->
                                                                      size[1] +
                                                                      1;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      i0);
                                                                      loop_ub =
                                                                      name->
                                                                      size[1];
                                                                      for (i0 =
                                                                      0; i0 <
                                                                      loop_ub;
                                                                      i0++) {
                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] * i0] =
                                                                      name->
                                                                      data
                                                                      [name->size
                                                                      [0] * i0];
                                                                      }

                                                                      b_name->data
                                                                      [b_name->size
                                                                      [0] *
                                                                      name->
                                                                      size[1]] =
                                                                      '\x00';
                                                                      m2c_error
                                                                      (b_name);
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

  emxFree_char_T(&b_name);
  emxFree_uint8_T(&data0);
}

void mpi_get_const_initialize(void)
{
}

void mpi_get_const_terminate(void)
{
}
