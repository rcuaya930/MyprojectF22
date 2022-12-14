//include library
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

//Define the data structure for the participants
typedef struct participant
{
	string language;
	string specialization;;
}

Participant;

// Define the data structure for the country matches 
typedef struct match
{
	string country;
	string language;
	string specialization;
}

Match;

// Declare variables
vector<Participant> participants;
vector<Match> matches;
vector<double> probabilities;

//vector containing specialiizations
const vector<string> specializations
{
	"Anetheiology",
	"Hematology",
	"Urology",
	"Pathology",
	"Infectious disease" };

//vector containing languages
const vector<string> languages
{
	"French",
	"Cantonese",
	"English",
	"Hindi",
	"Spanish",
	"Portugese",
	"Korean",
	"Afrikaans",
	"Oshiwambo",
	"Mandarin",
	"Russian",
	"Arabic",
	"Estonian",
	"Malay",
	"Argentina",
	"German",
	"Slovakian",
	"Haitian" };

//vector containing countries
const vector<string> countries
{
	"France",
	"China",
	"United States",
	"India",
	"Mexico",
	"Brazil",
	"South Korea",
	"South Africa",
	"Namibia",
	"China",
	"Russia",
	"Egypt",
	"Estonia",
	"Haiti" };

//Define function to input participants 
void input_participants()
{
	int indexLan;
	int indexSpec;
	for (int i = 0; i < 100; i++)
	{
		Participant p;
		indexLan = rand() % languages.size();
		indexSpec = rand() % specializations.size();
		p.language = languages[indexLan];
		p.specialization = specializations[indexSpec];
		participants.push_back(p);
	}
}

//Define function to input countries
void input_countries()
{
	//determine the number of countries
	int indexCountry;
	//deteremine the number of languages
	int indexLan;
	//determine the number of specializations
	int indexSpec;
	for (int i = 0; i < countries.size(); i++)
	{
		Match m;
		indexCountry = rand() % countries.size();
		indexLan = rand() % languages.size();
		indexSpec = rand() % specializations.size();
		m.country = countries[indexCountry];
		m.language = languages[indexLan];
		m.specialization = specializations[indexSpec];
		matches.push_back(m);
	}
}

//Define function to compute probability
void compute_probability()
{
	for (int i = 0; i < 100; i++)
	{
		double count = 0;
		for (int j = 0; j < countries.size(); j++)
		{
			if (participants[i].language == matches[j].language &&
				participants[i].specialization == matches[j].specialization)
			{
				count++;
			}
		}

		probabilities.push_back((count / (countries.size() *specializations.size())) *100);
	}
}

//Define Function to print the output
void print_output()
{
	//determine the number of matches
	for (int i = 0; i < 100; i++)
	{
		cout << "Language: " << participants[i].language << endl;
		cout << "Specialization: " << participants[i].specialization << endl;
		cout << "Matching Probability: " << probabilities[i] << "%" << endl;
		cout << endl;
	}
}

//Main function
int main()
{
	srand(time(NULL));
	//Define function to input participants
	input_participants();
	//Define function to input countries
	input_countries();
	//Define function to compute probability
	compute_probability();
	//Define function to print the output
	print_output();
	return 0;
}