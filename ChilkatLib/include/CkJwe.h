// CkJwe.h: interface for the CkJwe class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkJwe_H
#define _CkJwe_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkMultiByteBase.h"

class CkBinData;
class CkStringBuilder;
class CkPrivateKey;
class CkJsonObject;
class CkPublicKey;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkJwe
class CK_VISIBLE_PUBLIC CkJwe  : public CkMultiByteBase
{
    private:

	// Don't allow assignment or copying these objects.
	CkJwe(const CkJwe &);
	CkJwe &operator=(const CkJwe &);

    public:
	CkJwe(void);
	virtual ~CkJwe(void);

	static CkJwe *createNew(void);
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// Controls whether to use JWE Compact Serialization or JWE JSON Serialization when
	// creating JWEs. The default value is true, which is to use compact
	// serialization. If multiple recipients are used, or if any unprotected headers
	// exist, then JWE JSON Serialization is used regardless of this property setting.
	bool get_Compact(void);
	// Controls whether to use JWE Compact Serialization or JWE JSON Serialization when
	// creating JWEs. The default value is true, which is to use compact
	// serialization. If multiple recipients are used, or if any unprotected headers
	// exist, then JWE JSON Serialization is used regardless of this property setting.
	void put_Compact(bool newVal);

	// The number of recipients for this JWE.
	int get_NumRecipients(void);



	// ----------------------
	// Methods
	// ----------------------
	// Decrypts a JWE and returns the original (decrypted) string content. The byte
	// representation of the decrypted bytes is indicated by charset (such as "utf-8").
	// (The charset tells Chilkat how to intepret the decrypted bytes as characters.)
	// 
	// The index specifies which recipient key is used for decryption. (Most JWEs have
	// only a single recipent, and thus the index is typically 0.)
	// 
	bool Decrypt(int index, const char *charset, CkString &outStr);

	// Decrypts a JWE and returns the original (decrypted) string content. The byte
	// representation of the decrypted bytes is indicated by charset (such as "utf-8").
	// (The charset tells Chilkat how to intepret the decrypted bytes as characters.)
	// 
	// The index specifies which recipient key is used for decryption. (Most JWEs have
	// only a single recipent, and thus the index is typically 0.)
	// 
	const char *decrypt(int index, const char *charset);

	// Decrypts the loaded JWE and appends the decrypted bytes to the contents of bd.
	// The index specifies which recipient key is used for decryption. (Most JWEs have
	// only a single recipent, and thus the index is typically 0.)
	bool DecryptBd(int index, CkBinData &bd);


	// Decrypts the loaded JWE and appends the decrypted content to contentSb. The byte
	// representation of the decrypted bytes is indicated by charset (such as "utf-8").
	// (This tells Chilkat how to interpret the bytes as characters.)
	// 
	// The index specifies which recipient key is used for decryption. (Most JWEs have
	// only a single recipent, and thus the index is typically 0.)
	// 
	bool DecryptSb(int index, const char *charset, CkStringBuilder &contentSb);


	// Encrypts string content to produce a JWE. The byte representation of the content is
	// indicated by charset (such as "utf-8").
	bool Encrypt(const char *content, const char *charset, CkString &outStr);

	// Encrypts string content to produce a JWE. The byte representation of the content is
	// indicated by charset (such as "utf-8").
	const char *encrypt(const char *content, const char *charset);

	// Encrypts the contents of contentBd to produce a JWE that is appended to the contents
	// of jweSb. (This method provides the means to produce a JWE from binary content.)
	bool EncryptBd(CkBinData &contentBd, CkStringBuilder &jweSb);


	// Encrypts the contents of contentSb to produce a JWE that is appended to the contents
	// of jweSb. The byte representation of the string to be encrypted is indicated by
	// charset (such as "utf-8").
	bool EncryptSb(CkStringBuilder &contentSb, const char *charset, CkStringBuilder &jweSb);


	// Loads the contents of a JWE.
	bool LoadJwe(const char *jwe);


	// Loads the contents of a JWE from a StringBuilder object.
	bool LoadJweSb(CkStringBuilder &sb);


	// Sets the optional Additional Authenticated Data. This is only used for
	// non-compact serializations. The charset specifies the character encoding (such as
	// "utf-8") to be used for the byte representation for the additional authenticated
	// data.
	bool SetAad(const char *aad, const char *charset);


	// Sets the optional Additional Authenticated Data. This is only used for
	// non-compact serializations. This method provides a way for binary (non-text)
	// additional authenticated data to be used.
	bool SetAadBd(CkBinData &aad);


	// Sets the PBES2 password for key encryption or decryption. This is for the case
	// where the content encryption key (CEK) is encrypted using PBES2. An PBES2
	// password should be used in the cases where the "alg" header parameter value is
	// equal to one of the following:
	// PBES2-HS256+A128KW
	// PBES2-HS384+A192KW
	// PBES2-HS512+A256KW
	// The index is the index of the recipient, where the 1st recipient is at index 0.
	// (The typical use case for JWEs is for a single recipient.)
	bool SetPassword(int index, const char *password);


	// Sets a private key for RSA key unwrapping/decryption. This is for the case where
	// the content encryption key (CEK) is encrypted using RSA. An RSA private key
	// should be used for decrypting in the cases where the "alg" header parameter
	// value is equal to one of the following:
	// RSA1_5
	// RSA-OAEP
	// RSA-OAEP-256
	// The index is the index of the recipient, where the 1st recipient is at index 0.
	// (The typical use case for JWEs is for a single recipient.)
	bool SetPrivateKey(int index, CkPrivateKey &privKey);


	// Sets the JWE Protected Header.
	bool SetProtectedHeader(CkJsonObject &json);


	// Sets a public key for RSA key wrapping encryption. This is for the case where
	// the content encryption key (CEK) is encrypted using RSA. An RSA public key
	// should be used when encrypting for the cases where the "alg" header parameter
	// value is equal to one of the following:
	// RSA1_5
	// RSA-OAEP
	// RSA-OAEP-256
	// The index is the index of the recipient, where the 1st recipient is at index 0.
	// (The typical use case for JWEs is for a single recipient.)
	bool SetPublicKey(int index, CkPublicKey &pubKey);


	// Sets a per-recipient unprotected header. This method would only be called if the
	// JWE is for multiple recipients. The 1st recipient is at index 0.
	bool SetRecipientHeader(int index, CkJsonObject &json);


	// Sets the JWE Shared Unprotected Header.
	bool SetUnprotectedHeader(CkJsonObject &json);


	// Sets the AES wrapping key for encryption or decryption. This is for the case
	// where the content encryption key (CEK) is encrypted using AES Key Wrap or AES
	// GCM. An AES key should be used in the cases where the "alg" header parameter
	// value is equal to one of the following:
	// A128KW
	// A192KW
	// A256KW
	// A128GCMKW
	// A192GCMKW
	// A256GCMKW
	// dir
	// The index is the index of the recipient, where the 1st recipient is at index 0.
	// (The typical use case for JWEs is for a single recipient.)
	// 
	// Note: This method also sets the shared direct symmetric key for the case when
	// the "alg" is equal to "dir". In this case, the key specified is not actualy a
	// key encryption key, but is the direct content encryption key.
	// 
	// The encoding indicates the representation, such as "base64", "hex", "base64url",
	// etc. of the encodedKey.
	// 
	bool SetWrappingKey(int index, const char *encodedKey, const char *encoding);






	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif