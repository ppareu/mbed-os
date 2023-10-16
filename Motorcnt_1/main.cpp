#include "mbed.h"

// définition des pins:  sorties numériques et sorties pwm

DigitalOut moteur1a(D3); // Marche avant du premier moteur
DigitalOut moteur1b(D4); // Marche arrière du premier moteur
DigitalOut moteur2a(D5); // Marche avant du deuxième moteur
DigitalOut moteur2b(D6); // Marche arrière du deuxième moteur

PwmOut pwm1(D9);   // vitesse du premier moteur
PwmOut pwm2(D10);  // vitesse du deuxième moteur

int main() {
   
    while(1) {  // en boucle jusqu'à la fin de notre civilisation
    
    // on commence par le premier moteur seulement, en marche avant, vitesse lente (10%)
    
    pwm1.write(0.10f);  
    moteur1a = 1;
    moteur1b = 0;
    moteur2a = 0;
    moteur2b = 0;  
    ThisThread::sleep_for(3000);  // on ne change rien pendant 3 secondes
       
    // maintenant, pleine vitesse
    
    pwm1.write(1.00f);
    ThisThread::sleep_for(3000);  // on ne change rien pendant 3 secondes
    
    // on arrête tout 
     
    moteur1a = 0;
    ThisThread::sleep_for(3000);  // on ne change rien pendant 3 secondes
       
    // moteur 1 en marche inverse, vitesse moyenne (30%)
    pwm1.write(0.30f);   
    moteur1a = 0;
    moteur1b = 1;   
    ThisThread::sleep_for(3000);  // on ne change rien pendant 3 secondes
    
    // on ajoute le moteur 2:  marche avant, 50%

    pwm2.write(0.50f);  
    moteur2a = 0;
    moteur2b = 1;  
    ThisThread::sleep_for(3000);  // on ne change rien pendant 3 secondes
    
    // on arrête le moteur 1;  moteur 2:  vitesse lente en marche arrière
    pwm2.write(0.200f);   
    moteur1a = 0;
    moteur1b = 0;  
    moteur2a = 1;
    moteur2b = 0;
    ThisThread::sleep_for(3000);  // on ne change rien pendant 3 secondes
    
    // on arrête tout
    moteur2a = 0;
    ThisThread::sleep_for(3000);  // on ne change rien pendant 3 secondes
    
    }
}