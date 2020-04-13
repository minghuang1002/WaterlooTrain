#include "parent.h"
#include "bank.h"
#include "printer.h"

Parent::Parent(Printer & prt, Bank & bank, unsigned int numStudents, unsigned int parentalDelay, unsigned int maxTripCost):
        prt{prt}, bank{bank}, numStudents{numStudents}, parentalDelay{parentalDelay}, maxTripCost{maxTripCost} {
    prt.print(Printer::Parent, 'S');
}

Parent::~Parent() {
    prt.print(Printer::Parent, 'F');
}
void Parent::main() {
    for (;;) {
        _Accept(~Parent) {
            break;
        }
        _Else{
                yield(parentalDelay);
                unsigned int randomStudent = mprng(numStudents) - 1;
                unsigned int randomProportion = mprng(1, 3);
                unsigned int amountToGive = maxTripCost / randomProportion;
                bank.deposit(randomStudent, amountToGive);
                prt.print(Printer::Parent, 'D', randomStudent, amountToGive);
        }
    }
}