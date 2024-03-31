#include <iostream>
#include "Personnage.h"

using namespace std;

//Debut -> Variable choix -> Variable Etage -> Variable Event Rdm -> Fin
//Jet de dé simplifié (réussite, échec) (critique ou non)
//Faire Inventaire en appuyant sur "E"
//Fonction Cuisine en tapant "KOUIZINE"
//Faire fonction combat avec (ATK, SOIN, ATK MAG, CHANT, FUITE)
//Faire un GAME OVER
int demarrage = 0;
int piece;
string continuer;
int personnage;
int ActualFloor = 1;
//Fonction Servant au joueur de passer à la suite du jeu
void suite() {
	while (continuer != "suite") {
		cout << "Taper 'suite' pour continuer" << endl;
		cin >> continuer;
		if (continuer == "suite") {
			system("cls");

		}
	}
	continuer = "t";
}
//Fonction pour lancer le texte de chaque fin d'étage
void EndFloor() {
	if (ActualFloor == 1) {
		cout << "L eau arrete de couler des murs et s ecoule par l escalier, l equipe prend les escalier et ce rend a l etage du dessus. " << endl;

	}
	else if (ActualFloor == 2) {
		cout << "Fin etage 2" << endl;
	}
	else if (ActualFloor == 2) {
		cout << "Fin etage 3" << endl;
	}
	else if (ActualFloor == 4) {
		cout << "Fin etage 4" << endl;
	}
}
//Tout les Textes et objet de la Piece 1 en fonction de l'étage
void TxtRoom1() {
	if (ActualFloor == 1) {
		cout << "l equipe ouvre le porte de la premiere chambre du pallier, ils entrent en pataugent dans l eau. Ils ce rendent compte que le liquide jaillit du sol de la piece quand tout d un coup  la porte ce claque derriere eux." << endl << "Un etre fait de plasma apparait ! " << endl;
	}
	else if (ActualFloor == 2) {
		cout << "l’equipe ouvre le porte, Un vent glaciale sabbat sur eux. Le lieux est completement givre et des cristaux ce forme au plafond. Un bruit attire leurs regards, quand tout d’un coup  la porte ce claque derrière eux." << endl << "Un etre fait de plasma apparait ! " << endl;
	}
	else if (ActualFloor == 3) {
		cout << "l’equipe rentre dans la piece avec difficulte, le sable genant la progression. Un drole de sentiment s’empare des chasseurs quand soudain la porte ce ferme violemment derriere eux." << endl << "Un etre fait de plasma apparait !" << endl;
	}
	else if (ActualFloor == 4) {
		cout << "les chasseurs rentre dans la piece il trouve un cle parterre et ressorte" << endl;
	}
}
//Tout les Textes et objet de la Piece 2
void TxtRoom2() {
	if (ActualFloor == 1) {
		cout << "les chasseurs de fantomes entrent dans la chambre numero deux, dans une table de chevet ils trouvent un barre de cereale " << endl;
	}
	else if (ActualFloor == 2) {
		cout << "l’equipe ouvre le porte, Un vent glaciale sabbat sur eux. Le lieux est completement givre et des cristaux ce forme au plafond. Un bruit attire leurs regards, quand tout d’un coup  la porte ce claque derrière eux." << endl << "Un etre fait de plasma apparait !" << endl;
	}
	else if (ActualFloor == 3) {
		cout << "Une table plein de petit gateaux ce trouve au milieux de la piece, seulement trois ne sont pas recouvert de sable. " << endl;
	}
	else if (ActualFloor == 4) {
		cout << "l’equipe rentre dans la chambre, quatre paquet de pop corn sont place sur une table en feu, des petit « pop » « pop » arrives au oreilles des chasseurs, ils prennent les paquet pret et ressorte. " << endl;
	}
}
//Tout les Textes et objet de la Piece 3
void TxtRoom3() {
	if (ActualFloor == 1) {
		cout << "l equipe ouvre le porte de la troisieme chambre du pallier, ils entrent en pataugent dans l eau. Ils ce rendent compte que le liquide coule des murs de la piece quand tout d un coup  la porte ce claque derriere eux." << endl << "Un etre fait de plasma apparait ! " << endl;
	}
	else if (ActualFloor == 2) {
		cout << "l’equipe ouvre le porte, de la neige tombe dans la salle. Le lieux est completement enneiger. La porte ce ferme violemment derriere eux." << endl << "Un etre fait de plasma apparait ! " << endl;
	}
	else if (ActualFloor == 3) {
		cout << "les chasseurs fouille la chambre en quete d’objet interessant, dans une armoire il trouve un cle et sorte de la piece " << endl;
	}
	else if (ActualFloor == 4) {
		cout << "l’equipe ouvre le porte, des flamme leurs brule legerement les habits ,le lieux est completement en feu. La porte ce ferme violemment derriere eux." << endl << "Un etre fait de plasma apparait !" << endl;
	}
}
//Tout les Textes et objet de la Piece 4
void TxtRoom4() {
	if (ActualFloor == 3) {
		cout << "les chasseurs rentre dans la pièce, de la poussière vole dans l’air et commence a former un tempête. La porte claque violemment derrière l’équipe." << endl << "Un etre fait de plasma apparait ! " << endl;
	}
	else if (ActualFloor == 4) {
		cout << "l’equipe ouvre le porte, de la lave coule des murs, la chaleurs est etouffante. L’equipe tentent de sortir quand la porte ce ferme violemment derriere eux." << endl << "Un etre fait de plasma apparait ! " << endl;
	}
}
//Choix de la Piece à visiter
void RoomToChoose(bool a, bool b, bool c, bool d) {
	cout << "Quelle Chambre voulez vous visiter ?" << endl << "Chambres Restantes :";
	if (a) {
		cout << "1  ";
	}
	if (b) {
		cout << "2  ";
	}
	if (c) {
		cout << "3  ";
	}
	if (ActualFloor >= 3 && d) {
		cout << "4  ";
	}
}
//Fonction d'un étage
void Floor() {
	int RoomLeft;
	int ChoosenRoom;
	bool Room1 = true;
	bool Room2 = true;
	bool Room3 = true;
	bool Room4 = true;
	if (ActualFloor >= 3) {
		RoomLeft = 4;
	}
	else {
		RoomLeft = 3;
	}
	while (RoomLeft > 0) {
		cout << "Etage" << ActualFloor << endl;
		RoomToChoose(Room1, Room2, Room3, Room4);
		cin >> ChoosenRoom;
		system("cls");
		if (ChoosenRoom <= 3 && ChoosenRoom >= 1) {
			if (Room1 && ChoosenRoom == 1) {
				TxtRoom1();
				//Combat
				Room1 = false;
				RoomLeft -= 1;
				suite();
				system("cls");
			}
			else if (Room2 && ChoosenRoom == 2) {
				TxtRoom2();
				//Combat
				Room2 = false;
				RoomLeft -= 1;
				suite();
				system("cls");
			}
			else if (Room3 && ChoosenRoom == 3) {
				TxtRoom3();
				//Combat
				Room3 = false;
				RoomLeft -= 1;
				suite();
				system("cls");
			}
		}
		else if (ActualFloor >= 3 && ChoosenRoom == 4)
		{
			if (Room4 && ChoosenRoom == 4) {
				TxtRoom4();
				//Combat
				Room4 = false;
				RoomLeft -= 1;
				suite();
				system("cls");

			}
		}

	}
	EndFloor();
}

