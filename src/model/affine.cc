#include "parser.h"

/// @brief move the shape in X
/// @param amount_vertices
/// @param vertices array vectors
/// @param value on what need move
void s21::Model::translateX(int amount_vertices, double** vertices,
                            double value) {
  int i = 0;
  int j = 0;
  while (i < amount_vertices) {
    (*vertices)[j] += value;
    j += 3;
    i++;
  }
}

/// @brief move the shape in Y
/// @param amount_vertices
/// @param vertices array vectors
/// @param value on what need move
void s21::Model::translateY(int amount_vertices, double** vertices,
                            double value) {
  int i = 0;
  int j = 1;
  while (i < amount_vertices) {
    (*vertices)[j] += value;
    j += 3;
    i++;
  }
}

/// @brief move the shape in Z
/// @param amount_vertices
/// @param vertices array vectors
/// @param value on what need move
void s21::Model::translateZ(int amount_vertices, double** vertices,
                            double value) {
  int i = 0;
  int j = 2;
  while (i < amount_vertices) {
    (*vertices)[j] += value;
    j += 3;
    i++;
  }
}

/// @brief rotate the shape around X
/// @param amount_vertices
/// @param vertices array vectors
/// @param angle how far to turn
void s21::Model::rotateX(int amount_vertices, double** vertices, double angle) {
  int i = 0;
  int xyz = 0;
  double rot = angle * M_PI / 180;
  while (i < amount_vertices) {
    double y_vector = (*vertices)[(i * 3) + 1];
    double z_vector = (*vertices)[(i * 3) + 2];

    while (xyz < 3) {
      if (xyz == 1) {  // y
        (*vertices)[(i * 3) + xyz] = y_vector * cos(rot) + z_vector * sin(rot);
      } else if (xyz == 2) {  // z
        (*vertices)[(i * 3) + xyz] = -y_vector * sin(rot) + z_vector * cos(rot);
      }
      xyz++;
    }
    xyz = 0;
    i++;
  }
}

/// @brief rotate the shape around Y
/// @param amount_vertices
/// @param vertices array vectors
/// @param angle how far to turn
void s21::Model::rotateY(int amount_vertices, double** vertices, double angle) {
  int i = 0;
  int xyz = 0;
  double rot = angle * M_PI / 180;
  while (i < amount_vertices) {
    double x_vector = (*vertices)[(i * 3)];
    double z_vector = (*vertices)[(i * 3) + 2];

    while (xyz < 3) {
      if (xyz == 0) {  // x
        (*vertices)[(i * 3) + xyz] = x_vector * cos(rot) + z_vector * sin(rot);
      } else if (xyz == 2) {  // z
        (*vertices)[(i * 3) + xyz] = -x_vector * sin(rot) + z_vector * cos(rot);
      }
      xyz++;
    }
    xyz = 0;
    i++;
  }
}

/// @brief rotate the shape around Z
/// @param amount_vertices
/// @param vertices array vectors
/// @param angle how far to turn
void s21::Model::rotateZ(int amount_vertices, double** vertices, double angle) {
  int i = 0;
  int xyz = 0;
  double rot = angle * M_PI / 180;
  while (i < amount_vertices) {
    double x_vector = (*vertices)[(i * 3)];
    double y_vector = (*vertices)[(i * 3) + 1];

    while (xyz < 3) {
      if (xyz == 0) {  // x
        (*vertices)[(i * 3) + xyz] = x_vector * cos(rot) - y_vector * sin(rot);
      } else if (xyz == 1) {  // y
        (*vertices)[(i * 3) + xyz] = x_vector * sin(rot) + y_vector * cos(rot);
      }
      xyz++;
    }
    xyz = 0;
    i++;
  }
}

/// @brief scaling shape vertices
/// @param amount_vertices
/// @param vertices
/// @param scale
void s21::Model::ScaleShape(int amount_vertices, double** vertices, int scale) {
  int i = 0;

  while (i < amount_vertices * 3) {
    (*vertices)[i] = (*vertices)[i] * scale / 10;
    i++;
  }
}

/// @brief scaling shape vertices
/// @param amount_vertices
/// @param vertices
/// @param scale
void s21::Model::DivideShape(int amount_vertices, double** vertices,
                             int scale) {
  int i = 0;

  while (i < amount_vertices * 3) {
    (*vertices)[i] = (*vertices)[i] / scale * 10;
    i++;
  }
}
