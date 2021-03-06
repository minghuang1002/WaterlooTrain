#include "groupoff.h"

Groupoff::Groupoff(Printer & prt, unsigned int numStudents, unsigned int maxTripCost, unsigned int groupoffDelay):
    prt{prt}, numStudents{numStudents}, maxTripCost{maxTripCost}, groupoffDelay{groupoffDelay}, nextDelivery{0} {
    giftcards = new WATCard::FWATCard[numStudents];
    watcards = new WATCard*[numStudents];
}

Groupoff::~Groupoff() {
    delete [] giftcards;
    delete [] watcards;
}

WATCard::FWATCard Groupoff::giftCard() {
    return giftcards[nextDelivery++];
}

void Groupoff::main() {
    prt.print(Printer::Kind::Groupoff, 'S');
    // Each student wants to receive a giftcard
    for (unsigned int id = 0; id < numStudents; id++) {
        try {
            _Accept(giftCard) {}
        }
        catch (uMutexFailure::RendezvousFailure &) {}
    }

    for (unsigned int id = 0; id < numStudents; id++) {
        try {
            _Accept(~Groupoff) {}
            _Else {
                yield(groupoffDelay);

                watcards[id] = new WATCard();
                watcards[id]->deposit(maxTripCost);
                giftcards[mprng(numStudents - 1)].delivery(watcards[id]);

                prt.print(Printer::Kind::Groupoff, 'D', maxTripCost);

            }
        }
        catch(uMutexFailure::RendezvousFailure &){}
    }
    prt.print(Printer::Kind::Groupoff, 'F');
}
