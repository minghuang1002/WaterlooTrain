#include "conductor.h"
#include "train.h"
#include "printer.h"
#include <iostream>

Conductor::Conductor(Printer & prt, unsigned int id, Train * train, unsigned int delay):
    prt{prt}, id{id}, train{train}, delay{delay} {
}

Conductor::~Conductor() {
}

void Conductor::main() {
    prt.print(Printer::Kind::Conductor, id, 'S');
    try {
        for (;;) {
            _Accept(~Conductor)
            {
                break;
            }
            _Else{
                    yield(delay);
                    prt.print(Printer::Kind::Conductor, id, 'c');
                    train->scanPassengers();
                    break;
            }
        }
    }
    catch (uMutexFailure::RendezvousFailure &) {}
    prt.print(Printer::Kind::Conductor, id, 'F');
}