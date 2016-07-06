#include <iostream>
//#include <fstream>
#include <vector>

#include "clean_cache.h"
#include "defines.h"
#include "sync.h"

using namespace std;

LongVec::LongVec(const int & size, string program,
		const size_t & num_loop) {
        //get time seed
        srand(time(NULL));

	//set members
	prog  = program;
	loops = num_loop;

	//build array
	for (int i = 0; i < size; ++i) {
		int elt = rand();
		vec.push_back(elt);
	}
}


void LongVec::rcn_frdly(const int & n) {
	//n is the # of different positions
	vector <int> pos;
	int p;
	bool fst_loop = true;
	size_t i, j;

	for (i = 0, j = 0; i < loops ; ++i, ++j) {
		listen(i, prog);
		//in the first loop, 
	        //put the positions into the vector
		if (i == n) fst_loop = false;

		//repeatedly access n postions
		if (j == n) j = 0;

		if (fst_loop) {
			p = rand() % vec.size();
			pos.push_back(p);
		}
		else if (pos.size() != 0)
			p = pos.at(j);
		else { //vector pos is empty
			cout << "Errorr\n";
			exit(1);
		}
		++vec.at(p);
	}
}

void LongVec::streaming() {
	size_t i, j;
	for (i = 0, j = 0; i < loops; ++i, ++j) {
		//listen(i, prog);
		if (j >= vec.size()) j = 0;
		++vec.at(j);
	}
}

void LongVec::thrashing() {
	size_t i, j;
	
	for (i = 0, j = 0; i < loops; ++i) {
		if (j >= vec.size()) j = 0;
		++vec.at(j);
		j += 16;
	}
}

void LongVec::show() const {
	for (size_t i = 0; i < vec.size(); ++i) 
		cout << vec.at(i) << " ";
	cout << endl;
}

void LongVec::rand_acc() {
	for (size_t i = 0; i < loops ; ++i) {
		size_t pos = rand() % vec.size();
		//cout << "pos = " << pos << endl;
		++vec.at(pos);
	}
}

//int main (int argc, char ** argv) {
  ////timing
  ////clock_t begin_, end_;
  ////begin_ = clock();
  //double time_spent;
  //time_t begin_, end_;
  //time(&begin_);
  //double run_time = 171;


	////skip the initialization stage
	////==========================================
	//mcsim_skip_instrs_begin();

	//if (argc != 5) {
		//cout << "Usage: clean_cache [-s size] [-l loops].\n";
		//exit(EXIT_FAILURE);
	//}

	//srand(time(NULL));
	//int size, loops;
	
	////get options
	//int opt;
	//while ((opt = getopt(argc, argv, "ls")) != -1) {
		//switch (opt) {
			//case 'l':
				//loops = atoi(argv[optind]);
				//break;
			//case 's':
				//size = atoi(argv[optind]);
				//break;
			
			//default:  //case '?':
				//cout << "Usage: clean_cache [-s size] [-l loops].\n";
				//exit(EXIT_FAILURE);
		//}
	//}
	
	////cout << "loops = " << loops;
	////cout << " size = " << size << endl;

	//LongVec V(size);

	//mcsim_skip_instrs_end();
	////==========================================
	

	////V.show();

	//V.streaming(loops);
	////V.rand_acc(loops);
	////V.thrashing(loops);
	
	////int num = 50; // num = the # of different positions
	////V.rcn_frdly(loops, num); 

	////V.show();

	////end_ = clock();
	////time_spent = (double)(end_ - begin_) / CLOCKS_PER_SEC;
	//time(&end_);
	//time_spent = (double)difftime(end_, begin_);
	//cout << "----------------------------------\n";
	//cout << "tot time = " << time_spent << endl;
	//cout << "----------------------------------\n";

	//term_prog();

	//return 0;
//}


// helper functions
void usage() {
        cout << "Usage: hashtable_str [-s size] [-l loops].\n";
        exit(EXIT_FAILURE);
}

void get_arg(int argc, char ** argv, int * size, int * loops) {
        if (argc != 5) {
                usage();
        }

        // get options
        int opt;
        while ((opt = getopt(argc, argv, "s:l:")) != -1) {
                switch (opt) {
                        case 'l':
                                *loops = atoi(optarg);
                                break;
                        case 's':
                                *size = atoi(optarg);
                                break;
                        default:
                                usage();
                }
        }
}
