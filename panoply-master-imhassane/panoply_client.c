/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "panoply.h"

#include <stdio.h>
#include <string.h>


void
panoplyprog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	new_member_params  register_1_arg[2];
	int  *result_2;
	login_member_params  login_1_arg;
	int  *result_3;
	char *total_members_1_arg;
	member_t  *result_4;
	int  show_member_1_arg;
	int  *result_5;
	subscription_t  new_subscription_1_arg;
	int  *result_6;
	char *total_subscriptions_1_arg;
	subscription_t  *result_7;
	int  show_subscription_1_arg;
	int  *result_8;
	subscription_t  update_subscription_1_arg;
	int  *result_9;
	set_member_subscription_params  set_member_subscription_1_arg;
	int  *result_10;
	new_collection_params  new_collection_1_arg;
	int  *result_11;
	char *total_collections_1_arg;
	collection_t  *result_12;
	int  show_collection_1_arg;
	int  *result_13;
	set_clothing_collection_params  set_clothing_collecton_1_arg;
	int  *result_14;
	new_clothing_params  new_clothing_1_arg;
	int  *result_15;
	char *total_clothings_1_arg;
	cloth_t  *result_16;
	int  show_clothing_1_arg;
	int  *result_17;
	int  rent_clothing_1_arg;
	int  *result_18;
	char *total_rents_1_arg;
	rental_t  *result_19;
	int  show_rental_1_arg;
	clothes_list_t  *result_20;
	char *list_clothes_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, PANOPLYPROG, PANOPLYVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	// Création de compte.
	puts("##### CREATION DES COMPTES #####");
	strcpy(register_1_arg[0].first_name, "Hassane");
	strcpy(register_1_arg[0].last_name, "Sow");
	strcpy(register_1_arg[0].user_name, "admin");
	strcpy(register_1_arg[0].password, "admin");

	strcpy(register_1_arg[1].first_name, "Jean");
	strcpy(register_1_arg[1].last_name, "Dumas");
	strcpy(register_1_arg[1].user_name, "client");
	strcpy(register_1_arg[1].password, "client");

	for(int i = 0; i < 2; i++) {
		result_1 = register_1(&register_1_arg[i], clnt);
		if (result_1 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
	}

	puts("##### CONNEXION EN TANT QU'ADMINISTRATEUR #####");
	strcpy(login_1_arg.user_name, "admin");
	strcpy(login_1_arg.password, "admin");
	result_2 = login_1(&login_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	puts("##### NOMBRE TOTAL DE COMPTE #####");
	result_3 = total_members_1((void*)&total_members_1_arg, clnt);
	if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("Le nombre total de comptes est: %d\n", *result_3);
/*
	result_4 = show_member_1(&show_member_1_arg, clnt);
	if (result_4 == (member_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_5 = new_subscription_1(&new_subscription_1_arg, clnt);
	if (result_5 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_6 = total_subscriptions_1((void*)&total_subscriptions_1_arg, clnt);
	if (result_6 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_7 = show_subscription_1(&show_subscription_1_arg, clnt);
	if (result_7 == (subscription_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_8 = update_subscription_1(&update_subscription_1_arg, clnt);
	if (result_8 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_9 = set_member_subscription_1(&set_member_subscription_1_arg, clnt);
	if (result_9 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_10 = new_collection_1(&new_collection_1_arg, clnt);
	if (result_10 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_11 = total_collections_1((void*)&total_collections_1_arg, clnt);
	if (result_11 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_12 = show_collection_1(&show_collection_1_arg, clnt);
	if (result_12 == (collection_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_13 = set_clothing_collecton_1(&set_clothing_collecton_1_arg, clnt);
	if (result_13 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_14 = new_clothing_1(&new_clothing_1_arg, clnt);
	if (result_14 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_15 = total_clothings_1((void*)&total_clothings_1_arg, clnt);
	if (result_15 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_16 = show_clothing_1(&show_clothing_1_arg, clnt);
	if (result_16 == (cloth_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_17 = rent_clothing_1(&rent_clothing_1_arg, clnt);
	if (result_17 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_18 = total_rents_1((void*)&total_rents_1_arg, clnt);
	if (result_18 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_19 = show_rental_1(&show_rental_1_arg, clnt);
	if (result_19 == (rental_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_20 = list_clothes_1((void*)&list_clothes_1_arg, clnt);
	if (result_20 == (clothes_list_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	*/
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */

}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	panoplyprog_1 (host);
exit (0);
}
