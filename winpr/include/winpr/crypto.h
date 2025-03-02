/**
 * WinPR: Windows Portable Runtime
 * Cryptography API (CryptoAPI)
 *
 * Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WINPR_CRYPTO_H
#define WINPR_CRYPTO_H

#include <winpr/winpr.h>
#include <winpr/wtypes.h>

#include <winpr/error.h>

#ifdef _WIN32

#include <wincrypt.h>

#endif

#ifndef ALG_TYPE_RESERVED7
#define ALG_TYPE_RESERVED7 (7 << 9)
#endif

#if !defined(NTDDI_VERSION) || (NTDDI_VERSION <= 0x05010200)
#define ALG_SID_SHA_256 12
#define ALG_SID_SHA_384 13
#define ALG_SID_SHA_512 14
#define CALG_SHA_256 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_256)
#define CALG_SHA_384 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_384)
#define CALG_SHA_512 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_512)
#endif

#ifndef _WIN32

/* ncrypt.h */

typedef ULONG_PTR NCRYPT_HANDLE;
typedef ULONG_PTR NCRYPT_PROV_HANDLE;
typedef ULONG_PTR NCRYPT_KEY_HANDLE;
typedef ULONG_PTR NCRYPT_HASH_HANDLE;
typedef ULONG_PTR NCRYPT_SECRET_HANDLE;

/* wincrypt.h */

#define GET_ALG_CLASS(x) (x & (7 << 13))
#define GET_ALG_TYPE(x) (x & (15 << 9))
#define GET_ALG_SID(x) (x & (511))

#define ALG_CLASS_ANY (0)
#define ALG_CLASS_SIGNATURE (1 << 13)
#define ALG_CLASS_MSG_ENCRYPT (2 << 13)
#define ALG_CLASS_DATA_ENCRYPT (3 << 13)
#define ALG_CLASS_HASH (4 << 13)
#define ALG_CLASS_KEY_EXCHANGE (5 << 13)
#define ALG_CLASS_ALL (7 << 13)

#define ALG_TYPE_ANY (0)
#define ALG_TYPE_DSS (1 << 9)
#define ALG_TYPE_RSA (2 << 9)
#define ALG_TYPE_BLOCK (3 << 9)
#define ALG_TYPE_STREAM (4 << 9)
#define ALG_TYPE_DH (5 << 9)
#define ALG_TYPE_SECURECHANNEL (6 << 9)

#define ALG_SID_ANY (0)

#define ALG_SID_RSA_ANY 0
#define ALG_SID_RSA_PKCS 1
#define ALG_SID_RSA_MSATWORK 2
#define ALG_SID_RSA_ENTRUST 3
#define ALG_SID_RSA_PGP 4

#define ALG_SID_DSS_ANY 0
#define ALG_SID_DSS_PKCS 1
#define ALG_SID_DSS_DMS 2

#define ALG_SID_DES 1
#define ALG_SID_3DES 3
#define ALG_SID_DESX 4
#define ALG_SID_IDEA 5
#define ALG_SID_CAST 6
#define ALG_SID_SAFERSK64 7
#define ALG_SID_SAFERSK128 8
#define ALG_SID_3DES_112 9
#define ALG_SID_CYLINK_MEK 12
#define ALG_SID_RC5 13

#define ALG_SID_AES_128 14
#define ALG_SID_AES_192 15
#define ALG_SID_AES_256 16
#define ALG_SID_AES 17

#define ALG_SID_SKIPJACK 10
#define ALG_SID_TEK 11

#define CRYPT_MODE_CBCI 6
#define CRYPT_MODE_CFBP 7
#define CRYPT_MODE_OFBP 8
#define CRYPT_MODE_CBCOFM 9
#define CRYPT_MODE_CBCOFMI 10

#define ALG_SID_RC2 2

#define ALG_SID_RC4 1
#define ALG_SID_SEAL 2

#define ALG_SID_DH_SANDF 1
#define ALG_SID_DH_EPHEM 2
#define ALG_SID_AGREED_KEY_ANY 3
#define ALG_SID_KEA 4

#define ALG_SID_ECDH 5

#define ALG_SID_MD2 1
#define ALG_SID_MD4 2
#define ALG_SID_MD5 3
#define ALG_SID_SHA 4
#define ALG_SID_SHA1 4
#define ALG_SID_MAC 5
#define ALG_SID_RIPEMD 6
#define ALG_SID_RIPEMD160 7
#define ALG_SID_SSL3SHAMD5 8
#define ALG_SID_HMAC 9
#define ALG_SID_TLS1PRF 10

#define ALG_SID_HASH_REPLACE_OWF 11

#define ALG_SID_SHA_256 12
#define ALG_SID_SHA_384 13
#define ALG_SID_SHA_512 14

#define ALG_SID_SSL3_MASTER 1
#define ALG_SID_SCHANNEL_MASTER_HASH 2
#define ALG_SID_SCHANNEL_MAC_KEY 3
#define ALG_SID_PCT1_MASTER 4
#define ALG_SID_SSL2_MASTER 5
#define ALG_SID_TLS1_MASTER 6
#define ALG_SID_SCHANNEL_ENC_KEY 7

#define ALG_SID_ECMQV 1

#define CALG_MD2 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD2)
#define CALG_MD4 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD4)
#define CALG_MD5 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD5)
#define CALG_SHA (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA)
#define CALG_SHA1 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA1)
#define CALG_MAC (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MAC)
#define CALG_RSA_SIGN (ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA_ANY)
#define CALG_DSS_SIGN (ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_DSS_ANY)

#define CALG_NO_SIGN (ALG_CLASS_SIGNATURE | ALG_TYPE_ANY | ALG_SID_ANY)

