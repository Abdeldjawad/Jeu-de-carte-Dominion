
#include <iostream>
#include <unordered_map>
#include <map>
#include "Reserve.h"
#include "Or.h"
#include "Cuivre.h"
#include "Argent.h"
#include "Domaine.h"
#include "Province.h"
#include "Duche.h"
#include "Malediction.h"
#include "Sorciere.h"
#include "Festin.h"
#include "Douve.h"
#include "Chapelle.h"
#include "Voleur.h"
#include "Atelier.h"
#include "Bucheron.h"
#include "Laboratoire.h"
#include "Jardin.h"
#include "Village.h"




Reserve::~Reserve()
{
}

Reserve::Reserve(const std::vector<Carte*>& cards) : Deck(cards) {
}

Reserve::Reserve() : Deck(createReserveHand()) {
}


Reserve Reserve::createReserveHand() {
    std::vector<Carte*> deck;

    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Cuivre());
    }
    
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Or());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Argent());
    }
    for (int i = 0; i < 12; ++i) {
        deck.push_back(new Domaine());
    }
    for (int i = 0; i < 12; ++i) {
        deck.push_back(new Province());
    }
    for (int i = 0; i < 12; ++i) {
        deck.push_back(new Duche());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Malediction());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Sorciere());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Festin());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Douve());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Chapelle());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Voleur());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Atelier());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Bucheron());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Laboratoire());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Jardin());
    }
    for (int i = 0; i < 10; ++i) {
        deck.push_back(new Village());
    }
    return Reserve(deck);
}


void Reserve::afficherReserve() {
    static std::map<std::string, int> cardGroups; 
    static int z = 1; 
    std::vector<Carte*> temp = getDeck();
    for (Carte* card : temp) {
        std::string cardName = card->obtenirNom();
        if (cardGroups.find(cardName) == cardGroups.end()) {
            cardGroups[cardName] = z++;
        }
    }
    std::map<std::string, int> cardCounts;
    for (Carte* card : temp) {
        cardCounts[card->obtenirNom()]++;
    }
    std::map<int, std::pair<std::string, int>> sortedByGroup; 
    for (const auto& [cardName, groupIndex] : cardGroups) {
        int count = cardCounts[cardName]; 
        sortedByGroup[groupIndex] = {cardName, count};
    }
    for (const auto& [groupIndex, cardData] : sortedByGroup) {
        const std::string& cardName = cardData.first;
        int count = cardData.second;
        Carte* exampleCard = nullptr;
        for (Carte* card : temp) {
            if (card->obtenirNom() == cardName) {
                exampleCard = card;
                break;
            }
        }
        int cost = exampleCard ? exampleCard->getCout() : 0;
        std::cout << groupIndex << " ---- " << count << " cartes " << cardName
                  << " restantes  et le prix est de : " << cost << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;
}

int Reserve::compterPacket(){
    int n = 1;
    for(size_t i=1;i<getDeck().size();i++){
        if(getDeck()[i-1]->obtenirNom() != getDeck()[i]->obtenirNom()){
            n++;
        }
    }
    return n;
}

int Reserve::verifierCarte(std::string name){
    for(Carte* c : getDeck()){
        if(c->obtenirNom() == name){
            return 1;
        }
    }
    return 0;
}



