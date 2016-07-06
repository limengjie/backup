#include <iostream>
#include "sync.h"
#include "defines.h"
#include "clean_cache.h"

using namespace std;

const string prog = "stm"; //program's name, used by term_prog()


int main (int argc, char ** argv) {
  //timing
  //clock_t begin_, end_;
  //begin_ = clock();
  //double time_spent;
  //time_t begin_, end_;
  //time(&begin_);
  //double run_time = 171;


	//==========================================
	//<initializatio> 
	//==========================================
	mcsim_skip_instrs_begin();

	srand(time(NULL));
	//get two members
	int size, loops;
	get_arg(argc, argv, &size, &loops);
	
	//build array
	LongVec V(size, prog, loops);

	mcsim_skip_instrs_end();
	//==========================================
	//</initialization>
	//==========================================
	

	//V.show();

	V.streaming();
	//V.rand_acc();
	//V.thrashing();
	
	//int num = 50; // num = the # of different positions
	//V.rcn_frdly(num); 

	//V.show();

	//end_ = clock();
	//time_spent = (double)(end_ - begin_) / CLOCKS_PER_SEC;
	//time(&end_);
	//time_spent = (double)difftime(end_, begin_);
	//cout << "----------------------------------\n";
	//cout << "tot time = " << time_spent << endl;
	//cout << "----------------------------------\n";

	term_prog(loops, prog);

	return 0;
}
