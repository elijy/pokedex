/*
 * pokemon.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: elijahjoseph-young
 */

#include "pokemon.h"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <QChar>
#include <QString>

#include<iostream>
using std::cerr;
using std::endl;
using std::cout;

Pokemon::Pokemon()
{
}

Pokemon::~Pokemon() {
	// TODO Auto-generated destructor stub
}

void Pokemon::populate() {

	m_statNames = new QString [25];
	m_statID = new QString [25];
	m_statLanguageID = new QString [25];

	 QFile file("app/native/assets/data/stat_names.csv");
	 if (file.open(QIODevice::ReadOnly | QIODevice::Text)) // Successfully opened
	{
		 QTextStream in(&file); // create a text stream from the file
		 int indextracker = 0;
		 while (!in.atEnd())
		 {
		   QString line = in.readLine(); // Read a line as a QString
		   //cerr << line.toStdString() << endl;
		   QStringList list = line.split(",");//creates an array of strings for each line
		   m_statNames[indextracker] = list[2];
		   m_statID[indextracker] = list[0];
		   m_statLanguageID[indextracker] = list[1];
		   indextracker++;
		  }
	}else cerr << "Failed to open types.csv: " << file.error() << endl;

	 m_stat_pokemonID = new QString [4669];
	 m_stat_statID = new QString [4669];
	 m_stat_baseStat = new QString [4669];

	QFile file2("app/native/assets/data/pokemon_stats.csv");
	if (file2.open(QIODevice::ReadOnly | QIODevice::Text)) // Successfully opened
	 	{
	 		 QTextStream in(&file2); // create a text stream from the file
	 		 int indextracker = 0;
	 		 while (!in.atEnd())
	 		 {
	 		   QString line = in.readLine(); // Read a line as a QString
	 		   //cerr << line.toStdString() << endl;
	 		   QStringList list = line.split(",");//creates an array of strings for each line
	 		   m_stat_baseStat[indextracker] = list[2];
	 		   m_stat_statID[indextracker] = list[0];
	 		   m_stat_pokemonID[indextracker] = list[1];
	 		   indextracker++;
	 		  }
	 	}else cerr << "Failed to open types.csv: " << file2.error() << endl;

	m_pokemon_name = new QString [780];
	m_pokemon_height = new QString [780];
	m_pokemon_weight = new QString [780];
	m_pokemon_baseExp = new QString [780];
	m_pokemon_ID = new QString[780];

	QFile file3("app/native/assets/data/pokemon.csv");
		 if (file3.open(QIODevice::ReadOnly | QIODevice::Text)) // Successfully opened
		{
			 QTextStream in(&file3); // create a text stream from the file
			 int indextracker = 0;
			 while (!in.atEnd())
			 {
			   QString line = in.readLine(); // Read a line as a QString
			   //cerr << line.toStdString() << endl;
			   QStringList list = line.split(",");//creates an array of strings for each line
			   m_pokemon_name[indextracker] = list[1];
			   m_pokemon_height[indextracker] = list[3];
			   m_pokemon_weight[indextracker] = list[4];
			   m_pokemon_baseExp[indextracker] = list[5];
			   m_pokemon_ID[indextracker] = list[0];
			   //cerr << m_pokemon_ID[indextracker].toStdString() << endl;
			   indextracker++;
			   //cerr << m_pokemon_ID[indextracker].toStdString() << endl;
			  }
		}else cerr << "Failed to open types.csv: " << file3.error() << endl;

		 m_description = new QString [1000000];
		 QFile file4("app/native/assets/data/pokemon_species_flavor_text.csv");
		 		if (file4.open(QIODevice::ReadOnly | QIODevice::Text)) // Successfully opened
		 		{
		 			 QTextStream in(&file4); // create a text stream from the file
		 			 int indextracker = 0;
		 			 QString tmp = "species_id,version_id,language_id,flavor_text";

		 			 while (!in.atEnd())
		 			 {
		 			   QString line = in.readLine();
		 			  // cerr<<line.toStdString()<< endl;
		 			   //cerr<<"line over"<< endl;// Read a line as a QString

		 			   if(line.contains(",\""))
		 			   {
		 				 m_description[indextracker] = line;
		 				 indextracker++;
		 			   }
		 			   else if(line != tmp)
		 			   {
		 				  m_description[indextracker-1] = m_description[indextracker-1].append(line);
		 			   }else
		 			   {
		 				   cerr<<line.toStdString()<< endl;
		 			   }
		 			 }
		 			m_descriptionID = new QString [10341];
		 			m_generationID = new QString [10341];

		 				for(int i=0; i< 10341; i++)
		 				{
		 					//QStringList list = m_description[i].split("\"");
		 					//m_description[i] = list[1];
		 					//m_descriptionID[i] = list[0];
		 					//QStringList list2 = m_descriptionID[i].split(",");
		 					//m_descriptionID[i] = list2[0];
		 					//m_generationID[i] = list2[1];
		 					//cerr<< m_description[i].toStdString() << endl;;
		 				}
		 		}else cerr << "Failed to open types.csv: " << file4.error() << endl;

cerr<< " finished populate" << endl;
};


