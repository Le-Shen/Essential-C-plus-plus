#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

typedef vector<string> vstring;
map<string, vstring> families;

void populate_map( ifstream &nameFile, map<string, vstring> &families )
{
	string textline;
	while( getline( nameFile, textline )){
		string fam_name;
		vector<string> child;
		string::size_type pos = 0, prev_pos = 0, text_size = textline.size();
		
		while(( pos = textline.find_first_of( ' ', pos )) != string::npos ){
			string::size_type end_pos = pos - prev_pos;
			if ( !prev_pos )
				fam_name = textline.substr( prev_pos, end_pos );
			else child.push_back( textline.substr( prev_pos, end_pos ));
			prev_pos = ++pos;
		}
		
		if( prev_pos < text_size )
			child.push_back( textline.substr( prev_pos, pos - prev_pos ));
			
		if ( !families.count( fam_name ))
			families[ fam_name ] = child;
		else cerr << "Oops! We already have a " << fam_name << " family in our map!\n";
	}	
}

void display_map ( const map<string, vstring> &families, ostream &os )
{
	map<string, vstring>::const_iterator it = families.begin(), end_it = families.end();
	while( it != end_it ){
		os << "The " << it->first << " family ";
		if ( it->second.empty() )
			os << "has no children\n";
		else {
			os << "has " << it->second.size() << " children: ";
			vector<string>::const_iterator iter = it->second.begin(), end_iter = it->second.end();
			while( iter != end_iter ){
				os << *iter << " "; ++iter;
			}
			os << endl;
		}
		++it;
	}		
}

void query_map( const string &family, const map<string, vstring> &families )
{
	map<string, vstring>::const_iterator it = families.find( family );
	if ( it == families.end() ){
		cout << "Sorry. The " << family << " is not currently entered.\n";  
		return;
	}
	cout << "The " << family;
	if( !it->second.size() )
		cout << " has no children\n";
	else {
		cout << " has " << it->second.size() << " children: ";
		vector<string>::const_iterator iter = it->second.begin(), end_iter = it->second.end();
		while( iter != end_iter ){
			cout << *iter << " "; ++iter;
		}
		cout << endl;
	}
}

int main()
{
	map<string, vstring> families;
	ifstream nameFile( "C:\\Users\\lshen\\Downloads\\Essential C++ Uebungen\\families.txt" ); //文档中franz后面紧跟一个空格，否则提示" is not currently entered"
	if ( !nameFile ){
		cerr << "Unable to find families.txt file. Bailing Out!\n";
		return -1;
	}
	populate_map( nameFile, families );
	
	string family_name;
	while( 1 ){
		cout << "Please enter a family name or q to quit ";
		cin >> family_name;
		
		if( family_name == "q" )
			break;
		query_map( family_name, families );
	}
	display_map( families, cout );
}
