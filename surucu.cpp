/*Alihan Demirel
*/

#include <iostream>
using namespace std;
#include <list>
#include "surucu.h"
using std::iterator;
using std::list;

Surucu::Surucu()
{
    ad = nullptr;
    yas.age = 0;
}
Surucu::Surucu(char *ad, unsigned int yas1, EhliyetSinifi &ehliyet)
{
    setter_name(ad);
    yas.age = yas1 - 30;
    setter_ehliyet(ehliyet);
}
Surucu::~Surucu()
{
    if (ad != nullptr)
    {
        delete[] ad;
    }
}
Surucu::Surucu(const Surucu &other)
{
    setter_name(other.ad);
    setter_age(other.yas.age);
    Ehliyet = other.Ehliyet;
}
const Surucu &Surucu::operator=(const Surucu &other)
{
    if (this == &other)
    {
        return *this;
    }
    setter_name(other.ad);
    setter_age(other.yas.age);
    Ehliyet = other.Ehliyet;

    return *this;
}
char *Surucu::getter_name() const
{
    return ad;
}
void Surucu::setter_name(char *name)
{
    if (ad != nullptr)
    {
        delete[] ad;
    }
    ad = nullptr;
    try
    {
        ad = new char[uzunluk(name) + 1];
    }
    catch (bad_alloc &b)
    {
        std::cerr << "bad_alloc caught: " << b.what() << endl;
    }

    ad = new char[uzunluk(name) + 1];
    for (unsigned int i = 0; i < uzunluk(name); i++)
    {
        ad[i] = name[i];
    }
    ad[uzunluk(name)] = '\0';
}
unsigned int Surucu::getter_age() const
{
    return yas.age;
}
void Surucu::setter_age(unsigned int age)
{

    yas.age = age;
}
EhliyetSinifi Surucu::getter_ehliyet() const
{
    return Ehliyet;
}
void Surucu::setter_ehliyet(EhliyetSinifi &ehliyet)
{
    Ehliyet = ehliyet;
}
unsigned Surucu::uzunluk(char *str) const
{
    unsigned int length = 0;

    while (*str++ != '\0')
    {
        ++length;
    }
    return length;
}
Yolcu::Yolcu()
{
    ad = nullptr;
    BinisNoktasi = nullptr;
    InisNoktasi = "";
}
Yolcu::Yolcu(char *ad, char *BinisNoktasi, string InisNoktasi)
{
    setter_name(ad);
    setter_BinisNoktasi(BinisNoktasi);
    setter_InisNoktasi(InisNoktasi);
}
Yolcu::~Yolcu()
{
    if (ad != nullptr)
    {
        delete[] ad;
    }
    if (BinisNoktasi != nullptr)
    {
        delete[] BinisNoktasi;
    }
}
Yolcu::Yolcu(const Yolcu &other)
{
    setter_name(other.ad);
    setter_BinisNoktasi(other.BinisNoktasi);
    setter_InisNoktasi(other.InisNoktasi);
}
const Yolcu &Yolcu::operator=(const Yolcu &other)
{
    if (this == &other)
    {
        return *this;
    }
    setter_name(other.ad);
    setter_BinisNoktasi(other.BinisNoktasi);
    setter_InisNoktasi(other.InisNoktasi);

    return *this;
}
char *Yolcu::getter_name() const
{
    return ad;
}
void Yolcu::setter_name(char *name)
{
    if (ad != nullptr)
    {
        delete[] ad;
    }
    ad = nullptr;
    try
    {
        ad = new char[uzunluk(name) + 1];
    }
    catch (bad_alloc &b)
    {
        std::cerr << "bad_alloc caught: " << b.what() << endl;
    }

    for (unsigned int i = 0; i < uzunluk(name); i++)
    {
        ad[i] = name[i];
    }
    ad[uzunluk(name)] = '\0';
}
char *Yolcu::getter_BinisNoktasi() const
{
    return BinisNoktasi;
}
void Yolcu::setter_BinisNoktasi(char *x)
{
    if (BinisNoktasi != nullptr)
    {
        delete[] BinisNoktasi;
    }
    BinisNoktasi = nullptr;
    try
    {
        BinisNoktasi = new char[uzunluk(x) + 1];
    }
    catch (bad_alloc &b)
    {
        std::cerr << "bad_alloc caught: " << b.what() << endl;
    }

    BinisNoktasi = new char[uzunluk(x) + 1];
    for (unsigned int i = 0; i < uzunluk(x) + 1; i++)
    {
        BinisNoktasi[i] = x[i];
    }
    BinisNoktasi[uzunluk(x)] = '\0';
}
string Yolcu::getter_InisNoktasi() const
{
    return InisNoktasi;
}
void Yolcu::setter_InisNoktasi(string y)
{
    InisNoktasi = y;
}
unsigned Yolcu::uzunluk(char *str) const
{
    unsigned int length = 0;

    while (*str++ != '\0')
    {
        ++length;
    }
    return length;
}
Yuk::Yuk()
{
    icerik = nullptr;
    agirlik = 0;
    hacim = 0;
    alici = "";
    BinisNoktasi = "";
    InisNoktasi = "";
}
Yuk::Yuk(char *icerik, double agirlik, double hacim, string alici, string binis, string inis)
{
    setter_icerik(icerik);
    setter_agirlik(agirlik);
    setter_hacim(hacim);
    setter_alici(alici);
    setter_binis(binis);
    setter_inis(inis);
}
Yuk::~Yuk()
{
    if (icerik != nullptr)
    {
        delete[] icerik;
    }
}
Yuk::Yuk(const Yuk &other)
{
    setter_icerik(other.icerik);
    setter_agirlik(other.agirlik);
    setter_hacim(other.hacim);
    setter_alici(other.alici);
    setter_binis(other.BinisNoktasi);
    setter_inis(other.InisNoktasi);
}
Yuk &Yuk::operator=(const Yuk &other)
{
    if (this == &other)
    {
        return *this;
    }
    setter_icerik(other.icerik);
    setter_agirlik(other.agirlik);
    setter_hacim(other.hacim);
    setter_alici(other.alici);
    setter_binis(other.BinisNoktasi);
    setter_inis(other.InisNoktasi);
    return *this;
}
char *Yuk::getter_icerik() const
{
    return icerik;
}
void Yuk::setter_icerik(char *icerik1)
{
    if (icerik != nullptr)
    {
        delete[] icerik;
    }
    try
    {
        icerik = new char[uzunluk(icerik1) + 1];
    }
    catch (bad_alloc &b)
    {
        std::cerr << "bad_alloc caught: " << b.what() << endl;
    }

    for (unsigned int i = 0; i < uzunluk(icerik1); i++)
    {
        icerik[i] = icerik1[i];
    }
    icerik[uzunluk(icerik1)] = '\0';
}
double Yuk::getter_agirlik() const
{
    return agirlik;
}
void Yuk::setter_agirlik(double weight)
{
    agirlik = weight;
}
double Yuk::getter_hacim() const
{
    return hacim;
}
void Yuk::setter_hacim(double volume)
{
    hacim = volume;
}
string Yuk::getter_alici() const
{
    return alici;
}
void Yuk::setter_alici(string x)
{
    alici = x;
}
string Yuk::getter_binis() const
{
    return BinisNoktasi;
}
void Yuk::setter_binis(string y)
{
    BinisNoktasi = y;
}
string Yuk::getter_inis() const
{
    return InisNoktasi;
}
void Yuk::setter_inis(string z)
{
    InisNoktasi = z;
}
unsigned Yuk::uzunluk(char *str) const
{
    unsigned int length = 0;

    while (*str++ != '\0')
    {
        ++length;
    }
    return length;
}
Arac::Arac()
{
    plaka = nullptr;
}
Arac::Arac(char *plate, list<Surucu> drivers)
{
    setter_plaka(plate);
    setter_surucu(drivers);
}

