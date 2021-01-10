// ---------------------------------------------------------------------------
#pragma hdrstop
#include "XXTEA.h"
#include <string.h>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#define MX (((z >> 5) ^ (y << 2)) + ((y >> 3) ^ (z << 4))) ^ ((sum ^ y) + \
             (key[(p & 3) ^ e] ^ z))
#define DELTA 0x9e3779b9
#define FIXED_KEY \
	unsigned i;\
    unsigned char fixed_key[16];\
    memcpy(fixed_key, key, 16);\
    for (i = 0; (i < 16) && (fixed_key[i] != 0); ++i);\
	for (++i; i < 16; ++i) fixed_key[i] = 0;\


static unsigned * xxtea_to_uint_array(const unsigned char * data, unsigned len, int inc_len, unsigned * out_len) {
	unsigned *out;
	unsigned n;
	n = (((len & 3) == 0) ? (len >> 2) : ((len >> 2) + 1));
	if (inc_len) {
		out = (unsigned *)calloc(n + 1, sizeof(unsigned));
		if (!out)
			return 0;
		out[n] = (unsigned)len;
		*out_len = n + 1;
	}
	else {
		out = (unsigned *)calloc(n, sizeof(unsigned));
		if (!out)
			return 0;
		*out_len = n;
	}
	memcpy(out, data, len);
	return out;
}

static unsigned char * xxtea_to_ubyte_array(const unsigned * data, unsigned len, int inc_len, unsigned * out_len) {
	unsigned char *out;
	unsigned m, n;
	n = len << 2;
	if (inc_len) {
		m = data[len - 1];
		n -= 4;
		if ((m < n - 3) || (m > n))
			return 0;
		n = m;
	}
	out = (unsigned char *)malloc(n + 1);
	memcpy(out, data, n);
	out[n] = '\0';
	*out_len = n;
	return out;
}

static unsigned * xxtea_uint_encrypt(unsigned * data, unsigned len, unsigned * key) {
	unsigned n = (unsigned)len - 1;
	unsigned z = data[n], y, p, q = 6 + 52 / (n + 1), sum = 0, e;
	if (n < 1)
		return data;
	while (0 < q--) {
		sum += DELTA;
		e = sum >> 2 & 3;
		for (p = 0; p < n; p++) {
			y = data[p + 1];
			z = data[p] += MX;
		}
		y = data[0];
		z = data[n] += MX;
	}
	return data;
}

static unsigned * xxtea_uint_decrypt(unsigned * data, unsigned len, unsigned * key) {
	unsigned n = (unsigned)len - 1;
	unsigned z, y = data[0], p, q = 6 + 52 / (n + 1), sum = q * DELTA, e;
	if (n < 1)
		return data;
	while (sum != 0) {
		e = sum >> 2 & 3;
		for (p = n; p > 0; p--) {
			z = data[p - 1];
			y = data[p] -= MX;
		}
		z = data[n];
		y = data[0] -= MX;
		sum -= DELTA;
	}
	return data;
}

static unsigned char * xxtea_ubyte_encrypt(const unsigned char * data, unsigned len, const unsigned char * key,
	unsigned * out_len) {
	unsigned char *out;
	unsigned *data_array, *key_array;
	unsigned data_len, key_len;
	if (!len)
		return 0;
	data_array = xxtea_to_uint_array(data, len, 1, &data_len);
	if (!data_array)
		return 0;
	key_array = xxtea_to_uint_array(key, 16, 0, &key_len);
	if (!key_array) {
		free(data_array);
		return 0;
	}
	out = xxtea_to_ubyte_array(xxtea_uint_encrypt(data_array, data_len, key_array), data_len, 0, out_len);
	free(data_array);
	free(key_array);
	return out;
}

static unsigned char * xxtea_ubyte_decrypt(const unsigned char * data, unsigned len, const unsigned char * key,
	unsigned * out_len) {
	unsigned char *out;
	unsigned *data_array, *key_array;
	unsigned data_len, key_len;
	if (!len)
		return 0;
	data_array = xxtea_to_uint_array(data, len, 0, &data_len);
	if (!data_array)
		return 0;
	key_array = xxtea_to_uint_array(key, 16, 0, &key_len);
	if (!key_array) {
		free(data_array);
		return 0;
	}
	out = xxtea_to_ubyte_array(xxtea_uint_decrypt(data_array, data_len, key_array), data_len, 1, out_len);
	free(data_array);
	free(key_array);
	return out;
}

void * xxtea_encrypt(const void * data, unsigned len, const void * key, unsigned * out_len) {
	FIXED_KEY return xxtea_ubyte_encrypt((const unsigned char *)data, len, fixed_key, out_len);
}

void * xxtea_decrypt(const void * data, unsigned len, const void * key, unsigned * out_len) {
	FIXED_KEY return xxtea_ubyte_decrypt((const unsigned char *)data, len, fixed_key, out_len);
}
