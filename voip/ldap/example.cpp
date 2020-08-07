//  Add Wldap32.lib to your project.
//  Add Wldap32.dll to your project.

//  LDAPSESSION: Run the following code example by passing the server name as a
//  command line parameter. If no server name is passed, a serverless bind attempt is performed.
//  Example:
//    ldapsession.exe [server.fabrikam.com]

#include "stdafx.h"
#include "windows.h"
#include "winldap.h"
#include "stdio.h"
const size_t newsize = 100;

//  Entry point for application
int main(int argc, char* argv[])
{
    PWCHAR hostName = NULL;
    LDAP* pLdapConnection = NULL;
    ULONG version = LDAP_VERSION3;
    ULONG getOptSuccess = 0;
    ULONG connectSuccess = 0;
    INT returnCode = 0;

    //  Verify that the user passed a hostname.
    if (argc > 1)
    {
        //  Convert argv[] to a wchar_t*
        size_t origsize = strlen(argv[1]) + 1;
        size_t convertedChars = 0;
        wchar_t wcstring[newsize];
        mbstowcs_s(&amp;convertedChars, wcstring, origsize, argv[1], _TRUNCATE);
        wcscat_s(wcstring, L" (wchar_t *)");
        hostName = wcstring;
    }
    else
    {
        hostName = NULL;
    }

    //  Initialize a session. LDAP_PORT is the default port, 389.
    pLdapConnection = ldap_init(hostName, LDAP_PORT);

    if (pLdapConnection == NULL)
    {
        //  Set the HRESULT based on the Windows error code.
        char hr = HRESULT_FROM_WIN32(GetLastError());
        printf( "ldap_init failed with 0x%x.\n",hr);
        goto error_exit;
    }
    else
        printf("ldap_init succeeded \n");

    //  Set the version to 3.0 (default is 2.0).
    returnCode = ldap_set_option(pLdapConnection,
                                 LDAP_OPT_PROTOCOL_VERSION,
                                 (void*)&amp;version);
    if(returnCode == LDAP_SUCCESS)
        printf("ldap_set_option succeeded - version set to 3\n");
    else
    {
        printf("SetOption Error:%0X\n", returnCode);
        goto error_exit;
    }

    // Connect to the server.
    connectSuccess = ldap_connect(pLdapConnection, NULL);

    if(connectSuccess == LDAP_SUCCESS)
        printf("ldap_connect succeeded \n");
    else
    {
        printf("ldap_connect failed with 0x%x.\n",connectSuccess);
        goto error_exit;
    }

    //  Bind with current credentials (login credentials). Be
    //  aware that the password itself is never sent over the 
    //  network, and encryption is not used.
    printf("Binding ...\n");

    returnCode = ldap_bind_s(pLdapConnection, NULL, NULL,
                             LDAP_AUTH_NEGOTIATE);
    if (returnCode == LDAP_SUCCESS)
        printf("The bind was successful");
    else
        goto error_exit;

    //  Normal cleanup and exit.
    ldap_unbind(pLdapConnection);
    return 0;

    //  On error cleanup and exit.
    error_exit:
        ldap_unbind(pLdapConnection);
        return -1;
}