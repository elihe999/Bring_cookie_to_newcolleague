1. slapd.conf
> base: dc=maxcrc,dc=com
 DN: cn=Manager,dc=maxcrc,dc=com
 secret

2. openldap -> run
3. ldapbroswer -> lbe.jar

# About LDAP

## My Question

## searchRequest? baseObject or wholeSubtree

<https://curl.haxx.se/rfc/rfc4516.txt>

>RFC 4516             LDAP: Uniform Resource Locator            June 2006


      dn          = distinguishedName ; From Section 3 of [RFC4514],
                                      ; subject to the provisions of
                                      ; the "Percent-Encoding"
                                      ; section below.

      attributes  = attrdesc *(COMMA attrdesc)
      attrdesc    = selector *(COMMA selector)
      selector    = attributeSelector ; From Section 4.5.1 of
                                      ; [RFC4511], subject to the
                                      ; provisions of the
                                      ; "Percent-Encoding" section
                                      ; below.

      scope       = "base" / "one" / "sub"
      extensions  = extension *(COMMA extension)
      extension   = [EXCLAMATION] extype [EQUALS exvalue]
      extype      = oid               ; From section 1.4 of [RFC4512].

      exvalue     = LDAPString        ; From section 4.1.2 of
                                      ; [RFC4511], subject to the
                                      ; provisions of the
                                      ; "Percent-Encoding" section
                                      ; below.

      EXCLAMATION = %x21              ; exclamation mark ("!")
      SLASH       = %x2F              ; forward slash ("/")
      COLON       = %x3A              ; colon (":")
      QUESTION    = %x3F              ; question mark ("?")


## Max Hits and Search Timeout

sizeLimit       INTEGER (0 ..  maxInt),
timeLimit       INTEGER (0 ..  maxInt),
---


## All I need

> ```ldapurl -b dc=maxcrc,dc=com -s sub -a cn,sn,telephoneNumber -f telephoneNumber=*1*,sn=*1* -h 127.0.0.1```


LDAP protocol	| LDAP / LDAPs
> :646 
:389

Server Address
> ldap://123

Port	
> --

Base	        | dc=maxcrc,dc=com
> ldap://1:389/dc=maxcrc


User Name       |cn=manager,dc=maxcrc,dc=com
Password	

> <https://curl.haxx.se/libcurl/c/CURLOPT_USERNAME.html>

LDAP Number Filter	
LDAP Name Filter	
> ?phoneNumber=*1*

LDAP Version	Version 2Version 3
LDAP Name Attributes  | cn sn
LDAP Number Attributes	| telephoneNumber
LDAP Display Name   | sn cn


Max. Hits   | 50
> **sizelimit=1**
ldapurl -E

Search Timeout	| 30
> **sizelimit=1?timeout=1**
ldapurl -E

---- 
>ldap_search_ext(3) - Linux man page
Name
ldap_search, ldap_search_s, ldap_search_st, ldap_search_ext, ldap_search_ext_s - Perform an LDAP search operation

>Library
OpenLDAP LDAP (libldap, -lldap)

