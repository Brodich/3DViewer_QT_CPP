#ifndef CPP_3DVIEWER_V2_CONTROLLER_H_
#define CPP_3DVIEWER_V2_CONTROLLER_H_

#include "../model/parser.h"

namespace s21 {
class Controller {
 private:
  s21::Model* pt_business_log = nullptr;
  s21::Model::data_t parse_data = {0};
  s21::Model::polygon_t polygons = {0};

 public:
  Controller(s21::Model* business_logic) : pt_business_log(business_logic) {}
  ~Controller() { pt_business_log = nullptr; }

  void GetPolygons(FILE* fd, int amount_polygons, Model::polygon_t* polygons) {
    pt_business_log->GetPolygons(fd, amount_polygons, polygons);
  }
  int GetVertices(FILE* fd, int amount_vertices, double** vertices) {
    return pt_business_log->GetVertices(fd, amount_vertices, vertices);
  }
  int GetCountVertexPolygon(char* pt_str) {
    return pt_business_log->GetCountVertexPolygon(pt_str);
  }
  int GetParseData(Model::data_t* parse_data, const char* pathtofile) {
    return pt_business_log->GetParseData(parse_data, pathtofile);
  }
  double GetMaxVector(double* vertices, int amount_polygons) {
    return pt_business_log->GetMaxVector(vertices, amount_polygons);
  }
};
}  // namespace s21

#endif  // CPP_3DVIEWER_V2_CONTROLLER_H_
