#include "parser.h"

/// @brief fill struct polygons
/// @param fd open file descriptor
/// @param amount_polygons
/// @param polygons vertecies what needs to connect
void s21::Model::GetPolygons(FILE* fd, int amount_polygons,
                             polygon_t* polygons) {
  int vertex = 0;
  Error_e flag = Error_e::SUCCESS;
  int first_vertex_polygon = 0;
  int i = 0;
  char* line = new char[SIZE_BUFFER];
  polygons->vertices = (int*)malloc(sizeof(int) * 1);
  char* pt_line = NULL;
  int vertex_in_facet = 0;
  int index_vertex = 1;

  polygons->number_of_vertices = 0;
  while (i < amount_polygons) {
    getline(&line, &length, fd);
    pt_line = line;
    if (line[0] == 'f' && line[1] == ' ') {
      vertex_in_facet = GetCountVertexPolygon(line);
      polygons->number_of_vertices += vertex_in_facet;
      if (polygons->number_of_vertices > 0)
        polygons->vertices = (int*)realloc(
            polygons->vertices, polygons->number_of_vertices * sizeof(int));
      while (*pt_line != 0) {
        if (*pt_line >= '0' && *pt_line <= '9') {
          polygons->vertices[vertex] = strtol(pt_line, &pt_line, 10) - 1;
          if (flag == Error_e::SUCCESS) {
            first_vertex_polygon = polygons->vertices[vertex];
            flag = Error_e::FAIL;
          } else if (index_vertex < vertex_in_facet) {
            polygons->vertices[vertex + 1] = polygons->vertices[vertex];
            index_vertex++;
            vertex++;
          }
          index_vertex++;
          vertex++;
          while (*pt_line != ' ' && *pt_line != '\0' && *pt_line != '\n') {
            pt_line++;
          }
        }
        pt_line++;
      }
      if (vertex_in_facet > 2) {
        polygons->vertices[vertex] = first_vertex_polygon;
        vertex++;
      }
      index_vertex = 1;
      flag = Error_e::SUCCESS;
      i++;
    }
  }
  delete[] line;
}

/// @brief fill array coordinates xyz
/// @param fd open file
/// @param amount_vertices
/// @param vertices array coordinates xyz
/// @return code errors
int s21::Model::GetVertices(FILE* fd, int amount_vertices, double** vertices) {
  Error_e code = Error_e::SUCCESS;
  char* line = new char[SIZE_BUFFER];
  (*vertices) = (double*)malloc(sizeof(double) * 1);
  char* pt_line = NULL;
  int size = 1;
  int i = 0;
  int j = 0;
  while (i < amount_vertices) {
    getline(&line, &length, fd);
    pt_line = line;
    if (line[0] == 'v' && line[1] == ' ') {
      int xyz = 0;
      size += 3;
      (*vertices) = (double*)realloc((*vertices), size * sizeof(double));
      while (xyz != 3 && *pt_line != '\n') {
        if ((*pt_line >= '0' && *pt_line <= '9') || *pt_line == '-') {
          (*vertices)[j] = strtod(pt_line, &pt_line);
          xyz++;
          j++;
        }
        pt_line++;
      }
      if (xyz != 3) {
        code = Error_e::FAIL;
      }
      i++;
    }
  }
  delete[] line;
  //  free(line);
  return static_cast<int>(code);
}

/// @brief return count vertices in one line obj file f 1 2 4 -> 12 24 41 = 6
/// symbols
/// @param pt_str line
/// @return
int s21::Model::GetCountVertexPolygon(char* pt_str) {
  int count = 0;
  while (*pt_str != 0 && *pt_str != '\n' && *pt_str != -1) {
    if (*pt_str >= '0' && *pt_str <= '9') {
      count++;
      while (*pt_str != ' ' && *pt_str != '\0') {
        pt_str++;
      }
      pt_str--;
    }
    pt_str++;
  }
  if (count > 2) {
    count *= 2;
  }
  return (count);
}

/// @brief open file and count vertices(v) and polygons(f)
/// @param parse_data struct count (v) and (f) in obj file
/// @param pathtofile path to file
int s21::Model::GetParseData(data_t* parse_data, const char* pathtofile) {
  FILE* fd;
  parse_data->amount_polygons = 0;
  parse_data->amount_vertices = 0;
  fd = fopen(pathtofile, "r");
  if (fd == NULL) {
    fprintf(stderr, "Error not have been file \n");
    return ERROR_FILE;
  }
  char* line = new char[SIZE_BUFFER];
  while (getline(&line, &length, fd) != -1) {
    if (line[0] == 'v' && line[1] == ' ') {
      parse_data->amount_vertices++;
    } else if (line[0] == 'f' && line[1] == ' ') {
      parse_data->amount_polygons++;
    }
  }
  free(line);
  fclose(fd);
  return PARSE_OK;
}

/// @brief find max vector in vertices
/// @param vertices
/// @param amount_polygons
/// @return
double s21::Model::GetMaxVector(double* vertices, int amount_polygons) {
  double max = 1;
  int i = 0;

  while (i < amount_polygons * 3) {
    if (fabs(max) < fabs(vertices[i])) {
      max = fabs(vertices[i]);
    }
    i++;
  }
  return (max);
}
