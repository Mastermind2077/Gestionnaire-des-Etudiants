#include <iostream>
#include <string>

using namespace std;

class Etudiant {
public:
    string matricule;
    string nom;
    string prenom;
    char sexe;
    int age;
    float note1;
    float note2;
    float note3;
    Etudiant* suivant;

    Etudiant(string m, string n, string p, char s, int a, float n1, float n2, float n3)
        : matricule(m), nom(n), prenom(p), sexe(s), age(a), note1(n1), note2(n2), note3(n3), suivant(nullptr) {}
};

class ListeEtudiants {
private:
    Etudiant* tete;
public:
    ListeEtudiants() : tete(nullptr) {}

    void ajouterEtudiant() {
        string matricule, nom, prenom;
        char sexe;
        int age;
        float note1, note2, note3;

        cout << "Entrez le matricule: ";
        cin >> matricule;
        cout << "Entrez le nom: ";
        cin >> nom;
        cout << "Entrez le prenom: ";
        cin >> prenom;
        cout << "Entrez le sexe (M/F): ";
        cin >> sexe;
        cout << "Entrez l'age: ";
        cin >> age;
        cout << "Entrez la note 1: ";
        cin >> note1;
        cout << "Entrez la note 2: ";
        cin >> note2;
        cout << "Entrez la note 3: ";
        cin >> note3;

        Etudiant* nouveau = new Etudiant(matricule, nom, prenom, sexe, age, note1, note2, note3);
        nouveau->suivant = tete;
        tete = nouveau;

        cout << "Etudiant ajoute avec succes!\n";
    }

    void mettreAJourEtudiant() {
        string matricule;
        cout << "Entrez le matricule de l'etudiant a mettre a jour: ";
        cin >> matricule;

        Etudiant* courant = tete;
        while (courant != nullptr) {
            if (courant->matricule == matricule) {
                cout << "Entrez le nouveau nom: ";
                cin >> courant->nom;
                cout << "Entrez le nouveau prenom: ";
                cin >> courant->prenom;
                cout << "Entrez le nouveau sexe (M/F): ";
                cin >> courant->sexe;
                cout << "Entrez le nouvel age: ";
                cin >> courant->age;
                cout << "Entrez la nouvelle note 1: ";
                cin >> courant->note1;
                cout << "Entrez la nouvelle note 2: ";
                cin >> courant->note2;
                cout << "Entrez la nouvelle note 3: ";
                cin >> courant->note3;
                cout << "Etudiant mis a jour avec succes!\n";
                return;
            }
            courant = courant->suivant;
        }
        cout << "Etudiant non trouve.\n";
    }

    void supprimerEtudiant() {
        string matricule;
        cout << "Entrez le matricule de l'etudiant a supprimer: ";
        cin >> matricule;

        Etudiant* courant = tete;
        Etudiant* precedent = nullptr;
        while (courant != nullptr) {
            if (courant->matricule == matricule) {
                if (precedent == nullptr) {
                    tete = courant->suivant;
                } else {
                    precedent->suivant = courant->suivant;
                }
                delete courant;
                cout << "Etudiant supprime avec succes!\n";
                return;
            }
            precedent = courant;
            courant = courant->suivant;
        }
        cout << "Etudiant non trouve.\n";
    }

    void afficherMenu() {
        int choix;
        do {
            cout << "\nMenu:\n";
            cout << "1 - Ajouter un etudiant\n";
            cout << "2 - Mettre a jour un etudiant\n";
            cout << "3 - Supprimer un etudiant\n";
            cout << "4 - Quitter\n";
            cout << "Entrez votre choix: ";
            cin >> choix;
            switch (choix) {
                case 1:
                    ajouterEtudiant();
                    break;
                case 2:
                    mettreAJourEtudiant();
                    break;
                case 3:
                    supprimerEtudiant();
                    break;
                case 4:
                    cout << "Au revoir!\n";
                    break;
                default:
                    cout << "Choix invalide. Veuillez reessayer.\n";
            }
        } while (choix != 4);
    }
};

int main() {
    ListeEtudiants liste;
    liste.afficherMenu();
    return 0;
}
