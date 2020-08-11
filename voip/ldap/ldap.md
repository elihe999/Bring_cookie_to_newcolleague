
<https://linux.die.net/man/3/ldap_search_ext_s>

```c
#include <sys/types.h>
#include <ldap.h>

int ldap_search_ext(
       LDAP *ld,
       char *base,
       int scope,
       char *filter,
       char *attrs[],
       int attrsonly,
       LDAPControl **serverctrls,
       LDAPControl **clientctrls,
       struct timeval *timeout,
       int sizelimit,
       int *msgidp );

int ldap_search_ext_s(
       LDAP *ld,
       char *base,
       int scope,
       char *filter,
       char *attrs[],
       int attrsonly,
       LDAPControl **serverctrls,
       LDAPControl **clientctrls,
       struct timeval *timeout,
       int sizelimit,
       LDAPMessage **res );
```

[openldap](https://www.openldap.org/)
[ldapbrowser](http://www.ldapbrowserwindows.com/)