#define CALG_RSA_KEYX (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_RSA | ALG_SID_RSA_ANY)
#define CALG_DES (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_DES)
#define CALG_3DES_112 (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_3DES_112)
#define CALG_3DES (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_3DES)
#define CALG_DESX (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_DESX)
#define CALG_RC2 (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_RC2)
#define CALG_RC4 (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_STREAM | ALG_SID_RC4)
#define CALG_SEAL (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_STREAM | ALG_SID_SEAL)
#define CALG_DH_SF (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_DH_SANDF)
#define CALG_DH_EPHEM (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_DH_EPHEM)
#define CALG_AGREEDKEY_ANY (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_AGREED_KEY_ANY)
#define CALG_KEA_KEYX (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_KEA)
#define CALG_HUGHES_MD5 (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_ANY | ALG_SID_MD5)
#define CALG_SKIPJACK (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_SKIPJACK)
#define CALG_TEK (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_TEK)
#define CALG_CYLINK_MEK (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_CYLINK_MEK)
#define CALG_SSL3_SHAMD5 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SSL3SHAMD5)
#define CALG_SSL3_MASTER (ALG_CLASS_MSG_ENCRYPT | ALG_TYPE_SECURECHANNEL | ALG_SID_SSL3_MASTER)
#define CALG_SCHANNEL_MASTER_HASH \
	(ALG_CLASS_MSG_ENCRYPT | ALG_TYPE_SECURECHANNEL | ALG_SID_SCHANNEL_MASTER_HASH)
#define CALG_SCHANNEL_MAC_KEY \
	(ALG_CLASS_MSG_ENCRYPT | ALG_TYPE_SECURECHANNEL | ALG_SID_SCHANNEL_MAC_KEY)
#define CALG_SCHANNEL_ENC_KEY \
	(ALG_CLASS_MSG_ENCRYPT | ALG_TYPE_SECURECHANNEL | ALG_SID_SCHANNEL_ENC_KEY)
#define CALG_PCT1_MASTER (ALG_CLASS_MSG_ENCRYPT | ALG_TYPE_SECURECHANNEL | ALG_SID_PCT1_MASTER)
#define CALG_SSL2_MASTER (ALG_CLASS_MSG_ENCRYPT | ALG_TYPE_SECURECHANNEL | ALG_SID_SSL2_MASTER)
#define CALG_TLS1_MASTER (ALG_CLASS_MSG_ENCRYPT | ALG_TYPE_SECURECHANNEL | ALG_SID_TLS1_MASTER)
#define CALG_RC5 (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_RC5)
#define CALG_HMAC (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_HMAC)
#define CALG_TLS1PRF (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_TLS1PRF)

#define CALG_HASH_REPLACE_OWF (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_HASH_REPLACE_OWF)
#define CALG_AES_128 (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_AES_128)
#define CALG_AES_192 (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_AES_192)
#define CALG_AES_256 (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_AES_256)
#define CALG_AES (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_BLOCK | ALG_SID_AES)

#define CALG_SHA_256 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_256)
#define CALG_SHA_384 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_384)
#define CALG_SHA_512 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_512)

#define CALG_ECDH (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_ECDH)
#define CALG_ECMQV (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_ANY | ALG_SID_ECMQV)

typedef struct
{
	DWORD cbData;
	BYTE* pbData;
} CRYPT_INTEGER_BLOB, *PCRYPT_INTEGER_BLOB, CRYPT_UINT_BLOB, *PCRYPT_UINT_BLOB, CRYPT_OBJID_BLOB,
    *PCRYPT_OBJID_BLOB, CERT_NAME_BLOB, *PCERT_NAME_BLOB, CERT_RDN_VALUE_BLOB,
    *PCERT_RDN_VALUE_BLOB, CERT_BLOB, *PCERT_BLOB, CRL_BLOB, *PCRL_BLOB, DATA_BLOB, *PDATA_BLOB,
    CRYPT_DATA_BLOB, *PCRYPT_DATA_BLOB, CRYPT_HASH_BLOB, *PCRYPT_HASH_BLOB, CRYPT_DIGEST_BLOB,
    *PCRYPT_DIGEST_BLOB, CRYPT_DER_BLOB, *PCRYPT_DER_BLOB, CRYPT_ATTR_BLOB, *PCRYPT_ATTR_BLOB;

typedef struct
{
	LPSTR pszObjId;
	CRYPT_OBJID_BLOB Parameters;
} CRYPT_ALGORITHM_IDENTIFIER, *PCRYPT_ALGORITHM_IDENTIFIER;

typedef struct
{
	DWORD cbData;
	BYTE* pbData;
	DWORD cUnusedBits;
} CRYPT_BIT_BLOB, *PCRYPT_BIT_BLOB;

typedef struct
{
	CRYPT_ALGORITHM_IDENTIFIER Algorithm;
	CRYPT_BIT_BLOB PublicKey;
} CERT_PUBLIC_KEY_INFO, *PCERT_PUBLIC_KEY_INFO;

typedef struct
{
	LPSTR pszObjId;
	BOOL fCritical;
	CRYPT_OBJID_BLOB Value;
} CERT_EXTENSION, *PCERT_EXTENSION;
typedef const CERT_EXTENSION* PCCERT_EXTENSION;

typedef struct
{
	DWORD dwVersion;
	CRYPT_INTEGER_BLOB SerialNumber;
	CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
	CERT_NAME_BLOB Issuer;
	FILETIME NotBefore;
	FILETIME NotAfter;
	CERT_NAME_BLOB Subject;
	CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
	CRYPT_BIT_BLOB IssuerUniqueId;
	CRYPT_BIT_BLOB SubjectUniqueId;
	DWORD cExtension;
	PCERT_EXTENSION rgExtension;
} CERT_INFO, *PCERT_INFO;

