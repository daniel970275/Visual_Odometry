/**************************************************************
 * @file    EPnP.h
 * @author  Chau En, Kuo
 * @date    05/13/23
 * @brief
 **************************************************************/

#include "Math.h"
#include "sym_svd.hpp"

#define MODEL_POINTS 5

void swap(FLOAT &a, FLOAT &b);

void inv(FLOAT input[3][3], FLOAT output[3][3]);

void compute_R_and_t(FLOAT u[12][4], FLOAT betas[4],
                     FLOAT alphas[MODEL_POINTS][4],
                     FLOAT pws[MODEL_POINTS][3],
                     FLOAT R[3][3], FLOAT t[3]);

void estimate_R_t(FLOAT u3[12][4], FLOAT Betas3[4],
                  FLOAT alphas3[MODEL_POINTS][4],
                  FLOAT pws3[MODEL_POINTS][3],
                  FLOAT u4[12][4], FLOAT Betas4[4],
                  FLOAT alphas4[MODEL_POINTS][4],
                  FLOAT pws4[MODEL_POINTS][3],
                  FLOAT u5[12][4], FLOAT Betas5[4],
                  FLOAT alphas5[MODEL_POINTS][4],
                  FLOAT pws5[MODEL_POINTS][3],
                  FLOAT R3[3][3], FLOAT t3[3],
                  FLOAT R4[3][3], FLOAT t4[3],
                  FLOAT R5[3][3], FLOAT t5[3]);

void compute_R_and_t_x3(FLOAT u[12 * 12],
                        FLOAT Beta3[4], FLOAT Beta4[4], FLOAT Beta5[4],
                        FLOAT alphas[MODEL_POINTS][4],
                        FLOAT pws[MODEL_POINTS][3],
                        FLOAT R[9][3], FLOAT t[9]);

void gauss_newton(FLOAT L_6x10[6][10], FLOAT Rho[6], FLOAT betas[4]);

void epnp(OPOINT opoint[MODEL_POINTS],
          IPOINT ipoint[MODEL_POINTS],
          FLOAT fx, FLOAT fy, FLOAT cx, FLOAT cy,
          FLOAT rmat[9], FLOAT tvec[3]);