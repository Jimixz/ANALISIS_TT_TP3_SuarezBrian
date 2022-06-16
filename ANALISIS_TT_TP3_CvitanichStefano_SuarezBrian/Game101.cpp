#include <iostream>
#include <time.h>

using namespace std;

void main()
{
	int dado = 0;

	// "punJugadorXFinal" los utilizo para ir guardaando los puntos de ambos jugadores.
	int punJugadorDosFinal = 0;
	int punJugadorUnoFinal = 0;

	// "punAnotadoX" son los puntos que los jugadores van acumulando sin guardar.
	int punAnotadoUno = 0;
	int punAnotadoDos = 0;

	int limite = 0;
	int opcion = 0;
	int aux = 0;

	/*DEFINICION DE LAS BANDERAS*/
	// "seguir" lo uso para el primer while, me valida la condicion si ambos jugadores decidieron plantarse.
	bool seguir = true; 
	// "HabilitarOpcion" lo utilizo para mostrar o no las opciones que tienen los jugadores.
	bool HabilitarOpcion = true;
	// "EsJugadorUno" lo utilizo para pasar al otro jugador.
	bool EsJugadorUno = true;
	// "EsPlantarseUno" lo utilizo para cuando el jugador 1 decide plantarse.
	bool EsPlantarseUno = false;
	// "EsPlantarseDos" lo utilizo para cuando el jugador 1 decide plantarse.
	bool EsPlantarseDos = false;

	srand(time(NULL));

	cout << "INGRESE EL LIMITE PARA GUARDAR O PLANTARSE (25-80)" << endl;;

	do
	{
		cout << "SELECCION :";
		cin >> limite;
	} while (limite < 25 || limite > 80);

	// do
	// {
		while(seguir)
		{
			// Turnbo del jugador 1
			if (EsJugadorUno && !EsPlantarseUno)
			{				
				system("cls");
				HabilitarOpcion = true;

				dado = rand() % 6 + 1;
				dado = 101;

				cout << "JUGADOR 1, PUNTOS [" << punJugadorUnoFinal << "] TOTALES, PUNTOS [" << punAnotadoUno << "] ANOTADO" << endl;
				cout << "SE HAN LANZADO LOS DADOS..." << endl;
				cout << "DADOS : " << dado << endl;;

				// El aux me toma la tirada de la ronda anterior
				if (dado == 1 || aux == 1)
				{
					// Lo que interprete de las reglas es, que si el jugador saco 1 y anoto los punto, y luego en su proxima tirada saca 1 de nuevo, no se resetean los todos los puntos.
					if (dado == 1 && aux == 1)
					{
						system("cls");

						cout << "JUGADOR 1, TIRO LOS DADOS  Y SACO : [" << dado << "]" << endl;
						cout << "\nLOS PUNTOS ANOTADOS DEL JUGADOR 1, NO SE RESETEAN..." << endl;
						punAnotadoUno = 0;
						HabilitarOpcion = false;

						system("pause");
					}
					if (dado != 1 && aux == 1)
					{
						system("cls");

						cout << "JUGADOR 1, TIRO LOS DADOS  Y SACO : [" << dado << "]" << endl;
						cout << "\nLOS PUNTOS ANOTADOS DEL JUGADOR 1, SE RESETEAN..." << endl;
						punAnotadoUno = 0;
						HabilitarOpcion = false;

						system("pause");
					}

					// Si es el primer 1 que saca de los dados, se le mostrara estas opciones.
					if (HabilitarOpcion)
					{
						cout << "\nHAS SACADO [" << dado << "] EN LOS DADOS, TIENES DOS OPCIONES : \n1 - PLANTARSE\n2 - ANOTAR" << endl;

						do
						{
							cout << "SELECCION :";
							cin >> opcion;
						} while (opcion < 1 || opcion > 2);


						switch (opcion)
						{
						case 1:
							punJugadorUnoFinal += punAnotadoUno;
							punAnotadoUno = 0;
							EsPlantarseUno = true;
							EsJugadorUno = false;
							aux = 0;
							break;
						case 2:
							// En este caso no hace falta poner nada, por que los puntos ya se quedan anotados.
							break;
						}

						HabilitarOpcion = false;
					}				

				}
				else
				{
					cout << "\nDESEA UTILIZAR EL NUMERO COMO \n1 - UNIDAD [" << dado << "]\n2 - DECENA [" << (dado * 10) << "]" << endl;

					do
					{
						cout << "SELECCION :";
						cin >> opcion;
					} while (opcion < 1 || opcion > 2);

					// Lei por google que los numeros que da el dado, el jugador tiene la opcion de tomar la unidad como tal o en decena de esta forma lo aplique.
					if (opcion == 1)
					{
						punAnotadoUno += dado;
					}
					else
					{
						punAnotadoUno += (dado * 10);
					}
				}

				// Condiciones
				if ((punJugadorUnoFinal + punAnotadoUno) >= 90 && (punJugadorUnoFinal + punAnotadoUno) < 101 || (punJugadorUnoFinal + punAnotadoUno) > 101)
				{
					// Vuelvo a los puntos guardados, en el caso de que sume 100 y el ultimo numero no sea 1.
					if ((punJugadorUnoFinal + punAnotadoUno) == 100 && dado != 1)
					{
						punAnotadoUno = 0;					
					}

					// No reseteo los puntos si sumo 100 y en el ultimo tiro el dado es 1.		
					if ((punJugadorUnoFinal + punAnotadoUno) == 100 && dado == 1) 								
					{
						punAnotadoUno = 0;
						punJugadorUnoFinal = 0;
					}

					// Si supero los 101 reseteo los puntos anotados.
					if ((punJugadorUnoFinal + punAnotadoUno) > 101 || punAnotadoUno > 101)
					{
						punAnotadoUno = 0;
						HabilitarOpcion = false;
						EsJugadorUno = false;
						aux = 0;

						system("cls");
						cout << "EL JUGADOR 1 HA SUPERADO EL NUMERO 101, SUS PUNTOS ANOTADOS SERAN RESETEADOS...\n" << endl;
						system("pause");
					}
				}

				if (HabilitarOpcion)
				{
					system("cls");

					cout << "JUGADOR 1, PUNTOS [" << punJugadorUnoFinal << "] TOTALES, PUNTOS [" << punAnotadoUno << "] ANOTADO" << endl;
					cout << "SE HAN LANZADO LOS DADOS..." << endl;
					cout << "DADOS : " << dado << endl;

					if (punAnotadoUno >= limite || punJugadorUnoFinal >= limite)
					{
						cout << "\nOPCIONES DISPONIBLES, ANOTADO [" << punAnotadoUno << "] : \n1 - PLANTARSE\n2 - GUARDAR\n3 - SEGUIR" << endl;

						do
						{
							cout << "SELECCION :";
							cin >> opcion;
						} while (opcion < 1 || opcion > 3);

						switch (opcion)
						{
						case 1:
							punJugadorUnoFinal += punAnotadoUno;
							punAnotadoUno = 0;
							EsPlantarseUno = true;
							EsJugadorUno = false;
							aux = 0;
							break;
						case 2:
							// En caso de que el jugador guarde y sume 101 punto exactos
							if ((punJugadorUnoFinal + punAnotadoUno) == 101)
							{
								punJugadorUnoFinal += punAnotadoUno;

								system("cls");
								cout << "FELICIDADES JUGADOR 1, HAS LLEGADO AL NUMERO '101'...\n" << endl;

								seguir = false;
								aux = 0;

								system("pause");
							}
							else
							{
								punJugadorUnoFinal += punAnotadoUno;
								punAnotadoUno = 0;
								EsJugadorUno = false;
								aux = 0;
							}
							break;
						}

					}
				}

				// Si el jugador se planta no tomo el numero sacado en la ronda anterior
				if (!EsPlantarseUno)
				{
					aux = dado;
				}
				
			}

			// Turno del Jugador 2
			if (!EsJugadorUno && !EsPlantarseDos)
			{
				system("cls");
				HabilitarOpcion = true;

				dado = rand() % 6 + 1;

				cout << "JUGADOR 2, PUNTOS [" << punJugadorDosFinal << "] TOTALES, PUNTOS [" << punAnotadoDos << "] ANOTADO" << endl;
				cout << "SE HAN LANZADO LOS DADOS..." << endl;
				cout << "DADOS : " << dado << endl;

				// El aux  me toma la tirada de la ronda anterior
				if (dado == 1 || aux == 1)
				{
					// Lo que interprete de las reglas es, que si el jugador saco 1 y anoto los punto, y luego en su proxima tirada saca 1 de nuevo, no se resetean los todos los puntos.
					if (dado == 1 && aux == 1)
					{
						system("cls");

						cout << "JUGADOR 2, TIRO LOS DADOS  Y SACO : [" << dado << "]" << endl;
						cout << "\nLOS PUNTOS ANOTADOS DEL JUGADOR 1, NO SE RESETEAN..." << endl;
						punAnotadoDos = 0;
						HabilitarOpcion = false;

						system("pause");
					}
					if (dado != 1 && aux == 1)
					{
						system("cls");

						cout << "JUGADOR 2, TIRO LOS DADOS  Y SACO : [" << dado << "]" << endl;
						cout << "LOS PUNTOS ANOTADOS DEL JUGADOR 1, SE RESETEAN..." << endl;
						punAnotadoDos = 0;
						HabilitarOpcion = false;

						system("pause");
					}

					// Si es el primer 1 que saca de los dados, se le mostrara estas opciones.
					if (HabilitarOpcion)
					{
						cout << "\nHAS SACADO [" << dado << "] EN LOS DADOS, TIENES DOS OPCIONES : \n1 - PLANTARSE\n2 - ANOTAR" << endl;

						do
						{
							cout << "SELECCION :";
							cin >> opcion;
						} while (opcion < 1 || opcion > 2);


						switch (opcion)
						{
						case 1:
							punJugadorDosFinal += punAnotadoDos;
							punAnotadoDos = 0;
							EsPlantarseDos = true;
							EsJugadorUno = true;
							aux = 0;
							break;
						case 2:
							// En este caso no hace falta poner nada, por que los puntos ya se quedan anotados.
							break;
						}

						HabilitarOpcion = false;
					}

				}
				else
				{
					cout << "\nDESEA UTILIZAR EL NUMERO COMO \n1 - UNIDAD [" << dado << "]\n2 - DECENA [" << (dado * 10) << "]" << endl;

					do
					{
						cout << "SELECCION :";
						cin >> opcion;
					} while (opcion < 1 || opcion > 2);

					// Lei por google que los numeros sacados del dado, el jugador tiene la opcion de tomar la unidad como tal o en decena de esta forma lo aplique.
					if (opcion == 1)
					{
						punAnotadoDos += dado;
					}
					else
					{
						punAnotadoDos += (dado * 10);
					}
				}

				if ((punJugadorDosFinal + punAnotadoDos) >= 90 && (punJugadorDosFinal + punAnotadoDos) < 101 || (punJugadorDosFinal + punAnotadoDos) > 101)
				{
					// Vuelvo a los puntos guardados, en el caso de que sume 100 y el ultimo numero no sea 1.
					if ((punJugadorDosFinal + punAnotadoDos) == 100 && dado != 1)
					{
						punAnotadoDos = 0;
					}

					// No reseteo los puntos si sumo 100 y en el ultimo tiro el dado es 1.	
					if ((punJugadorDosFinal + punAnotadoDos) == 100 && dado == 1)
					{
						punAnotadoDos = 0;
						punJugadorDosFinal = 0;
					}

					// Si supero los 101 reseteo los puntos anotados.
					if ((punJugadorDosFinal + punAnotadoDos) > 101 || punAnotadoDos > 101)
					{
						punAnotadoDos = 0;
						HabilitarOpcion = false;
						EsJugadorUno = true;
						aux = 0;

						system("cls");
						cout << "EL JUGADOR 2 HA SUPERADO EL NUMERO 101, SUS PUNTOS ANOTADOS SERAN RESETEADOS...\n" << endl;
						system("pause");
					}
				}

				if (HabilitarOpcion)
				{
					system("cls");

					cout << "JUGADOR 2, PUNTOS [" << punJugadorDosFinal << "] TOTALES, PUNTOS [" << punAnotadoDos << "] ANOTADO" << endl;
					cout << "SE HAN LANZADO LOS DADOS..." << endl;
					cout << "DADOS : " << dado << endl;

					if (punAnotadoDos >= limite || punJugadorDosFinal >= limite)
					{
						cout << "\nOPCIONES DISPONIBLES, ANOTADO [" << punAnotadoUno << "] : \n1 - PLANTARSE\n2 - GUARDAR\n3 - SEGUIR" << endl;

						do
						{
							cout << "SELECCION :";
							cin >> opcion;
						} while (opcion < 1 || opcion > 3);

						switch (opcion)
						{
						case 1:
							punJugadorDosFinal += punAnotadoDos;
							punAnotadoDos = 0;
							EsJugadorUno = true;
							EsPlantarseDos = true;
							aux = 0;
							break;
						case 2:
							// En caso de que el jugador guarde y sume 101 punto exactos
							if ((punJugadorDosFinal + punAnotadoDos) == 101)
							{
								punJugadorDosFinal += punAnotadoDos;

								system("cls");
								cout << "FELICIDADES JUGADOR 2, HAS LLEGADO AL NUMERO '101'...\n" << endl;

								seguir = false;
								aux = 0;

								system("pause");
							}
							else
							{
								punJugadorDosFinal += punAnotadoDos;
								punAnotadoDos = 0;
								EsJugadorUno = true;
								aux = 0;
							}
							break;
						}

					}
				}

				// Si el jugador se planta no tomo el numero sacado en la ronda anterior
				if (!EsPlantarseDos)
				{
					aux = dado;
				}
				
			}

			// En el caso de que ambos jugadores se hayan plantado, el juego termina y muestra los resultados.
			if (EsPlantarseUno && EsPlantarseDos)
			{
				seguir = false;
			}
		}	

	// } while (punJugador <= 101);
	
	system("cls");

	cout << "EL JUGADOR 1, PUNTOS [" << punJugadorUnoFinal << "]" << endl;
	cout << "EL JUGADOR 2, PUNTOS [" << punJugadorDosFinal << "]" << endl;

	// En el caso que ambos decidan retirarse y de la casualidad de que tengan los mismo puntos.
	if (punJugadorUnoFinal == punJugadorDosFinal)
	{
		cout << "\nAMBOS JUGADORES HAN CONSEGUIDO LOS MISMO PUNTO, EMPATE... FIN DEL JUEGO." << endl;
	}
	else
	{
		if (punJugadorUnoFinal > punJugadorDosFinal)
		{
			cout << "\nEL JUGADOR NUMERO 1 HA GANADOM FELICIDADES !!!... FIN DEL JUEGO." << endl;
		}
		else
		{
			cout << "\nEL JUGADOR NUMERO 2 HA GANADOM FELICIDADES !!!... FIN DEL JUEGO." << endl;
		}
	}

	system("pause");
}