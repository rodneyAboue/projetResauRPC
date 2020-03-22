enum MEMBER_TYPE {
  ADMIN,
  VISITOR
};
typedef enum MEMBER_TYPE MEMBER_TYPE;

enum RENTAL_STATE {
  RENTED,
  BACK
};
typedef enum RENTAL_STATE RENTAL_STATE;

struct date_t {
  int day;
  int month;
  int year;
};

/* Définition des types d'abonnements possibles. */
struct subscription_t {
  int type;
  int credits;
  int price;
};

/* Définition du type representant l'activité mensuelle d'un utilisateur */
/* Il comprend: */
/* - Le nombre de crédits maximal par mois en fonction de l'abonnement */
/* - Le nombre de crédits utilisé */
/* - L'activité pour le mois suivant */
/* - Si aucune activité n'est éffectuée ce mois, le nombre de crédits restant */
/*    sera transféré au mois suivant. */
struct member_activity_t {
  int total_credits;
  int current_usage;

  date_t start_date;
  date_t end_date;
};

/* Définition des abonnements d'un utilisateur. */
struct member_subscription_t {
  int is_valid;
  subscription_t * subscription;

  member_activity_t first_month;
  member_activity_t second_month;
  member_activity_t third_month;
};


/* Un utililsateur. */
struct member_t {
  int id;
  char first_name[10];
  char last_name[50];
  char user_name[10];
  /* Not a real word project :) :) */
  char password[32];
  char address[250];

  MEMBER_TYPE type;
  member_subscription_t subscription;
};

/* Une collection */
struct collection_t {
  int id;
  char name[50];
};

/* Une occasion */
struct occasion_t {
  int id;
  char name[50];
};

/* Une marque */
struct brand_t {
  int id;
  char name[50];
};

/* Un vêtement */
struct cloth_t {
  int id;
  char name[50];
  int price;
  int credits;
  int stock;

  collection_t * collection;
  occasion_t * occasion;
  brand_t * brand;
};

/* Une location */
struct rental_t {
  int id;
  cloth_t * cloth;
  RENTAL_STATE rental_state;
};

/* Structure representant en quelques sortes une table de collections. */
struct collections_list_t {
  collection_t data[100];
  int last_inserted;
};

/* Table des occasions. */
struct occasions_list_t {
  occasion_t data[100];
  int last_inserted;
};

/* Table des marques. */
struct brands_list_t {
  brand_t data[100];
  int last_inserted;
};

/* Table des vêtemements. */
struct clothes_list_t {
  cloth_t data[100];
  int last_inserted;
};

/* Table des locations. */
struct rentals_list_t {
  rental_t data[100];
  int last_inserted;
};

/* Table des membres. */
struct members_list_t {
  member_t data[100];
  int last_inserted;
};

/* Table des abonnements */
struct subscriptions_list_t {
  subscription_t data[10];
  int last_inserted;
};

/* Définition des paramêtres des fonctions */
struct new_member_params {
    char first_name[10];
    char last_name[50];
    char user_name[10];
    char password[32];
    char address[250];
};

struct login_member_params {
  char user_name[10];
  char password[32];
};

struct new_collection_params {
  char name[50];
};

struct new_clothing_params {
  char name[50];
  int price;
  int credits;
  int stock;
};

struct set_member_subscription_params {
  int member_id;
  int subscription_id;
};

struct set_clothing_collection_params {
  int clothing_id;
  int collection_id;
};

program PANOPLYPROG {
  version PANOPLYVERS {

    /* Créer un membre */
    int REGISTER(new_member_params) = 1;

    /* Connexion */
    int LOGIN(login_member_params) = 2;

    /* Nombre total d'utilisateurs. */
    int TOTAL_MEMBERS() = 3;

    /* Affichage d'un membre. */
    member_t SHOW_MEMBER(int) = 4;

    /* Gestion des abonnements. */
    /* Nouvel abonnement. */
    int NEW_SUBSCRIPTION(subscription_t) = 5;

    /* Nombre total d'abonnements */
    int TOTAL_SUBSCRIPTIONS() = 6;

    /* Details d'un abonnement */
    subscription_t SHOW_SUBSCRIPTION(int) = 7;

    /* Mise à jour d'un abonnement. */
    int UPDATE_SUBSCRIPTION(subscription_t) = 8;

    /* Affectation d'un abonnement à un membre. */
    int SET_MEMBER_SUBSCRIPTION(set_member_subscription_params) = 9;

    /* Nouvelle collection. */
    int NEW_COLLECTION(new_collection_params) = 10;

    /* Nombre de collections */
    int TOTAL_COLLECTIONS() = 11;

    /* Affichage d'une collection. */
    collection_t SHOW_COLLECTION(int) = 12;

    /* Associer un vêtement à une collection. */
    /* @param collection_id: identifiant de la collection. */
    /* @param clothing_id: identifiant du vêtement. */
    int SET_CLOTHING_COLLECTON(set_clothing_collection_params) = 13;

    /* Nouveau vêtement. */
    int NEW_CLOTHING(new_clothing_params) = 14;

    /* Nombre total de vêtements. */
    int TOTAL_CLOTHINGS() = 15;

    /* Affichage d'un vêtement. */
    cloth_t SHOW_CLOTHING(int) = 16;

    /* Location d'un vêtement. */
    int RENT_CLOTHING(int) = 17;

    /* Nombre total de locations. */
    int TOTAL_RENTS() = 18;

    /* Afficher une location. */
    rental_t SHOW_RENTAL(int) = 19;

    /* Afficher la liste des vêtements */
    clothes_list_t  LIST_CLOTHES() = 20;
  } = 1;
} = 0x12345678;