typedef void* HCERTSTORE;
typedef ULONG_PTR HCRYPTPROV;
typedef ULONG_PTR HCRYPTPROV_LEGACY;

typedef struct
{
	DWORD dwCertEncodingType;
	BYTE* pbCertEncoded;
	DWORD cbCertEncoded;
	PCERT_INFO pCertInfo;
	HCERTSTORE hCertStore;
} CERT_CONTEXT, *PCERT_CONTEXT;
typedef const CERT_CONTEXT* PCCERT_CONTEXT;

#if !defined(AT_KEYEXCHANGE)
#define AT_KEYEXCHANGE (1)
#endif
#if !defined(AT_SIGNATURE)
#define AT_SIGNATURE (2)
#endif
#if !defined(AT_AUTHENTICATE)
#define AT_AUTHENTICATE (3)
#endif

#define CERT_ENCODING_TYPE_MASK 0x0000FFFF
#define CMSG_ENCODING_TYPE_MASK 0xFFFF0000
#define GET_CERT_ENCODING_TYPE(x) (x & CERT_ENCODING_TYPE_MASK)
#define GET_CMSG_ENCODING_TYPE(x) (x & CMSG_ENCODING_TYPE_MASK)

#define CRYPT_ASN_ENCODING 0x00000001
#define CRYPT_NDR_ENCODING 0x00000002
#define X509_ASN_ENCODING 0x00000001
#define X509_NDR_ENCODING 0x00000002
#define PKCS_7_ASN_ENCODING 0x00010000
#define PKCS_7_NDR_ENCODING 0x00020000

#define CERT_COMPARE_MASK 0xFFFF
#define CERT_COMPARE_SHIFT 16
#define CERT_COMPARE_ANY 0
#define CERT_COMPARE_SHA1_HASH 1
#define CERT_COMPARE_NAME 2
#define CERT_COMPARE_ATTR 3
#define CERT_COMPARE_MD5_HASH 4
#define CERT_COMPARE_PROPERTY 5
#define CERT_COMPARE_PUBLIC_KEY 6
#define CERT_COMPARE_HASH CERT_COMPARE_SHA1_HASH
#define CERT_COMPARE_NAME_STR_A 7
#define CERT_COMPARE_NAME_STR_W 8
#define CERT_COMPARE_KEY_SPEC 9
#define CERT_COMPARE_ENHKEY_USAGE 10
#define CERT_COMPARE_CTL_USAGE CERT_COMPARE_ENHKEY_USAGE
#define CERT_COMPARE_SUBJECT_CERT 11
#define CERT_COMPARE_ISSUER_OF 12
#define CERT_COMPARE_EXISTING 13
#define CERT_COMPARE_SIGNATURE_HASH 14
#define CERT_COMPARE_KEY_IDENTIFIER 15
#define CERT_COMPARE_CERT_ID 16
#define CERT_COMPARE_CROSS_CERT_DIST_POINTS 17
#define CERT_COMPARE_PUBKEY_MD5_HASH 18
#define CERT_COMPARE_SUBJECT_INFO_ACCESS 19
#define CERT_COMPARE_HASH_STR 20
#define CERT_COMPARE_HAS_PRIVATE_KEY 21

#define CERT_FIND_ANY (CERT_COMPARE_ANY << CERT_COMPARE_SHIFT)
#define CERT_FIND_SHA1_HASH (CERT_COMPARE_SHA1_HASH << CERT_COMPARE_SHIFT)
#define CERT_FIND_MD5_HASH (CERT_COMPARE_MD5_HASH << CERT_COMPARE_SHIFT)
#define CERT_FIND_SIGNATURE_HASH (CERT_COMPARE_SIGNATURE_HASH << CERT_COMPARE_SHIFT)
#define CERT_FIND_KEY_IDENTIFIER (CERT_COMPARE_KEY_IDENTIFIER << CERT_COMPARE_SHIFT)
#define CERT_FIND_HASH CERT_FIND_SHA1_HASH
#define CERT_FIND_PROPERTY (CERT_COMPARE_PROPERTY << CERT_COMPARE_SHIFT)
#define CERT_FIND_PUBLIC_KEY (CERT_COMPARE_PUBLIC_KEY << CERT_COMPARE_SHIFT)
#define CERT_FIND_SUBJECT_NAME (CERT_COMPARE_NAME << CERT_COMPARE_SHIFT | CERT_INFO_SUBJECT_FLAG)
#define CERT_FIND_SUBJECT_ATTR (CERT_COMPARE_ATTR << CERT_COMPARE_SHIFT | CERT_INFO_SUBJECT_FLAG)
#define CERT_FIND_ISSUER_NAME (CERT_COMPARE_NAME << CERT_COMPARE_SHIFT | CERT_INFO_ISSUER_FLAG)
#define CERT_FIND_ISSUER_ATTR (CERT_COMPARE_ATTR << CERT_COMPARE_SHIFT | CERT_INFO_ISSUER_FLAG)
#define CERT_FIND_SUBJECT_STR_A \
	(CERT_COMPARE_NAME_STR_A << CERT_COMPARE_SHIFT | CERT_INFO_SUBJECT_FLAG)
#define CERT_FIND_SUBJECT_STR_W \
	(CERT_COMPARE_NAME_STR_W << CERT_COMPARE_SHIFT | CERT_INFO_SUBJECT_FLAG)
#define CERT_FIND_SUBJECT_STR CERT_FIND_SUBJECT_STR_W
#define CERT_FIND_ISSUER_STR_A \
	(CERT_COMPARE_NAME_STR_A << CERT_COMPARE_SHIFT | CERT_INFO_ISSUER_FLAG)
