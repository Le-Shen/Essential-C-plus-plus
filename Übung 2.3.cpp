#include<iostream>
#include<string>
#include<vector>
using namespace std;

// bool calc_elements( vector<int> &vec, int pos );
void display_elems( vector<int> &vec, int pos, const string &title, ostream &os = cout );

/* 
bool calc_elements( vector<int> &vec, int pos )
{
	if ( pos <= 0 || pos > 64 ){
		 cerr << "Sorry. Invalid position: " << pos << endl; 
		 return false;
	}
	
	for (int ix = 0; ix < pos ; ++ix)
		vec.push_back( ix * ( 3*ix - 1 ) / 2 );
		
	return true;
}
*/
extern void really_calc_elems( vector<int>&, int );
inline bool calc_elems( vector<int> &vec, int pos )
{
	if ( pos <= 0 || pos > 64){
		cerr << "Sorry. Invalid position: " << pos << endl;
		return false;
	}
	if ( vec.size() < pos )
	really_calc_elems( vec, pos);
	
	return true;
}

void really_calc_elems( vector<int> &vec, int pos )
{
	for ( int ix = 0; ix < pos ; ++ix )
		vec.push_back( ix * ( 3*ix - 1 ) / 2 );
}

void display_elems( vector<int> &vec, int pos, const string &title, ostream &os)
{
	os << "\n" << title << "\n\t";
	for ( int ix = 0; ix < pos ; ++ix )
		os << vec[ ix ] << ' ';
	os << endl;
}

int main()
{
	vector<int> pent;
	const string title ( "Pentagonal Numeric Series" );
	
	//if ( calc_elements( pent, 0 ))
	if	( calc_elems( pent, 0 ))
		display_elems( pent, 0, title );
		
	//if ( calc_elements( pent, 8 ))
	if ( calc_elems( pent, 14 ))
		display_elems( pent, 14, title );
		
	//if ( calc_elements( pent, 14 ))
	if ( calc_elems( pent, 8 ))
		display_elems( pent, 8, title );
		
	//if ( // calc_elements( pent, 138 ))
	if ( calc_elems( pent, 138 ))
		display_elems( pent, 138, title );
		
}
