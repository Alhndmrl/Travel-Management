/*Alihan Demirel
*/

#include "surucu.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <locale>

#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

unsigned int dosyadanOku(const string &fileName, list<Arac *> araclar)
{

    setlocale(LC_ALL, "tr_TR.utf8"); // Turkish locale settings

    xml_document<> doc;
    xml_node<> *root_node;

    // Read the xml file into a vector
    ifstream theFile(fileName);

    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');

    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>(&buffer[0]);

    // Set the root node
    root_node = doc.first_node("Araclar");
    string agirlik1, hacim1, alici1, BinisNoktasi1, InisNoktasi1, yas1, ehlyt1, tur, InisNoktasi, yas2, ehlyt2;
    char *icerik1, *ozluSoz, *plaka, *ad1, *ad3, *BinisNoktasi2, *ad2;

    vector<Yuk> y1;
    list<Surucu> y;
    list<Surucu> y2;
    vector<Yolcu> d;
    EhliyetSinifi ehliyet1;
    EhliyetSinifi ehliyet2;

    // Iterate over the Vehicles

    unsigned int basarili_Donus = 0;

    for (auto *vehicle_node = root_node->first_node("Arac"); vehicle_node; vehicle_node = vehicle_node->next_sibling())
    {

        tur = vehicle_node->first_node("Turu")->value();
        plaka = vehicle_node->first_node("Plaka")->value();

        if (!strcmp(vehicle_node->first_node("Turu")->value(), "Kamyon"))
        {

            ozluSoz = vehicle_node->first_node("OzluSoz")->value();
        }
        auto *drivers_root_node = vehicle_node->first_node("Suruculer");

        if (!strcmp(vehicle_node->first_node("Turu")->value(), "Otobüs"))
        {
            for (auto *driver_node = drivers_root_node->first_node("Surucu"); driver_node; driver_node = driver_node->next_sibling())
            {

                ad1 = driver_node->first_node("Adi")->value();
                yas1 = driver_node->first_node("Yasi")->value();
                ehlyt1 = driver_node->first_node("EhliyetSinifi")->value();
                if (ehlyt1 == "B")
                {
                    ehliyet1 = EhliyetSinifi::B;
                }
                else if (ehlyt1 == "C")
                {
                    ehliyet1 = EhliyetSinifi::C;
                }
                else if (ehlyt1 == "D")
                {
                    ehliyet1 = EhliyetSinifi::D;
                }
                else if (ehlyt1 == "E")
                {
                    ehliyet1 = EhliyetSinifi::E;
                }
                Surucu x(ad1, stoi(yas1), ehliyet1);
                y.push_back(x);
            }
            auto *passengers_root_node = vehicle_node->first_node("Yolcular");

            for (auto *passenger_node = passengers_root_node->first_node("Yolcu"); passenger_node; passenger_node = passenger_node->next_sibling())
            {

                ad3 = passenger_node->first_node("Adi")->value();
                BinisNoktasi2 = passenger_node->first_node("BinisNoktasi")->value();
                InisNoktasi = passenger_node->first_node("InisNoktasi")->value();
                Yolcu c(ad3, BinisNoktasi2, InisNoktasi);
                

                
            }
            basarili_Donus++;
            Arac *p = new Otobus(plaka, y, d);

            araclar.push_back(p);
            d.clear();
            y.clear();
        }
        else if (!strcmp(vehicle_node->first_node("Turu")->value(), "Kamyon"))
        {
            for (auto *driver_node = drivers_root_node->first_node("Surucu"); driver_node; driver_node = driver_node->next_sibling())
            {

                ad2 = driver_node->first_node("Adi")->value();
                yas2 = driver_node->first_node("Yasi")->value();
                ehlyt2 = driver_node->first_node("EhliyetSinifi")->value();
                if (ehlyt2 == "B")
                {
                    ehliyet2 = EhliyetSinifi::B;
                }
                else if (ehlyt2 == "C")
                {
                    ehliyet2 = EhliyetSinifi::C;
                }
                else if (ehlyt2 == "D")
                {
                    ehliyet2 = EhliyetSinifi::D;
                }
                else if (ehlyt2 == "E")
                {
                    ehliyet2 = EhliyetSinifi::E;
                }
                Surucu p(ad2, stoi(yas2), ehliyet2);
                y2.push_back(p);
            }

            auto *loads_root_node = vehicle_node->first_node("Yukler");

            for (auto *load_node = loads_root_node->first_node("Yuk"); load_node; load_node = load_node->next_sibling())
            {

                icerik1 = load_node->first_node("Icerik")->value();
                agirlik1 = load_node->first_node("Agirlik")->value();
                hacim1 = load_node->first_node("Hacim")->value();
                alici1 = load_node->first_node("Alici")->value();
                BinisNoktasi1 = load_node->first_node("BinisNoktasi")->value();
                InisNoktasi1 = load_node->first_node("InisNoktasi")->value();
                

                Yuk x1(icerik1, stod(agirlik1), stod(hacim1), alici1, BinisNoktasi1, InisNoktasi1);

                y1.push_back(x1);
            }
            basarili_Donus++;

            Arac *p2 = new Kamyon(plaka, y2, ozluSoz, y1);
            araclar.push_back(p2);
            y2.clear();
            y1.clear();
        }
    }
    for (Arac *x : araclar)
    {
        cout << *x;
    }

    return basarili_Donus;
}

int main()
{
    
    unsigned int y = 0;
    list<Arac *> araclar1;

    y = dosyadanOku("bil122_hw08.xml", araclar1);

    cout << "Basarili Okunan Arac Sayisi :" << y << endl;
  
}