int main() {
	while (demarrage != 1) {
		cout << "Bienvenue dans :" << endl;
		//insérer le titre et le logo
		cout << "Entrez 1 pour demarrer le jeu" << endl;
		cin >> demarrage;
	}

	cout << "Vous etes un groupe de 4 chasseur de Fantome : Jean le tank, Remi le mage, Xavier l assassin et Salim le bard" << endl;
	cout << "Votre but est de traverser les etages et de debarasser cet hôtel des spectres qui s'y trouve" << endl;
	suite();
	cout << "Apres une dizaines de minutes de route votre equipe de chasseur de fantomes descendit de leur voiture d’urgence et decouvrit le grand batiments qui, en quelques heure, a ete ravager part la horde de fantomes qui occupent maintenant les lieux." << endl;
	cout << "L equipe s’avance vers le hall d’entrer et entre dans le batiments. Les lumieres sont hors services et l’air est lourde, charger de peur et de plasma. " << endl;
	Floor();
	ActualFloor += 1;
	cout << "Etage 2" << endl;
	cout << "les chasseurs de fantomes arrivent sur le deuxieme pallier. La temperature baisse drastiquement, leurs souffles deviennent de la buee et leurs doigts s engourdisse. " << endl;
	Floor();
	ActualFloor += 1;
	cout << "Etage 3" << endl;
	cout << "les chasseurs de fantomes arrives sur l etage numero 3, du sable s’ecoule du plafond. De la poussier est en suspend dans l air et respirer ce fait difficile. L’escalier principale pour monter au premiere etage et bloquer par une montagne de sable, il va falloir trouver un autre passage " << endl;
	Floor();
	ActualFloor += 1;
	cout << "Etage 4" << endl;
	cout << "les chasseurs de fantomes arrives sur l etage numero 4, la chaleur ce fait insoutenable. L etage et en feu mais les flamme ne semble pas bruler la charpente, en effet seul les meubles sont en proie au feu pour le moment.Cependant L escalier principale est en flamme bloquant le passage a l equipe.Il faudrait passer par un autre endroit " << endl;
	Floor();
	cout << "les chasseurs de fantomes arrives sur le toit, l’air et frais et la brise et agreable comparer a la fournaise de l’etage precedant. Un frisson traverse l’echine de chaque membres de l’equipe." << endl << "Un cri terrifiant ce fait entendre.L’equipe ce retourne et tombe nez a nez avec un spectre a glacer le sang" << endl;


	return 0;
}


/*void defeat() {
	//Si tout les personnage <=0 alors
	cout << "Vous avez perdu" << endl;
}*/


