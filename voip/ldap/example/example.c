#include <stdio.h> 
#include "ldap.h"  
/* Adjust these setting for your own LDAP server */
#define HOSTNAME "localhost" 
#define PORT_NUMBER  LDAP_PORT 
#define FIND_DN "uid=bjensen, ou=People, dc=example,dc=com" 
int
main(int argc, char **argv)
{
    LDAP         *ld;
    LDAPMessage  *result, *e;
    BerElement   *ber;
    char         *a;
    char         **vals;
    int          i, rc;
    /* Get a handle to an LDAP connection. */
    if ((ld = ldap_init(HOSTNAME, PORT_NUMBER)) == NULL) {
        perror("ldap_init");
        return(1);
    }
    /* Bind anonymously to the LDAP server. */
    rc = ldap_simple_bind_s(ld, NULL, NULL);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "ldap_simple_bind_s: %s\n", ldap_err2string(rc));
        return(1);
    }
    /* Search for the entry. */
    if ((rc = ldap_search_ext_s(ld, FIND_DN, LDAP_SCOPE_BASE,
        "(objectclass=*)", NULL, 0, NULL, NULL, LDAP_NO_LIMIT,
        LDAP_NO_LIMIT, &result)) != LDAP_SUCCESS) {
        fprintf(stderr, "ldap_search_ext_s: %s\n", ldap_err2string(rc));
        return(1);
    }
    /* Since we are doing a base search, there should be only
       one matching entry.  */
    e = ldap_first_entry(ld, result);
    if (e != NULL) {
        printf("\nFound %s:\n\n", FIND_DN);
        /* Iterate through each attribute in the entry. */
        for (a = ldap_first_attribute(ld, e, &ber);
            a != NULL; a = ldap_next_attribute(ld, e, ber)) {
            /* For each attribute, print the attribute name and values. */
            if ((vals = ldap_get_values(ld, e, a)) != NULL) {
                for (i = 0; vals[i] != NULL; i++) {
                    printf("%s: %s\n", a, vals[i]);
                }
                ldap_value_free(vals);
            }
            ldap_memfree(a);
        }
        if (ber != NULL) {
            ber_free(ber, 0);
        }
    }
    ldap_msgfree(result);
    ldap_unbind(ld);
    return(0);
}