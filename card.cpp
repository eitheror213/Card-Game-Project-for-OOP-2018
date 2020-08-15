// HW5 C331 SP18

#include "card.h"
#include <QStringList>
#include <QDialogButtonBox>

Card::Card(int faceNbr, int suitNbr)
    : m_FaceNbr(faceNbr), m_SuitNbr(suitNbr){}

QString Card::toString() const{
    return QString("%1 %2").arg(getFace()).arg(getSuit());
}

int Card::getValue() const {
   if (m_FaceNbr == 0)
       return 4;
   else if (m_FaceNbr == 12)
       return 3;
   else if (m_FaceNbr == 11)
       return 2;
   else if (m_FaceNbr == 10)
       return 1;
   else
       return 0;
}

QStringList Card::s_Faces = QStringList() << "A" << "2" << "3" << "4" << "5" << "6" << "7" << "8"
                                          << "9" << "T" << "J" << "Q" << "K";

QStringList Card::s_Suits = QStringList() << "Clubs" << "Diamonds" << "Hearts" << "Spades";

QString Card::getFace() const { return s_Faces[m_FaceNbr]; }
QString Card::getSuit() const { return s_Suits[m_SuitNbr]; }
