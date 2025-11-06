#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string> 

using namespace std;

int main() {

    int combustible = 30;
    int oxigeno = 50;
    int suministro = 40;
    float salud = 100.0;
    int dia = 1;
    bool supervivencia = true;
    char opcion;
    string capitan; 

    // Prepara los numeros aleatorios
    srand(time(0));

    cout << "Registro de Capitan: Por favor introduce su nombre: ";
    getline(cin, capitan); 
    cout << endl;

    cout << "¡Hola Capitan " << capitan << ", Bienvenido al juego de la nave espacial!" << endl;
    cout << "Tu eres el capitan " << capitan << " y tienes que llegar a tu destino en 10 dias." << endl;
    cout << "Debes cuidar el combustible, oxigeno, suministros y la salud de la nave." << endl;
    cout << "Empezemos!..." << endl << endl;

    // Ciclo principal del juego dura 10 dias o hasta que perdamos
    while (supervivencia && dia <= 10) {

        cout << "=== Dia " << dia << " ===" << endl;
        cout << "Combustible: " << combustible << " unidades" << endl;
        cout << "Oxigeno: " << oxigeno << " unidades" << endl;
        cout << "Suministros: " << suministro << " unidades" << endl;
        cout << "Integridad de la nave: " << fixed << setprecision(1) << salud << "%" << endl << endl;

        // Revisa si perdimos al empezar el dia
        if (oxigeno <= 0 || combustible <= 0 || salud <= 0.0 || suministro <= 0) {
            cout << "Oh no Te quedaste sin recursos. El juego termino :(" << endl;
            supervivencia = false;
            break;
        }

        cout << "Elige que hacer hoy, Capitan " << capitan << ":" << endl; 
        cout << "1. Explorar un planeta cercano" << endl;
        cout << "2. Reparar la nave" << endl;
        cout << "3. Enviar senales" << endl;
        cout << "4. Rendirme" << endl;
        cout << "Escribe el numero de tu opcion: ";

        cin >> opcion;
        cout << endl;

        // Opcion 1: Explorar
        if (opcion == '1') {
            
            // Revisa si tenemos combustible para la accion
            if (combustible < 15) {
                cout << "No tienes suficiente combustible para explorar." << endl;
                continue;
            }

            combustible -= 15;
            cout << "Vas a explorar un planeta. Gastaste 15 de combustible." << endl;

            // Numero aleatorio para decidir que encontramos
            int numeroalea = rand() % 100;

            if (numeroalea < 60) {
                int oxigeno2 = rand() % 21 + 20;
                oxigeno += oxigeno2;
                cout << "¡Genial! Encontraste oxigeno. Ganaste " << oxigeno2 << " unidades." << endl;

            } else if (numeroalea < 85) { 
                int combustible2 = rand() % 21 + 10;
                combustible += combustible2;
                cout << "¡Que suerte! Encontraste combustible. Ganaste " << combustible2 << " unidades." << endl;

            } else if (numeroalea < 95) { 
                int suministros2 = rand() % 71 + 30;
                suministro += suministros2;
                cout << "¡Excelente! Encontraste suministros. Ganaste " << suministros2 << " unidades." << endl;

            } else if (numeroalea < 97) {
                float danorec = rand() % 11 + 10;
                salud -= danorec;
                cout << "¡Cuidado! Hubo una tormenta electrica. Perdiste " << danorec << "% de integridad." << endl;

            } else {
                float danorec = rand() % 11 + 10;
                salud -= danorec;
                cout << "¡Oh no! Aterrizaje forzado. Perdiste " << danorec << "% de integridad." << endl;
            }
        
        // Opcion 2: Reparar
        } else if (opcion == '2') {
            cout << "¿Cuantos porcentajes quieres reparar? (Cada porcentaje cuesta 10 de suministros): ";
            int puntosrep;
            cin >> puntosrep;
            
            if (puntosrep == 0) {
                cout << "No se realizaron reparaciones." << endl;
                continue;
            }

            // Calcula el costo
            int costorep = puntosrep * 10;
            
            // Revisa si podemos pagarlo
            if (costorep > suministro) {
                cout << "No tienes suficientes suministros. No puedes reparar tanto." << endl;
            } else {
                suministro -= costorep;
                salud += puntosrep;
                if (salud > 100.0) {
                    salud = 100.0;
                }
                cout << "Reparaste la nave en " << puntosrep << "%. Gastaste " << costorep << " de suministros" << endl;
            }

        // Opcion 3: Enviar señales
        } else if (opcion == '3') {
            int senal = rand() % 2; 
            if (senal == 0) {
                combustible += 60;
                cout << "¡Ayuda! Llego combustible. Ganaste 60 unidades!" << endl;
            } else {
                salud -= 15;
                suministro -= 20;
                cout << "¡Piratas Perdiste 15% de integridad y 20 de suministros!" << endl;
            }

        // Opcion 4: Rendirse
        } else if (opcion == '4') {
            cout << "Te has rendido el viaje termino" << endl;
            supervivencia = false;

        } else {
            cout << "Esa opcion no es valida intenta de nuevo" << endl;
            continue;
        }
         if (!supervivencia) {
            break;
        }

        oxigeno -= 20;
        suministro -= 30;
        cout << "Es de noche gastaste 20 de oxigeno y 30 de suministros" << endl;

        // Probabilidades de los eventos nocturnos
        if (rand() % 100 < 15) { // 15% de chance
            
            int eventonoche = rand() % 3; 
            
            if (eventonoche == 0) {
                oxigeno -= 10;
                cout << "¡Tormenta cosmica perdiste 10 de oxigeno!" << endl;
            
            } else if (eventonoche == 1) {
                int alien = rand() % 2; 
                if (alien == 0) {
                    combustible += 20;
                    cout << "¡Alienigenas amistosos ganaste 20 de combustible!" << endl;
                } else {
                    salud -= 10;
                    cout << "¡Alienigenas hostils perdiste 10% de integridad!" << endl;
                }

            } else {
                cout << "¡Meteoritos ¿Quieres maniobrar o vas a dejar que te golpeen?" << endl;
                cout << "1. Maniobrar" << endl;
                cout << "2. Recibir golpe" << endl;
                char meteorito;
                cin >> meteorito;

                if (meteorito == '1') {
                    int maniobra = rand() % 21 + 10;
                    
                    // Revisa si tenemos combustible para maniobrar
                    if (combustible < maniobra) {
                        cout << "¡No tenias suficiente combustible para maniobrar!" << endl;
                        float danorec = rand() % 11 + 15;
                        salud -= danorec;
                        cout << "Recibiste el golpe de todos modos perdiste " << danorec << "% de integridad" << endl;
                    } else {
                        combustible -= maniobra;
                        cout << "Maniobraste bien gastaste " << maniobra << " de combustible" << endl;
                    }
                } else {
                    float danorec = rand() % 11 + 15;
                    salud -= danorec;
                    cout << "Recibiste el golpe perdiste " << danorec << "% de integridad" << endl;
                }
            }
        }

        cout << "Fin del dia " << dia << " tus recursos ahora son:" << endl;
        cout << "Combustible: " << combustible << " unidades" << endl;
        cout << "Oxigeno: " << oxigeno << " unidades" << endl;
        cout << "Suministros: " << suministro << " unidades" << endl;
        cout << "Integridad de la nave: " << fixed << setprecision(1) << salud << "%" << endl << endl;

        // Revisa si perdimos durante la noche
        if (oxigeno <= 0 || combustible <= 0 || salud <= 0.0 || suministro <= 0) {
            cout << "Has sucumbido a los peligros del espacio durante la noche el juego termino" << endl;
            supervivencia = false;
        }

        dia++; // Pasa al siguiente dia
    }

    
    if (dia > 10 && supervivencia) {
        cout << "¡Felicidades Capitan " << capitan << "! tu y tu tripulacion lograron luchar contra las adversidades del espacio, llegaste a tu destino despues de 10 dias disfruta tu descanso " << endl;
    
    } else if (oxigeno <= 0 || combustible <= 0 || salud <= 0.0 || suministro <= 0) {
        cout << "Tu viaje termino Capitan " << capitan << ", fuiste un gran capitan!...Mejor suerte la proxima vez" << endl;
    
    }

    return 0;
}