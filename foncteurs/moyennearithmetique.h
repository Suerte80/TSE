#ifndef MOYENNEARITHMETIQUE_H
#define MOYENNEARITHMETIQUE_H

using namespace std;

class Stock;

class MoyenneArithmetique{
public:
    MoyenneArithmetique();

    float resultat();

    void operator()(Stock &stock);

private:
    unsigned int somme;
    unsigned int iteration;
};

#endif // MOYENNEARITHMETIQUE_H
