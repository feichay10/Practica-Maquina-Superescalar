#include <iostream>
#include <vector>

int main(void) {
  int tam = 16;
  int aux;
  std::vector<int> vector(tam);

  // Posiciones de la memoria
  vector[0] = 15;   // 40
  vector[1] = 10;   // 41
  vector[2] = 16;   // 42
  vector[3] = 6;    // 43
  vector[4] = 3;    // 44
  vector[5] = 12;   // 45
  vector[6] = 4;    // 46
  vector[7] = 14;   // 47
  vector[8] = 8;    // 48
  vector[9] = 9;    // 49
  vector[10] = 1;   // 50
  vector[11] = 7;   // 51
  vector[12] = 2;   // 52
  vector[13] = 5;   // 53
  vector[14] = 11;  // 54
  vector[15] = 13;  // 55

  // Imprime el vector sin ordenar
  for (int i = 0; i < vector.size(); i++) {
    std::cout << vector[i] << " | ";
  }
  std::cout << "\n";

  for (int i = 0; i < vector.size(); i++) {  // recorre el vector
    std::cout << "##########i -> " << i << "\n";
    for (int j = 0; j < (vector.size() - i); j++) {  // coge cada elemento del vector
      if (vector[j] > vector[j + 1]) {
        aux = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = aux;
        //std::cout << "swap -> " << vector[j] << std::endl;
      }
      std::cout << "2 for -> " << vector[j] << std::endl;
    }
  }

  // Imprime el vector ordenado
  for (int i = 1; i <= vector.size(); i++) {
    std::cout << vector[i] << " | ";
  }
  std::cout << "\n";
}