#define CERT_FIND_ISSUER_STR_W \
	(CERT_COMPARE_NAME_STR_W << CERT_COMPARE_SHIFT | CERT_INFO_ISSUER_FLAG)
#define CERT_FIND_ISSUER_STR CERT_FIND_ISSUER_STR_W
#define CERT_FIND_KEY_SPEC (CERT_COMPARE_KEY_SPEC << CERT_COMPARE_SHIFT)
#define CERT_FIND_ENHKEY_USAGE (CERT_COMPARE_ENHKEY_USAGE << CERT_COMPARE_SHIFT)
#define CERT_FIND_CTL_USAGE CERT_FIND_ENHKEY_USAGE
#define CERT_FIND_SUBJECT_CERT (CERT_COMPARE_SUBJECT_CERT << CERT_COMPARE_SHIFT)
#define CERT_FIND_ISSUER_OF (CERT_COMPARE_ISSUER_OF << CERT_COMPARE_SHIFT)
#define CERT_FIND_EXISTING (CERT_COMPARE_EXISTING << CERT_COMPARE_SHIFT)
#define CERT_FIND_CERT_ID (CERT_COMPARE_CERT_ID << CERT_COMPARE_SHIFT)
#define CERT_FIND_CROSS_CERT_DIST_POINTS (CERT_COMPARE_CROSS_CERT_DIST_POINTS << CERT_COMPARE_SHIFT)
#define CERT_FIND_PUBKEY_MD5_HASH (CERT_COMPARE_PUBKEY_MD5_HASH << CERT_COMPARE_SHIFT)
#define CERT_FIND_SUBJECT_INFO_ACCESS (CERT_COMPARE_SUBJECT_INFO_ACCESS << CERT_COMPARE_SHIFT)
#define CERT_FIND_HASH_STR (CERT_COMPARE_HASH_STR << CERT_COMPARE_SHIFT)
#define CERT_FIND_HAS_PRIVATE_KEY (CERT_COMPARE_HAS_PRIVATE_KEY << CERT_COMPARE_SHIFT)

#define CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG 0x1
#define CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG 0x2
#define CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG 0x4
#define CERT_FIND_NO_ENHKEY_USAGE_FLAG 0x8
#define CERT_FIND_OR_ENHKEY_USAGE_FLAG 0x10
#define CERT_FIND_VALID_ENHKEY_USAGE_FLAG 0x20
#define CERT_FIND_OPTIONAL_CTL_USAGE_FLAG CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG
#define CERT_FIND_EXT_ONLY_CTL_USAGE_FLAG CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG
#define CERT_FIND_PROP_ONLY_CTL_USAGE_FLAG CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG
#define CERT_FIND_NO_CTL_USAGE_FLAG CERT_FIND_NO_ENHKEY_USAGE_FLAG
#define CERT_FIND_OR_CTL_USAGE_FLAG CERT_FIND_OR_ENHKEY_USAGE_FLAG
#define CERT_FIND_VALID_CTL_USAGE_FLAG CERT_FIND_VALID_ENHKEY_USAGE_FLAG

#define CERT_NAME_EMAIL_TYPE 1
#define CERT_NAME_RDN_TYPE 2
#define CERT_NAME_ATTR_TYPE 3
#define CERT_NAME_SIMPLE_DISPLAY_TYPE 4
#define CERT_NAME_FRIENDLY_DISPLAY_TYPE 5
#define CERT_NAME_DNS_TYPE 6
#define CERT_NAME_URL_TYPE 7
#define CERT_NAME_UPN_TYPE 8

#define CERT_NAME_ISSUER_FLAG 0x1
#define CERT_NAME_DISABLE_IE4_UTF8_FLAG 0x00010000

#define CERT_NAME_SEARCH_ALL_NAMES_FLAG 0x2

#define CERT_STORE_PROV_MSG ((LPCSTR)1)
#define CERT_STORE_PROV_MEMORY ((LPCSTR)2)
#define CERT_STORE_PROV_FILE ((LPCSTR)3)
#define CERT_STORE_PROV_REG ((LPCSTR)4)
#define CERT_STORE_PROV_PKCS7 ((LPCSTR)5)
#define CERT_STORE_PROV_SERIALIZED ((LPCSTR)6)
#define CERT_STORE_PROV_FILENAME_A ((LPCSTR)7)
#define CERT_STORE_PROV_FILENAME_W ((LPCSTR)8)
#define CERT_STORE_PROV_FILENAME CERT_STORE_PROV_FILENAME_W
#define CERT_STORE_PROV_SYSTEM_A ((LPCSTR)9)
#define CERT_STORE_PROV_SYSTEM_W ((LPCSTR)10)
#define CERT_STORE_PROV_SYSTEM CERT_STORE_PROV_SYSTEM_W
#define CERT_STORE_PROV_COLLECTION ((LPCSTR)11)
#define CERT_STORE_PROV_SYSTEM_REGISTRY_A ((LPCSTR)12)
#define CERT_STORE_PROV_SYSTEM_REGISTRY_W ((LPCSTR)13)
#define CERT_STORE_PROV_SYSTEM_REGISTRY CERT_STORE_PROV_SYSTEM_REGISTRY_W
#define CERT_STORE_PROV_PHYSICAL_W ((LPCSTR)14)
#define CERT_STORE_PROV_PHYSICAL CERT_STORE_PROV_PHYSICAL_W
#define CERT_STORE_PROV_SMART_CARD_W ((LPCSTR)15)
#define CERT_STORE_PROV_SMART_CARD CERT_STORE_PROV_SMART_CARD_W
#define CERT_STORE_PROV_LDAP_W ((LPCSTR)16)
#define CERT_STORE_PROV_LDAP CERT_STORE_PROV_LDAP_W
#define CERT_STORE_PROV_PKCS12 ((LPCSTR)17)
#define sz_CERT_STORE_PROV_MEMORY "Memory"
#define sz_CERT_STORE_PROV_FILENAME_W "File"
#define sz_CERT_STORE_PROV_FILENAME sz_CERT_STORE_PROV_FILENAME_W
#define sz_CERT_STORE_PROV_SYSTEM_W "System"
#define sz_CERT_STORE_PROV_SYSTEM sz_CERT_STORE_PROV_SYSTEM_W
#define sz_CERT_STORE_PROV_PKCS7 "PKCS7"
#define sz_CERT_STORE_PROV_PKCS12 "PKCS12"
#define sz_CERT_STORE_PROV_SERIALIZED "Serialized"
#define sz_CERT_STORE_PROV_COLLECTION "Collection"
#define sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W "SystemRegistry"
#define sz_CERT_STORE_PROV_SYSTEM_REGISTRY sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W
#define sz_CERT_STORE_PROV_PHYSICAL_W "Physical"
#define sz_CERT_STORE_PROV_PHYSICAL sz_CERT_STORE_PROV_PHYSICAL_W
#define sz_CERT_STORE_PROV_SMART_CARD_W "SmartCard"
#define sz_CERT_STORE_PROV_SMART_CARD sz_CERT_STORE_PROV_SMART_CARD_W
#define sz_CERT_STORE_PROV_LDAP_W "Ldap"
#define sz_CERT_STORE_PROV_LDAP sz_CERT_STORE_PROV_LDAP_W

