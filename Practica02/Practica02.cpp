// Practica02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

char *ObtenerBytes_fromInt(unsigned int _iOrigen) {
  char* pInicioCadena_ = reinterpret_cast<char*>(&_iOrigen);
  return pInicioCadena_;
}

unsigned int *ObtenerMayor_fromIntTable(unsigned int* iElementoInicial, const int size) {
  unsigned int* mayor = iElementoInicial;
  for (int i = 1; i < size; i++) {
    unsigned int* actual = (iElementoInicial + i);
    if (*actual > *mayor) {
      mayor = actual;
    }
  }
  return mayor;
}

unsigned char* ObtenerByteMayor_fromTable(unsigned char* iElementoInicial, const int size) {
  unsigned char* mayor = iElementoInicial;
  for (int i = 1; i < size; i++) {
    unsigned char* actual = (iElementoInicial + i);
    if (*actual > *mayor) {
      mayor = actual;
    }
  }
  return mayor;
}

int main()
{
  /*
  char aMiArray[] = "Hola";

  for (char iElemento : aMiArray)
  {
    printf("%c", iElemento);
  }

  printf("\n");

  for (int i = 0; i < sizeof(aMiArray) / sizeof(char); i++)
  {
    printf("%c", aMiArray[i]);
  }

  printf("\n");

  for (int i = 0; i < strlen(aMiArray); i++) // Cada iteración tiene que recorrer la cadena al completo pq strlen lo que hace es iterar hasta encontrar un 0
  {
    printf("%c", aMiArray[i]);
  }

  printf("\n");

  printf("%s\n", aMiArray);

  int iIndex = 0;
  while (aMiArray[iIndex] != '\0') {
    printf("%c", aMiArray[iIndex]);
    iIndex++;
  }

  printf("\n");

  iIndex = 0;
  while (true) {
    printf("%c", aMiArray[iIndex]);
    iIndex++;
    if (aMiArray[iIndex] == '\0') { break; }
  }

  printf("\n");

  char* pMiArray = &aMiArray[0];
  iIndex = 0;
  while (true) {
    printf("%c", *(pMiArray + iIndex));
    iIndex++;
    if (*(pMiArray + iIndex) == '\0') { break; }
  }

  printf("\n");
*/
  // Punto 1
  const unsigned int iInitialNumber = 0x89abcdef;
  char aEsperados01[4] = { 0xef, 0xcd, 0xab, 0x89 };

  char* pCadenaChar = ObtenerBytes_fromInt(iInitialNumber);

  for (unsigned int i = 0; i < sizeof(int) / sizeof(char); i++) {
    printf("Elemento %d como caracter: %c\n", i + 1, *(pCadenaChar + i));
    printf("Elemento %d esperado: %c\n", i + 1, aEsperados01[i]);
  }

  // Punto 2
  unsigned int uTabla[] = {1,3,2,5,3,0xFFFFFFFF,2};
  unsigned int* uResultadoMayor = ObtenerMayor_fromIntTable(&uTabla[0], sizeof(uTabla) / sizeof(int));
  printf("El mayor es 0x%x que se encuentra en 0x%x\n", *uResultadoMayor, &uResultadoMayor);

  // Punto 3
  unsigned char* uResultadoMayorByte = ObtenerByteMayor_fromTable(reinterpret_cast<unsigned char*>(&uTabla[0]), sizeof(uTabla) / sizeof(char));
  printf("El mayor es 0x%x que se encuentra en 0x%x\n", *uResultadoMayorByte, &uResultadoMayorByte);
  
  // Punto 4 - Invertir cadena
  unsigned char cCadena[] = { 'a', 'b', 'c', 'd' };
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
