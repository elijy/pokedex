/*
 * PokemonList.cpp
 *
 *  Created on: 2013-11-02
 *      Author: Jagath
 */

#include "pokemonlist.h"
#include "pokemon.h"
#include "applicationui.h"
#include <bb/cascades/DataModelChangeType>
#include <iostream>
using std::cerr;
using std::endl;
/*
 * PokemonList is derive from DataModel which provides the base class for the "model"
 * in the model-view-controller pattern used by the ListView UI control
*/

int numOfPoke = 718;
PokemonList::PokemonList(QObject* parent) : bb::cascades::DataModel(parent)
{
}

// Return the number of child items contained in a given entry
// Since we only implement a flat list, we must return 0 for any sub item.
int PokemonList::childCount(const QVariantList& indexPath) {
	// For indexPath, See http://developer.blackberry.com/native/reference/cascades/bb__cascades__datamodel.html

	// Return the item count if asking for top level count
	if (indexPath.empty())
		return numOfPoke;	// TODO: Return the correct number of pokemon

	// No sub levels
	return 0;
}

// Used for displaying multi-level lists
bool PokemonList::hasChildren(const QVariantList& indexPath) {
	if (indexPath.empty())
		return true; // The root node always has children
	else
		return false; //
}

// Return the data for the item given by indexPath
QVariant PokemonList::data(const QVariantList& indexPath) {
	// TODO: Load the list from db/pokemon.csv file
	cerr<<"entered data function"<<endl;

	//static QString pokemon_list[6]={"#001 Bulbasaur [Grass, Poison]", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", "Charizard"};
	static QString pokemon_type[10]={"Grass, Poison", "Grass, Poison", "Grass, Poison", "Fire", "Fire", "Fire, Flying"};
	//static QString pokemon_hitpoints[10]={"SwagonSwag","swagswag","yoloswag","swagonyolo"};
	//static QString pokemon_attack[10]={"SwagonSwag","swagswag","yoloswag","swagonyolo"};
	//static QString pokemon_defense[10]={"SwagonSwag","swagswag","yoloswag","swagonyolo"};
	//static QString pokemon_specialAttack[10]={"SwagonSwag","swagswag","yoloswag","swagonyolo"};
	//static QString pokemon_specialDefense[10]={"SwagonSwag","swagswag","yoloswag","swagonyolo"};
	//static QString pokemon_speed[10]={"SwagonSwag","swagswag","yoloswag","swagonyolo"};

	//m_pokemon_list = new QString [4152];
	//populateNames();

	int i = indexPath[0].toInt(); 		// Get the menu index
	QVariantMap data;
	data["name"] = m_nameDisplay[i];	// Get the name of pokemon for this index
	data["type"] = pokemon_type[i];
	data["hitpoints"] = pokemon_hitpoints[i];
	data["attack"] = pokemon_attack[i];
	data["defense"] = pokemon_defense[i];
	data["specialAttack"] = pokemon_specialAttack[i];
	data["specialDefense"] = pokemon_specialDefense[i];
	data["speed"] = pokemon_speed[i];
	data["height"] = pokemon_height[i];
	data["weight"] = pokemon_weight[i];
	data["total"] = pokemon_baseExp[i];


	cerr<<"left data function"<<endl;
	return data;			// Return the name as a QVariant object
}

PokemonList::~PokemonList() {
	// TODO: Delete any object that were created
}

void PokemonList::populateNames()
{
	cerr<<" entered populate names"<<endl;
		m_pokemon_list = new QString[4153];//dynamic array which will hold all the pokemon
		m_language_id = new QString[4153];
		m_pokemonID = new QString [4153];

		QFile file("app/native/assets/data/pokemon_species_names.csv");
		if (file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
		QTextStream in(&file); // create a text stream from the file
		int index_counter = 0;//variable to keep track of the index when populating the array
			while (!in.atEnd())
			{ // Read until EOF
				QString line = in.readLine(); // Read a line as a QString
				//cerr << line.toStdString() << endl;
				QStringList list = line.split(",");//splits each line into an string held in an array
				m_pokemon_list[index_counter] = list[2];//adds pokemon name into array
				m_language_id[index_counter] = list[1];
				m_pokemonID[index_counter] = list[0];
				index_counter ++;
			}
		}
		else
		cerr << "Failed to open types.csv: " << file.error() << endl;

		m_type_pokeID = new QString [1155];
		m_type_ID = new QString [1155];
		m_type_slot = new QString [1155];

		QFile file1("app/native/assets/data/pokemon_types.csv");
				if (file1.open(QIODevice::ReadOnly | QIODevice::Text))
				{
				QTextStream in(&file1); // create a text stream from the file
				int index_counter = 0;//variable to keep track of the index when populating the array
					while (!in.atEnd())
					{ // Read until EOF
						QString line = in.readLine(); // Read a line as a QString
						//cerr << line.toStdString() << endl;
						QStringList list = line.split(",");//splits each line into an string held in an array
						m_type_pokeID[index_counter] = list[0];//adds pokemon name into array
						m_type_ID[index_counter] = list[1];
						m_type_slot[index_counter] = list[2];
						//cerr<< m_type_ID[index_counter].toStdString()<<endl;
						index_counter ++;

					}
				}
				else
				cerr << "Failed to open types.csv: " << file1.error() << endl;
		populateStats(m_pokemon);
		refreshList(9,0);
		Pokemon pokemon;

		cerr<<" left populate names"<<endl;
}

