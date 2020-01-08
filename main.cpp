//Aleksandra Chesiak
#include <iostream>
using namespace std;

class Gladiator;
class Human;
class Squad;
class Beast;
class Caesar;


class Gladiator {
protected:
    int numOfHits = 0;

    unsigned int health;
    unsigned int damage;
    unsigned int rapidity;
    unsigned int defence;

    friend class Caesar;
    friend class Squad;
    virtual void die();                     // zeruje pkty życia
public:
    Gladiator() {}                    // daj wszędzie metody CZYSTO wirtualne
    ~Gladiator(){}
    virtual unsigned int getRemainingHealth() =0;
    virtual unsigned int getHealthPoints(){};
    virtual unsigned int getDamage () =0;
    virtual unsigned int getRapidity() =0;
    virtual void takeDamage(unsigned int) =0;
    virtual void applyWinnerReward() =0;
    virtual void cure() =0;
    virtual void printParams() =0;
    virtual string getName () {};


};

void Gladiator::die() {
    health = 0;
}

class Human : virtual public Gladiator {
protected:
    string humanName;

    const int MAX_HEALTH = 200;
    const int BASE_DAMAGE = 30;
    const int BASE_RAPIDITY = 10;
    const int BASE_DEFENCE = 10;

public:
    Human(){}
    ~Human() {}
    Human(string s) {
        humanName = s;
        health = 200;
        damage = 30;
        rapidity = 10;
        defence = 10;
    }

    virtual unsigned int getRemainingHealth();
    virtual unsigned int getDamage ();
    virtual unsigned int getRapidity();
    unsigned int getHealthPoints ();

    virtual void takeDamage(unsigned int);
    virtual void applyWinnerReward();
    virtual void cure();
    virtual void printParams();
    virtual string getName ();

};

string Human::getName() {
    return humanName;
}
unsigned int Human::getRemainingHealth() { // procentowo
    return ((double)health / MAX_HEALTH ) * 100;
}
unsigned int Human::getHealthPoints() {
    return health;
}
unsigned int Human::getDamage() {
    return damage;
}
unsigned int Human::getRapidity() {
    return rapidity;
}

void Human::takeDamage( unsigned int x ) {             // x pomniejszany o wartosc obrony i pkty szybkości
    if ( x > defence ) {
        x -= defence;
        if ( x > rapidity ) {
            x -= rapidity;
        }
        else {
            x = 0;
        }
    }
    else {
        x = 0;
    }
    if ( health > x ) {
        health -= x;
    }
    else {
        health = 0;
    }
}

void Human::applyWinnerReward() {
    damage += 2;
    rapidity += 2;
}

void Human::cure() {
    health = MAX_HEALTH;
}

void Human::printParams() {
//    cout << "Human" << endl;
    cout << humanName << ":" << getRemainingHealth();
    cout << ":" << getDamage() << ":" << getRapidity() << endl;
}

class Beast : virtual public Gladiator {
protected:
    string beastName;

    const int MAX_HEALTH = 150;
    const int BASE_DAMAGE = 40;
    const int BASE_RAPIDITY = 20;
    const int BASE_DEFENCE = 0;

public:
    Beast(){}
    Beast ( string s ){
        beastName = s;
        health = 150;
        damage = 40;
        rapidity = 20;
        defence = 0;
    }
    ~Beast() {}
    virtual unsigned int getRemainingHealth();
    unsigned int getHealthPoints ();
    virtual unsigned int getDamage ();
    virtual unsigned int getRapidity();
    virtual void takeDamage(unsigned int);
    virtual void applyWinnerReward();
    virtual void cure();
    virtual void printParams();
    virtual string getName ();

};

string Beast::getName() {
    return beastName;
}
unsigned int Beast::getRemainingHealth() {
    return ((double)health / MAX_HEALTH ) * 100;
}
unsigned int Beast::getHealthPoints() {
    return health;
}
unsigned int Beast::getDamage() {
    if ( getRemainingHealth() < 25 ) {
        return 2 * damage;
    }
    else {
        return damage;
    }
}
unsigned int Beast::getRapidity() {
    return rapidity;
}