void Pokemon::organize()
{
	cerr<<"entered organize"<<endl;
	//description();
	m_container = new Pokemon [719];
	int i = 0;
	for(int index_tracker = 0; index_tracker < 718; index_tracker++)
	{
		m_container[index_tracker].m_pokemonID = m_stat_pokemonID[i+1];
		m_container[index_tracker].m_hitpoints = m_stat_baseStat[i+1];
		m_container[index_tracker].m_attack = m_stat_baseStat[i+2];
		m_container[index_tracker].m_defense = m_stat_baseStat[i+3];
		m_container[index_tracker].m_specialAttack = m_stat_baseStat[i+4];
		m_container[index_tracker].m_specialDefense = m_stat_baseStat[i+5];
		m_container[index_tracker].m_speed = m_stat_baseStat[i+6];

		m_container[index_tracker].m_height = m_pokemon_height[index_tracker+1];
		m_container[index_tracker].m_weight = m_pokemon_weight[index_tracker+1];
		m_container[index_tracker].m_baseExp = m_pokemon_baseExp[index_tracker+1];

		//m_container[index_tracker].m_description2 = m_tmpArray[index_tracker];
		i=i+6;
	}
	createNum();

	cerr<<"left organize"<<endl;
}

void Pokemon::createNum()
{
	int index_tracker = 0;
	for(int i = 0; i < 719; i++)
		{
			if (m_pokemon_ID[i].toInt() < 10)
			{
				QString tmp = "[00";
				tmp.append(m_pokemon_ID[i]);
				tmp.append("]");
				m_container[index_tracker].m_ID = tmp;
				index_tracker++;
			}
			else if (m_pokemon_ID[i].toInt() < 100)
			{
				QString tmp = "[0";
				tmp.append(m_pokemon_ID[i]);
				tmp.append("]");
				m_container[index_tracker].m_ID = tmp;
				index_tracker++;
			}
			else
			{
				QString tmp = "[";
				tmp.append(m_pokemon_ID[i]);
				tmp.append("]");
				m_container[index_tracker].m_ID = tmp;
				index_tracker++;
			}
		}
	cerr<<"left create num"<<endl;
}

void Pokemon::description()
{
	m_tmpArray = new QString [718];
	int index = 0;
	int counter = 1;
	for(int i=0; i< 10341; i++)
	{
		if(m_descriptionID[i].toInt() == counter)
		{
			for(int j=1; j< 25; j++)
			{
				if(m_generationID[i].toInt() == j)
				{
					m_tmpArray[index] = m_description[i];
					index++;
					counter++;
					break;
				}
			}
		}
	//cerr<< index-1  << endl;
	}
}
QString Pokemon::returnHitPoints(int index)
{
	return m_container[index].m_hitpoints;
}

QString Pokemon::returnAttack(int index)
{
	return m_container[index].m_attack;
}

QString Pokemon::returnDefense(int index)
{
	return m_container[index].m_defense;
}

QString Pokemon::returnSpecialAttack(int index)
{
	return m_container[index].m_specialAttack;
}

QString Pokemon::returnSpecialDefense(int index)
{
	return m_container[index].m_specialDefense;
}

QString Pokemon::returnSpeed(int index)
{
	return m_container[index].m_speed;
}

QString Pokemon::returnHeight(int index)
{
	return m_container[index].m_height;
}

QString Pokemon::returnWeight(int index)
{
	return m_container[index].m_weight;
}


QString Pokemon::returnBase(int index)
{
	return m_container[index].m_baseExp;
}

QString Pokemon::returnID(int index)
{
	return m_container[index].m_ID;
}
