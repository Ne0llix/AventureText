#include <iostream>
//#include <Personnage.h>

using namespace std;

//Debut -> Variable choix -> Variable Etage -> Variable Event Rdm -> Fin
//Jet de dé simplifié (réussite, échec) (critique ou non)
//Faire Inventaire en appuyant sur "E"
//Fonction Cuisine en tapant "KOUIZINE"
//Faire fonction combat avec (ATK, SOIN, ATK MAG, CHANT, FUITE)
//Faire un GAME OVER
int demarrage=0;
int piece;
string continuer;
int personnage;


int main() {
	while (demarrage != 1) {
		cout << "Bienvenue dans :" << endl;
		//insérer le titre et le logo
		cout << "Entrez 1 pour demarrer le jeu" << endl;
		cin >> demarrage;
	}
	suite();

	cout << "Vous êtes un groupe de 4 chasseur de Fantôme : Jean le tank, Remi le mage, Xavier l'assassin et Salim le bard" << endl;
	cout << "Votre but est de traverser les etages et de debarasser cet hôtel des spectres qui s'y trouve" << endl;
	suite();
	cout << "Apres une dizaines de minutes de route votre equipe de chasseur de fantomes descendit de leur voiture d’urgence et decouvrit le grand batiments qui, en quelques heure, a ete ravager part la horde de fantomes qui occupent maintenant les lieux."<< endl;
	cout << "L’équipe s’avance vers le hall d’entrer et entre dans le batiments. Les lumieres sont hors services et l’air est lourde, charger de peur et de plasma. "<< endl;

	return 0;
}


/*void defeat() {
	//Si tout les personnage <=0 alors 
	cout << "Vous avez perdu" << endl;
}*/
void suite() {
	while (continuer != "suite") {
		cout << "Taper 'suite' pour continuer" << endl;
		cin >> continuer;
		if (continuer == "suite") {
			system("cls");
			continuer = "t";
		}
	}
	

 }
void Perso() {
	cout << "Qui souhaitez-vous envoyer ?" << endl;
	cin >> personnage;
}