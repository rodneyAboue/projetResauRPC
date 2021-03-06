/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "panoply.h"

bool_t
xdr_MEMBER_TYPE (XDR *xdrs, MEMBER_TYPE *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_RENTAL_STATE (XDR *xdrs, RENTAL_STATE *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_date_t (XDR *xdrs, date_t *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->day))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->month))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->year))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_subscription_t (XDR *xdrs, subscription_t *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->credits))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->price))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_member_activity_t (XDR *xdrs, member_activity_t *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->total_credits))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->current_usage))
		 return FALSE;
	 if (!xdr_date_t (xdrs, &objp->start_date))
		 return FALSE;
	 if (!xdr_date_t (xdrs, &objp->end_date))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_member_subscription_t (XDR *xdrs, member_subscription_t *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->is_valid))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->subscription, sizeof (subscription_t), (xdrproc_t) xdr_subscription_t))
		 return FALSE;
	 if (!xdr_member_activity_t (xdrs, &objp->first_month))
		 return FALSE;
	 if (!xdr_member_activity_t (xdrs, &objp->second_month))
		 return FALSE;
	 if (!xdr_member_activity_t (xdrs, &objp->third_month))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_member_t (XDR *xdrs, member_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->first_name, 10,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->last_name, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->user_name, 10,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->password, 32,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->address, 250,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_MEMBER_TYPE (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_member_subscription_t (xdrs, &objp->subscription))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_collection_t (XDR *xdrs, collection_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->name, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_occasion_t (XDR *xdrs, occasion_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->name, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_brand_t (XDR *xdrs, brand_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->name, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_cloth_t (XDR *xdrs, cloth_t *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_int (xdrs, &objp->id))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->name, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->price))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->credits))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->stock))
				 return FALSE;

		} else {
		IXDR_PUT_LONG(buf, objp->price);
		IXDR_PUT_LONG(buf, objp->credits);
		IXDR_PUT_LONG(buf, objp->stock);
		}
		 if (!xdr_pointer (xdrs, (char **)&objp->collection, sizeof (collection_t), (xdrproc_t) xdr_collection_t))
			 return FALSE;
		 if (!xdr_pointer (xdrs, (char **)&objp->occasion, sizeof (occasion_t), (xdrproc_t) xdr_occasion_t))
			 return FALSE;
		 if (!xdr_pointer (xdrs, (char **)&objp->brand, sizeof (brand_t), (xdrproc_t) xdr_brand_t))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_int (xdrs, &objp->id))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->name, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->price))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->credits))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->stock))
				 return FALSE;

		} else {
		objp->price = IXDR_GET_LONG(buf);
		objp->credits = IXDR_GET_LONG(buf);
		objp->stock = IXDR_GET_LONG(buf);
		}
		 if (!xdr_pointer (xdrs, (char **)&objp->collection, sizeof (collection_t), (xdrproc_t) xdr_collection_t))
			 return FALSE;
		 if (!xdr_pointer (xdrs, (char **)&objp->occasion, sizeof (occasion_t), (xdrproc_t) xdr_occasion_t))
			 return FALSE;
		 if (!xdr_pointer (xdrs, (char **)&objp->brand, sizeof (brand_t), (xdrproc_t) xdr_brand_t))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->name, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->price))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->credits))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->stock))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->collection, sizeof (collection_t), (xdrproc_t) xdr_collection_t))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->occasion, sizeof (occasion_t), (xdrproc_t) xdr_occasion_t))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->brand, sizeof (brand_t), (xdrproc_t) xdr_brand_t))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_rental_t (XDR *xdrs, rental_t *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->cloth, sizeof (cloth_t), (xdrproc_t) xdr_cloth_t))
		 return FALSE;
	 if (!xdr_RENTAL_STATE (xdrs, &objp->rental_state))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_collections_list_t (XDR *xdrs, collections_list_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->data, 100,
		sizeof (collection_t), (xdrproc_t) xdr_collection_t))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->last_inserted))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_occasions_list_t (XDR *xdrs, occasions_list_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->data, 100,
		sizeof (occasion_t), (xdrproc_t) xdr_occasion_t))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->last_inserted))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_brands_list_t (XDR *xdrs, brands_list_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->data, 100,
		sizeof (brand_t), (xdrproc_t) xdr_brand_t))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->last_inserted))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_clothes_list_t (XDR *xdrs, clothes_list_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->data, 100,
		sizeof (cloth_t), (xdrproc_t) xdr_cloth_t))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->last_inserted))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_rentals_list_t (XDR *xdrs, rentals_list_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->data, 100,
		sizeof (rental_t), (xdrproc_t) xdr_rental_t))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->last_inserted))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_members_list_t (XDR *xdrs, members_list_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->data, 100,
		sizeof (member_t), (xdrproc_t) xdr_member_t))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->last_inserted))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_subscriptions_list_t (XDR *xdrs, subscriptions_list_t *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->data, 10,
		sizeof (subscription_t), (xdrproc_t) xdr_subscription_t))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->last_inserted))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_new_member_params (XDR *xdrs, new_member_params *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->first_name, 10,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->last_name, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->user_name, 10,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->password, 32,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->address, 250,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_login_member_params (XDR *xdrs, login_member_params *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->user_name, 10,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->password, 32,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_new_collection_params (XDR *xdrs, new_collection_params *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->name, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_new_clothing_params (XDR *xdrs, new_clothing_params *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->name, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->price))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->credits))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->stock))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_set_member_subscription_params (XDR *xdrs, set_member_subscription_params *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->member_id))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->subscription_id))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_set_clothing_collection_params (XDR *xdrs, set_clothing_collection_params *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->clothing_id))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->collection_id))
		 return FALSE;
	return TRUE;
}
