// CkCertChainW.h: interface for the CkCertChainW class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkCertChainW_H
#define _CkCertChainW_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkWideCharBase.h"

class CkCertW;
class CkTrustedRootsW;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkCertChainW
class CK_VISIBLE_PUBLIC CkCertChainW  : public CkWideCharBase
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkCertChainW(const CkCertChainW &);
	CkCertChainW &operator=(const CkCertChainW &);

    public:
	CkCertChainW(void);
	virtual ~CkCertChainW(void);

	static CkCertChainW *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The number of certificates in the chain. The end-user subscriber certificate is
	// at index 0. This is the certificate most removed from the trusted root.
	// Intermediate certificates are at indices 1 to NumCerts - 2. The trusted root (or
	// self-signed certificate) is at index NumCerts - 1.
	int get_NumCerts(void);

	// Returns the number of certificates in the chain that have expired.
	int get_NumExpiredCerts(void);

	// true if this certificate chain extends all the way to the root certificate.
	// The root certificate is either a trusted CA root or a self-signed certificate.
	// In both cases, the issuer of a root certificate is itself.
	bool get_ReachesRoot(void);



	// ----------------------
	// Methods
	// ----------------------
	// Returns the Nth certificate in the chain.
	// The caller is responsible for deleting the object returned by this method.
	CkCertW *GetCert(int index);

	// Returns true if the root of the certificate chain is a certificate found in
	// ARG1.
	bool IsRootTrusted(CkTrustedRootsW &trustedRoots);

	// Verifies the certificate signatures to the root. Returns true if all
	// certificate signatures are valid.
	bool VerifyCertSignatures(void);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
