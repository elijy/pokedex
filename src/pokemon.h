/*
 * pokemon.h
 *
 *  Created on: Nov 21, 2013
 *      Author: elijahjoseph-young
 */

#ifndef POKEMON_H_
#define POKEMON_H_

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

class Pokemon {
public:
	Pokemon();
	virtual ~Pokemon();

	void populate();
	void organize();
	void createNum();
	void description();
	QString returnHitPoints(int);
	QString returnAttack(int);
	QString returnDefense(int);
	QString returnSpecialAttack(int);
	QString returnSpecialDefense(int);
	QString returnSpeed(int);
	QString returnHeight(int);
	QString returnWeight(int);
	QString returnBase(int);
	QString returnID(int);

private:
	Pokemon* m_container;
	QString m_pokemonID;
	QString m_hitpoints;
	QString m_attack;
	QString m_defense;
	QString m_specialAttack;
	QString m_specialDefense;
	QString m_speed;
	QString m_height;
	QString m_weight;
	QString m_baseExp;
	QString m_ID;
	QString m_description2;
	//QString m_baseStat;

	QString* m_statNames;
	QString* m_statID;
	QString* m_statLanguageID;

	QString* m_stat_pokemonID;
	QString* m_stat_statID;
	QString* m_stat_baseStat;

	QString* m_pokemon_name;
	QString* m_pokemon_height;
	QString* m_pokemon_weight;
	QString* m_pokemon_baseExp;
	QString* m_pokemon_ID;

	QString* m_description;
	QString* m_tmpArray;
	QString* m_descriptionID;
	QString* m_generationID;


};

#endif /* POKEMON_H_ */
