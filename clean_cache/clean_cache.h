#ifndef __CLEAN_CACHE_H__
#define __CLEAN_CACHE_H__

#include <vector>
#include <unistd.h> // getopt

using namespace std;

class LongVec {
	private:
		vector<int> vec;
		string prog;
		size_t loops;
	public:
		LongVec(const int &, string, const size_t &);
		void rcn_frdly(const int &);
		void streaming();
		void rand_acc();  // random access
		void thrashing();
		void show() const;

};


//helper functs
void usage();
void get_arg(int, char **, int *, int *);

#endif
