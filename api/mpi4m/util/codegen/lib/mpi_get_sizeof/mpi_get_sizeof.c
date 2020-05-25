#include "mpi_get_sizeof.h"
#include "m2c.h"
#include "mpi.h"

static boolean_T b_strcmp(const emxArray_char_T *a);
static boolean_T c_strcmp(const emxArray_char_T *a);
static boolean_T d_strcmp(const emxArray_char_T *a);
static void m2c_error(const emxArray_char_T *varargin_3);
static boolean_T b_strcmp(const emxArray_char_T *a)
{
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv[4] = { 'C', 'H', 'A', 'R' };

  b_bool = false;
  if (a->size[1] == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a->data[kstr] != cv[kstr]) {
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
  static const char cv[13] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_', 'C',
    'H', 'A', 'R' };

  b_bool = false;
  if (a->size[1] == 13) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 13) {
        if (a->data[kstr] != cv[kstr]) {
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
  static const char cv[4] = { 'B', 'Y', 'T', 'E' };

  b_bool = false;
  if (a->size[1] == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a->data[kstr] != cv[kstr]) {
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

  M2C_error("mpi_get_sizeof:UnknownType", "Unknonw datatype %s.",
            &b_varargin_3->data[0]);
  emxFree_char_T(&b_varargin_3);
}

int mpi_get_sizeof(const emxArray_char_T *typename)
{
  int n;
  int i;
  int i1;
  boolean_T b_bool;
  int kstr;
  int exitg1;
  static const char cv[7] = { 'R', 'e', 'q', 'u', 'e', 's', 't' };

  static const char cv1[6] = { 'S', 't', 'a', 't', 'u', 's' };

  static const char cv2[4] = { 'A', 'i', 'n', 't' };

  static const char cv3[2] = { 'O', 'p' };

  static const char cv4[8] = { 'D', 'a', 't', 'a', 't', 'y', 'p', 'e' };

  emxArray_char_T *b_typename;
  static const char cv5[6] = { 'D', 'O', 'U', 'B', 'L', 'E' };

  static const char cv6[4] = { '2', 'I', 'N', 'T' };

  static const char cv7[5] = { 'F', 'L', 'O', 'A', 'T' };

  static const char cv8[3] = { 'I', 'N', 'T' };

  static const char cv9[8] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D' };

  static const char cv10[5] = { 'S', 'H', 'O', 'R', 'T' };

  static const char cv11[14] = { 'U', 'N', 'S', 'I', 'G', 'N', 'E', 'D', '_',
    'S', 'H', 'O', 'R', 'T' };

  int loop_ub;
  n = 0;
  if (5 > typename->size[1]) {
    i = 1;
    i1 = 1;
  } else {
    i = 5;
    i1 = typename->size[1] + 1;
  }

  b_bool = false;
  if (i1 - i == 7) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 7) {
        if (typename->data[(i + kstr) - 1] != cv[kstr]) {
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

  if (b_bool) {
    n = sizeof(MPI_Request);
  } else {
    if (5 > typename->size[1]) {
      i = 1;
      i1 = 1;
    } else {
      i = 5;
      i1 = typename->size[1] + 1;
    }

    b_bool = false;
    if (i1 - i == 6) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 6) {
          if (typename->data[(i + kstr) - 1] != cv1[kstr]) {
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

    if (b_bool) {
      n = sizeof(MPI_Status);
    } else {
      if (5 > typename->size[1]) {
        i = 1;
        i1 = 1;
      } else {
        i = 5;
        i1 = typename->size[1] + 1;
      }

      b_bool = false;
      if (i1 - i == 4) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 4) {
            if (typename->data[(i + kstr) - 1] != cv2[kstr]) {
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

      if (b_bool) {
        n = sizeof(MPI_Aint);
      } else {
        if (5 > typename->size[1]) {
          i = 1;
          i1 = 1;
        } else {
          i = 5;
          i1 = typename->size[1] + 1;
        }

        b_bool = false;
        if (i1 - i == 2) {
          kstr = 0;
          do {
            exitg1 = 0;
            if (kstr < 2) {
              if (typename->data[(i + kstr) - 1] != cv3[kstr]) {
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

        if (b_bool) {
          n = sizeof(MPI_Op);
        } else {
          if (5 > typename->size[1]) {
            i = 1;
            i1 = 1;
          } else {
            i = 5;
            i1 = typename->size[1] + 1;
          }

          b_bool = false;
          if (i1 - i == 8) {
            kstr = 0;
            do {
              exitg1 = 0;
              if (kstr < 8) {
                if (typename->data[(i + kstr) - 1] != cv4[kstr]) {
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

          if (b_bool) {
            n = sizeof(MPI_Datatype);
          } else {
            if (5 > typename->size[1]) {
              i = 1;
              i1 = 1;
            } else {
              i = 5;
              i1 = typename->size[1] + 1;
            }

            b_bool = false;
            if (i1 - i == 6) {
              kstr = 0;
              do {
                exitg1 = 0;
                if (kstr < 6) {
                  if (typename->data[(i + kstr) - 1] != cv5[kstr]) {
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

            emxInit_char_T(&b_typename, 2);
            if (b_bool) {
              n = 8;
            } else {
              if (5 > typename->size[1]) {
                i = 1;
                i1 = 1;
              } else {
                i = 5;
                i1 = typename->size[1] + 1;
              }

              b_bool = false;
              if (i1 - i == 4) {
                kstr = 0;
                do {
                  exitg1 = 0;
                  if (kstr < 4) {
                    if (typename->data[(i + kstr) - 1] != cv6[kstr]) {
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

              if (b_bool) {
                n = 8;
              } else {
                if (5 > typename->size[1]) {
                  i = 1;
                  i1 = 1;
                } else {
                  i = 5;
                  i1 = typename->size[1] + 1;
                }

                b_bool = false;
                if (i1 - i == 5) {
                  kstr = 0;
                  do {
                    exitg1 = 0;
                    if (kstr < 5) {
                      if (typename->data[(i + kstr) - 1] != cv7[kstr]) {
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

                if (b_bool) {
                  n = 4;
                } else {
                  if (5 > typename->size[1]) {
                    i = 1;
                    i1 = 1;
                  } else {
                    i = 5;
                    i1 = typename->size[1] + 1;
                  }

                  b_bool = false;
                  if (i1 - i == 3) {
                    kstr = 0;
                    do {
                      exitg1 = 0;
                      if (kstr < 3) {
                        if (typename->data[(i + kstr) - 1] != cv8[kstr]) {
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

                  if (b_bool) {
                    n = 4;
                  } else {
                    if (5 > typename->size[1]) {
                      i = 1;
                      i1 = 1;
                    } else {
                      i = 5;
                      i1 = typename->size[1] + 1;
                    }

                    b_bool = false;
                    if (i1 - i == 8) {
                      kstr = 0;
                      do {
                        exitg1 = 0;
                        if (kstr < 8) {
                          if (typename->data[(i + kstr) - 1] != cv9[kstr]) {
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

                    if (b_bool) {
                      n = 4;
                    } else {
                      if (5 > typename->size[1]) {
                        i = 1;
                        i1 = 1;
                      } else {
                        i = 5;
                        i1 = typename->size[1] + 1;
                      }

                      b_bool = false;
                      if (i1 - i == 5) {
                        kstr = 0;
                        do {
                          exitg1 = 0;
                          if (kstr < 5) {
                            if (typename->data[(i + kstr) - 1] != cv10[kstr]) {
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

                      if (b_bool) {
                        n = 2;
                      } else {
                        if (5 > typename->size[1]) {
                          i = 1;
                          i1 = 1;
                        } else {
                          i = 5;
                          i1 = typename->size[1] + 1;
                        }

                        b_bool = false;
                        if (i1 - i == 14) {
                          kstr = 0;
                          do {
                            exitg1 = 0;
                            if (kstr < 14) {
                              if (typename->data[(i + kstr) - 1] != cv11[kstr])
                              {
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

                        if (b_bool) {
                          n = 2;
                        } else {
                          if (5 > typename->size[1]) {
                            i = 0;
                            i1 = 0;
                          } else {
                            i = 4;
                            i1 = typename->size[1];
                          }

                          kstr = b_typename->size[0] * b_typename->size[1];
                          b_typename->size[0] = 1;
                          loop_ub = i1 - i;
                          b_typename->size[1] = loop_ub;
                          emxEnsureCapacity_char_T(b_typename, kstr);
                          for (i1 = 0; i1 < loop_ub; i1++) {
                            b_typename->data[i1] = typename->data[i + i1];
                          }

                          if (b_strcmp(b_typename)) {
                            n = 1;
                          } else {
                            if (5 > typename->size[1]) {
                              i = 0;
                              i1 = 0;
                            } else {
                              i = 4;
                              i1 = typename->size[1];
                            }

                            kstr = b_typename->size[0] * b_typename->size[1];
                            b_typename->size[0] = 1;
                            loop_ub = i1 - i;
                            b_typename->size[1] = loop_ub;
                            emxEnsureCapacity_char_T(b_typename, kstr);
                            for (i1 = 0; i1 < loop_ub; i1++) {
                              b_typename->data[i1] = typename->data[i + i1];
                            }

                            if (c_strcmp(b_typename)) {
                              n = 1;
                            } else {
                              if (5 > typename->size[1]) {
                                i = 0;
                                i1 = 0;
                              } else {
                                i = 4;
                                i1 = typename->size[1];
                              }

                              kstr = b_typename->size[0] * b_typename->size[1];
                              b_typename->size[0] = 1;
                              loop_ub = i1 - i;
                              b_typename->size[1] = loop_ub;
                              emxEnsureCapacity_char_T(b_typename, kstr);
                              for (i1 = 0; i1 < loop_ub; i1++) {
                                b_typename->data[i1] = typename->data[i + i1];
                              }

                              if (d_strcmp(b_typename)) {
                                n = 1;
                              } else {
                                i = b_typename->size[0] * b_typename->size[1];
                                b_typename->size[0] = 1;
                                b_typename->size[1] = typename->size[1] + 1;
                                emxEnsureCapacity_char_T(b_typename, i);
                                loop_ub = typename->size[1];
                                for (i = 0; i < loop_ub; i++) {
                                  b_typename->data[i] = typename->data[i];
                                }

                                b_typename->data[typename->size[1]] = '\x00';
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

            emxFree_char_T(&b_typename);
          }
        }
      }
    }
  }

  return n;
}

void mpi_get_sizeof_initialize(void)
{
}

void mpi_get_sizeof_terminate(void)
{
}
