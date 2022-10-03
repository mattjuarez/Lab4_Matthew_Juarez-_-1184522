#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>
#include<stdlib.h> 

using namespace System;

void carrera(int* cuadroT, int* cuadroL) {
	int num = 1;

	while ((*cuadroT < 70) && (*cuadroL < 70)) {
		int vT = rand() % 10 + 1, vL = rand() % 10 + 1;
		Console::WriteLine("Pulso de reloj " + num);

		if (vT >= 1 && vT <= 5) {
			Console::WriteLine("La tortuga va un paso veloz! Avanza 3 cuadros a la derecha");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			*cuadroT += 3;
			Console::WriteLine("Ahora la tortuga va en el cuadro " + *cuadroT);

		}
		else if (vT == 6 || vT == 7) {
			Console::WriteLine("La tortuga ha tenido un resbalón! Retrocede 6 cuadros");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			*cuadroT -= 6;
			if (*cuadroT < 1) {
				*cuadroT = 1;
			}
			Console::WriteLine("Ahora la tortuga va en el cuadro " + *cuadroT);

		}
		else if (vT >= 8 && vT <= 10) {
			Console::WriteLine("La tortuga va a un paso lento! Avanza 1 cuadro a la derecha");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			*cuadroT += 1;
			Console::WriteLine("Ahora la tortuga va en el cuadro " + *cuadroT);

		}

		if (vL == 1 || vL == 2) {
			Console::WriteLine("La liebre duerme ZZZ... No se mueve");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			Console::WriteLine("La liebre sigue en el cuadro " + *cuadroL);
		}
		else if (vL == 3 || vL == 4) {
			Console::WriteLine("La liebre da un gran salto! Avanza 9 cuadros a la derecha");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			*cuadroL += 9;
			Console::WriteLine("Ahora la liebre va en el cuadro " + *cuadroL);
		}
		else if (vL == 5) {
			Console::WriteLine("La liebre ha tenido un gran resbalon! Retrocede 12 cuadros");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			*cuadroL -= 12;
			if (*cuadroL < 1) {
				*cuadroL = 1;
			}
			Console::WriteLine("Ahora la liebre va en el cuadro " + *cuadroL);
		}
		else if (vL >= 6 && vL <= 8) {
			Console::WriteLine("La liebre da un salto pequeño! Avanza 1 cuadro a la derecha");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			*cuadroL += 1;
			Console::WriteLine("Ahora la liebre va en el cuadro " + *cuadroL);
		}
		else if (vL == 9 || vL == 10) {
			Console::WriteLine("La liebre ha tenido un resbalon pequeño! Retrocede 2 cuadros");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			*cuadroL -= 2;
			if (*cuadroL < 1) {
				*cuadroL = 1;
			}
			Console::WriteLine("Ahora la liebre va en el cuadro " + *cuadroL);
		}

		if (*cuadroT == *cuadroL) {
			if (*cuadroT != 1 && *cuadroL != 1) {
				Console::WriteLine("¡OUCH!");
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
		}
		num++;
		Console::WriteLine("\n");
	}
	if (*cuadroT == *cuadroL) {
		Console::WriteLine("Fin de la carrera. Es un empate!");
	}
	else if (*cuadroT >= 70) {
		Console::WriteLine("LA TORTUGA GANA! ¡BRAVO!");
	}
	else if (*cuadroL >= 70) {
		Console::WriteLine("La liebra gana! Ni hablar");
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Console::ReadKey();
}

int main(array<System::String^>^ args) {
	system("color 1F");
	Console::WriteLine("¡BANG!");
	Console::WriteLine("¡Y ARRANCAN!");
	int cuadroT, cuadroL;
	int* apCuadroT = &cuadroT;
	int* apCuadroL = &cuadroL;
	*apCuadroT = 1, * apCuadroL = 1;
	carrera(apCuadroT, apCuadroL);
}