void Beast::takeDamage(unsigned int x ) {       // x pomnijeszamy o POŁOWĘ pktów szybkości
    if ( x > ( rapidity / 2 ) ) {
        x -= ( rapidity / 2 );
    }
    else {
         x = 0;
    }
    if ( health > x ) {
        health -= x;
    }
    else {
        health = 0;
    }
}

void Beast::applyWinnerReward() {
    damage += 2;
    rapidity += 2;
}

void Beast::cure() {
    health = MAX_HEALTH;
}

void Beast::printParams() {
//    cout << "Beast" << endl;
    cout << beastName << ":" << getRemainingHealth();
    cout << ":" << getDamage() << ":" << getRapidity() << endl;
}

class Berserker : public Human, public  Beast{
protected:
    string berserkerName;

    const int MAX_HEALTH = 200;
    const int BASE_DAMAGE = 45;
    const int BASE_RAPIDITY = 5;
    const int BASE_DEFENCE = 15;

public:
    Berserker() {}
    ~Berserker() {}
    Berserker ( string s ) {
        berserkerName = s;
        health = 200;
        damage = 35;
        rapidity = 5;
        defence = 15;
    }
    virtual void printParams();

    virtual unsigned int getRemainingHealth();
    unsigned int getHealthPoints ();
    virtual unsigned int getDamage ();
    virtual unsigned int getRapidity();
    virtual void takeDamage(unsigned int);
    virtual void applyWinnerReward();
    virtual void cure();
    virtual string getName ();

};

string Berserker::getName() {
    return berserkerName;
}
void Berserker::printParams() {
//    cout << "Berserker" << endl;
    cout << getName() << ":" << getRemainingHealth();
    cout << ":" << getDamage() << ":" << getRapidity() << endl;
}
unsigned int Berserker::getHealthPoints() {
    return health;
}
unsigned int Berserker::getDamage() {
    if ( getRemainingHealth() < 25 ) {
        return 2 * damage;
    }
    else {
        return damage;
    }
}
unsigned int Berserker::getRapidity() {
    return rapidity;
}

void Berserker::takeDamage(unsigned int x ) {
    if ( getRemainingHealth() < 25 ) {
        Beast::takeDamage(x);
    }
    else {
        Human::takeDamage(x);
    }

}

void Berserker::applyWinnerReward() {
    damage += 2;
    rapidity += 2;
}

void Berserker::cure() {
    health = MAX_HEALTH;
    defence = BASE_DEFENCE;
}

unsigned int Berserker::getRemainingHealth() {
    return ((double)health / MAX_HEALTH ) * 100;
}

class Squad : public Gladiator {
protected:
    string id = "Squad";
    Gladiator* grupa [ 10000 ];
    int top = -1;

    virtual void die();

public:
    bool isSquadEmpty ();
    bool isSquadFull ();

    unsigned int getRemainingHealth();       // zdrowie najsilniejszego członka - getRemainingHealth
    unsigned int getHealthPoints ();
    unsigned int getDamage ();
    unsigned int getRapidity();              // szybkość najwolniejszego czlonka
    void takeDamage(unsigned int);
    virtual void applyWinnerReward();
    virtual void cure();
    void printParams();
    virtual string getName ();
    void updateDead ();

    void addGladiator ( Gladiator* );
    void removeFromSquad ( int );

};

void Squad::printParams() {
    cout << "Squad:" << getRemainingHealth();
    cout << ":" << getDamage() << ":" << getRapidity() << endl;
}

bool Squad::isSquadEmpty() {
    return ( top == -1 );
}
bool Squad::isSquadFull() {
    return ( top == 9999 );
}
void Squad::addGladiator(Gladiator *g) {
    if ( g != NULL ) {
        bool uniqueGlad = true;
        for (int i = 0; i <= top ; ++i) {
            if ( grupa [ i ] == g ) {
                uniqueGlad = false;
                break;
            }
        }
        if ( uniqueGlad ) {                 // czy to potrzebne ?
            if ( ! isSquadFull() ) {
                grupa [ ++top ] = g;
            }
        }
    }
}