void PokemonList::populateStats(Pokemon pokemon)
{
	cerr<<"entered populate stats"<< endl;
	m_pokemon.populate();
	m_pokemon.organize();

	pokemon_type = new QString [10];
	pokemon_hitpoints = new QString [10];
	pokemon_attack = new QString [10];
	pokemon_defense = new QString [10];
	pokemon_specialAttack = new QString [10];
	pokemon_specialDefense = new QString [10];
	pokemon_speed = new QString [10];
	pokemon_height = new QString [10];
	pokemon_weight = new QString [10];
	pokemon_baseExp = new QString [10];

	for (int i = 0; i< 10; i++)
	{
		pokemon_hitpoints[i] = m_pokemon.returnHitPoints(i);
		pokemon_attack[i] = m_pokemon.returnAttack(i);
		pokemon_defense[i] = m_pokemon.returnDefense(i);
		pokemon_specialAttack[i] = m_pokemon.returnSpecialAttack(i);
		pokemon_specialDefense[i] = m_pokemon.returnSpecialDefense(i);
		pokemon_speed[i] = m_pokemon.returnSpeed(i);
		pokemon_height[i] = m_pokemon.returnHeight(i);
		pokemon_weight[i] = m_pokemon.returnWeight(i);
		pokemon_baseExp[i] = m_pokemon.returnBase(i);
	}
	cerr<<"left populate stats"<< endl;
}

void PokemonList::refreshList(int language,int type)
{
	m_nameDisplay = NULL;
	m_nameDisplay = new QString[4153];
	QString* tmpArray = new QString [1155];
	int index_counter1 = 0;
	int index_counter2 = 0;

	if(type == 0)
		{
			for(int i = 0; i < 1155 ; i++)
			{
				if(m_type_slot[i].toInt() == 1)
				{
					tmpArray[index_counter1] = m_type_pokeID[i];
					index_counter1++;

				}
			}
			}
	else
		{
			for(int i = 0; i < 1155 ; i++)
			{
				if(m_type_ID[i].toInt() == type)
				{
					tmpArray[index_counter1] = m_type_pokeID[i];
					index_counter1++;
				}
			}
		}

	for(int i=0; i <718; i++)
	{
		for(int j = 0; j< 4153; j++)
		{
			if(language == 7 || language == 8)
			{
				if(tmpArray[i].toInt() == m_pokemonID[j].toInt() && m_language_id[j].toInt() == 9)
				{
					QString tmp = m_pokemon.returnID(tmpArray[i].toInt());
					tmp.append(m_pokemon_list[j]);
					tmp.append( " [English]");
					m_nameDisplay[index_counter2] = tmp;
					index_counter2++;
					numOfPoke = index_counter2;
				}
			}
			else if(tmpArray[i].toInt() == m_pokemonID[j].toInt() && m_language_id[j].toInt() == language)
			{
				QString tmp = m_pokemon.returnID(tmpArray[i].toInt());
				tmp.append(m_pokemon_list[j]);
				m_nameDisplay[index_counter2] = tmp;
				index_counter2++;
				numOfPoke = index_counter2;
			}else if(language == 1 || language == 5 || language == 6)
			{
				if(tmpArray[i].toInt() == m_pokemonID[j].toInt() && m_language_id[j].toInt() == 9 && tmpArray[i].toInt() > 649)
				{
					QString tmp = m_pokemon.returnID(tmpArray[i].toInt());
					tmp.append(m_pokemon_list[j]);
					tmp.append( " [English]");
					m_nameDisplay[index_counter2] = tmp;
					index_counter2++;
					numOfPoke = index_counter2;
				}
			}else if(language == 2 || language == 3)
			{
				if(tmpArray[i].toInt() == m_pokemonID[j].toInt() && m_language_id[j].toInt() == 9 && tmpArray[i].toInt() > 493)
				{
					QString tmp = m_pokemon.returnID(tmpArray[i].toInt());
					tmp.append(m_pokemon_list[j]);
					tmp.append( " [English]");
					m_nameDisplay[index_counter2] = tmp;
					index_counter2++;
					numOfPoke = index_counter2;
				}
			}else if(language == 5)
			{
				if(tmpArray[i].toInt() == m_pokemonID[j].toInt() && m_language_id[j].toInt() == 9 && tmpArray[i].toInt() > 500)
				{
					QString tmp = m_pokemon.returnID(tmpArray[i].toInt());
					tmp.append(m_pokemon_list[j]);
					tmp.append( " [English]");
					m_nameDisplay[index_counter2] = tmp;
					index_counter2++;
					numOfPoke = index_counter2;
				}
			}

		}
	}

		cerr<<"language changed"<<endl;
		emit itemsChanged( bb::cascades::DataModelChangeType::Update);
};

