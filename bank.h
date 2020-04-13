#ifndef BANK_H
#define BANK_H
#pragma once

_Monitor Bank {
    unsigned int numStudents;
    unsigned int * studentBank;
    uCondition * studentCond;

  public:
	Bank( unsigned int numStudents );
	~Bank();
	
	void deposit( unsigned int id, unsigned int amount ); // deposit "amount" $ for student "id";
	void withdraw( unsigned int id, unsigned int amount ); // withdrawal "amount" $ from student "id"; block until student has enough funds
}; // Bank

// Local Variables: //
// mode: c++ //
// tab-width: 4 //
// compile-command: "make" //
// End: //
#endif