unsigned int Squad::getRapidity () {
    updateDead();
    if ( !isSquadEmpty() ) {
        int speed = 0;
        for (int i = 1; i <= top ; ++i) {
            if ( grupa[ speed ]->getRapidity() > grupa[ i ]->getRapidity() ) {
                speed = i;
            }
        }
        return grupa [ speed ]->getRapidity();
    }
    else {
        return 0;
    }
}

unsigned int Squad::getRemainingHealth() {
    updateDead();
    if ( !isSquadEmpty() ) {
        int maxHP = 0;
        for (int i = 1; i <= top ; ++i) {
            if ( grupa [ maxHP ]->getRemainingHealth() < grupa [ i ]->getRemainingHealth() ) {
                maxHP = i;
            }
        }
        return grupa[ maxHP ]->getRemainingHealth();
    }
    else {
        return 0;
    }
}

unsigned int Squad::getHealthPoints() {
    updateDead();
    if ( !isSquadEmpty() ) {
        int maxHP = 0;
        for (int i = 1; i <= top ; ++i) {
            if ( grupa [ maxHP ]->getHealthPoints() < grupa [ i ]->getHealthPoints() ) {
                maxHP = i;
            }
        }
        return grupa[ maxHP ]->getHealthPoints();
    }
    else {
        return 0;
    }
}

void Squad::removeFromSquad(int i) {
    if ( !isSquadEmpty() ) {
        grupa[ i ] = grupa[ top ];
        top--;
    }
}

unsigned int Squad::getDamage() {
    updateDead();
    if ( !isSquadEmpty() ) {
        unsigned int attackSum = 0;
        for (int i = 0; i <= top ; ++i) {
            attackSum += grupa [ i ]->getDamage();
        }
        return attackSum;
    }
    return 0;
}

void Squad::takeDamage ( unsigned int x ) {             // każdy członek otrzymuje średnią wart x
    updateDead();
    int mianownik = top + 1;
    for (int i = top; i >= 0 ; i-- ) {
        grupa [ i ]->takeDamage( x/ mianownik );
        if ( grupa[ i ]->getRemainingHealth() == 0 ) {
            removeFromSquad( i );
        }
    }
}

string Squad::getName() {
    if ( !isSquadEmpty() ) {
        return grupa[ 0 ]->getName();
    }
    return "empty squad";
}

void Squad::applyWinnerReward() {
    updateDead();
    for (int i = 0; i <= top ; ++i) {
        grupa[ i ]->applyWinnerReward();
    }
}

void Squad::cure() {
    updateDead();
    for (int i = 0; i <= top ; ++i) {
        grupa[ i ]->cure();
    }
}

void Squad::die() {

    for (int i = 0; i <= top ; ++i) {
        grupa[ i ]->die();
    }
    health = 0;
//    top = -1;
}

void Squad::updateDead() {
    for (int i = top; i >= 0 ; i-- ) {

        if ( grupa[ i ]->getRemainingHealth() == 0 ) {
            removeFromSquad( i );
        }
    }

}


class Caesar {
public:
    int numOfJudges = 0;
    int numOfHits = 0;
    void judgeDeathOfLife ( Gladiator * );
};

void Caesar::judgeDeathOfLife(Gladiator *g ) {
    numOfJudges++;
//    cout << "Cezar osąd numer: " << numOfJudges << endl;
    if ( numOfJudges % 3 == 0 && numOfHits % 2 == 0 ) {
        g->die();
    }
}

class Amphitheatre {
protected:
    Caesar *caesar;
public:
    Amphitheatre ( Caesar *c ) {
        caesar = c;
    }
    void fight ( Gladiator*, Gladiator* );

};

