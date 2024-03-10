#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../parser.h"

START_TEST(correct_input) {
  data_t parse_data = {0};

  char const* pathtofile = "../src/assets/test.obj";
  ck_assert_int_eq(get_parse_data(&parse_data, pathtofile), 0);
}
END_TEST

START_TEST(incorrect_input) {
  data_t parse_data = {0};
  char const* pathtofile = "assets/test8.obj";
  ck_assert_int_eq(get_parse_data(&parse_data, pathtofile), 1);
}
END_TEST

START_TEST(parser_array) {
  data_t parse_data = {0};
  char const* pathtofile = "assets/test.obj";
  polygon_t polygons;       // free
  double* vertices = NULL;  // free
  FILE* fd;
  fd = fopen(pathtofile, "r");
  get_parse_data(&parse_data, pathtofile);
  get_vertices(fd, parse_data.amount_vertices, &vertices);

  ck_assert_float_eq_tol(vertices[0], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[1], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[2], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[3], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[4], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[5], 1, 1e-6);
  ck_assert_float_eq_tol(vertices[6], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[7], 1, 1e-6);
  ck_assert_float_eq_tol(vertices[8], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[9], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[10], 1, 1e-6);
  ck_assert_float_eq_tol(vertices[11], 1, 1e-6);
  ck_assert_float_eq_tol(vertices[12], 1, 1e-6);
  ck_assert_float_eq_tol(vertices[13], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[14], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[15], 1, 1e-6);
  ck_assert_float_eq_tol(vertices[16], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[17], 1, 1e-6);
  ck_assert_float_eq_tol(vertices[18], 1, 1e-6);
  ck_assert_float_eq_tol(vertices[19], 1, 1e-6);
  ck_assert_float_eq_tol(vertices[20], 0, 1e-6);
  ck_assert_float_eq_tol(vertices[21], 1, 1e-6);
  ck_assert_float_eq_tol(vertices[22], 1, 1e-6);
  ck_assert_float_eq_tol(vertices[23], 1, 1e-6);
  free(vertices);
  fclose(fd);
}
END_TEST

START_TEST(parser_polygon) {
  data_t parse_data = {0};
  char const* pathtofile = "assets/test.obj";
  polygon_t polygons;       // free
  double* vertices = NULL;  // free
  FILE* fd;
  fd = fopen(pathtofile, "r");
  get_parse_data(&parse_data, pathtofile);
  get_polygons(fd, parse_data.amount_polygons, &polygons);

  ck_assert_int_eq(polygons.vertices[0], 0);
  ck_assert_int_eq(polygons.vertices[1], 6);
  ck_assert_int_eq(polygons.vertices[2], 6);
  ck_assert_int_eq(polygons.vertices[3], 4);
  ck_assert_int_eq(polygons.vertices[4], 4);
  ck_assert_int_eq(polygons.vertices[5], 0);
  ck_assert_int_eq(polygons.vertices[6], 0);
  ck_assert_int_eq(polygons.vertices[7], 2);
  ck_assert_int_eq(polygons.vertices[8], 2);
  ck_assert_int_eq(polygons.vertices[9], 6);
  ck_assert_int_eq(polygons.vertices[10], 6);
  ck_assert_int_eq(polygons.vertices[11], 0);
  ck_assert_int_eq(polygons.vertices[12], 0);
  ck_assert_int_eq(polygons.vertices[13], 3);
  ck_assert_int_eq(polygons.vertices[14], 3);
  ck_assert_int_eq(polygons.vertices[15], 2);
  ck_assert_int_eq(polygons.vertices[16], 2);
  ck_assert_int_eq(polygons.vertices[17], 0);
  ck_assert_int_eq(polygons.vertices[18], 0);
  ck_assert_int_eq(polygons.vertices[19], 1);
  ck_assert_int_eq(polygons.vertices[20], 1);
  ck_assert_int_eq(polygons.vertices[21], 3);
  ck_assert_int_eq(polygons.vertices[22], 3);
  ck_assert_int_eq(polygons.vertices[23], 0);
  ck_assert_int_eq(polygons.vertices[24], 2);
  ck_assert_int_eq(polygons.vertices[25], 7);
  ck_assert_int_eq(polygons.vertices[26], 7);
  ck_assert_int_eq(polygons.vertices[27], 6);
  ck_assert_int_eq(polygons.vertices[28], 6);
  ck_assert_int_eq(polygons.vertices[29], 2);
  free(polygons.vertices);
  free(vertices);
  fclose(fd);
}
END_TEST

START_TEST(max_vertex) {
  data_t parse_data = {0};
  char const* pathtofile = "assets/test.obj";
  polygon_t polygons;       // free
  double* vertices = NULL;  // free
  FILE* fd;
  fd = fopen(pathtofile, "r");
  get_parse_data(&parse_data, pathtofile);
  get_vertices(fd, parse_data.amount_vertices, &vertices);
  get_polygons(fd, parse_data.amount_polygons, &polygons);
  ck_assert_float_eq_tol(get_max_vector(vertices, parse_data.amount_polygons),
                         1, 1e-6);
  free(polygons.vertices);
  free(vertices);
  fclose(fd);
}
END_TEST

Suite* s21_3d_suite(void) {
  Suite* suite;

  suite = suite_create("s21_3d");
  TCase* tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, incorrect_input);
  tcase_add_test(tcase_core, correct_input);
  tcase_add_test(tcase_core, parser_array);
  tcase_add_test(tcase_core, parser_polygon);
  tcase_add_test(tcase_core, max_vertex);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite* suite = s21_3d_suite();
  SRunner* suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
