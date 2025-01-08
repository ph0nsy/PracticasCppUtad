// Practica01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#define MASK_BULLETS 0x00ff0000
#define MASK_NOBULLETS 0xff00ffff
unsigned int Num_Bullets(unsigned int _uCharacter) {
  unsigned int uBalas_ = (_uCharacter << 8) >> (32 - 8);
  // Alternativa >>> unsigned int iBalas_ = (_uCharacter & MASK_BULLETS) >> 16;
  return uBalas_;
}
void Add_Bullets(unsigned int* _uCharacter, unsigned int _uNewBullets) {
  unsigned int uNewAmmo = (Num_Bullets(*_uCharacter) + _uNewBullets);
  if(uNewAmmo <= 255u){
    uNewAmmo = uNewAmmo << 16;
    // Alternativa >>> unsigned int uNewAmmo = 16 << _uNewBullets;
    *_uCharacter = (*_uCharacter & MASK_NOBULLETS) | uNewAmmo;
    return;
  }
  else { return; }
}

bool Check_Status(unsigned int _uCharacter, short int iPosition) {
  bool check = _uCharacter & (1 << iPosition);
  return check;
}

void Update_Status(unsigned int* _uCharacter, short int iPosition) {
  // Alternativa >>> *_uCharacter |= BIT(iPosition) para solo cambiar la posición
  *_uCharacter = *_uCharacter ^ (1 << iPosition);

}
int main()
{
  // Vida -> 137 --HEX--> 89
  // Munición -> 13 --HEX--> 0D
  // Aliados -> 7 --HEX--> 07
  // Berseker --------> True  ↴
  // Escudo ----------> True  ↴
  // Balas infinitas -> False ↴
  // Invulnerable ----> False --> C
  unsigned int uInitialVal = 0x890D700C;
  unsigned int *uMiChar = &uInitialVal;
  printf("Municion: %u Balas\n", Num_Bullets(*uMiChar));
  Add_Bullets(uMiChar, 9);
  printf("Nueva Municion: %u Balas\n", Num_Bullets(*uMiChar));
  printf("Estado seleccionado (1) activado?: %s\n", Check_Status(*uMiChar, 1u) ? "true" : "false");
  Update_Status(uMiChar, 1u);
  printf("Estado seleccionado (1) activado?: %s\n", Check_Status(*uMiChar, 1u) ? "true" : "false");
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
