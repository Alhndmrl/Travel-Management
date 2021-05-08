/*Alihan Demirel
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>
using namespace std;
using std::list;

enum EhliyetSinifi
{
    B,
    C,
    D,
    E
};
struct Age
{
    unsigned int age : 5;
};
class Surucu
{
    friend ostream &operator<<(ostream &out, const Surucu &other)
    {
        out << "Isim: ";
        out << other.ad;

        out << endl
            << "Yas:" << other.yas.age + 30 << endl;
        if (other.Ehliyet == 0)
        {
            out << "Sinif: "
                << "B";
        }
        else if (other.Ehliyet == 1)
        {
            out << "Sinif: "
                << "C";
        }
        else if (other.Ehliyet == 2)
        {
            out << "Sinif: "
                << "D";
        }
        else if (other.Ehliyet == 3)
        {
            out << "Sinif: "
                << "E";
        }
        out << endl;
        return out;
    }

private:
    char *ad = nullptr;
    Age yas;
    EhliyetSinifi Ehliyet;

public:
    Surucu();
    Surucu(char *ad, unsigned int yas, EhliyetSinifi &Ehliyet);
    ~Surucu();
    Surucu(const Surucu &other);
    const Surucu &operator=(const Surucu &other);
    char *getter_name() const;
    void setter_name(char *name);
    unsigned int getter_age() const;
    void setter_age(unsigned int age);
    EhliyetSinifi getter_ehliyet() const;
    void setter_ehliyet(EhliyetSinifi &ehliyet);
    unsigned uzunluk(char *str) const;
};
class Yolcu
{
    friend ostream &operator<<(ostream &out, const Yolcu &other)
    {
        out << "Yolcu : " << endl;

        out << "Isim: ";
        out << other.ad;

        out << endl;
        out << "Binis Noktasi  :";

        out << other.BinisNoktasi;

        out << endl;
        out << "İnis Noktasi  :";

        out << other.InisNoktasi;
        out << endl
            << endl;

        return out;
    }

private:
    char *ad = nullptr;
    char *BinisNoktasi = nullptr;
    string InisNoktasi;

public:
    Yolcu();
    Yolcu(char *ad, char *BinisNoktasi, string InisNoktasi);
    ~Yolcu();
    Yolcu(const Yolcu &other);
    const Yolcu &operator=(const Yolcu &other);
    char *getter_name() const;
    void setter_name(char *name);
    char *getter_BinisNoktasi() const;
    void setter_BinisNoktasi(char *BinisNoktasi);
    string getter_InisNoktasi() const;
    void setter_InisNoktasi(string InisNoktasi);
    unsigned uzunluk(char *str) const;
};
class Yuk
{
    friend ostream &operator<<(ostream &out, const Yuk &other)
    {
        out << "İcerik:" << endl;

        out << other.icerik;

        out << endl;
        out << "Agirlik: " << other.agirlik << endl;
        out << "Hacim: " << other.hacim << endl;
        out << "Alici: " << other.alici << endl;
        out << "Binis: " << other.BinisNoktasi << endl;
        out << "Inis : " << other.InisNoktasi << endl;
        return out;
    }

private:
    char *icerik = nullptr;
    double agirlik = 0;
    double hacim = 0;
    string alici;
    string BinisNoktasi;
    string InisNoktasi;

public:
    Yuk();
    Yuk(char *icerik, double agirlik, double hacim, string alici, string binis, string inis);
    ~Yuk();
    Yuk(const Yuk &other);
    Yuk &operator=(const Yuk &other);
    char *getter_icerik() const;
    void setter_icerik(char *icerik1);
    double getter_agirlik() const;
    void setter_agirlik(double weight);
    double getter_hacim() const;
    void setter_hacim(double volume);
    string getter_alici() const;
    void setter_alici(string x);
    string getter_binis() const;
    void setter_binis(string y);
    string getter_inis() const;
    void setter_inis(string z);
    unsigned uzunluk(char *str) const;
};
class Arac
{
    friend ostream &operator<<(ostream &out, const Arac &other)
    {
        other.write(out);
        return out;
    }

private:
    char *plaka;
    list<Surucu> suruculer;

public:
    virtual void write(ostream &out) const;
    Arac();
    Arac(char *plate, list<Surucu> drivers);
    virtual ~Arac();
    Arac(const Arac &other);
    Arac &operator=(const Arac &other);
    char *getter_plaka() const;
    virtual void setter_plaka(char *plate);
    list<Surucu> getter_surucu() const;
    virtual void setter_surucu(list<Surucu> drivers);
    unsigned uzunluk(char *str) const;
};
class Otobus : public Arac
{
    friend ostream &operator<<(ostream &out, const Otobus &other)
    {
        other.write(out);
        return out;
    }

private:
    vector<Yolcu> Yolcular;

public:
    void write(ostream &out) const;
    Otobus();
    Otobus(char *plate, list<Surucu> drivers, vector<Yolcu> yolcu);
    vector<Yolcu> getter_yolcu() const;
    void setter_yolcu(vector<Yolcu> Yolcular1);
};
class Kamyon : public Arac
{
    friend ostream &operator<<(ostream &out, const Kamyon &other)
    {
        other.write(out);
        return out;
    }

private:
    char *OzluSoz = nullptr;
    vector<Yuk> Yukler;

public:
    void write(ostream &out) const;
    Kamyon();
    Kamyon(char *plate, list<Surucu> drivers, char *soz, vector<Yuk> yuk);
    virtual ~Kamyon();
    Kamyon(const Kamyon &other);
    Kamyon &operator=(const Kamyon &other);

    char *getter_soz() const;
    void setter_soz(char *soz);
    vector<Yuk> getter_yuk() const;
    void setter_yuk(vector<Yuk> Yukler1);
};