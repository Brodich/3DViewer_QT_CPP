#include <gtest/gtest.h>
#include <string.h>

#include <iostream>

#include "../model/parser.h"

using namespace s21;

TEST(code_return, 1) {
  Model busines_logic;
  Model::data_t parse_data = {0};

  char const* pathtofile = "../src/assets/test.obj";
  ASSERT_EQ(busines_logic.GetParseData(&parse_data, pathtofile), 0);
}

TEST(code_return, 2) {
  Model busines_logic;
  Model::data_t parse_data = {0};

  char const* pathtofile = "assets/test8.obj";
  ASSERT_EQ(busines_logic.GetParseData(&parse_data, pathtofile), 1);
}

TEST(parser_array, 1) {
  Model busines_logic;
  Model::data_t parse_data = {0};

  char const* pathtofile = "assets/test.obj";
  double* vertices = NULL;  // free
  FILE* fd;
  fd = fopen(pathtofile, "r");
  busines_logic.GetParseData(&parse_data, pathtofile);
  busines_logic.GetVertices(fd, parse_data.amount_vertices, &vertices);

  ASSERT_NEAR(vertices[0], 0, 1e-6);
  ASSERT_NEAR(vertices[1], 0, 1e-6);
  ASSERT_NEAR(vertices[2], 0, 1e-6);
  ASSERT_NEAR(vertices[3], 0, 1e-6);
  ASSERT_NEAR(vertices[4], 0, 1e-6);
  ASSERT_NEAR(vertices[5], 1, 1e-6);
  ASSERT_NEAR(vertices[6], 0, 1e-6);
  ASSERT_NEAR(vertices[7], 1, 1e-6);
  ASSERT_NEAR(vertices[8], 0, 1e-6);
  ASSERT_NEAR(vertices[9], 0, 1e-6);
  ASSERT_NEAR(vertices[10], 1, 1e-6);
  ASSERT_NEAR(vertices[11], 1, 1e-6);
  ASSERT_NEAR(vertices[12], 1, 1e-6);
  ASSERT_NEAR(vertices[13], 0, 1e-6);
  ASSERT_NEAR(vertices[14], 0, 1e-6);
  ASSERT_NEAR(vertices[15], 1, 1e-6);
  ASSERT_NEAR(vertices[16], 0, 1e-6);
  ASSERT_NEAR(vertices[17], 1, 1e-6);
  ASSERT_NEAR(vertices[18], 1, 1e-6);
  ASSERT_NEAR(vertices[19], 1, 1e-6);
  ASSERT_NEAR(vertices[20], 0, 1e-6);
  ASSERT_NEAR(vertices[21], 1, 1e-6);
  ASSERT_NEAR(vertices[22], 1, 1e-6);
  ASSERT_NEAR(vertices[23], 1, 1e-6);
  free(vertices);
  fclose(fd);
  // ASSERT_EQ(busines_logic.GetParseData(&parse_data, pathtofile), 1);
}

TEST(parser_polygon, 1) {
  Model busines_logic;
  Model::data_t parse_data = {0};

  char const* pathtofile = "assets/test.obj";
  Model::polygon_t polygons;  // free
  double* vertices = NULL;    // free
  FILE* fd;
  fd = fopen(pathtofile, "r");
  busines_logic.GetParseData(&parse_data, pathtofile);
  //    get_vertices(fd, parse_data.amount_vertices, &vertices);
  busines_logic.GetPolygons(fd, parse_data.amount_polygons, &polygons);

  ASSERT_EQ(polygons.vertices[0], 0);
  ASSERT_EQ(polygons.vertices[1], 6);
  ASSERT_EQ(polygons.vertices[2], 6);
  ASSERT_EQ(polygons.vertices[3], 4);
  ASSERT_EQ(polygons.vertices[4], 4);
  ASSERT_EQ(polygons.vertices[5], 0);
  ASSERT_EQ(polygons.vertices[6], 0);
  ASSERT_EQ(polygons.vertices[7], 2);
  ASSERT_EQ(polygons.vertices[8], 2);
  ASSERT_EQ(polygons.vertices[9], 6);
  ASSERT_EQ(polygons.vertices[10], 6);
  ASSERT_EQ(polygons.vertices[11], 0);
  ASSERT_EQ(polygons.vertices[12], 0);
  ASSERT_EQ(polygons.vertices[13], 3);
  ASSERT_EQ(polygons.vertices[14], 3);
  ASSERT_EQ(polygons.vertices[15], 2);
  ASSERT_EQ(polygons.vertices[16], 2);
  ASSERT_EQ(polygons.vertices[17], 0);
  ASSERT_EQ(polygons.vertices[18], 0);
  ASSERT_EQ(polygons.vertices[19], 1);
  ASSERT_EQ(polygons.vertices[20], 1);
  ASSERT_EQ(polygons.vertices[21], 3);
  ASSERT_EQ(polygons.vertices[22], 3);
  ASSERT_EQ(polygons.vertices[23], 0);
  ASSERT_EQ(polygons.vertices[24], 2);
  ASSERT_EQ(polygons.vertices[25], 7);
  ASSERT_EQ(polygons.vertices[26], 7);
  ASSERT_EQ(polygons.vertices[27], 6);
  ASSERT_EQ(polygons.vertices[28], 6);
  ASSERT_EQ(polygons.vertices[29], 2);
  free(polygons.vertices);
  free(vertices);
  fclose(fd);
}

TEST(max_vertex, 1) {
  Model busines_logic;
  Model::data_t parse_data = {0};

  char const* pathtofile = "assets/test.obj";
  Model::polygon_t polygons;  // free
  double* vertices = NULL;    // free
  FILE* fd;
  fd = fopen(pathtofile, "r");
  busines_logic.GetParseData(&parse_data, pathtofile);
  busines_logic.GetVertices(fd, parse_data.amount_vertices, &vertices);
  busines_logic.GetPolygons(fd, parse_data.amount_polygons, &polygons);
  ASSERT_NEAR(busines_logic.GetMaxVector(vertices, parse_data.amount_polygons),
              1, 1e-6);
  free(polygons.vertices);
  free(vertices);
  fclose(fd);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
