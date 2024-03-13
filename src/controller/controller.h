#ifndef CONTROLLER
#define CONTROLLER

#include "../model/parser.h"

namespace s21 {
class Controller {
 private:
  s21::Model* pt_business_log = nullptr;

 public:
  Controller(s21::Model* business_logic) : pt_business_log(business_logic) {}
  ~Controller() { pt_business_log = nullptr; }

  void GetPolygons(FILE* fd, int amount_polygons, Model::polygon_t* polygons);
  int GetVertices(FILE* fd, int amount_vertices, double** vertices);
  int GetCountVertexPolygon(char* pt_str);
  int GetParseData(Model::data_t* parse_data, const char* pathtofile);

};
}  // namespace s21

#endif
