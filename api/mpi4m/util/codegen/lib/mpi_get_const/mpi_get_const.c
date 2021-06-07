#include "mpi_get_const.h"
#include "mpi_get_const_types.h"
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
  static const char cv[4] = { 'P', 'R', 'O', 'D' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T ac_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[4] = { 'C', 'A', 'R', 'T' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T b_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[6] = { 'D', 'O', 'U', 'B', 'L', 'E' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T bb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[3] = { 'M', 'I', 'N' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T bc_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[12] = { 'R', 'E', 'Q', 'U', 'E', 'S', 'T', '_', 'N', 'U',
    'L', 'L' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 12) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T c_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[11] = { 'L', 'O', 'N', 'G', '_', 'D', 'O', 'U', 'B', 'L',
    'E' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T cb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[3] = { 'M', 'A', 'X' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T cc_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[10] = { 'G', 'R', 'O', 'U', 'P', '_', 'N', 'U', 'L', 'L'
  };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T d_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[3] = { 'I', 'N', 'T' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T db_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[3] = { 'B', 'O', 'R' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T dc_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[11] = { 'G', 'R', 'O', 'U', 'P', '_', 'E', 'M', 'P', 'T',
    'Y' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 11) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 11)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T e_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[8] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T eb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[4] = { 'B', 'A', 'N', 'D' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T ec_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[13] = { 'S', 'T', 'A', 'T', 'U', 'S', '_', 'I', 'G', 'N',
    'O', 'R', 'E' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T f_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[4] = { 'L', 'O', 'N', 'G' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T fb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[4] = { 'B', 'X', 'O', 'R' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T fc_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[9] = { 'I', 'N', 'F', 'O', '_', 'N', 'U', 'L', 'L' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T g_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[13] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_', 'L',
    'O', 'N', 'G' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T gb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[3] = { 'L', 'O', 'R' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T gc_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[9] = { 'A', 'R', 'G', 'V', '_', 'N', 'U', 'L', 'L' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T h_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[9] = { 'L', 'O', 'N', 'G', '_', 'L', 'O', 'N', 'G' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T hb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[4] = { 'L', 'A', 'N', 'D' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T hc_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[15] = { 'E', 'R', 'R', 'C', 'O', 'D', 'E', 'S', '_', 'I',
    'G', 'N', 'O', 'R', 'E' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 15) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 15)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T i_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[13] = { 'L', 'O', 'N', 'G', '_', 'L', 'O', 'N', 'G', '_',
    'I', 'N', 'T' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T ib_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[4] = { 'L', 'X', 'O', 'R' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[5] = { 'F', 'L', 'O', 'A', 'T' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T j_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[18] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_', 'L',
    'O', 'N', 'G', '_', 'L', 'O', 'N', 'G' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 18) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 18)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T jb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[6] = { 'M', 'A', 'X', 'L', 'O', 'C' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T k_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[5] = { 'S', 'H', 'O', 'R', 'T' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T kb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[6] = { 'M', 'I', 'N', 'L', 'O', 'C' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T l_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[14] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_', 'S',
    'H', 'O', 'R', 'T' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T lb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[7] = { 'O', 'P', '_', 'N', 'U', 'L', 'L' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
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
  loop_ub = varargin_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_varargin_3->data[i] = varargin_3->data[i];
  }

  M2C_error("mpi_get_const:UnknownConstant", "Unknonw constant %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

static boolean_T m_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[4] = { 'C', 'H', 'A', 'R' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T mb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[10] = { 'A', 'N', 'Y', '_', 'S', 'O', 'U', 'R', 'C', 'E'
  };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T n_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[13] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_', 'C',
    'H', 'A', 'R' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T nb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[7] = { 'A', 'N', 'Y', '_', 'T', 'A', 'G' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T o_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[4] = { 'B', 'Y', 'T', 'E' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T ob_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[8] = { 'I', 'N', '_', 'P', 'L', 'A', 'C', 'E' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 8) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T p_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[4] = { '2', 'I', 'N', 'T' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 4) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T pb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[16] = { 'E', 'R', 'R', 'O', 'R', 'S', '_', 'A', 'R', 'E',
    '_', 'F', 'A', 'T', 'A', 'L' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 16) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 16)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T q_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[9] = { 'S', 'H', 'O', 'R', 'T', '_', 'I', 'N', 'T' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T qb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[13] = { 'E', 'R', 'R', 'O', 'R', 'S', '_', 'R', 'E', 'T',
    'U', 'R', 'N' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T r_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[9] = { 'F', 'L', 'O', 'A', 'T', '_', 'I', 'N', 'T' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T rb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[14] = { 'B', 'S', 'E', 'N', 'D', '_', 'O', 'V', 'E', 'R',
    'H', 'E', 'A', 'D' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 14) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 14)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T s_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[10] = { 'D', 'O', 'U', 'B', 'L', 'E', '_', 'I', 'N', 'T'
  };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T sb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[9] = { 'U', 'N', 'D', 'E', 'F', 'I', 'N', 'E', 'D' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T t_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[6] = { 'P', 'A', 'C', 'K', 'E', 'D' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 6) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 6)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T tb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[5] = { 'I', 'D', 'E', 'N', 'T' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T u_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[13] = { 'D', 'A', 'T', 'A', 'T', 'Y', 'P', 'E', '_', 'N',
    'U', 'L', 'L' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 13) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 13)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T ub_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[9] = { 'C', 'O', 'N', 'G', 'R', 'U', 'E', 'N', 'T' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T v_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[10] = { 'C', 'O', 'M', 'M', '_', 'W', 'O', 'R', 'L', 'D'
  };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 10) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 10)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T vb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[7] = { 'S', 'I', 'M', 'I', 'L', 'A', 'R' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T w_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[9] = { 'C', 'O', 'M', 'M', '_', 'S', 'E', 'L', 'F' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T wb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[7] = { 'U', 'N', 'E', 'Q', 'U', 'A', 'L' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 7) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T x_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[9] = { 'C', 'O', 'M', 'M', '_', 'N', 'U', 'L', 'L' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 9) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T xb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[18] = { 'M', 'A', 'X', '_', 'P', 'R', 'O', 'C', 'E', 'S',
    'S', 'O', 'R', '_', 'N', 'A', 'M', 'E' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 18) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 18)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T y_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[3] = { 'S', 'U', 'M' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 3) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

static boolean_T yb_isequal(const emxArray_char_T *varargin_1)
{
  static const char cv[5] = { 'G', 'R', 'A', 'P', 'H' };

  int k;
  boolean_T b_p;
  boolean_T exitg1;
  boolean_T p;
  p = false;
  b_p = false;
  if (varargin_1->size[1] == 5) {
    b_p = true;
  }

  if (b_p && (varargin_1->size[1] != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!(varargin_1->data[k] == cv[k])) {
        b_p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  return b_p || p;
}

void mpi_get_const(const emxArray_char_T *name, struct0_T *obj)
{
  static const char cv4[14] = { 'M', 'P', 'I', '_', 'E', 'r', 'r', 'h', 'a', 'n',
    'd', 'l', 'e', 'r' };

  static const char cv[12] = { 'M', 'P', 'I', '_', 'D', 'a', 't', 'a', 't', 'y',
    'p', 'e' };

  static const char cv7[12] = { 'M', 'P', 'I', '_', 'S', 't', 'a', 't', 'u', 's',
    ' ', '*' };

  static const char cv5[11] = { 'M', 'P', 'I', '_', 'R', 'e', 'q', 'u', 'e', 's',
    't' };

  static const char cv6[9] = { 'M', 'P', 'I', '_', 'G', 'r', 'o', 'u', 'p' };

  static const char cv1[8] = { 'M', 'P', 'I', '_', 'C', 'o', 'm', 'm' };

  static const char cv8[8] = { 'M', 'P', 'I', '_', 'I', 'n', 'f', 'o' };

  static const char cv9[7] = { 'c', 'h', 'a', 'r', ' ', '*', '*' };

  static const char cv2[6] = { 'M', 'P', 'I', '_', 'O', 'p' };

  static const char cv3[6] = { 'v', 'o', 'i', 'd', ' ', '*' };

  static const char cv10[5] = { 'i', 'n', 't', ' ', '*' };

  MPI_Comm b_arg;
  MPI_Datatype arg;
  MPI_Errhandler f_arg;
  MPI_Group h_arg;
  MPI_Info j_arg;
  MPI_Op c_arg;
  MPI_Request g_arg;
  MPI_Status * i_arg;
  char ** k_arg;
  char * ptr;
  int d_arg;
  void * e_arg;
  emxArray_char_T *b_name;
  int i;
  int i1;
  int * l_arg;
  int loop_ub;
  int sizepe;
  if (5 > name->size[1]) {
    i = 0;
    i1 = 0;
  } else {
    i = 4;
    i1 = name->size[1];
  }

  emxInit_char_T(&b_name, 2);
  sizepe = b_name->size[0] * b_name->size[1];
  b_name->size[0] = 1;
  loop_ub = i1 - i;
  b_name->size[1] = loop_ub;
  emxEnsureCapacity_char_T(b_name, sizepe);
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_name->data[i1] = name->data[i + i1];
  }

  if (isequal(b_name)) {
    arg = MPI_FLOAT;
    sizepe = sizeof(MPI_Datatype);
    i = obj->data->size[0];
    obj->data->size[0] = sizepe;
    emxEnsureCapacity_uint8_T(obj->data, i);
    i = obj->type->size[0] * obj->type->size[1];
    obj->type->size[0] = 1;
    obj->type->size[1] = 12;
    emxEnsureCapacity_char_T(obj->type, i);
    for (i = 0; i < 12; i++) {
      obj->type->data[i] = cv[i];
    }

    obj->nitems = 1;
    ptr = (char *)(&arg);
    for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
      obj->data->data[loop_ub] = *(ptr);
      ptr = ptr + 1;
    }
  } else {
    if (5 > name->size[1]) {
      i = 0;
      i1 = 0;
    } else {
      i = 4;
      i1 = name->size[1];
    }

    sizepe = b_name->size[0] * b_name->size[1];
    b_name->size[0] = 1;
    loop_ub = i1 - i;
    b_name->size[1] = loop_ub;
    emxEnsureCapacity_char_T(b_name, sizepe);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_name->data[i1] = name->data[i + i1];
    }

    if (b_isequal(b_name)) {
      arg = MPI_DOUBLE;
      sizepe = sizeof(MPI_Datatype);
      i = obj->data->size[0];
      obj->data->size[0] = sizepe;
      emxEnsureCapacity_uint8_T(obj->data, i);
      i = obj->type->size[0] * obj->type->size[1];
      obj->type->size[0] = 1;
      obj->type->size[1] = 12;
      emxEnsureCapacity_char_T(obj->type, i);
      for (i = 0; i < 12; i++) {
        obj->type->data[i] = cv[i];
      }

      obj->nitems = 1;
      ptr = (char *)(&arg);
      for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
        obj->data->data[loop_ub] = *(ptr);
        ptr = ptr + 1;
      }
    } else {
      if (5 > name->size[1]) {
        i = 0;
        i1 = 0;
      } else {
        i = 4;
        i1 = name->size[1];
      }

      sizepe = b_name->size[0] * b_name->size[1];
      b_name->size[0] = 1;
      loop_ub = i1 - i;
      b_name->size[1] = loop_ub;
      emxEnsureCapacity_char_T(b_name, sizepe);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_name->data[i1] = name->data[i + i1];
      }

      if (c_isequal(b_name)) {
        arg = MPI_LONG_DOUBLE;
        sizepe = sizeof(MPI_Datatype);
        i = obj->data->size[0];
        obj->data->size[0] = sizepe;
        emxEnsureCapacity_uint8_T(obj->data, i);
        i = obj->type->size[0] * obj->type->size[1];
        obj->type->size[0] = 1;
        obj->type->size[1] = 12;
        emxEnsureCapacity_char_T(obj->type, i);
        for (i = 0; i < 12; i++) {
          obj->type->data[i] = cv[i];
        }

        obj->nitems = 1;
        ptr = (char *)(&arg);
        for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
          obj->data->data[loop_ub] = *(ptr);
          ptr = ptr + 1;
        }
      } else {
        if (5 > name->size[1]) {
          i = 0;
          i1 = 0;
        } else {
          i = 4;
          i1 = name->size[1];
        }

        sizepe = b_name->size[0] * b_name->size[1];
        b_name->size[0] = 1;
        loop_ub = i1 - i;
        b_name->size[1] = loop_ub;
        emxEnsureCapacity_char_T(b_name, sizepe);
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_name->data[i1] = name->data[i + i1];
        }

        if (d_isequal(b_name)) {
          arg = MPI_INT;
          sizepe = sizeof(MPI_Datatype);
          i = obj->data->size[0];
          obj->data->size[0] = sizepe;
          emxEnsureCapacity_uint8_T(obj->data, i);
          i = obj->type->size[0] * obj->type->size[1];
          obj->type->size[0] = 1;
          obj->type->size[1] = 12;
          emxEnsureCapacity_char_T(obj->type, i);
          for (i = 0; i < 12; i++) {
            obj->type->data[i] = cv[i];
          }

          obj->nitems = 1;
          ptr = (char *)(&arg);
          for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
            obj->data->data[loop_ub] = *(ptr);
            ptr = ptr + 1;
          }
        } else {
          if (5 > name->size[1]) {
            i = 0;
            i1 = 0;
          } else {
            i = 4;
            i1 = name->size[1];
          }

          sizepe = b_name->size[0] * b_name->size[1];
          b_name->size[0] = 1;
          loop_ub = i1 - i;
          b_name->size[1] = loop_ub;
          emxEnsureCapacity_char_T(b_name, sizepe);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_name->data[i1] = name->data[i + i1];
          }

          if (e_isequal(b_name)) {
            arg = MPI_UNSIGNED;
            sizepe = sizeof(MPI_Datatype);
            i = obj->data->size[0];
            obj->data->size[0] = sizepe;
            emxEnsureCapacity_uint8_T(obj->data, i);
            i = obj->type->size[0] * obj->type->size[1];
            obj->type->size[0] = 1;
            obj->type->size[1] = 12;
            emxEnsureCapacity_char_T(obj->type, i);
            for (i = 0; i < 12; i++) {
              obj->type->data[i] = cv[i];
            }

            obj->nitems = 1;
            ptr = (char *)(&arg);
            for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
              obj->data->data[loop_ub] = *(ptr);
              ptr = ptr + 1;
            }
          } else {
            if (5 > name->size[1]) {
              i = 0;
              i1 = 0;
            } else {
              i = 4;
              i1 = name->size[1];
            }

            sizepe = b_name->size[0] * b_name->size[1];
            b_name->size[0] = 1;
            loop_ub = i1 - i;
            b_name->size[1] = loop_ub;
            emxEnsureCapacity_char_T(b_name, sizepe);
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_name->data[i1] = name->data[i + i1];
            }

            if (f_isequal(b_name)) {
              arg = MPI_LONG;
              sizepe = sizeof(MPI_Datatype);
              i = obj->data->size[0];
              obj->data->size[0] = sizepe;
              emxEnsureCapacity_uint8_T(obj->data, i);
              i = obj->type->size[0] * obj->type->size[1];
              obj->type->size[0] = 1;
              obj->type->size[1] = 12;
              emxEnsureCapacity_char_T(obj->type, i);
              for (i = 0; i < 12; i++) {
                obj->type->data[i] = cv[i];
              }

              obj->nitems = 1;
              ptr = (char *)(&arg);
              for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
                obj->data->data[loop_ub] = *(ptr);
                ptr = ptr + 1;
              }
            } else {
              if (5 > name->size[1]) {
                i = 0;
                i1 = 0;
              } else {
                i = 4;
                i1 = name->size[1];
              }

              sizepe = b_name->size[0] * b_name->size[1];
              b_name->size[0] = 1;
              loop_ub = i1 - i;
              b_name->size[1] = loop_ub;
              emxEnsureCapacity_char_T(b_name, sizepe);
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_name->data[i1] = name->data[i + i1];
              }

              if (g_isequal(b_name)) {
                arg = MPI_UNSIGNED_LONG;
                sizepe = sizeof(MPI_Datatype);
                i = obj->data->size[0];
                obj->data->size[0] = sizepe;
                emxEnsureCapacity_uint8_T(obj->data, i);
                i = obj->type->size[0] * obj->type->size[1];
                obj->type->size[0] = 1;
                obj->type->size[1] = 12;
                emxEnsureCapacity_char_T(obj->type, i);
                for (i = 0; i < 12; i++) {
                  obj->type->data[i] = cv[i];
                }

                obj->nitems = 1;
                ptr = (char *)(&arg);
                for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
                  obj->data->data[loop_ub] = *(ptr);
                  ptr = ptr + 1;
                }
              } else {
                if (5 > name->size[1]) {
                  i = 0;
                  i1 = 0;
                } else {
                  i = 4;
                  i1 = name->size[1];
                }

                sizepe = b_name->size[0] * b_name->size[1];
                b_name->size[0] = 1;
                loop_ub = i1 - i;
                b_name->size[1] = loop_ub;
                emxEnsureCapacity_char_T(b_name, sizepe);
                for (i1 = 0; i1 < loop_ub; i1++) {
                  b_name->data[i1] = name->data[i + i1];
                }

                if (h_isequal(b_name)) {
                  arg = MPI_LONG_LONG;
                  sizepe = sizeof(MPI_Datatype);
                  i = obj->data->size[0];
                  obj->data->size[0] = sizepe;
                  emxEnsureCapacity_uint8_T(obj->data, i);
                  i = obj->type->size[0] * obj->type->size[1];
                  obj->type->size[0] = 1;
                  obj->type->size[1] = 12;
                  emxEnsureCapacity_char_T(obj->type, i);
                  for (i = 0; i < 12; i++) {
                    obj->type->data[i] = cv[i];
                  }

                  obj->nitems = 1;
                  ptr = (char *)(&arg);
                  for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
                    obj->data->data[loop_ub] = *(ptr);
                    ptr = ptr + 1;
                  }
                } else {
                  if (5 > name->size[1]) {
                    i = 0;
                    i1 = 0;
                  } else {
                    i = 4;
                    i1 = name->size[1];
                  }

                  sizepe = b_name->size[0] * b_name->size[1];
                  b_name->size[0] = 1;
                  loop_ub = i1 - i;
                  b_name->size[1] = loop_ub;
                  emxEnsureCapacity_char_T(b_name, sizepe);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_name->data[i1] = name->data[i + i1];
                  }

                  if (i_isequal(b_name)) {
                    arg = MPI_LONG_LONG_INT;
                    sizepe = sizeof(MPI_Datatype);
                    i = obj->data->size[0];
                    obj->data->size[0] = sizepe;
                    emxEnsureCapacity_uint8_T(obj->data, i);
                    i = obj->type->size[0] * obj->type->size[1];
                    obj->type->size[0] = 1;
                    obj->type->size[1] = 12;
                    emxEnsureCapacity_char_T(obj->type, i);
                    for (i = 0; i < 12; i++) {
                      obj->type->data[i] = cv[i];
                    }

                    obj->nitems = 1;
                    ptr = (char *)(&arg);
                    for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
                      obj->data->data[loop_ub] = *(ptr);
                      ptr = ptr + 1;
                    }
                  } else {
                    if (5 > name->size[1]) {
                      i = 0;
                      i1 = 0;
                    } else {
                      i = 4;
                      i1 = name->size[1];
                    }

                    sizepe = b_name->size[0] * b_name->size[1];
                    b_name->size[0] = 1;
                    loop_ub = i1 - i;
                    b_name->size[1] = loop_ub;
                    emxEnsureCapacity_char_T(b_name, sizepe);
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      b_name->data[i1] = name->data[i + i1];
                    }

                    if (j_isequal(b_name)) {
                      arg = MPI_UNSIGNED_LONG_LONG;
                      sizepe = sizeof(MPI_Datatype);
                      i = obj->data->size[0];
                      obj->data->size[0] = sizepe;
                      emxEnsureCapacity_uint8_T(obj->data, i);
                      i = obj->type->size[0] * obj->type->size[1];
                      obj->type->size[0] = 1;
                      obj->type->size[1] = 12;
                      emxEnsureCapacity_char_T(obj->type, i);
                      for (i = 0; i < 12; i++) {
                        obj->type->data[i] = cv[i];
                      }

                      obj->nitems = 1;
                      ptr = (char *)(&arg);
                      for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
                        obj->data->data[loop_ub] = *(ptr);
                        ptr = ptr + 1;
                      }
                    } else {
                      if (5 > name->size[1]) {
                        i = 0;
                        i1 = 0;
                      } else {
                        i = 4;
                        i1 = name->size[1];
                      }

                      sizepe = b_name->size[0] * b_name->size[1];
                      b_name->size[0] = 1;
                      loop_ub = i1 - i;
                      b_name->size[1] = loop_ub;
                      emxEnsureCapacity_char_T(b_name, sizepe);
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_name->data[i1] = name->data[i + i1];
                      }

                      if (k_isequal(b_name)) {
                        arg = MPI_SHORT;
                        sizepe = sizeof(MPI_Datatype);
                        i = obj->data->size[0];
                        obj->data->size[0] = sizepe;
                        emxEnsureCapacity_uint8_T(obj->data, i);
                        i = obj->type->size[0] * obj->type->size[1];
                        obj->type->size[0] = 1;
                        obj->type->size[1] = 12;
                        emxEnsureCapacity_char_T(obj->type, i);
                        for (i = 0; i < 12; i++) {
                          obj->type->data[i] = cv[i];
                        }

                        obj->nitems = 1;
                        ptr = (char *)(&arg);
                        for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
                          obj->data->data[loop_ub] = *(ptr);
                          ptr = ptr + 1;
                        }
                      } else {
                        if (5 > name->size[1]) {
                          i = 0;
                          i1 = 0;
                        } else {
                          i = 4;
                          i1 = name->size[1];
                        }

                        sizepe = b_name->size[0] * b_name->size[1];
                        b_name->size[0] = 1;
                        loop_ub = i1 - i;
                        b_name->size[1] = loop_ub;
                        emxEnsureCapacity_char_T(b_name, sizepe);
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          b_name->data[i1] = name->data[i + i1];
                        }

                        if (l_isequal(b_name)) {
                          arg = MPI_UNSIGNED_SHORT;
                          sizepe = sizeof(MPI_Datatype);
                          i = obj->data->size[0];
                          obj->data->size[0] = sizepe;
                          emxEnsureCapacity_uint8_T(obj->data, i);
                          i = obj->type->size[0] * obj->type->size[1];
                          obj->type->size[0] = 1;
                          obj->type->size[1] = 12;
                          emxEnsureCapacity_char_T(obj->type, i);
                          for (i = 0; i < 12; i++) {
                            obj->type->data[i] = cv[i];
                          }

                          obj->nitems = 1;
                          ptr = (char *)(&arg);
                          for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
                            obj->data->data[loop_ub] = *(ptr);
                            ptr = ptr + 1;
                          }
                        } else {
                          if (5 > name->size[1]) {
                            i = 0;
                            i1 = 0;
                          } else {
                            i = 4;
                            i1 = name->size[1];
                          }

                          sizepe = b_name->size[0] * b_name->size[1];
                          b_name->size[0] = 1;
                          loop_ub = i1 - i;
                          b_name->size[1] = loop_ub;
                          emxEnsureCapacity_char_T(b_name, sizepe);
                          for (i1 = 0; i1 < loop_ub; i1++) {
                            b_name->data[i1] = name->data[i + i1];
                          }

                          if (m_isequal(b_name)) {
                            arg = MPI_CHAR;
                            sizepe = sizeof(MPI_Datatype);
                            i = obj->data->size[0];
                            obj->data->size[0] = sizepe;
                            emxEnsureCapacity_uint8_T(obj->data, i);
                            i = obj->type->size[0] * obj->type->size[1];
                            obj->type->size[0] = 1;
                            obj->type->size[1] = 12;
                            emxEnsureCapacity_char_T(obj->type, i);
                            for (i = 0; i < 12; i++) {
                              obj->type->data[i] = cv[i];
                            }

                            obj->nitems = 1;
                            ptr = (char *)(&arg);
                            for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
                              obj->data->data[loop_ub] = *(ptr);
                              ptr = ptr + 1;
                            }
                          } else {
                            if (5 > name->size[1]) {
                              i = 0;
                              i1 = 0;
                            } else {
                              i = 4;
                              i1 = name->size[1];
                            }

                            sizepe = b_name->size[0] * b_name->size[1];
                            b_name->size[0] = 1;
                            loop_ub = i1 - i;
                            b_name->size[1] = loop_ub;
                            emxEnsureCapacity_char_T(b_name, sizepe);
                            for (i1 = 0; i1 < loop_ub; i1++) {
                              b_name->data[i1] = name->data[i + i1];
                            }

                            if (n_isequal(b_name)) {
                              arg = MPI_UNSIGNED_CHAR;
                              sizepe = sizeof(MPI_Datatype);
                              i = obj->data->size[0];
                              obj->data->size[0] = sizepe;
                              emxEnsureCapacity_uint8_T(obj->data, i);
                              i = obj->type->size[0] * obj->type->size[1];
                              obj->type->size[0] = 1;
                              obj->type->size[1] = 12;
                              emxEnsureCapacity_char_T(obj->type, i);
                              for (i = 0; i < 12; i++) {
                                obj->type->data[i] = cv[i];
                              }

                              obj->nitems = 1;
                              ptr = (char *)(&arg);
                              for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
                                obj->data->data[loop_ub] = *(ptr);
                                ptr = ptr + 1;
                              }
                            } else {
                              if (5 > name->size[1]) {
                                i = 0;
                                i1 = 0;
                              } else {
                                i = 4;
                                i1 = name->size[1];
                              }

                              sizepe = b_name->size[0] * b_name->size[1];
                              b_name->size[0] = 1;
                              loop_ub = i1 - i;
                              b_name->size[1] = loop_ub;
                              emxEnsureCapacity_char_T(b_name, sizepe);
                              for (i1 = 0; i1 < loop_ub; i1++) {
                                b_name->data[i1] = name->data[i + i1];
                              }

                              if (o_isequal(b_name)) {
                                arg = MPI_BYTE;
                                sizepe = sizeof(MPI_Datatype);
                                i = obj->data->size[0];
                                obj->data->size[0] = sizepe;
                                emxEnsureCapacity_uint8_T(obj->data, i);
                                i = obj->type->size[0] * obj->type->size[1];
                                obj->type->size[0] = 1;
                                obj->type->size[1] = 12;
                                emxEnsureCapacity_char_T(obj->type, i);
                                for (i = 0; i < 12; i++) {
                                  obj->type->data[i] = cv[i];
                                }

                                obj->nitems = 1;
                                ptr = (char *)(&arg);
                                for (loop_ub = 0; loop_ub < sizepe; loop_ub++) {
                                  obj->data->data[loop_ub] = *(ptr);
                                  ptr = ptr + 1;
                                }
                              } else {
                                if (5 > name->size[1]) {
                                  i = 0;
                                  i1 = 0;
                                } else {
                                  i = 4;
                                  i1 = name->size[1];
                                }

                                sizepe = b_name->size[0] * b_name->size[1];
                                b_name->size[0] = 1;
                                loop_ub = i1 - i;
                                b_name->size[1] = loop_ub;
                                emxEnsureCapacity_char_T(b_name, sizepe);
                                for (i1 = 0; i1 < loop_ub; i1++) {
                                  b_name->data[i1] = name->data[i + i1];
                                }

                                if (p_isequal(b_name)) {
                                  arg = MPI_2INT;
                                  sizepe = sizeof(MPI_Datatype);
                                  i = obj->data->size[0];
                                  obj->data->size[0] = sizepe;
                                  emxEnsureCapacity_uint8_T(obj->data, i);
                                  i = obj->type->size[0] * obj->type->size[1];
                                  obj->type->size[0] = 1;
                                  obj->type->size[1] = 12;
                                  emxEnsureCapacity_char_T(obj->type, i);
                                  for (i = 0; i < 12; i++) {
                                    obj->type->data[i] = cv[i];
                                  }

                                  obj->nitems = 1;
                                  ptr = (char *)(&arg);
                                  for (loop_ub = 0; loop_ub < sizepe; loop_ub++)
                                  {
                                    obj->data->data[loop_ub] = *(ptr);
                                    ptr = ptr + 1;
                                  }
                                } else {
                                  if (5 > name->size[1]) {
                                    i = 0;
                                    i1 = 0;
                                  } else {
                                    i = 4;
                                    i1 = name->size[1];
                                  }

                                  sizepe = b_name->size[0] * b_name->size[1];
                                  b_name->size[0] = 1;
                                  loop_ub = i1 - i;
                                  b_name->size[1] = loop_ub;
                                  emxEnsureCapacity_char_T(b_name, sizepe);
                                  for (i1 = 0; i1 < loop_ub; i1++) {
                                    b_name->data[i1] = name->data[i + i1];
                                  }

                                  if (q_isequal(b_name)) {
                                    arg = MPI_SHORT_INT;
                                    sizepe = sizeof(MPI_Datatype);
                                    i = obj->data->size[0];
                                    obj->data->size[0] = sizepe;
                                    emxEnsureCapacity_uint8_T(obj->data, i);
                                    i = obj->type->size[0] * obj->type->size[1];
                                    obj->type->size[0] = 1;
                                    obj->type->size[1] = 12;
                                    emxEnsureCapacity_char_T(obj->type, i);
                                    for (i = 0; i < 12; i++) {
                                      obj->type->data[i] = cv[i];
                                    }

                                    obj->nitems = 1;
                                    ptr = (char *)(&arg);
                                    for (loop_ub = 0; loop_ub < sizepe; loop_ub
                                         ++) {
                                      obj->data->data[loop_ub] = *(ptr);
                                      ptr = ptr + 1;
                                    }
                                  } else {
                                    if (5 > name->size[1]) {
                                      i = 0;
                                      i1 = 0;
                                    } else {
                                      i = 4;
                                      i1 = name->size[1];
                                    }

                                    sizepe = b_name->size[0] * b_name->size[1];
                                    b_name->size[0] = 1;
                                    loop_ub = i1 - i;
                                    b_name->size[1] = loop_ub;
                                    emxEnsureCapacity_char_T(b_name, sizepe);
                                    for (i1 = 0; i1 < loop_ub; i1++) {
                                      b_name->data[i1] = name->data[i + i1];
                                    }

                                    if (r_isequal(b_name)) {
                                      arg = MPI_FLOAT_INT;
                                      sizepe = sizeof(MPI_Datatype);
                                      i = obj->data->size[0];
                                      obj->data->size[0] = sizepe;
                                      emxEnsureCapacity_uint8_T(obj->data, i);
                                      i = obj->type->size[0] * obj->type->size[1];
                                      obj->type->size[0] = 1;
                                      obj->type->size[1] = 12;
                                      emxEnsureCapacity_char_T(obj->type, i);
                                      for (i = 0; i < 12; i++) {
                                        obj->type->data[i] = cv[i];
                                      }

                                      obj->nitems = 1;
                                      ptr = (char *)(&arg);
                                      for (loop_ub = 0; loop_ub < sizepe;
                                           loop_ub++) {
                                        obj->data->data[loop_ub] = *(ptr);
                                        ptr = ptr + 1;
                                      }
                                    } else {
                                      if (5 > name->size[1]) {
                                        i = 0;
                                        i1 = 0;
                                      } else {
                                        i = 4;
                                        i1 = name->size[1];
                                      }

                                      sizepe = b_name->size[0] * b_name->size[1];
                                      b_name->size[0] = 1;
                                      loop_ub = i1 - i;
                                      b_name->size[1] = loop_ub;
                                      emxEnsureCapacity_char_T(b_name, sizepe);
                                      for (i1 = 0; i1 < loop_ub; i1++) {
                                        b_name->data[i1] = name->data[i + i1];
                                      }

                                      if (s_isequal(b_name)) {
                                        arg = MPI_DOUBLE_INT;
                                        sizepe = sizeof(MPI_Datatype);
                                        i = obj->data->size[0];
                                        obj->data->size[0] = sizepe;
                                        emxEnsureCapacity_uint8_T(obj->data, i);
                                        i = obj->type->size[0] * obj->type->
                                          size[1];
                                        obj->type->size[0] = 1;
                                        obj->type->size[1] = 12;
                                        emxEnsureCapacity_char_T(obj->type, i);
                                        for (i = 0; i < 12; i++) {
                                          obj->type->data[i] = cv[i];
                                        }

                                        obj->nitems = 1;
                                        ptr = (char *)(&arg);
                                        for (loop_ub = 0; loop_ub < sizepe;
                                             loop_ub++) {
                                          obj->data->data[loop_ub] = *(ptr);
                                          ptr = ptr + 1;
                                        }
                                      } else {
                                        if (5 > name->size[1]) {
                                          i = 0;
                                          i1 = 0;
                                        } else {
                                          i = 4;
                                          i1 = name->size[1];
                                        }

                                        sizepe = b_name->size[0] * b_name->size
                                          [1];
                                        b_name->size[0] = 1;
                                        loop_ub = i1 - i;
                                        b_name->size[1] = loop_ub;
                                        emxEnsureCapacity_char_T(b_name, sizepe);
                                        for (i1 = 0; i1 < loop_ub; i1++) {
                                          b_name->data[i1] = name->data[i + i1];
                                        }

                                        if (t_isequal(b_name)) {
                                          arg = MPI_PACKED;
                                          sizepe = sizeof(MPI_Datatype);
                                          i = obj->data->size[0];
                                          obj->data->size[0] = sizepe;
                                          emxEnsureCapacity_uint8_T(obj->data, i);
                                          i = obj->type->size[0] * obj->
                                            type->size[1];
                                          obj->type->size[0] = 1;
                                          obj->type->size[1] = 12;
                                          emxEnsureCapacity_char_T(obj->type, i);
                                          for (i = 0; i < 12; i++) {
                                            obj->type->data[i] = cv[i];
                                          }

                                          obj->nitems = 1;
                                          ptr = (char *)(&arg);
                                          for (loop_ub = 0; loop_ub < sizepe;
                                               loop_ub++) {
                                            obj->data->data[loop_ub] = *(ptr);
                                            ptr = ptr + 1;
                                          }
                                        } else {
                                          if (5 > name->size[1]) {
                                            i = 0;
                                            i1 = 0;
                                          } else {
                                            i = 4;
                                            i1 = name->size[1];
                                          }

                                          sizepe = b_name->size[0] *
                                            b_name->size[1];
                                          b_name->size[0] = 1;
                                          loop_ub = i1 - i;
                                          b_name->size[1] = loop_ub;
                                          emxEnsureCapacity_char_T(b_name,
                                            sizepe);
                                          for (i1 = 0; i1 < loop_ub; i1++) {
                                            b_name->data[i1] = name->data[i + i1];
                                          }

                                          if (u_isequal(b_name)) {
                                            arg = MPI_DATATYPE_NULL;
                                            sizepe = sizeof(MPI_Datatype);
                                            i = obj->data->size[0];
                                            obj->data->size[0] = sizepe;
                                            emxEnsureCapacity_uint8_T(obj->data,
                                              i);
                                            i = obj->type->size[0] * obj->
                                              type->size[1];
                                            obj->type->size[0] = 1;
                                            obj->type->size[1] = 12;
                                            emxEnsureCapacity_char_T(obj->type,
                                              i);
                                            for (i = 0; i < 12; i++) {
                                              obj->type->data[i] = cv[i];
                                            }

                                            obj->nitems = 1;
                                            ptr = (char *)(&arg);
                                            for (loop_ub = 0; loop_ub < sizepe;
                                                 loop_ub++) {
                                              obj->data->data[loop_ub] = *(ptr);
                                              ptr = ptr + 1;
                                            }
                                          } else {
                                            if (5 > name->size[1]) {
                                              i = 0;
                                              i1 = 0;
                                            } else {
                                              i = 4;
                                              i1 = name->size[1];
                                            }

                                            sizepe = b_name->size[0] *
                                              b_name->size[1];
                                            b_name->size[0] = 1;
                                            loop_ub = i1 - i;
                                            b_name->size[1] = loop_ub;
                                            emxEnsureCapacity_char_T(b_name,
                                              sizepe);
                                            for (i1 = 0; i1 < loop_ub; i1++) {
                                              b_name->data[i1] = name->data[i +
                                                i1];
                                            }

                                            if (v_isequal(b_name)) {
                                              b_arg = MPI_COMM_WORLD;
                                              sizepe = sizeof(MPI_Comm);
                                              i = obj->data->size[0];
                                              obj->data->size[0] = sizepe;
                                              emxEnsureCapacity_uint8_T
                                                (obj->data, i);
                                              i = obj->type->size[0] * obj->
                                                type->size[1];
                                              obj->type->size[0] = 1;
                                              obj->type->size[1] = 8;
                                              emxEnsureCapacity_char_T(obj->type,
                                                i);
                                              for (i = 0; i < 8; i++) {
                                                obj->type->data[i] = cv1[i];
                                              }

                                              obj->nitems = 1;
                                              ptr = (char *)(&b_arg);
                                              for (loop_ub = 0; loop_ub < sizepe;
                                                   loop_ub++) {
                                                obj->data->data[loop_ub] = *(ptr);
                                                ptr = ptr + 1;
                                              }
                                            } else {
                                              if (5 > name->size[1]) {
                                                i = 0;
                                                i1 = 0;
                                              } else {
                                                i = 4;
                                                i1 = name->size[1];
                                              }

                                              sizepe = b_name->size[0] *
                                                b_name->size[1];
                                              b_name->size[0] = 1;
                                              loop_ub = i1 - i;
                                              b_name->size[1] = loop_ub;
                                              emxEnsureCapacity_char_T(b_name,
                                                sizepe);
                                              for (i1 = 0; i1 < loop_ub; i1++) {
                                                b_name->data[i1] = name->data[i
                                                  + i1];
                                              }

                                              if (w_isequal(b_name)) {
                                                b_arg = MPI_COMM_SELF;
                                                sizepe = sizeof(MPI_Comm);
                                                i = obj->data->size[0];
                                                obj->data->size[0] = sizepe;
                                                emxEnsureCapacity_uint8_T
                                                  (obj->data, i);
                                                i = obj->type->size[0] *
                                                  obj->type->size[1];
                                                obj->type->size[0] = 1;
                                                obj->type->size[1] = 8;
                                                emxEnsureCapacity_char_T
                                                  (obj->type, i);
                                                for (i = 0; i < 8; i++) {
                                                  obj->type->data[i] = cv1[i];
                                                }

                                                obj->nitems = 1;
                                                ptr = (char *)(&b_arg);
                                                for (loop_ub = 0; loop_ub <
                                                     sizepe; loop_ub++) {
                                                  obj->data->data[loop_ub] =
                                                    *(ptr);
                                                  ptr = ptr + 1;
                                                }
                                              } else {
                                                if (5 > name->size[1]) {
                                                  i = 0;
                                                  i1 = 0;
                                                } else {
                                                  i = 4;
                                                  i1 = name->size[1];
                                                }

                                                sizepe = b_name->size[0] *
                                                  b_name->size[1];
                                                b_name->size[0] = 1;
                                                loop_ub = i1 - i;
                                                b_name->size[1] = loop_ub;
                                                emxEnsureCapacity_char_T(b_name,
                                                  sizepe);
                                                for (i1 = 0; i1 < loop_ub; i1++)
                                                {
                                                  b_name->data[i1] = name->
                                                    data[i + i1];
                                                }

                                                if (x_isequal(b_name)) {
                                                  b_arg = MPI_COMM_NULL;
                                                  sizepe = sizeof(MPI_Comm);
                                                  i = obj->data->size[0];
                                                  obj->data->size[0] = sizepe;
                                                  emxEnsureCapacity_uint8_T
                                                    (obj->data, i);
                                                  i = obj->type->size[0] *
                                                    obj->type->size[1];
                                                  obj->type->size[0] = 1;
                                                  obj->type->size[1] = 8;
                                                  emxEnsureCapacity_char_T
                                                    (obj->type, i);
                                                  for (i = 0; i < 8; i++) {
                                                    obj->type->data[i] = cv1[i];
                                                  }

                                                  obj->nitems = 1;
                                                  ptr = (char *)(&b_arg);
                                                  for (loop_ub = 0; loop_ub <
                                                       sizepe; loop_ub++) {
                                                    obj->data->data[loop_ub] =
                                                      *(ptr);
                                                    ptr = ptr + 1;
                                                  }
                                                } else {
                                                  if (5 > name->size[1]) {
                                                    i = 0;
                                                    i1 = 0;
                                                  } else {
                                                    i = 4;
                                                    i1 = name->size[1];
                                                  }

                                                  sizepe = b_name->size[0] *
                                                    b_name->size[1];
                                                  b_name->size[0] = 1;
                                                  loop_ub = i1 - i;
                                                  b_name->size[1] = loop_ub;
                                                  emxEnsureCapacity_char_T
                                                    (b_name, sizepe);
                                                  for (i1 = 0; i1 < loop_ub; i1
                                                       ++) {
                                                    b_name->data[i1] =
                                                      name->data[i + i1];
                                                  }

                                                  if (y_isequal(b_name)) {
                                                    c_arg = MPI_SUM;
                                                    sizepe = sizeof(MPI_Op);
                                                    i = obj->data->size[0];
                                                    obj->data->size[0] = sizepe;
                                                    emxEnsureCapacity_uint8_T
                                                      (obj->data, i);
                                                    i = obj->type->size[0] *
                                                      obj->type->size[1];
                                                    obj->type->size[0] = 1;
                                                    obj->type->size[1] = 6;
                                                    emxEnsureCapacity_char_T
                                                      (obj->type, i);
                                                    for (i = 0; i < 6; i++) {
                                                      obj->type->data[i] = cv2[i];
                                                    }

                                                    obj->nitems = 1;
                                                    ptr = (char *)(&c_arg);
                                                    for (loop_ub = 0; loop_ub <
                                                         sizepe; loop_ub++) {
                                                      obj->data->data[loop_ub] =
                                                        *(ptr);
                                                      ptr = ptr + 1;
                                                    }
                                                  } else {
                                                    if (5 > name->size[1]) {
                                                      i = 0;
                                                      i1 = 0;
                                                    } else {
                                                      i = 4;
                                                      i1 = name->size[1];
                                                    }

                                                    sizepe = b_name->size[0] *
                                                      b_name->size[1];
                                                    b_name->size[0] = 1;
                                                    loop_ub = i1 - i;
                                                    b_name->size[1] = loop_ub;
                                                    emxEnsureCapacity_char_T
                                                      (b_name, sizepe);
                                                    for (i1 = 0; i1 < loop_ub;
                                                         i1++) {
                                                      b_name->data[i1] =
                                                        name->data[i + i1];
                                                    }

                                                    if (ab_isequal(b_name)) {
                                                      c_arg = MPI_PROD;
                                                      sizepe = sizeof(MPI_Op);
                                                      i = obj->data->size[0];
                                                      obj->data->size[0] =
                                                        sizepe;
                                                      emxEnsureCapacity_uint8_T
                                                        (obj->data, i);
                                                      i = obj->type->size[0] *
                                                        obj->type->size[1];
                                                      obj->type->size[0] = 1;
                                                      obj->type->size[1] = 6;
                                                      emxEnsureCapacity_char_T
                                                        (obj->type, i);
                                                      for (i = 0; i < 6; i++) {
                                                        obj->type->data[i] =
                                                          cv2[i];
                                                      }

                                                      obj->nitems = 1;
                                                      ptr = (char *)(&c_arg);
                                                      for (loop_ub = 0; loop_ub <
                                                           sizepe; loop_ub++) {
                                                        obj->data->data[loop_ub]
                                                          = *(ptr);
                                                        ptr = ptr + 1;
                                                      }
                                                    } else {
                                                      if (5 > name->size[1]) {
                                                        i = 0;
                                                        i1 = 0;
                                                      } else {
                                                        i = 4;
                                                        i1 = name->size[1];
                                                      }

                                                      sizepe = b_name->size[0] *
                                                        b_name->size[1];
                                                      b_name->size[0] = 1;
                                                      loop_ub = i1 - i;
                                                      b_name->size[1] = loop_ub;
                                                      emxEnsureCapacity_char_T
                                                        (b_name, sizepe);
                                                      for (i1 = 0; i1 < loop_ub;
                                                           i1++) {
                                                        b_name->data[i1] =
                                                          name->data[i + i1];
                                                      }

                                                      if (bb_isequal(b_name)) {
                                                        c_arg = MPI_MIN;
                                                        sizepe = sizeof(MPI_Op);
                                                        i = obj->data->size[0];
                                                        obj->data->size[0] =
                                                          sizepe;
                                                        emxEnsureCapacity_uint8_T
                                                          (obj->data, i);
                                                        i = obj->type->size[0] *
                                                          obj->type->size[1];
                                                        obj->type->size[0] = 1;
                                                        obj->type->size[1] = 6;
                                                        emxEnsureCapacity_char_T
                                                          (obj->type, i);
                                                        for (i = 0; i < 6; i++)
                                                        {
                                                          obj->type->data[i] =
                                                            cv2[i];
                                                        }

                                                        obj->nitems = 1;
                                                        ptr = (char *)(&c_arg);
                                                        for (loop_ub = 0;
                                                             loop_ub < sizepe;
                                                             loop_ub++) {
                                                          obj->data->
                                                            data[loop_ub] =
                                                            *(ptr);
                                                          ptr = ptr + 1;
                                                        }
                                                      } else {
                                                        if (5 > name->size[1]) {
                                                          i = 0;
                                                          i1 = 0;
                                                        } else {
                                                          i = 4;
                                                          i1 = name->size[1];
                                                        }

                                                        sizepe = b_name->size[0]
                                                          * b_name->size[1];
                                                        b_name->size[0] = 1;
                                                        loop_ub = i1 - i;
                                                        b_name->size[1] =
                                                          loop_ub;
                                                        emxEnsureCapacity_char_T
                                                          (b_name, sizepe);
                                                        for (i1 = 0; i1 <
                                                             loop_ub; i1++) {
                                                          b_name->data[i1] =
                                                            name->data[i + i1];
                                                        }

                                                        if (cb_isequal(b_name))
                                                        {
                                                          c_arg = MPI_MAX;
                                                          sizepe = sizeof(MPI_Op);
                                                          i = obj->data->size[0];
                                                          obj->data->size[0] =
                                                            sizepe;
                                                          emxEnsureCapacity_uint8_T
                                                            (obj->data, i);
                                                          i = obj->type->size[0]
                                                            * obj->type->size[1];
                                                          obj->type->size[0] = 1;
                                                          obj->type->size[1] = 6;
                                                          emxEnsureCapacity_char_T
                                                            (obj->type, i);
                                                          for (i = 0; i < 6; i++)
                                                          {
                                                            obj->type->data[i] =
                                                              cv2[i];
                                                          }

                                                          obj->nitems = 1;
                                                          ptr = (char *)(&c_arg);
                                                          for (loop_ub = 0;
                                                               loop_ub < sizepe;
                                                               loop_ub++) {
                                                            obj->data->
                                                              data[loop_ub] =
                                                              *(ptr);
                                                            ptr = ptr + 1;
                                                          }
                                                        } else {
                                                          if (5 > name->size[1])
                                                          {
                                                            i = 0;
                                                            i1 = 0;
                                                          } else {
                                                            i = 4;
                                                            i1 = name->size[1];
                                                          }

                                                          sizepe = b_name->size
                                                            [0] * b_name->size[1];
                                                          b_name->size[0] = 1;
                                                          loop_ub = i1 - i;
                                                          b_name->size[1] =
                                                            loop_ub;
                                                          emxEnsureCapacity_char_T
                                                            (b_name, sizepe);
                                                          for (i1 = 0; i1 <
                                                               loop_ub; i1++) {
                                                            b_name->data[i1] =
                                                              name->data[i + i1];
                                                          }

                                                          if (db_isequal(b_name))
                                                          {
                                                            c_arg = MPI_BOR;
                                                            sizepe = sizeof
                                                              (MPI_Op);
                                                            i = obj->data->size
                                                              [0];
                                                            obj->data->size[0] =
                                                              sizepe;
                                                            emxEnsureCapacity_uint8_T
                                                              (obj->data, i);
                                                            i = obj->type->size
                                                              [0] * obj->
                                                              type->size[1];
                                                            obj->type->size[0] =
                                                              1;
                                                            obj->type->size[1] =
                                                              6;
                                                            emxEnsureCapacity_char_T
                                                              (obj->type, i);
                                                            for (i = 0; i < 6; i
                                                                 ++) {
                                                              obj->type->data[i]
                                                                = cv2[i];
                                                            }

                                                            obj->nitems = 1;
                                                            ptr = (char *)
                                                              (&c_arg);
                                                            for (loop_ub = 0;
                                                                 loop_ub <
                                                                 sizepe; loop_ub
                                                                 ++) {
                                                              obj->data->
                                                                data[loop_ub] = *
                                                                (ptr);
                                                              ptr =
                                                                ptr + 1;
                                                            }
                                                          } else {
                                                            if (5 > name->size[1])
                                                            {
                                                              i = 0;
                                                              i1 = 0;
                                                            } else {
                                                              i = 4;
                                                              i1 = name->size[1];
                                                            }

                                                            sizepe =
                                                              b_name->size[0] *
                                                              b_name->size[1];
                                                            b_name->size[0] = 1;
                                                            loop_ub = i1 - i;
                                                            b_name->size[1] =
                                                              loop_ub;
                                                            emxEnsureCapacity_char_T
                                                              (b_name, sizepe);
                                                            for (i1 = 0; i1 <
                                                                 loop_ub; i1++)
                                                            {
                                                              b_name->data[i1] =
                                                                name->data[i +
                                                                i1];
                                                            }

                                                            if (eb_isequal
                                                                (b_name)) {
                                                              c_arg = MPI_BAND;
                                                              sizepe = sizeof
                                                                (MPI_Op);
                                                              i = obj->
                                                                data->size[0];
                                                              obj->data->size[0]
                                                                = sizepe;
                                                              emxEnsureCapacity_uint8_T
                                                                (obj->data, i);
                                                              i = obj->
                                                                type->size[0] *
                                                                obj->type->size
                                                                [1];
                                                              obj->type->size[0]
                                                                = 1;
                                                              obj->type->size[1]
                                                                = 6;
                                                              emxEnsureCapacity_char_T
                                                                (obj->type, i);
                                                              for (i = 0; i < 6;
                                                                   i++) {
                                                                obj->type->
                                                                  data[i] =
                                                                  cv2[i];
                                                              }

                                                              obj->nitems = 1;
                                                              ptr = (char *)
                                                                (&c_arg);
                                                              for (loop_ub = 0;
                                                                   loop_ub <
                                                                   sizepe;
                                                                   loop_ub++) {
                                                                obj->data->
                                                                  data[loop_ub] =
                                                                  *(ptr);
                                                                ptr =
                                                                  ptr + 1;
                                                              }
                                                            } else {
                                                              if (5 > name->
                                                                  size[1]) {
                                                                i = 0;
                                                                i1 = 0;
                                                              } else {
                                                                i = 4;
                                                                i1 = name->size
                                                                  [1];
                                                              }

                                                              sizepe =
                                                                b_name->size[0] *
                                                                b_name->size[1];
                                                              b_name->size[0] =
                                                                1;
                                                              loop_ub = i1 - i;
                                                              b_name->size[1] =
                                                                loop_ub;
                                                              emxEnsureCapacity_char_T
                                                                (b_name, sizepe);
                                                              for (i1 = 0; i1 <
                                                                   loop_ub; i1++)
                                                              {
                                                                b_name->data[i1]
                                                                  = name->data[i
                                                                  + i1];
                                                              }

                                                              if (fb_isequal
                                                                  (b_name)) {
                                                                c_arg = MPI_BXOR;
                                                                sizepe = sizeof
                                                                  (MPI_Op);
                                                                i = obj->
                                                                  data->size[0];
                                                                obj->data->size
                                                                  [0] = sizepe;
                                                                emxEnsureCapacity_uint8_T
                                                                  (obj->data, i);
                                                                i = obj->
                                                                  type->size[0] *
                                                                  obj->
                                                                  type->size[1];
                                                                obj->type->size
                                                                  [0] = 1;
                                                                obj->type->size
                                                                  [1] = 6;
                                                                emxEnsureCapacity_char_T
                                                                  (obj->type, i);
                                                                for (i = 0; i <
                                                                     6; i++) {
                                                                  obj->
                                                                    type->data[i]
                                                                    = cv2[i];
                                                                }

                                                                obj->nitems = 1;
                                                                ptr = (char *)
                                                                  (&c_arg);
                                                                for (loop_ub = 0;
                                                                     loop_ub <
                                                                     sizepe;
                                                                     loop_ub++)
                                                                {
                                                                  obj->
                                                                    data->
                                                                    data[loop_ub]
                                                                    = *(ptr);
                                                                  ptr =
                                                                    ptr + 1;
                                                                }
                                                              } else {
                                                                if (5 >
                                                                    name->size[1])
                                                                {
                                                                  i = 0;
                                                                  i1 = 0;
                                                                } else {
                                                                  i = 4;
                                                                  i1 =
                                                                    name->size[1];
                                                                }

                                                                sizepe =
                                                                  b_name->size[0]
                                                                  * b_name->
                                                                  size[1];
                                                                b_name->size[0] =
                                                                  1;
                                                                loop_ub = i1 - i;
                                                                b_name->size[1] =
                                                                  loop_ub;
                                                                emxEnsureCapacity_char_T
                                                                  (b_name,
                                                                   sizepe);
                                                                for (i1 = 0; i1 <
                                                                     loop_ub; i1
                                                                     ++) {
                                                                  b_name->
                                                                    data[i1] =
                                                                    name->data[i
                                                                    + i1];
                                                                }

                                                                if (gb_isequal
                                                                    (b_name)) {
                                                                  c_arg =
                                                                    MPI_LOR;
                                                                  sizepe =
                                                                    sizeof
                                                                    (MPI_Op);
                                                                  i = obj->
                                                                    data->size[0];
                                                                  obj->
                                                                    data->size[0]
                                                                    = sizepe;
                                                                  emxEnsureCapacity_uint8_T
                                                                    (obj->data,
                                                                     i);
                                                                  i = obj->
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
                                                                     i);
                                                                  for (i = 0; i <
                                                                      6; i++) {
                                                                    obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv2[i];
                                                                  }

                                                                  obj->nitems =
                                                                    1;
                                                                  ptr = (char *)
                                                                    (&c_arg);
                                                                  for (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                  {
                                                                    obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                    ptr =
                                                                      ptr + 1;
                                                                  }
                                                                } else {
                                                                  if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                    i = 0;
                                                                    i1 = 0;
                                                                  } else {
                                                                    i = 4;
                                                                    i1 =
                                                                      name->
                                                                      size[1];
                                                                  }

                                                                  sizepe =
                                                                    b_name->
                                                                    size[0] *
                                                                    b_name->
                                                                    size[1];
                                                                  b_name->size[0]
                                                                    = 1;
                                                                  loop_ub = i1 -
                                                                    i;
                                                                  b_name->size[1]
                                                                    = loop_ub;
                                                                  emxEnsureCapacity_char_T
                                                                    (b_name,
                                                                     sizepe);
                                                                  for (i1 = 0;
                                                                      i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                    b_name->
                                                                      data[i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                  }

                                                                  if (hb_isequal
                                                                      (b_name))
                                                                  {
                                                                    c_arg =
                                                                      MPI_LAND;
                                                                    sizepe =
                                                                      sizeof
                                                                      (MPI_Op);
                                                                    i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                    obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                    emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                    i =
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
                                                                      i);
                                                                    for (i = 0;
                                                                      i < 6; i++)
                                                                    {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv2[i];
                                                                    }

                                                                    obj->nitems =
                                                                      1;
                                                                    ptr = (char *)
                                                                      (&c_arg);
                                                                    for (loop_ub
                                                                      = 0;
                                                                      loop_ub <
                                                                      sizepe;
                                                                      loop_ub++)
                                                                    {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                    }
                                                                  } else {
                                                                    if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                    } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                    }

                                                                    sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                    b_name->
                                                                      size[0] =
                                                                      1;
                                                                    loop_ub = i1
                                                                      - i;
                                                                    b_name->
                                                                      size[1] =
                                                                      loop_ub;
                                                                    emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                    for (i1 = 0;
                                                                      i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 6; i++)
                                                                      {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv2[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&c_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                    } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 6; i++)
                                                                      {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv2[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&c_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 6; i++)
                                                                      {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv2[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&c_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 6; i++)
                                                                      {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv2[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&c_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                      }

                                                                      if
                                                                      (mb_isequal
                                                                      (b_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_ANY_SOURCE;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      obj->
                                                                      type->
                                                                      data[0] =
                                                                      'i';
                                                                      obj->
                                                                      type->
                                                                      data[1] =
                                                                      'n';
                                                                      obj->
                                                                      type->
                                                                      data[2] =
                                                                      't';
                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                      }

                                                                      if
                                                                      (nb_isequal
                                                                      (b_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_ANY_TAG;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      obj->
                                                                      type->
                                                                      data[0] =
                                                                      'i';
                                                                      obj->
                                                                      type->
                                                                      data[1] =
                                                                      'n';
                                                                      obj->
                                                                      type->
                                                                      data[2] =
                                                                      't';
                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 6; i++)
                                                                      {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv3[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&e_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 14; i
                                                                      ++) {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv4[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&f_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 14; i
                                                                      ++) {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv4[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&f_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                      }

                                                                      if
                                                                      (rb_isequal
                                                                      (b_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_BSEND_OVERHEAD;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      obj->
                                                                      type->
                                                                      data[0] =
                                                                      'i';
                                                                      obj->
                                                                      type->
                                                                      data[1] =
                                                                      'n';
                                                                      obj->
                                                                      type->
                                                                      data[2] =
                                                                      't';
                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                      }

                                                                      if
                                                                      (sb_isequal
                                                                      (b_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_UNDEFINED;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      obj->
                                                                      type->
                                                                      data[0] =
                                                                      'i';
                                                                      obj->
                                                                      type->
                                                                      data[1] =
                                                                      'n';
                                                                      obj->
                                                                      type->
                                                                      data[2] =
                                                                      't';
                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                      }

                                                                      if
                                                                      (tb_isequal
                                                                      (b_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_IDENT;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      obj->
                                                                      type->
                                                                      data[0] =
                                                                      'i';
                                                                      obj->
                                                                      type->
                                                                      data[1] =
                                                                      'n';
                                                                      obj->
                                                                      type->
                                                                      data[2] =
                                                                      't';
                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                      }

                                                                      if
                                                                      (ub_isequal
                                                                      (b_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_CONGRUENT;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      obj->
                                                                      type->
                                                                      data[0] =
                                                                      'i';
                                                                      obj->
                                                                      type->
                                                                      data[1] =
                                                                      'n';
                                                                      obj->
                                                                      type->
                                                                      data[2] =
                                                                      't';
                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                      }

                                                                      if
                                                                      (vb_isequal
                                                                      (b_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_SIMILAR;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      obj->
                                                                      type->
                                                                      data[0] =
                                                                      'i';
                                                                      obj->
                                                                      type->
                                                                      data[1] =
                                                                      'n';
                                                                      obj->
                                                                      type->
                                                                      data[2] =
                                                                      't';
                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                      }

                                                                      if
                                                                      (wb_isequal
                                                                      (b_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_UNEQUAL;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      obj->
                                                                      type->
                                                                      data[0] =
                                                                      'i';
                                                                      obj->
                                                                      type->
                                                                      data[1] =
                                                                      'n';
                                                                      obj->
                                                                      type->
                                                                      data[2] =
                                                                      't';
                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                      }

                                                                      if
                                                                      (xb_isequal
                                                                      (b_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_MAX_PROCESSOR_NAME;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      obj->
                                                                      type->
                                                                      data[0] =
                                                                      'i';
                                                                      obj->
                                                                      type->
                                                                      data[1] =
                                                                      'n';
                                                                      obj->
                                                                      type->
                                                                      data[2] =
                                                                      't';
                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                      }

                                                                      if
                                                                      (yb_isequal
                                                                      (b_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_GRAPH;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      obj->
                                                                      type->
                                                                      data[0] =
                                                                      'i';
                                                                      obj->
                                                                      type->
                                                                      data[1] =
                                                                      'n';
                                                                      obj->
                                                                      type->
                                                                      data[2] =
                                                                      't';
                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
                                                                      }

                                                                      if
                                                                      (ac_isequal
                                                                      (b_name))
                                                                      {
                                                                      d_arg =
                                                                      MPI_CART;
                                                                      sizepe =
                                                                      sizeof(int);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      obj->
                                                                      type->
                                                                      data[0] =
                                                                      'i';
                                                                      obj->
                                                                      type->
                                                                      data[1] =
                                                                      'n';
                                                                      obj->
                                                                      type->
                                                                      data[2] =
                                                                      't';
                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&d_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 11; i
                                                                      ++) {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv5[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&g_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 9; i++)
                                                                      {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv6[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&h_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 9; i++)
                                                                      {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv6[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&h_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 12; i
                                                                      ++) {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv7[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&i_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 8; i++)
                                                                      {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv8[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&j_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 7; i++)
                                                                      {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv9[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&k_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      if (5 >
                                                                      name->
                                                                      size[1]) {
                                                                      i = 0;
                                                                      i1 = 0;
                                                                      } else {
                                                                      i = 4;
                                                                      i1 =
                                                                      name->
                                                                      size[1];
                                                                      }

                                                                      sizepe =
                                                                      b_name->size
                                                                      [0] *
                                                                      b_name->size
                                                                      [1];
                                                                      b_name->size
                                                                      [0] = 1;
                                                                      loop_ub =
                                                                      i1 - i;
                                                                      b_name->size
                                                                      [1] =
                                                                      loop_ub;
                                                                      emxEnsureCapacity_char_T
                                                                      (b_name,
                                                                      sizepe);
                                                                      for (i1 =
                                                                      0; i1 <
                                                                      loop_ub;
                                                                      i1++) {
                                                                      b_name->data
                                                                      [i1] =
                                                                      name->
                                                                      data[i +
                                                                      i1];
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
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 5; i++)
                                                                      {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv10[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&l_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }
                                                                      } else {
                                                                      e_arg =
                                                                      NULL;
                                                                      sizepe =
                                                                      sizeof
                                                                      (void *);
                                                                      i =
                                                                      obj->
                                                                      data->
                                                                      size[0];
                                                                      obj->
                                                                      data->
                                                                      size[0] =
                                                                      sizepe;
                                                                      emxEnsureCapacity_uint8_T
                                                                      (obj->data,
                                                                      i);
                                                                      i =
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
                                                                      i);
                                                                      for (i = 0;
                                                                      i < 6; i++)
                                                                      {
                                                                      obj->
                                                                      type->
                                                                      data[i] =
                                                                      cv3[i];
                                                                      }

                                                                      obj->nitems
                                                                      = 1;
                                                                      ptr =
                                                                      (char *)
                                                                      (&e_arg);
                                                                      for
                                                                      (loop_ub =
                                                                      0; loop_ub
                                                                      < sizepe;
                                                                      loop_ub++)
                                                                      {
                                                                      obj->
                                                                      data->
                                                                      data[loop_ub]
                                                                      = *(ptr);
                                                                      ptr =
                                                                      ptr + 1;
                                                                      }

                                                                      i =
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
                                                                      (b_name, i);
                                                                      loop_ub =
                                                                      name->
                                                                      size[1];
                                                                      for (i = 0;
                                                                      i <
                                                                      loop_ub; i
                                                                      ++) {
                                                                      b_name->data
                                                                      [i] =
                                                                      name->
                                                                      data[i];
                                                                      }

                                                                      b_name->data
                                                                      [name->size
                                                                      [1]] =
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
}

void mpi_get_const_initialize(void)
{
}

void mpi_get_const_terminate(void)
{
}