#define CERT_STORE_SIGNATURE_FLAG 0x00000001
#define CERT_STORE_TIME_VALIDITY_FLAG 0x00000002
#define CERT_STORE_REVOCATION_FLAG 0x00000004
#define CERT_STORE_NO_CRL_FLAG 0x00010000
#define CERT_STORE_NO_ISSUER_FLAG 0x00020000
#define CERT_STORE_BASE_CRL_FLAG 0x00000100
#define CERT_STORE_DELTA_CRL_FLAG 0x00000200

#define CERT_STORE_NO_CRYPT_RELEASE_FLAG 0x00000001
#define CERT_STORE_SET_LOCALIZED_NAME_FLAG 0x00000002
#define CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG 0x00000004
#define CERT_STORE_DELETE_FLAG 0x00000010
#define CERT_STORE_UNSAFE_PHYSICAL_FLAG 0x00000020
#define CERT_STORE_SHARE_STORE_FLAG 0x00000040
#define CERT_STORE_SHARE_CONTEXT_FLAG 0x00000080
#define CERT_STORE_MANIFOLD_FLAG 0x00000100
#define CERT_STORE_ENUM_ARCHIVED_FLAG 0x00000200
#define CERT_STORE_UPDATE_KEYID_FLAG 0x00000400
#define CERT_STORE_BACKUP_RESTORE_FLAG 0x00000800
#define CERT_STORE_READONLY_FLAG 0x00008000
#define CERT_STORE_OPEN_EXISTING_FLAG 0x00004000
#define CERT_STORE_CREATE_NEW_FLAG 0x00002000
#define CERT_STORE_MAXIMUM_ALLOWED_FLAG 0x00001000

#define CERT_SYSTEM_STORE_MASK 0xFFFF0000
#define CERT_SYSTEM_STORE_RELOCATE_FLAG 0x80000000
#define CERT_SYSTEM_STORE_UNPROTECTED_FLAG 0x40000000
#define CERT_SYSTEM_STORE_DEFER_READ_FLAG 0x20000000
#define CERT_SYSTEM_STORE_LOCATION_MASK 0x00FF0000
#define CERT_SYSTEM_STORE_LOCATION_SHIFT 16
#define CERT_SYSTEM_STORE_CURRENT_USER_ID 1
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_ID 2
#define CERT_SYSTEM_STORE_CURRENT_SERVICE_ID 4
#define CERT_SYSTEM_STORE_SERVICES_ID 5
#define CERT_SYSTEM_STORE_USERS_ID 6
#define CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID 7
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID 8
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID 9

