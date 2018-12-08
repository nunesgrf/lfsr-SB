#include <cmath>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <vector>
#include <iomanip>

#define MAX_COUNTER 65535
#define SIZE        64
#define CORINTHIANS 1024
#define SEED        0xAB

double g_acm = 0;
std::vector<int> g_classes(SIZE,0);
std::vector<double> g_chiQuad(SIZE,0.0);

void results() {

    for(unsigned i = 0; i < g_classes.size(); i++) {
        std::cout << "Índice: " << std::setw(2) << std::setfill('0') << i << " | Tamanho da classe: " << g_classes.at(i) << " | Valor Chi: " << g_chiQuad.at(i) << std::endl; 
    }
    std::cout << std::endl << "Valor de Chi Quadrado : " << (double)g_acm << std::endl;

}

void frequencies() {
    for(unsigned i = 0; i < g_classes.size(); i++) {
        auto result     = (pow((g_classes.at(i)-CORINTHIANS),2))/CORINTHIANS;
        g_chiQuad.at(i) = result;
        g_acm          += result;
    }
}

void splitClasses(uint32_t n) {
    g_classes.at((n/CORINTHIANS))++;
}

void lfshift() {

    uint16_t bit;
    uint16_t lfsr = SEED;
    unsigned long counter = 0;
    do {
        bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ^ (lfsr >> 8) ^(lfsr >> 13) ^(lfsr >> 15)) & 1;
        lfsr =  (lfsr >> 1) | (bit << 15);
        counter++;

        splitClasses(lfsr);
    } while(counter < MAX_COUNTER);
}

int main() {

    lfshift();
    frequencies();
    
    results();    
}