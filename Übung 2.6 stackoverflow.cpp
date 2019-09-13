#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

template <typename Type> Type max ( Type t1, Type t2 )
{	return t1 > t2 ? t1 : t2; }

template <typename vecType> vecType max ( std::vector<vecType> vec )
{	return *std::max_element( vec.begin(), vec.end() ); }

template <typename arrayType> arrayType max ( arrayType *parray, int size )
{	return *std::max_element( parray, parray + size); }
	
int main()
{	
	int iarray[] = { 12, 70, 2, 169, 1, 5, 29 };
	std::vector<int> ivec( iarray, iarray + 7 );
	
	std::string sarray[] = { "We", "were", "her", "pride", "of", "ten" };
	std::vector<std::string> svec( sarray, sarray + 6);
	
	float farray[] = { 2.5, 24.8, 18.7, 4.1, 23.9 };
	std::vector<float> fvec( farray, farray + 5);
	
	int imax = max( max( ivec ), max( iarray, 7 ) );
	float fmax = max( max( fvec ), max( farray, 5 ) );
	std::string smax = ::max( ::max( svec ), ::max( sarray, 6 ) );
	
	std::cout << "imax should be 169  -- found: " << imax << "\n"
		 << "fmax should be 24.8 -- found: " << fmax << "\n"
		 << "smax should be were -- found: " << smax << "\n";
}