void Amphitheatre::fight(Gladiator *g1, Gladiator *g2) {

    Gladiator* first;
    Gladiator* second;
    if ( g1->getRemainingHealth() == 0 || g2->getRemainingHealth() == 0 ) {
        // nie żyje jeden, czyli nie dochodzi do walki
//        cout << "Jeden gostek martwy!" << endl;
    }
    else {
        if( g1->getRapidity() > g2->getRapidity() ) {
            first = g1;
            second = g2;
        }
        else {
            if ( g1->getRapidity() == g2->getRapidity() ) {
                first = g1;
                second = g2;
            }
            else {
                first = g2;
                second = g1;
            }
        }       // wiemu już kto zacznie
        int numOfhits = 0;
        int firstHits = 0;
        int secondHits = 0;
        while ( numOfhits < 40 ) {
            int xe = first->getDamage();
            second->takeDamage( xe );
//            second->takeDamage( first->getDamage() );       // zadaje ciosy drugiemy gladiatorowi
            firstHits++;
            // rozpatrujemy skutki
            if ( second->getRemainingHealth() >= 10 ) {       // drugi może zadać ciosy
                int x = second->getDamage();
//                first->takeDamage( second->getDamage() );
                first->takeDamage( x );
                secondHits++;

                if ( first->getRemainingHealth() < 10 ) {
                    if ( first->getRemainingHealth() > 0 ) {    // sądzi pierwszego
                        this->caesar->numOfHits = numOfhits+1;
//                        this->caesar->numOfHits = firstHits;
                        caesar->judgeDeathOfLife( first );
//                        this->caesar->numOfHits = secondHits;
//                        caesar->judgeDeathOfLife( second );
                        break;
                    }
                    else {
                        break;
                    }

                }
                else {
                    first->printParams();                       // print params dla first, potem dla second
                    second->printParams();
                }
            }
            else {
                if ( second->getRemainingHealth() == 0 ) {
                    break;
                }
                else {
                    this->caesar->numOfHits = numOfhits+1;
//                    this->caesar->numOfHits = firstHits;
//                    caesar->judgeDeathOfLife( first );
//                    this->caesar->numOfHits = secondHits;
                    caesar->judgeDeathOfLife( second );
                    break;
                }
            }
            numOfhits++;
        }
        if ( numOfhits == 40 ) {
            if ( first->getRemainingHealth() > 0 && second->getRemainingHealth() > 0 ) {
                this->caesar->numOfHits = numOfhits;
                caesar->judgeDeathOfLife(first);
//                this->caesar->numOfHits = secondHits;
                caesar->judgeDeathOfLife( second );
            }
        }

        if ( first->getRemainingHealth() > 0 ) {
            first->applyWinnerReward();
            first->cure();
        }
        if ( second->getRemainingHealth() > 0 ) {
            second->applyWinnerReward();
            second->cure();
        }
        first->printParams();
        second->printParams();

    }

}




int main(int argc, char const *argv[]) {
    Amphitheatre a(new Caesar());
    Berserker glad("glad");
    Berserker b("b");





    Squad squad;
    squad.addGladiator(&b);

    b.takeDamage( 10000 );

    squad.printParams();

//    a.fight( &b, &glad);
/*


    Human h1 ( "h1" );
    Beast b1 ( "b1" );
    Berserker ber ("berk" );

    a.fight( &h1, &glad );
    cout << endl;
    a.fight( &b1, &glad );
    cout << endl;
    a.fight( &ber, &glad );
    cout << endl;

    a.fight( &glad, &ber);

    Human h2 ("h2");
    cout << endl;
    a.fight( &glad, &h2);
    cout << endl;
    a.fight( &h2, &glad);

    Beast b2 ("b2");
    cout << endl;
    a.fight( &glad, &b2);

    cout << endl;
    a.fight( &glad, &h2);
    cout << endl;
    b2.cure();
    a.fight( &glad, &b2);

    cout << endl;
    a.fight( &h1, &glad);


    cout << endl;
    a.fight( &h1, &glad);


    cout << endl;
    a.fight( &glad, &h1);


*/
    return 0;
}


