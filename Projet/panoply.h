/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */
#ifndef _PANOPLY_H_RPCGEN
#define _PANOPLY_H_RPCGEN

#include <rpc/rpc.h>

#define MONMAX 1000
#ifdef __cplusplus
extern "C" {
#endif


struct abonnement {
	int identifiant;
	char nomabn[100];
	int prix;
	int nombreCredit;
};
typedef struct abonnement abonnement;
abonnement tableauAbonnement[MONMAX];
static int globaleAbonnement=0;

enum typeCompte {
	client = 0,
	gestionnaire = 1,
};
typedef enum typeCompte typeCompte;


enum step {
	engage = 0,
	abonne = 1,
	resilie = 2,
};
typedef enum step step;


struct date {
	int jour;
	int mois;
	int annee;
};
typedef struct date date;


struct engagement {
	abonnement abn;
	date debut;
	date fin;
	step etat;
};
typedef struct engagement engagement;


struct compte {
	char nom[100];
	char prenom[100];
	int identifiant;
	char mdp[32];
	char adresse[250];
	engagement monEngagement;
	typeCompte monType;
};
typedef struct compte compte;
static compte compteTmp;

compte tableauCompte [MONMAX];
static int globaleCompte=0;

struct collection {
	char nomCollection[100];
	int idCollection;
};
typedef struct collection collection;

collection tableauCollection [MONMAX];
static int globaleCollection=0;


struct marque {
	char nomMarque[100];
	int idMarque;
};
typedef struct marque marque;
marque tableauMarque [MONMAX];
static int globaleMarque=0;

struct occasion {
	char nomOccasion[100];
	int idOccasion;
};
typedef struct occasion occasion;
occasion tableauOccasion [MONMAX];
static int globaleOccasion=0;

struct vetement {
	char nomVetement[100];
	int prixVetement;
	int nbCredit;
	int idVetement;
	int nbExemplaire;
	collection maCollection;
	marque maMarque;
	occasion monOccasion;
};
typedef struct vetement vetement;

vetement tableauVetement [MONMAX];
static int globaleVetement=0;


struct tj_vetement_collection {
	vetement vetement_de_la_collection[1000];
	int nombre;
};
typedef struct tj_vetement_collection tj_vetement_collection;


struct tj_vetement_marque {
	vetement vetement_de_la_marque[1000];
	int nombre;
};
typedef struct tj_vetement_marque tj_vetement_marque;



struct tj_vetement_occasion {
	vetement vetement_de_l_occasion[1000];
	int nombre;
};
typedef struct tj_vetement_occasion tj_vetement_occasion;


enum stepLocation {
	louer = 0,
	rendu = 1,
};
typedef enum stepLocation stepLocation;


struct location {
	date debut_location;
	date fin_location;
	stepLocation etatDeLaLocation;
	int identifiantClient;
	int identifiantVetement;
	int identifiantLocation;
};
typedef struct location location;
static int globaleLocation=0;

enum boolean {
	false = 0,
	true = 1,
};
typedef enum boolean boolean;

#define PANOPLYPROG 0x23456780
#define PANOPLYVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define CREERCOMPTE 1
extern  boolean * creercompte_1(compte *, CLIENT *);
extern  boolean * creercompte_1_svc(compte *, struct svc_req *);
#define SECONNECTER 2
extern  boolean * seconnecter_1(compte *, CLIENT *);
extern  boolean * seconnecter_1_svc(compte *, struct svc_req *);
#define AFFICHERCOMPTE 3
extern  compte * affichercompte_1(int *, CLIENT *);
extern  compte * affichercompte_1_svc(int *, struct svc_req *);
#define NOMBRECOMPTE 4
extern  int * nombrecompte_1(void *, CLIENT *);
extern  int * nombrecompte_1_svc(void *, struct svc_req *);
#define CREERABONNEMENT 5
extern  boolean * creerabonnement_1(abonnement *, CLIENT *);
extern  boolean * creerabonnement_1_svc(abonnement *, struct svc_req *);
#define NOMBREABONNEMENT 6
extern  int * nombreabonnement_1(void *, CLIENT *);
extern  int * nombreabonnement_1_svc(void *, struct svc_req *);
#define AFFICHERABONNEMENT 7
extern  abonnement * afficherabonnement_1(int *, CLIENT *);
extern  abonnement * afficherabonnement_1_svc(int *, struct svc_req *);
#define MAJUNABONNEMENT 8
extern  boolean * majunabonnement_1(abonnement *, CLIENT *);
extern  boolean * majunabonnement_1_svc(abonnement *, struct svc_req *);
#define AFFECTATIONABONNEMENT 9
extern  boolean * affectationabonnement_1(compte *, CLIENT *);
extern  boolean * affectationabonnement_1_svc(compte *, struct svc_req *);
#define CREERCOLLECTION 10
extern  boolean * creercollection_1(collection *, CLIENT *);
extern  boolean * creercollection_1_svc(collection *, struct svc_req *);
#define NOMBRECOLLECTION 11
extern  int * nombrecollection_1(void *, CLIENT *);
extern  int * nombrecollection_1_svc(void *, struct svc_req *);
#define AFFICHERCOLLECTION 12
extern  collection * affichercollection_1(int *, CLIENT *);
extern  collection * affichercollection_1_svc(int *, struct svc_req *);
#define ASSOCIERVETEMENTCOLLECTION 13
extern  boolean * associervetementcollection_1(vetement *, CLIENT *);
extern  boolean * associervetementcollection_1_svc(vetement *, struct svc_req *);
#define CREERVETEMENT 14
extern  boolean * creervetement_1(vetement *, CLIENT *);
extern  boolean * creervetement_1_svc(vetement *, struct svc_req *);
#define AFFICHERVETEMENT 15
extern  vetement * affichervetement_1(int *, CLIENT *);
extern  vetement * affichervetement_1_svc(int *, struct svc_req *);
#define NOMBREVETEMENT 16
extern  int * nombrevetement_1(void *, CLIENT *);
extern  int * nombrevetement_1_svc(void *, struct svc_req *);
#define LOUERVETEMENT 17
extern  boolean * louervetement_1(location *, CLIENT *);
extern  boolean * louervetement_1_svc(location *, struct svc_req *);
#define NOMBRELOCATION 18
extern  int * nombrelocation_1(void *, CLIENT *);
extern  int * nombrelocation_1_svc(void *, struct svc_req *);
#define AFFICHERLOCATION 19
extern  location * afficherlocation_1(int *, CLIENT *);
extern  location * afficherlocation_1_svc(int *, struct svc_req *);
extern int panoplyprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define CREERCOMPTE 1
extern  boolean * creercompte_1();
extern  boolean * creercompte_1_svc();
#define SECONNECTER 2
extern  boolean * seconnecter_1();
extern  boolean * seconnecter_1_svc();
#define AFFICHERCOMPTE 3
extern  compte * affichercompte_1();
extern  compte * affichercompte_1_svc();
#define NOMBRECOMPTE 4
extern  int * nombrecompte_1();
extern  int * nombrecompte_1_svc();
#define CREERABONNEMENT 5
extern  boolean * creerabonnement_1();
extern  boolean * creerabonnement_1_svc();
#define NOMBREABONNEMENT 6
extern  int * nombreabonnement_1();
extern  int * nombreabonnement_1_svc();
#define AFFICHERABONNEMENT 7
extern  abonnement * afficherabonnement_1();
extern  abonnement * afficherabonnement_1_svc();
#define MAJUNABONNEMENT 8
extern  boolean * majunabonnement_1();
extern  boolean * majunabonnement_1_svc();
#define AFFECTATIONABONNEMENT 9
extern  boolean * affectationabonnement_1();
extern  boolean * affectationabonnement_1_svc();
#define CREERCOLLECTION 10
extern  boolean * creercollection_1();
extern  boolean * creercollection_1_svc();
#define NOMBRECOLLECTION 11
extern  int * nombrecollection_1();
extern  int * nombrecollection_1_svc();
#define AFFICHERCOLLECTION 12
extern  collection * affichercollection_1();
extern  collection * affichercollection_1_svc();
#define ASSOCIERVETEMENTCOLLECTION 13
extern  boolean * associervetementcollection_1();
extern  boolean * associervetementcollection_1_svc();
#define CREERVETEMENT 14
extern  boolean * creervetement_1();
extern  boolean * creervetement_1_svc();
#define AFFICHERVETEMENT 15
extern  vetement * affichervetement_1();
extern  vetement * affichervetement_1_svc();
#define NOMBREVETEMENT 16
extern  int * nombrevetement_1();
extern  int * nombrevetement_1_svc();
#define LOUERVETEMENT 17
extern  boolean * louervetement_1();
extern  boolean * louervetement_1_svc();
#define NOMBRELOCATION 18
extern  int * nombrelocation_1();
extern  int * nombrelocation_1_svc();
#define AFFICHERLOCATION 19
extern  location * afficherlocation_1();
extern  location * afficherlocation_1_svc();
extern int panoplyprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_abonnement (XDR *, abonnement*);
extern  bool_t xdr_abonnement (XDR *, abonnement*);
extern  bool_t xdr_typeCompte (XDR *, typeCompte*);
extern  bool_t xdr_typeCompte (XDR *, typeCompte*);
extern  bool_t xdr_step (XDR *, step*);
extern  bool_t xdr_step (XDR *, step*);
extern  bool_t xdr_date (XDR *, date*);
extern  bool_t xdr_date (XDR *, date*);
extern  bool_t xdr_engagement (XDR *, engagement*);
extern  bool_t xdr_engagement (XDR *, engagement*);
extern  bool_t xdr_compte (XDR *, compte*);
extern  bool_t xdr_compte (XDR *, compte*);
extern  bool_t xdr_collection (XDR *, collection*);
extern  bool_t xdr_collection (XDR *, collection*);
extern  bool_t xdr_marque (XDR *, marque*);
extern  bool_t xdr_marque (XDR *, marque*);
extern  bool_t xdr_occasion (XDR *, occasion*);
extern  bool_t xdr_occasion (XDR *, occasion*);
extern  bool_t xdr_vetement (XDR *, vetement*);
extern  bool_t xdr_vetement (XDR *, vetement*);
extern  bool_t xdr_tj_vetement_collection (XDR *, tj_vetement_collection*);
extern  bool_t xdr_tj_vetement_marque (XDR *, tj_vetement_marque*);
extern  bool_t xdr_tj_vetement_occasion (XDR *, tj_vetement_occasion*);
extern  bool_t xdr_stepLocation (XDR *, stepLocation*);
extern  bool_t xdr_stepLocation (XDR *, stepLocation*);
extern  bool_t xdr_location (XDR *, location*);
extern  bool_t xdr_location (XDR *, location*);
extern  bool_t xdr_boolean (XDR *, boolean*);
extern  bool_t xdr_boolean (XDR *, boolean*);

#else /* K&R C */
extern bool_t xdr_abonnement ();
extern bool_t xdr_abonnement ();
extern bool_t xdr_typeCompte ();
extern bool_t xdr_typeCompte ();
extern bool_t xdr_step ();
extern bool_t xdr_step ();
extern bool_t xdr_date ();
extern bool_t xdr_date ();
extern bool_t xdr_engagement ();
extern bool_t xdr_engagement ();
extern bool_t xdr_compte ();
extern bool_t xdr_compte ();
extern bool_t xdr_collection ();
extern bool_t xdr_collection ();
extern bool_t xdr_marque ();
extern bool_t xdr_marque ();
extern bool_t xdr_occasion ();
extern bool_t xdr_occasion ();
extern bool_t xdr_vetement ();
extern bool_t xdr_vetement ();
extern bool_t xdr_tj_vetement_collection ();
extern bool_t xdr_tj_vetement_marque ();
extern bool_t xdr_tj_vetement_occasion ();
extern bool_t xdr_stepLocation ();
extern bool_t xdr_stepLocation ();
extern bool_t xdr_location ();
extern bool_t xdr_location ();
extern bool_t xdr_boolean ();
extern bool_t xdr_boolean ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PANOPLY_H_RPCGEN */
