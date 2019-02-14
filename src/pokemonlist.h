/*
 * PokemonList.h
 *
 *  Created on: 2013-11-02
 *      Author: Jagath
 */

#ifndef POKEMONLIST_H_
#define POKEMONLIST_H_

#include <bb/cascades/DataModel>
#include "pokemon.h"

class PokemonList: public bb::cascades::DataModel {
	Q_OBJECT
public:
	PokemonList(QObject *parent = 0);

	// Required interface implementation
	virtual int childCount(const QVariantList& indexPath);
	virtual bool hasChildren(const QVariantList& indexPath);
	virtual QVariant data(const QVariantList& indexPath);

	virtual ~PokemonList();
	void populateNames();
	void populateStats(Pokemon);
	void refreshList(int,int);

private:
	int m_numOfPoke;
	Pokemon m_pokemon;
	QString* m_pokemon_list;
	QString* m_nameDisplay;
	QString* m_language_id;
	QString* m_pokemonID;


	QString* m_type_pokeID;
	QString* m_type_ID;
	QString* m_type_slot;

	QString* pokemon_type;
	QString* pokemon_hitpoints;
	QString* pokemon_attack;
	QString* pokemon_defense;
	QString* pokemon_specialAttack;
	QString* pokemon_specialDefense;
	QString* pokemon_speed;
	QString* pokemon_height;
	QString* pokemon_weight;
	QString* pokemon_baseExp;
};
#endif /* POKEMONLIST_H_ */
