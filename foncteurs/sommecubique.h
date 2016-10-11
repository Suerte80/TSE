#ifndef SOMMECUBIQUE_H
#define SOMMECUBIQUE_H

using namespace std;

class Stock;

class SommeCubique{
public:
    SommeCubique();

    int resultat();

    void operator()(Stock &stock);

private:
    int sommeCubique;
};

#endif // SOMMECUBIQUE_H
