#ifndef CPP_3DVIEWER_V2_MODEL_H_
#define CPP_3DVIEWER_V2_MODEL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_BUFFER 512
#define ERROR_FILE 1
#define PARSE_OK 0

namespace s21 {

class Model {
 private:
  size_t length = 512;

 public:
  Model() = default;
  ~Model() = default;

  typedef struct facets {
    int* vertices;
    int number_of_vertices;
  } polygon_t;

  typedef struct data {
    int amount_vertices;
    int amount_polygons;
  } data_t;

  int GetParseData(data_t* parse_data, char const* pathtofile);
  int GetVertices(FILE* fd, int amount_vertices, double** vertices);
  void GetPolygons(FILE* fd, int amount_polygons, polygon_t* polygons);
  int GetCountVertexPolygon(char* pt_str);

  double GetMaxVector(double* vertices, int amount_polygons);

  void translateX(int amount_vertices, double** vertices, double value);
  void translateY(int amount_vertices, double** vertices, double value);
  void translateZ(int amount_vertices, double** vertices, double value);

  void rotateX(int amount_vertices, double** vertices, double angle);
  void rotateY(int amount_vertices, double** vertices, double angle);
  void rotateZ(int amount_vertices, double** vertices, double angle);

  void ScaleShape(int amount_vertices, double** vertices, int scale);
  void DivideShape(int amount_vertices, double** vertices, int scale);

  enum class Error_e {
    SUCCESS = 1,
    VERTEX_MISS = -1,
    INCORRECT_MATRIX = -1,
    FAIL = -1
  };
};
}  // namespace s21

#endif  // CPP_3DVIEWER_V2_MODEL_H_