Arac::~Arac()
{
    if (plaka != nullptr)
    {
        delete[] plaka;
    }
}
Arac::Arac(const Arac &other)
{
    setter_plaka(other.plaka);
    setter_surucu(other.suruculer);
}
Arac &Arac::operator=(const Arac &other)
{
    if (this == &other)
    {
        return *this;
    }
    setter_plaka(other.plaka);
    setter_surucu(other.suruculer);
    return *this;
}
char *Arac::getter_plaka() const
{
    return plaka;
}
void Arac::setter_plaka(char *plate)
{
    if (plaka != nullptr)
    {
        delete[] plaka;
    }
    plaka = nullptr;
    try
    {
        plaka = new char[uzunluk(plate) + 1];
    }
    catch (bad_alloc &b)
    {
        std::cerr << "bad_alloc caught: " << b.what() << endl;
    }

    for (unsigned int i = 0; i < uzunluk(plate); i++)
    {
        plaka[i] = plate[i];
    }
    plaka[uzunluk(plate)] = '\0';
}
list<Surucu> Arac::getter_surucu() const
{
    return suruculer;
}
void Arac::setter_surucu(list<Surucu> drivers)
{
    suruculer = drivers;
}
unsigned Arac::uzunluk(char *str) const
{
    unsigned int length = 0;

    while (*str++ != '\0')
    {
        ++length;
    }
    return length;
}
void Arac::write(ostream &out) const
{
    out << "Plaka:" << getter_plaka() << endl;
    out << "Arac Suruculeri" << endl;
    for (Surucu x : suruculer)
    {
        out << x;
    }
    out << endl;
}
Otobus::Otobus()
{
}
Otobus::Otobus(char *plate, list<Surucu> drivers, vector<Yolcu> yolcu)
{
    setter_plaka(plate);
    setter_surucu(drivers);
    setter_yolcu(yolcu);
}
vector<Yolcu> Otobus::getter_yolcu() const
{
    return Yolcular;
}
void Otobus::setter_yolcu(vector<Yolcu> Yolcular1)
{
    for (unsigned int i = 0; i < Yolcular1.size(); ++i)
    {
        Yolcular.push_back(Yolcular1[i]);
    }
}
void Otobus::write(ostream &out) const
{
    out << "Plaka: " << getter_plaka() << endl;
    out << "Arac Suruculeri" << endl;
    for (Surucu x : getter_surucu())
    {
        out << x << endl;
    }
    out << "Yolcular" << endl;
    for (unsigned int i = 0; i < Yolcular.size(); ++i)
    {
        out << Yolcular[i];
    }
}
Kamyon::Kamyon()
{
    OzluSoz = nullptr;
}
Kamyon::Kamyon(char *plate, list<Surucu> drivers, char *soz, vector<Yuk> yuk)
{
    setter_plaka(plate);
    setter_surucu(drivers);
    setter_soz(soz);
    setter_yuk(yuk);
}
Kamyon::~Kamyon()
{
    if (OzluSoz != nullptr)
    {
        delete[] OzluSoz;
    }
}
Kamyon::Kamyon(const Kamyon &other)
{

    setter_plaka(other.getter_plaka());
    setter_surucu(other.getter_surucu());
    setter_soz(other.OzluSoz);
    setter_yuk(other.Yukler);
}
Kamyon &Kamyon::operator=(const Kamyon &other)
{
    if (this == &other)
    {
        return *this;
    }
    setter_plaka(other.getter_plaka());
    setter_surucu(other.getter_surucu());
    setter_soz(other.OzluSoz);
    setter_yuk(other.Yukler);
    return *this;
}
char *Kamyon::getter_soz() const
{
    return OzluSoz;
}
void Kamyon::setter_soz(char *soz)
{
    if (OzluSoz != nullptr)
    {
        delete[] OzluSoz;
    }
    OzluSoz = nullptr;
    try
    {
        OzluSoz = new char[uzunluk(soz) + 1];
    }
    catch (bad_alloc &b)
    {
        std::cerr << "bad_alloc caught: " << b.what() << endl;
    }

    for (unsigned int i = 0; i < uzunluk(soz); i++)
    {
        OzluSoz[i] = soz[i];
    }
    OzluSoz[uzunluk(soz)] = '\0';
}
vector<Yuk> Kamyon::getter_yuk() const
{
    return Yukler;
}
void Kamyon::setter_yuk(vector<Yuk> Yukler1)
{
    for (unsigned int i = 0; i < Yukler1.size(); ++i)
    {
        Yukler.push_back(Yukler1[i]);
    }
}
void Kamyon::write(ostream &out) const
{

    out << "Plaka: " << getter_plaka() << endl;
    out << "Arac Suruculeri" << endl;
    for (Surucu x : getter_surucu())
    {
        out << x;
    }
    out << endl;

    out << getter_soz() << endl;
    for (unsigned int i = 0; i < Yukler.size(); i++)
    {
        out << Yukler[i] << endl;
    }
}
