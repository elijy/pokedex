#include "applicationui.h"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/DropDown>
#include <bb/cascades/RadioGroup>
#include <bb/cascades/Label>
#include <bb/cascades/ListView>
#include <bb/cascades/DataModelChangeType>

#include <iostream>

#include "pokemonlist.h"
#include "pokemon.h"

using namespace bb::cascades;

using std::cerr;
using std::endl;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
        QObject(app), m_pokemonList(0)
{

    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

    // Create root object for the UI
    m_root = qml->createRootObject<AbstractPane>();

    // Set the handle for the "pokedex" object from QML
    qml->setContextProperty("pokedex", this);

    // Create the "model" to store data about pokemon
    m_pokemonList = new PokemonList(this);
    qml->setContextProperty("poke_list", m_pokemonList);
    m_pokemonList->populateNames();

	/* An example on how to locate the dropdown UI control and add an option
	 * See http://developer.blackberry.com/native/reference/cascades/bb__cascades__dropdown.html
	 * to see what else you can do with the DropDown class
	 */

    /* TODO: All of following should be in a separate init() function. You will need to
     * save the root pointer in a member variable so that you can access it later from
     * the init() function
     */
    returnNum();

    // Set created root object as the application scene
    app->setScene(m_root);
}

void ApplicationUI::init()
{
	m_types = new QString [113];
	m_language_id = new QString [22];
	m_type_id = new QString [113];
	m_selectedLanguage = 9;
	//m_selectedType = 0;
	m_language_type_id = new QString [113];

    // Populate radio buttons for language settings
	RadioGroup *radio(0);	// A pointer to hold the RadioGroup UI object
	radio = m_root->findChild<RadioGroup *>("pokedex_languages");// Search the root QML object for a control named "pokemon_types"

	if (radio)
	{
	// TODO: Open language_name.csv file, parse the csv data and create the drop down list
	// Remove above two lines after that is done
	QFile file("app/native/assets/data/language_names.csv");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text)) // Successfully opened
		{
			QTextStream in(&file); // create a text stream from the file
			int value = 1; //variable to keep track of value in drop drown menu
			int index_tracker = 0;
			while (!in.atEnd())
			{
			  QString line = in.readLine(); // Read a line as a QString
			  //cerr << line.toStdString() << endl;
			  QStringList list = line.split(",");//creates an array of strings for each line
			  if(m_selectedLanguage == list[1].toInt())
			     { //determines if it is the correct language, and adds the type into the drop down menu
			        radio->add(Option::create().text(list[2]).value(value));
			        value ++;
			        m_language_id[index_tracker] = list[0];
			        index_tracker ++;
			     }
			 }
		}else cerr << "Failed to open language.csv: " << file.error() << endl;
	}else cerr << "failed to find pokedex_languages " << endl;


	// TODO: Open types.csv file, parse the csv data and create the drop down list
	// Remove above two lines after that is done
QFile file("app/native/assets/data/type_names.csv");
if (file.open(QIODevice::ReadOnly | QIODevice::Text)) // Successfully opened
	{
	   QTextStream in(&file); // create a text stream from the file
	   int index_tracker = 0;
	   while (!in.atEnd())
	   {
	    QString line = in.readLine(); // Read a line as a QString
	    //cerr << line.toStdString() << endl;
	    QStringList list = line.split(",");//creates an array of strings for each line
	    m_types[index_tracker] = list[2];
	    m_type_id[index_tracker] = list[0];
	    m_language_type_id[index_tracker] = list[1];
	    index_tracker++;
	    }
	  }else cerr << "Failed to open types.csv: " << file.error() << endl;
typeDropDown();

cerr<<"entered init function"<<endl;
	       // Set status text

}


void ApplicationUI::typeSelected(int type) {
	cerr << "In typeSelected() with " << "type=" << type << endl;
	m_selectedType = type;
	m_pokemonList->refreshList(m_selectedLanguage,m_selectedType);
	returnNum();

}


void ApplicationUI::languageSelected(int language) {
	cerr << "In languageSelected() with " << "language=" << language << endl;
	m_selectedLanguage = language;
	typeDropDown();
	m_pokemonList->refreshList(m_selectedLanguage,m_selectedType);
	returnNum();

}

void ApplicationUI::typeDropDown()
{
	m_dropDown = m_root->findChild<DropDown *>("pokemon_types");
	m_dropDown->removeAll();

	if(m_dropDown)
	{
		for(int i = 0; i < 104; i++)
		{
			if(m_selectedLanguage == (m_language_type_id[i]).toInt())
			{
				m_dropDown->add(Option::create().text(m_types[i]).value(m_type_id[i].toInt()));
			}
			else if(m_type_id[i].toInt() == 18)
					{
						QString tmp = " [English]";
						tmp.prepend(m_types[i]);
						m_dropDown->add(Option::create().text(tmp).value(m_type_id[i].toInt()));
					}
			else if(m_selectedLanguage == 2 || m_selectedLanguage == 3 || m_selectedLanguage == 4)
					{
						QString tmp = " [English]";
						tmp.prepend(m_types[i]);
						if(i%6 == 0 && i!=0) m_dropDown->add(Option::create().text(tmp).value(m_type_id[i].toInt()));
					}

		}
	}
}

void ApplicationUI::returnNum()
{
	 Label *status(0);	// A pointer to hold the Label UI object
	    	       // Search the root QML object for a control named "status"
	    status = m_root->findChild<Label *>("pokedex_status");
	    if (status) { // did we succeed in getting a pointer to the Label UI control?
	    	       	// Yes. Now set the text as appropriate
	    	       	status->setText(QString("Found %1 Pokémon").arg(m_pokemonList->childCount(QVariantList())));
	    	       }
	    	       else {
	    	       	cerr << "failed to find status " << endl;
	    	       }
}

int ApplicationUI::returnLanguage()
{
	return m_selectedLanguage;
}
