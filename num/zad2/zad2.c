#include <stdio.h>
#include <gsl/gsl_linalg.h>

int main(void)
{
    double a1_data[] = {2.40827208, -0.36066254, 0.80575445, 0.46309511, 1.20708553,
                        -0.36066254, 1.14839502, 0.02576113, 0.02672584, -1.03949556,
                        0.80575445, 0.02576113, 2.45964907, 0.13824088, 0.0472749,
                        0.46309511, 0.02672584, 0.13824088, 2.05614464, -0.9434493,
                        1.20708553, -1.03949556, 0.0472749, -0.9434493, 1.92753926};

    double a2_data[] = {2.61370745, -0.6334453, 0.76061329, 0.24938964, 0.82783473,
                        -0.6334453, 1.51060349, 0.08570081, 0.31048984, -0.53591589,
                        0.76061329, 0.08570081, 2.46956812, 0.18519926, 0.13060932,
                        0.24938964, 0.31048984, 0.18519926, 2.27845311, -0.54893124,
                        0.82783473, -0.53591589, 0.13060932, -0.54893124, 2.6276678};

    double b1_data[] = {5.40780228, 3.67008677, 3.12306266, -1.11187948, 0.54437218};
    double b2_data[] = {5.40781228, 3.67008677, 3.12306266, -1.11187948, 0.54437218};

    ///////////////////////////////////////////
    //A1 b1
    gsl_matrix_view m11 = gsl_matrix_view_array(a1_data, 5, 5);

    gsl_vector_view b11 = gsl_vector_view_array(b1_data, 5);

    gsl_vector *x11 = gsl_vector_alloc(5);

    int s11;

    gsl_permutation *p11 = gsl_permutation_alloc(5);

    gsl_linalg_LU_decomp(&m11.matrix, p11, &s11);

    gsl_linalg_LU_solve(&m11.matrix, p11, &b11.vector, x11);

    printf("y1 = \n");
    gsl_vector_fprintf(stdout, x11, "%g");

    printf("\n \n \n");

    ///////////////////////////////////////////
    //A1 b2
    gsl_matrix_view m12 = gsl_matrix_view_array(a1_data, 5, 5);

    gsl_vector_view b12 = gsl_vector_view_array(b2_data, 5);

    gsl_vector *x12 = gsl_vector_alloc(5);

    int s12;

    gsl_permutation *p12 = gsl_permutation_alloc(5);

    gsl_linalg_LU_decomp(&m12.matrix, p12, &s12);

    gsl_linalg_LU_solve(&m12.matrix, p12, &b12.vector, x12);

    printf("y1' = \n");
    gsl_vector_fprintf(stdout, x12, "%g");

    printf("\n \n \n");

    ////////////////////////////////////////////////////////
    //A2 b2
    gsl_matrix_view m22 = gsl_matrix_view_array(a2_data, 5, 5);

    gsl_vector_view b22 = gsl_vector_view_array(b2_data, 5);

    gsl_vector *x22 = gsl_vector_alloc(5);

    int s22;

    gsl_permutation *p22 = gsl_permutation_alloc(5);

    gsl_linalg_LU_decomp(&m22.matrix, p22, &s22);

    gsl_linalg_LU_solve(&m22.matrix, p22, &b22.vector, x22);

    printf("y2' = \n");
    gsl_vector_fprintf(stdout, x22, "%g");
    printf("\n \n \n");

    ////////////////////////////////////////////////////////
    //A2 b1
    gsl_matrix_view m21 = gsl_matrix_view_array(a2_data, 5, 5);

    gsl_vector_view b21 = gsl_vector_view_array(b1_data, 5);

    gsl_vector *x21 = gsl_vector_alloc(5);

    int s21;

    gsl_permutation *p21 = gsl_permutation_alloc(5);

    gsl_linalg_LU_decomp(&m21.matrix, p21, &s21);

    gsl_linalg_LU_solve(&m21.matrix, p21, &b21.vector, x21);

    printf("y2 = \n");
    gsl_vector_fprintf(stdout, x21, "%g");
    printf("\n \n \n");

    ///////////////////////////////////////////

    gsl_vector_sub(x11, x12);

    double n1 = gsl_blas_dnrm2(x11);
    printf("||y1 - y1'||_2=%f \n", n1);
    printf("\n \n \n");

    gsl_vector_sub(x21, x22);

    double n2 = gsl_blas_dnrm2(x21);
    printf("||y2 - y2'||_2=%f\n", n2);
    printf("\n \n \n");

    gsl_permutation_free(p11);
    gsl_vector_free(x11);

    gsl_permutation_free(p12);
    gsl_vector_free(x12);

    gsl_permutation_free(p21);
    gsl_vector_free(x21);

    gsl_permutation_free(p22);
    gsl_vector_free(x22);

    return 0;
}