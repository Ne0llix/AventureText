#include <iostream>
#include "Personnage.h"
#include "Fantome.h"
#include "Inventaire.h"
#include "PersonnageTank.h"
#include <vector>

using namespace std;

//Debut -> Variable choix -> Variable Etage -> Variable Event Rdm -> Fin
//Jet de dé simplifié (réussite, échec) (critique ou non)
//Faire Inventaire en appuyant sur "E"
//Fonction Cuisine en tapant "KOUIZINE"
//Faire fonction combat avec (ATK, SOIN, ATK MAG, CHANT, FUITE)
//Faire un GAME OVER
Inventaire i1("Canette de Soda", 1, 20);
Inventaire i2("barre de cereale", 1, 25);
Inventaire i3("Paquet de Gateaux", 1, 30);
Inventaire i4("Gateaux", 3, 10);
Inventaire i5("Popcorn", 4, 10);

PersonnageTank pt1;
Personnage p2("Remi", "Mage", "Homme", 40, 175, 100,100, 60, 90, "Moteur ireel", 20, "De taille moyenne, Remi se moque de l'Unité, dans l'église de l'Ireel, il est un element moteur du groupe grace a sa magie de force C++.", false);
Personnage p3("Xavier", "Assassin", "Homme", 45, 175, 90,90, 70, 105, "Mise en scene", 25, "Discret et observateur, Xavier trouve son bonheur dans l'anthropologie et les reactions humaines, c'est tirant partie de ses qualites qu'il a appris a parfaire ses techniques de vol.", false);
Personnage p4("Salim", "Barde", "Homme", 45, 180, 75,75, 60, 70, "Chant de destruction", 30, "Bien que n'aimant pas ce terme, Salim est un artiste dans l'ame, au dessin ou a l'ecriture il se passionne reellement. C'est donc logique qu'il soit devenu le barde du groupe.", false);

Fantome f1("Fantome normal", 100, 120,120, 60, 20, "Ce fantome degouline de plasma, il ne semble pas tres fort mais vous ne le sous - estimez pas pour autant.Vous faites face a votre peur.");
Fantome f2("Fantome d'eau", 90, 140, 140,40, 40, "Ce fantome degouline de plasma et d'eau, il semble intangible. Vous vous demandez si vous seriez gluant ou mouille a son contact.");
Fantome f3("Fantome de glace", 110, 120,120, 35, 50, "Ce fantome ne degouline pas, il semble comme fige dans la glace. Vous n'aimeriez qu'un de ses stalagtite vous tombe dessus.");
Fantome f4("Fantome de feu", 100, 90,90, 40, 30, "Ce fantome semble bruler a chaudes flammes, sa chaleur vous empeche de vous apprcher plus. Vous vous sentez comme dans une vraie fournaise.");
Fantome f5("Fantome de sable", 100, 105,105, 40, 30, "Ce fantome degouline de plasma et de sable, il semble a la fois palpable et intangible. Vous n'aimeriez pas l'avoir dans votre chaussure.");
Fantome f6("Boss des fantomes", 200, 300,300, 60, 55, "Ce fantome est gigantesque, il semble capable de se battre aussi bien que tous les autres fantomes reunis, attention. Votre peur augmente mais vous y faites face.");

std::vector<Inventaire*> Inventory;
std::vector<Personnage*> Chara;
std::vector<Fantome*> Ghost;
int demarrage = 0;
int piece;
string continuer;
int personnage;
int fantome;
int ActualFloor = 1;
int ChoosenItem;
int Ennemi;
int EnnemiNb;
int Character;
bool FightAction= false;
int FightChoice;
int ActualChara = 0;
bool CanGhostAttack;
int DeathNB;


