#ifndef MOYENNEQUADRATIQUE_H
#define MOYENNEQUADRATIQUE_H

class Stock;

class MoyenneQuadratique
{
public:
    MoyenneQuadratique();

    float resultat();

    void operator()(Stock &stock);

private:
    int sommeQuadratique;
    int iteration;
};

#endif // MOYENNEQUADRATIQUE_H
