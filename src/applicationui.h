#ifndef ApplicationUI_H_
#define ApplicationUI_H_

#include <QObject>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/DropDown>

namespace bb
{
    namespace cascades
    {
        class Application;
    }
}

/*!
 * @brief Application object
 *
 *
 */
class PokemonList; // forward declaration to avoid including header

class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI(bb::cascades::Application *app);
    // callables from QML
    Q_INVOKABLE void typeSelected(int type);
    Q_INVOKABLE void languageSelected(int language);

    virtual ~ApplicationUI() { }

    void init();
    void typeDropDown();
    void returnNum();
    int returnLanguage();

private:
    PokemonList *m_pokemonList;
    QString  *m_typeNames;
    QString * m_language_id;
    QString * m_type_id;
    QString * m_types;
    QString * m_language_type_id;
    int m_selectedLanguage;
    int m_selectedType;

    bb::cascades::AbstractPane *m_root;
    bb::cascades::DropDown *m_dropDown;
};

#endif /* ApplicationUI_H_ */
