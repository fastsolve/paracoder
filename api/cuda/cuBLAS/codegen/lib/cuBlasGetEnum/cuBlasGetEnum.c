#include "cuBlasGetEnum.h"
#include "m2c.h"
#include "cuda4m.h"

int cuBlasGetEnum(const emxArray_char_T *str)
{
  int val;
  boolean_T b_bool;
  int kstr;
  int exitg12;
  static const char cv0[24] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'P', 'O', 'I',
    'N', 'T', 'E', 'R', '_', 'M', 'O', 'D', 'E', '_', 'H', 'O', 'S', 'T' };

  int exitg11;
  static const char cv1[26] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'P', 'O', 'I',
    'N', 'T', 'E', 'R', '_', 'M', 'O', 'D', 'E', '_', 'D', 'E', 'V', 'I', 'C',
    'E' };

  int exitg10;
  static const char cv2[26] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'A', 'T', 'O',
    'M', 'I', 'C', 'S', '_', 'N', 'O', 'T', '_', 'A', 'L', 'L', 'O', 'W', 'E',
    'D' };

  int exitg9;
  static const char cv3[22] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'A', 'T', 'O',
    'M', 'I', 'C', 'S', '_', 'A', 'L', 'L', 'O', 'W', 'E', 'D' };

  int exitg8;
  static const char cv4[21] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'S', 'U', 'C', 'C', 'E', 'S', 'S' };

  int exitg7;
  static const char cv5[29] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'N', 'O', 'T', '_', 'I', 'N', 'I', 'T', 'I', 'A', 'L',
    'I', 'Z', 'E', 'D' };

  int exitg6;
  static const char cv6[26] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'A', 'L', 'L', 'O', 'C', '_', 'F', 'A', 'I', 'L', 'E',
    'D' };

  int exitg5;
  static const char cv7[27] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'I', 'N', 'V', 'A', 'L', 'I', 'D', '_', 'V', 'A', 'L',
    'U', 'E' };

  int exitg4;
  static const char cv8[27] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'A', 'R', 'C', 'H', '_', 'M', 'I', 'S', 'M', 'A', 'T',
    'C', 'H' };

  int exitg3;
  static const char cv9[27] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T', 'A',
    'T', 'U', 'S', '_', 'M', 'A', 'P', 'P', 'I', 'N', 'G', '_', 'E', 'R', 'R',
    'O', 'R' };

  int exitg2;
  static const char cv10[30] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T',
    'A', 'T', 'U', 'S', '_', 'E', 'X', 'E', 'C', 'U', 'T', 'I', 'O', 'N', '_',
    'F', 'A', 'I', 'L', 'E', 'D' };

  int exitg1;
  static const char cv11[28] = { 'C', 'U', 'B', 'L', 'A', 'S', '_', 'S', 'T',
    'A', 'T', 'U', 'S', '_', 'I', 'N', 'T', 'E', 'R', 'N', 'A', 'L', '_', 'E',
    'R', 'R', 'O', 'R' };

  b_bool = false;
  if (str->size[1] == 24) {
    kstr = 0;
    do {
      exitg12 = 0;
      if (kstr + 1 < 25) {
        if (str->data[kstr] != cv0[kstr]) {
          exitg12 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg12 = 1;
      }
    } while (exitg12 == 0);
  }

  if (b_bool) {
    kstr = 0;
  } else {
    b_bool = false;
    if (str->size[1] == 26) {
      kstr = 0;
      do {
        exitg11 = 0;
        if (kstr + 1 < 27) {
          if (str->data[kstr] != cv1[kstr]) {
            exitg11 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg11 = 1;
        }
      } while (exitg11 == 0);
    }

    if (b_bool) {
      kstr = 1;
    } else {
      b_bool = false;
      if (str->size[1] == 26) {
        kstr = 0;
        do {
          exitg10 = 0;
          if (kstr + 1 < 27) {
            if (str->data[kstr] != cv2[kstr]) {
              exitg10 = 1;
            } else {
              kstr++;
            }
          } else {
            b_bool = true;
            exitg10 = 1;
          }
        } while (exitg10 == 0);
      }

      if (b_bool) {
        kstr = 2;
      } else {
        b_bool = false;
        if (str->size[1] == 22) {
          kstr = 0;
          do {
            exitg9 = 0;
            if (kstr + 1 < 23) {
              if (str->data[kstr] != cv3[kstr]) {
                exitg9 = 1;
              } else {
                kstr++;
              }
            } else {
              b_bool = true;
              exitg9 = 1;
            }
          } while (exitg9 == 0);
        }

        if (b_bool) {
          kstr = 3;
        } else {
          b_bool = false;
          if (str->size[1] == 21) {
            kstr = 0;
            do {
              exitg8 = 0;
              if (kstr + 1 < 22) {
                if (str->data[kstr] != cv4[kstr]) {
                  exitg8 = 1;
                } else {
                  kstr++;
                }
              } else {
                b_bool = true;
                exitg8 = 1;
              }
            } while (exitg8 == 0);
          }

          if (b_bool) {
            kstr = 4;
          } else {
            b_bool = false;
            if (str->size[1] == 29) {
              kstr = 0;
              do {
                exitg7 = 0;
                if (kstr + 1 < 30) {
                  if (str->data[kstr] != cv5[kstr]) {
                    exitg7 = 1;
                  } else {
                    kstr++;
                  }
                } else {
                  b_bool = true;
                  exitg7 = 1;
                }
              } while (exitg7 == 0);
            }

            if (b_bool) {
              kstr = 5;
            } else {
              b_bool = false;
              if (str->size[1] == 26) {
                kstr = 0;
                do {
                  exitg6 = 0;
                  if (kstr + 1 < 27) {
                    if (str->data[kstr] != cv6[kstr]) {
                      exitg6 = 1;
                    } else {
                      kstr++;
                    }
                  } else {
                    b_bool = true;
                    exitg6 = 1;
                  }
                } while (exitg6 == 0);
              }

              if (b_bool) {
                kstr = 6;
              } else {
                b_bool = false;
                if (str->size[1] == 27) {
                  kstr = 0;
                  do {
                    exitg5 = 0;
                    if (kstr + 1 < 28) {
                      if (str->data[kstr] != cv7[kstr]) {
                        exitg5 = 1;
                      } else {
                        kstr++;
                      }
                    } else {
                      b_bool = true;
                      exitg5 = 1;
                    }
                  } while (exitg5 == 0);
                }

                if (b_bool) {
                  kstr = 7;
                } else {
                  b_bool = false;
                  if (str->size[1] == 27) {
                    kstr = 0;
                    do {
                      exitg4 = 0;
                      if (kstr + 1 < 28) {
                        if (str->data[kstr] != cv8[kstr]) {
                          exitg4 = 1;
                        } else {
                          kstr++;
                        }
                      } else {
                        b_bool = true;
                        exitg4 = 1;
                      }
                    } while (exitg4 == 0);
                  }

                  if (b_bool) {
                    kstr = 8;
                  } else {
                    b_bool = false;
                    if (str->size[1] == 27) {
                      kstr = 0;
                      do {
                        exitg3 = 0;
                        if (kstr + 1 < 28) {
                          if (str->data[kstr] != cv9[kstr]) {
                            exitg3 = 1;
                          } else {
                            kstr++;
                          }
                        } else {
                          b_bool = true;
                          exitg3 = 1;
                        }
                      } while (exitg3 == 0);
                    }

                    if (b_bool) {
                      kstr = 9;
                    } else {
                      b_bool = false;
                      if (str->size[1] == 30) {
                        kstr = 0;
                        do {
                          exitg2 = 0;
                          if (kstr + 1 < 31) {
                            if (str->data[kstr] != cv10[kstr]) {
                              exitg2 = 1;
                            } else {
                              kstr++;
                            }
                          } else {
                            b_bool = true;
                            exitg2 = 1;
                          }
                        } while (exitg2 == 0);
                      }

                      if (b_bool) {
                        kstr = 10;
                      } else {
                        b_bool = false;
                        if (str->size[1] == 28) {
                          kstr = 0;
                          do {
                            exitg1 = 0;
                            if (kstr + 1 < 29) {
                              if (str->data[kstr] != cv11[kstr]) {
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
                          kstr = 11;
                        } else {
                          kstr = -1;
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

  switch (kstr) {
   case 0:
    val = (CUBLAS_POINTER_MODE_HOST);
    break;

   case 1:
    val = (CUBLAS_POINTER_MODE_DEVICE);
    break;

   case 2:
    val = (CUBLAS_ATOMICS_NOT_ALLOWED);
    break;

   case 3:
    val = (CUBLAS_ATOMICS_ALLOWED);
    break;

   case 4:
    val = (CUBLAS_STATUS_SUCCESS);
    break;

   case 5:
    val = (CUBLAS_STATUS_NOT_INITIALIZED);
    break;

   case 6:
    val = (CUBLAS_STATUS_ALLOC_FAILED);
    break;

   case 7:
    val = (CUBLAS_STATUS_INVALID_VALUE);
    break;

   case 8:
    val = (CUBLAS_STATUS_ARCH_MISMATCH);
    break;

   case 9:
    val = (CUBLAS_STATUS_MAPPING_ERROR);
    break;

   case 10:
    val = (CUBLAS_STATUS_EXECUTION_FAILED);
    break;

   case 11:
    val = (CUBLAS_STATUS_INTERNAL_ERROR);
    break;

   default:
    val = -1;
    break;
  }

  return val;
}

void cuBlasGetEnum_initialize(void)
{
}

void cuBlasGetEnum_terminate(void)
{
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}