#define CERT_SYSTEM_STORE_CURRENT_USER \
	(CERT_SYSTEM_STORE_CURRENT_USER_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_LOCAL_MACHINE \
	(CERT_SYSTEM_STORE_LOCAL_MACHINE_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_CURRENT_SERVICE \
	(CERT_SYSTEM_STORE_CURRENT_SERVICE_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_SERVICES \
	(CERT_SYSTEM_STORE_SERVICES_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_USERS (CERT_SYSTEM_STORE_USERS_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY \
	(CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY \
	(CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE \
	(CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)

WINPR_API HCERTSTORE CertOpenStore(LPCSTR lpszStoreProvider, DWORD dwMsgAndCertEncodingType,
                                   HCRYPTPROV_LEGACY hCryptProv, DWORD dwFlags, const void* pvPara);

WINPR_API HCERTSTORE CertOpenSystemStoreW(HCRYPTPROV_LEGACY hProv, LPCWSTR szSubsystemProtocol);
WINPR_API HCERTSTORE CertOpenSystemStoreA(HCRYPTPROV_LEGACY hProv, LPCSTR szSubsystemProtocol);

WINPR_API BOOL CertCloseStore(HCERTSTORE hCertStore, DWORD dwFlags);

#ifdef UNICODE
#define CertOpenSystemStore CertOpenSystemStoreW
#else
#define CertOpenSystemStore CertOpenSystemStoreA
#endif

#ifdef __cplusplus
extern "C"
{
#endif

	WINPR_API PCCERT_CONTEXT CertFindCertificateInStore(HCERTSTORE hCertStore,
	                                                    DWORD dwCertEncodingType, DWORD dwFindFlags,
	                                                    DWORD dwFindType, const void* pvFindPara,
	                                                    PCCERT_CONTEXT pPrevCertContext);

	WINPR_API PCCERT_CONTEXT CertEnumCertificatesInStore(HCERTSTORE hCertStore,
	                                                     PCCERT_CONTEXT pPrevCertContext);

	WINPR_API DWORD CertGetNameStringW(PCCERT_CONTEXT pCertContext, DWORD dwType, DWORD dwFlags,
	                                   void* pvTypePara, LPWSTR pszNameString, DWORD cchNameString);
	WINPR_API DWORD CertGetNameStringA(PCCERT_CONTEXT pCertContext, DWORD dwType, DWORD dwFlags,
	                                   void* pvTypePara, LPSTR pszNameString, DWORD cchNameString);

#ifdef __cplusplus
}
#endif

#ifdef UNICODE
#define CertGetNameString CertGetNameStringW
#else
#define CertGetNameString CertGetNameStringA
#endif

/**
 * Data Protection API (DPAPI)
 */

#define CRYPTPROTECTMEMORY_BLOCK_SIZE 16

#define CRYPTPROTECTMEMORY_SAME_PROCESS 0x00000000
#define CRYPTPROTECTMEMORY_CROSS_PROCESS 0x00000001
#define CRYPTPROTECTMEMORY_SAME_LOGON 0x00000002

#define CRYPTPROTECT_PROMPT_ON_UNPROTECT 0x00000001
#define CRYPTPROTECT_PROMPT_ON_PROTECT 0x00000002
#define CRYPTPROTECT_PROMPT_RESERVED 0x00000004
#define CRYPTPROTECT_PROMPT_STRONG 0x00000008
#define CRYPTPROTECT_PROMPT_REQUIRE_STRONG 0x00000010

#define CRYPTPROTECT_UI_FORBIDDEN 0x1
#define CRYPTPROTECT_LOCAL_MACHINE 0x4
#define CRYPTPROTECT_CRED_SYNC 0x8
#define CRYPTPROTECT_AUDIT 0x10
#define CRYPTPROTECT_NO_RECOVERY 0x20
#define CRYPTPROTECT_VERIFY_PROTECTION 0x40
#define CRYPTPROTECT_CRED_REGENERATE 0x80

#define CRYPTPROTECT_FIRST_RESERVED_FLAGVAL 0x0FFFFFFF
#define CRYPTPROTECT_LAST_RESERVED_FLAGVAL 0xFFFFFFFF

typedef struct
{
	DWORD cbSize;
	DWORD dwPromptFlags;
	HWND hwndApp;
	LPCWSTR szPrompt;
} CRYPTPROTECT_PROMPTSTRUCT, *PCRYPTPROTECT_PROMPTSTRUCT;

#define CRYPTPROTECT_DEFAULT_PROVIDER                      \
	{                                                      \
		0xdf9d8cd0, 0x1501, 0x11d1,                        \
		{                                                  \
			0x8c, 0x7a, 0x00, 0xc0, 0x4f, 0xc2, 0x97, 0xeb \
		}                                                  \
	}

#ifdef __cplusplus
extern "C"
{
#endif

	WINPR_API BOOL CryptProtectMemory(LPVOID pData, DWORD cbData, DWORD dwFlags);
	WINPR_API BOOL CryptUnprotectMemory(LPVOID pData, DWORD cbData, DWORD dwFlags);

	WINPR_API BOOL CryptProtectData(DATA_BLOB* pDataIn, LPCWSTR szDataDescr,
	                                DATA_BLOB* pOptionalEntropy, PVOID pvReserved,
	                                CRYPTPROTECT_PROMPTSTRUCT* pPromptStruct, DWORD dwFlags,
	                                DATA_BLOB* pDataOut);
	WINPR_API BOOL CryptUnprotectData(DATA_BLOB* pDataIn, LPWSTR* ppszDataDescr,
	                                  DATA_BLOB* pOptionalEntropy, PVOID pvReserved,
	                                  CRYPTPROTECT_PROMPTSTRUCT* pPromptStruct, DWORD dwFlags,
	                                  DATA_BLOB* pDataOut);

#ifdef __cplusplus
}
#endif

#define CRYPT_STRING_BASE64HEADER 0x00000000
#define CRYPT_STRING_BASE64 0x00000001
#define CRYPT_STRING_BINARY 0x00000002
#define CRYPT_STRING_BASE64REQUESTHEADER 0x00000003
#define CRYPT_STRING_HEX 0x00000004
#define CRYPT_STRING_HEXASCII 0x00000005
#define CRYPT_STRING_BASE64_ANY 0x00000006
#define CRYPT_STRING_ANY 0x00000007
#define CRYPT_STRING_HEX_ANY 0x00000008
#define CRYPT_STRING_BASE64X509CRLHEADER 0x00000009
#define CRYPT_STRING_HEXADDR 0x0000000A
#define CRYPT_STRING_HEXASCIIADDR 0x0000000B
#define CRYPT_STRING_HEXRAW 0x0000000C

#define CRYPT_STRING_HASHDATA 0x10000000
#define CRYPT_STRING_STRICT 0x20000000
#define CRYPT_STRING_NOCRLF 0x40000000
#define CRYPT_STRING_NOCR 0x80000000

WINPR_API BOOL CryptStringToBinaryW(LPCWSTR pszString, DWORD cchString, DWORD dwFlags,
                                    BYTE* pbBinary, DWORD* pcbBinary, DWORD* pdwSkip,
                                    DWORD* pdwFlags);
WINPR_API BOOL CryptStringToBinaryA(LPCSTR pszString, DWORD cchString, DWORD dwFlags,
                                    BYTE* pbBinary, DWORD* pcbBinary, DWORD* pdwSkip,
                                    DWORD* pdwFlags);

WINPR_API BOOL CryptBinaryToStringW(CONST BYTE* pbBinary, DWORD cbBinary, DWORD dwFlags,
                                    LPWSTR pszString, DWORD* pcchString);
WINPR_API BOOL CryptBinaryToStringA(CONST BYTE* pbBinary, DWORD cbBinary, DWORD dwFlags,
                                    LPSTR pszString, DWORD* pcchString);

#ifdef UNICODE
#define CryptStringToBinary CryptStringToBinaryW
#define CryptBinaryToString CryptBinaryToStringW
#else
#define CryptStringToBinary CryptStringToBinaryA
#define CryptBinaryToString CryptBinaryToStringA
#endif

#endif

#ifndef ALG_SID_ECSDA
#define ALG_SID_ECDSA 3
#define CALG_ECDSA (ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_ECDSA)
#endif

/**
 * Custom Crypto API Abstraction Layer
 */

#define WINPR_MD4_DIGEST_LENGTH 16
#define WINPR_MD5_DIGEST_LENGTH 16
#define WINPR_SHA1_DIGEST_LENGTH 20
#define WINPR_SHA224_DIGEST_LENGTH 28
#define WINPR_SHA256_DIGEST_LENGTH 32
#define WINPR_SHA384_DIGEST_LENGTH 48
#define WINPR_SHA512_DIGEST_LENGTH 64
#define WINPR_RIPEMD160_DIGEST_LENGTH 20
#define WINPR_SHA3_224_DIGEST_LENGTH 28
#define WINPR_SHA3_256_DIGEST_LENGTH 32
#define WINPR_SHA3_384_DIGEST_LENGTH 48
#define WINPR_SHA3_512_DIGEST_LENGTH 64
#define WINPR_SHAKE128_DIGEST_LENGTH 16
#define WINPR_SHAKE256_DIGEST_LENGTH 32

/**
 * HMAC
 */
typedef enum
{
	WINPR_MD_NONE = 0,
	WINPR_MD_MD2 = 1,
	WINPR_MD_MD4 = 2,
	WINPR_MD_MD5 = 3,
	WINPR_MD_SHA1 = 4,
	WINPR_MD_SHA224 = 5,
	WINPR_MD_SHA256 = 6,
	WINPR_MD_SHA384 = 7,
	WINPR_MD_SHA512 = 8,
	WINPR_MD_RIPEMD160 = 9,
	WINPR_MD_SHA3_224 = 10,
	WINPR_MD_SHA3_256 = 11,
	WINPR_MD_SHA3_384 = 12,
	WINPR_MD_SHA3_512 = 13,
	WINPR_MD_SHAKE128 = 14,
	WINPR_MD_SHAKE256 = 15
} WINPR_MD_TYPE;

typedef struct winpr_hmac_ctx_private_st WINPR_HMAC_CTX;

#ifdef __cplusplus
extern "C"
{
#endif

	WINPR_API WINPR_MD_TYPE winpr_md_type_from_string(const char* name);
	WINPR_API const char* winpr_md_type_to_string(WINPR_MD_TYPE md);

	WINPR_API WINPR_HMAC_CTX* winpr_HMAC_New(void);
	WINPR_API BOOL winpr_HMAC_Init(WINPR_HMAC_CTX* ctx, WINPR_MD_TYPE md, const BYTE* key,
	                               size_t keylen);
	WINPR_API BOOL winpr_HMAC_Update(WINPR_HMAC_CTX* ctx, const BYTE* input, size_t ilen);
	WINPR_API BOOL winpr_HMAC_Final(WINPR_HMAC_CTX* ctx, BYTE* output, size_t ilen);
	WINPR_API void winpr_HMAC_Free(WINPR_HMAC_CTX* ctx);
	WINPR_API BOOL winpr_HMAC(WINPR_MD_TYPE md, const BYTE* key, size_t keylen, const BYTE* input,
	                          size_t ilen, BYTE* output, size_t olen);

#ifdef __cplusplus
}
#endif

/**
 * Generic Digest API
 */

typedef struct winpr_digest_ctx_private_st WINPR_DIGEST_CTX;

#ifdef __cplusplus
extern "C"
{
#endif

	WINPR_API WINPR_DIGEST_CTX* winpr_Digest_New(void);
	WINPR_API BOOL winpr_Digest_Init_Allow_FIPS(WINPR_DIGEST_CTX* ctx, WINPR_MD_TYPE md);
	WINPR_API BOOL winpr_Digest_Init(WINPR_DIGEST_CTX* ctx, WINPR_MD_TYPE md);
	WINPR_API BOOL winpr_Digest_Update(WINPR_DIGEST_CTX* ctx, const BYTE* input, size_t ilen);
	WINPR_API BOOL winpr_Digest_Final(WINPR_DIGEST_CTX* ctx, BYTE* output, size_t ilen);
	WINPR_API void winpr_Digest_Free(WINPR_DIGEST_CTX* ctx);
	WINPR_API BOOL winpr_Digest_Allow_FIPS(WINPR_MD_TYPE md, const BYTE* input, size_t ilen,
	                                       BYTE* output, size_t olen);
	WINPR_API BOOL winpr_Digest(WINPR_MD_TYPE md, const BYTE* input, size_t ilen, BYTE* output,
	                            size_t olen);

#ifdef __cplusplus
}
#endif

/**
 * Random Number Generation
 */

#ifdef __cplusplus
extern "C"
{
#endif

	WINPR_API int winpr_RAND(BYTE* output, size_t len);
	WINPR_API int winpr_RAND_pseudo(BYTE* output, size_t len);

#ifdef __cplusplus
}
#endif

/**
 * RC4
 */

typedef struct winpr_rc4_ctx_private_st WINPR_RC4_CTX;

#ifdef __cplusplus
extern "C"
{
#endif

	WINPR_API WINPR_RC4_CTX* winpr_RC4_New_Allow_FIPS(const BYTE* key, size_t keylen);
	WINPR_API WINPR_RC4_CTX* winpr_RC4_New(const BYTE* key, size_t keylen);
	WINPR_API BOOL winpr_RC4_Update(WINPR_RC4_CTX* ctx, size_t length, const BYTE* input,
	                                BYTE* output);
	WINPR_API void winpr_RC4_Free(WINPR_RC4_CTX* ctx);

#ifdef __cplusplus
}
#endif

/**
 * Generic Cipher API
 */

#define WINPR_AES_BLOCK_SIZE 16

/* cipher operation types */
#define WINPR_ENCRYPT 0
#define WINPR_DECRYPT 1

/* cipher types */
#define WINPR_CIPHER_NONE 0
#define WINPR_CIPHER_NULL 1
#define WINPR_CIPHER_AES_128_ECB 2
#define WINPR_CIPHER_AES_192_ECB 3
#define WINPR_CIPHER_AES_256_ECB 4
#define WINPR_CIPHER_AES_128_CBC 5
#define WINPR_CIPHER_AES_192_CBC 6
#define WINPR_CIPHER_AES_256_CBC 7
#define WINPR_CIPHER_AES_128_CFB128 8
#define WINPR_CIPHER_AES_192_CFB128 9
#define WINPR_CIPHER_AES_256_CFB128 10
#define WINPR_CIPHER_AES_128_CTR 11
#define WINPR_CIPHER_AES_192_CTR 12
#define WINPR_CIPHER_AES_256_CTR 13
#define WINPR_CIPHER_AES_128_GCM 14
#define WINPR_CIPHER_AES_192_GCM 15
#define WINPR_CIPHER_AES_256_GCM 16
#define WINPR_CIPHER_CAMELLIA_128_ECB 17
#define WINPR_CIPHER_CAMELLIA_192_ECB 18
#define WINPR_CIPHER_CAMELLIA_256_ECB 19
#define WINPR_CIPHER_CAMELLIA_128_CBC 20
#define WINPR_CIPHER_CAMELLIA_192_CBC 21
#define WINPR_CIPHER_CAMELLIA_256_CBC 22
#define WINPR_CIPHER_CAMELLIA_128_CFB128 23
#define WINPR_CIPHER_CAMELLIA_192_CFB128 24
#define WINPR_CIPHER_CAMELLIA_256_CFB128 25
#define WINPR_CIPHER_CAMELLIA_128_CTR 26
#define WINPR_CIPHER_CAMELLIA_192_CTR 27
#define WINPR_CIPHER_CAMELLIA_256_CTR 28
#define WINPR_CIPHER_CAMELLIA_128_GCM 29
#define WINPR_CIPHER_CAMELLIA_192_GCM 30
#define WINPR_CIPHER_CAMELLIA_256_GCM 31
#define WINPR_CIPHER_DES_ECB 32
#define WINPR_CIPHER_DES_CBC 33
#define WINPR_CIPHER_DES_EDE_ECB 34
#define WINPR_CIPHER_DES_EDE_CBC 35
#define WINPR_CIPHER_DES_EDE3_ECB 36
#define WINPR_CIPHER_DES_EDE3_CBC 37
#define WINPR_CIPHER_BLOWFISH_ECB 38
#define WINPR_CIPHER_BLOWFISH_CBC 39
#define WINPR_CIPHER_BLOWFISH_CFB64 40
#define WINPR_CIPHER_BLOWFISH_CTR 41
#define WINPR_CIPHER_ARC4_128 42
#define WINPR_CIPHER_AES_128_CCM 43
#define WINPR_CIPHER_AES_192_CCM 44
#define WINPR_CIPHER_AES_256_CCM 45
#define WINPR_CIPHER_CAMELLIA_128_CCM 46
#define WINPR_CIPHER_CAMELLIA_192_CCM 47
#define WINPR_CIPHER_CAMELLIA_256_CCM 48

typedef struct winpr_cipher_ctx_private_st WINPR_CIPHER_CTX;

#ifdef __cplusplus
extern "C"
{
#endif

	WINPR_API WINPR_CIPHER_CTX* winpr_Cipher_New(int cipher, int op, const BYTE* key,
	                                             const BYTE* iv);
	WINPR_API BOOL winpr_Cipher_Update(WINPR_CIPHER_CTX* ctx, const BYTE* input, size_t ilen,
	                                   BYTE* output, size_t* olen);
	WINPR_API BOOL winpr_Cipher_Final(WINPR_CIPHER_CTX* ctx, BYTE* output, size_t* olen);
	WINPR_API void winpr_Cipher_Free(WINPR_CIPHER_CTX* ctx);

#ifdef __cplusplus
}
#endif

/**
 * Key Generation
 */

#ifdef __cplusplus
extern "C"
{
#endif

	WINPR_API int winpr_Cipher_BytesToKey(int cipher, int md, const BYTE* salt, const BYTE* data,
	                                      int datal, int count, BYTE* key, BYTE* iv);

#ifdef __cplusplus
}
#endif

#endif /* WINPR_CRYPTO_H */
