// ---------------------------------------------------------------------------

#ifndef XXTEA_CB_H
#define XXTEA_CB_H
// ---------------------------------------------------------------------------
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

	void * xxtea_encrypt(const void * data, unsigned len, const void * key, unsigned * out_len);

	void * xxtea_decrypt(const void * data, unsigned len, const void * key, unsigned * out_len);

#ifdef __cplusplus
}
#endif

#endif
