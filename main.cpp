#include <iostream>
#include "Valec.h"
#include <limits>

int main() {
    float polomer, vyska, objemVody, naCmKrychlove;
    bool opakovani = true;
    int cislo;
    Valec v1;
    Valec v2(5.6, 5.2);
    Valec v3(v2);
    std::cout << "Objekt vytvoreny vychozim konstruktorem (polomer, vyska): " << v1 << std::endl;
    std::cout << "Objekt vytvoreny konstruktorem s parametry(polomer, vyska): " << v2 << std::endl;
    std::cout << "Objekt vytvoreny kopirovacim konstruktorem(polomer, vyska): " << v3 << std::endl;
    do {
        do {
            std::cout << "Zadej polomer v cm: " << std::endl;
            std::cin >> polomer;
            std::cout << "Zadej vysku v cm: " << std::endl;
            std::cin >> vyska;
            std::cout << "Zadej objem v decilitrech: " << std::endl;
            std::cin >> objemVody;
            if (!v1.setValec(polomer, vyska) || objemVody < 0 || std::cin.fail() || std::cin.peek() != '\n') {
                std::cout << "Nebyla zadana platna hodnota, zadej znovu" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (v1.getPolomer() < 0 || v1.getVyska() < 0 || objemVody < 0);
        naCmKrychlove = objemVody * 100;
        std::cout << "Polomer po zmene: " << v1.getPolomer() << std::endl;
        std::cout << "Vyska po zmene: " << v1.getVyska() << std::endl;
        std::cout << "Objem valce je " << v1.objemValce() << " cm krychlovych" << std::endl;
        std::cout << "Povrch valce je " << v1.povrchValce() << " cm ctverecnych" << std::endl;
        std::cout << "Obsah plaste je " << v1.obsahPlaste() << " cm ctverecnych" << std::endl;
        std::cout << "Obsah podstavy je " << v1.obsahPodstavy() << " cm ctverecnych" << std::endl;
        if (v1.objemValce() < naCmKrychlove) {
            std::cout << "Valec je prilis maly, voda se do neho nevejde" << std::endl;
        } else {
            std::cout << "Hladina vody je ve vysce " << v1.vyskaVody(naCmKrychlove) << std::endl;
        }
        std::cout << " " << std::endl;
        std::cout << "Zadej 1 pro opakovani programu" << std::endl;
        std::cin >> cislo;
        if (cislo != 1 ||  std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opakovani = false;
        }
    } while (opakovani);
    return 0;
}