>Synopsis
```
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
>Description

 
>>These routines are used to perform LDAP search operations. The ldap_search_ext_s() routine does the search synchronously (i.e., not returning until the operation completes), providing a pointer to the resulting LDAP messages at the location pointed to by the res parameter.
>>The ldap_search_ext() routine is the asynchronous version, initiating the search and returning the message id of the operation it initiated in the integer pointed to by the msgidp parameter.
>>The base parameter is the DN of the entry at which to start the search.
The scope parameter is the scope of the search and should be one of LDAP_SCOPE_BASE, to search the object itself, LDAP_SCOPE_ONELEVEL, to search the object's immediate children, LDAP_SCOPE_SUBTREE, to search the object and all its descendants, or LDAP_SCOPE_CHILDREN, to search all of the descendants. Note that the latter requires the server support the LDAP Subordinates Search Scope extension.

>>The filter is a string representation of the filter to apply in the search. The string should conform to the format specified in RFC 4515 as extended by RFC 4526. For instance, "(cn=Jane Doe)". Note that use of the extension requires the server to support the LDAP Absolute True/False Filter extension. NULL may be specified to indicate the library should send the filter (objectClass=*).
The attrs parameter is a null-terminated array of attribute descriptions to return from matching entries. If NULL is specified, the return of all user attributes is requested. The description "*" (LDAP_ALL_USER_ATTRIBUTES) may be used to request all user attributes to be returned. The description "+"(LDAP_ALL_OPERATIONAL_ATTRIBUTES) may be used to request all operational attributes to be returned. Note that this requires the server to support the LDAP All Operational Attribute extension. To request no attributes, the description "1.1" (LDAP_NO_ATTRS) should be listed by itself.

>The attrsonly parameter should be set to a non-zero value if only attribute descriptions are wanted. It should be set to zero (0) if both attributes descriptions and attribute values are wanted.
The serverctrls and clientctrls parameters may be used to specify server and client controls, respectively.
The ldap_search_ext_s() routine is the synchronous version of ldap_search_ext().
It also returns a code indicating success or, in the case of failure, indicating the nature of the failure of the operation. See ldap_error(3) for details.

> ##### Notes
>>Note that both read and list functionality are subsumed by these routines, by using a filter like "(objectclass=*)" and a scope of LDAP_SCOPE_BASE (to emulate read) or LDAP_SCOPE_ONELEVEL (to emulate list).
>>These routines may dynamically allocate memory. The caller is responsible for freeing such memory using supplied deallocation routines. Return values are contained in <ldap.h>.
>>Note that res parameter of ldap_search_ext_s() and ldap_search_s() should be freed with ldap_msgfree() regardless of return value of these functions.
>##### Deprecated Interfaces
>>The ldap_search() routine is deprecated in favor of the ldap_search_ext() routine. The ldap_search_s() and ldap_search_st() routines are deprecated in favor of the ldap_search_ext_s() routine.
>>Deprecated interfaces generally remain in the library. The macro LDAP_DEPRECATED can be defined to a non-zero value (e.g., -DLDAP_DEPRECATED=1) when compiling program designed to use deprecated interfaces. It is recommended that developers writing new programs, or updating old programs, avoid use of deprecated interfaces. Over time, it is expected that documentation (and, eventually, support) for deprecated interfaces to be eliminated.

> #### See Also
>>ldap(3), ldap_result(3), ldap_error(3)
>>Acknowledgements
OpenLDAP Software is developed and maintained by The OpenLDAP Project <http://www.openldap.org/>. OpenLDAP Software is derived from University of Michigan LDAP 3.3 Release.
Referenced By
ldap_abandon_ext(3), ldap_set_option(3), ldap_sync(3), ldapsearch(1)

----
Sort Results	| NoYes
LDAP Lookup	    | Incoming Calls Outgoing Calls
Lookup Display Name	| sn cn description
Exact Match Search	| NoYes

# Other

<https://www.novell.com/documentation/developer/jldap/jldapenu/api/com/novell/ldap/LDAPSearchRequest.html>
<https://curl.haxx.se/rfc/rfc1959.txt>
<https://curl.haxx.se/rfc/rfc4511.txt>
<https://curl.haxx.se/rfc/rfc2255.txt>
<https://curl.haxx.se/docs/manual.html>
<https://git.openldap.org/openldap/openldap/>
[ldapbrowser](http://www.ldapbrowserwindows.com/)
<https://packages.debian.org/buster/libldap2-dev>


## curl log

> Changelog Development Documentation Download libcurl Mailing Lists News
cURL / Mailing Lists / curl-library / Single Mail
curl-library
Re: Question on libcurl LDAP support
This message: [ Message body ] [ More options ]
Related messages: [ Next message ] [ Previous message ] [ In reply to ]
From: Daniel Stenberg <daniel_at_haxx.se>
Date: Mon, 8 Feb 2010 16:08:35 +0100 (CET)
On Sat, 6 Feb 2010, Paschal Mushubi wrote:
> Is support for LDAP mature and actively maintained?
AFAIK it works fine.
> Where can I find examples of how to use libcurl against an LDAP server? C++
> examples would be best but C is fine too.
Use libcurl like with any other protocol and just use a LDAP URL with it. The
http://curl.haxx.se/docs/manual.html page talks a little about that, search
for ldap:// on that page.
-- 
  / daniel.haxx.se
-------------------------------------------------------------------
>> List admin: http://cool.haxx.se/list/listinfo/curl-library
Etiquette:  http://curl.haxx.se/mail/etiquette.html
Received on 2010-02-08
This message: [ Message body ]
Next message: Daniel Stenberg: "ANNOUNCE: curl and libcurl 7.20.0"
Previous message: Daniel Stenberg: "Re: Curl error code (33)"
In reply to: Paschal Mushubi: "Question on libcurl LDAP support"
Contemporary messages sorted: [ by date ] [ by thread ] [ by subject ] [ by author ] [ by messages with attachments ]