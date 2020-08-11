# Sending a Search Request

> To search the directory, call ldap_search_ext_s() or ldap_search_ext():

ldap_search_ext_s() is a synchronous function. This function blocks until all results have been received from the server.
ldap_search_ext() is an asynchronous function. This function sends an LDAP search request to the server. You can do other work while periodically checking to see if the server has returned any results.
These two functions are declared as follows:
```
LDAP_API(int) LDAP_CALL ldap_search_ext( LDAP *ld,
const char *base, int scope, const char *filter,
char **attrs, int attrsonly, LDAPControl **serverctrls,
LDAPControl **clientctrls, struct timeval *timeoutp,
int sizelimit, int *msgidp );
LDAP_API(int) LDAP_CALL ldap_search_ext_s( LDAP *ld,
const char *base, int scope, const char *filter, char **attrs,
int attrsonly, LDAPControl **serverctrls,
LDAPControl **clientctrls, struct timeval *timeoutp,
int sizelimit, LDAPMessage **res );
```
For either function, you specify the search criteria using the following parameters:

base specifies the starting point in the directory, or the base DN (an entry where to start searching).

To search entries under "dc=example,dc=com", the base DN is "dc=example,dc=com". See "Specifying the Base DN and Scope" for details.

scope specifies the scope of the search (which entries you want to search).

You can narrow the scope of the search to search only the base DN, entries at one level under the base DN, or entries at all levels under the base DN. See Specifying the Base DN and Scope for details.

filter specifies a search filter (what to search for).

A search filter can be as simple as "find entries where the last name is Jensen" or as complex as "find entries that belong to Dept. #17 and whose first names start with the letter F." See Specifying a Search Filter for details.

attrs and attrsonly specify the type of information that you want return (which attributes you want to retrieve) and whether you want to retrieve only the attribute type or the attribute type and its values

For details, see Specifying the Attributes to Retrieve.

You can also specify that you only want to return the names of attributes (and not the values) by passing a non-zero value for the attrsonly argument.

serverctrls and clientctrls specify the LDAPv3 controls associated with this search operation

For details on LDAPv3 controls, see Chapter 14 - Working with LDAP Controls."

timeoutp and sizelimit specify the search constraints that you want applied to this search.

For example, you can specify a different time-out period or maximum number of results that differ from the values of these options for the current session. See Setting Search Preferences for details.