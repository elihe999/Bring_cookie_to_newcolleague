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

### Error Code

```c
LDAP_SUCCESS = 0 //成功
LDAP_OPERATIONS_ERROR = 1 //操作错误
LDAP_PROTOCOL_ERROR = 2 //协议错误
LDAP_TIME_LIMIT_EXCEEDED = 3 //超过最大时间限制
LDAP_SIZE_LIMIT_EXCEEDED = 4 //超过最大返回条目数
LDAP_COMPARE_FALSE = 5 //比较不匹配
LDAP_COMPARE_TRUE = 6 //比较匹配
LDAP_AUTH_METHOD_NOT_SUPPORTED = 7 //认证方法未被支持
LDAP_STRONG_AUTH_REQUIRED = 8 //需要强认证
LDAP_PARTIAL_RESULTS = 9 //null
LDAP_REFERRAL = 10 //Referral
LDAP_ADMIN_LIMIT_EXCEEDED = 11 //超出管理员权限
LDAP_UNAVAILABLE_CRITICAL_EXTENSION = 12 //Critical扩展无效
LDAP_CONFIDENTIALITY_REQUIRED = 13 //需要Confidentiality
LDAP_SASL_BIND_IN_PROGRESS = 14 //需要SASL绑定
LDAP_NO_SUCH_ATTRIBUTE = 16 //未找到该属性
LDAP_UNDEFINED_ATTRIBUTE_TYPE = 17 //未定义的属性类型
LDAP_INAPPROPRIATE_MATCHING = 18 //不适当的匹配
LDAP_CONSTRAINT_VIOLATION = 19 //约束冲突
LDAP_ATTRIBUTE_OR_value_EXISTS = 20 //属性或值已存在
LDAP_INVALID_ATTRIBUTE_SYNTAX = 21 //无效的属性语法
LDAP_NO_SUCH_OBJECT = 32 //未找到该对象
LDAP_ALIAS_PROBLEM = 33 //别名有问题
LDAP_INVALID_DN_SYNTAX = 34 //无效的DN语法
LDAP_IS_LEAF = 35 //null
LDAP_ALIAS_DEREFERENCING_PROBLEM = 36 //Dereference别名有问题
LDAP_INAPPROPRIATE_AUTHENTICATION = 48 //不适当的认证
LDAP_INVALID_CREDENTIALS = 49 //无效的Credential
LDAP_INSUFFICIENT_ACCESS_RIGHTS = 50 //访问权限不够
LDAP_BUSY = 51 //遇忙
LDAP_UNAVAILABLE = 52 //无效
LDAP_UNWILLING_TO_PERform = 53 //意外问题
LDAP_LOOP_DETECT = 54 //发现死循环
LDAP_NAMING_VIOLATION = 64 //命名冲突
LDAP_OBJECT_CLASS_VIOLATION = 65 //对象类冲突
LDAP_NOT_ALLOWED_ON_NON_LEAF = 66 //不允许在非叶结点执行此操作
LDAP_NOT_ALLOWED_ON_RDN = 67 //不允许对RDN执行此操作
LDAP_ENTRY_ALREADY_EXISTS = 68 //Entry已存在
LDAP_OBJECT_CLASS_MODS_PROHIBITED = 69 //禁止更改对象类
LDAP_AFFECTS_MULTIPLE_DSAS = 71 //null
LDAP_OTHER = 80 //其它
再来一份十六进制的，大家对照吧。
下面是winldap.h文件中的定义的十六进制错误码，我给其中的绝大部分加上了从活动目录的书上看的汉语说明，。
typedef enum
Unknown macro: {
LDAP_SUCCESS = 0x00,//操作成功
LDAP_OPERATIONS_ERROR = 0x01,//一个未指定的错误发生在处理LDAP请求的服务器上
LDAP_PROTOCOL_ERROR = 0x02,//服务器接受到一个没有正确格式化或顺序出错的包
LDAP_TIMELIMIT_EXCEEDED = 0x03,//操作上指定的时间限制被超出。这不同于服务器没有及时响应时的客户方检测到的超时错误
LDAP_SIZELIMIT_EXCEEDED = 0x04,//搜索返回的项数超过了管理限制或请求限制
LDAP_COMPARE_FALSE = 0x05,//LDAP比较函数(例如ldap_compare())返回FALSE
LDAP_COMPARE_TRUE = 0x06,//LDAP比较函数(例如ldap_compare())返回TRUE
LDAP_AUTH_METHOD_NOT_SUPPORTED = 0x07,//绑定(bind)操作中(例如ldap_bind())请求的认证方法不被服务器支持。如果你使用一个非微软LDAP客户与活动目录通信，这种情况可能发生
LDAP_STRONG_AUTH_REQUIRED = 0x08,//服务器要求一个字符串认证方法而不是一个简单口令
LDAP_REFERRAL_V2 = 0x09,//搜索结果包含LDAPv2引用或者一个部分结果集
LDAP_PARTIAL_RESULTS = 0x09,
LDAP_REFERRAL = 0x0a,//请求操作必须由另一个拥有适当的命名上下文备份的服务器处理
LDAP_ADMIN_LIMIT_EXCEEDED = 0x0b,//管理限制被超出。例如，搜索操作花费的时间超出了服务器所允许的最大时间
LDAP_UNAVAILABLE_CRIT_EXTENSION = 0x0c,//客户请求一个LDAP扩展并且指示该扩展是关键的，但是服务器并不支持扩展
LDAP_CONFIDENTIALITY_REQUIRED = 0x0d,//操作要求某种级别的加密
LDAP_SASL_BIND_IN_PROGRESS = 0x0e,//当一个SASL绑定(bind)已经在客户处理过程中时，请求一个绑定(bind)操作
LDAP_NO_SUCH_ATTRIBUTE = 0x10,//客户尝试修改或者删除一个并不存在的项的一个属性
LDAP_UNDEFINED_TYPE = 0x11,//未定义的类型
LDAP_INAPPROPRIATE_MATCHING = 0x12,//提供的匹配规则对搜索不合适或者对于属性不合适
LDAP_CONSTRAINT_VIOLATION = 0x13,//客户请求一个将违背目录中语义约束的操作。一个经常的原因是不合适的改变了模式--例如当添加一个新类时提供了一个重复的OID(对象识别符)
LDAP_ATTRIBUTE_OR_value_EXISTS = 0x14,//客户尝试添加一个已经存在的属性或值
LDAP_INVALID_SYNTAX = 0x15,//搜索过滤器的语法无效
LDAP_NO_SUCH_OBJECT = 0x20,//客户尝试或者删除一个在目录中并不存在的项
LDAP_ALIAS_PROBLEM = 0x21,//服务器在处理别名时遇到了一个错误
LDAP_INVALID_DN_SYNTAX = 0x22,//请求中指定的可区别名字的格式无效
LDAP_IS_LEAF = 0x23,//函数中指定的项是目录树中的一个叶子项
LDAP_ALIAS_DEREF_PROBLEM = 0x24,//在解除对一个别名的引用时服务器遇到了一个错误。例如，目的项并不存在
LDAP_INAPPROPRIATE_AUTH = 0x30,//认证级别对于操作不足
LDAP_INVALID_CREDENTIALS = 0x31,//绑定(bind)请求中提供的证书是无效的--例如一个无效的口令
LDAP_INSUFFICIENT_RIGHTS = 0x32,//没有执行该操作所需的足够的访问权限
LDAP_BUSY = 0x33,//服务器太忙碌而无法服务该请求。稍后重新尝试
LDAP_UNAVAILABLE = 0x34,//目录服务暂不可用。稍后重新尝试
LDAP_UNWILLING_TO_PERform = 0x35,//由于管理策略约束方面的原因，服务器将不支持该操作--例如，如果在模式修改没有被允许或者没有连接到模式管理器的情况下，试图修改该模式
LDAP_LOOP_DETECT = 0x36,//在追踪引用的过程中，客户引用到它以前已经引用的服务器
LDAP_SORT_CONTROL_MISSING = 0x3C,
LDAP_OFFSET_RANGE_ERROR = 0x3D,
LDAP_NAMING_VIOLATION = 0x40,//客户指定了一个不正确的对象的可区别名字
LDAP_OBJECT_CLASS_VIOLATION = 0x41,//操作违背了类定义中定义的语义规则
LDAP_NOT_ALLOWED_ON_NONLEAF = 0x42,//所请求的操作只可能在一个叶子对象(非容器)上执行
LDAP_NOT_ALLOWED_ON_RDN = 0x43,//在相对可区别名字上不允许该操作
LDAP_ALREADY_EXISTS = 0x44,//客户试图添加一个已经存在的对象
LDAP_NO_OBJECT_CLASS_MODS = 0x45,//客户试图通过改变一个对象的objectClass属性来修改对象的类
LDAP_RESULTS_TOO_LARGE = 0x46,//搜索操作的结果集太大，服务器无法处理
LDAP_AFFECTS_MULTIPLE_DSAS = 0x47,//所请求的操作将影响多个DSA--例如，在一个子树包含一个下级引用，该引用指向另一个命名上下文的情况下，删除该子树将影响多个DSA(目录服务器代理)
LDAP_VIRTUAL_LIST_VIEW_ERROR = 0x4c,
LDAP_OTHER = 0x50,//发生了一些其他的LDAP错误
LDAP_SERVER_DOWN = 0x51,//LDAP服务器已关闭
LDAP_LOCAL_ERROR = 0x52,//客户发生了其他一些未指定的错误
LDAP_ENCODING_ERROR = 0x53,//在将一个LDAP请求编码为ASN.1的过程中发生了一个错误
LDAP_DECODING_ERROR = 0x54,//从服务器接受到的ASN.1编码的数据是无效的
LDAP_TIMEOUT = 0x55,//在指定的时间内服务器不能响应客户
LDAP_AUTH_UNKNOWN = 0x56,//在绑定(bind)请求中指定了一种未知的认证机制
LDAP_FILTER_ERROR = 0x57,//搜索过滤器出现了某种错误
LDAP_USER_CANCELLED = 0x58,//用户取消了操作
LDAP_PARAM_ERROR = 0x59,//函数中指定的某个参数出现了错误。例如，向一个LDAP API函数传递一个NULL指针，但该函数并不希望这样，在这种情况下就产生该错误
LDAP_NO_MEMORY = 0x5a,//客户试图分配内存并且失败了
LDAP_CONNECT_ERROR = 0x5b,//客户试图向服务器建立一个TCP连接并且失败了
LDAP_NOT_SUPPORTED = 0x5c,//所请求的操作不被这种版本的LDAP协议所支持
LDAP_NO_RESULTS_RETURNED = 0x5e,//从服务器接受到一个响应，但是它没有包含结果
LDAP_CONTROL_NOT_FOUND = 0x5d,//从服务器接受到的数据表明有一个LDAP控制出现但是在数据中没有找到一个LDAP控制
LDAP_MORE_RESULTS_TO_RETURN = 0x5f,//因为有太多的结果，所以客户无法检索
LDAP_CLIENT_LOOP = 0x60,//在处理引用时客户检测到一个循环
引用数目超过了限制
LDAP_REFERRAL_LIMIT_EXCEEDED = 0x61//客户追踪的
}
LDAP_RETCODE;
```