//Fonction Servant au joueur de passer à la suite du jeu
void suite() {
	while (continuer != "suite") {
		cout << "Tapez 'suite' pour continuer" << endl;
		cin >> continuer;
		if (continuer == "suite") {
			system("cls");

		}
	}
	continuer = "t";
}
void GestionInventaire() {
	do {
		cout << "Quelle item voulez-vous utiliser ? :" << endl;
		for (int i = 0; i < Inventory.size(); i++) {
			cout << i + 1 << "." << Inventory[i]->GetName() << " x" << Inventory[i]->GetNombre() << " " << Inventory[i]->GetSoin() << "PV" << "    ";

		}
		cout << Inventory.size() + 1 << "." << "ou plus pour revenir en arriere" << endl;
		cin >> ChoosenItem;
	} while (ChoosenItem < 1);



	ChoosenItem -= 1;
	if (ChoosenItem == Inventory.size()) {
		FightAction = false;
		return;
	}
	else if (Inventory[ChoosenItem]->GetNombre() <= 0) {
		cout << "Vous n'avez plus assez de cet objet" << endl;
		FightAction = false;
		return;
	}
	else {
		Inventory[ChoosenItem]->UseObject();
		cout << "Vous avez utilise " << Inventory[ChoosenItem]->GetName() << " et avez recupere " << Inventory[ChoosenItem]->GetSoin() << "PV" << endl;
		Chara[ActualChara]->ReceiveHeal(Inventory[ChoosenItem]->GetSoin());
		FightAction = true;
	}

}
void Combat() {
	ActualChara = 0;
	cout << "Un ennemi se dresse devant vous" << endl;
	while (Ghost[0]->getHealth() > 0) {
		do {
			if (Chara[ActualChara]->getIsDead() == false ){
				FightAction = false;
				FightChoice = 0;
				cout << "c'est au tour de " << Chara[ActualChara]->getName() << ", que souhaitez-vous faire ?" << endl;
				cout << "1 : Attaque - 2 : Inventaire - 3 : Informations sur l'ennemi - 4 : Informations sur l'equipe" << endl;
				cin >> FightChoice;
				if (FightChoice == 1) {
					cout << "Vous attaquez le fantome " << Ghost[0]->getElementType_ToString() << " ennemi" << endl;
					cout << "il perd " << Chara[ActualChara]->getAttack() - Ghost[0]->getDefense() << " pv" << endl;
					Ghost[0]->ReceiveAttack(Chara[ActualChara]->getAttack());
					FightAction = true;
				}
				else if (FightChoice == 2) {
					cout << "vous ouvrez votre inventaire" << endl;
					GestionInventaire();
				}
				else if (FightChoice == 3) {
					cout << "vous décidez d'en apprendre plus sur l'ennemi : " << endl;
					cout << Ghost[Ennemi]->getElementType_ToString() << endl;
					cout << Ghost[Ennemi]->getSize() << endl;
					cout << Ghost[Ennemi]->getDescription() << endl;
					cout << Ghost[Ennemi]->getHealth() << endl;
					cout << Ghost[Ennemi]->getAttack() << endl;
					cout << Ghost[Ennemi]->getDefense() << endl;
				}
				else if (FightChoice == 4) {
					cout << "Voici les informations de votre equipe :" << endl;
					for (int i = 0; i < 4; i++) {
						cout << Chara[i]->getName() << " : " << endl;
						cout << Chara[i]->getHealth() << " Pv Actuel" << endl;
						cout << Chara[i]->getMaxHealth() << " Pv Max" << endl;
						cout << Chara[i]->getDefense() << " Point de defense" << endl;
						cout << Chara[i]->getAttack() << " Point d'attaque" << endl;
					}
				}
			}
			else {
				FightAction = true;
				FightChoice = 1;
			}
			
		} while (FightChoice != (1, 2, 3,4) && !FightAction);
		if (ActualChara != 3) {
			ActualChara += 1;
		}
		else {
			ActualChara = 0;
			CanGhostAttack = true;
		}
		if (Ghost[0]->getHealth() > 0&& CanGhostAttack) {
			cout << "Le fantome vous attaque !" << endl;
			CanGhostAttack = false;
			DeathNB = 0;
			for (int i = 0; i < 4; i++) {
				if (Chara[i]->getIsDead() == false) {
					Chara[i]->ReceiveAttack(Ghost[0]->getAttack());
					cout << Chara[i]->getName() << " perd " << Ghost[0]->getAttack() - Chara[i]->getDefense() << " Pv" << endl;
				}
				if (Chara[i]->getHealth() <= 0) {
					cout << Chara[i]->getName() << " est mort et ne peut plus se battre" << endl;
					Chara[i]->setIsDead(true);
					DeathNB += 1;
				}
			}
		}
		if (DeathNB == 4) {
			cout << "l equipe a perit , le lieux n a pas ete exorciser,  les fantomes enerves de l arriver des chasseurs ont commencer a ce multiplier et a infecter d’autres batiments avant d envahir la ville en entier. L equipe sera a jamais vue comme les responsables de le mort de million de personnes " << endl;
			suite();
			abort;
		}
		suite();
		system("cls");
		
	}
	cout << "Bravo, vous avez vaincu le fantome de type " << Ghost[0]->getElementType_ToString() << endl;

}
//Fonction pour lancer le texte de chaque fin d'étage
void EndFloor() {
	if (ActualFloor == 1) {
		cout << "L'eau arrete de couler des murs et s'ecoule par l'escalier, l'equipe prend les escaliers et se rend a l'etage du dessus. " << endl;
		Ghost.pop_back();
		Ghost.push_back(&f3);
	}
	else if (ActualFloor == 2) {
	cout << "La temperature remonte de cinq degres Celsius et la neige fond a vue d oeil. L equipe s avance vers les escaliers . " << endl;
	Ghost.pop_back();
	Ghost.push_back(&f5);
	}
	else if (ActualFloor == 2) {
		cout << "les chasseurs de fantomes sortent de la derniere piece, il remarque que le sable commence a s’evaporer  par le plancher cependant l escalier reste inaccessible " << endl;
		Ghost.pop_back();
		Ghost.push_back(&f4);
	}
	else if (ActualFloor == 4) {
		cout << "la chaleur commence a s’attenuer, neanmoins les flamme ont rendu l’escalier principale trop fragile pour que l’on puis l’utiliser " << endl;
		Ghost.pop_back();
		Ghost.push_back(&f6);
	}
}
//Tout les Textes et objet de la Piece 1 en fonction de l'étage
void TxtRoom1() {
	if (ActualFloor == 1) {
		cout << "Votre equipe ouvre la porte de la premiere chambre du pallier, vous entrez en pataugeant dans l eau. Vous vous rendez compte que le liquide jaillit du sol de la piece quand tout d'un coup, la porte se claque derriere vous." << endl << "Un etre fait de plasma apparait ! " << endl;
		Combat();
		Ghost[0]->setHealth(Ghost[0]->getMaxHealth());
	}
	else if (ActualFloor == 2) {
		cout << "Les chasseurs de fantomes entrent dans la piece, sur une table ils trouvent un paquet de gateaux." << endl;
		Inventory.push_back(&i3);
	}
	else if (ActualFloor == 3) {
		cout << "L’equipe rentre dans la piece avec difficulte, le sable genant la progression. Un drole de sentiment s’empare des chasseurs quand soudain la porte se ferme violemment derriere vous." << endl << "Un etre fait de plasma apparait !" << endl;
		Combat();
		Ghost[0]->setHealth(Ghost[0]->getMaxHealth());
	}
	else if (ActualFloor == 4) {
		cout << "Vous entrez dans la piece, trouvez une cle par terre et ressortez" << endl;
	}
}
//Tout les Textes et objet de la Piece 2
void TxtRoom2() {
	if (ActualFloor == 1) {
		cout << "les chasseurs de fantomes entrent dans la chambre numero deux, dans une table de chevet ils trouvent un barre de cereale " << endl;
		Inventory.push_back(&i2);
	}
	else if (ActualFloor == 2) {
		cout << "L’equipe ouvre le porte, Un vent glaciale sabbat sur eux. Le lieux est completement givre et des cristaux ce forme au plafond. Un bruit attire leurs regards, quand tout d’un coup  la porte ce claque derrière eux." << endl << "Un etre fait de plasma apparait !" << endl;
		Combat();
		Ghost[0]->setHealth(Ghost[0]->getMaxHealth());
	}
	else if (ActualFloor == 3) {
		cout << "Une table plein de petits gateaux se trouve au milieu de la piece, seulement trois ne sont pas recouverts de sable. " << endl;
		Inventory.push_back(&i4);
	}
	else if (ActualFloor == 4) {
		cout << "L’equipe rentre dans la chambre, quatre paquets de pop-corn sont places sur une table en feu, des petit « pop » « pop » arrives au oreilles des chasseurs, vous prenez les paquets pres et ressortez. " << endl;
		Inventory.push_back(&i5);
	}
}
//Tout les Textes et objet de la Piece 3
void TxtRoom3() {
	if (ActualFloor == 1) {
		cout << "L'equipe et vous-même ouvrez la porte de la troisieme chambre du pallier, vous entrez en pataugeant dans l'eau. Vous vous rendez compte que le liquide coule des murs de la piece quand tout d'un coup, la porte se claque derriere vous." << endl << "Un etre fait de plasma apparait ! " << endl;
		Combat();
		Ghost[0]->setHealth(Ghost[0]->getMaxHealth());
	}
	else if (ActualFloor == 2) {
		cout << "Votre equipe ouvre la porte, de la neige tombe dans la salle. Le lieu est completement enneige. La porte se ferme violemment derriere vous." << endl << "Un etre fait de plasma apparait ! " << endl;
		Combat();
		Ghost[0]->setHealth(Ghost[0]->getMaxHealth());
	}
	else if (ActualFloor == 3) {
		cout << "Les chasseurs fouillent la chambre en quete d’objet interessant, dans une armoire vous trouvez une cle et sortez de la piece " << endl;
		Combat();
		Ghost[0]->setHealth(Ghost[0]->getMaxHealth());
	}
	else if (ActualFloor == 4) {
		cout << "L’equipe ouvre la porte, des flammes leur brulent legerement les habits ,le lieux est completement en feu. La porte se ferme violemment derriere vous." << endl << "Un etre fait de plasma apparait !" << endl;
		Combat();
		Ghost[0]->setHealth(Ghost[0]->getMaxHealth());
	}
}
//Tout les Textes et objet de la Piece 4
void TxtRoom4() {
	if (ActualFloor == 3) {
		cout << "Vous et les chasseurs rentrez dans la pièce, de la poussière vole dans l’air et commence a former une tempête. La porte claque violemment derriere l’equipe." << endl << "Un etre fait de plasma apparait ! " << endl;
		Combat();
		Ghost[0]->setHealth(Ghost[0]->getMaxHealth());
	}

	else if (ActualFloor == 4) {
		cout << "L’equipe ouvre le porte, de la lave coule des murs, la chaleurs est etouffante. Vous tentez de sortir quand la porte se ferme violemment derriere vous." << endl << "Un etre fait de plasma apparait ! " << endl;
		Combat();
		Ghost[0]->setHealth(Ghost[0]->getMaxHealth());
	}
}
//Choix de la Piece à visiter
void RoomToChoose(bool a, bool b, bool c, bool d) {
	cout << "Quelle Chambre voulez-vous visiter ?" << endl << "Chambres Restantes :";
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
//L'inventaire de l'équipe en temps réel





int main() {
	Chara.push_back(&pt1);
	Chara.push_back(&p2);
	Chara.push_back(&p3);
	Chara.push_back(&p4);


	while (demarrage != 1) {
		cout << "Bienvenue dans :" << endl;
		//insérer le titre et le logo
		cout << "Entrez 1 pour demarrer le jeu" << endl;
		cin >> demarrage;
	}

	cout << "Vous etes un groupe de 4 chasseurs de Fantomes : Jean le tank, Remi le mage, Xavier l assassin et Salim le barde" << endl;
	cout << "Votre but est de traverser les etages et de debarasser cet hotel des spectres qui s'y trouve" << endl;
	suite();
	cout << "Apres une dizaine de minutes de route votre equipe de chasseurs de fantomes descend de leur voiture d’urgence et decouvre le grand batiment qui, en quelques heures, a ete ravage par la horde de fantomes qui occupent maintenant les lieux." << endl;
	cout << "Vous avancez vers le hall d’entree et entre dans le batiment. Les lumieres sont hors service et l’air est lourd, charge de peur et de plasma. " << endl;
	Ghost.push_back(&f2);
	Floor();
	ActualFloor += 1;
	cout << "Etage 2" << endl;
	cout << "Votre equipe et vous arrivez sur le deuxieme pallier. La temperature baisse drastiquement, vos souffles deviennent de la buee et vos doigts s'engourdissent. " << endl;
	Floor();
	ActualFloor += 1;
	cout << "Etage 3" << endl;
	cout << "Vous arrivez avec votre groupe au troisieme etage, du sable s’ecoule du plafond. De la poussiere est en suspend dans l'air et respirer se fait difficile. L’escalier principal pour monter au prochain etage est bloque par une montagne de sable, il va falloir trouver un autre passage " << endl;
	Floor();
	ActualFloor += 1;
	cout << "Etage 4" << endl;
	cout << "Vous atteignez l'etage numero 4, la chaleur se fait insoutenable. L'etage est en feu mais les flammes ne semblent pas bruler la charpente, en effet seuls les meubles sont en proie au feu pour le moment. Cependant l'escalier principal est en flammes bloquant le passage a l'equipe. Il faudrait passer par un autre endroit " << endl;
	Floor();
	cout << "Vous arrivez enfin sur le toit, l’air est frais et la brise est agreable comparee a la fournaise de l’etage precedent. Un frisson traverse l’echine de chaque membre de l’equipe." << endl << "Un cri terrifiant se fait entendre. L’equipe se retourne et tombe nez a nez avec un spectre a glacer le sang" << endl;
	Combat();
	cout << "Vous avez reussi a vaincre tout les spectres du batiment ! vous avez sauver le monde, Bravo !" << endl;

	return 0;
}
